/*File Name: ProductInventory.cpp
 
 Author: Shane Fleming
 Date: 03/30/16
 Assignment Number: 5
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Store Inventory, One constructors and functions for editing inventory*/

#include <iostream>
using namespace std;

#include "ProductInventory.h"

ProductInventory::ProductInventory(int s)
{
    size = s;
    products = new Product[size];
}

ProductInventory::~ProductInventory() {
    // Destroy products array
    delete[] products;
}

bool ProductInventory::addProduct(Product p)
{
    // Price or quantity is invalid
    if(!p.isValid()) {
        return false;
    }
    
    // Already have this
    for(int i = 0; i < count; i++) {
        if(products[i].isEqual(p)) {
            return false;
        }
    }
    
    // Resize
    if(count == size) {
        resize();
    }
    
    // Set the last product to p and increment count
    products[count++] = p;
    
    return true;
}

bool ProductInventory::removeProduct(const Product& p)
{
    // Decrement count
    for(int i = 0; i < count; i++) {
        if(products[i].isEqual(p)) {
            // Remove
            products[i] = products[--count];
            
            return true;
        }
    }
    
    return false;
}

void ProductInventory::showInventory()
{
    for(int i = 0; i < count; i++)
    {
        cout << products[i].getLocator()
        << "\t" << products[i].getQuantity()
        << "\t" << products[i].getPrice()
        << "\t" << products[i].getProductName() << endl;
    }
}

void ProductInventory::sortIventory()
{
    
}

int ProductInventory::getTotalQuantity()
{
    int sum = 0;
    
    for(int i = 0; i < count; i++) {
        sum += products[i].getQuantity();
    }
    
    return sum;
}

void ProductInventory::resize()
{
    Product* temp = products;
    
    size = size * 2;
    products = new Product[size];
    
    for(int i = 0; i < count; i++) {
        products[i] = temp[i];
    }
    
    delete[] temp;
}