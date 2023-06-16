#include <cstdio>

enum class Operation
{
	Add,
	Subtract,
	Multiply,
	Divide
};

struct Calculator
{
	Calculator(Operation operation)
	{
		to_perform = operation;
	}

	int calculate(int a, int b)
	{
		int ans;
		switch (to_perform)
		{
		
		case (Operation::Add): ans = a+b;
			break;
		
		case (Operation::Subtract): ans = a-b;
			break;
		
		case (Operation::Multiply): ans = a*b;
			break;
		
		case (Operation::Divide): ans = a/b;
			break;
		}

		return ans;
	}

private:
	Operation to_perform;
};

int main()
{
	Operation my = Operation::Add;
	Calculator calc{Operation::Add};
	printf("Answer is:%d", calc.calculate(20, 20));
}