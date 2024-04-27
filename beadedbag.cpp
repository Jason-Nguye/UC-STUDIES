#include <algorithm>
#include "beadedbag.h"
#include "item.h"
#include <vector>

// Implement the BeadedBag::size and BeadedBag::insert member functions here.
int BeadedBag::size() {
	return lost.size();
}

void BeadedBag::insert(Item to_insert) {
	if (!contains(to_insert)) {
		//since were in a vector would it be pushback or something i forgot
		lost.push_back(to_insert);
	}
}



// Complete the implementation of the BeadedBag::contains member function.

bool BeadedBag::contains(Item maybe_contained_item) {
// if contains ( maybe_contained_item ) could work?... would it need &?...
//anyways skip for now
//  wait do we need a for loop to read every item, id assume so but we would need size in theory
// 	but this for loop alone doesnt read directly from the item thing
	for (int i = 0; i - lost.size(); i++) {
		if (maybe_contained_item.isEqual(lost[i])) {
			return true;
		}
	}
return false;
//return im lost
}			   						  
									  