//Travis Stephney 20172675
//Dan Battaglia    20172740
//date written 2019/10/10

 #include <stdio.h> //packages
 #include <string.h>
 #include <ctype.h>
 
 #define USERCHARS 200 //max string length
 #define ROTORLEN 26 //length of rotor
 
int rotorZero[ROTORLEN]={ 6, 12, 11, 18, 25, 7, 0, 5, 17, 14, 22, 2, 1, 19, 9, 21, 23, 8, 3, 13, 24, 15, 10, 16, 20, 4 }; //first rotor 
int rotorOne[ROTORLEN]={ 7, 8, 15, 14, 17, 23, 24, 0, 1, 21, 16, 12, 11, 19, 3, 2, 10, 4, 20, 13, 18, 9, 25, 5, 6, 22 }; //second rotor 
int rotorTwo[ROTORLEN]={ 5, 8, 24, 12, 17, 0, 11, 20, 1, 23, 15, 6, 3, 22, 19, 10, 18, 4, 16, 14, 7, 25, 13, 9, 2, 21 }; //third rotor 
int reflector[ROTORLEN]={ 3, 16, 12, 0, 18, 11, 24, 22, 25, 17, 15, 5, 2, 23, 20, 10, 1, 9, 4, 21, 14, 19, 7, 13, 6, 8 }; //reflector

int backwards(int value, int rotor[]); //declaring function
 
 int main (int argv, char **argc){
     
     int letter, letterNum, rotor0Out, rotor1Out, rotor2Out, reflectorOut, reverse; //all required integers
     char userInput [USERCHARS]; //the string that the user inputs
     
     printf ("WELCOME TO THE ENIGMA\n\n"); //welcome statement
     
     printf ("\nEnter Transmision:\n\n"); //user prompt
     
     fgets(userInput, USERCHARS, stdin); //gets user input
     
     while (strcmp(userInput, "done\n")!=0){ //checks if done
            
            for (int i=0;i<strlen(userInput); i++){ //moves through each letter in line
                letter=userInput[i]; //asign string element to integer 
                
                if (isupper(letter)){ //checks if element is a capital letter 
                    letterNum=letter-'A'; //switches letter to ordinal number 
                   
                    rotor0Out=rotorZero[letterNum]; //runs each rotor 
                    rotor1Out=rotorOne[rotor0Out];
                    rotor2Out=rotorTwo[rotor1Out];
                    reflectorOut=reflector[rotor2Out]; //reflector - one sided rotor 
                    rotor2Out=backwards(reflectorOut, rotorTwo); // run 'backwards' function to allow for encryption and decryption 
                    rotor1Out=backwards(rotor2Out, rotorOne);
                    rotor0Out=backwards(rotor1Out, rotorZero);
                    
                    printf("%c", rotor0Out+'A'); //switchs final number back to a letter and prints it 
                }
            }
            printf("\n");
            
            fgets(userInput, USERCHARS, stdin); //prompts user for next line
     }
     
     return 0;
 }
 
 int backwards(int value, int rotor[]){ //function that runs rotors backwards to decrypt
     for (int k=0;k<ROTORLEN;k++) //searches for index of letter 
         if (rotor[k]==value){
             return k;
         }
 }