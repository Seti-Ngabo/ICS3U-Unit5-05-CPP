// Copyright (c) 2019 St. Mother Teresa HS All rights reserved.
//
// Created by: Seti Ngabo
// Created on: Oct 2021
// This program prints canadian address
//   with user input

#include <iostream>
#include <string>
#include <cstring>
#include <locale>
#include <algorithm>

std::string fullAddress(std::string fullNameString,
                        int streetNumber,
                        std::string streetTypeString,
                        std::string cityString,
                        std::string provinceString,
                        std::string postalCodeString,
                        int apartmentNumber = 0) {
    // This function turns letters into upper case
    std::string rightAddress;

    // process
    if (apartmentNumber != 0) {
        rightAddress = fullNameString
                     + "\n"
                     + std::to_string(apartmentNumber)
                     + "-"
                     + std::to_string(streetNumber)
                     + " "
                     + streetTypeString
                     + "\n"
                     + cityString
                     + " "
                     + provinceString
                     + "  "
                     + postalCodeString;
    } else {
        rightAddress = fullNameString
                     + "\n"
                     + std::to_string(streetNumber)
                     + " "
                     + streetTypeString
                     + "\n"
                     + cityString
                     + " "
                     + provinceString
                     + "  "
                     + postalCodeString;
    }

    std::for_each(rightAddress.begin(), rightAddress.end(),
    [](char & c) { c = ::toupper(c);});

    return rightAddress;
}

main() {
    // This function accepts inputs
    std::string location;
    std::string fullNameString;
    std::string questionString;
    std::string aptNumberString;
    int aptNumber;
    std::string streetNumberString;
    int streetNumber;
    std::string streetNameString;
    std::string cityString;
    std::string provinceString;
    std::string postalString;


    // input
    std::cout << "Enter your full name: ";
    getline(std::cin, fullNameString);
    std::cout << "Enter your street number: ";
    getline(std::cin, streetNumberString);
    std::cout << "Enter your street name: ";
    getline(std::cin, streetNameString);
    std::cout << "Do you live in an apartment? (y/n): ";
    getline(std::cin, questionString);
    if (questionString == "y" || questionString == "yes") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, aptNumberString);
    }
    std::cout << "Enter your city: ";
    getline(std::cin, cityString);
    std::cout << "Enter your province (ex: ON, BC..): ";
    getline(std::cin, provinceString);
    std::cout << "Enter your postal code (ex: K2A 123): ";
    getline(std::cin, postalString);
    std::cout << "" << std::endl;

    try {
        if (questionString == "y" || questionString == "yes") {
            aptNumber = std::stoi(aptNumberString);
        }
        streetNumber = std::stoi(streetNumberString);

        // call functions
        if (questionString != "") {
            location = fullAddress(fullNameString,
                                       streetNumber,
                                       streetNameString,
                                       cityString,
                                       provinceString,
                                       postalString,
                                       aptNumber);
        } else {
            location = fullAddress(fullNameString,
                                       streetNumber,
                                       streetNameString,
                                       cityString,
                                       provinceString,
                                       postalString);
        }

        std::cout << location << std::endl;
    } catch (std::invalid_argument) {
        // output
        std::cout << "Fix your street number or street name." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
