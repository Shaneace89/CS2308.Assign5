/*File Name: ProductInventory.cpp
 
 Author: Shane Fleming
 Date: 03/30/16
 Assignment Number: 5
 CS 2308.257 Spring 2016
 Instructor: Jill Seaman
 
 Store Inventory, One constructors and functions for editing inventory*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "ProductInventory.h"


/*****************************************************************************
 ProductInventory: Constructor creates array of Products the desired size
 int s, size input from Driver
 returns: NO RETURN
 ****************************************************************************/

ProductInventory::ProductInventory(int s)
{
    size = s;
    products = new Product[size+1]; //+1 for sort temp
}

/*****************************************************************************
 ~ProductInventory: Destroy products array
 returns: NO RETURN
 ****************************************************************************/

ProductInventory::~ProductInventory()
{
    delete[] products;
}

/*****************************************************************************
 addProduct: Inpute validation, call resize if full
 Product p, passes Product as p
 returns: bool, false if duplicate, or not "invalid", else true
 ****************************************************************************/

bool ProductInventory::addProduct(Product p)
{
    // Price or quantity is invalid
    if(!p.isValid())
    {
        return false;
    }
    
    // Already have this
    for(int i = 0; i < count; i++)
    {
        if(products[i].isEqualP(p))
        {
            return false;
        }
    }
    
    // Resize
    if(count == size)
    {
        resize();
    }
    
    // Set the last product to p and increment count
    products[count++] = p;
    
    return true;
}

/*****************************************************************************
 removeProduct: removes desired product
 string testName, passes name for desired remove product
 string testLoc, passes location for desired remove product
 returns: bool, if found returns true, else false
 ****************************************************************************/

bool ProductInventory::removeProduct(string testName, string testLoc)
{
    // Decrement count
    for(int i = 0; i < count; i++)
    {
        if(products[i].isEqual(testName, testLoc))
        {
            // Remove
            products[i] = products[--count];
            
            return true;
        }
    }
    
    return false;
}

/*****************************************************************************
 showInventory: displays all of inventory
 returns: NO RETURN Void Function
 ****************************************************************************/

void ProductInventory::showInventory()
{
    for(int i = 0; i < count; i++)
    {
        cout << products[i].getLocator()
        << "\t" << products[i].getQuantity();
        cout << setprecision(2) << fixed;
        cout << "\t" << products[i].getPrice();
        cout << setprecision(1) << fixed;
        cout << "\t" << products[i].getProductName() << endl;
    }
}

/*****************************************************************************
 sortInventory: sorts inventory
 returns: NO RETURN Void Function
 ****************************************************************************/

void ProductInventory::sortInventory()
{
    
    int y = 1;  //counters to cycle array
    
    for(int i = 0; i < count; i++)
    {
        if(products[y].greaterThan(products[i]))
        {
            products[size+1] = products[i];
            products[i] = products[y];
            products[y] = products[size+1];
            y++;
        }
        else
            y++;
    }
}

/*****************************************************************************
 getTotal: adds the quantity of all products
 returns: sum of all quantity
 ****************************************************************************/

int ProductInventory::getTotalQuantity()
{
    int sum = 0;    //sum of all quantity
    
    for(int i = 0; i < count; i++)
    {
        sum += products[i].getQuantity();
    }
    
    return sum;
}

/*****************************************************************************
 resize: doubles the size of the array
 returns: NO RETURN Void Function
 ****************************************************************************/

void ProductInventory::resize()
{
    Product* temp = products;
    
    size = size * 2;
    products = new Product[size+1]; //+1 for sort temp
    
    for(int i = 0; i < count; i++)
    {
        products[i] = temp[i];
    }
    
    delete[] temp;
}