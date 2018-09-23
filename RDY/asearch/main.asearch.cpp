#include <bits/stdc++.h>
#include "asearch.hpp"
using namespace std;

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
        { 1, 1, 0, 0, 1, 1, 1, 0, 1, 0 },
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
    print_grid(grid);
    print_grid(grid_result);

    printf("\n------sin diagonales-----\n");
    result = aStarSearch(grid, src, dest, false);
    print_path(result);
    grid_result = grid_from_path(result,grid);
    print_grid(grid);
    print_grid(grid_result);

    printf("\n-----ejemplo con mapa generado-----\n\n");
    grid = make_grid(6,8);
    print_grid(grid);
    pair<Pair,Pair> points = make_src_dest(grid);
    printf("source y destination generados:\n");
    print_pair(points.first);
    print_pair(points.second);
    result = aStarSearch(grid, points.first, points.second, false);
    grid_result = grid_from_path(result,grid);
    print_grid(grid_result);



    return(0);


}
