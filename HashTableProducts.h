#include <iostream>
#include <cctype>
#include <algorithm>
#include "Product.h"
using std::cout;
class HashTableProducts
{
private:
    vector<vector<Product>> table;
    int numProducts;

public:
    HashTableProducts();
    void addProduct(Product &_product);

    int productHash(const string &_category);

    void insert( Product &_product, int index);
    
};