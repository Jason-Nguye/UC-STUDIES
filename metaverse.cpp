#include "metaverse.h"
#include "display.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <vector>
/*
count_neighbors

count the number of occupid neighbors for a given location
input <metaverse constant(metaverse_t)
	   row number (int) row of the location to determine neighborhood population
	   column number(int) column of the location determine neighborhood population>
output < THe funciton will return the number of occupied neighbors in the current generation>

*/

int count_neighbors(const metaverse_t& board, int row, int column) {
	int neighbor{ 0 };

	for (int i = -1; i <= 1; i++) {
		for (int k = -1; k <= 1; k++) {

			int currentrow = row + i;
			int currentcolumn = column + k;
			//skip the cell itself
			if (currentrow == row && currentcolumn == column) {
				continue;
			}

			//check if the indexes are valid
			if (currentrow >= 0 && currentcolumn >= 0 && currentrow < board.size() && currentcolumn < board.size()) {
				//if valid check if occupied
				if (board[currentrow][currentcolumn] == true) {
					neighbor += 1;
				}
				else {
					continue;
				}

			}

		}
	}
	return neighbor;
}



/*
occupied in the next tick

this function will return true if a given location is occupied in the next generation

input < bool that indicates whether the location is occupied
	   occupied neighbor count(int) an int that holds the count of the number of occupied neighbors
output< the function will return true if unoccupied location with specified number of occupeid neighbors will be occupied in the next gen
*/
bool occupied_in_next_tick(bool currently_occupied, int neighbor_count) {
	if ((neighbor_count==2 || neighbor_count==3) && currently_occupied == true) {
		return true;
	}
	if (currently_occupied == false && neighbor_count == 3) {
		return true;
	}
	else {
		return false;
	}
}
/*
tick

build a new metaverse one tick in the future from a given metaverse

input < metaverse constant (metaverse_t)>
output<the function will return a new metaverse that descibes the next generation of the metaverse descibed by the metaverse referense parameter>
*/
metaverse_t tick(const metaverse_t& board) {
	metaverse_t metaverse{};
	resize_metaverse(board.size(), metaverse);
	for (int i{ 0 }; i < board.size(); i++) {
		for (int k{ 0 }; k < board.size(); k++) {
			int neighbors = count_neighbors(board, i, k);
			if (occupied_in_next_tick(board[i][k], neighbors)) {
				metaverse[i][k] = true;
			}
			else {
				metaverse[i][k] = false;
			}
		}
	}
	return metaverse;
}
/*
resize_metaverse

this function will resize a meaverse according to a given size

input <Size number(int) thatrepresents number of rows and columns
	   metaverse reference (metaverse_t)>
output <the function will resize the given metaverse_t
		function will always return true>
*/

bool resize_metaverse(int rows, metaverse_t& board) {
	board.resize(rows, std::vector<bool>(rows));
	return true;
}
/*
citizenship_row_to_metaverse_row

It will take a string of char read from a row of the uni file and update the citizenship

input < row string(const std::string) contains citizen row of metaverse)
		row number (int) specifies the row whos occupancy isdefiend by the row string
		metaverse reference (metaverse_t) >
output <return true and update the metaverse according to the raw string and return false and nto update the metaverse
		if the raw string does not have a valid length


*/
bool citizenship_row_to_metaverse_row(const std::string& input_row, int row,
	metaverse_t& board) {
	for (int i{ 0 }; i < input_row.size(); i++) {
		int neighbor{ 0 };
		if (input_row[i] == '1') {
			board[row][i] = true;
		}
		else {
			board[row][i] = false;
		}
	}
	return true;
}
/*
read_metaverse_configuration_line_from_file

This function will read and parse the configuation line from a universe file. It will return true and update its out parameters if it was successful
but will return false otherwise

input< A universe file referense (std::ifstream)
	  A size number referse A reference to an int
	  A gneration number reference to an int

*/
bool read_metaverse_configuration_line_from_file(std::ifstream& metaverse_file,
	int& size, int& generations) {
	char character{ 'a' };
	char comma{ ' ' };
	if (!(metaverse_file >> size)) {
		return false;
	}
	metaverse_file >> comma;
	if (!(metaverse_file >> generations)) {
		return false;
	}
	return true;
}
bool initialize_metaverse_from_file(std::ifstream& metaverse_file,
	metaverse_t& metaverse,
	int& generations) {
	int size{};
	int actual_row{};

	generations = 0;

	if (!read_metaverse_configuration_line_from_file(metaverse_file, size,
		generations)) {
		return false;
	}

	if (!resize_metaverse(size, metaverse)) {
		return false;
	}

	metaverse_file >> std::ws;
	while (!metaverse_file.eof()) {
		std::string line{};
		if (!std::getline(metaverse_file, line)) {
			return false;
		}
		if (!citizenship_row_to_metaverse_row(line, actual_row, metaverse)) {
			return false;
		}
		actual_row++;
		metaverse_file >> std::ws;
	}
	return actual_row == size;
}
/*
model_metaverse

this function will model the evolution of the metaverse for a given number of generations. The function will display each tick of the metaverse

input <metaverse reference ( metaverse_t) specifying the citizenship of the metaverse at generation 0
	  numbersof generations (int)>
output <This function will return no value however it will haveside effcts of printing out the state of the metaverse between generation>

*/
void model_metaverse(const metaverse_t& starting_metaverse, int generations) {
	metaverse_t metaverse{ starting_metaverse };
	
	for (int i{ 0 }; i < generations; i++) {
		display_metaverse(std::cout, metaverse);
		metaverse = tick(metaverse);
		
	}
}
