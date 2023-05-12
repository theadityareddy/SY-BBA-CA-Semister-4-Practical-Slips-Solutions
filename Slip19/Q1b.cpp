#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string Name, Editor;
    float Price;
public:
    virtual void Accept() = 0;
    virtual void Display() = 0;
};

class NewsPaper : public Media {
private:
    int No_ofPages;
public:
    void Accept() {
        cout << "Enter NewsPaper Name: ";
        getline(cin, Name);
        cout << "Enter NewsPaper Editor: ";
        getline(cin, Editor);
        cout << "Enter NewsPaper Price: ";
        cin >> Price;
        cout << "Enter Number of Pages: ";
        cin >> No_ofPages;
        cin.ignore();
    }
    void Display() {
        cout << "NewsPaper Name: " << Name << endl;
        cout << "NewsPaper Editor: " << Editor << endl;
        cout << "NewsPaper Price: " << Price << endl;
        cout << "Number of Pages: " << No_ofPages << endl;
    }
};

class Magazine : public Media {
private:
    string Category;
public:
    void Accept() {
        cout << "Enter Magazine Name: ";
        getline(cin, Name);
        cout << "Enter Magazine Editor: ";
        getline(cin, Editor);
        cout << "Enter Magazine Price: ";
        cin >> Price;
        cin.ignore();
        cout << "Enter Category: ";
        getline(cin, Category);
    }
    void Display() {
        cout << "Magazine Name: " << Name << endl;
        cout << "Magazine Editor: " << Editor << endl;
        cout << "Magazine Price: " << Price << endl;
        cout << "Category: " << Category << endl;
    }
};

int main() {
    Media* mediaPtr;
    NewsPaper npaper;
    Magazine mag;

    mediaPtr = &npaper;
    mediaPtr->Accept();
    cout << "\nNewsPaper Details:\n";
    mediaPtr->Display();

    mediaPtr = &mag;
    mediaPtr->Accept();
    cout << "\nMagazine Details:\n";
    mediaPtr->Display();

    return 0;
}

