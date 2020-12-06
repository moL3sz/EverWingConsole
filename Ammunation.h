#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED



#endif // PROJECTILE_H_INCLUDED
#include "libs/json.hpp"
#include <fstream>
using json = nlohmann::json;
using namespace std;
class Ammo{
    public:
        json parsedConfig;

    void getProjectiles(){
        string pathToConfig ="Config\\projectile.cfg";
        ifstream file(pathToConfig);
        file >> parsedConfig;
    }
    json getParsedJSON(){
        return parsedConfig;
    }







};
