/*******************************************************************************
 Name: Michael Dimmitt
 Student ID: n00841838
 Course: COP 2220
 Date: 2/10/2016

/*****************************************************************
The program will decompose an input number into its component values:
1’s, 10’s, 100’s, 1,000’s and 10,000’s.

example output:
"You have entered: 99999

 10,000’s: 	9
 1,000’s:  	9
 100’s:  	9
 10’s: 		9
 1’s: 		9"

******************************************************************/
//creative bit: 
//instead of manually setting starting value in each function 
//and calling the functions individually
//use of log to deconstruct users input
//cast float into int for next equation.
//and then use of exponents to construct starting value.
//allows automation to resolve variables
//now the program can run using a while loop.

#include <stdio.h>
#include <locale.h> //imported to deliminate thousands place values when an int is presented as a string.
#include <math.h> //allow use of logarithm and exponent functions.

int getInput(void); //returns x 
void func(int* x, int * startingValue, int* num);
void display(*startingValue, *num);
void decStart(int* startingValue);

int main() {
setlocale(LC_NUMERIC, "");//usedd to deliminate thousands values.
//declare pointers below.
int* startingValue;
int* x;	//will be input.
int* num;//will be number printed out.
//declare values to be assigned to pointers.
int s;//startingValue holder.								potentially assigned to pointer startingValue.
int b = 1;//baseStarting Value if... input was 0; //says val == 0 at placeholder 1.	potentially assigned to pointer startingValue.
int p = getInput();//an integer that is positive and less thaan 100,0000		later assigned to pointer x. //which is input.
	if (p == -1) {//how to break program if invalid input (not positive).
		return 0;
	} 
	if (p == 0) {//what future of program needs if input is 0.
		startingValue = &b;
	}
	else {//call function.. pass value. //return startingValue for deconstructing number.
	int z; //zero placeholder understood by log base 10 equation.			//for later constructing startingValue.
	float t; //temp used for constructing starting value. for deconstructing number.
	
	z = log(p) / log(10);	//figure out zero place holder of assignment.
	
	t = pow(10, z);         //using float value keeps it from rounding.
	s = (int) t;            //figure out starting value. for deconstructing number.
	
	startingValue = &s; 	//assign starting value for deconstructing number.
	}
	
	int n;//prepare value to assign to pointer. num.
	//two assignments below are done to pass pointer to function func().
	num = &n; //assign num value 1.
	x = &p;//assign x value of the positive accepted number. or zero.

	while (*startingValue != 1) {//for values greater than 9. within ... appropriate index.
		func(x, startingValue, num); //num/10,000		potentially... or 1,000 or 100 or 10 
		display(*startingValue, *num);
		decStart(startingValue);
	}
	func(x, startingValue, num); //num/10
	display(*startingValue, *num);
	return 0;
}

int getInput(void) {
	int x;
	printf("please enter an integer that is positive and less than 100,000\n");
	scanf("%d", &x);
	if (x < 0 || x > 100000) {//1215752193 //|| x > 100000
		printf("invalid number entered\n");
		return -1;
	}
	return x;

}
void display(int startingValue,int num)
   {
   char str[20];
	char str2[20];
	sprintf(str, "%'d", startingValue); //%-6d    //this +2down func.. pass num pass start
	sprintf(str2, "%s's:", str);
	printf("%-10s%d\n", str2, num);
   }
void decStart(int* startingValue) {
	int s = *startingValue;
	*startingValue = s / 10;
	return;
}
void func(int* x, int* startingValue, int* num) {
	int v = *x;
	int s = *startingValue;
	*num = v / s;
	*x = v % s;
	return;
}
