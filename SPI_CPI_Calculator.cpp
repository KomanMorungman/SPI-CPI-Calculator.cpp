#include<iostream>
using namespace std;
int total_credit_point(int credit[],int cr,string grade[],int result[]);
float spi_cal();
float cpi_cal();
int main(){
int choice;
float check,check1;
cout<<"Enter your choice:1)SPI Calculation 2)CPI Calculation 3)SPI & CPI Calculation\n";
cin>>choice;
switch (choice){
case 1:cout<<"-------SPI Calculation---------";
           check=spi_cal();
           if(check==-1)
                 cout<<"Typo in grade";
          else cout<<check;
           break;
case 2:cout<<"-------CPI Calculation---------";
           check=cpi_cal();
           if(check==-1)
                 cout<<"Typo in grade";
          else cout<<check;
           break;
case 3:cout<<"-------SPI & CPI Calculation---------";
            check=spi_cal();
           if(check==-1)
                 cout<<"Typo in grade";
          else cout<<check;
           check1=cpi_cal();
           if(check==-1)
                 cout<<"Typo in grade";
          else cout<<check1;

           break;
default:cout<<"Please try again wrong choice";

}
return 0;


}
int total_credit_point(int credit[], int cr,string grade[],int result[]){
int grade_point[cr],i,tot_credit=0,tot_point=0;
result[2]=0;
for(i=0;i<cr;i++){
    if ((grade[i]=="AA") || (grade[i]=="AS"))
         grade_point[i]=10;
    else if(grade[i]=="AB")
        grade_point[i]=9;
    else if(grade[i]=="BB")
        grade_point[i]=8;
    else if(grade[i]=="BC")
        grade_point[i]=7;
    else if(grade[i]=="CC")
        grade_point[i]=6;
    else if(grade[i]=="CD")
        grade_point[i]=5;
    else if(grade[i]=="DD")
        grade_point[i]=4;
    else if(grade[i]=="FP")
        grade_point[i]=0;
    else {
            result[2]=-1;
             return 0;
    }
}
for(i=0;i<cr;i++)
    tot_credit+=credit[i];
for(i=0;i<cr;i++)
    tot_point+=(credit[i]*grade_point[i]);
result[0]=tot_credit;
result[1]=tot_point;

}

float spi_cal(){
int cr;
cout<<"\nEnter the number of courses:";
cin>>cr;
int credit[cr],i,result[2];
string grade[cr];
cout<<"\nEnter the credits of your "<<cr<<" courses:";
for(i=0;i<cr;i++)
    cin>>credit[i];
cout<<"\nEnter the corresponding grades(capital letters) of your "<<cr<<" courses:";
for(i=0;i<cr;i++)
    cin>>grade[i];
total_credit_point( credit,cr,grade,result);
cout<<"SPI:";
if(result[2]!=-1){
        return(float(result[1])/result[0]);
}
else return result[2];
}
float cpi_cal(){

int cr;
cout<<"\nEnter the  number of courses completed till now(from first semester):";
cin>>cr;
int credit[cr],i,result[2];
string grade[cr];
cout<<"\nEnter the entire credits of your "<<cr<<" courses(from first semester):";
for(i=0;i<cr;i++)
    cin>>credit[i];
cout<<"\nEnter the corresponding grades(capital letters) of your "<<cr<<" courses(from first semester):";
for(i=0;i<cr;i++)
    cin>>grade[i];
total_credit_point( credit,cr,grade,result);
cout<<"CPI:";
if(result[2]!=-1){
        return(float(result[1])/result[0]);
}
else return result[2];
}

