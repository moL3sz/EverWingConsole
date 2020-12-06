#ifndef WEAPONS_H_INCLUDED
#define WEAPONS_H_INCLUDED



#endif // WEAPONS_H_INCLUDED
#include <libs/json.hpp>
#include <fstream>
using namespace std;
using json = nlohmann::json;
class Weapons{
    public:
        json weaponJSON;
        string path = "Config\\weapons.cfg";
        void getWeapons(){
            ifstream jsonFile(path);
            jsonFile >> weaponJSON;
        }




};
