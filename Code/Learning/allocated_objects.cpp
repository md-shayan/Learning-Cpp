#include <cstdio>

int main()
{
	char* name = new char[]{"Shayan"};
	printf("%s", name);
	delete name;
	printf("%s", name); // Even after deallocating name, it is still not cleaned from the memory. 
	return 0;
}