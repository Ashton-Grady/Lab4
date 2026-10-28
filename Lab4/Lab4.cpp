/*********************************************
Ashton Grady

start/end date (10/15/2026 - 10/27/2026)

Goal - Design and write a C++ program that takes inputs from a series of hourly temperature
from a file, and outputs a bar chart (using stars) of the temperatures. The temperature
should be printed to the left of the corresponding bar, and there should be a heading
that gives the scale of the chart. The range of temperatures should be from -30 to 120.
Because it is hard to display 150 characters on the screen, you should have each star
represent a range of 3 degrees. That way, the bars will be at most 50 characters wide.
Use meaningful variable names, proper indentation, and appropriate comments.
**********************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

/**************************************************
pre condition: the file Temp.txt is able to be opened and read, file contains numbers and code will run.


post condition: the program will output the hour, temperature, and star count in a bar chart format and exit with code 0.
or find an error and exit with code 1 or 2. 
**************************************************/

int main() 
{
	//opens the temp.txt file
	std::ifstream infile;
	infile.open("Temp.txt");

	//checks to see if the file can be opened if not returnes error message and exits
	if (!infile)
	{
		std::cout << "error cant fine file" << std::endl;
		return 1;
	}

	//definitions 
int input;
int L1 = 0;
int hour = 0;


//bar chart heading output with temperature in Fehrenheit becuase USA.
std::cout << "temperature hourly bar chart" << std::endl;
std::cout << "-------+--------------+-------------------------------" << std::endl;
std::cout << "hour   |temperature F |star count * = 3 degrees" << std::endl;
std::cout << "-------+--------------+-------------------------------" << std::endl;

//loop to read file input till EOF and output and line up hour, temperature, and star count
while (infile >> input) {

	//adds one hour per loop
	hour++;

	//checks to see if imputs are in perameter range if not returns error code
	if (input < -30 || input > 120) {
		std::cout << "One or more temperatures are out of the -30 to 120 range.\nPlease check temperature inputs and try again.\n\n" << std::endl;
		return 2;
	}

	//if not error then runs outputs till EOF
	else {

	int starV = input / 3;

		//outputs the hour and temperature in a lined up format
		std::cout << std::left << std::setw(7) << hour << "| ";
		std::cout << std::setw(13) << input << "|";
		
		
		//outputs star count for the temperature 
		int star = 0;
		while (star <= starV){
			star++;
			std::cout << "*";
		}
	}
	//ends the line for the next input
std::cout << "" << std::endl;

	//adds 1 for loop count
	L1++;
}

//bottom of chart to make things look neat
std::cout << "-------+--------------+-------------------------------" << std::endl;
	infile.close();

	//number of total tempetures prossessed and outputed
	std::cout << L1 << " temperatures processed." << std::endl;

	return 0;
}