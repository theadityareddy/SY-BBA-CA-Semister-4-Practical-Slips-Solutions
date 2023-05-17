#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Movie
{
private:
    string M_Name;
    int Release_Year;
    string director_Name;
    double Budget;

public:
    Movie() {}
    void setData(string name, int year, string director, double budget)
    {
        M_Name = name;
        Release_Year = year;
        director_Name = director;
        Budget = budget;
    }
    void showData()
    {
        cout << "Movie Name: " << M_Name << endl;
        cout << "Release Year: " << Release_Year << endl;
        cout << "Director Name: " << director_Name << endl;
        cout << "Budget: " << Budget << endl;
    }
};

int main()
{
    ofstream fout("Movie.txt", ios::out | ios::app);
    ifstream fin("Movie.txt", ios::in);
    Movie movie;
    int choice, count = 0;
    string name, director;
    int year;
    double budget;

    do
    {
        cout << "1. Add Movie Details" << endl;
        cout << "2. Display Movie Details" << endl;
        cout << "3. Count the number of objects stored" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Movie Name: ";
            cin >> name;
            cout << "Enter Release Year: ";
            cin >> year;
            cout << "Enter Director Name: ";
            cin >> director;
            cout << "Enter Budget: ";
            cin >> budget;
            movie.setData(name, year, director, budget);
            fout << name << " " << year << " " << director << " " << budget << endl;
            count++;
            break;
        case 2:
            while (fin >> name >> year >> director >> budget)
            {
                movie.setData(name, year, director, budget);
                movie.showData();
                cout << endl;
            }
            break;
        case 3:
            cout << "Number of Objects stored: " << count << endl;
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    fin.close();
    fout.close();

    return 0;
}
