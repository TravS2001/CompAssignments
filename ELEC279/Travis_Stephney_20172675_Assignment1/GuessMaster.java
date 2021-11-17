/*
Author Travis Stephney
Student Number 20172675
*/
import java.util.Scanner;

public class GuessMaster {	//Guess master includes the guess master constructor, the structure of the game
							//(startGame method)and the check function(check method).
	private int currentPerson;
	private Person person1;
	private Person person2;
	private Person person3;

	//GuessMaster constructor takes the 3 determined people to guess
	//and allows them to be accessed with a method.
	public GuessMaster(Person person1, Person person2, Person person3) {
		currentPerson=1;						//tally for what person the user is on
		
		this.person1=new Person(person1);		
		this.person2=new Person(person2);
		this.person3=new Person(person3);
	}
	
	//check determines if the date and persons birthday are equal, less or greater than, and returns the 
	//boolean run to ensure the program can continue to run
	public Boolean check(Date date, Person person, Boolean run) {
		
		if(date.equals(person.getDate())) {				//if date is equal, move to next person
			System.out.println("CORRECT. You got it!!\n");
			currentPerson++;
		}else if((date.getYear())<(person.getDate().getYear())){		//checks if input is less then expected day
				System.out.println("INCORRECT. Try an later date.\n");
		}else if((date.getYear())>(person.getDate().getYear())){		//checks if input is greater then expected day
			System.out.println("INCORRECT. Try an earlier date.\n");
		}else if((date.getMonth())<(person.getDate().getMonth())){		//checks if input is less then expected month
				System.out.println("INCORRECT. Try an later date.\n");
		}else if((date.getMonth())>(person.getDate().getMonth())){		//checks if input is greater then expected month
			System.out.println("INCORRECT. Try an earlier date.\n");
		}else if((date.getDay())<(person.getDate().getDay())){			//checks if input is less then expected year
				System.out.println("INCORRECT. Try an later date.\n");
		}else if((date.getDay())>(person.getDate().getDay())){			//checks if input is greater then expected year
				System.out.println("INCORRECT. Try an earlier date.\n");
		}
		return run;
	}
	
	//startGame method makes game from GuessMaster() and uses check method to compare guess to desired.
	public void startGame() {
		
		System.out.println("Welcome to GuessMaster!! Guess the birthdays of people below.\n");
		//set up scanner and what it will be set too
		Scanner intake= new Scanner(System.in);
		String guessString="";
		//run == true set so game runs
		Boolean run= true;
		
		while(run==true) {
			switch(currentPerson) {	//determines what person is to be guessed or if game is complete
									//prints corresponding persons name to guess
			case 1:
				System.out.println("You need to guess the birthday of " +person1.getName()+".\nEnter in format DD/MM/YYYY\n");
				break;
			case 2:
				System.out.println("You need to guess the birthday of " +person2.getName()+". \nEnter in format DD/MM/YYYY\n");
				break;
			case 3:
				System.out.println("You need to guess the birthday of " +person3.getName()+".\nEnter in format DD/MM/YYYY\n");
				break;
			case 4:
				System.out.println("You have completed the game!!");
				run=false;			//sets run to false to make game stop running
				System.exit(0);		//ensure file is terminated
				break;
			}
		
		guessString=intake.nextLine();		//take new input from user and set to guessString
		
		if(guessString.equals("quit")) {	//if quit is called, program ends
			System.out.println("Game exited.");
			run=false;						//sets run to false to make game stop running
			System.exit(0);					//ensure file is terminated
		}else {								//if the input is not quit, run it
			Date guess= new Date(guessString);	//make the guessString into a usable Date
											
				switch(currentPerson){		//for one of the three possible people, run a check
				case 1:
					run=check(guess, person1, run);		//setting run to checks output
					break;
				case 2:
					run=check(guess, person2, run);		//setting run to checks output
					break;
				case 3:
					run=check(guess, person3, run);		//setting run to checks output
					break;
				}
			}
		}
		intake.close();
		}
	}