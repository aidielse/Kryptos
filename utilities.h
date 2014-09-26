#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#ifndef UTILITIES_H
#define UTILITIES_H

int hammingDistance(string &a, string &b);
void find_shortest_distances(string &bin_text, int pos[]);
vector <string> breakIntoBlocks(int &keysize, string &ciphertext);
vector <string> transpose(vector <string> &input);
string ctobin(char &c);
char bintoc(string &input);
char bintohex(string &input);
string dectobin(int foo);
string hextobin(char &input);
int bitstodec(string &input);

#endif