#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "../src/class_definition.h"
#include "../src/object.h"
#include "../src/attribute.h"
#include "../src/value.h"
#include "../src/type.h"

int main()
{
    Type::init();
    
    // Define a class
    ClassDef * product = new ClassDef(0, "Product");
    product->addAttribute(Attribute("Product Number", Type::intT));
    product->addAttribute(Attribute("Name", Type::stringT));
    product->addAttribute(Attribute("Price", Type::doubleT));
    product->addAttribute(Attribute("Weight", Type::doubleT));

    // Display class information
    cout<<"Display class: Product\n";
    ClassDef::AttrIterator a;
    size_t idx;
    for (a = product->attribBegin(), idx = 0;a != product->attribEnd(); ++a, ++idx)
    {
        string attr_name = (*a).getName();
        int type_id = (*a).getType();
        cout << attr_name << ": "<< type_id <<"\n";
    }


    // Create an object
    Object * prod_obj(product->newObject());
    prod_obj->setValue("Name", RealValue<string>("Laptop"));
    prod_obj->setValue("Price", RealValue<double>(50000));
    prod_obj->setValue("Product Number", RealValue<int>(2147));
    prod_obj->setValue("Weight", RealValue<double>(2500));

    // Display object attributes and its values
    cout<<"Object of Product:\n";
    for (a = prod_obj->instanceOf().attribBegin(), idx = 0;a != prod_obj->instanceOf().attribEnd(); ++a, ++idx)
    {
        string attr_name = (*a).getName();
        cout << attr_name << ": "
             << prod_obj->getValue(attr_name)->asString() << endl;
    }

    return 0;
}