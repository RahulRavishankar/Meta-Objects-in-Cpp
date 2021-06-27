#include <vector>
#include <string>
#include <cassert>
#include "class_definition.h"
#include "object.h"
#include "type.h"
#include "value.h"

Object::Object(const ClassDef* class_)
: myClass(class_), values(class_->getAttributeCount())
{
    buildValueList();
}

ClassDef const & Object::instanceOf() const
{
    return *myClass;
}

BaseValue* Object::getValue(size_t attribIdx) const
{
    return values[attribIdx];
}

BaseValue* Object::getValue(string const & attribName) const
{
    size_t idx = instanceOf().findAttribute(attribName);
    if(idx==instanceOf().getAttributeCount())
    {
    	std::cout << "Attribute not found" << std::endl;
    	assert(idx!=instanceOf().getAttributeCount());
    }
    return getValue(idx);
}

void Object::setValue(size_t idx, BaseValue const& v)
{
    values[idx]->set(v);
}

void Object::setValue(string const & attribName, BaseValue const& v)
{
    size_t idx = instanceOf().findAttribute(attribName);
    if(idx==instanceOf().getAttributeCount())
    {
    	std::cout << "Attribute not found" << std::endl;
    	assert(idx!=instanceOf().getAttributeCount());
    }
    setValue(idx, v);
}

void Object::buildValueList()
{
    ClassDef::AttrIterator a;
    ValueContainer::iterator i = values.begin();
    for (a = instanceOf().attribBegin(); a != instanceOf().attribEnd(); ++a, ++i)
    {
        *i = Type((*a).getType()).newValue();
    }
}

Object::~Object()
{
    cout<<"Freeing all base_value pointers\n";
    for(vector<BaseValue*>::iterator it=values.begin(); it!=values.end();++it)
    {
        delete *it;
    }
}














