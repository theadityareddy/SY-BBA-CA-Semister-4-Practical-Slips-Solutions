#include <iostream>
#include <cstring>

using namespace std;

class Vector {
  private:
    int size;
    int* data;

  public:
    Vector() {
      size = 0;
      data = NULL;
    }

    Vector(int s) {
      size = s;
      data = new int[size];
    }

    Vector(const Vector& v) {
      size = v.size;
      data = new int[size];
      memcpy(data, v.data, size * sizeof(int));
    }

    ~Vector() {
      if (data != NULL) {
        delete[] data;
        data = NULL;
      }
    }

    void accept() {
      cout << "Enter the size of the vector: ";
      cin >> size;
      data = new int[size];

      cout << "Enter the elements of the vector: ";
      for (int i = 0; i < size; i++) {
        cin >> data[i];
      }
    }

    void display() {
      cout << "(";
      for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i != size - 1) {
          cout << ", ";
        }
      }
      cout << ")" << endl;
    }

    Vector operator+(const Vector& v) {
      Vector result(size + v.size);

      int i = 0;
      for (; i < size; i++) {
        result.data[i] = data[i];
      }

      for (int j = 0; j < v.size; j++, i++) {
        result.data[i] = v.data[j];
      }

      return result;
    }
};

int main() {
  Vector v1, v2, v3;

  cout << "Enter the first vector:\n";
  v1.accept();

  cout << "Enter the second vector:\n";
  v2.accept();

  cout << "First vector:\n";
  v1.display();

  cout << "Second vector:\n";
  v2.display();

  v3 = v1 + v2;
  cout << "Union of the two vectors:\n";
  v3.display();

  return 0;
}

