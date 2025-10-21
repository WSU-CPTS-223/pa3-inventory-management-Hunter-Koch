#include "HashTableProducts.h"
HashTableProducts::HashTableProducts(){
    table.resize(23);
    numProducts = 0;
}

void HashTableProducts::addProduct(Product &_product){
   // auto itr = _product.getCategories().begin();
    int index = 0;
    for (const string &cat : _product.getCategories())
    {
        index = productHash(cat);
        // insert
        insert(_product, index);
    }
}

int HashTableProducts::productHash(const string &_category)
{
    // std::transform(_category.begin(), _category.end(), _category.begin(), ::tolower);
    int hashVal = 0;
    for (unsigned int i = 1; i <= _category.size(); i++)
    {
        hashVal += _category[i - 1] * i;
    }
    hashVal = hashVal % table.size();

    /*
    bool doesContain = false;//does the array of products contain the categeroy we are looking for?

    //if
    if (table[hashVal][0].getID() != 0)
    {
        for (const string &cat: table[hashVal][0].getCategories()){
            if (cat == _category){
                doesContain = true;
            }
        }
    }*/
    return hashVal;
}

void HashTableProducts::insert(Product &_product, int index)
{
    if (table.size() > table.capacity())
    {
        //rehash
    }
    int thisID = _product.getID();
    auto itr = table[index].begin();
    while (itr->getID() < thisID && itr != table[index].end()){
        itr++;
    }
    
    table[index].emplace(itr, _product);
}