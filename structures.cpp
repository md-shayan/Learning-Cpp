#include <cstdio>

struct Car
{
	char brand[15];
	char model[10];
	char color[10];
	unsigned year;
	unsigned price;
	bool used;
};

int main()
{
	Car tesla{"Tesla", "Model S", "Red", 2022, 80000}; // the used is automatically evaluated to zero.
	if (tesla.used) printf("The Car Is A Used %s Coloured %s %s Manufactured In The Year %d At A Cost Of $%d", tesla.color, tesla.brand, tesla.model, tesla.year, tesla.price);
	else printf("The Car Is A %s Coloured %s %s Manufactured In The Year %d At A Cost Of $%d", tesla.color, tesla.brand, tesla.model, tesla.year, tesla.price);
}