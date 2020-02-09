#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	char Pagin = 'y';
	int Round = 1;
	do {
		do {
			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 10;
			const string WORDS[NUM_WORDS][NUM_FIELDS] = {
			{"sol", "It's a nearly perfect sphere of hot plasma."},
			{"mercury", "It's the smallest and innermost planet in the solar system."},
			{"venus", "It's named after the Roman goddess of love and beauty."},
			{"earth", "It's the only astronomical object known to harbor life."},
			{"mars", "It's named after the Roman god of war."},
			{"jupiter", "It's the largest planet in the solar system."},
			{"saturn", "It's a planet that's so buoyant, it'll float in water."},
			{"uranus", "It's named after the Roman god Saturn's father."},
			{"neptune", "It's the densest gas giant in the solar system."},
			{"pluto", "It's not a planet."}
			};

			enum difficulty { EASY, MEDIUM, HARD, NUM_DIFF_LEVELS };
			cout << "There are " << NUM_DIFF_LEVELS << " difficulty levels.";
			cout << "\tRound: " << Round << endl;

			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD];
			string theHint = WORDS[choice][HINT];

			string jumble = theWord;
			int length = jumble.size();
			for (int i = 0; i < length; ++i) {
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			cout << "\t\tWelcome to Solar Jumble!\n\n";
			cout << "Unscramble the letters to make a word.\n";
			cout << "Enter 'hint' for a hint.\n";
			cout << "Enter 'quit' to quit the game.\n\n";
			cout << "The jumble is: " << jumble;

			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;

			while ((guess != theWord) && (guess != "quit")) {
				if (guess == "hint") {
					cout << theHint;
				}
				else {
					cout << "Sorry, that's not it.";
				}
				cout << "\n\nYour guess: ";
				cin >> guess;
			}

			if (guess == theWord) {
				cout << "\nThat's it! You guessed it!\n" << endl;
				Round++;
			}
		} while (Round != 4);
		cout << "Thanks for Playing!\n";

		cout << "Wanna Play Again? Y/N: ";
		cin >> Pagin;
		if (Pagin == 'y' || Pagin == 'Y') {
			Round = 1;
		}
		cout << "\n";
	} while (Pagin == 'Y' || Pagin == 'y');
	
	return 0;
}