#include <iostream>

int get_int();
double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarter);
//declarations
int main() {
	int get_int;
	int year;
	int quarter;
	//inputs and outputs
	std::cout << "Please enter the year for the calculation: ";
	std::cin >> year;
	std::cout << "Please enter the quarter for the calculation: ";
	std::cin >> quarter;
	
	
	//calculations

	double epochq = 1977 * 4;
	double cd = year * 4 + (quarter - 1);
	double qb = cd - epochq; 

	
	std::cout << "In the " << quarter_to_ordinal( quarter) << " quarter of " << year << ", the projected contribution to GDP per working-age person is $" << format_money(calculate_per_capita_gdp_estimate(qb))  << ".\n";



	return 0;
}