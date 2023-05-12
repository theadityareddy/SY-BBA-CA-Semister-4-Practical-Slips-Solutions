#include<iostream>
using namespace std;

class cuboid
{
private:
    float length;
    float breadth;
    float height;
    float volume;
    float surfacearea;
public:
    void setvalues(float, float, float);
    void getvalues(void);
    float vol(void);
    float sa(void);
};
inline void cuboid::setvalues(float l, float b, float h)
{
    length = l;
    breadth = b;
    height = h;
}
inline void cuboid::getvalues()
{
    cout<<endl<<"Length: "<<length;
    cout<<endl<<"Breadth: "<<breadth;
    cout<<endl<<"Height: "<<height;
}
inline float cuboid::vol()
{
    volume = length * breadth * height;
    return volume;
}
inline float cuboid::sa()
{
    surfacearea = 2*(length*breadth + breadth*height + length*height);
    return surfacearea;
}

int main()
{
    cuboid c1;
    float l, h, b;

    cout<<"Enter length, breadth and height of cuboid: ";
    cin>>l>>b>>h;

    c1.setvalues(l, b, h);
    c1.getvalues();
    cout<<endl<<c1.vol();
    cout<<endl<<c1.sa();

    return 0;
}

