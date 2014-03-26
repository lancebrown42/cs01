/******************************
 * Task 1
 *
 *
 *
 *
 * ***************************/

#include <iostream>
#include <fstream>

using namespace std;
void draw(int x1, int x2, int y1, int y2, ofstream &outFile){
  outFile << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\"" << endl;
  outFile << "style=\"stroke:rgb(255,0,0);stroke-width:2;\"/>" << endl;
}
void coordinates(int x, int y, ofstream &outFile){
  outFile << "<text x=\"" << x << "\" y=\"" << y << "\" fill=\"black\">" << x << "," << y << "</text>" << endl;
}
int main(){
  ifstream inFile;
  ofstream outFile;
  outFile.open("grid.html");
  int x1 = 0;
  int x2 = 0;
  int y1 = 0;
  int y2 = 0;
  int x = 0;
  int y = 0;
  outFile << "<svg height=\"1000\" width=\"1000\">" << endl;
  for (int i = 0; i <= 10; i++){
    x1 = 100 * i;
    x2 = x1;
    y1 = 0;
    y2 = 1000;
    draw(x1,x2,y1,y2,outFile);

  }
  for (int i = 0; i <= 10; i++){
    x1 = 0;
    x2 = 1000;
    y1 = 100 * i;
    y2 = y1;
    draw(x1,x2,y1,y2,outFile);
  }
  for (int i = 0; i <= 10; i++){
    for (int j = 0; j <= 10; j++){
      x = i * 100;
      y = j * 100;
      coordinates (x,y,outFile);
    }
  }
  outFile << "</svg>" << endl;




return 0;

}
