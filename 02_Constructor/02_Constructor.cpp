#include <iostream>
#include <Windows.h>
using namespace std;

struct Coord
{
    int x;
    int y;
};

class Rect
{
    int width;
    int height;
    string symbol;
public:
    Rect()
    {
        width = 00;
        height = 00;
        symbol = "N/A";
    }
    Rect(int size, string symbol)
    {
        if (size >= 0)
        {
            width = size;
            height = size;
            this->symbol = symbol;
        }
        else
        {
            cout << "Wrong size!" << endl;
        }
    }
    Rect(int width, int height, string symbol)
    {
        if (width and height >= 0)
        {
            this->width = width;
            this->height = height;
            this->symbol = symbol;
        }
        else
        {
            cout << "Wrong size!" << endl;
        }
    }
    void Print()
    {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << symbol;
            }
            cout << endl;
        }
    }
    void ChangeSize(int width, int height)
    {
        if (width and height >= 0)
        {
            this->width = width;
            this->height = height;
        }
        else
        {
            cout << "Wrong size!" << endl;
        }
    }
    void MoveRectangle(int x, int y)
    {
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
};

int main()
{
    Rect rectangle1(5, "#");
    // Print
    rectangle1.Print();
    cout << endl;
    // ChangeSize
    rectangle1.ChangeSize(4, 6);
    rectangle1.Print();
    cout << endl;
    // MoveRectangle
    int x;
    int y;
    cout << "Enter coordinate X: "; cin >> x;
    cout << "Enter coordinate Y: "; cin >> y;
    system("cls");
    rectangle1.MoveRectangle(x, y);
    rectangle1.Print();
}