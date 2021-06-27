#ifndef TYPE_H
#define TYPE_H
#include <vector>

#include "value.h"

class Type
{
	public:
	enum TypeT {stringT, intT, doubleT, dateT, unknownT};
	explicit Type(TypeT typeId_);
	BaseValue * newValue() const;
	TypeT getType() const;
	
	static void init();
	static void free_prototypes();
	
	private:
	TypeT typeId_;
	static vector<BaseValue *> prototypes;
};

#endif
