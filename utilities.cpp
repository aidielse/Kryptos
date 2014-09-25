#include "utilities.h"

//converts a 4 bit string to it's hex equivalent
char bintohex(string &input) {

	if (input == "0000")return '0';
		
	else if(input=="0001") return '1';

	else if(input=="0010") return '2';

	else if(input=="0011") return '3';

	else if(input=="0100") return '4';

	else if(input=="0101") return '5';

	else if(input=="0110") return '6';

	else if(input=="0111") return '7';

	else if(input=="1000") return '8';

	else if(input=="1001") return '9';

	else if(input=="1010") return 'a';

	else if(input=="1011") return 'b';

	else if(input=="1100") return 'c';

	else if(input=="1101") return 'd';

	else if(input=="1110") return 'e';

	else return 'f';
	
}

//converts an int to byte form represented as a string
string dectobin(int foo) {

string bar = "";

while(foo != 0) {

		if(foo % 2 == 1) {
			bar += "1";
		}
		else {
			bar += "0";
		}
		foo = foo/2;
	}
	//this while loop fills in zeros and make's sure the int is represented as a byte
	while(bar.size() < 8) {

		bar += "0";
	}
	//reverse the string to be returned, since it's in reverse order.
	reverse(bar.begin(),bar.end());

	return bar;
}

//takes in a hexadecimal character and converts it to it's binary representation
string hextobin(char &input) {
	
	switch(input) {

		case '0' :
			return "0000";
		case '1' :
			return "0001";
		case '2' :
			return "0010";
		case '3' :
			return "0011";
		case '4' :
			return "0100";
		case '5' :
			return "0101";
		case '6' :
			return "0110";
		case '7' :
			return "0111";
		case '8' :
			return "1000";
		case '9' :
			return "1001";
		case 'a' :
			return "1010";
		case 'b' :
			return "1011";
		case 'c' :
			return "1100";
		case 'd' :
			return "1101";
		case 'e' :
			return "1110";
		case 'f' :
			return "1111";
	}
	return NULL;
}

//takes in any number of bits represented as a string, returns it's decimal equivalent as an int 
//used for bintob64
int bitstodec(string &input) {

	int sum = 0;

	for(int i = 0; i < input.size(); i++) {

		if(input[i] == '1') {
			sum += pow(2,input.size()-1-i);
		}
	}
	return sum;
}