#include <cstdio>

enum class Languages
{
	Python,
	Java,
	CPP,
	C_Sharp,
	Javascript
};

int main()
{	
	Languages current = Languages::CPP;

	switch (current)
	{

	case (Languages::Python):
		{
			printf("You are learning python");
		}
		break;

	case(Languages::Java):
		{
			printf("You are learning java");
		}
		break;

	case (Languages::CPP):
		{
			printf("You are learning C++");
		}
		break;

	case (Languages::C_Sharp):
		{
			printf("You are learning C#");
		}
		break;

	case (Languages::Javascript):
		{
			printf("You are learning javascript");
		}
		break;

	default: 
		{
			printf("I do not know this language");
		}
	}
}