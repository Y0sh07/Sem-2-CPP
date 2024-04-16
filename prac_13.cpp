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
    void getdata()
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
    void putdata()
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

    int searchid(string emp_id)
    {
        if (id == emp_id)
            return 1;

        else
            return 0;
    }

public:
    static void avgexp()
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
    void getdata()
    {

       employee :: getdata();
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

    void putdata()
    {
        employee :: putdata();
        cout.width(20);
        cout << left << "Employee Designation"
             << ":" << Designation << endl;
        cout.width(20);
        cout << left << "Employee Specialiazion "
             << ":" << specialization << endl;
        cout.width(20);
        cout << left << "Employee Pay Scale"
             << ":" << pay_scale << endl;
        avgexp();
    }

    int searchid(string emp_id)
    {

        return employee ::searchid(emp_id);
    }
};

class Non_Teaching_Empoyee : public employee
{
    int salary;

public:
    void getdata()
    {
       employee :: getdata();
        cout << "Enter Employee Salary :";
        cin >> salary;
        fflush(stdin);
    }

    void putdata()
    {
        employee :: putdata();
        cout.width(20);
        cout << left << "Employee Salary"
             << ":" << salary << endl;
    }

    int searchid(string emp_id)
    {

        return employee :: searchid(emp_id);
    }
};

int main()
{
    int Teach_Emp;
    int NonTeach_Emp;
    int i;
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
        a[i].getdata();
    }
    for (int i = 0; i < NonTeach_Emp; i++)
    {
        cout << "\nEnter Detail for " << i + 1 << "Non-Teaching Employee" << endl;
        b[i].getdata();
    }
    while (ch_condition == 'Y' || ch_condition == 'y')
    {
        int j=0,flag=0;
        cout << "Enter Employee id which you check:" << endl;
        cin >> emp_id;

        for (i = 0; i < Teach_Emp; i++)
        {
            j = a[i].searchid(emp_id);
            if (j == 1)
            {
                a[i].putdata();
                flag++;
                break;
            }
        }
        if(flag==0){
        for(int i=0;i<NonTeach_Emp;i++)
        {

            j = b[i].searchid(emp_id);
            if (j == 1)
            {
                b[i].putdata();
                flag++;
                break;
            }
        }
        }
        if (flag == 0)
        {
            cout << "ERROR, Id is not found..." << endl;
            break;
        }
        // for another employee details
        cout << "Press Y for Another Employee details:";
        cin >> ch_condition;
    }

    return 0;
}