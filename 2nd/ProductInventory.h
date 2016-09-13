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
    int size;
    int count;
    Product* products;
    
public:
    ProductInventory(int);
    ~ProductInventory();
    bool addProduct(Product);
    bool removeProduct(const Product&);
    void showInventory();
    void sortIventory();
    int getTotalQuantity();
    void resize();
};