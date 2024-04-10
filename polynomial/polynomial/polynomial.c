#include <stdio.h>

#define MAX_DEGREE 101 // max degree of polynomial+1

typedef struct{
	int degree;
	float coef[MAX_DEGREE];
}poly;

void print_poly(poly p) {
	int i;
	int expo = p.degree - 1;
	for (i = expo; i > 0; i--) {
		if (p.coef[i] != 0) {
			printf("%3.2lfx^%d + ", p.coef[i], i);
		}
	}
	if (p.coef[0] != 0) {
		printf("%3.2lf\n", p.coef[0]);
	}
}

int main() {
	poly a = { 5, {3, 4, 0, 6, 7} };
	print_poly(a);

	return 0;
}