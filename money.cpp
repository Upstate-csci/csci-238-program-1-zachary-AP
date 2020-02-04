/********
 Author:
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#include "money.h"

// convert current currency values to a string
string Money::toString() {
    return "";
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {
    stringstream ss;

    ss << "$" << left << setfill('0') << setw(4) << amount;
    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    stringstream moneyStream;
    total = 0.0;
    cin >> hundreds;
    total += (hundreds * 100.00);
    cin >> tens;
    total += (tens * 10.00);
    cin >> fives;
    total += (fives * 5.00);
    cin >> ones;
    total += ones;
    cin >> quarters;
    total += (quarters * .25);
    cin >> dimes;
    total += (dimes * .10);
    cin >> nickels;
    total += (nickels * .05);
    cin >> cents;
    total += (cents * .01);
    moneyStream << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters "
    << dimes << " dimes " << nickels << " nickels " << cents << " cents  = $" << total;

    return moneyStream.str();
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    cin >> total;
    double cash = total;
    stringstream floatStream;
    hundreds = (total / 100);
    total = total - (hundreds * 100);
    tens = (total / 10.0);
    total = total - (tens * 10);
    fives = (total / 5.0);
    total = total - (fives * 5);
    ones = (total / 1.0);
    total = total - (ones);
    quarters = (total / .25);
    total = total - (quarters * .25);
    dimes = (total / .1);
    total = total - (dimes * .1);
    nickels = (total / .05);
    total = total - (nickels * .05);
    cents = (total / .01);

    floatStream << "$" << cash << " = " << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters
    << " quarters " << dimes << " dimes " << nickels << " nickels " << cents << " pennies";
    return floatStream.str();
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    return "";
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    double payment;
    cin >> total;
    cin >> payment;
    double change = total - payment;

    stringstream floatChangeStream;
    hundreds = (change / 100);
    change = change - (hundreds * 100);
    tens = (change / 10.0);
    change = change - (tens * 10);
    fives = (change / 5.0);
    change = change - (fives * 5);
    ones = (change / 1.0);
    change = change - (ones);
    quarters = (change / .25);
    change = change - (quarters * .25);
    dimes = (change / .1);
    change = change - (dimes * .1);
    nickels = (change / .05);
    change = change - (nickels * .05);
    cents = (change / .01);

    floatChangeStream << "change back on $" << payment << " for purchase of $" << total << " is " << (payment - total)
    << " which is " << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones "
    << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << cents << " pennies";
    return floatChangeStream.str();
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    stringstream changeChange;
    string totalChange;
    double payment = 0.0;
    cin >> hundreds;
    payment += (hundreds * 100.0);
    cin >> tens;
    payment += (tens * 10.0);
    cin >> fives;
    payment += (fives * 5.0);
    cin >> ones;
    payment += ones;
    cin >> quarters;
    payment += (quarters * .25);
    cin >> dimes;
    payment += (dimes * .10);
    cin >> nickels;
    payment += (nickels * .05);
    cin >> cents;
    payment += (cents * .01);
    cin >> total;
    total = payment - total;

    hundreds = (total / 100);
    total = total - (hundreds * 100);
    tens = (total / 10.0);
    total = total - (tens * 10);
    fives = (total / 5.0);
    total = total - (fives * 5);
    ones = (total / 1.0);
    total = total - (ones);
    quarters = (total / .25);
    total = total - (quarters * .25);
    dimes = (total / .1);
    total = total - (dimes * .1);
    nickels = (total / .05);
    total = total - (nickels * .05);
    cents = (total / .01);

    changeChange << hundreds << " " << tens << " " << fives << " " << ones << " " << quarters << " " << dimes
                << " " << nickels << " " << cents;
    return changeChange.str();

}
