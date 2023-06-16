#include <cstdio>

class Age
{
	int current_year{2023};
	int year_of_birth;
	void age_error()
	{
		printf("\nAge Error: Year Of Birth Must Be Less Than Current Year.");
	}

public:
	void set_year_of_birth(int set_to)
	{
		if (set_to > current_year)
		{
			age_error();
		}

		else
		{
		year_of_birth = set_to;
		}
	}

	int get_age()
	{
		return current_year - year_of_birth;
	}
};

int main()
{
	Age self;
	Age other;
	self.set_year_of_birth(2006);
	printf("My current age is %d", self.get_age());
	other.set_year_of_birth(2024); // Calls age_error()

}