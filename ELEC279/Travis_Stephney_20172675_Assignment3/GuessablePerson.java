//Author -Travis Stephney  Student Number-20172675	Date-2021-04-09
public class GuessablePerson<P extends Person> implements Guessable, Cloneable, Comparable<Person>{	//creates generic class GuessablePerson

	private P person;			//type parameter person
	private double difficulty;	
	
	public GuessablePerson(P person, double difficulty) throws CloneNotSupportedException {	//GuessablePerson constructor
		this.person=(P) person.clone();
		this.difficulty=difficulty;
	}//end GuessablePerson
	
	public int compareTo(Person myPerson){		//compareTo method for Person type objects
		int check;
		try {		//try-catch to check if the birthdays are equal
			check = this.getBirthday().compareTo(myPerson.getDate());
		}catch(CloneNotSupportedException e) {
			return 10;
		}
		if(check ==1 || check == -1){		//if the dates are unequal return value 
			return check;
		}else {								//else compare the names to see which comes first alphabetically
			String person1 =this.getName();
			String person2 =myPerson.getName();
			return person1.compareTo(person2); 
		}//end if-else
	}//end compareTo
	public String startMessage() {		//starting message for the game
	return "Guess the birthday of the "+person.personType()+" "+person.getName();
	}//end startMessage
	public String closingMessage() {	//closing message for the game
	return "Congratulations!  You were correct, "+person.toString();
	}//end closingMessage
	public int getAwardedPointNumber() {	//calculates points from difficulty
	double points = this.difficulty*100;
	return (int) points;
	}//end getAwardedPointNumber
	public Date getBirthday() throws CloneNotSupportedException {	//accessor method for birthday for date objects
		return person.getDate();
	}//end getBirthday
	public String getName() {	//accessor method for name for date objects
		return person.getName();
	}//end getName
	public GuessablePerson clone() throws CloneNotSupportedException{	//better clone method for GuessablePerson, throws CloneNotSupportedException
		try {
			GuessablePerson newGuessablePerson= (GuessablePerson)super.clone();	// calls clone for the super, and casts to a GuessablePerson type object
			newGuessablePerson.person=person.clone();		//clones person variable
			return newGuessablePerson;
			}catch(CloneNotSupportedException e) {
				return null;
			}
	}//end GuessablePerson clone
}//end GuessablePerson class
