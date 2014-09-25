#include "base64.h"

string dectobinsix(int foo) {

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
	while(bar.size() < 6) {

		bar += "0";
	}
	//reverse the string to be returned, since it's in reverse order.
	reverse(bar.begin(),bar.end());

	return bar;
}


//converts a single base 64 character to it's int equivalent
int b64todec(char &c) {

	int index[64];

	index[0] = 'A';
	index[1] = 'B';
	index[2] = 'C';
	index[3] = 'D';
	index[4] = 'E';
	index[5] = 'F';
	index[6] = 'G';
	index[7] = 'H';
	index[8] = 'I';
	index[9] = 'J';
	index[10] = 'K';
	index[11] = 'L';
	index[12] = 'M';
	index[13] = 'N';
	index[14] = 'O';
	index[15] = 'P';
	index[16] = 'Q';
	index[17] = 'R';
	index[18] = 'S';
	index[19] = 'T';
	index[20] = 'U';
	index[21] = 'V';
	index[22] = 'W';
	index[23] = 'X';
	index[24] = 'Y';
	index[25] = 'Z';
	index[26] = 'a';
	index[27] = 'b';
	index[28] = 'c';
	index[29] = 'd';
	index[30] = 'e';
	index[31] = 'f';
	index[32] = 'g';
	index[33] = 'h';
	index[34] = 'i';
	index[35] = 'j';
	index[36] = 'k';
	index[37] = 'l';
	index[38] = 'm';
	index[39] = 'n';
	index[40] = 'o';
	index[41] = 'p';
	index[42] = 'q';
	index[43] = 'r';
	index[44] = 's';
	index[45] = 't';
	index[46] = 'u';
	index[47] = 'v';
	index[48] = 'w';
	index[49] = 'x';
	index[50] = 'y';
	index[51] = 'z';
	index[52] = '0';
	index[53] = '1';
	index[54] = '2';
	index[55] = '3';
	index[56] = '4';
	index[57] = '5';
	index[58] = '6';
	index[59] = '7';
	index[60] = '8';
	index[61] = '9';
	index[62] = '+';
	index[63] = '/';

	for(int i = 0; i < 64; i++) {
		if(c == index[i]) {
			return i;
		}
	}
	return -1;
}
//converts a binary input to base 64, hopefully the input is a multiple of 6 or else this code will not work correctly.
string bintob64(string &input) {
	char index[64];

	index[0] = 'A';
	index[1] = 'B';
	index[2] = 'C';
	index[3] = 'D';
	index[4] = 'E';
	index[5] = 'F';
	index[6] = 'G';
	index[7] = 'H';
	index[8] = 'I';
	index[9] = 'J';
	index[10] = 'K';
	index[11] = 'L';
	index[12] = 'M';
	index[13] = 'N';
	index[14] = 'O';
	index[15] = 'P';
	index[16] = 'Q';
	index[17] = 'R';
	index[18] = 'S';
	index[19] = 'T';
	index[20] = 'U';
	index[21] = 'V';
	index[22] = 'W';
	index[23] = 'X';
	index[24] = 'Y';
	index[25] = 'Z';
	index[26] = 'a';
	index[27] = 'b';
	index[28] = 'c';
	index[29] = 'd';
	index[30] = 'e';
	index[31] = 'f';
	index[32] = 'g';
	index[33] = 'h';
	index[34] = 'i';
	index[35] = 'j';
	index[36] = 'k';
	index[37] = 'l';
	index[38] = 'm';
	index[39] = 'n';
	index[40] = 'o';
	index[41] = 'p';
	index[42] = 'q';
	index[43] = 'r';
	index[44] = 's';
	index[45] = 't';
	index[46] = 'u';
	index[47] = 'v';
	index[48] = 'w';
	index[49] = 'x';
	index[50] = 'y';
	index[51] = 'z';
	index[52] = '0';
	index[53] = '1';
	index[54] = '2';
	index[55] = '3';
	index[56] = '4';
	index[57] = '5';
	index[58] = '6';
	index[59] = '7';
	index[60] = '8';
	index[61] = '9';
	index[62] = '+';
	index[63] = '/';

	string output = "";

	for(int i = 0; i < input.size(); i = i + 6) {
		string temp = "";
		temp = input[i];
		temp += input[i+1];
		temp += input[i+2];
		temp += input[i+3];
		temp += input[i+4];
		temp += input[i+5];

		//cout << "6 bytes: " << temp << "\n";
		int foo = bitstodec(temp);

		//cout << foo << "\n";

		output += index[foo];
	}	
	return output;
}

string hextob64(string &input) {
	string temp = "";
	for(int i = 0; i < input.size(); i++) {
		temp += hextobin(input[i]);
	}
	return bintob64(temp);
}

string b64tohex(string &input) {
	string bin_input="";
	for(int i =0; i < input.size(); i++) {
		bin_input += dectobinsix(b64todec(input[i]));
	}
	string output = "";
	cout << "binary input: " << bin_input << "\n";
	for(int i = 0; i < bin_input.size(); i = i + 4) {
		string foo = "";
		foo += bin_input[i];
		foo += bin_input[i+1];
		foo += bin_input[i+2];
		foo += bin_input[i+3];

		output += bintohex(foo);
	}
	return output;
}