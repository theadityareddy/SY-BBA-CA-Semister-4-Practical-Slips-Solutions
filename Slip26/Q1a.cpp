#include<iostream>
#include<conio.h>

using namespace std;

 int avg(int num1, int num2,int num3)
  {
    int ans;
    ans=(num1+num2+num3)/3;
    return ans;
  }

  float avg(float num1, float num2, float num3)
  {
    float ans;
    ans=(num1+num2+num3)/3;
    return ans;
  }

int main()
{
 
  float fnum1, fnum2, fnum3,favg;
  int inum1, inum2, inum3,iavg;

  cout<<"Enter three Numbers (float) :: "<<endl;
  cin>>fnum1>>fnum2>>fnum3;

  cout<<"Enter three Numbers (integer) :: "<<endl;
  cin>>inum1>>inum2>>inum3;

  favg=avg(fnum1,fnum2,fnum3);
  iavg=avg(inum1,inum2,inum3);

  cout << "Average(float) = " << favg << endl;
  cout << "Average(int) = " << iavg << endl;

}
