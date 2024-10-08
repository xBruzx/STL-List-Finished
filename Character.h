#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std; 
/*Simple header file defining what a character is with some varriables. With some getters and setters*/
class Character {
    private:
    string name;
    string characterClass;
    string race;
    
    public:
    //Getters
    string getName() {return name;}
    string getClass() {return characterClass;}
    string getRace() {return race;}

    //Setters
    void setName(string name) {this->name = name;}
    void setClass(string characterClass) {this->characterClass = characterClass;}
    void setRace(string race) {this->race = race;}

};



#endif