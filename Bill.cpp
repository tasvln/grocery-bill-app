/*
  Name: Temitope Oladimeji Samuel Adebayo

  I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
*/

#include <iostream>
#include "cstring.h"
#include "Bill.h"

using namespace std;

namespace sdds {
  // Set Bill to an empty state
  void Bill::setEmpty() {
    m_title[0] = '\0';
    m_items = nullptr;
  }

  // Check if Bill is valid
  bool Bill::isValid() const {
    bool ok = true;
    int i = 0;

    if (m_title[0] != '\0' && m_items != nullptr) {
      for (i = 0; i < m_noOfItems; i++) {
        if (!m_items[i].isValid()) {
          ok = false;
        }
      }
    } else {
      ok = true;
    }

    return ok;
  }

  // Calculate total tax
  double Bill::totalTax() const {
    double total = 0.0;
    int i = 0;

    for (i = 0; i < m_noOfItems; i++) {
      total += m_items[i].tax();
    }

    return total;
  }

  // Calculate total price
  double Bill::totalPrice() const {
    double total = 0.0;
    int i = 0;

    for (i = 0; i < m_noOfItems; i++) {
      total += m_items[i].price();
    }

    return total;
  }

  // Display Bill title
  void Bill::Title() const {
    cout <<  "+--------------------------------------+" << endl;
    if (isValid()) {
      cout << "| ";
      cout.setf(ios::left);
      cout.width(36);
      cout << m_title;
      cout.unsetf(ios::left);
      cout << " |" << endl;
    } else {
      cout << "| Invalid Bill                         |" << endl;
    }

    cout << "+----------------------+---------+-----+" << endl;
    cout << "| Item Name            | Price   + Tax |" << endl;
    cout << "+----------------------+---------+-----+" << endl;
  }

  // Display Bill footer
  void Bill::footer() const {
    cout << "+----------------------+---------+-----+" << endl;

    if (isValid()) {
      cout << "|                Total Tax: ";
      cout.setf(ios::fixed);
      cout.precision(2);
      cout.width(10);
      cout << totalTax();
      cout << " |" << endl;
      cout << "|              Total Price: ";
      cout.width(10);
      cout << totalPrice();
      cout << " |" << endl;
      cout << "|          Total After Tax: ";
      cout.width(10);
      cout << totalTax() + totalPrice();
      cout << " |" << endl;
    } else {
      cout << "| Invalid Bill                         |" << endl;
    }

    cout << "+--------------------------------------+" << endl;
  }

  // Initialize Bill
  void Bill::init(const char* title, int noOfItems) {
    int i = 0;

    if (title == nullptr || noOfItems <= 0) {
      setEmpty();
    } else {
      m_noOfItems = noOfItems;
      m_itemsAdded = 0;
      strnCpy(m_title, title, 36);
      m_items = new Item[m_noOfItems];

      for (i = 0; i < m_noOfItems; i++) {
        m_items[i].setEmpty();
      }
    }
  } 

  // Add item to Bill
  bool Bill::add(const char* item_name, double price, bool taxed) {
    bool ok = false;

    if (m_itemsAdded < m_noOfItems) {
      m_items[m_itemsAdded].set(item_name, price, taxed);
      m_itemsAdded++;
      ok = true;
    }

    return ok;
  }

  // Display Bill
  void Bill::display() const {
    int i = 0;

    Title();
    for (i = 0; i < m_noOfItems; i++) {
      m_items[i].display();
    }
    footer();
  }

  // Deallocate Bill Dynamically Allocated Memory
  void Bill::deallocate() {
    delete[] m_items;
    m_items = nullptr;
  }
}