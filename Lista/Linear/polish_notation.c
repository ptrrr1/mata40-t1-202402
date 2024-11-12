#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	int s = 0; int l = 0; 
	char eq[100], symb[100], lttr[100];
	scanf("%s", eq);

	for (int i = 0; i < strlen(eq); i++) {
		if (eq[i] == ')') {
			s--;
			lttr[l] = symb[s];
			l++;
		} else if (
			eq[i] == '+' || 
			eq[i] == '-' || 
			eq[i] == '*' || 
			eq[i] == '/') {
			symb[s] = eq[i];
			s++;
		} else if (eq[i] != '(') {
			lttr[l] = eq[i];
			l++;
		}
	}

	printf("%s\n", eq);
	printf("%s\n", lttr);

	return 0;
}