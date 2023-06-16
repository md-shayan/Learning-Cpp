#include <cstdio>
#include <cstddef>

int main()
{
	size_t char_ = sizeof(char);
	printf("size of char in bytes:%zd\n", char_);

	size_t uchar_ = sizeof(unsigned char);
	printf("size of unsigned char in bytes:%zd\n", uchar_);

	size_t short_ = sizeof(short);
	printf("size of short in bytes:%zd\n", short_);

	size_t ushort_ = sizeof(unsigned short);
	printf("size of unsigned short in bytes:%zd\n", ushort_);

	size_t int_ = sizeof(int);
	printf("size of int in bytes:%zd\n", int_);

	size_t uint_ = sizeof(unsigned int);
	printf("size of unsigned int in bytes:%zd\n", uint_);

	size_t long_ = sizeof(long);
	printf("size of long in bytes:%zd\n", long_);

	size_t ulong_ = sizeof(unsigned long);
	printf("size of unsigned long in bytes:%zd\n", ulong_);

	size_t long_long_  = sizeof(long long);
	printf("size of long long in bytes:%zd\n", long_long_);

	size_t ulong_long_  = sizeof(unsigned long long);
	printf("size of unsigned long long in bytes:%zd\n", ulong_long_);

	return 0;
}