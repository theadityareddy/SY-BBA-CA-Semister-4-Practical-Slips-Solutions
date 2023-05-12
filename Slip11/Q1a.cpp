#include <iostream>
using namespace std;

class MyArray {
private:
    int* arr;  // pointer to the dynamic array
    int size;  // size of the array

public:
    MyArray(int s) {  // dynamic constructor
        size = s;
        arr = new int[size];
    }

    ~MyArray() {  // destructor
        delete[] arr;
    }

    void input() {  // member function to input elements of the array
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i+1 << ": ";
            cin >> arr[i];
        }
    }

    void display_sum() {  // member function to display sum of array elements
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        cout << "Sum of array elements is: " << sum << endl;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    MyArray arr(n);  // create object of MyArray class with dynamic constructor

    arr.input();  // input elements of array
    arr.display_sum();  // display sum of array elements

    return 0;
}

