#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <sstream>
#include <queue>

using namespace std;

class Bank
{
public:
	string name;
	int balance;
	set<string> paymentTypes;

	Bank(const string &n = "", const set<string> &types = {})
		: name(n), balance(0), paymentTypes(types) {}
};

class Transaction
{
public:
	string from, to;
	int amount;
	string paymentType;

	Transaction(const string &f, const string &t, int amt, const string &type = "")
		: from(f), to(t), amount(amt), paymentType(type) {}

	bool canConsolidate(const Transaction &other) const
	{
		return from == other.from && to == other.to && paymentType == other.paymentType;
	}
};

class CashFlowMinimizer
{
private:
	vector<Bank> banks;
	unordered_map<string, int> bankIndex;
	vector<Transaction> transactions;
	vector<Transaction> minimizedTransactions;

	struct BankBalance
	{
		int index;
		int balance;

		BankBalance(int idx, int bal) : index(idx), balance(bal) {}

		bool operator<(const BankBalance &other) const
		{
			return abs(balance) < abs(other.balance);
		}
	};

	void calculateBalances()
	{
		for (auto &bank : banks)
		{
			bank.balance = 0;
		}

		for (const auto &trans : transactions)
		{
			banks[bankIndex[trans.from]].balance -= trans.amount;
			banks[bankIndex[trans.to]].balance += trans.amount;
		}
	}

	bool findMatchingPaymentType(const Bank &from, const Bank &to, string &matchType)
	{
		for (const auto &type : from.paymentTypes)
		{
			if (to.paymentTypes.count(type) > 0)
			{
				matchType = type;
				return true;
			}
		}
		return false;
	}

	void consolidateTransactions()
	{
		if (minimizedTransactions.empty())
			return;

		vector<Transaction> consolidated;
		vector<bool> used(minimizedTransactions.size(), false);

		for (size_t i = 0; i < minimizedTransactions.size(); i++)
		{
			if (used[i])
				continue;

			Transaction combined = minimizedTransactions[i];
			used[i] = true;

			for (size_t j = i + 1; j < minimizedTransactions.size(); j++)
			{
				if (!used[j] && combined.canConsolidate(minimizedTransactions[j]))
				{
					combined.amount += minimizedTransactions[j].amount;
					used[j] = true;
				}
			}

			consolidated.push_back(combined);
		}

		minimizedTransactions = consolidated;
	}

	// Helper function to clear input buffer
	void clearInputBuffer()
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	// Helper function to validate bank name
	bool isValidBankName(const string &name)
	{
		return !name.empty() && name.find_first_of(" \t\n") == string::npos;
	}

public:
	void loadFromFile(const string &filename)
	{
		ifstream file(filename);
		if (!file)
		{
			throw runtime_error("Cannot open file: " + filename);
		}

		string line;
		// Read number of banks
		if (!getline(file, line))
		{
			throw runtime_error("File is empty");
		}

		istringstream iss(line);
		int numBanks;
		if (!(iss >> numBanks) || numBanks < 2)
		{
			throw runtime_error("Invalid number of banks (must be >= 2)");
		}

		banks.clear();
		bankIndex.clear();

		// Read banks
		for (int i = 0; i < numBanks; i++)
		{
			if (!getline(file, line))
			{
				throw runtime_error("Unexpected end of file while reading bank " + to_string(i + 1));
			}

			istringstream bankIss(line);
			string name;
			int numTypes;

			if (!(bankIss >> name >> numTypes) || numTypes < 1)
			{
				throw runtime_error("Invalid bank data format for bank " + to_string(i + 1));
			}

			if (!isValidBankName(name))
			{
				throw runtime_error("Invalid bank name: " + name);
			}

			if (bankIndex.find(name) != bankIndex.end())
			{
				throw runtime_error("Duplicate bank name: " + name);
			}

			set<string> types;
			string type;
			for (int j = 0; j < numTypes; j++)
			{
				if (!(bankIss >> type))
				{
					throw runtime_error("Missing payment type for bank: " + name);
				}
				if (!types.insert(type).second)
				{
					throw runtime_error("Duplicate payment type '" + type + "' for bank: " + name);
				}
			}

			banks.emplace_back(name, types);
			bankIndex[name] = i;
		}

		// Read number of transactions
		if (!getline(file, line))
		{
			throw runtime_error("Missing transaction count");
		}

		istringstream transIss(line);
		int numTransactions;
		if (!(transIss >> numTransactions) || numTransactions < 0)
		{
			throw runtime_error("Invalid number of transactions");
		}

		// Read transactions
		transactions.clear();
		for (int i = 0; i < numTransactions; i++)
		{
			if (!getline(file, line))
			{
				throw runtime_error("Unexpected end of file while reading transaction " + to_string(i + 1));
			}

			istringstream transLineIss(line);
			string from, to;
			int amount;

			if (!(transLineIss >> from >> to >> amount))
			{
				throw runtime_error("Invalid transaction format at line " + to_string(i + 1));
			}

			if (bankIndex.find(from) == bankIndex.end())
			{
				throw runtime_error("Unknown source bank in transaction: " + from);
			}
			if (bankIndex.find(to) == bankIndex.end())
			{
				throw runtime_error("Unknown destination bank in transaction: " + to);
			}
			if (from == to)
			{
				throw runtime_error("Source and destination banks are the same in transaction " + to_string(i + 1));
			}
			if (amount <= 0)
			{
				throw runtime_error("Invalid amount in transaction " + to_string(i + 1));
			}

			transactions.emplace_back(from, to, amount);
		}
	}

	void loadFromManualInput()
	{
		cout << "\n================ CASH FLOW MINIMIZER SYSTEM ================\n\n";

		string input;
		int numBanks;

		// Get number of banks
		while (true)
		{
			cout << "Enter number of banks (minimum 2): ";
			getline(cin, input);
			istringstream iss(input);

			if (iss >> numBanks && numBanks >= 2 && iss.eof())
			{
				break;
			}
			cout << "Invalid input. Please enter a number >= 2\n";
		}

		banks.clear();
		bankIndex.clear();

		// Get all bank details
		cout << "\nEnter bank details in format: BankName NumPaymentTypes PaymentType1 PaymentType2 ...\n";
		cout << "Example: Bank1 2 PayPal Visa\n\n";

		for (int i = 0; i < numBanks; i++)
		{
			cout << "Bank " << (i + 1) << ": ";
			getline(cin, input);
			istringstream iss(input);

			string name;
			int numTypes;

			if (!(iss >> name >> numTypes) || numTypes < 1)
			{
				cout << "Invalid format. Please try again.\n";
				i--;
				continue;
			}

			if (!isValidBankName(name))
			{
				cout << "Invalid bank name. Names cannot contain spaces. Please try again.\n";
				i--;
				continue;
			}

			if (bankIndex.find(name) != bankIndex.end())
			{
				cout << "Bank name already exists. Please use a different name.\n";
				i--;
				continue;
			}

			set<string> types;
			string type;
			bool validTypes = true;
			for (int j = 0; j < numTypes; j++)
			{
				if (!(iss >> type))
				{
					cout << "Missing payment type(s). Please provide " << numTypes << " payment types.\n";
					validTypes = false;
					break;
				}
				if (!types.insert(type).second)
				{
					cout << "Duplicate payment type '" << type << "'. Please use unique types.\n";
					validTypes = false;
					break;
				}
			}

			if (!validTypes)
			{
				i--;
				continue;
			}

			string extra;
			if (iss >> extra)
			{
				cout << "Too many payment types provided. Please try again.\n";
				i--;
				continue;
			}

			banks.emplace_back(name, types);
			bankIndex[name] = i;
		}

		// Get transactions
		int numTransactions;
		while (true)
		{
			cout << "\nEnter number of transactions: ";
			getline(cin, input);
			istringstream iss(input);

			if (iss >> numTransactions && numTransactions > 0 && iss.eof())
			{
				break;
			}
			cout << "Invalid input. Please enter a positive number\n";
		}

		cout << "\nEnter transactions in format: FromBank ToBank Amount\n";
		cout << "Available banks:\n";
		for (const auto &bank : banks)
		{
			cout << "- " << bank.name << "\n";
		}

		transactions.clear();
		for (int i = 0; i < numTransactions; i++)
		{
			cout << "\nTransaction " << (i + 1) << ": ";
			getline(cin, input);
			istringstream iss(input);

			string from, to;
			int amount;

			if (!(iss >> from >> to >> amount))
			{
				cout << "Invalid format. Please try again.\n";
				i--;
				continue;
			}

			if (bankIndex.find(from) == bankIndex.end())
			{
				cout << "Error: Source bank '" << from << "' does not exist\n";
				i--;
				continue;
			}
			if (bankIndex.find(to) == bankIndex.end())
			{
				cout << "Error: Destination bank '" << to << "' does not exist\n";
				i--;
				continue;
			}
			if (from == to)
			{
				cout << "Error: Source and destination banks cannot be the same\n";
				i--;
				continue;
			}
			if (amount <= 0)
			{
				cout << "Invalid amount. Please enter a positive number\n";
				i--;
				continue;
			}

			string extra;
			if (iss >> extra)
			{
				cout << "Too many values provided. Please try again.\n";
				i--;
				continue;
			}

			transactions.emplace_back(from, to, amount);
		}
	}
	
	void minimizeTransactions()
	{
		calculateBalances();
		minimizedTransactions.clear();

		priority_queue<BankBalance> debtors;
		priority_queue<BankBalance> creditors;

		for (int i = 0; i < banks.size(); i++)
		{
			if (banks[i].balance < 0)
			{
				debtors.push(BankBalance(i, banks[i].balance));
			}
			else if (banks[i].balance > 0)
			{
				creditors.push(BankBalance(i, banks[i].balance));
			}
		}

		while (!debtors.empty() && !creditors.empty())
		{
			BankBalance maxDebtor = debtors.top();
			debtors.pop();
			BankBalance maxCreditor = creditors.top();
			creditors.pop();

			int amount = min(-maxDebtor.balance, maxCreditor.balance);

			Bank &fromBank = banks[maxDebtor.index];
			Bank &toBank = banks[maxCreditor.index];

			// Common Payment mode between banks
			string paymentType;

			// If common mode find, then add transaction
			if (findMatchingPaymentType(fromBank, toBank, paymentType))
			{
				minimizedTransactions.emplace_back(fromBank.name, toBank.name, amount, paymentType);
			}
			// If no common mode of payment, then world bank as intermediate
			else
			{
				string fromType = *fromBank.paymentTypes.begin();
				string toType = *toBank.paymentTypes.begin();
				minimizedTransactions.emplace_back(fromBank.name, "WorldBank", amount, fromType);
				minimizedTransactions.emplace_back("WorldBank", toBank.name, amount, toType);
			}

			int newDebtorBalance = maxDebtor.balance + amount;
			int newCreditorBalance = maxCreditor.balance - amount;


			// If balance left after transaction, push again into heap
			if (newDebtorBalance < 0)
			{
				debtors.push(BankBalance(maxDebtor.index, newDebtorBalance));
			}
			if (newCreditorBalance > 0)
			{
				creditors.push(BankBalance(maxCreditor.index, newCreditorBalance));
			}

			fromBank.balance = newDebtorBalance;
			toBank.balance = newCreditorBalance;
		}

		consolidateTransactions();
	}

	void displayResults() const
	{
		cout << "\n============== MINIMIZED CASH FLOW TRANSACTIONS ==============\n\n";

		if (minimizedTransactions.empty())
		{
			cout << "No transactions needed - all accounts are settled!\n";
			return;
		}

		cout << left
			 << setw(15) << "From Bank"
			 << setw(15) << "To Bank"
			 << setw(15) << "Amount"
			 << "Payment Type\n"
			 << string(60, '-') << "\n";

		for (const auto &trans : minimizedTransactions)
		{
			cout << left
				 << setw(15) << trans.from
				 << setw(15) << trans.to
				 << setw(15) << trans.amount
				 << trans.paymentType << "\n";
		}
		cout << "\n===========================================================\n";
	}
};

int main()
{
	try
	{
		CashFlowMinimizer minimizer;
		string input;

		cout << "Choose input method:\n"
			 << "1. Load from file\n"
			 << "2. Manual input\n"
			 << "Choice: ";

		getline(cin, input);
		if (input == "1")
		{
			cout << "Enter filename: ";
			getline(cin, input);
			minimizer.loadFromFile(input);
		}
		else if (input == "2")
		{
			minimizer.loadFromManualInput();
		}
		else
		{
			throw runtime_error("Invalid choice");
		}

		minimizer.minimizeTransactions();
		minimizer.displayResults();
	}
	catch (const exception &e)
	{
		cerr << "\nError: " << e.what() << "\n";
		return 1;
	}

	return 0;
}