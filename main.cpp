#include "base64.h"

int main() {

	char command;
	string main_menu = "MAIN MENU\n1: base64 options\nh: Print this menu\nq: exit\n\n";
	string base64_options = "BASE64 OPTIONS\n1: Convert Hex to Base 64 \n2: Convert Base 64 to Hex\nh: Print this menu\nb: Back to main menu\n\n";

	cout << main_menu;
	cout << "Kryptos>";

	while(1) {		

		//cout << "command: " << command << "\n";
		command = cin.get();

		if(command == '\n') {
			cout << "Kryptos>";
		}
				
		switch (command) {

			{case '1' :
				cout << base64_options;
				bool loop = true;
				while(loop) {
					command = cin.get();

					if(command == '\n') {
						cout << "Kryptos/b64>";
					}

					switch(command) {
						{case '1':
							string input;
							cout << "Hex string: ";
							cin >> input;
							cout << "\noutput: " << hextob64(input) << "\n";
							break;
						}
						{case '2':
							string input;
							cout << "Base 64 string: ";
							cin >> input;
							cout << "\noutput: " << b64tohex(input) << "\n";
						}
						{case 'h':
							cout <<base64_options;
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
