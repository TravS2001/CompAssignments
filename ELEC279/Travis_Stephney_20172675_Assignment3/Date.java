//Author -Travis Stephney  Student Number-20172675	Date-2021-04-09
public class Date implements Comparable<Date>, Cloneable { //Public class sets up date variables, accessor methods and constructors 
	
	private int day;
	private int month;
	private int year;
	
	public Date(int day, int month, int year) {					//constructor for date
			this.day=day;										//setting day
			this.month=month;									//setting month
			this.year=year;										//setting year
	}
	
	public Date clone() throws CloneNotSupportedException{		// better clone method for Date type objects, throws CloneNotSupportedException
		try {
			Date newDate= (Date)super.clone();					// calls clone for the super, and casts to a Date type object
			return newDate;
			}catch(CloneNotSupportedException e) {
				return null;
			}
	}//end Date clone
	
	public int compareTo(Date myDate) {		//compareTo method for Date type objects, compares if the date is >,<,or ==
		int compare = 0;
		if (this.equals(myDate)) {
			compare=0;
		}else if((this.getYear())<(myDate.getYear())) {
			compare=1;
		}else if((this.getYear())>(myDate.getYear())) {
			compare=-1;
		}else if((this.getMonth())<(myDate.getMonth())) {
			compare=1;
		}else if((this.getMonth())>(myDate.getMonth())) {
			compare=-1;
		}else if((this.getDay())<(myDate.getDay())) {
			compare=1;
		}else if((this.getDay())>(myDate.getDay())) {
			compare=-1;
		}
		return compare;
	}//end compareTo
	
	
	public Date(String myString){	//constructor for date to take in a string and give it the values of a Date 
		try {										//Try-catch used to see if the input is of the correct length
			if(myString.length()!=10) 
				throw new IncorrectDateException(myString);
		String day= myString.substring(0,2);		//taking the day from the string
		String month= myString.substring(3,5);		//taking the month from the string
		String year= myString.substring(6);			//taking the year from the string
		
		int dayInt= Integer.parseInt(day);			//setting day from string type to int
		int monthInt= Integer.parseInt(month);		//setting month from string type to int
		int yearInt= Integer.parseInt(year);		//setting year from string type to int
		
		this.day=dayInt;
		this.month=monthInt;
		this.year=yearInt;
		
		if(dayInt<1||monthInt<1||yearInt<1||dayInt>(Months.getDays(monthInt)))throw new IncorrectDateException(myString);
		}catch (IncorrectDateException e){
			this.day=1;
			this.month=1;
			this.year=1;
		}//end catch
	}//end Date

	public int getDay(){					//creating accessor for day
		return this.day;
		}//end getDay
	public int getMonth(){					//creating accessor for month
		return this.month;
		}//end getMonth
	public int getYear(){					//creating accessor for year
		return this.year;
		}//end getYear

	public boolean equals(Date date) {	//determines if two dates equal one another
		if((this.day==date.day)&&(this.month==date.month)&&(this.year==date.year)) {
			return true;
		}else{
			return false;
		}
	}//end equals

	private static class Months{ 				//static nested class Months
		private static int getDays(int month) {	//static method getDays, that returns the proper month length
			switch(month) {
			case 2:
				return 28;
			case 4:
				return 30;
			case 6:
				return 30;
			case 9:
				return 30;
			case 11:
				return 30;
			default:
				return 31;
			}//end switch
		}//end getDays 
	}//end Months
}//end Date Class
