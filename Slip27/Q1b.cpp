#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define Travels class
class Travels {
protected:
    int T_no;
    string Company_Name;
public:
    // Define accept_details() function to accept values
    void accept_details() {
        cout << "Enter Travels Number: ";
        cin >> T_no;
        cout << "Enter Company Name: ";
        cin >> Company_Name;
    }
};

// Define Route class
class Route : public Travels {
protected:
    int Route_id;
    string Source, Destination;
public:
    // Define accept_details() function to accept values
    void accept_details() {
        Travels::accept_details();
        cout << "Enter Route ID: ";
        cin >> Route_id;
        cout << "Enter Source: ";
        cin >> Source;
        cout << "Enter Destination: ";
        cin >> Destination;
    }
};

// Define Reservation class
class Reservation : public Route {
private:
    int Number_of_Seats;
    string Travels_Class;
    float Fare;
    string Travel_Date;
public:
    // Define accept_details() function to accept values
    void accept_details() {
        Route::accept_details();
        cout << "Enter Number of Seats: ";
        cin >> Number_of_Seats;
        cout << "Enter Travels Class: ";
        cin >> Travels_Class;
        cout << "Enter Fare: ";
        cin >> Fare;
        cout << "Enter Travel Date (dd/mm/yyyy): ";
        cin >> Travel_Date;
    }

    // Define display_details() function to display values
    void display_details() {
        cout << "Reservation Details:\n";
        cout << "Travels Number: " << T_no << endl;
        cout << "Company Name: " << Company_Name << endl;
        cout << "Route ID: " << Route_id << endl;
        cout << "Source: " << Source << endl;
        cout << "Destination: " << Destination << endl;
        cout << "Number of Seats: " << Number_of_Seats << endl;
        cout << "Travels Class: " << Travels_Class << endl;
        cout << "Fare: " << Fare << endl;
        cout << "Travel Date: " << Travel_Date << endl;
    }

    // Define display_details_by_date() function to display values of a specified date
    void display_details_by_date(string date) {
        if (date == Travel_Date) {
            display_details();
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of reservations: ";
    cin >> n;

    vector<Reservation> reservations;

    // Accept details of n reservations
    for (int i = 0; i < n; i++) {
        Reservation r;
        r.accept_details();
        reservations.push_back(r);
    }

    // Display details of all reservations
    for (int i = 0; i < n; i++) {
        cout << "\nReservation " << i+1 << ":\n";
        reservations[i].display_details();
    }

    // Display reservation details of a specified date
    string date;
    cout << "\nEnter a date to display details for (dd/mm/yyyy): ";
    cin >> date;

    for (int i = 0; i < n; i++) {
        reservations[i].display_details_by_date(date);
    }

    return 0;
}

