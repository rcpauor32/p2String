#include <stdio.h>
#include "my_string.h"

int main() {
	String s1 = "hello";
	String s2 = s1;
	String s3 = "world hola";

	//s3 += s1;
	
	printf("%s\n%s\n%d", s1.c_str(), s2.c_str(), s3.GetnArgs());

	getchar();
	return 0;
}