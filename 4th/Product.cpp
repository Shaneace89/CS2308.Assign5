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

/*****************************************************************************
 Product: Constructor creates default instance (with no inputs provided)
 returns: NO RETURN
 ****************************************************************************/

Product::Product() :locator(""), quantity(0), price(0), productName("") { }

/*****************************************************************************
 Product: Constructor creates instance (with inputs provided)
 returns: NO RETURN
 ****************************************************************************/

Product::Product(string loc, int quan, double pri, string name)
{
    setLocator(loc);
    setQuantity(quan);
    setPrice(pri);
    setProductName(name);
}

/*****************************************************************************
 isEqual: Compares agrument with instance provided
 string testName, passes of Name to be tested
 string testLoc, passes of Location to be tested
 returns: bool, TRUE only if both Name and Location are correct, else false
 ****************************************************************************/

bool Product::isEqual(string testName, string testLoc)
{
    return productName == testName && locator == testLoc;
}

/*****************************************************************************
 isEqualP: Compares agrument with instance provided
 Product other, passes instance of Product to be compared
 returns: bool, TRUE only if both Name and Location are correct, else false
        ****Had issues using isEqual in all instances needed****
 ****************************************************************************/

bool Product::isEqualP(const Product& other)
{
    return productName == other.productName && locator == other.locator;
}

/*****************************************************************************
 greaterThan: Checks if one name/loc is greater than another
 Product other, passes instance of Product to be compared
 returns: bool, true if name is greater, or if name same, but loc greater
 ****************************************************************************/

bool Product::greaterThan(const Product& other)
{
    if (productName == other.productName && locator > other.locator)
    {
        return locator > other.locator;
    }
    
    return productName > other.productName;
}