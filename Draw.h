#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy( int x, int y ){
    COORD p;
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
}
void printAtXY(int x, int y, string s){
    gotoxy(x,y);
    cout << s;

}
#endif // DRAW_H_INCLUDED
