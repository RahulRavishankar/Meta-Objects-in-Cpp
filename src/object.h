#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>


class ClassDef;
class BaseValue;

class Object
{
    public:
	explicit Object(ClassDef const * class_);
    ~Object();
    ClassDef const & instanceOf() const;
    BaseValue* getValue(string const & attribName) const;
	void setValue(string const & attribName, BaseValue const& bv);
    
    private:
    typedef vector<BaseValue *> ValueContainer;

    BaseValue* getValue(size_t attribIdx) const;
    void setValue(size_t idx, BaseValue const& bv);
    void buildValueList();
    ClassDef const * const myClass;
    ValueContainer values;
};

#endif
