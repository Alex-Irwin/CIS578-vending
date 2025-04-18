// src/BeveragePreferenceService/BeveragePreferenceHandler.h
#ifndef BEVERAGEPREFERENCEHANDLER_H
#define BEVERAGEPREFERENCEHANDLER_H

#include "../gen-cpp/vending_machine_types.h" // Correct include path
#include "../gen-cpp/BeveragePreferenceService.h" // Correct include path
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <random>
#include <vector>
#include <iostream>

namespace vending_machine { // Correct namespace

class BeveragePreferenceHandler : virtual public vending_machine::BeveragePreferenceServiceIf {
public:
    BeveragePreferenceHandler() {}

    void getBeverage(std::string& _return, const ::vending_machine::BeverageType::type btype) override { // MATCH THE GENERATED SIGNATURE EXACTLY
        std::cout << "getBeverage called with BeverageType: " << btype << std::endl; // Debugging

        if (btype == ::vending_machine::BeverageType::HOT) { // Correct enum value
            std::vector<std::string> hot_beverages = {"cappuccino", "latte", "espresso"};
            _return = hot_beverages[rand() % hot_beverages.size()];
        } else { // Assume anything else is COLD
            std::vector<std::string> cold_beverages = {"lemonade", "ice tea", "soda"};
            _return = cold_beverages[rand() % cold_beverages.size()];
        }
        std::cout << "Selected beverage: " << _return << std::endl; // Debugging
    }
};

std::ostream& operator<<(std::ostream& os, const BeverageType::type& btype) {
    switch (btype) {
        case BeverageType::HOT:
            os << "HOT";
            break;
        case BeverageType::COLD:
            os << "COLD";
            break;
        default:
            os << "UNKNOWN";
            break;
    }
    return os;
}

} // namespace vending_machine


#endif
