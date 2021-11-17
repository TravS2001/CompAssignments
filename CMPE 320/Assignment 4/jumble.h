//18tms9@queensu.ca 20172675
#ifndef JUMBLEPUZZLE_JUMBLE_H
#define JUMBLEPUZZLE_JUMBLE_H

#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

typedef char* charArrayPtr;
using namespace std;

//define Jumble Puzzle Class
class JumblePuzzle {
private:
    int len;
    char dir;
    char posDir[4]={'n', 'e', 's', 'w'};
    int row;
    int col;
    charArrayPtr* puzzle;
public:
    JumblePuzzle(string word, string difficulty);  //simple constructor
    JumblePuzzle(JumblePuzzle& otherJumble);            //copy constructor
    ~JumblePuzzle();                                    //destructor
    charArrayPtr* getJumble();                          //game array accessor
    int getSize();                                      //get size of the difficulty
    int getRowPos();                                    //get the random position
    int getColPos();                                    //get the random column
    char getDirection();                                 //get the direction decided upon
    JumblePuzzle& operator=(JumblePuzzle& right);       //assignment operator overload
};

//make an error class
class BadJumbleException {
public:
    BadJumbleException(const string& message);
    string& what();

private:
    string message;
};

#endif //JUMBLEPUZZLE_JUMBLE_H
