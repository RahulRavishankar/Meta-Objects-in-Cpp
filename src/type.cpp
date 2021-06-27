#include "type.h"
#include "value.h"
#include "class_definition.h"
#include "object.h"

vector<BaseValue *> Type::prototypes(Type::unknownT);

Type::Type(TypeT typeId) : typeId_(typeId)
{
	
}

BaseValue * Type::newValue() const
{
    return prototypes[typeId_]->clone();
}

Type::TypeT Type::getType() const
{
    return typeId_;
}
void Type::init()
{
    prototypes[stringT] = new RealValue<string>("");
    prototypes[intT] = new RealValue<int>(0);
    prototypes[doubleT] = new RealValue<double>(0);
    prototypes[dateT] = new RealValue<Date>(Date(0,0,0));

    ClassDef* x = new ClassDef(0,"");
    prototypes[unknownT] = new RealValue<Object>(x->newObject());
    atexit(free_prototypes);
}
void Type::free_prototypes()
{
    cout<<"Freeing all prototypes\n";
    delete prototypes[stringT];
    delete prototypes[intT];
    delete prototypes[doubleT];
}
