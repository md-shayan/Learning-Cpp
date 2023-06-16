#include <cstdio>

struct Date
{
	Date(int current_day, int current_month, int current_year)
	{
		if (current_day > 31) DayError();
		else if (current_month > 12) MonthError();
		else if (current_year > 2023) YearError();
		else
		{
			day = current_day;
			month = current_month;
			year = current_year;
		}
	}

	void setDate(int new_day, int new_month, int new_year)
	{
		if (new_day > 31) DayError();
		else if (new_month > 12) MonthError();
		else if (new_year > 2023) YearError();
		else
		{
		day = new_day;
		month = new_month;
		year = new_year;
		}
	}

	int getDay()
	{
		return day;
	}

	int getMonth()
	{
		return month;
	}

	int getYear()
	{
		return year;
	}

	void getDate()
	{
		printf("%d-%d-%d", day, month, year);
	}

private:
	int day;
	int month;
	int year;

	void DayError()
	{
		printf("Day must be less than 31");
	}

	void MonthError()
	{
		printf("Month must be less than 12");
	}

	void YearError()
	{
		printf("Year must be less than 2023");
	}
};

int main()
{
	Date today{16, 6, 2023};
	printf("Today is ");
	today.getDate();
}