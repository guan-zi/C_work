#include <iostream>
#define PI 3.14
using namespace std;

class Basic
{
    private:
        double r;
    public:
        Basic(){r=0;}
        Basic(double a):r(a){}
};

class Cylinder: public Basic
{
    protected:
        double height;
    public:
                
        double setHeight(double h)
        {
            height = h;
            return  height;
        }
        double getVolume(void)
        {
            return PI*r*r*height;
        }
        double getArea(void){};
};
  
  Cylinder::getArea(void)
 {
      return PI*r*r*2+2*r*PI*height;
 }
  
  int main()
 {
    Cylinder cylin;
    cylin.Basic(5.0);
    cylin.setHeight(5.0);
    cout << "the surface area:" << cylin.getArea() << endl;
    cout << "the volume :" << cylin.getVolume() << endl;
    return 0;
}
