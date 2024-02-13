#include<iostream>
using namespace std;

    

    void area(int r)
    {
        cout<<"The area of circle :"<<3.14*r<<endl;
    }

    void area(int h,int w)
    {
        cout<<"The area of rectangle :"<<h*w;
    }

    void area(int h,int w,int d)
    {
        cout<<"The area of cuboid :"<<h*w*d;
    }


int main()
{
    int radius;
    int r_hight;
    int r_width;
    int h_cuboid;
    int w_cuboid;
    int d_cuboid;
    
    cout<<"Enter The radius of circle :";
    cin>>radius;
    area(radius);

    cout<<"Enter The hight of a rectangle :";
    cin>>r_hight;
    cout<<"Enter The width of a rectangle :";
    cin>>r_width;
    area(r_hight,r_width);

    cout<<"\nEnter The height of a cuboid :";
    cin>>h_cuboid;
    cout<<"Enter The width of a cuboid :";
    cin>>w_cuboid;
    cout<<"Enter The depth of a cuboid :";
    cin>>d_cuboid;
    area(h_cuboid,w_cuboid,d_cuboid);


    return 0;  
}