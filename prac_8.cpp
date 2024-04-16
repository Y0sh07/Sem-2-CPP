#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class employee
{

    static int count;
    static float average_experiance;
    string id;
    string name;
    string qucalification;
    int experince;
    long long int phone_number;

protected:
    void getempdata()
    {
        // Enter employee details
        count++;
        fflush(stdin);
        cout << "Enter the Employee ID:";
        cin >> id;

        cout << "Enter thes Empoyee Name:";
        fflush(stdin);
        cin >> name;
        cout << "Enter the Qucalification:";
        cin >> qucalification;
        cout << "Enter Experince:";
        cin >> experince;
        cout << "Enter the Contact Number:";
        cin >> phone_number;
        fflush(stdin);
        average_experiance += experince;
    }
    void putempydata()
    {
        cout.width(20);
        cout << left << "Employee ID"
             << ":" << id << endl;
        cout.width(20);
        cout << left << "Employee Name"
             << ":" << name << endl;
        cout.width(20);
        cout << left << "Qucalification"
             << ":" << qucalification << endl;
        cout.width(20);
        cout << left << "Experince"
             << ":" << experince << endl;
        cout.width(20);
        cout << left << "Contact Number"
             << ":" << phone_number << endl;
        fflush(stdin);
    }

    int searchemp(string emp_id)
    {
        if (id == emp_id)
            return 1;

        else
            return 0;
    }

public:
    static void avg_of_experince()
    {
        cout << "\n\naverage experince is :" << (float)average_experiance / count << endl;
    }
};
int employee ::count;
float employee ::average_experiance;

class Teaching_Employee : public employee
{
    string Designation;
    string specialization;
    string pay_scale;

public:
    void gettempdata()
    {

        getempdata();
        fflush(stdin);
        cout << "Enter Designation :";
        getchar();
        getline(cin, Designation);

        cout << "Enter Specialization :";
        getchar();
        getline(cin, specialization);

        cout << "Enter Pay Scale :";
        getchar();
        getline(cin, pay_scale);
        fflush(stdin);
    }

    void puttempydata()
    {
        putempydata();
        cout.width(20);
        cout << left << "Employee Designation"
             << ":" << Designation << endl;
        cout.width(20);
        cout << left << "Employee Specialiazion "
             << ":" << specialization << endl;
        cout.width(20);
        cout << left << "Employee Pay Scale"
             << ":" << pay_scale << endl;
        avg_of_experince();
    }

    int searchtemp(string emp_id)
    {
        return searchemp(emp_id);
    }
};

class Non_Teaching_Empoyee : public employee
{
    int salary;

public:
    void getntempdata()
    {
        getempdata();
        cout << "Enter Employee Salary :";
        cin >> salary;
        fflush(stdin);
    }

    void putntempydata()
    {
        putempydata();
        cout.width(20);
        cout << left << "Employee Salary"
             << ":" << salary << endl;
    }

    int searchntemp(string emp_id)
    {

        return searchemp(emp_id);
    }
};

int main()
{
    int Teach_Emp;
    int NonTeach_Emp;
    int i, j = 0;
    char ch_condition = 'y';
    string emp_id;

    cout << "Enter the number of Teaching Employees :";
    cin >> Teach_Emp;
    cout << "Enter the number of Non-Teaching Employees :";
    cin >> NonTeach_Emp;
    cout << endl;
    Teaching_Employee a[Teach_Emp];
    Non_Teaching_Empoyee b[NonTeach_Emp];
    for (int i = 0; i < Teach_Emp; i++)
    {
        cout << "\nEnter Detail for " << i + 1 << "Teaching Employee" << endl;
        a[i].gettempdata();
    }
    for (int i = 0; i < NonTeach_Emp; i++)
    {
        cout << "\nEnter Detail for " << i + 1 << "Non-Teaching Employee" << endl;
        b[i].getntempdata();
    }
    while (ch_condition == 'Y' || ch_condition == 'y')
    {
        cout << "Enter Employee id which you check:" << endl;
        cin >> emp_id;

        for (i = 0; i < Teach_Emp + NonTeach_Emp; i++)
        {
            j = a[i].searchtemp(emp_id);
            if (j == 1)
            {
                a[i].puttempydata();
                break;
            }

            j = b[i].searchntemp(emp_id);
            if (j == 1)
            {
                b[i].putntempydata();
                break;
            }
        }
        if (j == 0)
        {
            cout << "ERROR" << endl;
        }
        // for another employee details
        cout << "Press Y for Another Employee details:";
        cin >> ch_condition;
    }

    return 0;
}