#include "my_string.h"
#include <assert.h>

p2String::p2String(unsigned int mem) {
		string = new char[mem + 1];
		string[mem] = '\0';
}

p2String::p2String(char* c_str) {
	assert(c_str != nullptr);
	this->capacity = strlen(c_str) + 1;
	this->string = new char[capacity];
	strcpy_s(this->string, capacity, c_str);
}

p2String::p2String(p2String& str){
	assert(str.string != nullptr);
	capacity = strlen(str.string) + 1;
	string = new char[capacity];
	strcpy_s(this->string, capacity, str.string);
}

int p2String::size() {
	return sizeof(string) / sizeof(string[0]);
}

const int p2String::length() {
	return strlen(this->string);
}

bool p2String::empty() const {
	return string[0] == '\0';
}

void p2String::clear() {
	delete[] string;
}

char* p2String::c_str() {
	return string;
}

p2String::~p2String() {
	delete[] string;
};

int p2String::GetnArgs() {
	int n_args = 1;
	while (*(string++) == ' ');
	for (int i = 0; i < strlen(string); i++){
		if (string[i] == ' ')
			n_args++;
	}

	return n_args;
}
