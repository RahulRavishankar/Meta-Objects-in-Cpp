#ifndef VALUE_H
#define VALUE_H
#include <iostream>
#include <string>
#include <sstream> 
#include "date.h"
#include "object.h"
using namespace std;

class BaseValue
{
	public:
    virtual ~BaseValue() { };
    virtual BaseValue * clone() const = 0;
    virtual string asString() const = 0;
    virtual void set(BaseValue const& bv) = 0;
	virtual Object* getObject()
	{
		cout<<"There's nothing here\n";
		return NULL;
	};
};

template <typename PlainT>
class RealValue : public BaseValue
{
	public:
	RealValue(PlainT v) : val(v) { }
	RealValue() {}
	RealValue* clone() const 
	{
    	return new RealValue(*this);
	}
	string asString() const
	{
		std::ostringstream oss;
		oss << val;
		return oss.str();
	}
	operator PlainT() const // conversion to plain type
	{
		return val;
	}
	void set(BaseValue const& bv)
	{
		val = dynamic_cast<RealValue<PlainT> const & >(bv);
	}

	private:
    PlainT val;
};

template <>
class RealValue<string> : public BaseValue
{
	public:
	RealValue(string const & s) : val(s) { }
	RealValue(char const * s) : val(s) { }
	RealValue() { }
	RealValue* clone() const
	{
		return new RealValue(*this);
	}
	string asString() const
	{
		return val;
	}
	operator string() const 
	{
		return val;
	}
	void set(BaseValue const& bv)
	{
		val = dynamic_cast<RealValue<string> const & >(bv);
	}
	friend ostream& operator<<(ostream& o, RealValue<string> &other)
	{
		o<<other.val;
		return o;
	}
	private:
	string val;
};

template <>
class RealValue<Date> : public BaseValue
{
	public:
	RealValue(Date v) : val(new Date(v)) { }

	RealValue* clone() const 
	{
    	return new RealValue(*this);
	}
	string asString() const
	{
		std::ostringstream oss;
		oss << *val;
		return oss.str();
	}
	operator Date()
	{
		return *val;
	}
	void set(BaseValue const& bv)
	{
		val = (dynamic_cast<RealValue<Date> const & >(bv)).val;
	}
	friend ostream& operator<<(ostream& o, RealValue<Date> &other)
	{
		o << *other.val;
		return o;
	}

	private:
    Date *val;
};

template <>
class RealValue<Object> : public BaseValue
{
	public:
	RealValue(Object *v) : val(v) { }

	RealValue* clone() const 
	{
    	return new RealValue(*this);
	}
	string asString() const
	{
		std::ostringstream oss;
		oss << val;
		return oss.str();
	}
	operator Object()
	{
		return *val;
	}
	void set(BaseValue const& bv)
	{
		val = (dynamic_cast<RealValue<Object> const & >(bv)).val;
	}
	Object* getObject()
	{
		return val;
	};
	private:
    Object *val;
};
#endif
