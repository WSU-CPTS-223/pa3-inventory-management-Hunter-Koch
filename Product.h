#include <string>
#include <vector>
using std::string;
using std::vector;

class Product
{
private:
    int uniqueID;
    string productName;
    vector<string> categories;

    public:
    Product(){
        uniqueID = 0;
        productName = "";
        //categories;
    }

    int getID(){ return uniqueID; }
    string getProductName() { return productName; }
    vector<string>& getCategories() { return categories; }

    void setID(int &_id) { uniqueID = _id; }
    void setProductName(string &_name) { productName = _name; }
    void addCategory(string &_categoroy) { categories.push_back(_categoroy); }
};