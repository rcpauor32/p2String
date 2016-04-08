#include <stdio.h>
#include "my_string.h"

int main() {
	String s1 = "hello";
	String s2 = s1;
	String s3 = "world";

	//s3 += s1;
	
	printf("%s\n%s\n%s", s1.c_str(), s2.c_str(), s3.c_str());

	getchar();
	return 0;
}