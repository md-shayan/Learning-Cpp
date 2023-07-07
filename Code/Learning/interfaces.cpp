#include <cstdio>

struct Logger {
	virtual ~Logger() = default;
	virtual void log_transfer(long from, long to, double amount) = 0;
};

struct DataLogger : Logger {
	void log_transfer(long from, long to, double amount) override {
		printf("[DataLogger] Data Transferred From Account %ld To Account %ld -> %f\n", from, to, amount);
	}
};

struct BankLogger : Logger {
	void log_transfer(long from, long to, double amount) override {
		printf("[BankLogger] Amount Transferred From Account %ld To Account %ld -> %f\n", from, to, amount);
	}
};


struct Bank {
	Bank(Logger* logger) : logger{logger} {}

	void makeTransfer(long from, long to, double amount) {
		logger->log_transfer(from, to, amount);
	}

	void setLogger(Logger* setLogger) {
		logger = setLogger;
	}
private:
	Logger* logger;
};

int main() {
	DataLogger dataLogger;
	BankLogger bankLogger;
	Bank bank{&bankLogger};
	bank.makeTransfer(100, 101, 10000);
	bank.setLogger(&dataLogger);
	bank.makeTransfer(100, 101, 10000);
	bank.setLogger(&bankLogger);
	bank.makeTransfer(100, 101, 10000);
}