//18tms9@queensu.ca 20172675
#include "jumble.h"

JumblePuzzle::JumblePuzzle(string word, string difficulty) {
    //initialize values
    puzzle = nullptr;
    len = 0;
    dir = 0;
    row = 0;
    col = 0;
    //take the first character in the first pos of the string
    char diff = difficulty[0];

    int wlen = word.length();
    //check if word fits bounds
    if(wlen<3 || wlen>10){
        throw BadJumbleException("Input Invalid. Please use words with length greater then 2 and less then 10.");
    }

    if(difficulty!="easy"&&difficulty!="medium"&&difficulty!="hard"){
        throw BadJumbleException("Input Invalid. Please enter easy, medium, or hard.");
    }

    //set the difficulty based on the input. If easy check for e, for medium check for m and for hard check for h

    switch (diff) {
        case 'e': {
            len = wlen * 2;
            puzzle = new char* [len]; //create array of pointers to fill with other pointers

            for (int i = 0; i < len; i++) {
                puzzle[i] = new char[len]; //using heap
            }
            break;
        }//end case e

        case 'm': {
            len = wlen * 3;
            puzzle = new char* [len]; //create array of pointers to fill with other pointers

            for (int i = 0; i < len; i++) {
                puzzle[i] = new char[len];  //using heap
            }
            break;
        }//end case m

        case 'h': {
            len = wlen * 4;
            puzzle = new char* [len]; //create array of pointers to fill with other pointers

            for (int i = 0; i < len; i++) {
                puzzle[i] = new char[len];  //using heap
            }
            break;
        }//end case h
    }//end switch

    //fill array with random letters
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            puzzle[i][j] = 97 + rand() % 26; //generate random char from ASCII values
        }
    }

    //generate random row and column position from 0 to size-1
    srand(time(NULL)); //generate random seed
    row = rand() % len;
    col = rand() % len;

    //generate random direction [0, 1, 2, 3]
    srand(time(NULL));
    int i = 0;
    //loop through word until the end is reached and each character is placed into the game array. The way this program
    // runs is that it pre selects the col and row position. It then trys to fit the word into the array by checking the
    // the distance from the edges of the array. if it does not fit the direction, it then selects a different direction
    // from the same position. It then completes the same check until it finds a valid direction to place the word.
    while (word[i] != '\0') {
        //select a random direction to check to see if the word fits
        dir = posDir[rand() % 4];
        switch (dir) {
            case 'w': //left
                if ((col - wlen) < 0) {
                    break;
                }else if (word[i] != '\0') {
                    for (int j = col; j > 0; j--) {
                        if (word[i] != '\0') {
                            puzzle[row][j] = word[i];
                            i++;
                        }
                    }
                }else {
                    break;
                }//end of case w

            case 'e': //Right
                if ((col + wlen) > len) {
                    break;
                }else if (word[i] != '\0') {
                    for (int j = col; j < len; j++) {
                        if (word[i] != '\0') {
                            puzzle[row][j] = word[i];
                            i++;
                        }
                    }
                }else {
                    break;
                }//end of case e

            case 'n': //up
                for (int j = row; j > 0;j--) {
                    if ((row - wlen) < 0) {
                        break;
                    } else if (word[i] != '\0') {
                        for (int j = row; j > 0; j--) {
                            if (word[i] != '\0') {
                                puzzle[j][col] = word[i];
                                i++;
                            }
                        }
                    }
                }
                break;//end of case n

            case 's': //down
                if ((row + wlen) > len) {
                    break;
                }else if (word[i] != '\0') {
                    for (int j = row; j < len; j++) {
                        if (word[i] != '\0') {
                            puzzle[j][col] = word[i];
                            i++;
                        }
                    }
                }else {
                    break;
                }//end of case s
        }//end switch
    }
}

JumblePuzzle::JumblePuzzle(JumblePuzzle& other) {   //copy constructor
    //set the new copy values
    row = other.getRowPos();
    col = other.getColPos();
    len = other.getSize();
    dir = other.getDirection();

    charArrayPtr* currPuzzle = other.getJumble(); //using heap, need to create array of pointers to fill with other pointers
    puzzle=new charArrayPtr[this->len];

    for(int i=0; i<len;i++){
        puzzle[i]=new char[len];
        for (int j=0;j<len;j++){
            puzzle[i][j]=currPuzzle[i][j];
        }
    }
}

JumblePuzzle::~JumblePuzzle() { //destructor
    for (int i = 0; i < len; i++) {
        delete[] puzzle[i];
    }
    delete[] puzzle;
}

//assignment overloading
JumblePuzzle& JumblePuzzle::operator=(JumblePuzzle& right) {

    if (this != &right) {		// Check to see if it is assigning to itself
        for (int i = 0; i < len; i++) {
            delete[] puzzle[i];
        }
        delete[] puzzle;
    }
    //use accessors to get values
    row = right.getRowPos();
    col = right.getColPos();
    len = right.getSize();
    dir = right.getDirection();

    charArrayPtr* newArr= new charArrayPtr [len]; //need to create array of pointers to fill with other pointers

    for (int i = 0; i < len; i++) {
        newArr[i] = new char[len];
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            newArr[i][j] = right.puzzle[i][j]; //copy contents of right
        }
    }
    return *this;   // Return ref to self
}

//accessor function for size of puzzle
int JumblePuzzle::getSize() {
    return len;
}

//accessor function for row position of puzzle solution
int JumblePuzzle::getRowPos() {
    return row;
}

//accessor function for column position of puzzle solution
int JumblePuzzle::getColPos() {
    return col;
}

//accessor function for the puzzle array
charArrayPtr*  JumblePuzzle::getJumble() {
    return this->puzzle;
}

//accessor function for the direction of puzzle solution
char JumblePuzzle::getDirection() {
    return this->dir;
}

//exception constructor class
BadJumbleException::BadJumbleException(const string& m) : message(m) {}
string& BadJumbleException::what() {
    return message;
}