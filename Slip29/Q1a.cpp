#include <iostream>
#include <string>
using namespace std;

class E_Bill {
  private:
    string Cust_Name;
    int Meter_ID;
    int No_of_Units;
    double Total_Charges;

  public:
    void acceptData() {
        cout << "Enter Customer Name: ";
        cin >> Cust_Name;
        cout << "Enter Meter ID: ";
        cin >> Meter_ID;
        cout << "Enter Number of Units: ";
        cin >> No_of_Units;
    }

    void calculateCharges() {
        if (No_of_Units <= 100) {
            Total_Charges = 1 * No_of_Units;
        } else if (No_of_Units <= 300) {
            Total_Charges = 100 + (No_of_Units - 100) * 2;
        } else {
            Total_Charges = 500 + (No_of_Units - 300) * 5;
        }

        if (Total_Charges < 150) {
            Total_Charges = 150;
        }

        if (Total_Charges > 250) {
            Total_Charges = Total_Charges + (Total_Charges * 0.15);
        }
    }

    void displayData() {
        cout << "Customer Name: " << Cust_Name << endl;
        cout << "Meter ID: " << Meter_ID << endl;
        cout << "Number of Units: " << No_of_Units << endl;
        cout << "Total Charges: " << Total_Charges << endl;
    }
};

int main() {
    E_Bill e;

    e.acceptData();
    e.calculateCharges();
    e.displayData();

    return 0;
}

