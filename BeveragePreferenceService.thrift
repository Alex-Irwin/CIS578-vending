// vendingmachine_tutorial/BeveragePreferenceService.thrift

namespace cpp BeveragePreferenceService

include "vending_machine.thrift" // Include the vending_machine.thrift file to access BeverageType

service BeveragePreferenceService {
  string getBeverage(1: vending_machine.BeverageType btype)
}
