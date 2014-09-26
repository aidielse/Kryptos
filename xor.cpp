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
	output << bar << "\n";
	}
	output.close();
	return 0;
}

int sByteXor(string &input, ofstream &output) {

	//perform all possible xor operations, store result in xor_results
	vector <string> xor_results = X_OR(input);

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
	output << bar << "\n";
	}
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

int repeating_Xor(string &key) {

	string inputFile;
	cout << "Enter the name of an existing text file in the current directory: ";
	cin >> inputFile;
	//open input file for reading
	ifstream input(inputFile);
	ofstream output("repeating_xor_output.txt");
	string output_bin = "";
	string bin_text = "";

	while(input.good()) {
		char c = input.get();
		//if input is still valid
		if(input.good()) {
			//convert character from input to 8bit binary string
			bin_text += ctobin(c);
		}
	}
	string bin_key="";
	for(int i = 0; i < key.size(); i++) {
		bin_key += ctobin(key[i]);
	}
	int foo = 0;
	for(int i = 0; i < bin_text.size(); i = i + 8) {

		string temp = "";
		temp += bin_text[i];
		temp += bin_text[i+1];
		temp += bin_text[i+2];
		temp += bin_text[i+3];
		temp += bin_text[i+4];
		temp += bin_text[i+5];
		temp += bin_text[i+6];
		temp += bin_text[i+7];

		string bar = "";

		bar += bin_key[foo];
		bar += bin_key[foo+1];
		bar += bin_key[foo+2];
		bar += bin_key[foo+3];
		bar += bin_key[foo+4];
		bar += bin_key[foo+5];
		bar += bin_key[foo+6];
		bar += bin_key[foo+7];

		foo += 8;

		foo = foo % 24;

		//cout << "XORing " << temp << " with key " << bar <<", result: " << X_OR_byte(temp,bar) << "\n";
		//cout << "foo = " << foo << "\n";
		output_bin += X_OR_byte(temp,bar);
	}
	input.close();

	for(int i = 0; i < output_bin.size(); i = i +4) {
		string temp = "";
		temp += output_bin[i];
		temp += output_bin[i+1];
		temp += output_bin[i+2];
		temp += output_bin[i+3];

		output << bintohex(temp);
	}
	output.close();
	return 0;
}

int break_Rkey_Xor() {

	string inputFile;
	cout << "Enter the name of an existing text file in the current directory: ";
	cin >> inputFile;
	//open input file for reading
	ifstream input(inputFile);
	string bin_text = "";
	//this while loop converts the input to binary form
	while(input.good()) {
		char c = input.get();
		//if input is still valid
		if(input.good()) {
			bin_text += hextobin(c);
		}
	}
	input.close();

	int pos[3];
	find_shortest_distances(bin_text,pos);

	vector <string> keyOneBlocks = breakIntoBlocks(pos[0],bin_text);
	vector <string> keyTwoBlocks = breakIntoBlocks(pos[1],bin_text);
	vector <string> keyThreeBlocks = breakIntoBlocks(pos[2],bin_text);

	vector <string> keyOneTranspose = transpose(keyOneBlocks);
	vector <string> keyTwoTranspose = transpose(keyTwoBlocks);
	vector <string> keyThreeTranspose = transpose(keyThreeBlocks);

	ofstream output("keyOneoutput.txt");
	for(int i = 0; i < keyOneTranspose.size(); i++) {
		sByteXor(keyOneTranspose[i],output);
	}
	output.close();
	ofstream output2("keyTwooutput.txt");
	for(int i = 0; i < keyTwoTranspose.size(); i++) {
		sByteXor(keyTwoTranspose[i],output2);
	}	
	output2.close();
	ofstream output3("keyThreeoutput.txt");
	for(int i = 0; i < keyThreeTranspose.size(); i++) {
		sByteXor(keyThreeTranspose[i],output3);
	}	
	output3.close();

	
	return 0;
}