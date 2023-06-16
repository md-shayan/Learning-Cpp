#include <cstdio>

int main()
{
	short x1; //Can hold between -32,768 to 32,767 (2 bytes in size); %hd
	unsigned x2; //Can hold between 0 to 65,535 (2 bytes in size); %hu
	int x3; //Can hold between -2,147,483,648 to 2,147,483,647 (4 bytes in size); %d
	unsigned int x4; //Can hold between 0 to 4,294,967,295 (4 bytes in size); %u
	long x5; //Can hold between -2,147,483,648 to 2,147,483,647 (4 bytes in size); %ld
	unsigned long x6; //Can hold between 0 to 4,294,967,295 (4 bytes in size); %lu
	long long x7; //Can hold betwenn -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (8 bytes in size); %lld
	unsigned long long x8; //Can hold between 0 to 18,446,744,073,709,551,615 (8 bytes in size); %llu
	return 0;
}