#include <string>
#include <cassert>
#include <ios>
#include <iostream>

/*
 * new_ending
 *
 * new_ending will create a new string whose contents are the
 * same as _candidate_ except that the last _suffix_length_
 * characters are replaced with the contents of _replacement_.
 *
 * input: candidate: The string of which to modify the ending.
 *        suffix_length: The number of characters to remove from _candidate_.
 *        replacement: The string with which to replace the
 *        last _suffix_length_ characters of _candidate_.
 * output: _candidate_ with the last _suffix_length_ characters
 *         replaced with the contents of _replacement_.
 */
std::string new_ending(std::string candidate, int suffix_length,
	std::string replacement) {
	int c = candidate.length() - suffix_length;
		//get length of candidate after length is taken away TEST - 3 4-3 1 
	std::string test{ candidate.substr(0,c)};
		//have the T
	//ADD THE REPLACEMNT but idk how to add the replacement maybe a loop or no? just add it together but how?
	//strings cant be added together so do we have to pull out letters and put them together thus causing a loop
	//strings cant be added together so do we have to pull out letters and put them together thus causing a loop
	return test + replacement;
}
/*
 * ends_with
 *
 * ends_with determine whether _candidate_ ends with _suffix_.
 *
 * input: candidate: The string for which to check the ending.
 *        suffix: The string to test against the ending of _candidate_.
 * output: true if _candidate_ ends with _suffix_; false, otherwise.
 */
bool ends_with(std::string candidate, std::string suffix) {
	if (suffix.length() > candidate.length()) {
		return false;
	}

	for (int c = 0; c < suffix.length(); c++) {
		if (candidate.at(candidate.length() - c -1 ) != suffix.at(suffix.length() - c - 1)) {

			return false;
		}
	}
	return true;
}

/*
 * is_vowel
 *
 * Determine whether _c_ is a vowel. Note: 'y' is *not* a vowel.
 *
 * input: c: The character to check for "vowelness".
 * output: true, if _c_ is a vowel; false, otherwise.
 */
bool is_vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {


		return true;
	}

	return false;
}

/*
 * is_vowel
 *
 * Determine whether _c_ is a consonant. Note: 'y' is a consonant.
 *
 * input: c: The character to check for "consonantness".
 * output: true, if _c_ is a consonant; false, otherwise.
 */
bool is_consonant(char c) {
	if (!(is_vowel(c))) {
		return true;
	}
	return false;

}/*
 * ends_with_double_consonant
 *
 * Determine whether _str_ ends with the same two letters
 * and those letters are both consonants. If _str_ has fewer
 * than two letters, the result is false.
 *
 * input: _str_: The string to check for a double-consontant ending.
 * output: true, if the string ends in the same two letters *and*
 *         those letters are both consontants; false, otherwise.
 *         false, if the string is shorter than 2 characters long.
 */
bool ends_with_double_consonant(std::string str) {
	if (str.length() < 2) {
		return false;
	}
	char lastChar = str[str.length() - 1];
	char secondLastChar = str[str.length() - 2];
	if (is_consonant(lastChar) && is_consonant(secondLastChar) && (lastChar == secondLastChar)) {
		return true;
	}
	else {
		return false;
	}
}

/*
 * count_consonants_at_front
 *
 * Count the number of consecutive consonants at the
 * start of _str_.
 *
 * input: str: The string from which to count the number of
 *        consecutive consonants at the front.
 * output: the number of consecutive consonants at
 *         the front of _str_. Note: Uses is_consonant to
 *         determine whether a character is a consonant.
 */
int count_consonants_at_front(std::string str) {
	int count = 0;
	for (char c : str) {
		if (is_consonant(c)) {
			++count;
		}
		else {
			break;
		}
	}
	return count;
}

/*
 * count_vowels_at_back
 *
 * Count the number of consecutive vowels at the
 * end of _str_.
 *
 * input: str: The string from which to count the number of
 *        consecutive vowels at the end.
 * output: the number of consecutive consonants at
 *         the end of _str_. Note: Uses is_vowel to
 *         determine whether a character is a consonant.
 */
int count_vowels_at_back(std::string str) {
	int count = 0;
	for (int c = str.length() - 1; c >= 0; c--) {
		if (is_vowel(str.at(c))) {
			++count;
		}
		else {
			break;
		}
	}
	return count;
}


/*
 * ends_with_cvc
 *
 * Determine whether _str_ ends with the combination of
 * a consonant, a vowel and a consonant. If _str_ is shorter
 * than three characters, the function returns false.
 *
 * input: str: The string to test for a consonant, vowel,
 *        consonant ending.
 * output: true, if _str_ ends in a combination of a consonant,
 *         vowel and consonant. false, otherwise. If _str_ is
 *         shorter than three characters, ends_with_cvc will return
 *         false.
 */
bool ends_with_cvc(std::string str) {
	if (str.size() < 3)
		return false;
	char lastChar = str.at(str.length() - 1);
	char middleChar = str.at(str.length() - 2);
	char firstChar = str.at(str.length() - 3);

	if (is_consonant(firstChar) && is_vowel(middleChar) && is_consonant(lastChar)) {
		return true;
	}
	else {
		return false;
	}

}


/*
 * contains_vowel
 *
 * Determine whether _str_ contains a vowel. Note, this function
 * uses is_vowel to determine whether a character is a vowel.
 *
 * input: str: The string to test for containing a vowel.
 * output: true, if _str_ contains a vowel; false, otherwise. Note:
 *         this function uses is_vowel to determine whether a
 *         character is a vowel.
 */
bool contains_vowel(std::string str) {
	for (char c : str) {
		if (is_vowel(c)) {
			return true;
		}
	}
	return false;
}