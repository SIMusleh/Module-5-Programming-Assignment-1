/* Program name: burger.h
 * Author: Sahar Musleh
 * Date last updated: 11/30/2025
 * Purpose: Declares the burger class and details required to create a customisable burger.
 */

#ifndef BURGER_H
#define BURGER_H

#include <string>
#include <map>
#include <algorithm>

// Enum for protein types available for burgers
enum proteinType { BEEF, TURKEY, CHICKEN, MUSH, VEGGIE };

// Enum for condiment types
enum condimentType { KETCHUP, MUSTARD, MAYO, SPECIAL, BBQ, STEAK, PEPPERCORN, NOCOND };

// Enum for topping types
enum toppingType { GRILLONION, RAWONION, TOMATO, LETTUCE, BACON, MUSHROOM, PICKLE, NOTOP };

// Enum for bun types
enum bunType { BRIOCHE, WHEAT, SESAME, ONION, RYE, NOBUN, GLUTENFREE };

// Enum for cheese types
enum cheeseType { CHEDDAR, AMERICAN, PEPPERJACK, SWISS, COLBYJACK, NOCHEESE };

class burger {
private:
    proteinType protein;
    condimentType condiments[7];
    toppingType toppings[7];
    bunType bun;
    cheeseType cheese;
    int numPatties;
    bool vegetarian;
    int numCondiments;
    int numToppings;

public:
    // Constructor
    burger(proteinType protein, condimentType condiments[], int numCondiments,
           toppingType toppings[], int numToppings, bunType bun,
           cheeseType cheese, int numPatties);

    // Getters
    proteinType getProtein() const;
    std::string getCondiments() const;
    std::string getToppings() const;
    bunType getBun() const;
    cheeseType getCheese() const;
    bool isVegetarian() const;
    int getNumPatties() const;
    double getPrice() const;

    // Setters
    void setProtein(proteinType);
    void setCondiments(condimentType[], int);
    void setToppings(toppingType[], int);
    void setBun(bunType);
    void setCheese(cheeseType);
    void setNumPatties(int);

    // Other
    std::string tostring();

    // Part 2: Static maps for enum-string conversions
    static std::map<proteinType, std::string> proteinToString;
    static std::map<std::string, proteinType> stringToProtein;

    static std::map<condimentType, std::string> condimentToString;
    static std::map<std::string, condimentType> stringToCondiment;

    static std::map<toppingType, std::string> toppingToString;
    static std::map<std::string, toppingType> stringToTopping;

    static std::map<bunType, std::string> bunToString;
    static std::map<std::string, bunType> stringToBun;

    static std::map<cheeseType, std::string> cheeseToString;
    static std::map<std::string, cheeseType> stringToCheese;

    // Helper function to convert strings to lowercase
    static std::string toLower(const std::string &input);
};

#endif
