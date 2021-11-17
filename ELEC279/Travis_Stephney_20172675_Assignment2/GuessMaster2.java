//Author -Travis Stephney  Student Number-20172675	Date-2021-03-12
import java.util.Arrays;		//used for the Person array
import java.util.Random;		//used for random number generation
import java.util.Scanner;		//used for the input

//a separate class for the GuessMaster code, has private variables, numPoints,numPeople and array Person[]
public class GuessMaster2 {		
	private Person[] people;
	private int numPoints;
	private int numPeople;

	public GuessMaster2() {	//sets up new guessmaster game, initializes the points, people and array to 0
		numPoints=0;
		numPeople=0;
		people=new Person[0];
	}//end GuessMaster2
	
	public void addPerson(Person myPerson) {			//addPerson adds a new person to guess to the array of people
		people=Arrays.copyOf(people, people.length+1);	//increases length of array by 1
		people[people.length-1]=myPerson;				//set last position in array to new person
		numPeople++;									//increase number of people to guess
	}//end addPerson
	
	public void startGame() {									// startGame starts the game setup

		System.out.println("Welcome! Lets start the game!");		
		while(true) {
			Random random= new Random();						// set up new random 
			int randomNumber= random.nextInt(numPeople);		//get a new random number
			System.out.println(people[randomNumber].startMessage());	//Use random number to pick person in array to guess
			check(people[randomNumber]);						//check guess of random person
		}//end while
	}//end startGame
	
public void check(Person person) {
		Scanner intake= new Scanner(System.in);		//set up scanner and what it will be set too
		String guessString="";
		Boolean run= true;							//run == true set so game runs
	
	while(run==true) {
		guessString=intake.nextLine();				//take new input from user and set to guessString
		if(guessString.equals("quit")) {			//if quit is called, program ends
			System.out.println("Game exited.");
			run=false;								//sets run to false to make game stop running
			System.exit(0);							//ensure file is terminated
		}else {
			Date date= new Date(guessString);		//make the guessString into a usable Date
			if(date.equals(person.getDate())) {		//if date is equal, move to next person
				System.out.println("CORRECT. You got it!!\n");
				int points = person.getAwardedPointNumber();	//get the points for guessing a corresponding person
				numPoints=numPoints+points;						//used to have total points and points earned in each round
				System.out.println("You won "+points+" points in this round. Your total number of points is "+numPoints);
				System.out.println(person.closingMessage());	//print corresponding persons closing message
				break;
			}else if((date.getYear())<(person.getDate().getYear())){		//checks if input is less then expected day
					System.out.println("INCORRECT. Try an later year.\n");
			}else if((date.getYear())>(person.getDate().getYear())){		//checks if input is greater then expected day
				System.out.println("INCORRECT. Try an earlier year.\n");
			}else if((date.getMonth())<(person.getDate().getMonth())){		//checks if input is less then expected month
					System.out.println("INCORRECT. Try an later month.\n");
			}else if((date.getMonth())>(person.getDate().getMonth())){		//checks if input is greater then expected month
				System.out.println("INCORRECT. Try an earlier month.\n");
			}else if((date.getDay())<(person.getDate().getDay())){			//checks if input is less then expected year
					System.out.println("INCORRECT. Try an later day.\n");
			}else if((date.getDay())>(person.getDate().getDay())){			//checks if input is greater then expected year
					System.out.println("INCORRECT. Try an earlier day.\n");
			}
		}//end main else 
		}//end while
	}//end check
}//end GuessMaster Class
