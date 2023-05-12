#include<iostream>
#include<string>
using namespace std;

class Student{
protected:
    int Roll_No;
    string Name;
public:
    void Accept_Student_Info(){
        cout<<"Enter Roll_No: ";
        cin>>Roll_No;
        cout<<"Enter Name: ";
        cin>>Name;
    }
    void Display_Student_Info(){
        cout<<"\nRoll_No: "<<Roll_No<<"\nName: "<<Name<<endl;
    }
};

class Theory: virtual public Student{
protected:
    int M1, M2, M3, M4;
public:
    void Accept_Theory_Marks(){
        cout<<"Enter marks of Theory Subjects (M1, M2, M3, M4): ";
        cin>>M1>>M2>>M3>>M4;
    }
};

class Practical: virtual public Student{
protected:
    int P1, P2;
public:
    void Accept_Practical_Marks(){
        cout<<"Enter marks of Practical Subjects (P1, P2): ";
        cin>>P1>>P2;
    }
};

class Result: public Theory, public Practical{
    float Total_Marks, Percentage;
    char Grade;
public:
    void Calculate_Total_Marks(){
        Total_Marks = M1+M2+M3+M4+P1+P2;
    }
    void Calculate_Percentage(){
        Percentage = Total_Marks/6.0;
    }
    void Calculate_Grade(){
        if(Percentage>=90) Grade = 'A';
        else if(Percentage>=80) Grade = 'B';
        else if(Percentage>=70) Grade = 'C';
        else if(Percentage>=60) Grade = 'D';
        else if(Percentage>=50) Grade = 'E';
        else Grade = 'F';
    }
    void Display_Result(){
        cout<<"\nTotal Marks: "<<Total_Marks<<"\nPercentage: "<<Percentage<<"\nGrade: "<<Grade<<endl;
    }
};

int main(){
    Result R;
    int choice;
    char repeat;
    do{
        cout<<"\n1. Accept Student Information\n2. Display Student Information\n3. Calculate Total_marks, Percentage and Grade\n 4.Exit";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                R.Accept_Student_Info();
                R.Accept_Theory_Marks();
                R.Accept_Practical_Marks();
                break;
            case 2:
                R.Display_Student_Info();
                break;
            case 3:
                R.Calculate_Total_Marks();
                R.Calculate_Percentage();
                R.Calculate_Grade();
                R.Display_Result();
                break;
            case 4:
            	exit(0);
            default:
                cout<<"Invalid Choice\n";
        }
        cout<<"Do you want to continue (y/n): ";
        cin>>repeat;
    }while(repeat=='y' || repeat=='Y');
    return 0;
}

