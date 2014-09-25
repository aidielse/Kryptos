#include "base64.h"

int main() {

	char command;
	string main_menu = "MAIN MENU\n1: base64 options\nh: Print this menu\nq: exit\n\n";
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
							cout << main_menu;
							loop=false;
							break;
						}
					}
				}
				break;
			}
			{case 'h':
				cout << main_menu;
				break;
			}
			{case 'q':
				return 0;
			}
		}
	}
	return 0;
}
