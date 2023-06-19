/*
* After Declaring a pointer pointing to an Object, Use the -> symbol to dereference its methods, variables etc. 
*/
#include <cstdio>

struct Year
{
	int year;
};

int main()
{
	Year newYear;
	Year *ptr_to_newYear = &newYear;
	ptr_to_newYear->year = 2023; // This pointer now changes the value of year variable to 2023.
	printf("Address of newYear: %p\n", ptr_to_newYear);
	printf("Value of newYear: %d\n", ptr_to_newYear->year);
	printf("Value of newYear: %d", (*ptr_to_newYear).year); // Alternatively just use this to get year.
	return 0;
}