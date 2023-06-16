#include <cstdio>

int main()
{
	char cap_alphabets[26];
	char small_alphabets[27];
	for (int i=0; i<26; i++)
	{
		cap_alphabets[i] = i + 65;
		small_alphabets[i] = i + 97;
	}
	small_alphabets[26] = 0;
	printf("The Capital Alphabets Are:\n%s", cap_alphabets);
	printf("\nThe Small Alphabets Are:\n%s", small_alphabets);
}