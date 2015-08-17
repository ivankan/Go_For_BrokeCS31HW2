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
	int numShares, priorTransactions, upperFloor, discountLevel1, discountLevel2, lowerBase, level1Base, level2Base;
	double sharePrice, pricePoint, upperCommission, lowerCommission;

	pricePoint = 1.00; //Share price determines the commission schedule
	level1Base = 30; //minimum prior transactions for discount level 1
	level2Base = 61; //minimum prior transactions for discount level 2

	//Define commission schedule for stocks above price point:
	upperCommission = 0.025; //commission per share
	upperFloor = 25; //minimum commission
	discountLevel1 = 10; //discount for level 1
	discountLevel2 = 25; //discount for level 2

	//Define commission schedule for stocks below price point:
	lowerBase = 20; //base commission
	lowerCommission = 0.02; //percent of the principle
	
	system("PAUSE");
	return 0;
}