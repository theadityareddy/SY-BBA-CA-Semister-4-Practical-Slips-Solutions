#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        int Roll_no;
        string S_Name;
        int Class;
        float Percentage;
    public:
        void getdata() {
            cout << "Enter roll no: ";
            cin >> Roll_no;
            cout << "Enter name: ";
            cin >> S_Name;
            cout << "Enter class: ";
            cin >> Class;
            cout << "Enter percentage: ";
            cin >> Percentage;
        }
        void display() {
            cout << "Roll no: " << Roll_no << endl;
            cout << "Name: " << S_Name << endl;
            cout << "Class: " << Class << endl;
            cout << "Percentage: " << Percentage << endl;
        }
        float getPercentage() {
            return Percentage;
        }
};

int main() {
    Student s1, s2;
    cout << "Enter details of student 1:" << endl;
    s1.getdata();
    cout << "Enter details of student 2:" << endl;
    s2.getdata();
    if (s1.getPercentage() > s2.getPercentage()) {
        cout << "Details of student 1 with maximum percentage:" << endl;
        s1.display();
    } else {
        cout << "Details of student 2 with maximum percentage:" << endl;
        s2.display();
    }
    return 0;
}

