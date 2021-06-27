#ifndef CLASS_DEFINITION_H
#define CLASS_DEFINITION_H

#include <string>
#include <vector>
#include "attribute.h"
class Object;
using namespace std;
typedef vector<Attribute> AttributeContainer;

class ClassDef
{
	public:
	ClassDef(const ClassDef* base, const string & name_);
	~ClassDef();
	template <typename iterator>
    ClassDef(ClassDef const * base, const string & name_, iterator attribBegin, iterator attribEnd)
	: baseClass(base), name(name_), ownAttributes(attribBegin, attribEnd), definitionFix(false)
	{
		baseInit();
    	effectiveAttributes.insert(effectiveAttributes.end(), ownAttributes.begin(), ownAttributes.end());
	}
    
	string getName() const;
    Object * newObject() const;
    
    class AttrIterator : public std::iterator<std::input_iterator_tag,Attribute>
    {
    	private:
    	AttributeContainer::const_iterator ptr;
    	
    	public:
    	AttrIterator()=default;
    	AttrIterator(AttributeContainer::const_iterator other): ptr(other) {}
    	
    	Attribute operator*()
		{
			return *ptr;
		}
		
		AttrIterator& operator++()
		{
			++ptr;
			return *this;
		}
		
		AttrIterator operator++(int)
		{
			AttrIterator temp(*this);
			++*this;
			return temp;
		}	
		
		bool operator==(const AttrIterator& rhs) const
		{
			return rhs.ptr==ptr;
		}
		
		bool operator!=(const AttrIterator& rhs) const
		{
			return !(*this==rhs);
		}
		
    };
    AttrIterator attribBegin() const;
    AttrIterator attribEnd() const;
    Attribute const & getAttribute(size_t idx) const;
    void addAttribute(const Attribute &);
    size_t getAttributeCount() const;
    
	size_t findAttribute(string const & name) const;
	size_t findOwnAttribute(string const & name) const;
	private:
    void baseInit();
    
    ClassDef const * const baseClass;
    string name;
    AttributeContainer ownAttributes, effectiveAttributes;
    mutable bool definitionFix;
    static vector<string> class_names;
};

#endif
