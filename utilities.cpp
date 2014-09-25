#include "utilities.h"

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