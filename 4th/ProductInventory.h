/*File Name: Product.cpp
 
 Author: Shane Fleming
 Date: 03/30/16
 Assignment Number: 5
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Store Inventory, Header file for class ProductIventory*/

#include "Product.h"

class ProductInventory
{
private:
    int size;               //size of the array
    int count;              //total count of products
    Product* products;      //pointer of type Product to point to Product array
    
public:
    // Constructor
    ProductInventory(int);
    
    // Destructor
    ~ProductInventory();
    
    // Modifiers
    bool addProduct(Product);
    bool removeProduct(string, string);
    void showInventory();
    void sortInventory();
    int getTotalQuantity();
    void resize();
};