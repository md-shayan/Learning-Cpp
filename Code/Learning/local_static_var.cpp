#include <cstdio>

void charge(int upto) // object's % of battery charged
{
	static int battery = 70;
	battery = battery + upto;
	if (battery>100)
	{
		printf("Warning! Battery is overcharged.\n");
		battery=100;
	}
	printf("Current Battery Level:%d%\n", battery);
}

void drain(int upto) // object's % of battery drained
{
	static int battery = 70;
	battery = battery - upto;
	if (battery<1)
	{
		printf("Warning! Out of power\n");
		battery=0;
	}
	printf("Current Battery Level:%d%\n", battery);
}

int main()
{
	charge(31);
	drain(109);
	return 0;
}