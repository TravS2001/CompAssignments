//Travis Stephney 20172675
//Dan Battaglia    20172740
//date written 2019/20/07

#include <stdbool.h>
#include <stdio.h>


#define sizeText 1024 // largest amount of characters the string can have
#define letterNum 26  // number of letters in the alphabet

int main(int argc, char **argv)
{

    char text[sizeText]; //make charector array the size of max string length
    int frequency[letterNum] = {0}; //array for frequency of each letter **must initialize as 0
    int most = 0, mostPos = 0, howMany = 0; //ints for printing most frequent
    
   
     FILE* inFile; //creates a file data type called inFile
        inFile= fopen //opens the file
        ("../data.txt","r"); // calling the file data.txt
    if (inFile== NULL){ 
        printf("Could not open file\n");
        return 0;
    }
 
    while(fgets(text, sizeText, inFile) != NULL) {  // scaning the data
      printf("The text in the data file is:\n %s \n", text);
      
    }
    
    for (int i = 0; i < 50; i++) { //loop to see if the data will equal an empty value to end code
        
        if (text[i] == '\0') {
            break;
        }
        
       for (int j = 97; j < letterNum+97; j++) {  //counter for letter and its index value
           
           if((int)text[i] == j) {
               //printf("processing %c\n, index is %d", text[i], j-97);
               frequency[j-97]++;
           }
       }
             
    }
    printf("The frequency of each letter in the text file is:\n");
    for (int k =0; k < letterNum; k++) {  // each letters frequency counter
        
        printf("%c: %d\n", k+97, frequency[k]); 
    }
    
    for(int r = 0; r < letterNum; r++) { //counter for the letter and letters frequency
        
        if(frequency[r] > most) {
            
            most = frequency[r];
            mostPos = r;
            
        }
    }
     for(int i=1; i<letterNum; i++){ //counter for amount of letters with max frequency
        if(most==frequency[i]){
        howMany= howMany+1; 
   
            }
        }
        
    printf("The most common letter is %c that occurs %d times\n", mostPos+97, most); //what letter get the most frequency
    printf("The are %d letters with this frequency\n", howMany);   //stating how many letters get max frequency
 
    fclose(inFile); //closes file

	return 0;
}
