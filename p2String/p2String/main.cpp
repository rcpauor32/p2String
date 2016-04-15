#include <stdio.h>
#include "my_string.h"

int main() {
	p2String s1 = "hello";
	p2String s2 = s1;
	p2String s3 = "world hola";

	//s3 += s1;
	p2String str = "world";
	p2String str1 = s3.GetChoosenArg(1);

	if (s3.GetChoosenArg(1) == "world") {
		printf("\ntesting");
	}

	printf("\n%s\n%s\n%s\n%d", s1.c_str(), s2.c_str(), s3.GetChoosenArg(1), strlen(str.c_str()));

	getchar();
	return 0;
}