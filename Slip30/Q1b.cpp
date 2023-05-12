#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_SUBJECTS = 5;

class Marksheet {
    private:
        int Seat_No;
        string Student_Name;
        string Class;
        string Subject_Name[NUM_SUBJECTS];
        int Int_Marks[NUM_SUBJECTS];
        int Ext_Marks[NUM_SUBJECTS];
        int Total[NUM_SUBJECTS];
        int Grand_Total;
        float Percentage;
        char Grade;

    public:
        void acceptStudentInfo() {
            cout << "Enter Seat No: ";
            cin >> Seat_No;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, Student_Name);
            cout << "Enter Class: ";
            getline(cin, Class);
            for (int i = 0; i < NUM_SUBJECTS; i++) {
                cout << "Enter marks for " << Subject_Name[i] << endl;
                cout << "Internal marks: ";
                cin >> Int_Marks[i];
                cout << "External marks: ";
                cin >> Ext_Marks[i];
                Total[i] = Int_Marks[i] + Ext_Marks[i];
            }
        }

        void calculate() {
            Grand_Total = 0;
            for (int i = 0; i < NUM_SUBJECTS; i++) {
                Grand_Total += Total[i];
            }
            Percentage = (float)Grand_Total / (NUM_SUBJECTS * 100) * 100;
            if (Percentage >= 90) {
                Grade = 'A';
            } else if (Percentage >= 80) {
                Grade = 'B';
            } else if (Percentage >= 70) {
                Grade = 'C';
            } else if (Percentage >= 60) {
                Grade = 'D';
            } else if (Percentage >= 50) {
                Grade = 'E';
            } else {
                Grade = 'F';
            }
        }

        void display() {
            cout << setprecision(2) << fixed << showpoint << setfill(' ');
            cout << "Seat No: " << setw(10) << Seat_No << endl;
            cout << "Name: " << setw(15) << Student_Name << endl;
            cout << "Class: " << setw(14) << Class << endl;
            cout << endl;
            cout << setw(25) << "Internal" << setw(10) << "External" << setw(10) << "Total" << endl;
            for (int i = 0; i < NUM_SUBJECTS; i++) {
                cout << setw(25) << Subject_Name[i] << setw(10) << Int_Marks[i] << setw(10) << Ext_Marks[i] << setw(10) << Total[i] << endl;
            }
            cout << setw(45) << "Grand Total: " << setw(10) << Grand_Total << endl;
            cout << setw(45) << "Percentage: " << setw(10) << Percentage << "%" << endl;
            cout << setw(45) << "Grade: " << setw(10) << Grade << endl;
        }
};

int main() {
    Marksheet m;
    m.acceptStudentInfo();
    m.calculate();
    m.display();
    return 0;
}

