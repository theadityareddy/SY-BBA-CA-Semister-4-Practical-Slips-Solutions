#include <iostream>
#include <string>
#include<math.h>
using namespace std;

class FixDeposit {
public:
    int FD_No;
    string Cust_Name;
    double FD_Amt;
    double Interest_Rate;
    double Maturity_Amt;
    int Number_of_Months;

    // Parameterized constructor with default value for interest rate
    FixDeposit(int fdNo, string custName, double fdAmt, double interestRate = 6.5, int numMonths = 12)
        : FD_No(fdNo), Cust_Name(custName), FD_Amt(fdAmt), Interest_Rate(interestRate), Number_of_Months(numMonths)
    {
        calculateMaturityAmt();
    }

    // Method to calculate the maturity amount
    void calculateMaturityAmt()
    {
        double r = Interest_Rate / 100;
        double n = Number_of_Months / 12.0;
        Maturity_Amt = FD_Amt * pow(1 + r / 4, 4 * n);
    }

    // Method to display all the details
    void displayDetails()
    {
        cout << "FD No: " << FD_No << endl;
        cout << "Customer Name: " << Cust_Name << endl;
        cout << "FD Amount: " << FD_Amt << endl;
        cout << "Interest Rate: " << Interest_Rate << "%" << endl;
        cout << "Number of Months: " << Number_of_Months << endl;
        cout << "Maturity Amount: " << Maturity_Amt << endl;
    }
};

int main()
{
    // Create and initialize a FixDeposit object using parameterized constructor
    FixDeposit fd1(123, "John Doe", 50000, 7.5, 24);

    // Display the details of the FixDeposit object
    fd1.displayDetails();

    return 0;
}

