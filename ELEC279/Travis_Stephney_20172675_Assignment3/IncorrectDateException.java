//Author -Travis Stephney  Student Number-20172675	Date-2021-04-09
public class IncorrectDateException extends Exception{		//creates  an incorrect date exception, to return a string saying the input was incorrect
	public IncorrectDateException(String dateString) {
		super("The date you have entered, "+ dateString+"is not a valid input");
	}
}
