// Code for Project 2
// Go for broke
// Ivan Kan

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string transactionType, clientName;
	int numShares, priorTransactions, upperFloor, lowerBase, level1Base, level2Base;
	double principal, sharePrice, pricePoint, discountLevel1, discountLevel2, upperCommission, lowerCommission, discount, commission, netAmount;

	pricePoint = 1.00; //Share price determines the commission schedule
	level1Base = 30; //minimum prior transactions for discount level 1
	level2Base = 61; //minimum prior transactions for discount level 2

	//Define commission schedule for stocks above price point:
	upperCommission = 0.025; //commission per share
	upperFloor = 25; //minimum commission
	discountLevel1 = .10; //discount for level 1
	discountLevel2 = .25; //discount for level 2

	//Define commission schedule for stocks below price point:
	lowerBase = 20; //base commission
	lowerCommission = 0.02; //percent of the principle

	//Prompt user for transaction type
	cout << "Buy or sell(b / s): ";
	getline(cin, transactionType);
	if (transactionType != "b")
	{
		if (transactionType != "s")
		{
			cout << "---" << endl << "You must enter b or s" << endl;
			system("PAUSE");
			return 1;
		}
	}
	cout << "Number of shares: ";
	cin >> numShares;
	if (numShares < 0)
	{
		cout << "---" << endl << "The number of shares must be positive" << endl;
		system("PAUSE");
		return 1;
	}
	if (numShares == 0)
	{
		cout << "---" << endl << "The number of shares cannot be zero" << endl;
		system("PAUSE");
		return 1;
	}
	cout << "Share price: ";
	cin >> sharePrice;
	if (sharePrice < 0)
	{
		cout << "---" << endl << "The share price must be positive" << endl;
		system("PAUSE");
		return 1;
	}
	if (sharePrice == 0)
	{
		cout << "---" << endl << "The share price cannot be zero" << endl;
		system("PAUSE");
		return 1;
	}
	cout << "Client name: ";
	cin.ignore(1000, '\n'); //Discard newline characters
	getline(cin, clientName);
	if (clientName == "")
	{
		cout << "---" << endl << "You must enter a name" << endl;
		system("PAUSE");
		return 1;
	}
	cout << "Number of prior transactions: ";
	cin >> priorTransactions;
	if (priorTransactions < 0)
	{
		cout << "---" << endl << "The number of prior transactions must not be negative" << endl;
		system("PAUSE");
		return 1;
	}
	if (priorTransactions == 0)
	{
		cout << "---" << endl << "The number of prior transactions cannot be zero" << endl;
		system("PAUSE");
		return 1;
	}

	//Calculation of principal
	principal = numShares * sharePrice;

	//Calculation of Commission
	if (sharePrice >= pricePoint)
	{
		commission = numShares * upperCommission;
		if (commission < upperFloor)
		{
			commission = 25;
		}
	}
	if (sharePrice < pricePoint)
	{
		commission = lowerBase + (lowerCommission * (principal));
	}
	
	//Calculation of Discount
	if (sharePrice >= pricePoint)
	{
		if (priorTransactions >= level1Base && priorTransactions < level2Base)
		{
			discount = commission * discountLevel1;
			cout << "Discount of: " << discountLevel1;
		}
		else if (priorTransactions >= level2Base)
		{
			discount = commission * discountLevel2;
			cout << "Discount of : " << discountLevel2;
		}
	}
	if (sharePrice < pricePoint)
	{
		discount = 0;
	}

	//Final check to see if commission is greater than principal
	commission = commission - discount;
	if (commission > principal)
	{
		commission = principal;
	}

	//Calculation of net amount
	if (transactionType == "b")
	{
		netAmount = principal + commission;
	}
	else if (transactionType == "s")
	{
		netAmount = principal - commission;
	}
	else
	{
		cout << "---" << endl << "You shouldn't be here Ivan";
		return 1;
	}

	cout << fixed << setprecision(2); //set to 2 digits after decimal point

	cout << "---" << endl << "Commission = " << commission << endl << "Principal = " << principal << endl;
	//Final output to user
	cout << "---" << endl << "Net amount for " << clientName << " is $" << netAmount << endl;
	system("PAUSE");
	return 0;
}