#include <cstdio>

struct Battery
{
	static int current_battery_level;

	static void get_current_battery_level()
	{
		printf("The Current Battery Level Is:%d\n", current_battery_level);
	}

	static void charge(int charge_upto)
	{
		current_battery_level = current_battery_level + charge_upto;

		if (current_battery_level > 100)
		{
			printf("Warning! Battery is overcharged.\n");
			current_battery_level = 100;
		}
		get_current_battery_level();
	}

	static void drain(int drain_upto)
	{
		current_battery_level = current_battery_level - drain_upto;

		if (current_battery_level < 1)
		{
			printf("Warning! Battery is out of power.\n");
			current_battery_level = 0;
		}
		get_current_battery_level();
	}
};

int Battery::current_battery_level = 70;

int main()
{
	Battery::charge(40);
	Battery::drain(101);
	return 0;
}