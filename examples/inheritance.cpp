#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "class_definition.h"
#include "object.h"
#include "attribute.h"
#include "value.h"
#include "type.h"

int main()
{
    Type::init();

    // Define a base class
    ClassDef * product = new ClassDef(0, "Product");
    product->addAttribute(Attribute("Product Number", Type::intT));
    product->addAttribute(Attribute("Name", Type::stringT));
    product->addAttribute(Attribute("Price", Type::doubleT));
    product->addAttribute(Attribute("Weight", Type::doubleT));

    // Create a list of attributes
    list<Attribute> attrL;
    attrL.push_back(Attribute("Author", Type::stringT));
    attrL.push_back(Attribute("Title", Type::stringT));
    attrL.push_back(Attribute("ISBN", Type::intT));

    // Define a derived class with the above list of attributes
    ClassDef * book = new ClassDef(product, "Book", attrL.begin(), attrL.end());
    
    // Display the attributes of the derived class
    cout<<"Class: Book\n";
    ClassDef::AttrIterator a;
    size_t idx;
    for (a = book->attribBegin(), idx = 0;a != book->attribEnd(); ++a, ++idx)
    {
        string attr_name = (*a).getName();
        int type_id = (*a).getType();
        cout << attr_name << ": "<< type_id <<"\n";
    }
    cout<<"------------------------------------------------\n";

    // Create a derived class object
    Object * book_obj(book->newObject());
	book_obj->setValue("Product Number", RealValue<int>(12345));
	book_obj->setValue("Author", RealValue<string>("Robert Kanigel"));
	book_obj->setValue("Title", RealValue<string>("The Man who knew Infinity"));
    book_obj->setValue("Weight", RealValue<double>(150));

    // Display the derived class object
    cout<<"Object of Book: \n";
    for (a = book_obj->instanceOf().attribBegin(), idx = 0;a != book_obj->instanceOf().attribEnd(); ++a, ++idx)
    {
        string attr_name = (*a).getName();
        cout << attr_name << ": "
             << book_obj->getValue(attr_name)->asString() << endl;
    }

    return 0;
}