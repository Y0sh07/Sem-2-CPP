#include <iostream>
using namespace std;

class complex_num
{
    float x, y;

public:
    void getdata()
    {
        cout << "Enter real part :";
        cin >> x;
        cout << "Enter emaginary part :";
        cin >> y;
    }
    void putdata()
    {
        cout << x << "+"
             << "(" << y << ")"
             << "i" << endl;
    }

    complex_num operator+(complex_num &p)
    {
        complex_num o;
        o.x = x + p.x;
        o.y = y + p.y;
        return o;
    }

    complex_num operator-(complex_num &p)
    {
        complex_num o;
        o.x = x - p.x;
        o.y = y - p.y;
        return o;
    }

    complex_num operator*(complex_num &p)
    {
        complex_num o;
        o.x = (x * p.x) - (y * p.y);
        o.y = (x * p.y) + (y * p.x);
        return o;
    }

    complex_num operator/(complex_num &p)
    {
        complex_num o;
        o.x = ((x * p.x) + (y * p.y)) / ((p.x * p.x) + (p.y * p.y));
        o.y = ((y * p.x) - (x * p.y)) / ((p.x * p.x) + (p.y * p.y));
        return o;
    }

    complex_num operator!()
    {
        complex_num o;
        o.x = -x;
        o.y = -y;
        return o;
    }
};

int main()
{
    complex_num a, b, c;
    char condition;
    a.getdata();
    b.getdata();
    cout << "Choose operation :" << endl;
    cout << "(+) addition" << endl
         << "(-) subtraction" << endl
         << "(*) multiplication" << endl
         << "(/) division" << endl
         << "(!) negation" << endl;
    cout << "Enter Your Choice :";
    cin >> condition;

    switch (condition)
    {
    case '+':
        c = a + b;
        c.putdata();
        break;

    case '-':
        c = a - b;
        c.putdata();
        break;

    case '*':
        c = a * b;
        c.putdata();
        break;

    case '/':
        c = a / b;
        c.putdata();
        break;

    case '!':
        c = !a;
        c.putdata();
        c = !b;
        c.putdata();
    }
}