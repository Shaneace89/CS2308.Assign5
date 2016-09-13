/*File Name: Product.h
 
 Author: Shane Fleming
 Date: 03/30/16
 Assignment Number: 5
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Store Inventory, Header file for class Product*/

#include <string>
using namespace std;

class Product
{
private:
    string productName;
    string locator;
    int quantity;
    double price;
    
public:
    // Constructors
    Product();
    Product(string, int, double, string);
    
    // Comparators
    bool isEqual(const Product&);
    bool greaterThan(const Product&);
    
    // Helper
    inline bool isValid() { return quantity >= 0 && price > 0; }
    
    // Getters
    inline string getProductName() { return productName; }
    inline string getLocator() { return locator; }
    inline int getQuantity() { return quantity; }
    inline double getPrice() { return price; }
    
    // Setters
    inline void setProductName(string name) { productName = name; }
    inline void setLocator(string loc) { locator = loc; }
    inline void setQuantity(int quant) { quantity = quant; }
    inline void setPrice(double p) { price = p; }
};
