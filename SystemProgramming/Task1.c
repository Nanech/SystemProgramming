#include "Header.h"

float quadratic_equation(float x) {
	// a*x^2+b*x+c 
	printf_s("\nenter values of a, b, c\nthe format is \"20 14 15\" only numbers, and you get a = 10, b = 14, c = 15\nremember the 14,6 writes like 14.6\n\n");
	float a, b, c;
	int counter = scanf("%f %f %f", &a, &b, &c);
	if (a == 0.0) {
		printf("the a value could`t be a zero");
		return 0;
	} 
	return a * pow(x, 2.0) + b * x + c;
}

linEq* system_of_2_liner_equations() {
	// there Kramer method
	float x1 = 3, x2 = 5, y1 = -2, y2 = 4, b1 = 6, b2 = 32;
	linEq* le = calloc(1, sizeof(linEq));
	printf_s("\nenter the following items in strict order: x1, y1, b1, x2, y2, b2\n\n ");
	int counter = scanf_s("%f %f %f %f %f %f", &x1, &y1, &b1, &x2, &y2, &b2);
	getchar();
	le[0].x = (b1 * y2 - b2 * y1) / (x1 * y2 - y1 * x2);
	le[0].y = (x1 * b2 - x2 * b1) / (x1 * y2 - y1 * x2);
	return le;
}

unsigned int factorial(unsigned int n) {
	if (n == 0) { return 1; }
	return n * factorial(n - 1);
}


void wrapper_of_choice(unsigned short int* n) {
	float x;
	unsigned int f;
	linEq* le;
	switch (*n)
	{
	case 1:
		printf_s("\nwrite the x: ");
		scanf_s("%f", &x);
		getchar();
		printf_s("\nYour answer %f", quadratic_equation(x));
		break;
	case 2:
		le = system_of_2_liner_equations();
		printf_s("\nx = %f, and y = %f", le->x, le->y);
		break;
	case 3:
		printf_s("\nwrite the number of elements: ");
		scanf_s("%u", &f);
		printf_s("\nthe number of the permutation is %hu", factorial(f));
		break;

	default:
		printf_s("something went wrong\n");
		break;
	}
	*n = 0;
}


void choice() {
	printf_s("\t\tThere is only a number at the input. If you write not the number program is exits.\n\n");
	printf_s("First task is quadratic_equation\nSecond task is system of 2 liner equations\nThird task is permutation of the elements\n\n");
	while (1) {
		unsigned short choice;
		printf("enter your task or something: ");
		scanf_s("%hu", &choice);
		getchar();
		if (choice == 1 || choice == 2 || choice == 3)
		{
			wrapper_of_choice(&choice);
			printf_s("\n\nprogram is over. you could select next task or exit\n\n");
		}
		else { break; }
	}
}