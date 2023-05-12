#include <iostream>

using namespace std;
class Number{
    public:
        void display(){
            static int cnt=1;
            cout<<"\nDisplay function is called "<<cnt<<" times"<<endl;
            cnt++;
        }
};
int main()
{
    Number n1,n2;
    n1.display();
    n1.display();
    n2.display();
    n2.display();
    return 0;
}
