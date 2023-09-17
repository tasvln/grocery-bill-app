/*
  Name: Temitope Oladimeji Samuel Adebayo

  I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Item.h"

using namespace std;

namespace sdds {
  // Set Item Name
  void Item::setName(const char *name) {
    strnCpy(m_itemName, name, 20);
    m_itemName[20] = '\0';
  }

  // Set Item to an empty state
  void Item::setEmpty() {
    m_price = 0.0;
    m_itemName[0] = '\0';
  }

  // Set Item
  void Item::set(const char* name, double price, bool taxed){
    if (price < 0 || name == nullptr) {
      setEmpty();
    }
    else {
      setName(name);
      m_price = price;
      m_taxed = taxed;
    }
  }

  // Return Item Price
  double Item::price() const {
    return m_price;
  }

  // Return Item Tax
  double Item::tax() const {
    double tax = 0.0;
    const double taxRate = 0.13;

    if (m_taxed) {
      tax = m_price * taxRate;
    }

    return tax;
  }

  // Check if Item is valid
  bool Item::isValid() const {
    bool valid = false;

    if (m_itemName[0] != '\0' && m_price > 0) {
      valid = true;
    }

    return valid;
  }

  // Display Item
  void Item::display() const {
    if (isValid()) {
      cout << "| ";
      cout.width(20);
      cout.setf(ios::left);
      cout.fill('.');
      cout << m_itemName;

      cout.unsetf(ios::left);
      cout << " | ";
      cout.width(7);
      cout.setf(ios::fixed);
      cout.precision(2);

      cout.fill(' ');
      cout << m_price;
      cout.unsetf(ios::fixed);

      cout << " | ";
      if (m_taxed) {
        cout << "Yes";
      }
      else {
        cout << "No ";
      }
      cout << " |" << endl;
    }
    else {
      cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
    }
  }
}