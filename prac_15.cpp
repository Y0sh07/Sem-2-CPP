#include<iostream>
#include<iomanip>

using namespace std;




class product
{
    protected:

     int product_id;
     string product_name;
     string product_manufacturer;
     int product_price;

     public:

     product(int product_id,string product_name,string product_manufacturer,int product_price)
     {
        this->product_id=product_id;
        this->product_name=product_name;
        this->product_manufacturer=product_manufacturer;
        this->product_price=product_price; 
     }

     virtual void putdata()=0;
};

class smartwatch :public product
{
    int dial_size;

    public:

    smartwatch(int product_id,string product_name,string product_manufacturer,int product_price,int dia_size) :product(product_id,product_name,product_manufacturer,product_price)
    {
        this->dial_size=dia_size;
    }

    void putdata()
    {
       cout<<product_id<<"   :   "<<product_name<<"   :   "<<product_manufacturer<<"   :   "<<product_price<<"   :   "<<dial_size;
    }

};

class bedsheet :public product
{
    

    float width,height;

    public:

    bedsheet(int product_id,string product_name,string product_manufacturer,int product_price,float width,float height ) :product(product_id,product_name,product_manufacturer,product_price)
    {
        this->width=width;
        this->height=height;
    }

    void putdata()
    {
        cout<<product_id<<"   :   "<<product_name<<"   :   "<<product_manufacturer<<"   :   "<<product_price<<"   :   "<<width<<"   :   "<<height;        
    }

};


int main()
{
    int x,pr_id,price;
    string pr_name,pr_manuf;
    cout<<"Enter 1: Smart Watch Menu"<<endl;
    cout<<"Enter 2: bedsheet menu"<<endl;
    cout<<"Enter your choice :";
    cin>>x;

    switch(x)
    {
        case 1:
        {

        int dial_size;

        cout<<"Enter product id :";
        cin>>pr_id;
        cout<<"Enter product name :";
        cin>>pr_name;
        cout<<"Enter product manufacturer :";
        cin>>pr_manuf;
        cout<<"Enter product price :";
        cin>>price;
        cout<<"Enter product dial size :";
        cin>>dial_size;

        smartwatch a (pr_id,pr_name,pr_manuf,price,dial_size);
        a.putdata();

        break;
        }

        case 2:
        {

        float width,height;


         cout<<"Enter product id :";
        cin>>pr_id;
        cout<<"Enter product name :";
        cin>>pr_name;
        cout<<"Enter product manufacturer :";
        cin>>pr_manuf;
        cout<<"Enter product price :";
        cin>>price;
        cout<<"Enter product width :";
        cin>>width;
        cout<<"Enter product height :";
        cin>>height;

        bedsheet b (pr_id,pr_name,pr_manuf,price,width,height);
        b.putdata();
        break;
        }
    }

}