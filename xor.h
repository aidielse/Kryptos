#include "utilities.h"
#include <vector>
#include <fstream>
using namespace std;

#ifndef X_OR_H
#define X_OR_H

string X_OR_byte(string &a, string &b);
string fixedXor(string &a,string &b);
vector <string> X_OR(string &input);
int sByteXor(string &input);
int detectXor();
#endif