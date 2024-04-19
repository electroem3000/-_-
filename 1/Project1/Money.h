#pragma once
#include <iostream>

using namespace std;
class Money
{
public:
	
	virtual bool add(Money* mon) = 0;
	virtual bool sub(Money* mon) = 0;
	virtual bool mod_zero(Money* mon) = 0;

	virtual void mul(int x) = 0;
	virtual void div(int x) = 0;
	
	virtual void select() = 0;
	virtual void print() = 0;
	virtual int compare(Money* mon) = 0;

};


class Ruble : public Money {
private:
	const int KOPECKS = 100;
	int rub;
	int kop;
public:

	Ruble(int r = 0, int k = 0) : rub(r), kop(k) { select(); };
	Ruble(const Ruble &other);
	void select() override;
	bool add(Money* mon) override;
	bool sub(Money* mon) override;
	bool mod_zero(Money* mon) override;

	void mul(int x) override;
	void div(int x) override;
	
	void print() override;
	void set_rub(int rub) { this->rub = rub; }
	void set_kop(int kop) { this->kop = kop; }
	int compare(Money* mon) override;
	
};





class Galleon : public Money {
private:
	const int SICKLES = 17, KNATS = 29;
	int gal;
	int sickle;
	int knat;
public:
	Galleon(int g = 0, int s = 0, int k = 0) : gal(g), sickle(s), knat(k) { select(); };
	Galleon(const Galleon& other);
	void select() override;
	bool add(Money* mon) override;
	bool sub(Money* mon) override;
	bool mod_zero(Money* mon) override;

	void mul(int x) override;
	void div(int x) override;

	void print() override;
	void set_gal(int gal) { this->gal = gal; }
	void set_sickle(int sickle) { this->sickle = sickle; }
	void set_knat(int knat) { this->knat = knat; }
	int compare(Money* mon) override;
	
};
