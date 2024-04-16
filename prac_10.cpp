#include <iostream>
using namespace std;

class employee_exp
{
    int year;
    int month;

public:
    void cal_exp(float x)
    {
        year = x;
        month = ((x - year) * 100) / 8;
    }
    void putdata()
    {
        cout << "Employee Experiance is " << year << "years and " << month << "months";
    }
};

int main()
{
    employee_exp c;
    float a;
    cin >> a;

    c.cal_exp(a);
    c.putdata();

    return 0;
}