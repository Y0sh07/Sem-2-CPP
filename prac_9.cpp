#include <iostream>
using namespace std;

class cm_convertor;

class mm_convertor
{
    float mm;
    float cm;

public:
    mm_convertor(float a)
    {
        mm = a;
        cm = a;
    }

    operator float()
    {
        mm = cm * 10;
        return mm;
    }

    float value()
    {
        return mm;
    }

    void display(float b)
    {
        cout << "Measurement in mm :" << b;
    }
};

class cm_convertor
{
    float cm;

public:
    cm_convertor(float x)
    {
        cm = x;
    }

    cm_convertor(mm_convertor &a)
    {
        float s = a.value();
        cm = s / 10;
    }
    float value()
    {
        return cm;
    }
    void display()
    {
        cout << "Measurement in cm :" << cm;
    }
};

int main()
{
    int d;
    float x;

    cout << "Enter 1: mm to cm converter " << endl;
    cout << "Enter 2: cm to mm converter " << endl;

    cin >> d;

    switch (d)
    {
    case 1:
    {

        cout << "Enter measurements in mm :";
        cin >> x;
        mm_convertor a(x);
        cm_convertor b(a);

        b.display();

        break;
    }
    case 2:
    {
        float b;

        cout << "Enter measurements in cm :";
        cin >> x;
        mm_convertor d(x);
        b = d;
        d.display(b);

        break;
    }

        return 0;
    }
}