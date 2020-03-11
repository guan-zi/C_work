#include <iostream>
using namespace std;

class Line
{
    protected:
        double length;
    public:
        void setLength(double len)
        {
            length = len;
        }
        double getLength(void);
        Line();
        Line(double len);
        ~Line();
};

double Line::getLength()
{
    return length;
}
Line :: Line()
{
    cout << "Object have been created;\n";
}

Line::Line(double len):length(len)
{
    cout << "Object have been created;\n";
}

Line:: ~Line()
{
    cout << "Object is being deleted;\n";
}


int main()
{
    Line line;
    line.setLength(10);
    cout << "Length of line:" << line.getLength() <<endl;
    return 0;
}
