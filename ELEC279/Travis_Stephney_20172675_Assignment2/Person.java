//Author -Travis Stephney  Student Number-20172675	Date-2021-03-12
public abstract class Person{	//person class combines the name of a person and their corresponding birthday
	private String name;
	private Date birthday;
	private double difficulty;

	
	Person(String name, Date birthday, double difficulty){		//constructor for person
		this.name=name;
		this.difficulty=difficulty;
		this.birthday= new Date(birthday);	//uses date input to make Date, then sets to birthday
	}
	public int getAwardedPointNumber() {		//creating method for awarding a point with any difficulty level
		int point=(int)((this.getDiff())*100);	//cast the double value of the point to an int
		return point;
	}
	
	public String getName() {				//creating accessor for name
		return this.name;
	}//end getName
	public Date getDate() {					//creating accessor for birthday
		return new Date(birthday);
	}//end getDate
	public double getDiff() {				//creating accessor for difficulty
		return this.difficulty;
	}
	public void setName(String name) {		//mutator for name
		this.name=name;		
	}
	public void setBirthday(Date birthday) {	//mutator for birthday
		this.birthday=new Date(birthday);
	}
	
	Person(Person myPerson){				//copy constructor for person
		this.name=myPerson.name;
		this.birthday=myPerson.birthday;
		this.difficulty=myPerson.difficulty;
	}
	
	public String toString() {		//use toString method to return wanted values to a string
		return (this.name + ", was born "+this.birthday.getDay()+" "+this.birthday.getMonth()+", "+this.birthday.getYear());
	}
	
	public abstract String personType();		//abstract method for personType
	
	public abstract Person clone();				//abstract method for clone
	
	public String startMessage() {		//returns games starting message for a determined person
		return "Guess the birthday of the "+this.personType()+" "+name+".";
	}
	public String closingMessage() {	//returns a closing message, with the desired toString following
		return "Congratulations! You were correct, "+this.toString();
	}
}
