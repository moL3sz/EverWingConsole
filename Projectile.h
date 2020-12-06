#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED



#endif // PROJECTILE_H_INCLUDED
#include <vector>
#include "libs/json.hpp"
#include "Draw.h"
using namespace std;
using json = nlohmann::json;
class Projectile{
    public:
        int x,y;
        vector<string> sprite;
        double damage;
        int speed;
        string name;
        string id;
        string pathForSprite;
        const int mapValue = 0xff;
        void Move(){
            if(y-1 > 0){y--;}
        }
        void Draw(){
                int sy = 0;
                for(string row : sprite){
                    replace(row.begin(),row.end(),'.',' ');
                    printAtXY(x,y+sy++,row);
                }
        }
        void createProjectile(json parsed){
            name = parsed[id]["name"];
            damage = parsed[id]["damage"];
            speed = parsed[id]["speed"];
            pathForSprite = parsed[id]["path"];
        }
        void LoadSprite(){
            ifstream spriteData (pathForSprite);
            if (spriteData.is_open()){
                string line;
                while (getline(spriteData,line)){
                    sprite.push_back(line);
                }
                spriteData.close();
            }
        }




};
