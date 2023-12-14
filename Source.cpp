//����������� ���������
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;//������������� ������������ ����
class organization_leisure
{
public:
	organization_leisure();//������� �����������
	organization_leisure(string name_event, string leader, string date, float time, float duration, float price);//����������� � �����������
	~organization_leisure();//�����������
	void set_data();//���� ������
	void print_field();//����� ����� �������
	void print_info();//����� ���������� �  ����
	void write_file(vector<organization_leisure> &arr, string path);//������ � ����
	void read_file(vector<organization_leisure>& arr, string path);//������ �� �����
	void find_field(vector<organization_leisure>& arr, string field, int var);//����� ������ �� ����
	void print_all_field();//����� ��������� ����� ������
	void print_field_mm();//����� ����� ��� ���������� ��������� ��� ��������
	void search_min(vector<organization_leisure>& arr, int var);//����� ������������
	void search_max(vector<organization_leisure>& arr, int var);//����� �������������
	void sort_field(vector<organization_leisure>& arr, int var);//���������� �� ����
private:
	string name_event;//������������ �����������
	string leader;//�������
	string name_user;//��� �������
	string date;//���� �����������
	float time;//����� ������ �����������
	float duration;//�����������������
	float price;//��������� �����������
};
int main()
{
	setlocale(LC_ALL, "rus");
	organization_leisure org;//�������� ������� ������
	vector<organization_leisure> arr;//�������� ������� ��������
	//���������� ����������
	int var, count, var_switch;
	var = count = var_switch = 0;
	string path = "data.txt";
	string field;
	bool exit = true;
	org.print_info();
	org.read_file(arr, path);//������ �� �����
	while (exit)
	{
		cout << "�������� ��������: " << endl;
		cin >> var_switch;
		switch (var_switch)//���������� ����
		{
		case 1://����� 1
			org.set_data();//���� ������
			arr.push_back(org);//���������� �������� � ������
			cout << "������ ������ ������" << endl;
			break;
		case 2://����� 2
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				cout << "��������� ��������:" << endl;
				count = 0;
				for (auto& el : arr)//����� ������� ����������
				{
					cout << "����� " << count << endl;
					count++;
				}
				cout << "����� ������� ������ �������?" << endl;
				cin >> var;
				if (var < arr.size())//�������� �� ����������� �����
				{
					arr.erase(arr.begin() + var);//�������� ��������
					org.write_file(arr, path);//������ � ����
					cout << "������ ������" << endl;
				}
				else
				{
					cout << "�������� ����� ��������" << endl;
				}
			}
			break;
		case 3://����� 3
			org.write_file(arr, path);//������ � ����
			cout << "������ ������� ��������� � ����" << endl;
			break;
		case 4://����� 4
			org.read_file(arr, path);//������ �� �����
			cout << "������ �������" << endl;
			break;
		case 5://����� 5
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				org.print_all_field();//����� ���� �����
				cout << "�������� ������ ����" << endl;
				cin >> var;
				cout << "������� ������ ������� ������ �����" << endl;
				cin >> field;
				org.find_field(arr, field, var);//����� ������ �� ����
			}
			break;
		case 6://����� 6
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				org.print_field_mm();//����� ����� ��� ���������� ��������� � ��������
				cout << "�������� ������ ����" << endl;
				cin >> var;
				org.search_min(arr, var);//����� ������������ �������
			}
			break;
		case 7://����� 7
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				org.print_field_mm();//����� ����� ��� ���������� ��������� � ��������
				cout << "�������� ������ ����" << endl;
				cin >> var;
				org.search_max(arr, var);//����� ������������� �������
			}
			break;
		case 8://����� 8
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				org.print_all_field();//����� ���� �����
				cout << "�������� ���� ��� ����������" << endl;
				cin >> var;
				org.sort_field(arr, var);//���������� �������
				cout << "������ ������������" << endl;
			}
			break;
		case 9://����� 9
			if (arr.empty())//�������� �� ������� ��������� � �������
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				for (auto& el : arr)//���� ��� ��
				{
					el.print_field();//����� ����� �������
				}
			}
			break;
		case 10://����� 10
			exit = false;//����� �� ���������
			cout << "��������� ���������" << endl;
			break;
		default:
			org.print_info();
			break;
		}
	}
	return 0;
}
organization_leisure::organization_leisure()//������� �����������
{
	//���������� ����� ������ ��������
	this->name_event = "";
	this->leader = "";
	this->name_user = "";
	this->date = "";
	this->time = 0.0f;
	this->duration = 0.0f;
	this->price = 0.0f;
}

organization_leisure::organization_leisure(string name_event, string leader, string date, float time, float duration, float price)//����������� � �����������
{
	//���������� ����� ��������� ��������
	this->name_event = name_event;
	this->leader = leader;
	this->name_user = name_user;
	this->date = date;
	this->time = time;
	this->duration = duration;
	this->price = price;
}

organization_leisure::~organization_leisure()//����������
{
	//���������� ����� ������ ��������
	this->name_event = "";
	this->leader = "";
	this->name_user = "";
	this->date = "";
	this->time = 0.0f;
	this->duration = 0.0f;
	this->price = 0.0f;
}

void organization_leisure::set_data()//���� ������
{
	string first_name, second_name, third_name;
	cout << "������� �������� �����������:" << endl;
	cin >> name_event;
	cout << "������� ������� ��������:" << endl;
	cin >> leader;
	cout << "������� ������� �������" << endl;
	cin >> first_name;
	cout << "������� ��� �������" << endl;
	cin >> second_name;
	cout << "������� �������� �������" << endl;
	cin >> third_name;
	name_user = first_name + " " + second_name + " " + third_name;
	cout << "������� ���� �����������:" << endl;
	cin >> date;
	cout << "������� ����� ������ �����������" << endl;
	cin >> time;
	cout << "������� �����������������" << endl;
	cin >> duration;
	cout << "������� ���������" << endl;
	cin >> price;
}

void organization_leisure::print_field()//����� ����� �������
{
	cout << "���� ������ organization_leisure" << endl;
	cout << "�������� ����������� = " << name_event << endl;
	cout << "������� = " << leader << endl;
	cout << "��� �������" << name_user << endl;
	cout << "���� ����������� = " << date << endl;
	cout << "����� ������ ����������� = " << time << endl;
	cout << "����������������� ����������� = " << duration << endl;
	cout << "��������� = " << price << endl;
}

void organization_leisure::print_info()//����� ���������� � ����
{
	cout << "��������� ������:" << endl;
	cout << "1 - ���� ������" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - ���������� ������ � ����" << endl;
	cout << "4 - ������ ������ �� �����" << endl;
	cout << "5 - ����� ������ �� �����" << endl;
	cout << "6 - ����� ������������ ��������" << endl;
	cout << "7 - ����� ������������� ��������" << endl;
	cout << "8 - ���������� �� �����" << endl;
	cout << "9 - ����� ������" << endl;
	cout << "10 - �����" << endl;
}

void organization_leisure::write_file(vector<organization_leisure> &arr, string path)//������ � ����
{
	fstream file;//�������� ������� ������ ������
	file.open(path, fstream::out);//�������� �����
	if (file.is_open())//�������� �������� �����
	{
		file.clear();//������� �����
		file << arr.size() << "\n";//������ ������ �������� ���������� ���������
		for (auto& el : arr)//���� ��� ��
		{
			//������ ����� � ����
			file << el.name_event << "\n";
			file << el.leader << "\n";
			file << el.name_user << "\n";
			file << el.date << "\n";
			file << el.time << "\n";
			file << el.duration << "\n";
			file << el.price << "\n";
		}
		file.close();//�������� �����
	}
	else
	{
		cout << "������ �������� �����" << endl;
	}
}

void organization_leisure::read_file(vector<organization_leisure>& arr, string path)//������ �� �����
{
	fstream file;//�������� ������� ������ ������
	organization_leisure obj;
	int size = 0;
	string field;
	file.open(path, fstream::in);//�������� �����
	if (file.is_open())//�������� �������� �����
	{
		arr.clear();//������� ������
		getline(file, field);//���������� ���������� ��������
		size = stoi(field);
		for (int i = 0;i < size;i++)
		{
			//������ ������ � ������ �� � ���� ������ 
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
			arr.push_back(obj);//���������� ������� � ������
		}
		file.close();//�������� �����
	}
	else
	{
		cout << "������ �������� �����" << endl;
	}
}

void organization_leisure::find_field(vector<organization_leisure>& arr, string field, int var)//����� �� �����
{
	bool check = false;
	switch (var)//����� ����
	{
	case 1:
		for (auto& el : arr)//���� ��� ��
		{
			if (field == el.name_event)//���������� ������ � ����
			{
				el.print_field();//����� ���� ����� ���������� �������
				check = true;
			}
		}
		if (check == false) { cout << "������ �� �������" << endl; }
		break;
	case 2:
		for (auto& el : arr)//���� ��� ��
		{
			if (field == el.leader)//��������� ������ � ����
			{
				el.print_field();//����� ���� ����� ���������� �������
				check = true;
			}
		}
		if (check == false) { cout << "������ �� �������" << endl; }
		break;
	case 3:
		for (auto& el : arr)//���� ��� ��
		{
			if (field == el.name_user)//���������� ������ � ����
			{
				el.print_field();//����� ���� ����� ���������� �������
				check = true;
			}
		}
		if (check == false) { cout << "������ �� �������" << endl; }
		break;
	case 4:
		for (auto& el : arr)//���� ��� ��
		{
			if (field == el.date)//���������� ������ � ����
			{
				el.print_field();//����� ���� ����� ���������� �������
				check = true;
			}
		}
		if (check == false) { cout << "������ �� �������" << endl; }
		break;
	case 5:
		for (auto& el : arr)//���� ��� ��
		{
			if (stoi(field) == el.time)//���������� ������ � ����
			{
				el.print_field();//����� ���� ����� ���������� �������
				check = true;
			}
		}
		if (check == false) { cout << "������ �� �������" << endl; }
		break;
	case 6:
		for (auto& el : arr)//���� ��� ��
		{
			if (stoi(field) == el.duration)//���������� ������ � ����
			{
				el.print_field();//����� ���� ����� ���������� �������
				check = true;
			}
		}
		if (check == false) { cout << "������ �� �������" << endl; }
		break;
	case 7:
		for (auto& el : arr)//���� ��� ��
		{
			if (stoi(field) == el.price)//���������� ������ � ����
			{
				el.print_field();//����� ���� ����� ���������� �������
				check = true;
			}
		}
		if (check == false) { cout << "������ �� �������" << endl; }
		break;
	default:
		cout << "�������� ���� " << endl;
		break;
	}
}

void organization_leisure::print_all_field()//����� ��������� �����
{
	cout << "��������� ����:" << endl;
	cout << "1 - �������� �����������" << endl;
	cout << "2 - ������� " << endl;
	cout << "3 - ��� �������" << endl;
	cout << "4 - ���� �����������" << endl;
	cout << "5 - ����� ������ ����������� " << endl;
	cout << "6 - ����������������� �����������" << endl;
	cout << "7 - ���������" << endl;
}

void organization_leisure::print_field_mm()//����� ����� ��� ���������� ��������� � ��������
{
	cout << "��������� ���� ��� ���������� ��������� ��� ��������" << endl;
	cout << "1 - ����� ������ �����������" << endl;
	cout << "2 - ����������������� �����������" << endl;
	cout << "3 - ���������" << endl;
}

void organization_leisure::search_min(vector<organization_leisure>& arr, int var)//����� ������������ ��������
{
	float min = 1000000.0f;
	switch (var)//����� ����
	{
	case 1:
		for (auto& el : arr)//���� ��� ��
		{
			if (min > el.time)//����������� ������������ ��������
			{
				min = el.time;
			}
		}
		cout << "����������� ������� = " << min << endl;//���� ������������ ��������
		break;
	case 2:
		for (auto& el : arr)//���� ��� ��
		{
			if (min > el.duration)//����������� ������������ ��������
			{
				min = el.duration;
			}
		}
		cout << "����������� ������� = " << min << endl;//����� ������������ ��������
		break;
	case 3:
		for (auto& el : arr)//���� ��� ��
		{
			if (min > el.price)//����������� ������������ ��������
			{
				min = el.price;
			}
		}
		cout << "����������� ������� = " << min << endl;//����� ������������ ��������
		break;
	default:
		cout << "�������� ����� ����" << endl;
		break;
	}
}

void organization_leisure::search_max(vector<organization_leisure>& arr, int var)//����� ������������� ��������
{
	float max = 0.0f;
	switch (var)//����� ����
	{
	case 1:
		for (auto& el : arr)//���� ��� ��
		{
			if (max < el.time)//����������� ������������� ��������
			{
				max = el.time;
			}
		}
		cout << "������������ ������� = " << max << endl;//����� ������������� ��������
		break;
	case 2:
		for (auto& el : arr)//���� ��� ��
		{
			if (max < el.duration)//����������� ������������� ��������
			{
				max = el.duration;
			}
		}
		cout << "������������ ������� = " << max << endl;//����� ������������� ��������
		break;
	case 3:
		for (auto& el : arr)//���� ��� ��
		{
			if (max < el.price)//����������� ������������� ��������
			{
				max = el.price;
			}
		}
		cout << "������������ ������� = " << max << endl;//����� ������������� ��������
		break;
	default:
		cout << "�������� ����� ����" << endl;
		break;
	}
}

void organization_leisure::sort_field(vector<organization_leisure>& arr, int var)//���������� �� ����
{
	switch (var)//����� ����
	{
	case 1:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.name_event < o2.name_event;});//����������
		break;
	case 2:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.leader < o2.leader;});//����������
		break;
	case 3:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.name_user < o2.name_user;});//����������
		break;
	case 4:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.date < o2.date;});//����������
		break;
	case 5:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.time < o2.time;});//����������
		break;
	case 6:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.duration < o2.duration;});//����������
		break;
	case 7:
		sort(arr.begin(), arr.end(), [](const organization_leisure& o1, const organization_leisure& o2) {return o1.price < o2.price;});//����������
		break;
	default:
		cout << "�������� ����� ����" << endl;
		break;
	}
}

