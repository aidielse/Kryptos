#include "base64.h"
#include "xor.h"
#include "scoring.h"

int main() {

	char command;
	string main_menu = "\nMAIN MENU\n1: Base64 options\n2: Xor options\nh: Print this menu\nq: Quit\n\n";
	string base64_options = "\nBASE64 OPTIONS\n1: Convert Hex to Base 64 \n2: Convert Base 64 to Hex\nh: Print this menu\nb: Back to main menu\n\n";
	string Xor_options = "\nXOR OPTIONS\n1: Fixed Xor of two hex strings (equal length)\n2: Break single byte Xor\n3: Detect and break single byte Xor\n4: Perform repeating key Xor\n5: Break Repeating Key Xor\nh: Print this menu\nb: Back to main menu\n\n";
	cout << main_menu;
	cout << "Kryptos>";

	while(1) {		

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
						{case 'q':
							cout << main_menu;
							loop=false;
							break;
						}
					}
				}
				break;
			}
			{case '2':
				cout << Xor_options;
				bool loop = true;
				while(loop) {
					command = cin.get();

					if(command == '\n') {
						cout << "Kryptos/Xor>";
					}

					switch(command) {
						{case '1':
							string inputone;
							string inputtwo;
							cout << "First hex string: ";
							cin >> inputone;
							cout << "Second hex string: ";
							cin >> inputtwo;

							cout << "\noutput: " << fixedXor(inputone,inputtwo) << "\n";
							break;
						}
						{case '2':
							string input;
							cout << "Hex to break: ";
							cin >> input;
							sByteXor(input);
							scoring();
						break;
						}
						{case '3':
							detectXor();
							scoring();
						}
						{case '4':
							string input;
							cout << "Enter a key: ";
							cin >> input;
							repeating_Xor(input);
							cout << "Output written to repeating_xor_output.txt\n";
						}
						{case '5':
							break_Rkey_Xor();
						}
						{case 'h':
							cout << Xor_options;
							break;
						}
						{case 'b':
							cout << main_menu;
							loop=false;
							break;
						}
						{case 'q':
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
