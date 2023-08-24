#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student
{
    string name, id, department;
    Student()
    {
        name = "Unknown";
        id = "Unknown";
        department = "Unknown";
    }
    Student(const string &n, const string &i, const string &d) : name(n), id(i), department(d){};

    static void writeToFile(Student sta[])
    {
        ofstream outFile("students.bin", ios::binary);
        if (outFile.is_open())
        {
            for (int i = 0; i < 3; i++)
            {
                outFile.write(reinterpret_cast<const char *>(&sta[i]), sizeof(Student));
            }

            outFile.close();
        }
        else
        {
            cout << "error writing data to file" << endl;
            exit(1);
        }
        cout << "Data successfully added to file" << endl;
    }
    static void readFromFile(Student *sta)
    {
        ifstream inFile("students.bin", ios::binary | ios::in);
        inFile.seekg(0);
        int i = 0;
        while (!inFile.eof())
        {
            if (inFile.is_open())
            {
                inFile.read(reinterpret_cast<char *>(sta + i), sizeof(Student));
            }
            i++;
        }
        inFile.close();
    }
};
int main()
{
    Student stArr[3];
    stArr[0] = Student("Saroj", "078BCT079", "Computer");
    stArr[1] = Student("Samip", "078BCT075", "Computer");
    stArr[2] = Student("Shashank", "078BCT084", "Computer");
    Student retrievedStArr[3];
    // storing
    Student::writeToFile(stArr);
    // retrieving
    cout << "The names students are: " << endl
         << setw(20) << "Student" << setw(20) << "Roll" << setw(20) << "Department" << endl;
    Student::readFromFile(retrievedStArr);
    for (Student s : retrievedStArr)
    {
        cout << setw(20) << s.name << setw(20) << s.id << setw(20) << s.department << endl;
    }
    return 0;
}