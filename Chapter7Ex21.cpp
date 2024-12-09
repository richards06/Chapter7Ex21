/*
Program Title: Chapter7Ex21
Programmer: Josh Richards
Date: December 7, 2024
Requirements:

Write a program that creates a two-dimensional array initialized with test data. Use any data type you wish. The program should have the following functions:
• getTotal—This function should accept a two-dimensional array as its argument and return the total of all the values in the array.
• getAverage—This function should accept a two-dimensional array as its argument and return the average of all the values in the array.
• getRowTotal—This function should accept a two-dimensional array as its first argument and an integer as its second argument. The second argument should be 
  the subscript of a row in the array. The function should return the total of the values in the specified row.
• getColumnTotal—This function should accept a two-dimensional array as its first argument and an integer as its second argument. The second argument should 
  be the subscript of a column in the array. The function should return the total of the values in the specified column.
• getHighestInRow—This function should accept a two-dimensional array as its first argument and an integer as its second argument. The second argument should 
  be the subscript of a row in the array. The function should return the highest value in the specified row of the array.
• getLowestInRow—This function should accept a two-dimensional array as its first argument and an integer as its second argument. The second argument should 
  be the subscript of a row in the array. The function should return the lowest value in the
Display the options in a menu to call the various functions.

*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

double getTotal(const vector<vector<int>>& array);
double getAverage(const vector<vector<int>>& array);
int getRowTotal(const vector<vector<int>>& array, int row);
int getColumnTotal(const vector<vector<int>>& array, int column);
int getHighestInRow (const vector<vector<int>>& array, int row);
int getLowestInRow (const vector<vector<int>>& array, int row);

int main()
{
	vector<vector<int>>testData = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};

	int choice, row, column;
	do {
		cout << "Menu:\n";
		cout << "1. Get Total\n";
		cout << "2. GetAverage\n";
		cout << "3. Get Row Total\n";
		cout << "4. Get Column Total\n";
		cout << "5. Get Highest in Row\n";
		cout << "6. Get Lowest in Row\n";
		cout << "7. Exit\n";
		cout << "Enter you choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Total: " << getTotal(testData) << endl;
			break;
		case 2:
			cout << "Average: " << getAverage(testData) << endl;
			break;
		case 3:
			cout << "Enter row index: ";
			cin >> row;
			cout << "Row Total" << getRowTotal(testData, row);
			break;
		case 4:
			cout << "Enter column index: ";
			cin >> column;
			cout << "Column Total: " << getColumnTotal(testData, column) << endl;
			break;
		case 5:
			cout << "Enter row index: ";
			cin >> row;
			cout << "Highest in Row: " << getHighestInRow(testData, row) << endl; 
			break;
		case 6:
			cout << "Enter row index: ";
			cin >> row;
			cout << "Lowest in Row: " << getLowestInRow(testData, row) << endl;
			break;
		case7:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
		}
	} while (choice != 7);
	return 0;
}

double getTotal(const vector<vector<int>>& array) {
	double total = 0;
	for (const auto& row : array) {
		for (int value : row) {
			total += value;
		}
	}
	return total;
}

double getAverage(const vector<vector<int>>& array) {
	double total = getTotal(array);
	int count = 0;
	for (const auto& row : array) {
		count += row.size();
	}
	return total / count;
}

int getRowTotal(const vector<vector<int>>& array, int row) {
	int total = 0;
	if (row >= 0 && row < array.size()) {
		for (int value : array[row]) {
			total += value;
		}
	}
	else {
		cout << "Invalid row index." << endl;
	}
	return total;
}

int getColumnTotal(const vector<vector<int>>& array, int column) {
	int total = 0;
	for (const auto& row : array) {
		if (column >= 0 && column < row.size()) {
			total += row[column];
		}
		else {
			cout << "Invalid column index." << endl;
			break;
		}
	}
	return total;
}

int getHighestInRow(const vector<vector<int>>& array, int row) {
	if (row >= 0 && row < array.size()) {
		int highest = numeric_limits<int>::min();
		for (int value : array[row]) {
			if (value > highest) {
				highest = value;
			}
		}
		return highest;
	}
	else {
		cout << "Invalid row index." << endl;
		return numeric_limits<int>::min();
	}
}

int getLowestInRow(const vector<vector<int>>& array, int row) {
	if (row >= 0 && row < array.size()) {
		int lowest = numeric_limits<int>::max();
		for (int value : array[row]) {
			if (value < lowest) {
				lowest = value;
			}
		}
		return lowest;
	}
	else {
		cout << "Invalid row index." << endl;
		return numeric_limits<int>::max();
	}
}