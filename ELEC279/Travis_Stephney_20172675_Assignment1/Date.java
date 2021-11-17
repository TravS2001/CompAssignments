/*
Author Travis Stephney
Student Number 20172675
*/
public class Date { //Public class sets up date variables, accessor methods and constructors 
	
	private int day;
	private int month;
	private int year;
	
	public Date(int day, int month, int year) {					//constructor for date
			this.day=day;										//setting day
			this.month=month;									//setting month
			this.year=year;										//setting year
	}

	Date(Date myDate){											//copy constructor for date
		this.day=myDate.day;
		this.month=myDate.month;
		this.year=myDate.year;
	}
	
	
	Date(String myString){	//constructor for date to take in a string and give it the values of a Date 
		String day= myString.substring(0,2);		//taking the day from the string
		String month= myString.substring(3,5);		//taking the month from the string
		String year= myString.substring(6);			//taking the year from the string
		
		int dayInt= Integer.parseInt(day);			//setting day from string type to int
		int monthInt= Integer.parseInt(month);		//setting month from string type to int
		int yearInt= Integer.parseInt(year);		//setting year from string type to int
		
		this.day=dayInt;
		this.month=monthInt;
		this.year=yearInt;
	}
	
	
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
}
