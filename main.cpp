// TODO: INCLUDE LIBRARIES
#include "Character.h"


void printMenu(); 

// TODO: CREATE FUNCTION PROTOTYPES
void loadCharacters(string fileName, list<Character>* characterList);
void addCharacter(list<Character>* characterList);

int main() { 
    // TODO: create our list object, specifying it handles Character objects.
    list<Character>* characterList = new list<Character>();

    // TODO: create two iterators
    list<Character>::iterator it1, it2; //Creating my two itterators. it1 is to start the list and it2 is to end the list.


    // input integer for our switch statement
    int choice = 0; 

    // TODO: load characters from file
    loadCharacters("threecharacters.txt", characterList);

    // TODO: set traversal iterator to the beginning 
    // set end "flag" iterator to end and decrement. 
    it1 = characterList->begin();
    it2 = characterList->end(); it2--;

    // TODO: WHILE LOOP  & Switch Case
    // print current character 
    cout << "Current Character:" << "\nCHARACTER: " << it1->getName() << "\nCLASS: " << it1->getClass() << "\nRACE: " << it1->getRace() << "\n****************" << endl;
    // take input
   while (choice != 5) {
    printMenu();

    cin >> choice;
    cin.ignore(); //input buffer to prevent buffer issues with other functions.

    // switch case for input 
    switch(choice) {

        // case 1 : next character 
        // case 2 : prev character 
        // case 3 : add character 
        // case 4 : delete character
        // case 5 : exit program 

        case 1:
        //If statement to set the list back to the begining if it hits the end.
            if (it1 == it2) {
                cout << "Current Character:" << "\nCHARACTER: " << it1->getName() << "\nCLASS: " << it1->getClass() << "\nRACE: " << it1->getRace() << "\n****************" << endl;
                it1 = characterList->begin();
            }
            //else keep incrementing.
            else {
                cout << "Current Character:" << "\nCHARACTER: " << it1->getName() << "\nCLASS: " << it1->getClass() << "\nRACE: " << it1->getRace() << "\n****************" << endl; 
                it1++;
            }
            break;
        case 2:
        //If statments to navagate the list backwards.
        if (it1 != characterList->begin()) {
            it1--;
            cout << "Current Character:" << "\nCHARACTER: " << it1->getName() << "\nCLASS: " << it1->getClass() << "\nRACE: " << it1->getRace() << "\n****************" << endl;
        }
        //If the list is at the begining set it1 to it2.
        if (it1 == characterList->begin()) {
            it1 = it2;
            cout << "Current Character:" << "\nCHARACTER: " << it1->getName() << "\nCLASS: " << it1->getClass() << "\nRACE: " << it1->getRace() << "\n****************" << endl;
        }
            break;
        case 3:
            //Call the addCharacter function to add a character to the list.
            addCharacter(characterList);
            it2++; //moves it2 to the end of the list after a new character is added to the end.
            break;
        case 4:
            if (it1 == it2) {
            it2--; //Moves the second itterator to the end of the list if we remove it from the end.
            }
            cout << "Character: " << it1->getName() << " has been removed from the list." << endl;
            characterList->erase(it1); //Call erase method for the list.
            it1 = characterList->begin(); //Moves it1 to the front of the list to prevent it from going outside of the list if the last character is removed.
            break;
        case 5:
            cout << "Goodbye!" << endl; //Say goodbye at the end of the program.
            break;
        default:
            cout << "Invalid option please try again." << endl;
    }
   }

    delete characterList;

    return 0;
}

void printMenu() { 
    cout << "1. Next Character" << endl;
    cout << "2. Previous Character" << endl;
    cout << "3. Add Character" << endl; 
    cout << "4. Delete Current Character" << endl; 
    cout << "5. Exit Program" << endl; 
}

// TODO: MAKE YOUR FUNCTIONS GOOBER - NOT GOOBER! >:(

void loadCharacters(string fileName, list<Character>* characterList) {
    //If statement to check and make sure that the file exists.
    ifstream file(fileName);
    if(!file.is_open()) {
        cout << "Error! File not found. Try another file name." << endl; //Shows error message if the file is not found or was renamed for whatever reason.
    }
    else {
        cout << fileName << " is open!" << endl; //file opened successfully.
    }
    string playerName, playerClass, playerRace;
    //While loop to read each line of the file and store name, class, and race respectivly and not include the # character as a delimiter.
    while (getline(file, playerName, '#')) {
        Character playerFromFile;
        getline(file, playerClass, '#');
        getline(file, playerRace, '#');

        playerFromFile.setName(playerName);
        playerFromFile.setClass(playerClass);
        playerFromFile.setRace(playerRace);

        characterList->push_back(playerFromFile);
    }
    file.close(); //Never forget to close the file after you are done!
}

void addCharacter(list<Character>* characterList) {
    string playerName, playerClass, playerRace; //Variables for a new player character.

    cout << "Character name: " << endl; //add a new character from player input.
    getline(cin, playerName);
    cout << "Character Class: " << endl; //player enters their class.
    getline(cin, playerClass);
    cout << "Character Race: " << endl; //player picks their race.
    getline(cin, playerRace);

    Character newCharacter; //New character object to use setters.

    newCharacter.setName(playerName);
    newCharacter.setClass(playerClass);
    newCharacter.setRace(playerRace);

    characterList->push_back(newCharacter); //Adds new character to the end of the list.
}