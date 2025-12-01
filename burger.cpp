/* Program name: burger.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/30/2025
 * Purpose: Implements the burger class functionality such as pricing computation, vegetarian check, and formatting.
 */ 
#include "burger.h"
#include <iostream>
#include <cctype>
#include <algorithm>

// Part 2: Initialize static maps
std::map<proteinType, std::string> burger::proteinToString = {
    {BEEF, "Beef"}, {TURKEY, "Turkey"}, {CHICKEN, "Chicken Breast"}, {MUSH, "Portabella Mushroom"}, {VEGGIE, "Veggie"}
};
std::map<std::string, proteinType> burger::stringToProtein = {
    {"beef", BEEF}, {"turkey", TURKEY}, {"chicken breast", CHICKEN}, {"portabella mushroom", MUSH}, {"veggie", VEGGIE}
};

std::map<condimentType, std::string> burger::condimentToString = {
    {KETCHUP, "Ketchup"}, {MUSTARD, "Mustard"}, {MAYO, "Mayonnaise"}, {SPECIAL, "Special Sauce"}, {BBQ, "BBQ Sauce"}, {STEAK, "Steak Sauce"}, {PEPPERCORN, "Peppercorn Ranch"}, {NOCOND, "None"}
};
std::map<std::string, condimentType> burger::stringToCondiment = {
    {"ketchup", KETCHUP}, {"mustard", MUSTARD}, {"mayonnaise", MAYO}, {"special sauce", SPECIAL}, {"bbq sauce", BBQ}, {"steak sauce", STEAK}, {"peppercorn ranch", PEPPERCORN}, {"none", NOCOND}
};

std::map<toppingType, std::string> burger::toppingToString = {
    {GRILLONION, "Grilled Onion"}, {RAWONION, "Raw Onion"}, {TOMATO, "Tomato"}, {LETTUCE, "Lettuce"}, {BACON, "Bacon"}, {MUSHROOM, "Grilled Mushroom"}, {PICKLE, "Pickle"}, {NOTOP, "None"}
};
std::map<std::string, toppingType> burger::stringToTopping = {
    {"grilled onion", GRILLONION}, {"raw onion", RAWONION}, {"tomato", TOMATO}, {"lettuce", LETTUCE}, {"bacon", BACON}, {"grilled mushroom", MUSHROOM}, {"pickle", PICKLE}, {"none", NOTOP}
};

std::map<bunType, std::string> burger::bunToString = {
    {BRIOCHE, "Brioche"}, {WHEAT, "Wheat"}, {SESAME, "Sesame"}, {ONION, "Onion"}, {RYE, "Rye Bread"}, {NOBUN, "None"}, {GLUTENFREE, "Gluten Free"}
};
std::map<std::string, bunType> burger::stringToBun = {
    {"brioche", BRIOCHE}, {"wheat", WHEAT}, {"sesame", SESAME}, {"onion", ONION}, {"rye bread", RYE}, {"none", NOBUN}, {"gluten free", GLUTENFREE}
};

std::map<cheeseType, std::string> burger::cheeseToString = {
    {CHEDDAR, "Cheddar"}, {AMERICAN, "American"}, {PEPPERJACK, "Pepper Jack"}, {SWISS, "Swiss"}, {COLBYJACK, "Colby Jack"}, {NOCHEESE, "None"}
};
std::map<std::string, cheeseType> burger::stringToCheese = {
    {"cheddar", CHEDDAR}, {"american", AMERICAN}, {"pepper jack", PEPPERJACK}, {"swiss", SWISS}, {"colby jack", COLBYJACK}, {"none", NOCHEESE}
};

// Converts a string to lowercase for case-insensitive comparisons
std::string burger::toLower(const std::string &input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c){ return std::tolower(c); });
    return result;
}
// Constructor
burger::burger(proteinType p, condimentType c[], int cCount, toppingType t[], int tCount, bunType b, cheeseType ch, int patties) {
    protein = p;
    bun = b;
    cheese = ch;
    numPatties = (patties < 1) ? 1 : patties;

    numCondiments = (cCount >= 0 && cCount <= 7) ? cCount : 0;
    for (int i = 0; i < numCondiments; i++) condiments[i] = c[i];

    numToppings = (tCount >= 0 && tCount <= 7) ? tCount : 0;
    for (int i = 0; i < numToppings; i++) toppings[i] = t[i];

    vegetarian = (protein == MUSH || protein == VEGGIE);
    for (int i = 0; i < numToppings; i++) if (toppings[i] == BACON) vegetarian = false;
}

// Getters
proteinType burger::getProtein() const { return protein; }
bunType burger::getBun() const { return bun; }
cheeseType burger::getCheese() const { return cheese; }
int burger::getNumPatties() const { return numPatties; }
bool burger::isVegetarian() const { return vegetarian; }

std::string burger::getCondiments() const {
    std::string result;
    for (int i = 0; i < numCondiments; i++) {
        result += condimentToString[condiments[i]];
        if (i < numCondiments - 1) result += ", ";
    }
    return result.empty() ? "None" : result;
}

std::string burger::getToppings() const {
    std::string result;
    for (int i = 0; i < numToppings; i++) {
        result += toppingToString[toppings[i]];
        if (i < numToppings - 1) result += ", ";
    }
    return result.empty() ? "None" : result;
}

// Setters
void burger::setProtein(proteinType p) {
    protein = p;
    vegetarian = (protein == MUSH || protein == VEGGIE);
    for (int i = 0; i < numToppings; i++) if (toppings[i] == BACON) vegetarian = false;
}

void burger::setCondiments(condimentType c[], int count) {
    numCondiments = (count >= 0 && count <= 7) ? count : 0;
    for (int i = 0; i < numCondiments; i++) condiments[i] = c[i];
}

void burger::setToppings(toppingType t[], int count) {
    numToppings = (count >= 0 && count <= 7) ? count : 0;
    for (int i = 0; i < numToppings; i++) toppings[i] = t[i];
    vegetarian = (protein == MUSH || protein == VEGGIE);
    for (int i = 0; i < numToppings; i++) if (toppings[i] == BACON) vegetarian = false;
}

void burger::setBun(bunType b) { bun = b; }
void burger::setCheese(cheeseType ch) { cheese = ch; }
void burger::setNumPatties(int patties) { numPatties = (patties < 1) ? 1 : patties; }

// Price calculation
double burger::getPrice() const {
    double price = 3.5 * numPatties; // base price
    price += 0.50 * numToppings;
    price += 0.25 * numCondiments;
    if (cheese != NOCHEESE) price += 0.10;
    return price;
}

// tostring
std::string burger::tostring() {
    std::string result;
    result += "Protein: " + proteinToString[protein] + "\n";
    result += "Number of patties: " + std::to_string(numPatties) + "\n";
    result += "Bun Type: " + bunToString[bun] + "\n";
    result += "Cheese: " + cheeseToString[cheese] + "\n";
    result += "Condiments: " + getCondiments() + "\n";
    result += "Toppings: " + getToppings() + "\n";
    if (vegetarian) result += "This is a vegetarian burger.\n";
    return result;
}
