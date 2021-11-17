
public class Singer extends Person{	//extends person and includes the debutAlbum and debutAlbumReleaseDate variable
	private String debutAlbum;		
	private Date debutAlbumReleaseDate;
	
	
	//constructor for Singer
	public Singer(String name, Date birthday, double difficulty, String debutAblum, Date debutAlbumReleaseDate) {
		super(name, birthday, difficulty);
		this.debutAlbum=debutAblum;
		this.debutAlbumReleaseDate=debutAlbumReleaseDate;
	}//end Singer
	
	public Singer(Singer mySinger) {		// copy constructor for Singer
		super(mySinger);
		this.debutAlbum=mySinger.debutAlbum;
		this.debutAlbumReleaseDate=mySinger.debutAlbumReleaseDate;
	}//end Singer copy constructor
	
	public Singer clone() {		//clone for Singer
		return new Singer(this);
	}//end Singer clone
	
	public String toString() {		//Corresponding toString method for Singer
		String message= super.toString()+". Their debut album was "+ this.debutAlbum +", and was released on "+this.debutAlbumReleaseDate.getDay()+"/"+this.debutAlbumReleaseDate.getMonth()+"/"+this.debutAlbumReleaseDate.getYear();
		return message;		//^set message and return set message
	}//end toString
	
	public String personType() {
		return "singer";
	}//end personType
}//end Singer Class
