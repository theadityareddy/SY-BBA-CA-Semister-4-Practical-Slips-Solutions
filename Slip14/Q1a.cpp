#include<iostream>
using namespace std;

#include<conio.h>

 inline float diameter(float r)

{

return(r /2);

}

inline float circlearea(float r)

{

return(3.14*r*r);

}

inline float circumference(float r)

{

return(3.14*2*r);

}

int main()

{

float radius;



 cout<<"\n\nEnter the radius of the circle:";

cin>>radius;

cout<<"\nDiameter of Circle:"<< diameter(radius);

cout<<"\nArea of Circle:"<< circlearea (radius);

cout<<"\nCircumference of Circle:"<< circumference(radius);

getch();

return 0;

 }
