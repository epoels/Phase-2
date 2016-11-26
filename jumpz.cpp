#include "common.h"
#include "jumpz.h"
#include "jumproto.h"
#include "helperFunctions.h"

jumpz::jumpz() {}
jumpz::~jumpz() {}

void jumpz::clone(stringstream&ss, int x) {
	jumpz *ok = new jumpz();
	ok->initialize(ss, x);
}

void jumpz::initialize(stringstream &ss, int x) {
	cout << ss.str() << endl;
	linenumber = x;
	string str = ss.str();
	stringstream iss(str);
	getline(iss, str, ' ');
	getline(iss, str, ',');
	cout << "label name = " << str << endl;
	labelname = str;
	acjump(str);
}

void jumpz::acjump(string str) {
	getline(iss, str, ',');
	getline(iss, str, ',');
	label * foundLabel = createdLabels[labelname];
	if (foundLabel == NULL) {
		cerr << "No label Found" << endl;
		exit(1);
	}
	if (str[0] == '$') {
		cout << str << endl;
		NUMERIC * obj = createdNUMERICS[str];
		if (obj == NULL) {
			cerr << "Variable does not exist" << endl;
			exit(1);
		}
		else {
			int i = obj->VALUE;
			if (i == 0) {
				counter = foundLabel->linenumber;
			}
		}
	}
	else {
		cout << str << endl;
		int i = stoi(str);
		if (i == 0) {
			counter = foundLabel->linenumber;
		}
	}
}