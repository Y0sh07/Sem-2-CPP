#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
class result;
class student
{
    char id[8];
    char name[20];
    int semester;

    public:

    void getdata_stu(){
    cout<<"Enter Student Name :";
    cin>>name;
    cout<<"Enter Student Id :";
    cin>>id;
    cout<<"Enter Semester :";
    cin>>semester;

    }

    void putdata_stu(){
    cout.width(15);
    cout<<left<<"Student ID"<<":"<<id<<endl;
    cout.width(15);
    cout<<left<<"Student Name"<<":"<<name<<endl;
    cout.width(15);
    cout<<left<<"Semester"<<":"<<semester<<endl<<endl;
    cout.width(28);
    cout<<left<<"Subjects"<<setw(10)<<"theory"<<"practical"<<endl;
    }
    void getdata_result(result &);
    void putdata_result(result &);
    int  convert_grade_point(int);
    string marks_convert(int);


};
     

class result
{
  char subjects[3][30];
  int subject_credits[3];
  int practical_credits[3];
  int th_marks[3];
  int pr_marks[3];
  string th_grade[3];
  string pr_grade[3];
  int th_grade_point[3];
  int pr_grade_point[3];
  float sum=0,sum1=0;
  float a=0,sgpa;


  friend  void student::getdata_result(result &);
  friend void student::putdata_result(result &);
  friend int student::convert_grade_point(int);
  friend string student::marks_convert(int);
  

 

};


void student:: getdata_result(result &b){

    for(int i=0;i<3;i++){
        cout<<"Enter "<<i+1<<" Subject Name :";
        cin>>b.subjects[i];
        
        cout<<"Enter "<<i+1<< " Subject's Theory Exam Mark :";
            cin>>b.th_marks[i];
            
            b.th_grade[i]=marks_convert(b.th_marks[i]);
            b.th_grade_point[i]=convert_grade_point(b.th_marks[i]);
        }
        
         for(int i=0;i<3;i++){
        cout<<"Enter "<<i+1<< " Subject's practical Exam Mark :";
        
        
            cin>>b.pr_marks[i];
            
            b.pr_grade[i]=marks_convert(b.pr_marks[i]);
            b.pr_grade_point[i]=convert_grade_point(b.pr_marks[i]);
        }          
  }
  
  void student:: putdata_result(result &x){
    

     for(int i=0;i<3;i++)
    {
        cout.width(30);
        cout<<left<<x.subjects[i];
        
        
            cout<<setw(11)<<x.th_grade[i];
            cout<<setw(11)<<x.pr_grade[i];

        
        cout<<endl;
    }
     
    cout<<endl;
    
        
            for(int j=0;j<2;j++)
            {
                x.sum=x.sum+x.subject_credits[j]*x.th_grade_point[j];
                x.sum1=x.sum1+x.subject_credits[j];
            }
        
        x.sgpa=(float)x.sum/x.sum1;
    
           cout<<"SGPA"<<right<<setw(4)<<":"<<setprecision(3)<<x.sgpa;

  }
   string student:: marks_convert(int mark)
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

     int student:: convert_grade_point(int mark)
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


 



int main()
{
    student s;
    result c;

   s.getdata_stu();
   s.getdata_result(c);
   s.putdata_stu();
   s.putdata_result(c);
    
    return 0;
}

