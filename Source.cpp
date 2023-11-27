#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
class organization_leisure
{
public:
	organization_leisure();
	organization_leisure(string name_event, string leader, string date, float time, float duration, float price);
	void set_data(string name_event, string leader, string date, float time, float duration, float price);
	void print_field();
private:
	string name_event;//наименование мероприятия
	string leader;//ведущий
	string name_user;//фио клиента
	string date;//дата мероприятия
	float time;//время начала мероприятия
	float duration;//продолжительность
	float price;//стоимость мероприятия
};
int main()
{
	setlocale(LC_ALL, "rus");
	return 0;
}
organization_leisure::organization_leisure()
{
	this->name_event = "";
	this->leader = "";
	this->name_user = "";
	this->date = "";
	this->time = 0.0f;
	this->duration = 0.0f;
	this->price = 0.0f;
}

organization_leisure::organization_leisure(string name_event, string leader, string date, float time, float duration, float price)
{
	this->name_event = name_event;
	this->leader = leader;
	this->name_user = name_user;
	this->date = date;
	this->time = time;
	this->duration = duration;
	this->price = price;
}

void organization_leisure::set_data(string name_event, string leader, string date, float time, float duration, float price)
{
	this->name_event = name_event;
	this->leader = leader;
	this->name_user = name_user;
	this->date = date;
	this->time = time;
	this->duration = duration;
	this->price = price;
}

void organization_leisure::print_field()
{
}
