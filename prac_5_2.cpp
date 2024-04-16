#include<iostream>
using namespace std;
#define PI 3.14;
    int a=0;
class area_circle
{
    int radius;
   

    public:

    area_circle()
    {
        radius=1;
        a++;
    }

    area_circle(double d)
    {
        radius=d;
        a++;
    }

    area_circle(area_circle &b)
    {
        radius=b.radius;
    }

    void display()
    {
        float area;
        area=radius*radius*PI;
        cout<<"Circle with radius "<<radius<<" has area "<<area<<endl;
    }
    
    ~area_circle()
    {
        cout<<"One Object is deleted"<<endl;
        a--;
        cout<<"total active objects are "<<a<<endl;
    }
};

int main()
{
   area_circle *s1,*s2;
   area_circle *s3;
   s1=new area_circle();
   s2=new area_circle(20.00);
   
   s1->display();
   s2->display();
   s3=new area_circle(*s1);
   delete s1;
   delete s2;
   s3->display();
   delete s3;
    return 0;  
}