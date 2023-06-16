#include <cstdio>

union Variable
{
	char string[11];
	int integer;
	float decimal;
	bool boolearn;
};

int main()
{
	Variable n;
	n.decimal = 3.14159;
	printf("The Variable Decimal Is %f", n.decimal);
	n.integer = 100;
	printf("\nThe Variable Integer Is %d", n.integer);
	/*
	* This does not give us the earlier value of n.decimal as the union Variable can hold any of the four types
	* but only one a time after we put n.integer = 100, the n.decimal is removed from the memory location of
	* Variable.
	*/
	printf("\nThe Variable Decimal Is %f", n.decimal);
}