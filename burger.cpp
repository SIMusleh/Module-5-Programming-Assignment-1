/* Program name: burger.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/30/2025
 * Purpose: Implements the burger class functionality such as pricing computation, vegetarian check, and formatting.
 */

#include "burger.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>

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
    std::transform(result.begin(), result.end(), result.begin(),
                    { return std::tolower(c); });

    return result;
}
