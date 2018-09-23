// A C++ Program to implement A* Search Algorithm
#include <bits/stdc++.h>
#include "asearch.hpp"
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
        no encuentra ruta     --> path.size() == 0
        src o dest no validos --> path.size() == 0

  Restricciones
  =============

    A) El grid debe ser 2x2 o MAYOR
        utilizar la funcion de crear grid

  Funciones
  =========

    A) Hay prints para todo

    B) make_grid(int filas, int columnas):
        crea un grid aleatorio dadas sus dimensiones
        returns Grid;

    C) make_src_dest(Grid grid):
        crea aleatoriamente un punto inicial
        y uno final dentro de un grid
        returns pair<Pair,Pair>;
          donde el primer Pair es source, segundo es destino

    C) Funcion para validar src/destino:
        validate_src_dest()

 */


// A structure to hold the neccesary parameters
struct cell
{
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};

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
  cout << "\n";
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
    printf("end.\n\n");
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


// A Utility Function to check whether the given cell is
// blocked or not for diagonal movement:
// this means it will move diagonally only if the two
// adjacent blocks are not both blocked
bool isUnBlockedDiagonally(Grid grid, int src_row, int src_col,
                          int dest_row, int dest_col, bool diagonals)
{
    // Returns true if the cell is not blocked else false
    if (!diagonals)
        return (isUnBlocked(grid, dest_row, dest_col));
    // Checks that a diagonal movement is allowed by
    // possible walls, if it's not a diagonal movement
    // it will be allowed by the conditions any way
    if (grid[dest_row][src_col] == UNBLOCKED ||
        grid[src_row][dest_col] == UNBLOCKED  )
        return (isUnBlocked(grid, dest_row, dest_col));
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

//returns empty grid if no path is found
Grid grid_from_path(Path path, Grid grid){
  if(path.size()==0){
    printf("Cannot make grid from empty path. "
      "(Path wasn't found probably)\n");
    Grid empty_grid(0);
    return empty_grid;
  }
  int RR = grid.size();
  int CC = grid[0].size();
  Grid path_grid(RR);
  for ( int i = 0 ; i < RR ; i++ )
    path_grid[i].resize(CC);

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

//returns:
//  true  = found a path, use tracePath(cellDetails, dest) afterwards from asearch function
//  false = did not find a path

bool successor(cellGrid& cellDetails, set<pPair>& openList, vector<vector<bool>>& closedList, Grid grid,
    Pair src, Pair dest, int successor_i, int successor_j, int parent_i, int parent_j, bool diagonals){
        // To store the 'g', 'h' and 'f' of the 8 successors
        double gNew, hNew, fNew;
        bool foundDest;

        // Only process this cell if this is a valid one
        if (isValid(successor_i, successor_j, grid) == true)
        {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(successor_i, successor_j, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[successor_i][successor_j].parent_i = parent_i;
                cellDetails[successor_i][successor_j].parent_j = parent_j;
                printf ("\nA* finished: The destination cell is found\n\n");
                foundDest = true;
                return(foundDest);
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[successor_i][successor_j] == false &&
                     isUnBlockedDiagonally(grid, parent_i, parent_j,
                     successor_i, successor_j, diagonals) == true)
            {
                gNew = cellDetails[parent_i][parent_j].g + 1.0;
                hNew = calculateHValue (successor_i, successor_j, dest, diagonals);
                fNew = gNew + hNew;

                // If it isn’t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is better,
                // using 'f' cost as the measure.
                if (cellDetails[successor_i][successor_j].f == FLT_MAX ||
                        cellDetails[successor_i][successor_j].f > fNew)
                {
                    openList.insert( make_pair(fNew,
                                               make_pair(successor_i, successor_j)));

                    // Update the details of this cell
                    cellDetails[successor_i][successor_j].f = fNew;
                    cellDetails[successor_i][successor_j].g = gNew;
                    cellDetails[successor_i][successor_j].h = hNew;
                    cellDetails[successor_i][successor_j].parent_i = parent_i;
                    cellDetails[successor_i][successor_j].parent_j = parent_j;
                }
            }
        }
        return false;
}


// A Function to find the shortest path between
// a given source cell to a destination cell according
// to A* Search Algorithm
// if path not found: returns an empty Path:
//    path.size()=0;
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
    // This closed list is implemented as a boolean 2D vector
    vector<vector<bool>> closedList(ROW,vector<bool>(COL,false));

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
        W -->  West        (i, j-1)
        N.E--> North-East  (i-1, j+1)
        N.W--> North-West  (i-1, j-1)
        S.E--> South-East  (i+1, j+1)
        S.W--> South-West  (i+1, j-1)*/

        //----------- 1st Successor (North) ------------

        if(successor(cellDetails, openList, closedList, grid,
                         src, dest, i-1, j, i, j, diagonals))
            return tracePath (cellDetails, dest);

        //----------- 2nd Successor (South) ------------

        if(successor(cellDetails, openList, closedList, grid,
                         src, dest, i+1, j, i, j, diagonals))
            return tracePath (cellDetails, dest);

        //----------- 3rd Successor (East) ------------

        if(successor(cellDetails, openList, closedList, grid,
                         src, dest, i, j+1, i, j, diagonals))
            return tracePath (cellDetails, dest);

        //----------- 4th Successor (West) ------------

        if(successor(cellDetails, openList, closedList, grid,
                         src, dest, i, j-1, i, j, diagonals))
            return tracePath (cellDetails, dest);

        //-----------          Diagonals         ------------

        // the following successors are only
        // calculated if diagonal movement is
        // allowed
        if(diagonals){

          //----------- 5th Successor (North-East) ------------

            if(successor(cellDetails, openList, closedList, grid,
                             src, dest, i-1, j+1, i, j, diagonals))
                return tracePath (cellDetails, dest);

          //----------- 6th Successor (North-West) ------------

            if(successor(cellDetails, openList, closedList, grid,
                             src, dest, i-1, j-1, i, j, diagonals))
                return tracePath (cellDetails, dest);

          //----------- 7th Successor (South-East) ------------

            if(successor(cellDetails, openList, closedList, grid,
                             src, dest, i+1, j+1, i, j, diagonals))
                return tracePath (cellDetails, dest);

          //----------- 8th Successor (South-West) ------------

            if(successor(cellDetails, openList, closedList, grid,
                             src, dest, i+1, j-1, i, j, diagonals))
                return tracePath (cellDetails, dest);
        }
    }

    // When the destination cell is not found and the open
    // list is empty, then we conclude that we failed to
    // reach the destiantion cell. This may happen when the
    // there is no way to destination cell (due to blockages)
    if (foundDest == false)
        printf("\nA* finished: Failed to find the Destination Cell\n");
    return path;
}

// devuelve grid vacio si fila o columna < 2
Grid make_grid(int filas, int columnas){
    //validacion
    if (filas < 2 || columnas < 2 ){
      printf("Invalid size for the grid");
      Grid empty_grid(0,vector<int>(0));
      return empty_grid;
    }

    //crear el grid con UNBLOCKED
    Grid grid(filas);
    for ( int i = 0 ; i < filas ; i++ )
      grid[i].resize(columnas, UNBLOCKED);

    //asegurarse de que al menos dos posiciones sean UNBLOCKED 
    //para poder generar source y dest
    srand(time(NULL));
    int src_c, src_r, dest_c, dest_r;
    do{
      src_c = rand() % columnas;
      src_r = rand() % filas;
      dest_c = rand() % columnas;
      dest_r = rand() % filas;
    }while(src_c!=dest_c||src_r!=dest_r);
    for(int row = 0; row<grid.size() ; row++){
      for(int col = 0; col<grid[0].size() ; col++){
        //skip the two positions previously chosen
        if(row!=src_r && col!=src_c && row!=dest_r && col!=dest_c){
          int possibility = rand()%100;
          if(possibility<PERCENT_BLOCKED){
            grid[row][col]=BLOCKED;
          }
        }
      }
    }
    return grid;
}

// si el grid no es valido devuelve un resultado con posiciones -1
pair<Pair,Pair> make_src_dest(Grid grid){
  if(grid.size()<2 || grid[0].size()<2){
    printf("wrong size grid, too small\n");
    pair<Pair, Pair> invalid_pair({-1,-1},{-1,-1});
    return invalid_pair;
  }
  srand(time(NULL));
  vector<Pair> list;
  for(int row = 0; row<grid.size() ; row++){
    for(int col = 0; col<grid[0].size() ; col++){
      if(grid[row][col]==UNBLOCKED){
        list.push_back(make_pair(row,col));
      }
    }
  }
  if(list.size()<2){
    printf("grid doesnt have 2 free spaces for src/dest\n");
    pair<Pair, Pair> invalid_pair({-1,-1},{-1,-1});
    return invalid_pair;
  }
  int i = rand()%list.size();
  Pair src = make_pair(list[i].first, list[i].second);
  list.erase(list.begin()+i);
  i = rand()%list.size();
  Pair dest = make_pair(list[i].first, list[i].second);
  return make_pair(src,dest);
}
