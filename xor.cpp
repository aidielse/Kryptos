#include "xor.h"
//xor's two strings of binary numbers that are equal length
string X_OR_byte(string &a, string &b) {

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

	string output = X_OR_byte(foo,bar);

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
//this function performs all possible xor operations on the given input
//the input string must be composed of '0''s and '1''s and must be a multiple of 8 in length
vector <string> X_OR(string &input) {

	string hexmatrix[16] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};

	vector <string> outputs;
	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 16; j++) {
			string temp = "";
			for(int k = 0; k < input.size();k = k+8) {

				string a = hexmatrix[i] + hexmatrix[j];
				string b = "";
				b += input[k];
				b += input[k+1];
				b += input[k+2];
				b += input[k+3];
				b += input[k+4];
				b += input[k+5];
				b += input[k+6];
				b += input[k+7];
				temp += X_OR_byte(a,b);
			}
			outputs.push_back(temp);
		}
	}
	return outputs;
}
//prints all possible XOR results
int sByteXor(string &input) {

	ofstream output("plaintexts.txt");
	string temp = "";
	//convert input argument from hex to it's binary equivalent, store in string temp
	for(int i = 0; i < input.size(); i++) {
		temp += hextobin(input[i]);
	}
	//cout << "temp  = " << temp << "\n";
	//perform all possible xor operations, store result in xor_results
	vector <string> xor_results = X_OR(temp);

	vector <string> ascii_results;

	//this for loop converts each xor result from binary to ascii and stores it in ascii_results
	for(int i = 0; i < xor_results.size(); i++) {
		string bar = "";
		for(int j = 0; j < xor_results[i].size(); j = j + 8) {

			string foo = "";
			foo += xor_results[i][j];
			foo += xor_results[i][j+1];
			foo += xor_results[i][j+2];
			foo += xor_results[i][j+3];
			foo += xor_results[i][j+4];
			foo += xor_results[i][j+5];
			foo += xor_results[i][j+6];
			foo += xor_results[i][j+7];

			bar += bintoc(foo);
		}
	ascii_results.push_back(bar);
	}
	//print all ascii_results
	string bar = "";
	for(int i = 0; i < ascii_results.size(); i++) {
		bar = ascii_results[i] + "\n";
		output << bar;
	}
	output.close();
	return 0;
}

int detectXor() {
	string inputfile;
	//get name of input file with hex encoded single byte XOR encrypted ciphertexts.
	cout << "Enter the name of an existing text file in the current directory: ";
	cin >> inputfile;

	ifstream input(inputfile);
	//open output file
	ofstream output("plaintexts.txt");

	string bar = "";

	while(input.good()) {
		string temp = "";
		string baz = "";
		//get line (ciphertext) from input, store in baz 
		getline(input,baz);

		//compute all possible plaintexts, write store them in ascii_results vector
		if(input.good()) {
			//convert hex to binary, store in temp
			for(int i = 0; i < baz.size(); i++) {
				temp += hextobin(baz[i]);
			}
			//cout << "temp  = " << temp << "\n";
			//perform xor, all possible xor results are stored in the vector
			vector <string> xor_results = X_OR(temp);

			vector <string> ascii_results;
			//convert every xor result from binary to the corresponding ascii characters
			for(int i = 0; i < xor_results.size(); i++) {
				string bar = "";
				for(int j = 0; j < xor_results[i].size(); j = j + 8) {

					string foo = "";
					foo += xor_results[i][j];
					foo += xor_results[i][j+1];
					foo += xor_results[i][j+2];
					foo += xor_results[i][j+3];
					foo += xor_results[i][j+4];
					foo += xor_results[i][j+5];
					foo += xor_results[i][j+6];
					foo += xor_results[i][j+7];

					bar += bintoc(foo);
				}
				//store ascii characters in ascii_results vector
				ascii_results.push_back(bar);
			}
			//print all ascii_results
			for(int i = 0; i < ascii_results.size(); i++) {
				bar = ascii_results[i] + "\n";
				output << bar;
			}
		}
	}
	//close input and output files
	input.close();
	output.close();

	return 0;
}