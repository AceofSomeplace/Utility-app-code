#include <iostream>
#include <windows.h> //This version of code is only compatible with Windows OS
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

//Variable and function setup
void pageStup();
void catagoryFunk();
void menuFunk(int catagory);
void itemBuyFunk(int ind);
void checkoutFunk();
//[0 = item name, 1 = product code, 2 = price][menu items] (placeholders: 3 catagories, 5 items in each, all 10 coin)
string menu[3][15] = { { "item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10", "item11", "item12", "item13", "item14", "item15" }, {"A1", "A2", "A3", "A4", "A5","B1", "B2", "B3", "B4", "B5","C1", "C2", "C3", "C4", "C5",}, {"10", "10", "10", "10", "10", "10", "10", "10", "10", "10", "10", "10", "10", "10", "10"} };
int basket[2][5]; //[0 = menu index of item, 1 = ammount in basket][inventory space]
int cataRange[] = { 0, 5, 10, 15 }; //Range of each catagory
int total, coins, basketSpace = 0;
string item;
bool boolEnd = false;


int main() {
	//Resizes window(*Windows exlsv)
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 500, 500, true);

	//Loads welcome screen
	pageStup();
	cout << "              Welcome to the vending machine!\n              ";
	system("pause"); //(*Windows exlsv)
	catagoryFunk();


	//When all functions return back, end
	boolEnd = true;
	pageStup();
	if (coins > total) {
		cout << "       Please collect your item(s) and " << 0-(total - coins) << "p change.";
	}
	else {
		cout << "                Please collect your item(s).";
	}
	cout << "\n                Thank you for shopping!\n              ";
	system("pause"); //(*Windows exlsv)
	return 0;
}



//Prints catagories and receives choice
void catagoryFunk() {
	pageStup();
	int catagory;
	//Prints catagory options, and asks user for catagory choice
	cout << "             Please enter a catagory number:\n         -Catagory 1 (1)\n         -Catagory 2 (2)\n         -Catagory 3 (3)\n         -All (4)\n          ";
	if (basketSpace > 0) { //If basket contains item, print checkout option (5)
		cout << "Checkout (5)\n         ";
	}
	cin >> catagory;


	//Check input is valid (must be int, if there is no items in basket, must be 4 or lower, must not excede 5)
	while (!cin || (basketSpace == 0 && catagory > 4) || catagory > 5) {
		cout << "           Invalid option, please re-enter:\n         ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> catagory;
	}

	//If checkout is entered (and valid) go to checkout. Else go to the entererd menu
	if (basketSpace != 0 && catagory == 5) {
		checkoutFunk();
	}
	else {
		menuFunk(catagory);
	}
	return;
}



//Prints menu according to catagory and receives choice
void menuFunk(int catagory) {
	pageStup();
	string item;
	int ind = 0;
	bool valid = false;

	cout << "  Please enter an item code, or type 'back' to go back:";
	for (int i = cataRange[catagory -1]; i < cataRange[catagory]; i++){ //Prints menu items from end of catagory range before, to catagory upper range
		cout << "\n          " << menu[0][i] << "(" << menu[1][i] << ")  " << menu[2][i] << "p";
	}
	cout << "\n          ";
	cin >> item;

	//Validation check
	while (valid == false) {
		//If input is invalid type
		while (!cin) {
			"\n             Invalid choice, please re-enter: ";
			cin >> item;
		}

		//Cheking input is either "back" or is an itemcode present in menu range
		transform(item.begin(), item.end(), item.begin(), ::toupper);
		if (item == "BACK") {
			catagoryFunk();
			return;
		}
		else {
			ind = cataRange[catagory - 1];
			while (ind < cataRange[catagory]) { //Compare item code to menu while i is less than upper catagory range
				//Converting first value to uppercase
				item[0] = toupper(item[0]);

				//Comparing item to menu at index i
				if (item == menu[1][ind]) { //If item equals item in menu at index i, input is valid
					valid = true;
					break;
				}
				ind++;
			}

			//If input is not present in menu range, re-ask for input
			if (valid == false) {
				cout << "Invalid choice, please re-enter: ";
				cin >> item;
			}
		}
	}

	//Once "item" input valid (and not equal "back"), call upon itemBuyFunk
	itemBuyFunk(ind);
	catagoryFunk();
}



//Asks user to confirm item, checks basket isn't full, and and adds it to basket if both conditions are met
void itemBuyFunk(int ind) {
	pageStup();

	//Check there is space in basket
	if (basketSpace < 5) { //If there is space, add item to basket
		bool itemLocated = false;
		for (int i = 0; i < basketSpace; i++) { //Search basket for item bought. If present, increase item ammount in basket by 1
			if (basket[0][i] == ind) {
				basket[1][i] += 1;
				itemLocated = true;
				break;
			}
		}
		if (itemLocated == false) { //If item is not already in basket, add it.
			basket[0][basketSpace] = ind;
			basket[1][basketSpace] = 1;
			basketSpace++;
		}
		cout << "                 Added " << menu[0][basket[0][basketSpace -1]] << " to basket.\n              ";
	}
	else { //If there is no space, add print they cannot add to basket
		cout << "            You have no more space in your basket!\n              ";
	}

	//Go back to menu
	system("pause"); //(*Windows exlsv)
	return;
}



//Rings up total and requires user to enter coins.
void checkoutFunk() {
	pageStup();
	int coinEntr = 0;

	//Prints basket and total, as well as calcuate total 
	cout << "                   Your basket contains:" << endl;
		for (int i = 0; i < basketSpace; i++) {
			cout << "                     " << menu[0][basket[0][i]] << " x" << basket[1][i] << "," << endl;
			total += stoi(menu[2][basket[0][i]]) * basket[1][i];
		}
		cout << "                Coming to a total of " << total << "p\n              ";
		system("pause"); //(*Windows exlsv)

	//Asks user to input coins until the total is met
	while (coinEntr < total) {
		pageStup();
		cout << "             Total: " << total << "    Entered ammount: " << coins << "\n  Please enter a coin of any value: 1, 5, 10, 50 or 100\n                        ";
		cin >> coinEntr;

		//If input is inavlid type, coin value is not valid, user must re-enter input until valid
		while (!cin || (coinEntr != 1 && coinEntr != 5 && coinEntr != 10 && coinEntr != 50 && coinEntr != 100)) {
			pageStup();
			cout << "                    Invalid coin type." << endl;
			cout << "             Total: " << total << "    Entered ammount: " << coins << "\n  Please enter a coin of any value: 1, 5, 10, 50 or 100\n                        ";
			cin >> coinEntr;
		}
		coins += coinEntr;
	}
	return;
}


//Sets up the visuals of the page
void pageStup() {
	system("CLS"); //(*Windows exlsv)

	//prints vending machine
	//header
	cout << "                 __________________________\n                 |                     |  |\n";
	//body
	for (int i = 0; i < 9; i++) {
		cout << "                 | [  ] [  ] [  ] [  ] |  |\n";
	}
	cout << "                 |_____________________|__| \n                 |[";
	//tray(appearence deppendant on if you're at the end or not)
	if (boolEnd == false) {
		cout << "___________________";
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (basketSpace > i) {
				cout << "o";
			}
			else {
				cout << "__";
			}

		}
	}
	//Bottom
	cout << "]   |\n                 |________________________|\n" << endl;
}