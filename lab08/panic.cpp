//******************************
// Conway's game of life
// Author: Lance Brown
// CS1021-001 March 3, 2014
//
// ***********************
//
// Description: 
//
// Input:
//
// Output:
//
// Procedure:
//
// Constraints:
//
// *****************************

#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

const char DEAD = '.';
const char ALIVE = 'O';

void printTest(int* neigh, int width, int height){
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      cout << *(neigh + (width * i) + j) << " ";
    }
    cout << endl;
  }
}

void printBoard(char* board, int width, int height){
 // cout << "\033[2J\033[1;1H";
  
  for (int i = 0; i < height; i++){
    for (int j = 0; j < width; j++){
      cout << *(board + (width * i) + j) << " ";
    }
    cout << endl;
  }
}

int isEdge(char* board, int offset, int width, int height){//check if cell is on edge of the board
  int edge = 0;
  char* cell = board + offset;
  if (offset >= 0 && offset < width){//north edge
    edge = 1;
  }
  if ((offset + 1) % width == 0){//east edge
    if (edge == 1){//northeast
      edge = 6;
    }
    else{ 
      edge = 2;
    }
  }
  if (offset >= width * height - width && offset < width * height){//south edge
    if (edge == 2){
      edge = 7;
    }else{
    edge = 3;
    }
  }
  if (offset % width == 0){//west edge?
    if (edge == 1){//northwest
      edge = 5;
    }else if (edge == 3){//southwest
      edge = 8;
    }else{
      edge = 4;
    }
  }
  return edge;
}
int adjacent(char* board, int offset, int width, int height){//checks the state of surrounding cells
  int alive = 0; //number of living adjacent cells
  char* cell = board + offset;
  if (*(cell - 1) == ALIVE){//cell to the west
    alive++;
  }
  if (*(cell + 1) == ALIVE){//celll to the east
    alive++;
  }
  if (*(cell - width) == ALIVE) {//cell north
    alive++;
  }
  if (*(cell + width) == ALIVE) {//cell south
    alive++;
  }
  if (*(cell - width - 1) == ALIVE) {//northwest
    alive++;
  }
  if (*(cell - width + 1) == ALIVE) {//northeast
    alive++;
  }
  if (*(cell + width - 1) == ALIVE) {//southwest
     alive++;
     }
  if (*(cell + width + 1) == ALIVE) {//southeast
    alive++;
  }


  return alive;
}
int adjacentEdge(char* board, int offset, int width, int height, int edge){
  int alive = 0;
  char* cell = board + offset;
  if (edge == 1){//north not corner
    if (*(cell - 1) == ALIVE){
      alive++;
    }
    if (*(cell + 1) == ALIVE){
      alive++;
    }
    if (*(cell + width) == ALIVE){
      alive++;
    }
    if (*(cell + width - 1) == ALIVE) {
      alive ++;
    }
    if (*(cell + width + 1) == ALIVE) {
      alive++;
    }
  }
  if (edge == 2){//east not corner
    if(*(cell - 1) == ALIVE){
      alive++;
    }
    if (*(cell + width) == ALIVE){
      alive++;
    }
    if (*(cell + width - 1) == ALIVE){
      alive++;

    }
    if (*(cell - width) == ALIVE){
      alive++;
    }
    if (*(cell - width - 1) == ALIVE){
      alive++;
    }
  }
  if (edge == 3){//south not corner
    if (*(cell - 1) == ALIVE){
      alive++;
    }
    if (*(cell + 1) == ALIVE){
      alive++;
    }
    if (*(cell - width) == ALIVE){
      alive++;
    }
    if (*(cell - width - 1) == ALIVE){
      alive++;
    }
    if (*(cell - width + 1) == ALIVE){
      alive++;
    }
  }
  if (edge == 4){//west not corner
    if (*(cell + 1) == ALIVE){
      alive++;
    }
    if (*(cell + width) == ALIVE){
      alive++;
    }
    if (*(cell + width + 1) == ALIVE){
      alive++;
    }
    if (*(cell - width) == ALIVE){
      alive++;
    }
    if (*(cell - width + 1) == ALIVE){
      alive++;
    }
  }
  if (edge == 5){//northwest
    if (*(cell + 1) == ALIVE){
      alive++;
    }
    if (*(cell + width) == ALIVE){
      alive++;
    }
    if (*(cell +width + 1) == ALIVE){
      alive++;
    }
  }
  if (edge == 6){//northeast
    if (*(cell -1) == ALIVE){
      alive++;
    }
    if (*(cell + width) == ALIVE){
      alive++;
    }
    if (*(cell + width - 1) == ALIVE){
      alive++;
    }
  }
  if (edge == 7){//southeast
    if (*(cell - 1) == ALIVE){
      alive++;
    }
    if (*(cell - width) == ALIVE){
        alive++;
        }
    if (*(cell - width - 1) == ALIVE){
      alive++;
    }
  }
  if (edge == 8){//southwest
    if(*(cell + 1) == ALIVE){
      alive++;
    }
    if(*(cell - width) == ALIVE){
      alive++;
    }
    if(*(cell - width + 1) == ALIVE){
      alive++;
    }
  }
  return alive;
}//that was a really stupid way to do that

char* advance(char* board, int width, int height){
  int size = width * height;
  char* refresh = new char[size];
  int* nextTo = new int[size];
  int neighbors = 0;
  for (int i = 0; i < size; i++){
    char* oldCell = board + i;
    char* newCell = refresh + i;
    int edge = 0;
    edge = isEdge(board, i, width, height);
    if (isEdge(board, i, width, height) == 0){
      neighbors = adjacent(board, i, width, height);
      *(nextTo + i) = neighbors;
    } else if (!(isEdge(board, i , width, height) == 0)){
      neighbors = adjacentEdge(board, i, width, height, edge);
      *(nextTo + i) = neighbors;
    }
    if (*oldCell == ALIVE){
      if (neighbors < 2 || neighbors > 3){
        *newCell = DEAD;
    }
      else {
        *newCell = ALIVE;
      }
    }
    else if (*oldCell == DEAD){
      if (neighbors == 3){
        *newCell = ALIVE;
      }
      else {
        *newCell = DEAD;
      }
    }
  }
  cout << endl;
  printTest(nextTo,width,height);
  return refresh;
}

int main (int argc, char*argv[]) {
  //Default generations to run is 100, but allow the user to 
  //pass in a different value on the command line.
  int generationsToRun = 100;
  if (argc > 1) {
    generationsToRun = atoi(argv[1]);
  
  }
  int width = 0;
  int height = 0;
  cin >> width >> height;
  int size = width * height;
  char* board = new char[size];
  for (int i = 0; i < size; i++){
    cin >> board[i];
  }
  printBoard(board, width, height);
  board = advance(board, width, height);
  cout << endl<<endl;
  printBoard(board, width, height);
  cout << endl;
  delete[] board;
  
  return 0;

}
