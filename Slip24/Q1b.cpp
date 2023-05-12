#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class InvoiceBill {
public:
  // Constructor
  InvoiceBill(int order_id, string o_date, string customer_name, int no_of_products) {
    Order_id = order_id;
    O_Date = o_date;
    Customer_Name = customer_name;
    No_of_Products = no_of_products;
    Prod_Name = new string[no_of_products];
    Quantity = new int[no_of_products];
    Prod_Price = new double[no_of_products];
  }

  // Destructor
  ~InvoiceBill() {
    delete[] Prod_Name;
    delete[] Quantity;
    delete[] Prod_Price;
  }

  // Member functions
  void readData() {
    cout << "Enter order details:" << endl;
    cout << "Order ID: ";
    cin >> Order_id;
    cout << "Order Date: ";
    cin >> O_Date;
    cin.ignore(); // Ignore the newline character
    cout << "Customer Name: ";
    getline(cin, Customer_Name);
    cout << "Number of products: ";
    cin >> No_of_Products;
    Prod_Name = new string[No_of_Products];
    Quantity = new int[No_of_Products];
    Prod_Price = new double[No_of_Products];
    for (int i = 0; i < No_of_Products; i++) {
      cout << "Product #" << i + 1 << " name: ";
      cin >> Prod_Name[i];
      cout << "Quantity: ";
      cin >> Quantity[i];
      cout << "Price per unit: ";
      cin >> Prod_Price[i];
    }
  }

  void displayBill() {
    cout << setprecision(2) << fixed;
    cout << "----------------------------------------" << endl;
    cout << "               INVOICE BILL              " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Order ID: " << Order_id << endl;
    cout << "Order Date: " << O_Date << endl;
    cout << "Customer Name: " << Customer_Name << endl;
    cout << "----------------------------------------" << endl;
    cout << setw(20) << left << "Product Name"
         << setw(10) << right << "Quantity"
         << setw(10) << right << "Price"
         << setw(10) << right << "Amount" << endl;
    cout << "----------------------------------------" << endl;
    double total_amount = 0.0;
    for (int i = 0; i < No_of_Products; i++) {
      double amount = Quantity[i] * Prod_Price[i];
      cout << setw(20) << left << Prod_Name[i]
           << setw(10) << right << Quantity[i]
           << setw(10) << right << Prod_Price[i]
           << setw(10) << right << amount << endl;
      total_amount += amount;
    }
    cout << "----------------------------------------" << endl;
    cout << setw(40) << right << "Total Amount: " << setw(10) << right << total_amount << endl;
    cout << "----------------------------------------" << endl;
  }

private:
  int Order_id;
  string O_Date;
  string Customer_Name;
  int No_of_Products;
  string* Prod_Name;
  int* Quantity;
  double* Prod_Price;
};

int main() {
  InvoiceBill bill(0, "", "", 0);
  bill.readData();
  bill.displayBill();
  return 0;
}

