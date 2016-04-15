#ifndef __MY_STRING_H__
#define	__MY_STRING_H__

#include <string.h>
#include <assert.h>
#include <stdio.h>

typedef unsigned int uint;

class p2String {
private:
	char* string;

public:
	uint capacity;

	p2String(unsigned int mem);
	p2String(char* c_str1);
	p2String(p2String &str);
	virtual ~p2String();

public:
	int size();
	const int length();
	bool empty() const;
	void clear();
	char* c_str();
	int GetnArgs();

	bool p2String::operator==(const char* c_str) const {
		return strcmp(this->string, c_str) == 0;
	}

	bool p2String::operator==(const p2String& str) const {
		return strcmp(this->string, str.string) == 0;
	}

	const p2String& p2String::operator=(const p2String& str) {
		if (this->capacity != str.capacity) {
			if (string != nullptr)
				delete[] this->string;

			capacity = strlen(str.string) + 1;
			string = new char[capacity];
		}
		strcpy_s(string, str.capacity, str.string);
		return *this;
	}

	const p2String& p2String::operator=(const char* c_str) {
		if (this->capacity != strlen(c_str) + 1) {
			if (string != nullptr)
				delete[] this->string;

			capacity = strlen(c_str) + 1;
			string = new char[capacity];
		}
		strcpy_s(string, capacity, c_str);
		return *this;
	}

	p2String GetChoosenArg(int n_arg) {
		p2String ret(capacity);
		uint i = 0;
		uint k = 0;
		uint n_ch = 0;
		n_arg--;
		if (n_arg < 1) {
			for (n_ch = 0; string[n_ch] != ' ' && string[n_ch] != '\0'; n_ch++) {
				ret.string[n_ch] = string[n_ch];
			}
			ret.string[n_ch] = '\0';
		}

		else {
			while (i < strlen(string) && n_arg > 0) {
				if (string[i] == ' ')
					n_arg--;
				i++;
			}

			while (string[i] != '\0' && string[i] != ' ' && i < capacity) {
				ret.string[k] = string[i];
				i++;
				k++;
			}
			ret.string[k + 1] = '\0';
		}


		return ret;
	}

	const char& p2String::operator[](uint index){
		assert(index < capacity);
		return string[index];
	}


};

#endif