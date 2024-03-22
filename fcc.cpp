#include <fstream>
#include <iostream>
#include <vector>

bool more_to_read(std::ifstream& file) {
	file >> std::noskipws;
	while (file.peek() == ' ') {
		char discard;
		file >> discard;
	}
	return !(file.eof() || std::iscntrl(file.peek()));
}
std::vector<std::string> read_from_file(std::ifstream& file) {
	std::vector<std::string> words;
	while (more_to_read(file)) {
		std::string next_word;
		file >> next_word;
		words.push_back(next_word);
	}
	return words;
}
int fcc(const std::string& fixme_filename, const std::string& typo_filename,
	const std::string& fixo_filename, std::string& fixed_sentence) {
	/*
	std::cout << "i'm printing fixme_filename " << fixme_filename << "\n";
	std::cout << "i'm printing typo_file " << typo_filename << "\n";
	std::cout << "i'm printing fixo_filename " << fixo_filename << "\n";
	*/

	//declare vectors
	std::vector<std::string> fixos;
	std::vector<std::string> typos;
	std::vector<std::string> fixme;
	std::ifstream fixos_file{ fixo_filename };
	std::ifstream typos_file{ typo_filename };
	std::ifstream fixme_file{ fixme_filename };
	std::ifstream fixedsentence{ fixed_sentence };
	int count{ 0 };
	std::string sentence{ "" };
	//while (data can be read from the fixos file
	fixos = read_from_file(fixos_file);
	typos = read_from_file(typos_file);
	fixme = read_from_file(fixme_file);

	//return -1 for one output
	if (fixos.size() != typos.size()) {
		return -1;
	}

	//for loop to read sentence
	for (int i = 0; i < fixme.size(); i++) {
		bool fixed{ false };
		for (int k = 0; k < typos.size(); k++) {
			if (typos[k] == fixme[i]) {
				count += 1;
				sentence += fixos[k] + " ";
				fixed = true;
				//std::cout << "NICE" << "\n";

			}
			//ERRORS KEEP GETTING ALL WORDS
			//NEED TO GET ALREADY CORRECT SPELT WORDS

		}
		if (fixed == false) {
			sentence += fixme[i] + " ";
			//std::cout << "COOL" << "\n";
		}
		//When we make it to the end we would want to remove the last space


	}
	if (more_to_read(fixme_file) == false); {
		//std::cout << "YES" << "\n";
		sentence = sentence.substr(0, sentence.size() - 1);
	}
	fixed_sentence = sentence + ".";
	return count;
}
