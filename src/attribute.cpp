#include "attribute.h"
#include "type.h"
#include "class_definition.h"

Attribute::Attribute(const string & name, Type::TypeT typeId)
: name_(name), typeId_(typeId)
{
	
}

Attribute::Attribute(const string & name, ClassDef* c)
: name_(name), typeId_(Type::dateT)
{

}
const string & Attribute::getName() const
{
    return name_;
}

Type::TypeT Attribute::getType() const
{
    return typeId_;
}


