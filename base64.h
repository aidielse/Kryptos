#include "utilities.h"
using namespace std;

#ifndef BASE_64_H
#define BASE_64_H

int b64todec(char &c);
string bintob64(string &input);
string hextob64(string &input);
string b64tohex(string &input);

#endif