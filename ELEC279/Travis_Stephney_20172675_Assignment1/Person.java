/*
Author Travis Stephney
Student Number 20172675
*/
public class Person{	//person class combines the name of a person and their corresponding birthday
	private String name;
	private Date birthday;

	
	Person(String name, Date birthday){		//constructor for person
		this.name=name;
		this.birthday= new Date(birthday);	//uses date input to make Date, then sets to birthday
	}
	
	
	public String getName() {				//creating accessor for name
		return this.name;
	}//end getName
	public Date getDate() {					//creating accessor for birthday
		return new Date(birthday);
	}//end getDate
	public void setName(String name) {		//mutator for name
		this.name=name;		
	}
	public void setBirthday(Date birthday) {	//mutator for birthday
		this.birthday=new Date(birthday);
	}
	
	Person(Person myPerson){				//copy constructor for person
		this.name=myPerson.name;
		this.birthday=myPerson.birthday;
	}
	
	public String toString(Person myPerson) {	//method to set person to a string
		String name=myPerson.getName();			//Taking all needed variables and setting them 
		Date birthday=myPerson.getDate();		// to string/int variables.
		
		Integer day= birthday.getDay();
		Integer month= birthday.getMonth();
		Integer year= birthday.getYear();
		
		String dayString=day.toString();
		String monthString=month.toString();
		String yearString=year.toString();
		//returning desired string from previously described variables
		String output =name+" born on "+dayString+"/"+monthString+"/"+yearString;
		return output;
	}
}
