//Author -Travis Stephney  Student Number-20172675	Date-2021-04-09

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;		

//a separate class for the GuessMaster code, has private variables, numPoints,numPeople and array Person[]
public class GuessMaster3 {		
	private HashSet<GuessablePerson<? extends Person>> people;	// instance variable for the hashset of people being guessed
	private int numPoints;										//counts the number of points the user has earned

	public GuessMaster3() {	//sets up new guessmaster game, initializes the points, people and array to 0
		numPoints=0;					//initializes the points for the user to zero
		people =new HashSet<>(0);		//creating new hashset to put the people to guess into
	}//end GuessMaster3
	
	public <M extends Person>void addPerson(M person, double difficulty) throws CloneNotSupportedException {			//addPerson adds a new person to guess to the array of people
		GuessablePerson<Person> GP=new GuessablePerson<>(person.clone(), difficulty);
		this.people.add(GP);
	}//end addPerson
	
	public HashSet<GuessablePerson<? extends Person>> getPeople(){		//accessor method forgetting the person in the hashset
		return people;
	}//end getPeople
	
	public void startGame() throws FileNotFoundException, CloneNotSupportedException {									// startGame starts the game setup
		System.out.println("Welcome! Lets start the game!");						
		while(true) {
			Iterator<GuessablePerson<? extends Person>> peopleIterator= people.iterator();	//creating the iterator
			while(peopleIterator.hasNext()) {												//run while the iterator has another variable 
				GuessablePerson<? extends Person> nextPerson=peopleIterator.next();		
				System.out.println(nextPerson.startMessage());
				check(nextPerson);
			}//end while
		}//end while(true)
	}//end startGame
	
public void check(GuessablePerson<? extends Person> person) throws CloneNotSupportedException, FileNotFoundException {
	Boolean run= true;						//run == true set so game runs
	File test= new File("C:\\Users\\travi\\eclipse-workspace\\GuessMaster\\src\\test.txt");	//take in the input file from computer
	
	try {													//try-catch to check if a file exists
		if(test.exists()==false) throw new FileNotFoundException();	
	}catch (FileNotFoundException e){	
			System.out.println("This file does not exist");
		}//exit catch
		
	Scanner intake = new Scanner(new FileInputStream(test));	//take in the file declared in the test variable decalred above
	
	while(run==true) {
		String guessString=intake.nextLine();		//take new input from user and set to guessString
		if(guessString.equals("quit")) {			//if quit is called, program ends
			System.out.println("Game exited.");
			run=false;								//sets run to false to make game stop running
			System.exit(0);							//ensure file is terminated
		}else {
			Date date= new Date(guessString);		//make the guessString into a usable Date
			System.out.println("If you would like to stop type\"quit\" to exit");
			
			
			if(date.compareTo(person.getBirthday())==0) {		//if date is equal, move to next person
				System.out.println("CORRECT. You got it!!\n");
				int points = person.getAwardedPointNumber();	//get the points for guessing a corresponding person
				numPoints=numPoints+points;						//used to have total points and points earned in each round
				System.out.println("You won "+points+" points in this round. Your total number of points is "+numPoints);
				System.out.println(person.closingMessage());	//print corresponding persons closing message
				break;
			}else if(date.compareTo(person.getBirthday())==-1){
				System.out.println("INCORRECT. Try an later date.\n");
			}else if(date.compareTo(person.getBirthday())==1){
				System.out.println("INCORRECT. Try an later date.\n");
				}
			}//end main else 
		}//end while
	}//end check
}//end GuessMaster Class

