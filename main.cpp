#include <iostream>
#include "BMP.h"
#include <cmath>
using namespace std;

int main() {
    //semi axis, moving up so can match bmp
    double a = 16 * sqrt(45);
    double b = 8 * sqrt(45);

    //changed from a, b to m, n so my ellipse variables would match the formula
    int m = a*2;
    int n = b*2;
    BMP bmpNew(m+1,n+1,false);

  //iterating from left side to right(x-axis) and calculating the y-values for each x-value 
    for (double x = -a; x <= a; x+=0.01) //decreased increment to improve smoothness
    {
        double y = (b * sqrt(1 - pow(x / a, 2)));
        bmpNew.set_pixel(a + x, b + y, 255, 255, 255, 0);
        bmpNew.set_pixel(a + x, b - y, 255, 255, 255, 0);
    }

  //circle time
  double cradius = a/2;
  for (double x2 = 0; x2 <= cradius; x2+=0.01)
  {
      double y2 = (b * sqrt(1 - pow(x2 / b, 2)));
      bmpNew.set_pixel(a + x2, b + y2, 0, 0, 255, 0);
      bmpNew.set_pixel(a + x2, b - y2, 0, 0, 255, 0);
  }

    bmpNew.write("output.bmp");
}
