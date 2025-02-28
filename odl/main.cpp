#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LENGTH 30
#define LL 40
#define LLa LL + 1
int d1();/*d for Determinant, number for order*/
int d2();
int d3();
int d4();
int cal();/*regular calculate*/
int inv();/*invertion*/
int lon();
int main() {
	int dp, e = 1;/*dp=display, e=exit*/
	char com;/*com=command*/
	printf("Detcom [version 1.2.1.32]\n");
	printf("(c)harukaworks.link all rights reserved.\n\n");
	while (e == 1) {
		printf("> ");
		scanf("%c", &com);
		if(com!='\n')
		switch (com) {/*determine order of the determinant*/
		case 49:/*command '1' for 1-order-det*/
			dp = d1();
			printf("\n%d\n\n", dp);
			break;
		case 50:/*command '2' for 2-order-det*/
			dp = d2();
			printf("\n%d\n\n", dp);
			break;
		case 51:/*command '3' for 3-order-det*/
			dp = d3();
			printf("\n%d\n\n", dp);
			break;
		case 52:/*command '4' for 4-order-det*/
			dp = d4();
			printf("\n%d\n\n", dp);
			break;
		case 63:/*command '?' for help*/
			printf("num ----/Insert num-order-Det.\n");
			printf("e   ----/Exit.\n");
			printf("c   ----/Clear screen.\n");
			printf("f   ----/Regular calculate.\n");
			printf("i   ----/Inversions.\n");
			printf("?   ----/help.\n");
			printf("!You may incert in either UPPER CASE or lower case.\n");
			printf("-'f' help for calculate mode\n");
			printf("+ num1 method num2\n");
			printf("+- method\n");
			printf(" + '+'----/Plus.\n");
			printf(" + '-'----/Minus.\n");
			printf(" + '*'----/Times.\n");
			printf(" + '/'----/Divide by.\n");
			printf(" + '^'----/Powers.\n");
			break;
		case 67:/*command 'C' for clear screen*/
			system("cls");
			break;
		case 69:/*command 'E' for exit*/
			e = 0;
			break;
		case 70:/*command 'F' for calculate*/
			dp = cal();
			printf("Calculate mode disabled.\n");
			break;
		case 73:/*command 'I' for inversions*/
			dp = inv();
			printf("\n%d\n\n", dp);
			break;
		case 76:
			dp = lon();
			break;
		case 99:/*command 'c' for clear screen*/
			system("cls");
			break;
		case 101:/*command 'e' for exit*/
			e = 0;
			break;
		case 102:/*command 'f' for calculate*/
			dp = cal();
			printf("Calculate mode disabled.\n");
			break;
		case 105:/*command 'i' for inversions*/
			dp = inv();
			printf("\n%d\n\n", dp);
			break;
		case 108:
			dp = lon();
			break;
		default:
			printf("\b\b");
			break;
		}
	}
	return 0;
}
int d1() {
	int q;
	printf("You are calculating a 1-order-Det.\n");
	printf("Insert your first line.\n");
	printf("> ");
	scanf("%d", &q);
	return q;
}
int d2() {
	int a1, b1, a2, b2, q;
	printf("You are calculating a 2-order-Det.\n");
	printf("Insert your first line.\n");
	printf("> ");
	scanf("%d %d", &a1, &b1);
	printf("Insert your second line.\n");
	printf("> ");
	scanf("%d %d", &a2, &b2);
	q = a1 * b2 - a2 * b1;
	return q;
}
int d3() {
	int a1, b1, c1, a2, b2, c2, a3, b3, c3, q;
	printf("You are calculating a 3-order-Det.\n");
	printf("Insert your first line.\n");
	printf("> ");
	scanf("%d %d %d", &a1, &b1, &c1);
	printf("Insert your second line.\n");
	printf("> ");
	scanf("%d %d %d", &a2, &b2, &c2);
	printf("Insert your third line.\n");
	printf("> ");
	scanf("%d %d %d", &a3, &b3, &c3);
	q = a1 * b2 * c3 + a2 * b3 * c1 + a3 * b1 * c2 - a1 * b3 * c2 - a2 * b1 * c3 - a3 * b2 * c1;
	return q;
}
int d4() {
	int a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3, a4, b4, c4, d4, q;
	printf("You are calculating a 4-order-Det.\n");
	printf("Insert your first line.\n");
	printf("> ");
	scanf("%d %d %d %d", &a1, &b1, &c1, &d1);
	printf("Insert your second line.\n");
	printf("> ");
	scanf("%d %d %d %d", &a2, &b2, &c2, &d2);
	printf("Insert your third line.\n");
	printf("> ");
	scanf("%d %d %d %d", &a3, &b3, &c3, &d3);
	printf("Insert your fourth line.\n");
	printf("> ");
	scanf("%d %d %d %d", &a4, &b4, &c4, &d4);
	q = a1 * (b2 * c3 * d4 + c2 * d3 * b4 + d2 * b3 * c4 - d2 * c3 * b4 - c2 * b3 * d4 - b2 * d3 * c4) - a2 * (b1 * c3 * d4 + c1 * d3 * b4 + d1 * b3 * c4 - d1 * c3 * b4 - c1 * b3 * d4 - b1 * d3 * c4) + a3 * (b1 * c2 * d4 + c1 * d2 * b4 + d1 * b2 * c4 - d1 * c2 * b4 - c1 * b2 * d4 - b1 * d2 * c4) - a4 * (b1 * c2 * d3 + c1 * d2 * b3 + d1 * b2 * c3 - d1 * c2 * b3 - c1 * b2 * d3 - b1 * d2 * c3);
	return q;
}
int cal() /*regular calculate*/ {
	double f1, f2, db2;
	char me;
	printf("Calculate mode enabled.\n");
	while (1) {
		printf("Cal> ");
		scanf("%lf %c %lf", &f1, &me, &f2);
		switch (me) {
		case 42:
			db2 = f1 * f2;
			printf("\n%lf\n\n", db2);
			break;
		case 43:
			db2 = f1 + f2;
			printf("\n%lf\n\n", db2);
			break;
		case 45:
			db2 = f1 - f2;
			printf("\n%lf\n\n", db2);
			break;
		case 47:
			db2 = f1 / f2;
			printf("\n%lf\n\n", db2);
			break;
		case 94:
			db2 = pow(f1, f2);
			printf("\n%lf\n\n", db2);
			break;
		default:
			return 0;
		}
	}
	return 0;
}
int inv() /*invertion*/ {
	scanf("%*c");
	char in[LENGTH],ch;
	int q = 0, k = 0;
	printf("INV> ");
	while (scanf("%c", &ch) && ch != '\n') {
		in[k++] = ch;
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (in[i] > in[j])
				q++;
		}
	}
	return q;
}
int lon() {
	scanf("%*c");
	int ch[40] = { 0 }, ar[40] = { 0 }, cr[41] = { 0 }, i = 0, j = 0, a = 40, k, m;
	char ca, cb;
	printf("> ");
	while (scanf("%c", &ca) && ca != '\n')
		ch[i++] = ca - 48;
	printf("> ");
	while (scanf("%c", &cb) && cb != '\n')
		ar[j++] = cb - 48;
	for (; i > 0 && j > 0; i--, j--) {
		k = cr[a] + ch[i - 1] + ar[j - 1];
		cr[a] = k;
		while (cr[a] > 9) {
			cr[a] = cr[a] - 10;
			cr[a - 1] = cr[a - 1] + 1;
		}
		a--;
	}
	for (; i != 0; i--)
		cr[a] = cr[a] + ch[i - 1];
	for (; j != 0; j--)
		cr[a] = cr[a] + ar[j - 1];
	printf("\n");
	for (m = 0; m < 41; m++) {
		if (cr[m] != 0) {
			printf("%d", cr[m]);
			break;
		}
	}
	for (m = m + 1; m < 41; m++)
		printf("%d", cr[m]);
	printf("\n\n");
	return 0;
}