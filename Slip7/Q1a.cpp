#include <iostream>
#include <cstring>

using namespace std;

class String {
  char str[50];

public:
  String(char s[]) {
    strcpy(str, s);
  }

  int replace(char ch1, char ch2 = '*') {
    int count = 0;
    for(int i = 0; i < strlen(str); i++) {
      if(str[i] == ch1) {
        str[i] = ch2;
        count++;
      }
    }
    return count;
  }

  void display() {
    cout << "String: " << str << endl;
  }
};

int main() {
  char s[50];
  cout << "Enter a string: ";
  cin.getline(s, 50);

  String str(s);
  str.display();

  char ch1, ch2;
  cout << "Enter the character to replace: ";
  cin >> ch1;
  cout << "Enter the replacing character (* for default): ";
  cin >> ch2;

  int count = str.replace(ch1, ch2);
  str.display();
  cout << "Number of replacements made: " << count << endl;

  return 0;
}
