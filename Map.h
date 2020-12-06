#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#endif // MAP_H_INCLUDED
#include <vector>
#include "Draw.h"
using namespace std;
class Map {
    public:
        int width = 100,height = 20; //coloum, row number
        string mapOutLineCharacter = "#";
        vector<vector<int>> mapMatrix;
        void initializeMapMatrix(){
            for(int y = 0; y < height; y++){
                vector<int> row;
                for(int x = 0; x < width;x++){
                    row.push_back(0);
                }
                mapMatrix.push_back(row);
            }
        }
        void DebugMap(){

            for(vector<int> row : mapMatrix){
                for(int e : row){   cout<<e<<" ";   }
            }
        }
        void setMapRes(int h,int w){
            this->width = w;
            this->height = h;
        }
        void DrawMap(vector<int> res){
            int MAPWIDTH = res[1];
            int MAPHEIGHT = res[0];
            int HALF = MAPWIDTH/2;
            int offset = this->width/2;
            int START_X = HALF-offset;
            int END_X = HALF+offset;
            //draw border
            for(int y = 0; y < MAPHEIGHT; y++){
                printAtXY(START_X,y,mapOutLineCharacter);
                printAtXY(END_X,y,mapOutLineCharacter);
            }
        }
        vector<int> getLimtis(vector<int> res){
            int MAPWIDTH = res[1];
            int MAPHEIGHT = res[0];
            int HALF = MAPWIDTH/2;
            int offset = this->width/2;
            int START_X = HALF-offset;
            int END_X = HALF+offset;
            vector<int>ret = {START_X,END_X};
            return ret;
        }





};


