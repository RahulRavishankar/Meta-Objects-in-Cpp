#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "class_definition.h"
#include "object.h"
#include "attribute.h"
#include "value.h"
#include "type.h"

int main()
{
    Type::init();

    ClassDef *date = new ClassDef(0, "Date");
    date->addAttribute(Attribute("DD", Type::intT));
    date->addAttribute(Attribute("MM", Type::intT));
    date->addAttribute(Attribute("YY", Type::intT));

    ClassDef *event = new ClassDef(0, "Event");
    event->addAttribute(Attribute("Event Name", Type::stringT));
    event->addAttribute(Attribute("Event Date", Type::unknownT));

    // Display event class
    cout<<"Class: Event\n";
    ClassDef::AttrIterator a;
    size_t idx;
    for (a = event->attribBegin(), idx = 0;a != event->attribEnd(); ++a, ++idx)
    {
        string attr_name = (*a).getName();
        int type_id = (*a).getType();
        cout << attr_name << ": "<< type_id <<"\n";
    }
    cout<<"------------------------------------------------\n";

    // Create an object
    Object * date_obj(date->newObject());
    date_obj->setValue("DD", RealValue<int>(8));
    date_obj->setValue("MM", RealValue<int>(5));
    date_obj->setValue("YY", RealValue<int>(21));

    Object * event_obj(event->newObject());
    event_obj->setValue("Event Name", RealValue<string>("Birthday"));
    event_obj->setValue("Event Date", RealValue<Object>(date_obj));

    // Display the event object
    cout<<"Object of event:\n";
    for (a = event_obj->instanceOf().attribBegin(), idx = 0;a != event_obj->instanceOf().attribEnd(); ++a, ++idx)
    {
        string attr_name = (*a).getName();
        cout << attr_name << ": "
             << event_obj->getValue(attr_name)->asString() << endl;
    }

    cout<<"\nDate object in Event object:\n";
    Object* event_date = event_obj->getValue("Event Date")->getObject();
    for (a = event_date->instanceOf().attribBegin(), idx = 0;a != event_date->instanceOf().attribEnd(); ++a, ++idx)
    {
        string attr_name = (*a).getName();
        cout << attr_name << ": "
             << event_date->getValue(attr_name)->asString() << endl;
    }

    return 0;
}