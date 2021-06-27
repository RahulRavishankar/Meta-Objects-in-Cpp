#include <assert.h>
#include "class_definition.h"
#include "object.h"
#include <string>
#include <vector>
#include <algorithm>

vector<string> ClassDef::class_names(0);

ClassDef::ClassDef(const ClassDef* base, const string & name_)
: baseClass(base),definitionFix(false)
{
	auto it=find(class_names.begin(),class_names.end(),name_);
	assert(it==class_names.end());
	class_names.push_back(name_);
	name=name_;
    baseInit();
    effectiveAttributes.insert(effectiveAttributes.end(), ownAttributes.begin(), ownAttributes.end());
}

ClassDef::~ClassDef()
{
	class_names.erase(find(class_names.begin(),class_names.end(),name));
}

void ClassDef::baseInit()
{
    if(baseClass)
    {
        baseClass->definitionFix = true;
        copy(baseClass->attribBegin(), baseClass->attribEnd(),
                back_inserter<AttributeContainer>(effectiveAttributes));
    }
}
string ClassDef::getName() const
{
	return name;
}

Object* ClassDef::newObject() const
{
    definitionFix = true;
    return new Object(this);
}

size_t ClassDef::findAttribute(const string& name) const
{
    // Do a reverse search to find the most derived
    AttributeContainer::const_reverse_iterator it;

    for (it = effectiveAttributes.rbegin(); it != effectiveAttributes.rend(); ++it)
    {
        if (it->getName() == name)
        {
            return distance(it, effectiveAttributes.rend()) - 1;
        }
    }
    return getAttributeCount();
}

size_t ClassDef::findOwnAttribute(const string& name) const
{
    // Do a reverse search to find the most derived
    AttributeContainer::const_reverse_iterator it;

    for (it = ownAttributes.rbegin(); it != ownAttributes.rend(); ++it)
    {
        if (it->getName() == name)
        {
            return distance(it, ownAttributes.rend()) - 1;
        }
    }
    return getAttributeCount();
}


ClassDef::AttrIterator ClassDef::attribBegin() const
{
	return ClassDef::AttrIterator(effectiveAttributes.begin());
}

ClassDef::AttrIterator ClassDef::attribEnd() const 
{
	return ClassDef::AttrIterator(effectiveAttributes.end());
}

Attribute const & ClassDef::getAttribute(size_t idx) const
{
	return effectiveAttributes[idx];
}

void ClassDef::addAttribute(const Attribute &A)
{
	if(!definitionFix)
	{
		if(findOwnAttribute(A.getName())==getAttributeCount())
		{
			effectiveAttributes.push_back(A);
			ownAttributes.push_back(A);	
		}
		else
		{
			cout << "Attribute already exists! Cannot add another attribute with the same name!!" << std::endl;
		}	
	}
	else
	{
		cout << "WARNING :: Cannot modify the class after instantiation" << std::endl;
	}
}

size_t ClassDef::getAttributeCount() const
{
	return effectiveAttributes.end()-effectiveAttributes.begin();
}



















    
