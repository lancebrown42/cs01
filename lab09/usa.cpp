/*****************************
 * USA USA USA USA USA USA
 *
 *
 *
 *
 * **************************/

#include <iostream> 
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

double convert(double x, double min){
  x = abs(x);
  x += abs(min);
  x *= 7;
  return x;
}
void draw(ifstream &inFile, ofstream &outFile, double minLong, double minLat){
  string subregion;
  string region;
  string buffer;
  int points = 0;
  double x = 0;
  double y = 0;
    inFile >> subregion;
    inFile >> region;
    inFile >> points;
  //outFile << "<polygon points=\"";
  cout << "state: " << subregion << endl;
  cout << "points: " <<  points << endl;
  for (int i = 0; i < points; i++){
    inFile >> x >> y;
    x = convert(x,minLong);
    y = convert(y,minLat);
    outFile << x << "," << y << " ";
    //if (i < points - 1){
      //outFile << " ";
   // }
  }
  //outFile << "\" style=\"fill:lime;stroke:black;stroke-width:1\" /> ";


}
//void drawBound(int x1, int y1, int x2, int y2, ofstream &outFile){
  
 // outFile << "<line x1 =\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\"" << endl;
 // outFile << "style=\"stroke:rgb(255,0,0);stroke-width:2;\" />" << endl;
//}
int main(){
  ifstream inFile;
  ofstream outFile;
  inFile.open("USA.txt");
  outFile.open("usa.html");
  double minLong = 0;
  double minLat = 0;
  double maxLong = 0;
  double maxLat = 0;
  int regions = 0;
  inFile >> minLong >> minLat >> maxLong >> maxLat >> regions;
  cout << "Min long: " << minLong << " lat: " << minLat << endl;
  cout << "Max long: " << maxLong << " lat: " << maxLat << endl;
  cout << "Regions: " << regions << endl;
  int width = 0;
  int height = 0;
  width = convert(maxLong,minLong);
  height = convert(maxLat,minLat);
  outFile << "<svg height=\"" << height << "\" width=\"" << width <<"\">" << endl;
  outFile << "polygon points=\"";
  //drawBound(0,0,width,0,outFile);
  //drawBound(0,0,0,height,outFile);
  //drawBound(width,0,width,height,outFile);
  //drawBound(0,height,width,height,outFile);
  regions = 2;
  for (int i = 0; i < regions; i++){
    draw(inFile, outFile, minLong, minLat);
    
  }
  outFile << "\" style=\"fill:lime;stroke:black;stroke-width:1\" />";
  outFile << " </svg>" ;
  inFile.close();
  outFile.close();
  cout << "height: " << height << endl << "width: " << width << endl;
  return 0;
}
