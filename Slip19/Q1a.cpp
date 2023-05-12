#include <iostream>
using namespace std;

class Distance {
private:
  int meter;
  int centimeter;

public:
  Distance(int m, int cm) {
    meter = m;
    centimeter = cm;
  }

  Distance Larger(Distance *d) {
    if (this->meter > d->meter) {
      return *this;
    } else if (this->meter < d->meter) {
      return *d;
    } else {
      if (this->centimeter > d->centimeter) {
        return *this;
      } else {
        return *d;
      }
    }
  }

  void display() {
    cout << "Distance = " << meter << " meters " << centimeter << " centimeters" << endl;
  }
};

int main() {
  Distance d1(5, 20);
  Distance d2(3, 50);
  Distance larger = d1.Larger(&d2);
  cout << "Larger distance: ";
  larger.display();
  return 0;
}

