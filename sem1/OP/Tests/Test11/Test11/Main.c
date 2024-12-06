#include <stdio.h>
#include <string.h>
#define N 100
char str[N];
char a = 1;
char res[N];

int main() {

	gets(str);
	for (int i = 0; i < N;i++) {
		if (str[i] == '\0') {

			break;

		}
		for ( ; a < 128; a++) {
			res[i] = a;
			if (a == str[i]) {

				a = 1;
				break;

			}

		}
		printf("%s\n", res);

	}



}


