#ifndef ASEARCH_HPP
#define ASEARCH_HPP

#include <bits/stdc++.h>

// valores para las celdas
#define UNBLOCKED 1
#define BLOCKED   0
// porcentage de celdas bloqueadas en el mapa
#define PERCENT_BLOCKED 40

using namespace std;


// forward declaration of cell, implementation inside .cpp
struct cell;
// Creating a shortcut for int, int pair type
typedef pair<int, int> Pair;
// Creating a shortcut for pair<int, pair<int, int>> type
typedef pair<double, pair<int, int>> pPair;
// Grid shortcut
typedef vector<vector<int>> Grid;
// Path Found
// Empty if none found
typedef deque<Pair> Path;
// 2D array of cells
typedef vector<vector<cell>> cellGrid;

pair<Pair,Pair> make_src_dest(Grid grid);
Grid make_grid(int filas,int columnas);
Path aStarSearch(Grid grid,Pair src,Pair dest,bool diagonals);
bool successor(cellGrid&cellDetails,set<pPair>&openList,vector<vector<bool>>&closedList,Grid grid,Pair src,Pair dest,int successor_i,int successor_j,int parent_i,int parent_j,bool diagonals);
bool validate_src_dest(Grid grid,Pair src,Pair dest);
Grid grid_from_path(Path path,Grid grid);
Path tracePath(cellGrid cellDetails,Pair dest);
double calculateHValue(int row,int col,Pair dest,bool diagonals);
bool isDestination(int row,int col,Pair dest);
bool isUnBlockedDiagonally(Grid grid,int src_row,int src_col,int dest_row,int dest_col,bool diagonals);
bool isUnBlocked(Grid grid,int row,int col);
void print_path(Path path);
void print_pair(Pair pair);
void print_grid(Grid grid);
bool isValid(int row,int col,Grid grid);


#endif /* ASEARCH_HPP */