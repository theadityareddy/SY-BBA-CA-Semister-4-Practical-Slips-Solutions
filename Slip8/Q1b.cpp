#include<iostream>
#include<string.h>
using namespace std;
class Person
{
	private:
		char pname[20],mno[11],city[10];
		int age;
	public:
		void accept()
		{
			cout<<"\nEnter person name: ";
			cin>>pname;
			cout<<"\nEnter mobile no: ";
			cin>>mno;
			cout<<mno;
			cout<<"\nEnter city: ";
			cin>>city;
			cout<<"\nEnter age: ";
			cin>>age;
		}
		
		void display()
		{
			cout<<"\nPerson Name: "<<pname;
			cout<<"\nMobile No: "<<mno;
			cout<<"\nCity: "<<city;
			cout<<"\nAge: "<<age;
		}
		
		static void getInfo(Person p[],int n)
		{
			char name[20];
			cout<<"\nEnter person name: ";
			cin>>name;
			
			for(int i=0;i<n;i++)
			{
				if(strcmp(p[i].pname,name)==0)
				{
					p[i].display();
				}
			}
		}
		
		static char* getInfo(Person p[],int n,char mno[11])
		{
			for(int i=0;i<n;i++)
			{
				if(strcmp(p[i].mno,mno)==0)
				{
					return p[i].pname;
				}
			}
		}
		
		static void getInfo(Person p[],int n,char city[10], int x)
		{
			for(int i=0;i<n;i++)
			{
				if(strcmp(p[i].city,city)==0)
				{
					p[i].display();
				}
			}
		}
};

int main()
{
	int n;
	char name[20],mno[11],city[20];
	
	cout<<"\nEnter total number of persons: ";
	cin>>n;
	Person p[10];
	
	for(int i=0;i<n;i++)
	{
		p[i].accept();
		p[i].display();
	}
	

	Person::getInfo(p,n);
	
	cout<<"\nEnter person mobile no to get name: ";
	cin>>mno;
	cout<<"\nPerson Name: "<<Person::getInfo(p,n,mno);
	
	cout<<"\nEnter city to get person details: ";
	cin>>city;
	Person::getInfo(p,n,city, 1);
	
	return 1;
}




