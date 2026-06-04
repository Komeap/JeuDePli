#include "Card.h"


std::string Card::toString() const {
	return rank + " de " + suit;
}