// A C++ Program to implement A* Search Algorithm
#include<bits/stdc++.h>
using namespace std;

 /*

Some rules:
===========

  A) Representacion del mapa (grid):

    Se utiliza un vector de vectores de ints
    Cada int representa una celda
      UNBLOCKED = celda vacia
      BLOCKED   = obstaculo
    usar los macros

  B) Representacion del origen y el destino:

    Se utiliza un par, funcion make_pair(x,y)
    con las coordenadas del origen y el destino

  C) Representacion para permitir movimientos diagonales:

    Un booleano

  D) Representacion de la solucion:

    Un vector de pares, representa la serie de movimientos
    para llegar al destino, cada par ordenado es la siguiente
    posicion (x,y) a la que se debe movilizar el agente

  E) Funcion de A* aStarSearch():

    Se pasa como argumento:
      grid       Grid vector<vector<int>>
      origen     pair<int, int>
      destino    pair<int, int>
      diagonales bool

    Devuelve:
      solucion   Path deque<pair<int, int>>

      'returns' en caso de:
        no encuentra ruta     --> path.size() = 0
        src o dest no validos --> path.size() = 0

  Restricciones
  =============

    A) El grid debe ser 2x2 o MAYOR
        utilizar la funcion de crear grid (PENDING)
        utilizar la funcion de elminar grid (PENDING)(necesario?)

  Funciones
  =========

    A) Hay prints para todo

    B) crear_grid/cambiar_grid (PENDING)

    C) Funcion para validar src/destino:
        validate_src_dest()

 */

// valores para las celdas
#define UNBLOCKED 1
#define BLOCKED   0


// Creating a shortcut for int, int pair type
typedef pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
typedef pair<double, pair<int, int>> pPair;

// Grid shortcut
typedef vector<vector<int>> Grid;

// Path Found
// Empty if none found
typedef deque<Pair> Path;

// A structure to hold the neccesary parameters
struct cell
{
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};

// 2D array of cells
typedef vector<vector<cell>> cellGrid;


// A Utility Function to check whether given cell (row, col)
// is a valid cell or not.
bool isValid(int row, int col, Grid grid)
{
    int ROW = grid.size();
    int COL = grid[0].size();
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}

//imprime un grid, debe ser rectangular
void print_grid(Grid grid){
  for(int row = 0; row<grid.size() ; row++){
    for(int col = 0; col<grid[0].size() ; col++){
      cout << " " << grid[row][col] << " ";
    }
    cout << "\n";
  }
}

//imprime un pair
void print_pair(Pair pair){
  printf("(%d,%d)", pair.first, pair.second);
}

void print_path(Path path){
  if (path.size()==0){
    printf("\n Path is empty! (none found)\n");
  }
  else{
    printf("\n Path found:\n");
    for(int i=0; i<path.size(); i++){
      print_pair(path[i]);
      printf("--> ");
    }
    printf("end.\n");
  }
}


// A Utility Function to check whether the given cell is
// blocked or not
bool isUnBlocked(Grid grid, int row, int col)
{
    // Returns true if the cell is not blocked else false
    if (grid[row][col] == UNBLOCKED)
        return (true);
    else
        return (false);
}

// A Utility Function to check whether destination cell has
// been reached or not
bool isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}


// A Utility Function to calculate the 'h' heuristics.
// bueno para diagonales, usar manhattan para no diagonales
double calculateHValue(int row, int col, Pair dest, bool diagonals)
{
    // if diagonals are allowed
    if(diagonals)
    // Return using the diagonal distance formula
      return ((double)max(abs(row-dest.first),
                          abs(col-dest.second)));
    // if diagonals are not alowed
    // Return using the manhattan distance formula
    return ((double)(abs(row-dest.first)+
                     abs(col-dest.second)));
}

// A Utility Function to trace the path from the source
// to destination
Path tracePath(cellGrid cellDetails, Pair dest)
{
    //printf ("\nThe Path is ");
    int row = dest.first;
    int col = dest.second;

    Path path;

    while (!(cellDetails[row][col].parent_i == row
             && cellDetails[row][col].parent_j == col ))
    {
        path.push_front(make_pair(row, col));
        //path.push (make_pair (row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    path.push_front (make_pair (row, col));
    //while (!path.empty())
    //{
    //    pair<int,int> p = path.top();
    //    path.pop();
    //    printf("-> (%d,%d) ",p.first,p.second);
    //}

    return path;
}

Grid grid_from_path(Path path, Grid grid){
  int RR = grid.size();
  int CC = grid[0].size();
  Grid path_grid(RR);
  for ( int i = 0 ; i < RR ; i++ )
    path_grid[i].resize(CC);

  //llena filas con su numero de fila, pa checkear
  for(int i = 0; i<path.size() ; i++){
    path_grid[path[i].first][path[i].second]=1;
  }
  path_grid[path[0].first][path[0].second]=8;
  path_grid[path[path.size()-1].first][path[path.size()-1].second]=9;
  return path_grid;

}

bool validate_src_dest(Grid grid, Pair src, Pair dest){
    // If the source is out of range
    if (isValid (src.first, src.second, grid) == false)
    {
        printf ("Source is invalid\n");
        return false;
    }

    // If the destination is out of range
    if (isValid (dest.first, dest.second, grid) == false)
    {
        printf ("Destination is invalid\n");
        return false;
    }

    // Either the source or the destination is blocked
    if (isUnBlocked(grid, src.first, src.second) == false ||
            isUnBlocked(grid, dest.first, dest.second) == false)
    {
        printf ("Source or the destination is blocked\n");
        return false;
    }

    // If the destination cell is the same as source cell
    if (isDestination(src.first, src.second, dest) == true)
    {
        printf ("We are already at the destination\n");
        return false;
    }
    return true;
}

// A Function to find the shortest path between
// a given source cell to a destination cell according
// to A* Search Algorithm
Path aStarSearch(Grid grid, Pair src, Pair dest, bool diagonals)
{
    Path path;
    int ROW = grid.size();
    int COL = grid[0].size();

    //validaciones para el src y el dest
    if(!validate_src_dest(grid, src, dest))
      return path;

    // Create a closed list and initialise it to false which means
    // that no cell has been included yet
    // This closed list is implemented as a boolean 2D array
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof (closedList));

    // Declare a 2D array of structure to hold the details
    //of that cell
    cellGrid cellDetails(ROW,vector<cell>(COL));

    int i, j;

    for (i=0; i<ROW; i++)
    {
        for (j=0; j<COL; j++)
        {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }

    // Initialising the parameters of the starting node
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    /*
     Create an open list having information as-
     <f, <i, j>>
     where f = g + h,
     and i, j are the row and column index of that cell
     Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
     This open list is implenented as a set of pair of pair.*/
    set<pPair> openList;

    // Put the starting cell on the open list and set its
    // 'f' as 0
    openList.insert(make_pair (0.0, make_pair (i, j)));

    // We set this boolean value as false as initially
    // the destination is not reached.
    bool foundDest = false;

    while (!openList.empty())
    {
        pPair p = *openList.begin();

        // Remove this vertex from the open list
        openList.erase(openList.begin());

        // Add this vertex to the closed list
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

       /*
        Generating all the 8 successor of this cell

            N.W   N   N.E
              \   |   /
               \  |  /
            W----Cell----E
                 / | \
               /   |  \
            S.W    S   S.E

        Cell-->Popped Cell (i, j)
        N -->  North       (i-1, j)
        S -->  South       (i+1, j)
        E -->  East        (i, j+1)
        W -->  West           (i, j-1)
        N.E--> North-East  (i-1, j+1)
        N.W--> North-West  (i-1, j-1)
        S.E--> South-East  (i+1, j+1)
        S.W--> South-West  (i+1, j-1)*/

        // To store the 'g', 'h' and 'f' of the 8 successors
        double gNew, hNew, fNew;

        //----------- 1st Successor (North) ------------

        // Only process this cell if this is a valid one
        if (isValid(i-1, j, grid) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i-1, j, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i-1][j].parent_i = i;
                cellDetails[i-1][j].parent_j = j;
                printf ("The destination cell is found\n");
                foundDest = true;
                return tracePath (cellDetails, dest);
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i-1][j] == false &&
                     isUnBlocked(grid, i-1, j) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue (i-1, j, dest, diagonals);
                fNew = gNew + hNew;

                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i-1][j].f == FLT_MAX ||
                        cellDetails[i-1][j].f > fNew)
                {
                    openList.insert( make_pair(fNew,
                                               make_pair(i-1, j)));

                    // Update the details of this cell
                    cellDetails[i-1][j].f = fNew;
                    cellDetails[i-1][j].g = gNew;
                    cellDetails[i-1][j].h = hNew;
                    cellDetails[i-1][j].parent_i = i;
                    cellDetails[i-1][j].parent_j = j;
                }
            }
        }

        //----------- 2nd Successor (South) ------------

        // Only process this cell if this is a valid one
        if (isValid(i+1, j, grid) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i+1, j, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i+1][j].parent_i = i;
                cellDetails[i+1][j].parent_j = j;
                printf("The destination cell is found\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i+1][j] == false &&
                     isUnBlocked(grid, i+1, j) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i+1, j, dest, diagonals);
                fNew = gNew + hNew;

                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i+1][j].f == FLT_MAX ||
                        cellDetails[i+1][j].f > fNew)
                {
                    openList.insert( make_pair (fNew, make_pair (i+1, j)));
                    // Update the details of this cell
                    cellDetails[i+1][j].f = fNew;
                    cellDetails[i+1][j].g = gNew;
                    cellDetails[i+1][j].h = hNew;
                    cellDetails[i+1][j].parent_i = i;
                    cellDetails[i+1][j].parent_j = j;
                }
            }
        }

        //----------- 3rd Successor (East) ------------

        // Only process this cell if this is a valid one
        if (isValid (i, j+1, grid) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j+1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i][j+1].parent_i = i;
                cellDetails[i][j+1].parent_j = j;
                printf("The destination cell is found\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }

            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i][j+1] == false &&
                     isUnBlocked (grid, i, j+1) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue (i, j+1, dest, diagonals);
                fNew = gNew + hNew;

                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i][j+1].f == FLT_MAX ||
                        cellDetails[i][j+1].f > fNew)
                {
                    openList.insert( make_pair(fNew,
                                        make_pair (i, j+1)));

                    // Update the details of this cell
                    cellDetails[i][j+1].f = fNew;
                    cellDetails[i][j+1].g = gNew;
                    cellDetails[i][j+1].h = hNew;
                    cellDetails[i][j+1].parent_i = i;
                    cellDetails[i][j+1].parent_j = j;
                }
            }
        }

        //----------- 4th Successor (West) ------------

        // Only process this cell if this is a valid one
        if (isValid(i, j-1, grid) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j-1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i][j-1].parent_i = i;
                cellDetails[i][j-1].parent_j = j;
                printf("The destination cell is found\n");
                foundDest = true;
                return tracePath(cellDetails, dest);
            }

            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i][j-1] == false &&
                     isUnBlocked(grid, i, j-1) == true)
            {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j-1, dest, diagonals);
                fNew = gNew + hNew;

                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[i][j-1].f == FLT_MAX ||
                        cellDetails[i][j-1].f > fNew)
                {
                    openList.insert( make_pair (fNew,
                                          make_pair (i, j-1)));

                    // Update the details of this cell
                    cellDetails[i][j-1].f = fNew;
                    cellDetails[i][j-1].g = gNew;
                    cellDetails[i][j-1].h = hNew;
                    cellDetails[i][j-1].parent_i = i;
                    cellDetails[i][j-1].parent_j = j;
                }
            }
        }

        //-----------          Diagonals         ------------

        // the following successors are only
        // calculated if diagonal movement is
        // allowed
        if(diagonals){

          //----------- 5th Successor (North-East) ------------

          // Only process this cell if this is a valid one
          if (isValid(i-1, j+1, grid) == true)
          {
              // If the destination cell is the same as the
              // current successor
              if (isDestination(i-1, j+1, dest) == true)
              {
                  // Set the Parent of the destination cell
                  cellDetails[i-1][j+1].parent_i = i;
                  cellDetails[i-1][j+1].parent_j = j;
                  printf ("The destination cell is found\n");
                  foundDest = true;
                  return tracePath (cellDetails, dest);
              }

              // If the successor is already on the closed
              // list or if it is blocked, then ignore it.
              // Else do the following
              else if (closedList[i-1][j+1] == false &&
                       isUnBlocked(grid, i-1, j+1) == true)
              {
                  gNew = cellDetails[i][j].g + 1.414;
                  hNew = calculateHValue(i-1, j+1, dest, diagonals);
                  fNew = gNew + hNew;

                  // If it isn’t on the open list, add it to
                  // the open list. Make the current square
                  // the parent of this square. Record the
                  // f, g, and h costs of the square cell
                  //                OR
                  // If it is on the open list already, check
                  // to see if this path to that square is better,
                  // using 'f' cost as the measure.
                  if (cellDetails[i-1][j+1].f == FLT_MAX ||
                          cellDetails[i-1][j+1].f > fNew)
                  {
                      openList.insert( make_pair (fNew,
                                      make_pair(i-1, j+1)));

                      // Update the details of this cell
                      cellDetails[i-1][j+1].f = fNew;
                      cellDetails[i-1][j+1].g = gNew;
                      cellDetails[i-1][j+1].h = hNew;
                      cellDetails[i-1][j+1].parent_i = i;
                      cellDetails[i-1][j+1].parent_j = j;
                  }
              }
          }

          //----------- 6th Successor (North-West) ------------

          // Only process this cell if this is a valid one
          if (isValid (i-1, j-1, grid) == true)
          {
              // If the destination cell is the same as the
              // current successor
              if (isDestination (i-1, j-1, dest) == true)
              {
                  // Set the Parent of the destination cell
                  cellDetails[i-1][j-1].parent_i = i;
                  cellDetails[i-1][j-1].parent_j = j;
                  printf ("The destination cell is found\n");
                  foundDest = true;
                  return tracePath (cellDetails, dest);
              }

              // If the successor is already on the closed
              // list or if it is blocked, then ignore it.
              // Else do the following
              else if (closedList[i-1][j-1] == false &&
                       isUnBlocked(grid, i-1, j-1) == true)
              {
                  gNew = cellDetails[i][j].g + 1.414;
                  hNew = calculateHValue(i-1, j-1, dest, diagonals);
                  fNew = gNew + hNew;

                  // If it isn’t on the open list, add it to
                  // the open list. Make the current square
                  // the parent of this square. Record the
                  // f, g, and h costs of the square cell
                  //                OR
                  // If it is on the open list already, check
                  // to see if this path to that square is better,
                  // using 'f' cost as the measure.
                  if (cellDetails[i-1][j-1].f == FLT_MAX ||
                          cellDetails[i-1][j-1].f > fNew)
                  {
                      openList.insert( make_pair (fNew, make_pair (i-1, j-1)));
                      // Update the details of this cell
                      cellDetails[i-1][j-1].f = fNew;
                      cellDetails[i-1][j-1].g = gNew;
                      cellDetails[i-1][j-1].h = hNew;
                      cellDetails[i-1][j-1].parent_i = i;
                      cellDetails[i-1][j-1].parent_j = j;
                  }
              }
          }

          //----------- 7th Successor (South-East) ------------

          // Only process this cell if this is a valid one
          if (isValid(i+1, j+1, grid) == true)
          {
              // If the destination cell is the same as the
              // current successor
              if (isDestination(i+1, j+1, dest) == true)
              {
                  // Set the Parent of the destination cell
                  cellDetails[i+1][j+1].parent_i = i;
                  cellDetails[i+1][j+1].parent_j = j;
                  printf ("The destination cell is found\n");
                  foundDest = true;
                  return tracePath (cellDetails, dest);
              }

              // If the successor is already on the closed
              // list or if it is blocked, then ignore it.
              // Else do the following
              else if (closedList[i+1][j+1] == false &&
                       isUnBlocked(grid, i+1, j+1) == true)
              {
                  gNew = cellDetails[i][j].g + 1.414;
                  hNew = calculateHValue(i+1, j+1, dest, diagonals);
                  fNew = gNew + hNew;

                  // If it isn’t on the open list, add it to
                  // the open list. Make the current square
                  // the parent of this square. Record the
                  // f, g, and h costs of the square cell
                  //                OR
                  // If it is on the open list already, check
                  // to see if this path to that square is better,
                  // using 'f' cost as the measure.
                  if (cellDetails[i+1][j+1].f == FLT_MAX ||
                          cellDetails[i+1][j+1].f > fNew)
                  {
                      openList.insert(make_pair(fNew,
                                          make_pair (i+1, j+1)));

                      // Update the details of this cell
                      cellDetails[i+1][j+1].f = fNew;
                      cellDetails[i+1][j+1].g = gNew;
                      cellDetails[i+1][j+1].h = hNew;
                      cellDetails[i+1][j+1].parent_i = i;
                      cellDetails[i+1][j+1].parent_j = j;
                  }
              }
          }

          //----------- 8th Successor (South-West) ------------

          // Only process this cell if this is a valid one
          if (isValid (i+1, j-1, grid) == true)
          {
              // If the destination cell is the same as the
              // current successor
              if (isDestination(i+1, j-1, dest) == true)
              {
                  // Set the Parent of the destination cell
                  cellDetails[i+1][j-1].parent_i = i;
                  cellDetails[i+1][j-1].parent_j = j;
                  printf("The destination cell is found\n");
                  foundDest = true;
                  return tracePath(cellDetails, dest);
              }

              // If the successor is already on the closed
              // list or if it is blocked, then ignore it.
              // Else do the following
              else if (closedList[i+1][j-1] == false &&
                       isUnBlocked(grid, i+1, j-1) == true)
              {
                  gNew = cellDetails[i][j].g + 1.414;
                  hNew = calculateHValue(i+1, j-1, dest, diagonals);
                  fNew = gNew + hNew;

                  // If it isn’t on the open list, add it to
                  // the open list. Make the current square
                  // the parent of this square. Record the
                  // f, g, and h costs of the square cell
                  //                OR
                  // If it is on the open list already, check
                  // to see if this path to that square is better,
                  // using 'f' cost as the measure.
                  if (cellDetails[i+1][j-1].f == FLT_MAX ||
                          cellDetails[i+1][j-1].f > fNew)
                  {
                      openList.insert(make_pair(fNew,
                                          make_pair(i+1, j-1)));

                      // Update the details of this cell
                      cellDetails[i+1][j-1].f = fNew;
                      cellDetails[i+1][j-1].g = gNew;
                      cellDetails[i+1][j-1].h = hNew;
                      cellDetails[i+1][j-1].parent_i = i;
                      cellDetails[i+1][j-1].parent_j = j;
                  }
              }
          }
        }
    }

    // When the destination cell is not found and the open
    // list is empty, then we conclude that we failed to
    // reach the destiantion cell. This may happen when the
    // there is no way to destination cell (due to blockages)
    if (foundDest == false)
        printf("Failed to find the Destination Cell\n");

    return path;
}



int main(){

/*
  //crea un grid segun lo que uno le meta, pa checkear
  int RR, CC; //RR = rows CC = cols
  cin >> RR;
  cin >> CC;
  Grid grid(RR);
  for ( int i = 0 ; i < RR ; i++ )
    grid[i].resize(CC);

  //llena filas con su numero de fila, pa checkear
  for(int row = 0; row<grid.size() ; row++){
    for(int col = 0; col<grid[0].size() ; col++){
      grid[row][col]=row;
    }
  }


  print_grid(grid);
*/

    /* Description of the Grid-
     1--> The cell is not blocked
     0--> The cell is blocked    */
    Grid grid
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
    };

    // Source is the left-most bottom-most corner
    Pair src = make_pair(8, 0);

    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 0);

    Path result = aStarSearch(grid, src, dest, true);
    print_path(result);
    Grid grid_result = grid_from_path(result,grid);
    printf("\n");
    print_grid(grid);
    printf("\n");
    print_grid(grid_result);

    printf("\n sin diagonales \n");
    result = aStarSearch(grid, src, dest, false);
    print_path(result);
    grid_result = grid_from_path(result,grid);
    printf("\n");
    print_grid(grid);
    printf("\n");
    print_grid(grid_result);

    return(0);


}
