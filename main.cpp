#include "base64.h"

int main() {

	char command;
	cout << "MAIN MENU\n";
	cout << "1: base64 options\n";
	cout << "h: Print this menu\n";
	cout << "q: exit\n\n";
	cout << "Kryptos>";

	while(1) {		

		//cout << "command: " << command << "\n";
		command = cin.get();

		if(command == '\n') {
			cout << "Kryptos>";
		}
				
		switch (command) {

			{case '1' :
				cout << "BASE64 OPTIONS\n";
				cout << "1: Convert Hex to Base 64 \n";
				cout << "h: Print this menu\n";
				cout << "b: Back to main menu\n\n";
				bool loop = true;
				while(loop) {
					command = cin.get();

					if(command == '\n') {
						cout << "Kryptos/b64>";
					}

					switch(command) {
						{case '1':
							string input;
							cout << "hex string: ";
							cin >> input;
							cout << "\noutput: " << hextob64(input);
							break;
						}
						{case 'h':
							cout << "BASE64 OPTIONS\n";
							cout << "1: Convert Hex to Base 64 \n";
							cout << "h: Print this menu\n";
							cout << "b: Back to main menu\n\n";
							break;
						}
						{case 'b':
							cout << "MAIN MENU\n";
							cout << "1: base64 options\n";
							cout << "h: Print this menu\n";
							cout << "q: exit\n\n";
							loop=false;
							break;
						}
					}
				}
				break;
			}
			{case 'h':
				cout << "MAIN MENU\n";
				cout << "1: base64 options\n";
				cout << "h: Print this menu\n";
				cout << "q: exit\n\n";
				break;
			}
			{case 'q':
				return 0;
			}
		}
	}
	return 0;
}
