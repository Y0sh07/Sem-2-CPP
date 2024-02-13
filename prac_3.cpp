#include <iostream>
#include <iomanip>
using namespace std;

class motors
{
    string airbeg[10];
    string Transmission[10];
    int Mileage[10];
    int Tank_Capacity[10];
    int Seating_capa[10];
public:
    string cars[10];
    string fuel[10];
    int price[10];
    int no_of_cars;

    void getdata()
    {
        // take input of car details
        cout << "How many cars you have :";
        cin >> no_of_cars;
        for (int i = 0; i < no_of_cars; i++)
        {
            cout << "Enter Car name :";
            cin >> cars[i];
            fflush(stdin);
            // first letter is capital in fuel type
            cout << cars[i] << " Fuel type is :";
            cin >> fuel[i];
            fflush(stdin);
            cout << cars[i] << " price is :";
            cin >> price[i];
            fflush(stdin);
            cout << cars[i] << " Mileage is :";
            cin >> Mileage[i];
            cout << cars[i] << " Transmission is :";
            cin >> Transmission[i];
            cout << cars[i] << " Tank Capacity is :";
            cin >> Tank_Capacity[i];
            cout << cars[i] << " Seating Capacity is :";
            cin >> Seating_capa[i];
            cout << " Airbag :";
            cin >> airbeg[i];
        }
    }

    void putdata(int x)
    {
        cout << setw(10) << cars[x];
        cout << setw(10) << fuel[x];
        cout << setw(10) << price[x];
        cout << setw(12) << Mileage[x];
        cout << setw(15) << Transmission[x];
        cout << setw(15) << Tank_Capacity[x];
        cout << setw(10) << Seating_capa[x];
        cout << setw(10) << airbeg[x] << endl;
    }
};

int main()
{
    int y;
    motors a;
    a.getdata();
    string for_fuel[4] = {"Petrol", "Diesel", "CNG", "EV"};

    while (y != 0)
    {
        cout << "\n\n";
        cout << "WELCOME TO Yash MOTORS" << endl;
        cout << "GET THE CAR DETAILS AS PER YOR PREFERENCE" << endl;
        cout << "1. Model Name" << endl;
        cout << "2. Fuel Type" << endl;
        cout << "3. Price Range" << endl;
        cout << "4. Exit" << endl
             << "\n";
        cout << "ENTER YOUR OPTION :";
        cin >> y;

        switch (y)
        {

            int x;
        case 1:
            // for displaying all cars
            cout << endl
                 << "List of Cars :\n"
                 << endl;
            for (int i = 0; i < a.no_of_cars; i++)
            {
                cout << i + 1 << "." << a.cars[i] << endl;
            }

            cout << "\nChoose Your Car To get details:";
            cin >> x;
            cout << "\n";
            cout << setw(10) << left << "Model" << setw(10) << "Fuel" << setw(10) << "price" << setw(12) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity" << setw(10) << "Seating" << setw(10) << "Airbages" << endl;
            cout << setw(20) << " " << setw(10) << "(Lakhs)" << setw(10) << "(km/L)" << setw(17) << " " << setw(15) << "(Liters)" << setw(12) << "Capacity" << endl;

            a.putdata(x - 1);

            break;
        case 2:
            // for type of fuel cars
            cout << "Yash Motors Available With Fuel option :" << endl;
            cout << "(1)Petrol  (2)Diesel  (3)CNG  (4)Electric" << endl;
            cout << "Enter Your Fuel Preference :";
            cin >> x;
            cout << setw(10) << left << "Model" << setw(10) << "Fuel" << setw(10) << "price" << setw(12) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity" << setw(10) << "Seating" << setw(10) << "Airbages" << endl;
            cout << setw(20) << " " << setw(10) << "(Lakhs)" << setw(10) << "(km/L)" << setw(17) << " " << setw(15) << "(Liters)" << setw(12) << "Capacity" << endl;

            for (int i = 0; i < a.no_of_cars; i++)
            {
                if (for_fuel[x - 1] == a.fuel[i])
                {
                    a.putdata(i);
                }
            }
            break;
        case 3:
            // for price
            cout << "Enter Your Maximun Affordable Range in Lakhs :";
            cin >> x;
            cout << setw(10) << left << "Model" << setw(10) << "Fuel" << setw(10) << "price" << setw(12) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity" << setw(10) << "Seating" << setw(10) << "Airbages" << endl;
            cout << setw(20) << " " << setw(10) << "(Lakhs)" << setw(10) << "(km/L)" << setw(17) << " " << setw(15) << "(Liters)" << setw(12) << "Capacity" << endl;

            for (int i = 0; i < a.no_of_cars; i++)
            {
                if (a.price[i] <= x)
                {
                    a.putdata(i);
                }
            }
            break;

        case 4:
            return 0;
        }
    }
}