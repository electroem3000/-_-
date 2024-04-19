#include <iostream>
#include "Money.h"
#include <list>
#include <fstream>
#include <string>
using namespace std;
using List = list<Money*>;

List task1(Money* ptr, const List& l);
List task2(Money* ptr, const List& l);
Money* task3(const List& l, int ch);

// �������� �� ���� ������
void input(int& x, const char* msg = "");

// �������� �� ���� ������ ����
void checkpoint(int& x, int maxim, int minim = 0, const char* msg = "");

// �������� �� ���� ����� �����
string readfilename();

// �������� �� ������������� ����� � ������ ������
void checkfilename(string& file_name);

void print(const List& l, const char* msg = "") {
	cout << msg;
	for (Money* ptr : l)
	{
		ptr->print();
		cout << ' ';
	}
	cout << endl;
}
std::istream& operator >> (std::istream& stream, Ruble& r)
{
	char ch; int rub, kop;
	stream >> rub >> ch >> kop;
	r.set_kop(kop);
	r.set_rub(rub);
	r.select();
	return stream;
}
std::istream& operator >> (std::istream& stream, Galleon& g)
{
	char ch; int gal, sickle, knat;
	stream >> gal >> ch >> sickle >> ch >> knat;
	g.set_gal(gal);
	g.set_sickle(sickle);
	g.set_knat(knat);
	g.select();
	return stream;
}
void readconsole(Ruble& r)  {
	int rub, kop;
	cout << "�����: ";
	input(rub);
	cout << "�������: ";
	input(kop);
	r.set_kop(kop);
	r.set_rub(rub);
	r.select();

}

void readconsole(Galleon& g) {
	int gal, sickle, knat;
	cout << "��������: ";
	input(gal);
	cout << "�����: ";
	input(sickle);
	cout << "�����: ";
	input(knat);
	g.set_gal(gal);
	g.set_sickle(sickle);
	g.set_knat(knat);
	g.select();

}

// ����
void main_menu()
{
	List l; int choice;
	int x = 1;
	while (x)
	{
		cout << "1.  ������� ������\n";
		cout << "2.  ������� ������ �� �����\n";
		cout << "3.  ������ �� ���������, ������� ���������\n";
		cout << "4.  ������ �� ���������, ��������� ��� �������\n";
		cout << "5.  ����� ������\n";
		cout << "6.  ������\n";
		cout << "0.  �����\n\n";
		checkpoint(x, 6);
		switch (x)
		{
		case 1: //������� ������
		{
			l.clear();
			cout << "1. �����\n2. ��������\n";
			checkpoint(choice, 2, 1);
			int size;
			cout << "������� ���������� ���������\n";
			checkpoint(size, UINT16_MAX);
			if (choice == 1) {

				Ruble* ptr;
				
				for (int i = 0; i < size; i++) {
					ptr = new Ruble();
					readconsole(*ptr);

					l.push_back(ptr);
					cout << endl;
				}
				ptr = nullptr;
			}
			else
			{
				Galleon* ptr;

				cout << "������� �������� \"���.���.����\"\n";
				for (int i = 0; i < size; i++) {
					ptr = new Galleon();
					readconsole(*ptr);
					l.push_back(ptr);
				}
				ptr = nullptr;

			}
			print(l, "LIST:\n");
			break;
		}
		case 2: //������� ������ �� �����
		{
			l.clear();
			cout << "1. �����\n2. ��������\n";
			checkpoint(choice, 2, 1);
			string file_name;
			checkfilename(file_name);
			ifstream file(file_name);
			if (choice == 1) {
				Ruble tmp;
				Ruble* ptr;
				while (file >> tmp)
				{
					ptr = new Ruble(tmp);
					l.push_back(ptr);
					
				}
				ptr = nullptr;
			}
			else
			{
				Galleon tmp;
				Galleon* ptr;
				while (file >>tmp)
				{
					ptr = new Galleon(tmp);
					l.push_back(ptr);
				}
				ptr = nullptr;
			}
			print(l, "LIST:\n");
			break;
		}
		
		case 3: // ������ �� ���������, ������� ���������
		{
			cout << "������� �������\n";
			
			if (choice == 1)
			{
				Ruble* ptr = new Ruble();
				readconsole(*ptr); 
				print(task1(ptr, l), "ANS:\n"); //
			}
			else
			{
				Galleon* ptr = new Galleon();
				readconsole(*ptr);
				print(task1(ptr, l), "ANS:\n");
			}
			break;
		}
		case 4: // ������ �� ���������, ��������� ��� �������
		{
			cout << "������� �������\n";

			if (choice == 1)
			{
				Ruble* ptr = new Ruble();
				readconsole(*ptr);
				Ruble* nul = new Ruble();
				if (ptr->compare(nul) == 0) {
					cout << "������� �� ����!\n";
				}
				else
					print(task2(ptr, l), "ANS:\n"); 
			}
			else
			{
				Galleon* ptr = new Galleon();
				readconsole(*ptr);
				Galleon* nul = new Galleon();
				if (ptr->compare(nul) == 0) {
					cout << "������� �� ����!\n";
				}
				else
					print(task2(ptr, l), "ANS:\n");
			}
			
			break;
		}
		case 5: // ����� ������
		{
			Money* ans = task3(l, choice);
			cout << "ANS:\n";
			ans->print();
			cout << endl;
			break;
		}
		case 6:// ������
		{
			print(l, "ANS:\n");
			break;
		}
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	main_menu();
	return 0;
}




List task1(Money* ptr, const List& l) 
{
	Ruble* ruble; Galleon* galleon;
	List ans;
	if (ruble = dynamic_cast<Ruble*>(ptr)) {
		for (Money* i: l) 
		{
			if (ruble->compare(i) == -1)
				ans.push_back(i);
		}
	}
	else if (galleon = dynamic_cast<Galleon*>(ptr))
	{
		for (Money* i : l)
		{
			if (galleon->compare(i) == -1)
				ans.push_back(i);
		}
	}
	return ans;
}

List task2(Money* ptr, const List& l)
{
	Ruble* ruble; Galleon* galleon;
	List ans;
	if (ruble = dynamic_cast<Ruble*>(ptr)) {
		for (Money* i : l)
		{
			if (ruble->mod_zero(i))
				ans.push_back(i);
		}
	}
	else if (galleon = dynamic_cast<Galleon*>(ptr))
	{
		for (Money* i : l)
		{
			if (galleon->mod_zero(i))
				ans.push_back(i);
		}
	}
	return ans;
}

Money* task3(const List& l, int ch)
{
	Money* ans = nullptr;
	if (ch == 1) {
		Ruble* r = new Ruble();
		for (Money* i : l) {
			r->add(i);
		}
		ans = r;
	}
	else if (ch == 2) {
		Galleon* g = new Galleon();
		for (Money* i : l) {
			g->add(i);
		}
		ans = g;
	}
	
	return ans;
}


void input(int& x, const char* msg)
{
	bool good = 0;
	do {
		cout << msg;
		cin >> x;
		if (!cin.fail()) {
			good = 1;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else {
			cout << "������ �����!\n";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
	} while (!good);
}

void checkpoint(int& x, int maxim, int minim, const char* msg)
{
	input(x);
	while (x > maxim || x < minim) {
		cout << "������ �����!\n";
		input(x, msg);
	}
}



string readfilename()
{
	string file_name;
	cout << "������� ��� �����:\n";
	cin >> file_name;
	return file_name;
}

void checkfilename(string& file_name)
{
	bool good = true;
	do {
		file_name = readfilename();
		ifstream file(file_name);
		if (file.fail())
		{
			cout << "����� �� ����������!\n";
			good = false;
		}
		else
			good = true;
	} while (!good);
}
