#include <cstdio>
#include <cstring>
#include <cstddef>

int main()
{
	char str[]{"Shayan"};
	char* ptr_to_str = str;
	size_t length = strlen(ptr_to_str);
	printf("%d", length);
	return 0;
}