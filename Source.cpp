#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int num;
	int lim1;
	int lim2;
	int pc_num = 0;
	int c = 0;
	char diff;
	char ans;
	char retry;
	bool counter = false;

	do {
		do {
			cout << "Do you want to set your own parameters? Y/N: ";
			cin >> ans; ans = tolower(ans);
			srand(time(NULL));

			switch (ans) {

			case 'y':
				cout << "Please select the first limit: ";
				cin >> lim1;
				while (!cin) {
					cout << "Invalid input.\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> lim1;
				}
				cout << "Now insert the second limit: ";
				cin >> lim2;
				while (!cin) {
					cout << "Invalid input.\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> lim2;
				}
				pc_num = lim1 + rand() % (lim2-lim1);
				cout << "A number between " << lim1 << " and " << lim2 << " has been generated!\n";
				break;

			case 'n':
				do {
					cout << "Would you like to play on a predetermined difficulty then? Y/N: ";
					cin >> ans; ans = tolower(ans);

					switch (ans) {

					case 'y':
						do {
							cout << "E for Easy (1 to 10)\nM for Medium (1 to 100)\nH for Hard (1 to 1000)\nX for Expert (1 to 10000)\nPlease select a difficuly: ";
							cin >> diff; diff = tolower(diff);

							switch (diff) {

							case 'e':
								pc_num = 1 + rand() % 10;
								cout << "\nA number between 1 and 10 has been generated!\n";
								break;

							case 'm':
								pc_num = 1 + rand() % 100;
								cout << "\nA number between 1 and 100 has been generated!\n";
								break;

							case 'h':
								pc_num = 1 + rand() % 1000;
								cout << "\nA number between 1 and 1000 has been generated!\n";
								break;

							case 'x':
								pc_num = 1 + rand() % 10000;
								cout << "\nA number between 1 and 10000 has been generated!\n";
								break;
							default:
								cout << "\nSomething went wrong. Command not recognizable.\n";
								break;
							}
						} while ((diff != 'e') && (diff != 'm') && (diff != 'h') && (diff != 'x'));
						break;

					case 'n':
						do {
							cout << "Would you like to play on a randomly generated difficulty then?\nThis is the last mode, if you say no the game will quit. Y/N: ";
							cin >> ans; ans = tolower(ans);

							switch (ans) {

							case 'y':
								lim1 = 1 + rand() % 10000;
								lim2 = 1 + rand() % 10000;
								if (lim1 > lim2) {
									pc_num = lim2 + rand() % (lim1-lim2);
									cout << "A number between " << lim2 << " and " << lim1 << " has been generated!\n";
								}
								else {
									pc_num = lim1 + rand() % (lim2-lim1);
									cout << "A number between " << lim1 << " and " << lim2 << " has been generated!\n";
								}
								break;

							case 'n':
								return 0;

							default:
								cout << "\nSomething went wrong. Command not recognizable.\n";
								break;
							}
						} while ((ans != 'y') && (ans != 'n'));
						break;

					default:
						cout << "\nSomething went wrong. Command not recognizable.\n";
						break;
					}
				} while ((ans != 'y') && (ans != 'n'));
				break;

			default:
				cout << "\nSomething went wrong. Command not recognizable.\n";
				break;
			}
		} while ((ans != 'y') && (ans != 'n'));

		do {
			cout << "Would you like to keep record of your tries? Y/N: ";
			cin >> ans; ans = tolower(ans);
			if (ans == 'y') counter = true;
			else if (ans == 'n') counter = false;
			else {
				cout << "Command not recognizable.\n";
			}
		} while (ans != 'y' && ans != 'n');

		cout << "Guess the number!\n";
		cin >> num;
		
		while (num != pc_num) {
			if (!cin) {
				cout << "Invalid input.\n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			else {
				c++;
				if (c > 1) {
					if (num > pc_num) {
						cout << "Lower. Try Again: ";
					}
					else {
						cout << "Higher. Try Again: ";
					}
				}
				else {
					if (num > pc_num) {
						cout << "The number you're looking for is lower. Try again: ";
					}
					else {
						cout << "The number you're looking for is higher. Try again: ";
					}
				}
			}
			cin >> num;
		}

		cout << "Congratulations! You got it!\n";
		if (counter == true) cout << "You failed a total of " << c << " times.";

		cout << "\nWould you like to play again? Y/N: ";
		cin >> retry; retry = tolower(retry);
		cout << endl;

	} while (retry == 'y');
	return 0;
}