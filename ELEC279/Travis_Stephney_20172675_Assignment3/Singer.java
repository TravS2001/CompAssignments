//Author -Travis Stephney  Student Number-20172675	Date-2021-04-09
public class Singer extends Person{	//extends person and includes the debutAlbum and debutAlbumReleaseDate variable
	private String debutAlbum;		
	private Date debutAlbumReleaseDate;
	//constructor for Singer
	public Singer(String name, Date birthday, String debutAblum, Date debutAlbumReleaseDate) throws CloneNotSupportedException {
		super(name, birthday);
		this.debutAlbum=debutAblum;
		this.debutAlbumReleaseDate=debutAlbumReleaseDate.clone();
	}//end Singer
	public Singer clone() throws CloneNotSupportedException{				//better clone method for singer, throws CloneNotSupportedException
		try {
			Singer newSinger= (Singer)super.clone();						// calls clone for the super, and casts to a Singer type object
			newSinger.debutAlbumReleaseDate=debutAlbumReleaseDate.clone();	//clones debutAlbumReleaseDate
			return newSinger;
			}catch(CloneNotSupportedException e) {
				return null;
			}
	}//end Singer clone
	public String toString() {		//Corresponding toString method for Singer
		String message= super.toString()+". Their debut album was "+ this.debutAlbum +", and was released on "+this.debutAlbumReleaseDate.getDay()+"/"+this.debutAlbumReleaseDate.getMonth()+"/"+this.debutAlbumReleaseDate.getYear();
		return message;		//^set message and return set message
	}//end toString
	
	public String personType() {
		return "singer";
	}//end personType
}//end Singer Class
