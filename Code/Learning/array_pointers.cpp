#include <cstdio>
#include <cstddef>

struct Smartphones
{
	char name[256];
};

void print_details(Smartphones* ptr_to_smartphone, size_t no_of_phones)
{
	for (int i=0; i<no_of_phones; i++)
	{
		printf("Name:%s\n", (ptr_to_smartphone[i]).name);
	}
}

int main()
{
	Smartphones Phones[]{"iPhone X", "iPhone 11", "iPhone 12", "iPhone 13", "iPhone 14"};
	size_t size_of_Phones = sizeof(Phones) / sizeof(Smartphones);
	Smartphones* ptr_to_Phone1 = Phones; // this now points to the first element of the Phones array.
	print_details(ptr_to_Phone1, size_of_Phones);
	return 0;
}