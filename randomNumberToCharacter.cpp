// Creating random numbers using the system time and static casting them to ascii characters and printing them and
//if they are unprintable, print NA or if they are a letter, print the upper and lower case

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>

//Setting standard for in/out statements
using namespace std;

//File access
fstream fileWriter;





int main()
{
	int counter, nbr;

	fileWriter.open("U:\\C++\\randomNumberToCharacter\\randomNumberToCharacter\\randomNumberToCharacterOutput.txt", ios::out);

	//Test for the file validity
	if (!fileWriter) {
		cout << "File not found" << '\n';
		system("PAUSE");
		return 0;
	}
	unsigned seed;

	//Taking the system time at the current instance and putting it in seed
	seed = time(0);
	//Incrementing factor for loop
	counter = 0;
	srand(seed);


	//Basic column formatting to help readability
	cout << setw(10) << " Random Number\t| Character\t| Uppercase\t| Lowercase\n";
	cout << "-------------------------------------------------------------\n";

	fileWriter << setw(10) << " Random Number\t| Character\t| Uppercase\t| Lowercase\n";
	fileWriter << "-------------------------------------------------------------\n";


	//Loop for amount of random numbers
	while (counter < 100) {
		nbr = rand() % 123;

		//First column
		//Console prints of the random number
		cout <<  setw(10) << " " << nbr;
		fileWriter << setw(10) << " " << nbr;
		

		//Second column
		//Test for non-printables
		if (nbr >= 0 && nbr <= 31) {
			cout << "\t|\t" << "NA";
			fileWriter << "\t|\t" << "NA";
		}
		//Test for space
		else if (nbr == 32) {
			cout << "\t|\t" << "Space";
			fileWriter << "\t|\t" << "Space";
		}
		//Printing of any symbols or letters
		else {
			cout << "\t|\t" << static_cast<char>(nbr);
			fileWriter << "\t|\t" << static_cast<char>(nbr);
		}
		

		
		//Third column
		//Print upper case
		//Test for upper case letters
		
		if(nbr >= 65 && nbr <= 90) {
			cout << "\t|\t" << static_cast<char>(nbr);
			fileWriter << "\t|\t" << static_cast<char>(nbr);
		}
		//Test for lower case letters
		else if (nbr >= 97 && nbr <= 122) {
			cout << "\t|\t" << static_cast<char>((nbr - 32));
			fileWriter << "\t|\t" << static_cast<char>((nbr - 32));
		}
		//Test for non-printables
		else if (nbr >= 0 && nbr <= 31) {
			cout << "\t|\t" << "NA";
			fileWriter << "\t|\t" << "NA";
		}
		//Test for space
		else if (nbr == 32) {
			cout << "\t|\t" << "Space";
			fileWriter << "\t|\t" << "Space";
		}
		//Else for everything that is a symbol that doesn't have an upper or lower case
		else {
			cout << "\t|\t" << "-";
			fileWriter << "\t|\t" << "-";
		}

		//Fourth Column
		//Print lower case
		//Test for lower case
		if (nbr >= 97 && nbr <= 122) {
			cout << "\t|\t" << static_cast<char>(nbr) << '\n';
			fileWriter << "\t|\t" << static_cast<char>(nbr) << '\n';
		}
		//Test for upper case
		else if (nbr >= 65 && nbr <= 90) {
			cout << "\t|\t" << static_cast<char>((nbr + 32)) << '\n';
			fileWriter << "\t|\t" << static_cast<char>((nbr + 32)) << '\n';
		}
		//Test for non-printables
		else if (nbr >= 0 && nbr <= 31) {
			cout << "\t|\t" << "NA" << '\n';
			fileWriter << "\t|\t" << "NA" << '\n';
		}
		//Test for space
		else if (nbr == 32) {
			cout << "\t|\t" << "Space" << '\n';
			fileWriter << "\t|\t" << "Space" << '\n';
		}
		//Else for everything that is a symbol that doesn't have an upper or lower case
		else {
			cout << "\t|\t" << "-" << '\n';
			fileWriter << "\t|\t" << "-" << '\n';
		}
		
		//Increment the loop
		counter++;
	}
	//Closing the random numbers file
	fileWriter.close();

	return 0;



}