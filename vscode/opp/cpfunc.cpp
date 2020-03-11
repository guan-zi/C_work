#include <iostream>

using namespace std;

class Line
{
    public:
        int getLength(void);
        Line (int len);//构造函数
        Line(const Line &obj);//拷贝构造函数
        ~Line();//析构函数
    
    private:
        int *ptr;
};

Line ::Line(const Line &obj)//拷贝构造函数的实现
{
    cout << "调用拷贝构造函数并为指针ptr分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}


// 成员函数定义包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 尾指针分配内存;
    ptr = new int;
    *ptr = len; // 拷贝值
}

Line:: ~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}

int Line:: getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "Line size:" << obj.getLength() << endl;
}

int main()
{
    Line line(10);
    Line line2 = line;
    display(line);
    display(line2);
    return 0;
}
