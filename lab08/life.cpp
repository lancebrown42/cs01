//******************************
// Conway's game of life
// Author: Lance Brown
// CS1021-001 March 3, 2014
//
// ***********************
//
// Description: Conway's game of life, given a starting board, the game progresses a set number of generations following a set of rules:
//     1. Any live cell with fewer than 2 live neighbors dies
//     2. Any live cell with two or three live neighbors lives
//     3. Any live cell with more than 3 live neighbors dies
//     4. Any dead cell with exactly three live neighbors becomes a live cell 
//
// Input: (optional) number of desired generations, Starting board as a .txt file
//
// Output: A display of each generation
//
// Procedure: Program reads in the txt file and assigns all the values to a char*, which it then
//     passes to the advancement function. This function checks all of the values on the board
//     to determine what their next state will be, and assigns the next state to a new board char*.
//     It checks each value for an edge case, as there is a different function to calculate the 
//     state of edges. It then returns the new board back to main and it loops until either the
//     final generation, or until all cells die
//
// Constraints: .txt file must start with height and width of board
//
// *****************************

#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

const char DEAD = '.';
const char ALIVE = 'O';


void printBoard(char* board, int width, int height){
  cout << "\033[2J\033[1;1H";
  
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
  int neighbors = 0;
  char* refresh = new char[size];
  for (int i = 0; i < size; i++){
    char* oldCell = board + i;
    char* newCell = refresh + i;
    int edge = 0;
    edge = isEdge(board, i, width, height);
    if (isEdge(board, i, width, height) == 0){
      neighbors = adjacent(board, i, width, height);
    } else if (!(isEdge(board, i , width, height) == 0)){
      neighbors = adjacentEdge(board, i, width, height, edge);
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
  delete[] board;
  return refresh;
}
bool gameOver (char* board, int width, int height){
  int size = width * height;
  bool endGame = true;
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      if (*(board + (i * width) + j) == ALIVE){
        return false;
        
      }
    }
  }
  return true;

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
  for (int i = 0; i < generationsToRun && !gameOver(board, width, height); i++){
    board = advance(board, width, height);
    cout << "\033[1;1H";
    printBoard(board, width, height);
    usleep(50000);
  }
  cout << endl;
  
  delete[] board;
  return 0;

}
