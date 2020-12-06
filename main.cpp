#include <iostream>
#include "Bird.h"
#include "Map.h"
#include <windows.h>
#include <cwchar>
#include <unistd.h>
#include "Ammunation.h"
#include "Draw.h"


#pragma comment(lib, "user32")
#define MAP_HEIGHT 60
#define MAP_WIDTH 120

void sleepForMs(int t){
    usleep(t/1000);
}
vector<int> getWindowsRes(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    vector<int> res = {rows,columns};
    return res;
}
using namespace std;
void GameLoop(SpaceShip *ss, Map *m){
    bool GameOver = false;
    vector<int> ConsoleResolution = getWindowsRes();
    //ss.DebugSkin();
    vector<int> Limits = m->getLimtis(ConsoleResolution);
    while(!GameOver){
        ss->Move(Limits[0],Limits[1]);
        ss->DrawSprite();

        usleep(10000);
        if(GetAsyncKeyState(27)){
            break;
        }
    }
}
void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void setConsoleFontSize(){
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 18;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}

void SetWindow(int Width, int Height){
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
int main(){
    vector<int> ConsoleResolution;
    SpaceShip ss;
    Map m;
    SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    //Initialize components
    m.initializeMapMatrix();
    ss.initializeSkin("Resources\\spaceship.dat");
    ss.decodeSsSkin();

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // Set the windows to a predefined size
    system("mode con:cols=320 lines=60");
    ss.SetPosition(159,55);
    //set The console font size a style (predefined)
    setConsoleFontSize();
    ConsoleResolution = getWindowsRes();
    //set the map resolution
    m.setMapRes(MAP_HEIGHT,MAP_WIDTH);
    //DEBUGS
    hidecursor();
    ss.remapSkin();
    m.DrawMap(ConsoleResolution);
    Ammo ammo;
    ammo.getProjectiles();


    vector<Projectile> projectileDatabase;
    int N = 2;
    for(int i = 0;i < N;i++){
        string id = to_string(i);
        Projectile p;
        p.id =id;
        p.createProjectile(ammo.getParsedJSON());
        projectileDatabase.push_back(p);
    }
    //GameLoop(&ss,&m);


    return 0;
}
