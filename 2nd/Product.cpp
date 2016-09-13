/*File Name: Product.cpp
 
 Author: Shane Fleming
 Date: 03/30/16
 Assignment Number: 5
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Store Inventory, Two constructors and functions for comparing*/

#include <iomanip>
#include <sstream>
using namespace std;

#include "Product.h"


// class function implementations

Product::Product() :
    locator(""), quantity(0), price(0), productName("") { }

Product::Product(string loc, int quan, double pri, string name)
{
    setLocator(loc);
    setQuantity(quan);
    setPrice(pri);
    setProductName(name);
    
    /*
    locator = loc;
    quantity = quan;
    price = pri;
    productName = name;
    */
}

bool Product::isEqual(const Product& other)
{
    return productName == other.productName && locator == other.locator;
}

bool Product::greaterThan(const Product& other)
{
    if (productName == other.productName && locator > other.locator) {
        return locator > other.locator;
    }
        
    return productName > other.productName;
}