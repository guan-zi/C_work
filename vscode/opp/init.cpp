#include <iostream>
using namespace std;


class Line
{
    public:
        void setLength(double len);
        double getLength(void);
        Line(double len);
        Line(void);
    protected:
            double length;
};

void Line::setLength(double len)
{
    length = len;
}

double Line :: getLength(void)
{
    return length;
}

Line::Line(double len):length(len){}
Line::Line()
{
    length = 0;
}

int main()
{
    Line line(10.0);
    cout << "Line length:" << line.getLength() <<endl;

    line.setLength(5.0);
    cout << "Line length:" << line.getLength() <<endl;
    Line line2;

    cout << "Line2 length:" << line2.getLength() <<endl;
    return 0;
}