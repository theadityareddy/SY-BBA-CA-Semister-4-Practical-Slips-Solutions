#include <iostream>
#include <fstream>
#include <cstring>

class MyFile
{
private:
    std::string filename;
    std::fstream file;

public:
    MyFile(std::string filename) : filename(filename) {}

    bool open()
    {
        file.open(filename.c_str(), std::ios::in | std::ios::out);
        return file.is_open();
    }

    void close()
    {
        file.close();
    }

    void display()
    {
        std::string line;
        while (getline(file, line))
        {
            std::cout << line << std::endl;
        }
    }

    bool operator+(MyFile &other)
    {
        std::ofstream outfile("concatenated.txt");
        if (!outfile)
        {
            return false;
        }

        outfile << file.rdbuf();
        other.file.seekg(0, std::ios::beg);
        outfile << other.file.rdbuf();

        outfile.close();
        return true;
    }

    bool operator!()
    {
        std::ofstream outfile("modified.txt");
        if (!outfile)
        {
            return false;
        }

        std::string line;
        bool upper = true;
        while (getline(file, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                if (isalpha(line[i]))
                {
                    if (upper)
                    {
                        line[i] = toupper(line[i]);
                    }
                    else
                    {
                        line[i] = tolower(line[i]);
                    }
                    upper = !upper;
                }
            }
            outfile << line << std::endl;
        }

        outfile.close();
        return true;
    }
};
int main()
{
    MyFile file1("file1.txt");
    MyFile file2("file2.txt");

    if (!file1.open())
    {
        std::cout << "Failed to open file1.txt" << std::endl;
        return 1;
    }

    if (!file2.open())
    {
        std::cout << "Failed to open file2.txt" << std::endl;
        return 1;
    }

    // Concatenate file1 and file2 into file3
    MyFile file3("file3.txt");
    if (!(file1 + file2))
    {
        std::cout << "Failed to concatenate files" << std::endl;
        return 1;
    }

    // Modify file3
    if (!(!file3))
    {
        std::cout << "Failed to modify file" << std::endl;
        return 1;
    }

    // Display the modified file
    file3.display();

    file1.close();
    file2.close();
    file3.close();
}
