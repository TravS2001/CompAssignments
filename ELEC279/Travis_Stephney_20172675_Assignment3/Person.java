//Author -Travis Stephney  Student Number-20172675	Date-2021-04-09
public abstract class Person implements Cloneable{	//person class combines the name of a person and their corresponding birthday
	private String name;
	private Date birthday;

	
	public Person(String name, Date birthday) throws CloneNotSupportedException{		//constructor for person
		this.name=name;
		this.birthday= birthday.clone();	//uses date input to make Date, then sets to birthday
	}//end Person
	
	public Person clone() throws CloneNotSupportedException{		//better clone method for Person type objects, throwsCloneNotSupportedException
		try {
			Person newPerson= (Person)super.clone();				// calls clone for the super, and casts to a person type object
			newPerson.birthday=birthday.clone();					//clones birthday variable
			return newPerson;
			}catch(CloneNotSupportedException e) {
				return null;
			}
	}//end Person clone
	public String getName() {	//creating accessor for name
		return this.name;
	}//end getName
	public Date getDate() throws CloneNotSupportedException {	//creating accessor for birthday
		return birthday.clone();
	}//end getDate
	public void setName(String name) {		//mutator for name
		this.name=name;		
	}//end setName
	public void setBirthday(Date birthday) throws CloneNotSupportedException {	//mutator for birthday
		this.birthday=birthday.clone();
	}//end setBirthday
	public String toString() {		//use toString method to return wanted values to a string
		return (this.name + ", was born "+this.birthday.getDay()+" "+this.birthday.getMonth()+", "+this.birthday.getYear());
	}//end toString
	public abstract String personType();		//abstract method for personType
}//end Person Class
