#include <cstdio>

struct Date
{
	Date(char* theDate)
	{
		for (int i=0; i<11; i++)
		{
			date[i] = theDate[i];
		}
	}

	void getDate()
	{
		printf("%s", date);
	}

	void setDate(const char* newDate)
	{
		for (int i=0; i<11; i++)
		{
			date[i] = newDate[i];
		}
		newDate[0] = "K"; // Shows error as 'newDate' is read only.
	}
private:
	char date[11];	
};

int main()
{
	char date[]{"21-06-2023"};
	char* ptr_to_date = date;
	Date today{ptr_to_date};
	today.getDate();

	char newDate[]{"20-06-2023"};
	today.setDate(&newDate[0]);
	today.getDate();

	return 0;
}