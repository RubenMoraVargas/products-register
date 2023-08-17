#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;

void registerSales(int**& sales, int days, int products) {
	for (int i = 0; i < days; i++) {
		cout << "Enter the daily sales for day " << i + 1 << ":" << endl;
		for (int j = 0; j < products; j++) {
			cout << "Product " << j + 1 << ": ";
			cin >> sales[i][j];
		}
	}
}

void calculateTotalSales(int**& sales, int days, int products) {
	cout << "Total sales per day:" << endl;
	for (int i = 0; i < days; i++) {
		int total = 0;
		for (int j = 0; j < products; j++) {
			total += sales[i][j];
		}
		cout << "Day " << i + 1 << ": " << total << endl;
	}
}

void freeMemory(int**& sales, int numRows) {
	for (int i = 0; i < numRows; i++) {
		delete[] sales[i];
	}
	delete[] sales;
}

void initMatrix(int**& sales, int numRows,int numColumns) {
	sales = new int* [numRows];
	for (int i = 0; i < numRows; i++) {
		sales[i] = new int[numColumns];
	}
}

int main() {
	const int NUM_DAYS = 7;
	const int NUM_PRODUCTS = 5;
	int** dailySales = nullptr;

	initMatrix(dailySales, NUM_DAYS, NUM_PRODUCTS);
	registerSales(dailySales, NUM_DAYS, NUM_PRODUCTS);
	calculateTotalSales(dailySales, NUM_DAYS, NUM_PRODUCTS);

	freeMemory(dailySales, NUM_DAYS);

	return 0;

}