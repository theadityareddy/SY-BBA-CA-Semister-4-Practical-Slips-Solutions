#include <iostream>

using namespace std;

class MyArray {
    private:
        int *arr;
        int size;
    public:
        MyArray(int n) {
            size = n;
            arr = new int[size];
        }
        void accept() {
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
        }
        void display() {
            cout << "Array elements: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        MyArray operator-() {
            MyArray temp(size);
            for (int i = 0; i < size; i++) {
                temp.arr[i] = arr[size - i - 1];
            }
            return temp;
        }
        MyArray operator+(int n) {
            MyArray temp(size);
            for (int i = 0; i < size; i++) {
                temp.arr[i] = arr[i] + n;
            }
            return temp;
        }
};

int main() {
    int size, n;
    cout << "Enter the size of the array: ";
    cin >> size;
    MyArray A(size), A2(size);
    A.accept();
    A.display();
    A2 = -A;
    cout << "Array elements after reversal: ";
    A2.display();
    cout << "Enter a constant to add to array elements: ";
    cin >> n;
    A2 = A + n;
    cout << "Array elements after adding " << n << " to all elements: ";
    A2.display();
    return 0;
}

