#include <iostream>
#include<fstream>
#include <iomanip>
using namespace std;

class motors
{
    string airbag;
    string Transmission;
    float Mileage;
    float Tank_Capacity;
    int Seating_capa;
    string cars;
    string fuel;
    float price;
    int no_of_cars;
public:

 string getmodel() {
        return cars;
    }

    string getfuel() {
        return fuel;
    }

    float getprice() {
        return price;
    }

    void getdata(string car,string fuel_type,float price1,float mileage1,string transmission,float tank_Capacity,int seating_capacity,string airbags)
    {
         cars=car;
         fuel =fuel_type;
         price=price1;
         Mileage=mileage1;
         Transmission=transmission;
         Tank_Capacity=tank_Capacity;
         Seating_capa=seating_capacity;
         airbag=airbags; 
    }

    void putdata()
    {
        cout << setw(10) << cars;
        cout << setw(10) << fuel;
        cout << setw(10) << price;
        cout << setw(12) << Mileage;
        cout << setw(15) << Transmission;
        cout << setw(15) << Tank_Capacity;
        cout << setw(10) << Seating_capa;
        cout << setw(10) << airbag << endl;
    }
};

int main()
{
    motors a[100];
    int y=1;
    string for_fuel[4] = {"Petrol", "Diesel", "CNG", "EV"};
    

    ifstream inf("cardata.txt");

    if (!inf) {
		cout << "Unable to open file";
		return 1;
	}

	cout<<"File opened successfully\n";


	string model_name,fuel_type, trans, airbag;
	string price, mileage, tc;
	float price1, mileage1, tc1;
	string seating;
	int seating1,count=0;

	while(inf)
    {
        getline(inf,model_name,',');
        getline(inf,fuel_type,',');
        getline(inf,price,',');
        price1 = stof(price);
        getline(inf,mileage,',');
        mileage1 = stof(mileage);
        getline(inf,trans,',');
        getline(inf,tc,',');
        tc1 = stof(tc);
        getline(inf,seating,',');
        seating1 = stod(seating);
        getline(inf,airbag,';');


        a[count++].getdata(model_name,fuel_type,price1,mileage1,trans,tc1,seating1,airbag);

    }

    inf.close();

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
            for (int i = 0; i < count-1; i++)
            {
                cout << i + 1 << "." << a[i].getmodel() << endl;
            }

            cout << "\nChoose Your Car To get details:";
            cin >> x;
            cout << "\n";
            cout << setw(10) << left << "Model" << setw(10) << "Fuel" << setw(10) << "price" << setw(12) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity" << setw(10) << "Seating" << setw(10) << "Airbages" << endl;
            cout << setw(20) << " " << setw(10) << "(Lakhs)" << setw(10) << "(km/L)" << setw(17) << " " << setw(15) << "(Liters)" << setw(12) << "Capacity" << endl;
           
           
            a[x-1].putdata();
           

            break;
        case 2:
            // for type of fuel cars
            cout << "Yash Motors Available With Fuel option :" << endl;
            cout << "(1)Petrol  (2)Diesel  (3)CNG  (4)Electric" << endl;
            cout << "Enter Your Fuel Preference :";
            cin >> x;
            cout << setw(10) << left << "Model" << setw(10) << "Fuel" << setw(10) << "price" << setw(12) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity" << setw(10) << "Seating" << setw(10) << "Airbages" << endl;
            cout << setw(20) << " " << setw(10) << "(Lakhs)" << setw(10) << "(km/L)" << setw(17) << " " << setw(15) << "(Liters)" << setw(12) << "Capacity" << endl;

            for (int i = 0; i < count-1; i++)
            {
                if (for_fuel[x - 1] == a[i].getfuel())
                {
                    a[i].putdata();
                }
            }
            
            break;
        case 3:
            // for price
            float t;
            cout << "Enter Your Maximun Affordable Range in Lakhs :";
            cin >> t;
            cout << setw(10) << left << "Model" << setw(10) << "Fuel" << setw(10) << "price" << setw(12) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity" << setw(10) << "Seating" << setw(12) << "Airbages" << endl;
            cout << setw(20) << " " << setw(10) << "(Lakhs)" << setw(10) << "(km/L)" << setw(17) << " " << setw(15) << "(Liters)" << setw(12) << "Capacity" << endl;

            for (int i = 0; i < count; i++)
            {
                if (a[i].getprice() <= t)
                {
                    a[i].putdata();
                }
            }
            break;

        case 4:
            return 0;
        }
    }
}