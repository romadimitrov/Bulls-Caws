#include <iostream>
#include <string>

using namespace std;

const int digitNumber = 4;
const int devider = 10;
const int totalGuesses = 10;

bool isDigitRepeat = false;
bool isValidNumber = true;

int* SecretNumber(int secretNumber = 0) {

	//Array declared as static
	static int digitOfSecretNumber[digitNumber]{};

	//Running until the number is valid
	do
	{
		//Entering the  secret number that we should guess
		cout << "Enter your secret 4 digit number: ";
		cin >> secretNumber;

		if (999 > secretNumber || secretNumber > 10000) {
			cout << "Invalid number!Should be between 999 and 10000! Try again!\n" << endl;

		}

		//Checking if the number is between 999 and 10 000 and add the digit to array
		else if (999 < secretNumber && secretNumber < 10000) {
			int newNumber = secretNumber;
			isValidNumber = false;

			for (int i = 4; i > 0; --i) {
				digitOfSecretNumber[i - 1] = newNumber % devider;
				newNumber = newNumber / devider;
			}

			for (int l = 0; l < 3; ++l) {
				for (int k = l + 1; k < 4; ++k) {
					if (digitOfSecretNumber[l] == digitOfSecretNumber[k]) {
						isDigitRepeat = true;
						isValidNumber = true;
					}

				}

			}
			//Checking if number is used twice
			if (isDigitRepeat == 1) {
				cout << "Wrong number! You can't use  number twice!\n" << endl;
				isDigitRepeat = false;
			}
		}
		else
			cout << "Invalid input!" << endl;

	} while (isValidNumber);

	return digitOfSecretNumber;
}

int* Guess(int guess = 0) {

	static int digitOfGuess[digitNumber]{};

	isValidNumber = true;
	while (isValidNumber)
	{
		cout << "Enter your guess: ";
		cin >> guess;

		if (999 < guess && guess < 10000) {
			int newGuess = guess;
			isValidNumber = false;


			for (int j = 4; j > 0; j--) {
				digitOfGuess[j - 1] = newGuess % devider;
				newGuess = newGuess / devider;
			}

			for (int l = 0; l < 3; ++l) {
				for (int k = l + 1; k < 4; ++k) {
					if (digitOfGuess[l] == digitOfGuess[k]) {
						isDigitRepeat = true;
						isValidNumber = true;
					}

				}

			}
			if (isDigitRepeat == 1) {
				cout << "Wrong number! You can't use  number twice!\n" << endl;
				isDigitRepeat = false;
			}
		}

		else {
			cout << "Invalid number!Should be between 999 and 10000! Try again!\n" << endl;

		}
	}
	return digitOfGuess;
}

void CheckingForBullsAndCows(int arrayOfSecretNumber[], int length) {

	bool isPlaying = true;

	int countGuesses = 0;

	while (isPlaying)
	{

		if (totalGuesses > countGuesses) {


			int bulls = 0, cows = 0, empty = 4;	


			int* arrayOfGuessNumber;
			//Calling function Guess
			arrayOfGuessNumber = Guess();


			//Nested loops to compare the digits from the two arrays 
			for (int l = 0; l < 4; l++) {
				for (int k = 0; k < 4; k++)
				{
					if (arrayOfSecretNumber[l] == arrayOfGuessNumber[k] && l == k)
					{
						bulls++;
					}
					else if (arrayOfSecretNumber[l] == arrayOfGuessNumber[k] && l != k)
					{
						cows++;
					}

				}
			}
				
			

			if (bulls == 4) {
				isPlaying = false;
				cout << "\nCongratulation you guess the secret number!!!\n" << endl; break;
			}

			//Message that inform us how manu bulls and cows we have
			cout << "You have " << bulls << " bulls, " << cows << " cows, "
				<< empty - (bulls + cows) << "wrong numbers" << endl;

			//Counting how many guesses we 
			++countGuesses;

			//Message for how many guesses we have left
			if ((totalGuesses - countGuesses) > 1) {
				cout << "You have  " << totalGuesses - countGuesses << " guesses left\n" << endl;
			}
			else if ((totalGuesses - countGuesses) == 1) {
				cout << "You have  " << totalGuesses - countGuesses << " guess left\n" << endl;
			}
			else {
				cout << "You do not have more guesses\n" << endl;
			}


		}
		else {
			isPlaying = false;
			cout << "You lost!You run out of guesses!\n" << endl;

		}
	}

}

int main() {

	cout << "-------------------------" << endl;
	cout << "|     Bulls and Cows   |" << endl;
	cout << "-------------------------" << endl;
	cout << "| The main aim for this |" << endl;
	cout << "| game is to guess the  |" << endl;
	cout << "| others's secret number|" << endl;
	cout << "| by trial and error!   |" << endl;
	cout << "-------------------------" << endl;

	system("pause");
	system("cls");

	

	bool playAgain = true;

	do {
		//pointers to hold address
		int* arrayOfSecretNumber;
		int* arrayOfGuessNumber;

		//address of digitOfSecretNumber
		arrayOfSecretNumber = SecretNumber();
		system("cls");

		CheckingForBullsAndCows(arrayOfSecretNumber, digitNumber);   

		char answer = '/0';

		//Asking the user if he wants to play more
		cout << "Do you want to start new game? (for yes press 'y'/for no any button)" << endl;
		cin >> answer;

		//Checking the answer

		if (answer == 'y' || answer == 'Y') {
			playAgain = true;
		}

		else {
			playAgain = false;
		}


		system("cls");



	} while (playAgain);

	cout << "End of the game!" << endl;


	return 0;
}