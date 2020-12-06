#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED
#endif // SPACESHIP
#include <vector>
#include <unordered_map>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <string>
#include "Draw.h"
#include "Projectile.h"
using namespace std;
class SpaceShip
{
public:
    int x,y;
    vector<vector<int>> decodedSsMatrix;
    vector<string> skin;
    Projectile *proj;
    void initializeSkin(string path){    //get the skin from the data
         //set the skin var to the merged lines of the data

        ifstream skinData (path);
        if (skinData.is_open())
        {
            string line;
            while (getline(skinData,line))
            {
                skin.push_back(line);
            }
            skinData.close();
        }
    }
    void decodeSsSkin(){
        unordered_map<char,int> encoderData;
        encoderData.reserve(32);
        encoderData['.'] = 0x0;
        encoderData['/'] = 0x1;
        encoderData['\\'] = 0x2;
        encoderData['('] = 0x3;
        encoderData[')'] = 0x4;
        encoderData['='] = 0x5;
        encoderData[':'] = 0x6;
        encoderData['U'] = 0x7;
        encoderData['-'] = 0x8;
        encoderData['_'] = 0x9;
        encoderData['O'] = 0xa;
        encoderData['o'] = 0xb;
        for(string row : skin){
            vector<int> decodedRow;
            for(char c: row){decodedRow.push_back(encoderData[c]);}
            decodedSsMatrix.push_back(decodedRow);
        }
    }
    void DebugSkin(){
        for(vector<int> r : decodedSsMatrix){
            for(int e : r){
                cout << e <<",";
            }
            cout<<endl;
        }
    }
    void SetPosition(int x, int y){
        int offset = decodedSsMatrix[0].size()/2;
        this->x = x-offset;
        this->y = y-offset;
    }
    void remapSkin(){
        vector<string> newSkin;
        for(string row : skin){
            replace(row.begin(),row.end(),'.',' ');
            newSkin.push_back(row);
        }
        skin = newSkin;
    }
    void DrawSprite(){
        for(int i = 0;i < skin.size();i++){
            printAtXY(this->x,this->y+i,skin[i]);
        }
    }
    void Move(int xmin, int xmax){
        if(x-1 > xmin){
            if( GetAsyncKeyState(VK_LEFT)){x--;}
        }
        if(x+skin[0].size()+1 < xmax){
            if( GetAsyncKeyState(VK_RIGHT)){x++;}
        }


    }
    void SetProjectile(Projectile p){
        proj = &p;
    }
};
