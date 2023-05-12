#include <iostream>
using namespace std;
inline int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
inline int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int main() {
  
  cout<<"enter the value of A and B :";
	int a,b;
	cin>>a>>b;
	cout<<"maximum is :"<<max(a,b)<<endl;
	cout<<"minimum is :"<<min(a,b);
	
}
