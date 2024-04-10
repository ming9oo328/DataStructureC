#include <stdio.h>
#include <stdbool.h>
#define max(a,b) ((a>b)? a:b) // 두 polynomial 중 degree가 더 큰 것 판단
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
			printf("%3.2lfx^%d", p.coef[i], i);
		}
		if (p.coef[i - 1] > 0) {
			printf("+");
		}
	}
	if (p.coef[0] != 0) {
		printf("%3.2lf", p.coef[0]);
	}
	printf("\n");
}

poly add_polys(poly a, poly b){
	int i;
	int maxdegree = max(a.degree, b.degree);
	poly c;
	c.degree = maxdegree;

	for (i = 0; i < maxdegree; i++) {
		c.coef[i] = a.coef[i] + b.coef[i];
	}
	return c;
}

bool isIn(int *a, int data) {
	int i;
	for (i = 0; i < sizeof(a); i++) {
		if (a[i] == data) {
			return true;
		}
	}
	return false;
}

poly multiple_polys(poly a, poly b) {
	int i,j;
	poly d;
	d.degree = a.degree + b.degree-1;
	int check[101];

	for (i = 0; i < a.degree; i++) {
		for (j = 0; j < b.degree; j++) {
			int expo = i + j;
			if (isIn(check, expo)) {
				d.coef[expo] += a.coef[i] * b.coef[j];
			}
			else {
				check[expo] = expo;
				d.coef[expo] = a.coef[i] * b.coef[j];
			}
		}
	}

	return d;
}

int main() {
	poly a = { 5, {3, 4, 0, 6, 7} };
	printf("%20s", "polynomial a : ");
	print_poly(a);

	poly b = { 6, {-3, 4, 3, -6, 7, 1} };
	printf("%20s", "polynomial b : ");
	print_poly(b);

	poly c = add_polys(a, b);
	printf("%20s", "sum of a, b : ");
	print_poly(c);

	poly d = multiple_polys(a, b);
	printf("%20s", "multi of a, b : ");
	print_poly(d);

	return 0;
}