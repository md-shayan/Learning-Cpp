#include <cstdio>

struct Age
{

	void age_error()
	{
		printf("Age Error: Year Of Birth Must Be Less Than Current Year");
	}

	int get_age()
	{
		return current_year - year_of_birth;
	}

	void set_year_of_birth(int set_to)
	{
		if (set_to>current_year)
		{
			age_error();
		}
		
		else
		{
		year_of_birth = set_to;
		}
	}
private:
	int year_of_birth;
	int current_year{2023};
};

int main()
{
	Age self;
	Age other;
	self.set_year_of_birth(2006);
	printf("My current age is %d", self.get_age());
	other.set_year_of_birth(2024); // Calls the age_error() function.
	printf("The Current Year Is %d", self.current_year); // Throws error as current_year is private.
}