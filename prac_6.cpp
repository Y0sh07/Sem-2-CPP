#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class employee
{
    

    static int sum_experince;
    static  int  count;
    string id;
    string name;
    string qucalification;
    int experince;
    long long int phone_number;


    public:

    void getdetail()
    {
        // Enter employee details
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
        sum_experince+=experince;
        count++;

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
    string get_id()
    {
        return id;
    }
   static void avg_of_experince()
    {
        cout<<"\n\naverage experince is :"<<(float)sum_experince/count<<endl;                                
    }
};
int employee ::  sum_experince;
int employee :: count;



int main()
{
   static employee s;
    int n;
    int i;
    char ch_condition = 'y';
    string emp_id;

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
            if (emp_id == a[i].get_id())
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


    s.avg_of_experince();  
    return 0;
       
}