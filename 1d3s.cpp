#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{ 26 };

int number_from_letter(char letter) {
	int offset = letter - (int)'a';
	if (offset < 0 || offset >= ALPHABET_LENGTH) {
		std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
		assert(false);
	}
	return offset;
}

char letter_from_number(int number) {

	if (number < 0 || number >= ALPHABET_LENGTH) {
		std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
		assert(false);
	}

	const char alphabet[] = { 'a',
	  'b',
	  'c',
	  'd',
	  'e',
	  'f',
	  'g',
	  'h',
	  'i',
	  'j',
	  'k',
	  'l',
	  'm',
	  'n',
	  'o',
	  'p',
	  'q',
	  'r',
	  's',
	  't',
	  'u',
	  'v',
	  'w',
	  'x',
	  'y',
	  'z' };
	return alphabet[number];
}

int main() {
	std::ifstream input_file{};
	input_file.open("input.txt");
	char shift_direction{ 'r' };
	int shift_number{ 5 };

	if (!(input_file >> shift_direction)) {
		std::cout << "Oops: Could not read the direction from the input file.\n";
		
		return 0;
	}
	else if (shift_direction != 'r' && shift_direction != 'l') {
		std::cout << "Oops: Invalid direction in the input file.\n";
		return 0;
	}

	if (!(input_file >> shift_number)) {
		std::cout << "Oops: Could not read the shift number from the input file.\n";
		return 0;
	}



	while (!std::iscntrl(input_file.peek()) && !input_file.eof()) {
		char plaintext{ 'b' };
		input_file >> plaintext;



		int plaintext_position{ number_from_letter(plaintext) };

		int actual_shift{ shift_number };
		if (shift_direction != 'r') {
			actual_shift *= -1;
		}

		int encrypted_position{ plaintext_position + actual_shift };


		encrypted_position = encrypted_position % 26;


		if (encrypted_position < 0) {
			encrypted_position += 26;
		}


		char encrypted{ letter_from_number(encrypted_position) };

		std::cout << encrypted;
	}
	std::cout << "\n"; return 0;




}