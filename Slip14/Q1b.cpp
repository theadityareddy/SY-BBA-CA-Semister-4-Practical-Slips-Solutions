#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* str;
    int str_length;

public:
    MyString() {
        str = NULL;
        str_length = 0;
    }

    MyString(const char* s) {
        str_length = strlen(s);
        str = new char[str_length + 1];
        strcpy(str, s);
    }

    MyString(const MyString& other) {
        str_length = other.str_length;
        str = new char[str_length + 1];
        strcpy(str, other.str);
    }

    ~MyString() {
        delete[] str;
    }

    MyString operator!() {
        MyString result(*this);
        for (int i = 0; i < str_length; i++) {
            if (islower(result.str[i])) {
                result.str[i] = toupper(result.str[i]);
            } else if (isupper(result.str[i])) {
                result.str[i] = tolower(result.str[i]);
            }
        }
        return result;
    }

    bool operator<(const MyString& other) {
        return str_length < other.str_length;
    }

    MyString operator+(int n) {
        MyString result(*this);
        for (int i = 0; i < str_length; i++) {
            result.str[i] += n;
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const MyString& s) {
        os << s.str;
        return os;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2("World");
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "!s1 = " << !s1 << endl;
    cout << "s1 < s2 = " << (s1 < s2) << endl;
    cout << "s1 + 1 = " << s1 + 1 << endl;
    return 0;
}

