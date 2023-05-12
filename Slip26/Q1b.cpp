#include <iostream>
using namespace std;

class Time {
  private:
    int hours;
    int minutes;
    int seconds;
  
  public:
    Time() {
      hours = 0;
      minutes = 0;
      seconds = 0;
    }

    friend bool operator!=(const Time &t1, const Time &t2);
    friend istream& operator>>(istream &in, Time &t);
    friend ostream& operator<<(ostream &out, const Time &t);
};

bool operator!=(const Time &t1, const Time &t2) {
  return (t1.hours != t2.hours) || (t1.minutes != t2.minutes) || (t1.seconds != t2.seconds);
}

istream& operator>>(istream &in, Time &t) {
  cout << "Enter time (hh:mm:ss): ";
  in >> t.hours >> t.minutes >> t.seconds;
  return in;
}

ostream& operator<<(ostream &out, const Time &t) {
  out << t.hours << ":" << t.minutes << ":" << t.seconds;
  return out;
}

int main() {
  Time t1, t2;
  
  cout << "Enter time 1:\n";
  cin >> t1;
  
  cout << "Enter time 2:\n";
  cin >> t2;

  if (t1 != t2) {
    cout << "The times are not equal.\n";
  } else {
    cout << "The times are equal.\n";
  }

  cout << "Time 1: " << t1 << endl;
  cout << "Time 2: " << t2 << endl;
  
  return 0;
}

