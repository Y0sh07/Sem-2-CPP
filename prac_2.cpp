#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct employee
{

    int id;
    string name;
    string qucalification;
    int experince;
    long long int phone_number;

    void getdetail()
    {
        // Enter employee details
        cout << "Enter the Employee ID:";
        cin >> id;
        fflush(stdin);
        cout << "Enter thes Empoyee Name: ";
        cin >> name;
        fflush(stdin);
        cout << "Enter the Qucalification:";
        cin >> qucalification;
        cout << "Enter Experince:";
        cin >> experince;
        cout << "Enter the Contact Number:";
        cin >> phone_number;
        fflush(stdin);
    }
    void putdata()
    {
        cout.width(20);
        cout << left << "Employee ID"<< ":" << id << endl;
        cout.width(20);
        cout << left << "Employee Name"<< ":" << name << endl;
        cout.width(20);
        cout << left << "Qucalification"<< ":" << qucalification << endl;
        cout.width(20);
        cout << left << "Experince"<< ":" << experince << endl;
        cout.width(20);
        cout << left << "Contact Number" << ":" << phone_number << endl;
    }
};
int main()
{
    int n;
    int i;
    char ch_condition = 'y';
    int emp_id;

    cout << "Enter the number of Employees :";
    cin >> n;
    cout << endl;
    employee a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Detail for " << i + 1 << "Employee" << endl;
        a[i].getdetail();
    }
    while ( ch_condition == 'Y' ||  ch_condition == 'y')
    {
        cout << "Enter Employee id which you check:" << endl;
        cin >> emp_id;

        for (i = 0; i < n; i++)
        {
            if (emp_id == a[i].id)
            {

                a[i].putdata();
                break;
            }
        }
        if (i == n)
        {
            cout << "ERROR" << endl;
        }
        //for another employee details
        cout << "Press Y for Another Employee details:";
        cin >> ch_condition;
    }
}