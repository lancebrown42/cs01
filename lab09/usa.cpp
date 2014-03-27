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
  x -= min;
  x *= 20;
  return abs(x);
}
void draw(ifstream &inFile, ofstream &outFile, double minLong, double maxLat){
  string subregion;
  string region;
  string multiword;//keeps washington dc, new-anything from fucking everyhting up
  int points = 0;
  double x = 0;
  double y = 0;
    inFile >> subregion;
    if (subregion == "District"){
      inFile >> multiword >> multiword;
    }else if (subregion == "New" || subregion == "North" || subregion == "South" || subregion == "West" || subregion == "Rhode"){
      inFile >> multiword;
    }
    inFile >> region;
    inFile >> points;
  outFile << "<polygon points=\"";
  for (int i = 0; i < points; i++){
    inFile >> x >> y;
    x = convert(x,minLong);
    y = convert(maxLat,y);
    outFile << x << "," << y;
    if (i < points - 1){
      outFile << " ";
    }
  }
  outFile << "\" style=\"fill:lime;stroke:black;stroke-width:1\" /> ";


}
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
  double width = 0;
  double height = 0;
  width = convert(maxLong,minLong);
  height = convert(maxLat,minLat);
  outFile << "<svg height=\"" << height << "\" width=\"" << width <<"\">" << endl;
  for (int i = 0; i < regions; i++){
    draw(inFile, outFile, minLong, maxLat);
    
  }
  outFile << " </svg>" ;
  inFile.close();
  outFile.close();
  cout << "height: " << height << endl << "width: " << width << endl;
  return 0;
}
