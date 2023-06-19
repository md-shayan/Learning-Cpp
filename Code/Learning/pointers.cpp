#include <cstdio>

int main()
{
	int myVar = 0;
	int *ptr_to_myVar = &myVar;
	*ptr_to_myVar = 17325; // This changes the data to 17325 at the memory address stored in ptr_to_myVar.
	printf("Address Of myVar:%p", ptr_to_myVar); // Memory address where myVar is stored.
	printf("\nValue of myVar:%d", *ptr_to_myVar); // Data stored at the memory address where the pointer is pointing to.
	return 0;
}