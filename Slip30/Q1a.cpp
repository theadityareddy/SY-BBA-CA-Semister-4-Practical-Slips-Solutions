#include<iostream>
using namespace std;

class Float_Array; // forward declaration

class Integer_Array {
    int arr[100], size;
public:
    void getdata() {
        cout << "Enter the size of the array: ";
        cin >> size;
        cout << "Enter the array elements: ";
        for(int i=0; i<size; i++)
            cin >> arr[i];
    }
    void display() {
        cout << "The array elements are: ";
        for(int i=0; i<size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    friend void average(Integer_Array I, Float_Array F);
};

class Float_Array {
    float arr[100];
    int size;
public:
    void getdata() {
        cout << "Enter the size of the array: ";
        cin >> size;
        cout << "Enter the array elements: ";
        for(int i=0; i<size; i++)
            cin >> arr[i];
    }
    void display() {
        cout << "The array elements are: ";
        for(int i=0; i<size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    friend void average(Integer_Array I, Float_Array F);
};

void average(Integer_Array I, Float_Array F) {
    int sum1 = 0;
    for(int i=0; i<I.size; i++)
        sum1 += I.arr[i];
    float avg1 = float(sum1)/I.size;
    cout << "Average of integer array: " << avg1 << endl;

    float sum2 = 0;
    for(int i=0; i<F.size; i++)
        sum2 += F.arr[i];
    float avg2 = sum2/F.size;
    cout << "Average of float array: " << avg2 << endl;
}

int main() {
    Integer_Array I;
    Float_Array F;

    cout << "Enter elements of integer array:\n";
    I.getdata();
    cout << "Enter elements of float array:\n";
    F.getdata();

    cout << "Displaying elements of integer array:\n";
    I.display();
    cout << "Displaying elements of float array:\n";
    F.display();

    average(I, F);

    return 0;
}

