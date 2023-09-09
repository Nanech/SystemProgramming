#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

// Task 1

struct liner_equation {
	float x;
	float y;	
}; typedef struct liner_equation linEq;

float quadratic_equation(float x);
linEq* system_of_2_liner_equations();
unsigned int factorial(unsigned int n);
void wrapper_of_choice(unsigned short int* n);
void choice();