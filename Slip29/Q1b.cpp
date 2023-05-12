#include <iostream>
#include <string>
using namespace std;

class Visiting_Staff {
  private:
    string Name;
    int No_of_Subjects;
    string *Name_of_Subjects;
    int Workinghours;
    double TotalSalary;

  public:
    Visiting_Staff(string name, int num_of_subs, string subs[], int hours) {
        Name = name;
        No_of_Subjects = num_of_subs;
        Name_of_Subjects = new string[No_of_Subjects];
        for (int i = 0; i < No_of_Subjects; i++) {
            Name_of_Subjects[i] = subs[i];
        }
        Workinghours = hours;
        TotalSalary = 0;
    }

    void calculateSalary() {
        TotalSalary = Workinghours * 300;
    }

    void displayDetails() {
        cout << "Name: " << Name << endl;
        cout << "Number of Subjects: " << No_of_Subjects << endl;
        cout << "Subjects: ";
        for (int i = 0; i < No_of_Subjects; i++) {
            cout << Name_of_Subjects[i] << " ";
        }
        cout << endl;
        cout << "Working Hours: " << Workinghours << endl;
        cout << "Total Salary: " << TotalSalary << endl;
    }
};

int main() {
    string subs[] = {"Maths", "Physics", "Chemistry"};
    Visiting_Staff v("John Doe", 3, subs, 40);
    v.calculateSalary();
    v.displayDetails();
    return 0;
}

