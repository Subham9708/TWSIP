#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
bool gameending;
const int width = 10;
const int height = 10;
int A,a,b, B, foodA, foodB, points;
int tailA[50], tailB[50];
int nTail;
enum eDirecton { FINISH = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup()
{
    gameending = false;
    dir = FINISH;
    a = width / 2;
    b = height / 2;
    foodA = rand() % width;
    foodB = rand() % height;
    points = 0;
}   
void Tie()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
	for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == b && j == a)
                cout << "O";
            else if (i == foodB && j == foodA)
                cout << "*";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailA[k] == j && tailB[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                 
 
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
 
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "points:" << points << endl;
}
// tie is defined
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case KEY_UP:
            dir = UP;
            break;
        case KEY_DOWN:
            dir = DOWN;
            break;
        case KEY_RIGHT:
            dir = RIGHT;
            break;
        case KEY_LEFT:
            dir = LEFT;
            break;
        case 'a':
            gameending = true;
            break;
        }
    }
}
void Approach()
{
    int prevA = tailA[0];
    int prevB = tailB[0];
    int prev2A, prev2B;
    tailA[0] = a;
    tailB[0] = b;
    for (int i = 1; i < nTail; i++)
    {
        prev2A = tailA[i];
        prev2A = tailB[i];
        tailA[i] = prevA;
        tailB[i] = prevB;
        prevA = prev2A;
        prevB = prev2B;
    }
    switch (dir)
    {
    case LEFT:
        a--;
        break;
    case RIGHT:
        a++;
        break;
    case UP:
        b--;
        break;
    case DOWN:
        b++;
        break;
    default:
        break;
    }
    if (a >= width) a = 0; else if (a < 0) a = width - 1;
    if (b >= height) b = 0; else if (b < 0) b = height - 1;
 
    for (int i = 0; i < nTail; i++)
        if (tailA[i] == a && tailB[i] == b)
            gameending = true;
 
    if (a == foodA && b == foodB)
    {
        points += 50;
        foodA = rand() % width;
        foodB = rand() % height;
        nTail++;
    }
}
int main()
{
    Setup();
    while (!gameending)
    {
        Tie();
        Input();
        Approach();
       Sleep(50);
    }
    return 0;
}
