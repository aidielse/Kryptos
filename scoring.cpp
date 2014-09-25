#include "scoring.h"

int scoring(string &input) {
	// get input file containing potential plaintexts
	//top 100 most frequent words in English
	ifstream topWords("topHundredWordsEnglish.txt");

	string words[100];

	int i = 0;
	//copy top words into words array
	while(topWords.good()) {
		getline(topWords,words[i]);
		i++;
	}
	//close ifstream
	topWords.close();
	//capitalize all words in words array
	for(i = 0; i < 100; i++) {
		for(int j = 0; j < words[i].size(); j++) {
			words[i][j] = toupper(words[i][j]);
		}
	}
	//vector to hold user inputs
	vector <string> inputs;
	istringstream iss(input);
	//get each potential plaintext, put into vector inputs
	for(int j = 0; j < input.size(); j++) {

		string foo = "";
		getline(iss,foo);
		inputs.push_back(foo);
		
	}
	//capitalize everything that is capitalize-able in the user's inputs, makes string search possible
	for(i = 0; i < inputs.size(); i++) {
		for(int j = 0; j < inputs[i].size(); j++) {
			inputs[i][j] = toupper(inputs[i][j]);
		}
	}
	//index for search
	int index[inputs.size()];
	//set all indexes to 0, one index per potential plaintext
	for(i = 0; i < inputs.size(); i++) {
		index[i] = 0;
	}
	// compare every string in vector inputs with each word in the top 100
	for(i = 0; i < inputs.size(); i++) { 
		for (int j = 0; j < 100 ; j++) {
			//if we find a top 100 word in the potential plaintext, the corresponding index is incremente by 1
			if(inputs[i].find(words[j]) != std::string::npos) {
				index[i]++;
			}
		}
	}
	// the most potential plaintext with the highest index is probably our correct plaintext,

	int temp = 0;
	//find the max index, store in temp
	for(i= 0; i < inputs.size(); i++) {

		if(index[i] > temp) {
			temp = index[i];
		}
	}
	//for each plaintext, if the index of the potential plaintext = maxindex - 1, print the potential plaintext.
	//we do this so that we have room for error. It is possible for the wrong plaintext to have a low index,
	// so we print highest indexes as a safeguard.
	for(i = 0; i < inputs.size(); i++) {
		if(index[i] >= temp - 1) {
			cout << inputs[i] << "\n";
		}
	}
	cout << "\n";

	return 0;
}