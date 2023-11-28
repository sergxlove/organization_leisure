#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class organization_leisure
{
public:
	organization_leisure();
	organization_leisure(string name_event, string leader, string date, float time, float duration, float price);
	~organization_leisure();
	void set_data();
	void print_field();
	void print_info();
	void write_file(vector<organization_leisure> &arr, string path);
	void read_file(vector<organization_leisure>& arr, string path);
	void find_field(vector<organization_leisure>& arr, string field, int var);
	void print_all_field();
	void print_field_mm();
	void search_min(vector<organization_leisure>& arr, int var);
	void search_max(vector<organization_leisure>& arr, int var);
	void sort_field(vector<organization_leisure>& arr, int var);
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
	organization_leisure org;
	vector<organization_leisure> arr;
	auto it = arr.begin();
	int var_switch = 0;
	int var, count;
	var = count = 0;
	string path = "data.txt";
	string field;
	bool exit = true;
	org.print_info();
	while (exit)
	{
		cout << "Выберите действие: " << endl;
		cin >> var_switch;
		switch (var_switch)
		{
		case 1:
			org.set_data();
			arr.push_back(org);
			cout << "Объект класса создан" << endl;
			break;
		case 2:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				cout << "Доступные элементы:" << endl;
				count = 0;
				for (auto& el : arr)
				{
					cout << "Номер " << count << endl;
				}
				cout << "Какой элемент хотите удалить?" << endl;
				cin >> var;
				if (var < arr.size())
				{
					arr.erase(arr.begin() + var);
					org.write_file(arr, path);
					cout << "Объект удален" << endl;
				}
				else
				{
					cout << "Неверный выбор элемента" << endl;
				}
			}
			break;
		case 3:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				org.write_file(arr, path);
				cout << "Данные успешно сохранены в файл" << endl;
			}
			break;
		case 4:
			org.read_file(arr, path);
			cout << "Данные считаны" << endl;
			break;
		case 5:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				org.print_all_field();
				cout << "Выберите нужное поле" << endl;
				cin >> var;
				cout << "Введите данные которые хотите найти" << endl;
				cin >> field;
				org.find_field(arr, field, var);
			}
			break;
		case 6:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				org.print_field_mm();
				cout << "Выберите нужное поле" << endl;
				cin >> var;
				org.search_min(arr, var);
			}
			break;
		case 7:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				org.print_field_mm();
				cout << "Выберите нужное поле" << endl;
				cin >> var;
				org.search_max(arr, var);
			}
			break;
		case 8:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				org.print_all_field();
				cout << "Выберите поле для сортировки" << endl;
				cin >> var;
				org.sort_field(arr, var);
				cout << "Массив отсортирован" << endl;
			}
			break;
		case 9:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				for (auto& el : arr)
				{
					el.print_field();
				}
			}
			break;
		case 10:
			exit = false;
			cout << "Программа завершена" << endl;
			break;
		}
	}
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

organization_leisure::~organization_leisure()
{
	this->name_event = "";
	this->leader = "";
	this->name_user = "";
	this->date = "";
	this->time = 0.0f;
	this->duration = 0.0f;
	this->price = 0.0f;
}

void organization_leisure::set_data()
{
	string first_name, second_name, third_name;
	cout << "Введите название мероприятия:" << endl;
	cin >> name_event;
	cout << "Введите фамилию ведущего:" << endl;
	cin >> leader;
	cout << "Введите фамилию клиента" << endl;
	cin >> first_name;
	cout << "Введите имя клиента" << endl;
	cin >> second_name;
	cout << "Введите отчество клиента" << endl;
	cin >> third_name;
	name_user = first_name + " " + second_name + " " + third_name;
	cout << "Введите дату мероприятия:" << endl;
	cin >> date;
	cout << "Введите время начала мероприятия" << endl;
	cin >> time;
	cout << "Введите продолжительность" << endl;
	cin >> duration;
	cout << "Введите стоимость" << endl;
	cin >> price;
}

void organization_leisure::print_field()
{
	cout << "Поля класса organization_leisure" << endl;
	cout << "Название мероприятия = " << name_event << endl;
	cout << "Ведущий = " << leader << endl;
	cout << "ФИО клиента" << name_user << endl;
	cout << "Дата мероприятия = " << date << endl;
	cout << "Время начала мероприятия = " << time << endl;
	cout << "Продолжительность мероприятия = " << duration << endl;
	cout << "Стоимость = " << price << endl;
}

void organization_leisure::print_info()
{
	cout << "Доступные режимы:" << endl;
	cout << "1 - Ввод данных" << endl;
	cout << "2 - Удаление объекта" << endl;
	cout << "3 - Сохранение данных в файл" << endl;
	cout << "4 - Чтение данных из файла" << endl;
	cout << "5 - Поиск данных по полям" << endl;
	cout << "6 - Поиск минимального элемента" << endl;
	cout << "7 - Поиск максимального элемента" << endl;
	cout << "8 - Сортировка по полям" << endl;
	cout << "9 - Вывод данных" << endl;
	cout << "10 - Выход" << endl;
}

void organization_leisure::write_file(vector<organization_leisure> &arr, string path)
{
	fstream file;
	file.open(path, fstream::out | fstream::app);
	if (file.is_open())
	{
		file << arr.size() << "\n";
		for (auto& el : arr)
		{
			file << el.name_event << "\n";
			file << el.leader << "\n";
			file << el.name_user << "\n";
			file << el.date << "\n";
			file << el.time << "\n";
			file << el.duration << "\n";
			file << el.price << "\n";
		}
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void organization_leisure::read_file(vector<organization_leisure>& arr, string path)
{
	fstream file;
	organization_leisure obj;
	int size = 0;
	string field;
	file.open(path, fstream::in);
	if (file.is_open())
	{
		arr.clear();
		getline(file, field);
		size = stoi(field);
		for (int i = 0;i < size;i++)
		{
			getline(file, obj.name_event);
			getline(file, obj.leader);
			getline(file, obj.name_user);
			getline(file, obj.date);
			getline(file, field);
			obj.time = stoi(field);
			getline(file, field);
			obj.duration = stoi(field);
			getline(file, field);
			obj.price = stoi(field);
			arr.push_back(obj);
		}
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void organization_leisure::find_field(vector<organization_leisure>& arr, string field, int var)
{
	bool check = false;
	switch (var)
	{
	case 1:
		for (auto& el : arr)
		{
			if (field == el.name_event)
			{
				el.print_field();
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 2:
		for (auto& el : arr)
		{
			if (field == el.leader)
			{
				el.print_field();
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 3:
		for (auto& el : arr)
		{
			if (field == el.name_user)
			{
				el.print_field();
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 4:
		for (auto& el : arr)
		{
			if (field == el.date)
			{
				el.print_field();
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 5:
		for (auto& el : arr)
		{
			if (stoi(field) == el.time)
			{
				el.print_field();
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 6:
		for (auto& el : arr)
		{
			if (stoi(field) == el.duration)
			{
				el.print_field();
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 7:
		for (auto& el : arr)
		{
			if (stoi(field) == el.price)
			{
				el.print_field();
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	default:
		cout << "Неверный ввод " << endl;
		break;
	}
}

void organization_leisure::print_all_field()
{
	cout << "Доступные поля:" << endl;
	cout << "1 - Название мероприятия" << endl;
	cout << "2 - Ведущий " << endl;
	cout << "3 - ФИО клиента" << endl;
	cout << "4 - Дата мероприятия" << endl;
	cout << "5 - Время начала мероприятия " << endl;
	cout << "6 - Продолжительность мероприятия" << endl;
	cout << "7 - Стоимость" << endl;
}

void organization_leisure::print_field_mm()
{
	cout << "Доступные поля для нахождение максимума или минимума" << endl;
	cout << "1 - Время начала мероприятия" << endl;
	cout << "2 - Продолжительность мероприятия" << endl;
	cout << "3 - Стоимость" << endl;
}

void organization_leisure::search_min(vector<organization_leisure>& arr, int var)
{
	float min = 1000000.0f;
	switch (var)
	{
	case 1:
		for (auto& el : arr)
		{
			if (min > el.time)
			{
				min = el.time;
			}
		}
		cout << "Минимальный элемент = " << min << endl;
		break;
	case 2:
		for (auto& el : arr)
		{
			if (min > el.duration)
			{
				min = el.duration;
			}
		}
		cout << "Минимальный элемент = " << min << endl;
		break;
	case 3:
		for (auto& el : arr)
		{
			if (min > el.price)
			{
				min = el.price;
			}
		}
		cout << "Минимальный элемент = " << min << endl;
		break;
	default:
		cout << "Неверный выбор поля" << endl;
		break;
	}
}

void organization_leisure::search_max(vector<organization_leisure>& arr, int var)
{
	float max = 0.0f;
	switch (var)
	{
	case 1:
		for (auto& el : arr)
		{
			if (max < el.time)
			{
				max = el.time;
			}
		}
		cout << "Максимальный элемент = " << max << endl;
		break;
	case 2:
		for (auto& el : arr)
		{
			if (max < el.duration)
			{
				max = el.duration;
			}
		}
		cout << "Максимальный элемент = " << max << endl;
		break;
	case 3:
		for (auto& el : arr)
		{
			if (max < el.price)
			{
				max = el.price;
			}
		}
		cout << "Максимальный элемент = " << max << endl;
		break;
	default:
		cout << "Неверный выбор поля" << endl;
		break;
	}
}

void organization_leisure::sort_field(vector<organization_leisure>& arr, int var)
{
	switch (var)
	{
	case 1:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.name_event < o2.name_event;});
		break;
	case 2:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.leader < o2.leader;});
		break;
	case 3:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.name_user < o2.name_user;});
		break;
	case 4:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.date < o2.date;});
		break;
	case 5:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.time < o2.time;});
		break;
	case 6:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.duration < o2.duration;});
		break;
	case 7:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.price < o2.price;});
		break;
	default:
		cout << "Неверный выбор поля" << endl;
		break;
	}
}

