#include <stdio.h>
/*
string = "I love India"
*/

char* split(char *input, int len, char delimiter) {
	static int start_index = 0;
	int temp_start = start_index;
	int end_index;
	char *token;

	while (temp_start < len) {
		if (input[temp_start] == delimiter) {
			end_index = temp_start;
			break;
		}
		temp_start++;
	}

	if (temp_start == len) {
		end_index = len - 1;
	}

	int token_size = end_index - start_index + 1;
	token = malloc(token_size * sizeof(char));

	int it = start_index;
	int temp = 0;
	while (it < end_index && it < len) {
		token[temp++] = input[it];
		it++;
	}

	token[it+1] = '\0';

	start_index = end_index + 1;


	return token;
}
int main(void) {
	char str[] = "I love India";
	char delimit = ' ';
	int len = sizeof(str)/sizeof(char);
	printf("%s\n", str);

	char *ptr1 = split(str, len, delimit);
	printf("%s\n", ptr1);

	char *ptr2 = split(str, len, delimit);
	printf("%s\n", ptr2);

	char *ptr3 = split(str, len, delimit);
	printf("%s\n", ptr3);

	return 0;
}
