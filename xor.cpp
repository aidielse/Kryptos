#include "xor.h"
//xor's two strings of binary numbers that are equal length
string X_OR(string &a, string &b) {

	int i = 0;
	string out = "";
	while(i < a.size()) {

		if(a[i] == b[i]) {
			out +="0";
		}
		else {
			out +="1";
		}
		i++;
	}
	return out;
}
//performs fixed xor on two Hex strings of equal length
string fixedXor(string &a,string &b) {

	string foo = "";
	string bar = "";

	for(int i = 0; i < a.size(); i++) {

		foo += hextobin(a[i]);
	}
	for(int i = 0; i < b.size(); i++) {

		bar += hextobin(b[i]);
	}

	string output = X_OR(foo,bar);

	int i = 0;
	string result = "";
	while(i < output.size()) {
		string temp = "";
		temp = output[i];
		temp += output[i+1];
		temp += output[i+2];
		temp += output[i+3];

		result += bintohex(temp);
		i = i + 4;
	}
	return result;
}