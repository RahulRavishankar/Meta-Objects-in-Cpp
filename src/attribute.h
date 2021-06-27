#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <string>
#include "type.h"

class ClassDef;
//Attribute
class Attribute
{
	public:
	Attribute(const string & name, Type::TypeT typeId);
	Attribute(const string & name, ClassDef* c);
	const string & getName() const;
	Type::TypeT getType() const;
	
	private:
    string name_;
    Type::TypeT typeId_;
};

#endif
