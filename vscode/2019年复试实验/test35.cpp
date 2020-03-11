#include <iostream>
using namespace std;
class BaseDemo{
    public: 
    BaseDemo(){
        cout<< "调用基类构造函数"<<endl;
    }
};

class DerivedDemo: public BaseDemo{
    public: DerivedDemo(){
        cout<<"调用子类的构造函数"<<endl;
    }
};

int main()
{
    BaseDemo basedemo;
    DerivedDemo deriveddemo;
}