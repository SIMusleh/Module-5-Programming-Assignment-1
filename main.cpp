
/* Program name: main.cpp
 * Author: Sahar Musleh
 * Date last updated: 11/30/2025
 * Purpose: Placeholder main file for burger assignment. The actual main function is provided by the instructor for testing.
 */

#include <iostream>
#include <vector>
#include "burger.h"

// Loop to allow user to create multiple burgers
int main() {
    std::vector<burger> orders;
    char more = 'y';

    while (tolower(more) == 'y') {
        int patties;
        std::cout << "How many patties do you want on your burger?\n";
        std::cin >> patties;
        std::cin.ignore();

        std::string input;
        // Prompt user for protein type and validate input using case-insensitive map
        std::cout << "Please enter a protein:\n";
        std::getline(std::cin, input);
        proteinType protein = BEEF;
        if (burger::stringToProtein.find(burger::toLower(input)) != burger::stringToProtein.end()) {
            protein = burger::stringToProtein[burger::toLower(input)];
        } else {
            std::cout << "Invalid protein. Defaulting to Beef.\n";
        }

        // Collect condiments from user until they enter -1
        condimentType conds[7]; int cCount = 0;
        std::cout << "Please enter a Condiment. Enter -1 to move to the next step\n";
        while (true) {
            std::getline(std::cin, input);
            if (input == "-1") break;
            std::string lower = burger::toLower(input);
            if (burger::stringToCondiment.find(lower) != burger::stringToCondiment.end()) {
                conds[cCount++] = burger::stringToCondiment[lower];
            } else {
                std::cout << "Invalid condiment. Try again.\n";
            }
        }

        // Collect toppings from user until they enter -1
        toppingType tops[7]; int tCount = 0;
        std::cout << "Please enter a Topping. Enter -1 to move to the next step\n";
        while (true) {
            std::getline(std::cin, input);
            if (input == "-1") break;
            std::string lower = burger::toLower(input);
            if (burger::stringToTopping.find(lower) != burger::stringToTopping.end()) {
                tops[tCount++] = burger::stringToTopping[lower];
            } else {
                std::cout << "Invalid topping. Try again.\n";
            }
        }
 // Prompt user for bun type and validate input
        std::cout << "Please enter a bun:\n";
        std::getline(std::cin, input);
        bunType bun = BRIOCHE;
        if (burger::stringToBun.find(burger::toLower(input)) != burger::stringToBun.end()) {
            bun = burger::stringToBun[burger::toLower(input)];
        }

        // Prompt user for cheese type and validate input
        std::cout << "Please enter a cheese:\n";
        std::getline(std::cin, input);
        cheeseType cheese = CHEDDAR;
        if (burger::stringToCheese.find(burger::toLower(input)) != burger::stringToCheese.end()) {
            cheese = burger::stringToCheese[burger::toLower(input)];
        }

        // Create burger object with user-selected options
        burger b(protein, conds, cCount, tops, tCount, bun, cheese, patties);
        
        // Display the details of the created burger
        std::cout << b.tostring() << "\n";
        
        // Menu to allow user to edit burger after creation (options 1–7)
        int choice;
        do {
            std::cout << "Would you like to change the burger? Please choose from the menu.\n";
            std::cout << "1. Change Protein\n2. Change Number of Patties\n3. Change Toppings\n4. Change Cheese\n5. Change Bun\n6. Change Condiments\n7. No Changes\n";
            std::cin >> choice;
            std::cin.ignore();

            if (choice == 1) {
                // Handle protein change
                std::cout << "Please enter a protein:\n";
                std::getline(std::cin, input);
                if (burger::stringToProtein.find(burger::toLower(input)) != burger::stringToProtein.end()) {
                    b.setProtein(burger::stringToProtein[burger::toLower(input)]);
                }
            } else if (choice == 2) {
            std::cout << "Enter new number of patties:\n";
                std::cin >> patties;
                std::cin.ignore();
                b.setNumPatties(patties);
            } else if (choice == 3) {
                tCount = 0;
                std::cout << "Enter new toppings. Enter -1 to stop.\n";
                while (true) {
                    std::getline(std::cin, input);
                    if (input == "-1") break;
                    if (burger::stringToTopping.find(burger::toLower(input)) != burger::stringToTopping.end()) {
                        tops[tCount++] = burger::stringToTopping[burger::toLower(input)];
                    }
                }
                b.setToppings(tops, tCount);
            } else if (choice == 4) {
                std::cout << "Enter new cheese:\n";
                std::getline(std::cin, input);
                if (burger::stringToCheese.find(burger::toLower(input)) != burger::stringToCheese.end()) {
                    b.setCheese(burger::stringToCheese[burger::toLower(input)]);
                }
            } else if (choice == 5) {
                std::cout << "Enter new bun:\n";
                std::getline(std::cin, input);
                if (burger::stringToBun.find(burger::toLower(input)) != burger::stringToBun.end()) {
                    b.setBun(burger::stringToBun[burger::toLower(input)]);
                }
            } else if (choice == 6) {
                cCount = 0;
                std::cout << "Enter new condiments. Enter -1 to stop.\n";
                while (true) {
                    std::getline(std::cin, input);
                    if (input == "-1") break;
                    if (burger::stringToCondiment.find(burger::toLower(input)) != burger::stringToCondiment.end()) {
                        conds[cCount++] = burger::stringToCondiment[burger::toLower(input)];
                    }
                }
                b.setCondiments(conds, cCount);
            }
        } while (choice != 7);
        
        // Add burger to orders list
        orders.push_back(b);

        // Ask if user wants to create another burger
        std::cout << "Do you want to enter another burger? (y/n): ";
        std::cin >> more;
        std::cin.ignore();
    }

    // Display all burgers ordered by the user
    std::cout << "You have ordered " << orders.size() << " burgers.\n";
    for (auto &b : orders) {
        std::cout << b.tostring() << "\n";
    }
    return 0;
}
