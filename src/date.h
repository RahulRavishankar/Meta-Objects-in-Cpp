#ifndef DATE_H
#define DATE_H
#include <iostream> 
using namespace std;

class Date
{
    public:
    Date(int d, int m, int y): dd(d), mm(m), yy(y) 
    { }
    Date(const Date &rhs)
    {
        dd = rhs.dd;
        mm = rhs.mm;
        yy = rhs.yy; 
    }
    friend ostream& operator<<(ostream& o, const Date &other)
	{
		o << other.dd <<" : "<< other.mm <<" : "<< other.yy << "\n";
		return o;
	}
    private:
    int dd;
    int mm;
    int yy;
};

#endif