
public class Politician extends Person{		//extends person and includes the party variable
	
	private String party;	
	
	
	public Politician(String name, Date birthday, double difficulty,String party) {	//constructor for politician
		super(name, birthday, difficulty);
		this.party=party;
	}//end Politician
	
	public Politician(Politician myPolitician) {	//copy constructor for politician
		super(myPolitician);
		this.party=party;
	}//end Politician copy constructor
	
	public Politician clone() {		//clone for politician
		return new Politician(this);
	}//end clone
	
	public String toString() {		//Corresponding toString method for politician
		String message= super.toString()+ ". They are a member of the "+this.party+" party.";	//set message
		return message;	//return message
	}//end toString
	
	public String personType() {		//personType responds politician if called by a politician
		return "politician";
	}//end personType
}//end Politician Class
