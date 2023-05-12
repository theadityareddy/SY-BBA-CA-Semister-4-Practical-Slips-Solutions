#include <iostream>
using namespace std;

class Number {
private:
  int num;
public:
  Number() { num = 0; }
  Number(int n) { num = n; }
  void display() { cout << num << endl; }

  Number operator++() { // pre-increment
    ++num;
    return Number(num);
  }

  Number operator++(int) { // post-increment
    num++;
    return Number(num - 1);
  }
};

int main() {
  Number n(5);
  cout << "Original value: ";
  n.display();

  Number pre_inc = ++n;
  cout << "After pre-increment: ";
  pre_inc.display();

  Number post_inc = n++;
  cout << "After post-increment: ";
  post_inc.display();

  cout << "Final value: ";
  n.display();

  return 0;
}

