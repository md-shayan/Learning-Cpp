#include <cstdio>

struct ConsoleLogger {
	void logTransfer(long from, long to, double amount) {
		printf("%ld -> %ld: %f\n", from, to, amount);
	}
};

struct Bank {
	void makeTransfer(long from, long to, double amount) {
		logger.logTransfer(from, to, amount);
	}

	ConsoleLogger logger;
};

int main() {
	Bank bank;
	bank.makeTransfer(1000, 100, 80000);

	return 0;
}