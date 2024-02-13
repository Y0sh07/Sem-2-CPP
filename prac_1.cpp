#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

void print_marksheet();
string marks_convert(int mark);
int convert_grade_point(int mark);
float convert_sgpa(int credits[3][2],int grade_point[3][2]);



int main()
{
    print_marksheet();
    return 0;
}

void print_marksheet()
{
    char id[8];
    char name[20];
    char subjects[3][30];
    int semester;
    int marks[3][2];
    string grade[3][2];
    int grade_point[3][2];
    float sgpa=0;
    int credits[3][2]={4,1,3,2,4,2};
    

   cout<<"Enter Student Name :";
    cin>>name;
    cout<<"Enter Student Id :";
    cin>>id;
    cout<<"Enter Semester :";
    cin>>semester;

    for(int i=0;i<3;i++){
        cout<<"Enter "<<i+1<< " subject name:";
        cin>>subjects[i];
        for(int j=0;j<2;j++){
            cin>>marks[i][j];
            
            grade[i][j]=marks_convert(marks[i][j]);
            grade_point[i][j]=convert_grade_point(marks[i][j]);
        }
        }
        cout<<endl;
        
        sgpa=convert_sgpa(credits,grade_point);
        system("CLS");
   
   cout.width(15);
    cout<<left<<"Student ID"<<":"<<id<<endl;
    cout.width(15);
    cout<<left<<"Student Name"<<":"<<name<<endl;
    cout.width(15);
    cout<<left<<"Semester"<<":"<<semester<<endl<<endl;
    cout.width(28);
    cout<<left<<"Subjects"<<setw(10)<<"theory"<<"practical"<<endl;
    
    for(int i=0;i<3;i++)
    {
        cout.width(30);
        cout<<left<<subjects[i];
        for(int j=0;j<2;j++)
        {
            cout<<setw(11)<<grade[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
       cout<<"SGPA"<<right<<setw(4)<<":"<<setprecision(3)<<sgpa;
}

     
  string marks_convert(int mark)
     {       
        if(mark>=80)
        return "AA";

        else if(mark>=73 && mark<80)
        return "AB";

        else if(mark>=66 && mark<73)
        return "BB";

        else if(mark>=60 && mark<66)
        return "BC";

        else if(mark>=55 && mark<60)
        return "CC";

        else if(mark>=50 && mark<55)
        return "CD";

        else if(mark>=45 && mark<50)
        return "CD";

        else if(mark<45)
        return "FF";
     }

     int convert_grade_point(int mark)
     {
       if(mark>=80)
        return 10;

        else if(mark>=73 && mark<80)
        return 9;

        else if(mark>=66 && mark<73)
        return 8;

        else if(mark>=60 && mark<66)
        return 7;

        else if(mark>=55 && mark<60)
        return 6;

        else if(mark>=50 && mark<55)
        return 5;

        else if(mark>=45 && mark<50)
        return 4;

        else if(mark<45)
        return 0;
     }

     float convert_sgpa(int credits[3][2],int grade_point[3][2])
     {
        int sum=0,sum1=0;
        float a=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                sum=sum+credits[i][j]*grade_point[i][j];
                sum1=sum1+credits[i][j];
            }
        }
        a=(float)sum/sum1;
        return a;
     }