#include <cstdio>

struct Year
{
	void setYear(int toYear) {
		year = toYear;
	}
	int getYear() {
		return year;
	}

private:
	int year;
};

void addYear(Year& someYear)
{
	someYear.setYear(someYear.getYear()+1);
}

int main()
{
	Year newYear = Year();
	newYear.setYear(2023);
	printf("The Year Is:%d\n", newYear.getYear());
	addYear(newYear); // The instance is passed as a reference.
	printf("The Year Is:%d", newYear.getYear());
	return 0;
}