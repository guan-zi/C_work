#include <iostream>
using namespace std;

class Shape
{
    protected:
        int width;
        int height;
    public:
        int setWidth(int w)
        {
            width = w;
            return width;
        }
        int setHeight(int h)
        {
            height = h;
            return height;
        }
};


class Rectangle: public Shape
{
    public:
        int getArea()
        {
            cout << "width:" << width << endl;
            cout << "height:" << height << endl;
            return (width*height);
        }
};

int main()
{
    Rectangle rect;
    // rect.setWidth(5);
    // rect.setHeight(7);
    cout << "height:"<< rect.setHeight(5)<< endl;
    cout << "width:"<< rect.setWidth(7)<< endl;
    int area;
    // area = rect.getArea();
    cout << "Total area:\n" << rect.getArea() <<endl;
    return 0;
}