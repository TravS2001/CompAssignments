//Author -Travis Stephney  Student Number-20172675	Date-2021-04-09
public class Politician extends Person{		//extends person and includes the party variable
	private String party;	
	public Politician(String name, Date birthday, String party) throws CloneNotSupportedException {	//constructor for politician
		super(name, birthday);
		this.party=party;
	}//end Politician
	public Politician clone() throws CloneNotSupportedException{	//better clone method for Politician, throws CloneNotSupportedException
		try {
			Politician newPolitician= (Politician)super.clone();	// calls clone for the super, and casts to a Politician type object
			return newPolitician;
			}catch(CloneNotSupportedException e) {
				return null;
			}
	}//end Politician clone
	public String toString() {		//Corresponding toString method for politician
		String message= super.toString()+ ". They are a member of the "+this.party+" party.";	//set message
		return message;	//return message
	}//end toString
	public String personType() {		//personType responds politician if called by a politician
		return "politician";
	}//end personType
}//end Politician Class