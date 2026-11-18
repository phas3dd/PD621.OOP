#include <iostream>
#include <fstream>

using namespace std;

struct Date 
{
    int day;
    int month;
    int year;
};

class Student 
{
private:
    string fullName;
    Date birthDate;
    string phone;
    string city;
    string country;
    string university;
    string uniCity;
    string uniCountry;
    string group;

public:
    void input() 
    {
        cout << "Enter full name: "; cin >> fullName;
        cout << "Enter birthdate: "; cin >> birthDate.day >> birthDate.month >> birthDate.year;
        cout << "Enter phone number: "; cin >> phone;
        cout << "Enter city: "; cin >> city;
        cout << "Enter current country: "; cin >> country;
        cout << "Enter university: "; cin >> university;
        cout << "Enter university city: "; cin >> uniCity;
        cout << "Enter university country: "; cin >> uniCountry;
        cout << "Enter group number: "; cin >> group;
    }

    void print() 
    {
        cout << endl;
        cout << "Student information: " << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Birthdate: " << birthDate.day << "." << birthDate.month << "." << birthDate.year << endl;
        cout << "Phone number: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
        cout << "University: " << university << endl;
        cout << "University city: " << uniCity << endl;
        cout << "University country: " << uniCountry << endl;
        cout << "Group number: " << group << endl;
    }
};

class Point 
{
private:
    double x;
    double y;
    double z;

public:
    void input() 
    {
        cout << "Enter x: "; cin >> x;
        cout << "Enter y: "; cin >> y;
        cout << "Enter z: "; cin >> z;
    }

    void print() {
        cout << "x - " << x << endl;
        cout << "y - " << y << endl;
        cout << "z - " << z << endl;
    }

    void saveToFile(string filename) {
        ofstream fout(filename);
        fout << "x - " << x << endl;
        fout << "y - " << y << endl;
        fout << "z - " << z << endl;
        fout.close();
        cout << "Success!" << endl;
    }

    void loadFromFile(string filename) {
        ifstream fin(filename);
        fin >> x;
        fin >> y;
        fin >> z;
        fin.close();
        cout << "Success!" << endl;
    }
};

int main() {
    Student s;
    s.input();
    s.print();

    Point p;
    p.input();
    p.print();

    p.saveToFile("point.txt");

    Point loadedPoint;
    loadedPoint.loadFromFile("point.txt");
    loadedPoint.print();
}