#include<iostream>
#include<conio.h>

using namespace std;

class College
{
	private:
	int id, year;
	char name[20],uname[20];
	public:
	College()
	{
	}
	friend ostream & operator << (ostream &out, const College &c);
	friend istream & operator >> (istream &in, College &c);
};

ostream & operator << (ostream &out, const College &c)
{
	out<<c.id<<"\t"<<c.name<<"\t"<<c.year<<"\t"<<c.uname<<endl;
	return out;
}

istream & operator >> (istream &in, College &c)
{
	cout << "Enter College ID : ";
	in >> c.id;
	cout << "\nEnter College Name : ";
	in >> c.name;
	cout<<"\nEnter Year of Establishment : ";
	in>>c.year;
	cout<<"\nEnter University Name : ";
	in>>c.uname;
	return in;
}

int main()
{
	
	College c1;
	cin>>c1;
	cout<<"\nThe College details are : "<<endl;
	cout<<c1;
	
}

