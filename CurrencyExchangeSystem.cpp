// CHONG WAN XIAN CASEY D0332310439
// NURNISA NABIHAH D032310494
// FARAH ATIQAH D032310480
// NURINA MAIZURAH D032310343

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <fstream>

using namespace std;

// Declaration of constant global variable
const int personNum = 10;

// Data structure for user to input their personal information
struct PERSON {

	// Declaration of local variable (elements) inside a data structure
	char name[60] = { '\0' };
	string phoneEmail[2][1] = { "" };

};

// Declaration of function prototypes
void intro();
PERSON inputUserInfo();
void countriesProvided(char answer[]);
int aseanCountriesList(char[][30], char[][5], double[][2]);
int asiaCountriesList(char[][30], char[][5], double[][2]);
int europeCountriesList(char[][30], char[][5], double[][2]);
void countryCalculation(char [][30], double []);
void askConversion();
double enterAmountRM();
void chooseCountry(int, char [][30], double [], char [][30], char [][5], double [][2]);
void halfReceipt(char[], char[], double, double, double, double, double);
void displayReceipt(bool, char[], string, string, char[], char[], double, double,
	double, double, double, string[], int);
bool paymentConfirmation();
char askForFeedback(int&, string[]);
int inputFeedback(string[]);
void reportRecordUser(PERSON);

// CHONG WAN XIAN CASEY D032310439
int main() {

	// Declaration of data structure
	PERSON userInfo[personNum];

	// Declaration of local variable in main()
	int userList = 0, amountComment = 0, feedbackRate = 0;
	char addUser = '0';
	string comments[3] = { "" };
	bool confirmationForChange = false, confirmationFeedback = false;

	intro();

	// Do-while loop to check whether user wanna add another currency exchange or not
	do {

		// Declaration of Array & Reset Array
		char countrySelectInfo[3][30] = { '\0' };
		double countrySelectCurrencyInfo[5] = { 0.0 };

		// Reset the answer to avoid unlimited loop
		amountComment = 0;
		addUser = '0';

		// Function call for user to input their data (Pass by value)
		userInfo[userList] = inputUserInfo();

		// Function call to record (redirect) user info into report file
		// Pass by reference
		reportRecordUser(userInfo[userList]);

		// Do-while loop when payment confirmation for change = true
		do {

			// Reset the answer to avoid unlimited loop
			confirmationForChange = false;

			// Function call to show all the countries (Continents List)
			// Pass by reference
			countriesProvided(countrySelectInfo[0]);

			// Function call to make calculation based on country chose
			// Pass by reference
			countryCalculation(countrySelectInfo, countrySelectCurrencyInfo);
			
			// Function call to display the half of the receipt (Payment part)
			// Pass by reference
			halfReceipt(countrySelectInfo[1], countrySelectInfo[2], countrySelectCurrencyInfo[1], countrySelectCurrencyInfo[3],
				countrySelectCurrencyInfo[0], countrySelectCurrencyInfo[4], countrySelectCurrencyInfo[2]);

			// Function call to get payment confirmation by user
			// Pass by reference
			confirmationForChange = paymentConfirmation();

			// Do-while loop when payment confirmation for change = true
		} while (confirmationForChange == true);

		// Function call to allow user to input feedback
		// Pass by reference
		confirmationFeedback = askForFeedback(amountComment, comments);

		// Function call to display the whole receipt
		// Pass by reference
		displayReceipt(confirmationFeedback, userInfo[userList].name, userInfo[userList].phoneEmail[0][0], userInfo[userList].phoneEmail[1][0],
			countrySelectInfo[0], countrySelectInfo[1], countrySelectCurrencyInfo[1], countrySelectCurrencyInfo[3],
			countrySelectCurrencyInfo[0], countrySelectCurrencyInfo[4], countrySelectCurrencyInfo[2],
			comments, amountComment);

		// Ask user whether they wanna add another currency exchange or not
		cout << endl << endl;
		cout << "Do you wanna make another currency exchange? Answer in number form ( 1 [YES] OR 0 [NO] )" << endl;
		cout << "Answer: ";
		cin >> addUser;

		// Switch-case used to verify their answer
		switch (addUser) {
		case '1':

			userList += 1;

			// cin.ignore() use to clear the buffer
			cin.ignore();

			// For-loop to reset all the information of country chose as well as all the comments
			for (int x = 0; x < 3; x++) {
				
				// Use stycpy_s to reset the value for char
				strcpy_s(countrySelectInfo[x], "\0");
				comments[x] = "";
			}

			// For-loop to reset all the information of country chose currency
			for (int x = 0; x < 5; x++) {
				countrySelectCurrencyInfo[x] = 0.0;
			}
		}

		// Do-while loop to check whether user wanna add another currency exchange or not
		// Loop when yes
	} while (addUser == '1');

	// Normal feedback that take write down at function main() only
	cout << endl << "------------------------------------------------" << endl << endl;
	cout << "How many stars do you rate for us? 1 - 5" << endl;
	cout << "Rate: ";
	cin >> feedbackRate; // Let user input the feedback rate towards this system

	// Ternary condition that replace the use of if-statement
	(feedbackRate >= 1 && feedbackRate <= 5) ? cout << endl << "Thanks for rating! See you next time." << endl :
		cout << endl << "The rate you input was invalid\nThe system closed automatically..." << endl;

	return 0;

}

// FARAH ATIQAH D032310480
// Function definition to display the introduction
// Pass by reference
void intro() {

	// Input file
	ifstream readIntro;
	string line = "";

	// Read file from introduction.txt
	readIntro.open("introduction.txt");

	// Read file line by line
	while (getline(readIntro, line)) {
		cout << line << endl;
	}

	// close the file
	readIntro.close();

	return;
}

// NURNISA NABIHAH D032310494
// Function definition for data structure
// Function for user in to input their data
// Pass by value
PERSON inputUserInfo() {

	// Declaration of local variables
	char  lastName[60] = { '\0' };
	int lengthFirstName = 0;

	// Declaration of local data structure
	PERSON userInfo;

	// User input their first name
	cout << endl << "Please insert your first name: ";
	cin.getline(userInfo.name, 60);

	// User input their last name
	cout << "Please insert your last name: ";
	cin.getline(lastName, 60);

	// Use strlen to check the length of the character (name)
	lengthFirstName = strlen(userInfo.name);
	userInfo.name[lengthFirstName] = ' ';
	
	// Use strcat_s to append last name with first name
	strcat_s(userInfo.name, lastName);

	// User input their phone number
	cout << "Please insert your phone number: ";
	getline(cin, userInfo.phoneEmail[0][0]);

	// User input their email address
	cout << "Please insert your email address: ";
	getline(cin, userInfo.phoneEmail[1][0]);

	return userInfo;

}

// NURNISA NABIHAH D032310494
// Function definition that list out all the countries set that our system provided
// Pass by reference
void countriesProvided(char answer[]) {

	// Declaring local variable
	int lengthCharacter = 0, integerInput = 0;
	bool x = false;

	// Get continent that chose by the user
	cout << endl << "------------------------------------------------" << endl << endl;
	cout << "Here are 3 type of continents we provided" << endl;
	cout << "\t1. Countries in South East Asia (ASEAN)" << endl;
	cout << "\t2. Countries in Asia" << endl;
	cout << "\t3. Countries in Europe" << endl;
	cout << endl << "Please choose either one to show all of countries included" << endl;
	cout << "You can in number form (1-3) or in word form" << endl;
	cout << "Your choice: "; // Input your choice in number form
	cin.getline(answer, 30);

	// Do-while loop to vadidate user answer
	do {

		// Reset the boolean value to avoid unlimited loop
		x = false;

		// If-statement to check whether the first character is digit or not
		if (isdigit(answer[0])) {

			// Use strlen to calculate length of the character
			lengthCharacter = strlen(answer);

			// Convert the character into integer and save in variable integerInput
			integerInput = atoi(answer);

			// If-statement to check whether the length of the character > 1 or not
			// As well as check whether the integer that user input is between 1 - 3 or not
			if (lengthCharacter > 1) {

				// Run all these if > 1
				cout << endl << "\tSince you input using number form" << endl;
				cout << "\tWe only accept 1 character only" << endl;
				cout << "\tFor exp, 1 is one character (Valid) while 12 is two characters (Invalid)" << endl;
				cout << "\tPlease try again" << endl;
				cout << "\tYour choice: "; // Input your choice in number form
				cin.getline(answer, 30);
				x = true;

			}
			else if (integerInput <= 0 || integerInput > 3) {

				// Run all thse if not
				cout << endl << "\tSince you input using number form" << endl;
				cout << "\tWe didnt find the continents that you input, which is invalid" << endl;
				cout << "\tPlease try again" << endl;
				cout << "\tYour choice: "; // Input your choice in number form
				cin.getline(answer, 30);
				integerInput = atoi(answer);
				x = true;

			}

		}
		else {

			// Convert all the character into uppercase
			_strupr_s(answer, 30);

			// If-statement to check whether which continent that user chose

			if (strcmp(answer, "SOUTH EAST ASIA") == 0 || strcmp(answer, "ASEAN") == 0) {

				// Use strcpy_s to set the formatted continent name
				strcpy_s(answer, 30, "SOUTH EAST ASIA");
				//y = false;
				break;
			}
			else if (strcmp(answer, "ASIA") == 0) {
				strcpy_s(answer, 30, "ASIA");
				//y = false;
				break;
			}
			else if (strcmp(answer, "EUROPE") == 0) {
				strcpy_s(answer, 30, "EUROPE");
				//y = false;
				break;
				}

			// If-statement to vadidate the answer from user
			cout << endl << "\tSince you input using word form" << endl;
			cout << "\tWe didn't find the continents that you input" << endl;
			cout << "\tBe make sure the spelling is correct" << endl;
			cout << "\tPlease try again" << endl;
			cout << "\tYour choice: "; // Input your choice in number form
			cin.getline(answer, 30);
			x = true;

		}

	} while (x == true);

	// If-statement to check whether which continent that user chose
	// And set the formatted coninent name
	if (answer[0] == '1') {
		strcpy_s(answer, 30, "SOUTH EAST ASIA");
	}
	else if (answer[0] == '2') {
		strcpy_s(answer, 30, "ASIA");
	}
	else if (answer[0] == '3') {
		strcpy_s(answer, 30, "EUROPE");
	}

	return;

}

// CHONG WAN XIAN CASEY D0332310439
// Function definition to show all the countries in Asean
// Pass by value and reference
int aseanCountriesList(char countriesASEAN[][30], char codeASEAN[][5], double currencyASEAN[][2]) {

	// Input file
	ifstream readCountries;

	// Read file from aseanCountriesProvided.txt
	readCountries.open("aseanCountriesProvided.txt");

	// Declaration of local variables and arrays
	int x = 0, y = 0;
	char tempLine[100][30] = { '\0' }, line[30] = { '\0' };
	char tempCurrencyASEAN[2][15] = { '\0' };

	// While-loop use to read the file line by line
	while (readCountries.getline(line, 30)) {
		strcpy_s(tempLine[x], line);
		x++;
	}

	// For-loop to save each line into arrays
	for (int z = 0; z < x; y++, z += 5) {
		strcpy_s(countriesASEAN[y], tempLine[z]);
		strcpy_s(codeASEAN[y], tempLine[z + 1]);
		strcpy_s(tempCurrencyASEAN[0], tempLine[z + 2]);
		strcpy_s(tempCurrencyASEAN[1], tempLine[z + 3]);
		for (int a = 0; a < 2; a++) {
			currencyASEAN[y][a] = atof(tempCurrencyASEAN[a]);
		}
	}

	cout << endl << "------------------------------------------------" << endl << endl;
	cout << "Here are some countries that we provided in the lists of South East Asia" << endl;

	// For-loop to display all the possible countries in ASEAN
	for (int z = 0; z < y; z++) {
		cout << "\t" << z + 1 << ". " << left << setw(20) << countriesASEAN[z];
		cout << "\tCode: " << codeASEAN[z];
		cout << "\tRate (1 MYR): " << fixed << setprecision(2) << currencyASEAN[z][0];
		cout << endl << fixed << setprecision(0);
	}

	// Close the file
	readCountries.close();

	return y;

}

// NURINA MAIZURAH D032310343
// Function definition to show all the countries in Asia
// Pass by value and reference
int asiaCountriesList(char countriesAsia[][30], char codeAsia[][5], double currencyAsia[][2]) {

	// Input file
	ifstream readCountries;

	// Read file from asiaCountriesProvided.txt
	readCountries.open("asiaCountriesProvided.txt");

	// Declaration of local variables and arrays
	int x = 0, y = 0;
	char tempLine[100][30] = { '\0' }, line[30] = { '\0' };
	char tempCurrencyAsia[2][15] = { '\0' };

	// While-loop use to read the file line by line
	while (readCountries.getline(line, 30)) {
		strcpy_s(tempLine[x], line);
		x++;
	}

	// For-loop to save each line into arrays
	for (int z = 0; z < x; y++, z += 5) {
		strcpy_s(countriesAsia[y], tempLine[z]);
		strcpy_s(codeAsia[y], tempLine[z + 1]);
		strcpy_s(tempCurrencyAsia[0], tempLine[z + 2]);
		strcpy_s(tempCurrencyAsia[1], tempLine[z + 3]);
		for (int a = 0; a < 2; a++) {
			currencyAsia[y][a] = atof(tempCurrencyAsia[a]);
		}
	}

	// For-loop to display all the possible countries in ASEAN
	cout << endl << "------------------------------------------------" << endl << endl;
	cout << "Here are some countries that we provided in the lists of South East Asia" << endl;
	for (int z = 0; z < y; z++) {
		cout << "\t" << z + 1 << ". " << left << setw(20) << countriesAsia[z];
		cout << "\tCode: " << codeAsia[z];
		cout << "\tRate (1 MYR): " << fixed << setprecision(2) << currencyAsia[z][0];
		cout << endl << fixed << setprecision(0);
	}

	// Close the file
	readCountries.close();

	return y;

}

// NURNISA NABIHAH D032310494
// Function definition to show all the countries in Europe
// Pass by value and reference
int europeCountriesList(char countriesEurope[][30], char codeEurope[][5], double currencyEurope[][2]) {

	// Input file
	ifstream readCountries;

	// Read file from europeCountriesProvided.txt
	readCountries.open("europeCountriesProvided.txt");

	// Declaration of local variables and arrays
	int x = 0, y = 0;
	char tempLine[100][30] = { '\0' }, line[30] = { '\0' };
	char tempCurrencyEurope[2][15] = { '\0' };

	// While-loop use to read the file line by line
	while (readCountries.getline(line, 30)) {
		strcpy_s(tempLine[x], line);
		x++;
	}

	// For-loop to save each line into arrays
	for (int z = 0; z < x; y++, z += 5) {
		strcpy_s(countriesEurope[y], tempLine[z]);
		strcpy_s(codeEurope[y], tempLine[z + 1]);
		strcpy_s(tempCurrencyEurope[0], tempLine[z + 2]);
		strcpy_s(tempCurrencyEurope[1], tempLine[z + 3]);
		for (int a = 0; a < 2; a++) {
			currencyEurope[y][a] = atof(tempCurrencyEurope[a]);
		}
	}

	// For-loop to display all the possible countries in ASEAN
	cout << endl << "------------------------------------------------" << endl << endl;
	cout << "Here are some countries that we provided in the lists of South East Asia" << endl;
	for (int z = 0; z < y; z++) {
		cout << "\t" << z + 1 << ". " << left << setw(20) << countriesEurope[z];
		cout << "\tCode: " << codeEurope[z];
		cout << "\tRate (1 MYR): " << fixed << setprecision(2) << currencyEurope[z][0];
		cout << endl << fixed << setprecision(0);
	}

	// Close the file
	readCountries.close();

	return y;

}

// CHONG WAN XIAN CASEY D0332310439
// Function definition to make calculation for the country chose
// Pass by value and reference
void countryCalculation(char countrySelectInfo[][30],
	double countrySelectCurrencyInfo[]) {

	// Declaration of local variables and arrays
	int x = 0;
	char allCountriesChose[20][30] = { '\0' }, allCodeChose[20][5] = { '\0' }; double allCurrencyChose[20][2];
	
	// If-statement to check the continent that user chose
	if (strcmp(countrySelectInfo[0], "SOUTH EAST ASIA") == 0) {

		// Function call to display all the possible countries in Asean
		// Pass by value and reference
		x = aseanCountriesList(allCountriesChose, allCodeChose, allCurrencyChose);

		// Function call to ask user whether they wanna make conversion or not
		// Pass by value
		askConversion();

		// Function call to allow user to enter amount in RM
		// Pass by value
		countrySelectCurrencyInfo[0] = enterAmountRM();

		// Function call to let user choose countries in the lists
		// Pass by reference
		chooseCountry(x, countrySelectInfo, countrySelectCurrencyInfo, allCountriesChose, allCodeChose, allCurrencyChose);
	}
	else if (strcmp(countrySelectInfo[0], "ASIA") == 0) {

		// Function call to display all the possible countries in Asia
		// Pass by value and reference
		x = asiaCountriesList(allCountriesChose, allCodeChose, allCurrencyChose);

		// Function call to ask user whether they wanna make conversion or not
		// Pass by value
		askConversion();

		// Function call to allow user to enter amount in RM
		// Pass by value
		countrySelectCurrencyInfo[0] = enterAmountRM();

		// Function call to let user choose countries in the lists
		// Pass by reference
		chooseCountry(x, countrySelectInfo, countrySelectCurrencyInfo, allCountriesChose, allCodeChose, allCurrencyChose);
	}
	else if (strcmp(countrySelectInfo[0], "EUROPE") == 0) {

		// Function call to display all the possible countries in Europe
		// Pass by value and reference
		x = europeCountriesList(allCountriesChose, allCodeChose, allCurrencyChose);

		// Function call to ask user whether they wanna make conversion or not
		// Pass by value
		askConversion();

		// Function call to allow user to enter amount in RM
		// Pass by value
		countrySelectCurrencyInfo[0] = enterAmountRM();

		// Function call to let user choose countries in the lists
		// Pass by reference
		chooseCountry(x, countrySelectInfo, countrySelectCurrencyInfo, allCountriesChose, allCodeChose, allCurrencyChose);
	}

	// Formula to calculate the conversion amount and cost charge
	countrySelectCurrencyInfo[3] = countrySelectCurrencyInfo[4] = 1.0;
	countrySelectCurrencyInfo[3] = countrySelectCurrencyInfo[0] * countrySelectCurrencyInfo[1];
	countrySelectCurrencyInfo[4] = countrySelectCurrencyInfo[0] * countrySelectCurrencyInfo[2];

	return;

}

// NURINA MAIZURAH D032310343
// Function definition to ask user whether they wanna make conversion or not
// Pass by value
void askConversion() {

	// Declaration of local variables
	char convert = '0';

	// Let user input whether they wanna make conversion or not
	cout << endl << "Do you want you make a conversion? Answer in number form ( 1 [YES] OR 0 [NO] )" << endl;
	cout << "Answer: ";
	cin >> convert;

	// Switch-case to check their answer
	switch (convert) {
	case '1': // If answr = 1, do nothing
		break;
	case '0': // If answer = 0, system close
		cout << endl << "The system closed automatically....." << endl << endl;

		// exit() function use to exit the system directly
		exit(0);
		break;
	default: // If answer = invalid, system close
		cout << endl << "Answer was invalid\nThe system closed automatically....." << endl << endl;

		// exit() function use to exit the system directly
		exit(0);
	}

	return;

}

// FARAH ATIQAH D032310480
// Function definition to let user input amount in RM
// Pass by value
double enterAmountRM() {

	// Declaration of local variable
	double amountRM = 0.0;

	cout << endl << endl << "Please insert a amount in MYR: RM";
	cin >> amountRM;

	// While-loop to vadidate the amountRM
	while (amountRM <= 0) {
		cout << endl << "\tThe amount you input seem not make any sense" << endl;
		cout << "\tPlease insert amount in positive number" << endl;
		cout << "\tPlease insert a amount in MYR: RM";
		cin >> amountRM;
	}

	// cin.ignore() use to clear the buffer
	cin.ignore();

	return amountRM;

}

// CHONG WAN XIAN CASEY D0332310439
// Function definition to let user choose countries in the lists
// Pass by reference
void chooseCountry(int a, char countrySelectInfo[][30], double countrySelectCurrencyInfo[], char countriesChooseLists[][30],
	char codeChooseLists[][5], double currencyChooseLists[][2]) {

	// Declaration of local variables
	bool z = false, b = true;
	int lengthCharacter = 0, numChoose = 0, integerInput = 0;

	// Get country that chose by the user
	cout << endl << endl << "Which countries do you want to choose? (Answer in number form or word form)" << endl;
	cout << "Be make sure the spelling is correct, otherwise invalid" << endl;
	cout << "Answer: ";
	cin.getline(countrySelectInfo[1], 30);

	// Do-while loop to vadidate user answer
	do {

		// Reset the value to avoid unlimited loop
		z = false;
		b = true;

		// If-statement to check whether the first character is digit or not
		if (isdigit(countrySelectInfo[1][0])) {

			// Use strlen to calculate the length of the character
			lengthCharacter = strlen(countrySelectInfo[1]);

			// Convert the character into integer and save in variable integerInput
			integerInput = atoi(countrySelectInfo[1]);

			// If-statement to check whether the length of the characters > 1 or not
			// As well as to check whether answer that user input correct or not
			if (lengthCharacter > 1) {

				// If > 1, run all these
				cout << endl << "\tSince you input using number form" << endl;
				cout << "\tWe only accept 1 character only" << endl;
				cout << "\tFor exp, 1 is one character (Valid) while 12 is two characters (Invalid)" << endl;
				cout << "\tPlease try again" << endl;
				cout << "\tYour choice: "; // Input your choice in number form
				cin.getline(countrySelectInfo[1], 30);
				z = true;
			}
			else if (integerInput < 1 || integerInput > a) {

				// If not, run all these
				cout << endl << "\tSince you input using number form" << endl;
				cout << "\tWe didnt find the country that you input, which is invalid" << endl;
				cout << "\tPlease try again" << endl;
				cout << "\tYour choice: "; // Input your choice in number form
				cin.getline(countrySelectInfo[1], 30);
				integerInput = atoi(countrySelectInfo[1]);
				z = true;

			}

		}
		else {

			// Use _strupr_s to set all the characters into uppercase
			_strupr_s(countrySelectInfo[1], 30);

			// For-loop to check whether which country that chose by the user
			for (int x = 0; x < a; x++) {

				if (strcmp(countrySelectInfo[1], countriesChooseLists[x]) == 0) {
					b = false;
					break;
				}

			}

			// If-statement to vadidate user input
			if (b == true) {

				// If invalid, run all these
				cout << endl << "\tSince you input using word form" << endl;
				cout << "\tWe didn't find the country that you input" << endl;
				cout << "\tBe make sure the spelling is correct" << endl;
				cout << "\tPlease try again" << endl;
				cout << "\tYour choice: "; // Input your choice in number form
				cin.getline(countrySelectInfo[1], 30);
				z = true;
			}

		}

	} while (z == true);

	// If-statement to check whether the first character that user input is digit or not
	if (isdigit(countrySelectInfo[1][0])) {

		// For-loop and if-statement to check whether which country that chose by the user
		for (int x = 0, y = 1; x < a; x++, y++) {
			if (y == integerInput) {
				strcpy_s(countrySelectInfo[1], 30, countriesChooseLists[x]);
				strcpy_s(countrySelectInfo[2], 30, codeChooseLists[x]);
				countrySelectCurrencyInfo[1] = currencyChooseLists[x][0];
				countrySelectCurrencyInfo[2] = currencyChooseLists[x][1];
			}
		}
	} 
	else {

		// For-loop and if-statement to check whether which country that chose by the user
		for (int x = 0; x < a; x++) {
			if (strcmp(countrySelectInfo[1], countriesChooseLists[x]) == 0) {
				strcpy_s(countrySelectInfo[1], 30, countriesChooseLists[x]);
				strcpy_s(countrySelectInfo[2], 30, codeChooseLists[x]);
				countrySelectCurrencyInfo[1] = currencyChooseLists[x][0];
				countrySelectCurrencyInfo[2] = currencyChooseLists[x][1];
			}
		}

	}

	return;

}

// NURNISA NABIHAH D032310494
// Function definition that display the half of the receipt (Payment part)
// Pass by reference
void halfReceipt(char countryName[], char countryCode[], double currency, double currencyConverted,
	double originalRM, double costCharge, double costChargeRate) {

	// Display all the relavant information about payment
	cout << fixed << setprecision(2);
	cout << endl << endl << "---- Currency Conversion Result: " << endl;
	cout << setw(25) << left << "\tMain Country" << ": Malaysia (MYR)" << endl;
	cout << setw(25) << left << "\tAmount in MYR" << ": RM" << originalRM << endl;
	cout << setw(25) << left << "\tCountry that Chose" << ": " << countryName << " (" << countryCode << ")" << endl;
	cout << setw(25) << left << "\tRate of Currency" << ": " << currency << " " << countryCode << endl;
	cout << setw(25) << left << "\tAmount that converted" << ": " << currencyConverted << " " << countryCode << endl << endl;

	cout << "---- Payment:" << endl;
	cout << setw(20) << left << "\tCost Charge Rate" << ": " << costChargeRate << endl;
	cout << setw(20) << left << "\tCost Charge" << ": RM" << costCharge << endl;
	cout << fixed << setprecision(0);

	return;

}

// CHONG WAN XIAN CASEY D0332310439
// Function definition to display the whole receipt
// Pass by reference
void displayReceipt(bool confirmationFb, char name[], string phone, string email, char countryName[],
	char countryCode[], double currency, double currencyConverted,
	double originalRM, double costCharge, double costChargeRate, 
	string comments[], int amountFb) {

	// Output file
	ofstream outputReport;

	// Output data into Report_For_CurrencyExchange.txt (Append form)
	outputReport.open("Report_For_CurrencyExchange.txt", ios_base::app);

	// Display all the relavant information
	cout << endl << endl << "------------------------------------------------" << endl << endl;
	cout << "Receipt : " << endl << endl;

	cout << "---- Personal Information: " << endl;
	cout << setw(8) << left << "\tName " << ": " << name << endl;
	cout << setw(8) << left << "\tPhone " << ": " << phone << endl;
	cout << setw(8) << left << "\tEmail " << ": " << email;

	// Function call to display the payment part
	// Pass by reference
	halfReceipt(countryName, countryCode, currency, currencyConverted, originalRM, costCharge, costChargeRate);

	// If-statement to check whether the user has input for feedback or not
	if (confirmationFb == true) {
		cout << endl << "---- Feedback Leave: " << endl;
		for (int x = 0; x < amountFb; x++) {
			cout << "\tFeedback" << x + 1 << ": " << comments[x] << endl;
		}

	}

	// Redirect/ Output all the information (receipt) into the file as record
	outputReport << "------------------------------------------------" << endl << endl;
	outputReport << "Receipt : " << endl << endl;

	outputReport << "---- Personal Information: " << endl;
	outputReport << setw(8) << left << "\tName " << ": " << name << endl;
	outputReport << setw(8) << left << "\tPhone " << ": " << phone << endl;
	outputReport << setw(8) << left << "\tEmail " << ": " << email << endl << endl;

	outputReport << fixed << setprecision(2);
	outputReport << "---- Currency Conversion Result: " << endl;
	outputReport << setw(25) << left << "\tMain Country" << ": Malaysia (MYR)" << endl;
	outputReport << setw(25) << left << "\tAmount in MYR" << ": RM" << originalRM << endl;
	outputReport << setw(25) << left << "\tCountry that Chose" << ": " << countryName << " (" << countryCode << ")" << endl;
	outputReport << setw(25) << left << "\tRate of Currency" << ": " << currency << " " << countryCode << endl;
	outputReport << setw(25) << left << "\tAmount that converted" << ": " << currencyConverted << " " << countryCode << endl << endl;

	outputReport << "---- Payment:" << endl;
	outputReport << setw(20) << left << "\tCost Charge Rate" << ": " << costChargeRate << endl;
	outputReport << setw(20) << left << "\tCost Charge" << ": RM" << costCharge << endl;
	outputReport << fixed << setprecision(0);

	// If-statement to check whether the user has input for feedback or not
	if (confirmationFb == true) {
		outputReport << endl << "---- Feedback Leave: " << endl;
		for (int x = 0; x < amountFb; x++) {
			outputReport << "\tFeedback" << x + 1 << ": " << comments[x] << endl;
		}

	}

	outputReport << endl;

	// Close the file
	outputReport.close();

	return;

}

// FARAH ATIQAH D032310480
// Function definition to get payment confirmation from user
// Pass by value
bool paymentConfirmation() {

	// Declaring local variables
	bool y = false;
	char answer = '0', answer2 = '0';

	cout << endl << "------------------------------------------------" << endl << endl;
	cout << "Are you confirm your conversion as well as the payment?";
	cout << " Answer in number form ( 1 [YES] OR 0 [NO] )" << endl;
	cout << "Answer: ";
	cin >> answer;

	// If-statement to check whether the answer == 1 or answer == 2 or answer >= 2
	if (answer == '1' && isdigit(answer)) {
		y = false;
	}
	else if (answer == '0' && isdigit(answer)) {
		cout << endl << "Do you want to change all the things you choose?" << endl << endl;
		cout << "Answer in number form ( 1 [YES] OR 0 [NO] )" << endl;
		cout << "Answer: ";
		cin >> answer2;

		if (answer2 == '1' && isdigit(answer2)) {
			y = true;
		}
		else if (answer2 == '0' && isdigit(answer2)) {
			cout << endl << "The system closed automatically..." << endl;
			y = false;

			// exit() to close the system directly
			exit(0);
		}
		else {
			cout << endl << "The answer input was invalid\nThe system closed automatically..." << endl;
			y = false;

			// exit() to close the system directly
			exit(0);
		}
	}
	else {
		cout << endl << "The answer input was invalid\nThe system closed automatically..." << endl;
		y = false;

		// exit() to close the system directly
		exit(0);
	}

	cin.ignore();

	return y;

}

// FARAH ATIQAH D032310480
// Function definition to ask user for feedback
// Pass by valuea and reference
char askForFeedback(int& amountComment, string comments[]) {

	// Declaration of local variable
	char answer = '0';

	// Get user answer on whether they wanna leave feedback or not
	cout << endl << "------------------------------------------------" << endl << endl;
	cout << "Before a receipt to be generated...." << endl;
	cout << "Do you want to leave a comment about our system? Answer in number form ( 1 [YES] OR 0 [NO] )" << endl;
	cout << "Answer: ";
	cin >> answer;

	// Vadidate the answer from user
	while (!isdigit(answer) || answer != '1' && answer != '0') {
		cout << "\n\tThe answer you input was invalid" << endl;
		cout << "\tPlease try again" << endl;
		cout << "\tAnswer: ";
		cin >> answer;
	}

	// Run if user answer yes (1)
	switch (answer) {
	case '1':

		// Function call to allow user input comments
		amountComment = inputFeedback(comments);

	}

	return answer;

}

// NURINA MAIZURAH D032310343
// Function definition to allow user input comments
// Pass by value and reference
int inputFeedback(string comments[]) {

	// Declaration of local variable
	int amountComment = 0;

	// Ask user on the amount of feedback that they wanna leave
	cout << endl << "How many comments that you want to leave? Maximum 3 only" << endl;
	cout << "Amount: ";
	cin >> amountComment;

	// Vadidate their answer
	while (amountComment <= 0) {
		cout << "\n\tYou are not allow to input 0 or negative numbers" << endl;
		cout << "\tPlease try again: ";
		cin >> amountComment;
	}

	while (amountComment > 3) {
		cout << "\n\tYou are not allow to input more than 3 comments" << endl;
		cout << "\tPlease try again: ";
		cin >> amountComment;
	}

	// Use this function to clear the buffer
	cin.ignore();

	// Input comments based on the amount they input just now
	for (int x = 0; x < amountComment; x++) {
		cout << "\nComment " << x + 1 << ": ";
		getline(cin, comments[x]);
	}

	return amountComment;

}

// NURINA MAIZURAH D032310343
// Function definiiton to record/ redirect the each user information into report file
// Pass by reference
void reportRecordUser(PERSON userInfo) {
	
	// Output file
	ofstream outputReport;

	// Redirect/ output each user info into Report_For_UserInfo.txt (Append form)
	outputReport.open("Report_For_UserInfo.txt", ios_base::app);

	outputReport << "----------User Info----------" << endl;
	outputReport << "User Name: " << userInfo.name << endl;
	outputReport << "User Phone: " << userInfo.phoneEmail[0][0] << endl;
	outputReport << "User Email: " << userInfo.phoneEmail[1][0] << endl;
	outputReport << endl;

	// Close the file
	outputReport.close();

	return;

}