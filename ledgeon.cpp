#include<iostream>
int main()
{
	//Enter The main value
	const double charity_charges{ 1008.97 };
	int year1{ 0 };
	std::cout << "Enter the first year: ";
	std::cin >> year1;
	int patients1{ 0 };
	std::cout << "Enter the number of patients we saw that year: ";
	std::cin >> patients1;




	//Second year
	int year2{ 0 };
	std::cout << "Enter the second year: ";
	std::cin >> year2;
	int patients2{ 0 };
	std::cout << "Enter the number of patients we saw that year: ";
	std::cin >> patients2;

	//output everthing as a test
	std::cout << "In year " << year1 << ", our hospital issued " << patients1 * charity_charges <<
		" dollars of charity charges.\n";
	std::cout << "In year " << year2 << ", our hospital issued " << patients2 * charity_charges <<
		" dollars of charity charges.\n";

	std::cout << "Between " << year1 << " and " << year2 << ", there was a " <<(static_cast<double>(patients2 - patients1) / patients1)*100 << "% increase in patients seen at our hospital.\n";


	return 0;


}