#include <cstdio>
#include <stdexcept>

struct DataLogger {
	void log_transfer(long from, long to, double amount) {
		printf("[DataLogger] Data Transferred From Account:%ld To Account:%ld -> %f\n", from, to, amount);
	}
};

struct BankLogger {
	void log_transfer(long from, long to, double amount) {
		printf("[BankLogger] Amount Transferred From Account:%ld To Account:%ld -> %f\n", from, to, amount);
	}
};

enum class LoggerType {
	Bank,
	Data
};

struct Bank {
	Bank() : type{LoggerType::Data} {}

	void setLogger(LoggerType newLogger) {
		type = newLogger;
	}

	void makeTransfer(long from, long to, double amount) {
		switch (type) {
		case LoggerType::Bank:
			bankLogger.log_transfer(from, to, amount);
			break;
		case LoggerType::Data:
			dataLogger.log_transfer(from, to, amount);
			break;
		default:
			throw std::logic_error("Unknown Logger Type Encountered.");
		}
	}

private:
	LoggerType type;
	DataLogger dataLogger;
	BankLogger bankLogger;
};

int main() {
	Bank bank;
	bank.makeTransfer(1000, 1001, 100000);
	bank.setLogger(LoggerType::Bank);
	bank.makeTransfer(1000, 1001, 100000);
	return 0;
}