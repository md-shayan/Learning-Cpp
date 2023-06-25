#include <cstdio>
#include <stdexcept>
#include <cstring>
#include <cstddef>

struct String
{
	String(size_t max_size) : max_size{max_size}, length{}
	{
		if (max_size == 0)
		{
			throw std::runtime_error{"max_size cannot be negative"};
		}

		buffer = new char[max_size];
		buffer[0] = 0;
	}

	void print(const char* tag) const
	{
		printf("%s: %s", tag, buffer);
	}

	bool append_line(const char* x)
	{
		const auto x_len = strlen(x);

		if (x_len + length + 2 > max_size) return false;
		std::strncpy(buffer + length, x, max_size - length);
		length += x_len;
		buffer[length++] = '\n';
		buffer[length] = 0;
		return true;
	}

	~String()
	{
		delete[] buffer;
	}

private:
	size_t max_size;
	char* buffer;
	size_t length;
};

struct NewString
{
	NewString(const char* x) : string{10}
	{
		if (!string.append_line(x))
		{
			throw std::runtime_error{"Not enough memory!"};
		}
		string.print("Constructed	");
	}

	~NewString()
	{
		string.print("About To Destroy");
	}

private:
	String string;
};

void fn_a()
{
	NewString a{"aaaaaaaaa"};
}

void fn_b()
{
	NewString b{"b"};
	fn_a();
}

int main()
{
	try
	{
		NewString c{"c"};
		fn_b();
		NewString d{"d"};
	}

	catch (std::exception& e)
	{
		printf("Exception: %s\n", e.what());
	}
}