//подключение библиотек
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;//использование пространства имен
class organization_leisure
{
public:
	organization_leisure();//базовый конструктор
	organization_leisure(string name_event, string leader, string date, float time, float duration, float price);//конструктор с параметрами
	~organization_leisure();//деструктоор
	void set_data();//ввод данных
	void print_field();//вывод полей объекта
	void print_info();//вывод информации о  меню
	void write_file(vector<organization_leisure> &arr, string path);//запись в файл
	void read_file(vector<organization_leisure>& arr, string path);//чтение из файла
	void find_field(vector<organization_leisure>& arr, string field, int var);//поиск данных по полю
	void print_all_field();//вывод доступных полей класса
	void print_field_mm();//вывод полей для нахождения максимума или минимума
	void search_min(vector<organization_leisure>& arr, int var);//поиск минимального
	void search_max(vector<organization_leisure>& arr, int var);//поиск максимального
	void sort_field(vector<organization_leisure>& arr, int var);//сортировка по полю
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
	organization_leisure org;//создание объекта класса
	vector<organization_leisure> arr;//создание массива объектов
	//объявление переменных
	int var, count, var_switch;
	var = count = var_switch = 0;
	string path = "data.txt";
	string field;
	bool exit = true;
	org.print_info();
	org.read_file(arr, path);//чтение из файла
	while (exit)
	{
		cout << "Выберите действие: " << endl;
		cin >> var_switch;
		switch (var_switch)//консольное меню
		{
		case 1://режим 1
			org.set_data();//ввод данных
			arr.push_back(org);//добавление элемента в вектор
			cout << "Объект класса создан" << endl;
			break;
		case 2://режим 2
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				cout << "Доступные элементы:" << endl;
				count = 0;
				for (auto& el : arr)//вывод номеров элемеентов
				{
					cout << "Номер " << count << endl;
					count++;
				}
				cout << "Какой элемент хотите удалить?" << endl;
				cin >> var;
				if (var < arr.size())//проверка на коррекность ввода
				{
					arr.erase(arr.begin() + var);//удаление элемента
					org.write_file(arr, path);//запись в файл
					cout << "Объект удален" << endl;
				}
				else
				{
					cout << "Неверный выбор элемента" << endl;
				}
			}
			break;
		case 3://режим 3
			org.write_file(arr, path);//запись в файл
			cout << "Данные успешно сохранены в файл" << endl;
			break;
		case 4://режим 4
			org.read_file(arr, path);//чтение из файла
			cout << "Данные считаны" << endl;
			break;
		case 5://режим 5
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				org.print_all_field();//вывод всех полей
				cout << "Выберите нужное поле" << endl;
				cin >> var;
				cout << "Введите данные которые хотите найти" << endl;
				cin >> field;
				org.find_field(arr, field, var);//поиск данных по полю
			}
			break;
		case 6://режим 6
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				org.print_field_mm();//вывод полей для нахождения максимума и минимума
				cout << "Выберите нужное поле" << endl;
				cin >> var;
				org.search_min(arr, var);//поиск минимального объекта
			}
			break;
		case 7://режим 7
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				org.print_field_mm();//вывод полей для нахождения максимума и минимума
				cout << "Выберите нужное поле" << endl;
				cin >> var;
				org.search_max(arr, var);//поиск максимального объекта
			}
			break;
		case 8://режим 8
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				org.print_all_field();//вывод всех полей
				cout << "Выберите поле для сортировки" << endl;
				cin >> var;
				org.sort_field(arr, var);//сортировка вектора
				cout << "Массив отсортирован" << endl;
			}
			break;
		case 9://режим 9
			if (arr.empty())//проверка на наличие элементов в векторе
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				for (auto& el : arr)//цикл фор ич
				{
					el.print_field();//вывод полей объекта
				}
			}
			break;
		case 10://режим 10
			exit = false;//выход из программы
			cout << "Программа завершена" << endl;
			break;
		default:
			org.print_info();
			break;
		}
	}
	return 0;
}
organization_leisure::organization_leisure()//базовый конструктор
{
	//присвоение полям пустых значений
	this->name_event = "";
	this->leader = "";
	this->name_user = "";
	this->date = "";
	this->time = 0.0f;
	this->duration = 0.0f;
	this->price = 0.0f;
}

organization_leisure::organization_leisure(string name_event, string leader, string date, float time, float duration, float price)//конструктор с параметрами
{
	//присвоение полям введенных значений
	this->name_event = name_event;
	this->leader = leader;
	this->name_user = name_user;
	this->date = date;
	this->time = time;
	this->duration = duration;
	this->price = price;
}

organization_leisure::~organization_leisure()//деструктор
{
	//присвоение полям пустых значений
	this->name_event = "";
	this->leader = "";
	this->name_user = "";
	this->date = "";
	this->time = 0.0f;
	this->duration = 0.0f;
	this->price = 0.0f;
}

void organization_leisure::set_data()//ввод данных
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

void organization_leisure::print_field()//вывод полей объекта
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

void organization_leisure::print_info()//вывод информации о меню
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

void organization_leisure::write_file(vector<organization_leisure> &arr, string path)//запись в файл
{
	fstream file;//создание объекта класса фстрим
	file.open(path, fstream::out);//открытие файла
	if (file.is_open())//проверка открытия файла
	{
		file.clear();//очистка файла
		file << arr.size() << "\n";//запись первой строчкой количества элементов
		for (auto& el : arr)//цикл фор ич
		{
			//запись полей в файл
			file << el.name_event << "\n";
			file << el.leader << "\n";
			file << el.name_user << "\n";
			file << el.date << "\n";
			file << el.time << "\n";
			file << el.duration << "\n";
			file << el.price << "\n";
		}
		file.close();//закрытие файла
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void organization_leisure::read_file(vector<organization_leisure>& arr, string path)//чтение из файла
{
	fstream file;//создание объекта класса фстрим
	organization_leisure obj;
	int size = 0;
	string field;
	file.open(path, fstream::in);//открытие файла
	if (file.is_open())//проверка открытия файла
	{
		arr.clear();//очистка вектор
		getline(file, field);//считывание количества объектов
		size = stoi(field);
		for (int i = 0;i < size;i++)
		{
			//чтение данных и запись их в поля класса 
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
			arr.push_back(obj);//добавление объекта в вектор
		}
		file.close();//закрытие файла
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void organization_leisure::find_field(vector<organization_leisure>& arr, string field, int var)//поиск по полям
{
	bool check = false;
	switch (var)//выбор поля
	{
	case 1:
		for (auto& el : arr)//цикл фор ич
		{
			if (field == el.name_event)//нахождение данных в поле
			{
				el.print_field();//вывод всех полей найденного объекта
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 2:
		for (auto& el : arr)//цикл фор ич
		{
			if (field == el.leader)//нахождени данных в поле
			{
				el.print_field();//вывод всех полей найденного объекта
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 3:
		for (auto& el : arr)//цикл фор ич
		{
			if (field == el.name_user)//нахождение данных в поле
			{
				el.print_field();//вывод всех полей найденного объекта
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 4:
		for (auto& el : arr)//цикл фор ич
		{
			if (field == el.date)//нахождение данных в поле
			{
				el.print_field();//вывод всех полей найденного объекта
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 5:
		for (auto& el : arr)//цикл фор ич
		{
			if (stoi(field) == el.time)//нахождение данных в поле
			{
				el.print_field();//вывод всех полей найденного объекта
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 6:
		for (auto& el : arr)//цикл фор ич
		{
			if (stoi(field) == el.duration)//нахождение данных в поле
			{
				el.print_field();//вывод всех полей найденного объекта
				check = true;
			}
		}
		if (check == false) { cout << "Данные не найдены" << endl; }
		break;
	case 7:
		for (auto& el : arr)//цикл фор ич
		{
			if (stoi(field) == el.price)//нахождение данных в поле
			{
				el.print_field();//вывод всех полей найденного объекта
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

void organization_leisure::print_all_field()//вывод доступных полей
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

void organization_leisure::print_field_mm()//вывод полей для нахождения максимума и минимума
{
	cout << "Доступные поля для нахождение максимума или минимума" << endl;
	cout << "1 - Время начала мероприятия" << endl;
	cout << "2 - Продолжительность мероприятия" << endl;
	cout << "3 - Стоимость" << endl;
}

void organization_leisure::search_min(vector<organization_leisure>& arr, int var)//поиск минимального элемента
{
	float min = 1000000.0f;
	switch (var)//выбор поля
	{
	case 1:
		for (auto& el : arr)//цикл фор ич
		{
			if (min > el.time)//определение минимального элемента
			{
				min = el.time;
			}
		}
		cout << "Минимальный элемент = " << min << endl;//вывд минимального элемента
		break;
	case 2:
		for (auto& el : arr)//цикл фор ич
		{
			if (min > el.duration)//определение минимального элемента
			{
				min = el.duration;
			}
		}
		cout << "Минимальный элемент = " << min << endl;//вывод минимального элемента
		break;
	case 3:
		for (auto& el : arr)//цикл фор ич
		{
			if (min > el.price)//определение минимального элемента
			{
				min = el.price;
			}
		}
		cout << "Минимальный элемент = " << min << endl;//вывод минимального элемента
		break;
	default:
		cout << "Неверный выбор поля" << endl;
		break;
	}
}

void organization_leisure::search_max(vector<organization_leisure>& arr, int var)//поиск максимального элемента
{
	float max = 0.0f;
	switch (var)//выбор поля
	{
	case 1:
		for (auto& el : arr)//цикл фор ич
		{
			if (max < el.time)//определение максимального элемента
			{
				max = el.time;
			}
		}
		cout << "Максимальный элемент = " << max << endl;//вывод максимального элемента
		break;
	case 2:
		for (auto& el : arr)//цикл фор ич
		{
			if (max < el.duration)//определение максимального элемента
			{
				max = el.duration;
			}
		}
		cout << "Максимальный элемент = " << max << endl;//вывод максимального элемента
		break;
	case 3:
		for (auto& el : arr)//цикл фор ич
		{
			if (max < el.price)//определение максимального элемента
			{
				max = el.price;
			}
		}
		cout << "Максимальный элемент = " << max << endl;//вывод максимального элемента
		break;
	default:
		cout << "Неверный выбор поля" << endl;
		break;
	}
}

void organization_leisure::sort_field(vector<organization_leisure>& arr, int var)//сортировка по полю
{
	switch (var)//выбор поля
	{
	case 1:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.name_event < o2.name_event;});//сортировка
		break;
	case 2:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.leader < o2.leader;});//сортировка
		break;
	case 3:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.name_user < o2.name_user;});//сортировка
		break;
	case 4:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.date < o2.date;});//сортировка
		break;
	case 5:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.time < o2.time;});//сортировка
		break;
	case 6:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.duration < o2.duration;});//сортировка
		break;
	case 7:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.price < o2.price;});//сортировка
		break;
	default:
		cout << "Неверный выбор поля" << endl;
		break;
	}
}

