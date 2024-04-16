#include <iostream>
using namespace std;

class employee_exp
{
    float experiance;

public:
    employee_exp(int a, int b)
    {
        experiance = a;
        experiance = experiance + (float)b / (float)12;
    }

    operator float()
    {
        return experiance;
    }
};

int main()
{
    int a;
    int b;
    float s;
    cin >> a;
    cin >> b;
    employee_exp c(a, b);
    s = c;
    cout << "Employee Experiance is " << s;

    return 0;
}