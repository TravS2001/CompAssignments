//Travis Stephney 20172675
//Dan Battaglia    20172740

#include <stdio.h>
#include <stdbool.h>



int main(int argc, char **argv)
{
	int min;        //Lowest bound
    min=1;
    int max;        //Max bound
    char answer;    //answer to the guess
    char y;        //user input if right
    char range;         // the input if the value was lower or higher
    char l;             //if the guess was lower
    int guesses;        //number of guesses
    guesses=1;
    
    
        printf("welcome to the Guessing Game!\n\nEnter the largest number you'd want to guess: ");  //Intro statement
        scanf("%i", &max);                                                                          //Looking for max bound
        printf("Your numbers will be between %i and %i\n",min,max);                                 //Stating bounds 
	
        printf("Think of a number between %i and %i (but don't tell me!!)\n",min,max);              //asking the user to think of a number   
        
        while (true)
        {
        int guess = ((max+min)/2);                                                                  //original guess
        printf("Is it %i, (y/n)", guess);                                                           //asking if the guess is correct
        scanf(" %c", &answer);                                                                      //scaning for yes or no
       
 
        if (answer=='y'){                                                                           //If else statement telling you if the answer was correct
            printf("Got your number!!\n");                                                        // if its correct
            printf("It took me %i guesses to get your number!\n",guesses);                          //determining the number of guesses
            printf("Thanks for playing the guessing game!\n");                                       // Closing statement
            break;
                    }
        else{
            printf("Was the answer lower or higher (l/h)?");                                        //asking if it is higher or lower
            scanf(" %c", &range);                                                                   //input to see if it is higher or lower
            
            if (range=='l'){                                                                        //if else statement to edit the range if lower
        
                
                max= (guess-1);
            }
            else {                                                                                  //if else statement to edit the range if higher
                
                
                min=(guess+1);
            
            };
            guesses=(guesses+1);                                                                      //guess counter
            printf("\nRats! I'll do better next time.\n");                                            //If its wrong
       }
    }
    

 
    return 0;
}
