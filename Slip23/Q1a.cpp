#include<conio.h>
 #include<iostream>
  #include<string.h>

  using namespace std;
class Mystring
{
    char *str;
    int len;

    public:
    Mystring()
    {}

    Mystring(char s[])
    {
        len=strlen(s);
        str=new char[len+1]; 
        strcpy(str,s);
    }

    void display()
    {
        cout<<endl<<str;
    }



    Mystring operator+(Mystring ob)
    {
        Mystring a; 
        
        int len1,len2;
        len1=strlen(str); 
        len2=strlen(ob.str); 
        a.str=new char[len1+len2+1]; 
        strcpy(a.str,str);
        strcat(a.str,ob.str); 
        return a;
    }

};

int main()
{
char s1[10],s2[20];

cout<<"\n Enter 1st string : "; cin>>s1;
cout<<"\n Enter 2nd string : "; cin>>s2;

Mystring m1(s1),m2(s2),m3; 
m1.display();
m2.display(); 

m3=m1+m2;
m3.display();

return 0;
}
