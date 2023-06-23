#include <cstdio>

struct YearOfBirth
{
	YearOfBirth(unsigned short yob)
	{
		this->year = yob;
	}

	unsigned short getYear()
	{
		return year;
	}

	bool setYear(unsigned short setTo)
	{
		if (setTo > year)
		{
			return false;
		}

		else
		{
			this->year = setTo;
			return true;
		}
	}

private:
	unsigned short year;
};

struct Year
{
	Year(unsigned short current_year)
	{
		this->year = current_year;
	}

	unsigned short getYear()
	{
		return year;
	}

	bool setYear(int setTo)
	{
		if (setTo < year)
			{
				this->year = setTo;
				return true;
			}
		else
			{
				return false;
			}
	}

private:
	unsigned short year;
};

int main()
{
	Year newYear(2023);
	newYear.setYear(2022);
	YearOfBirth myYOB(2020);
	myYOB.setYear(2019);
	printf("The year is:%d", newYear.getYear());
	return 0;
}