#include "Money.h"


Ruble::Ruble(const Ruble& other)
{
	rub = other.rub;
	kop = other.kop;
}

void Ruble::select()
{
	
	rub += kop / KOPECKS;
	kop %= KOPECKS;
	
}

bool Ruble::add(Money* mon)
{
	Ruble* other;
	bool ans;
	if (other = dynamic_cast<Ruble*>(mon)) {
		ans = true;
		kop += other->kop;
		rub += other->rub;
		select();
	}
	else
		ans = false;
	return ans;
}

bool Ruble::sub(Money* mon)
{
	Ruble* other;
	bool ans;
	if (other = dynamic_cast<Ruble*>(mon)) {
		ans = true;
		kop -= other->kop;
		rub -= other->rub;
		select();
	}
	else
		ans = false;
	return ans;
}

bool Ruble::mod_zero(Money* mon)
{
	Ruble* other;
	bool ans = false;
	if (other = dynamic_cast<Ruble*>(mon)) {
		int k1 = kop + rub * KOPECKS;
		int k2 = other->kop + other->rub * KOPECKS;
		ans = k2 % k1 == 0;
	}
	return ans;
}

void Ruble::mul(int x)
{
	kop *= x;
	rub *= x;
	select();
}

void Ruble::div(int x)
{
	if (x != 0)
	{
		kop /= x;
		rub /= x;
	}
}

void Ruble::print()
{
	std::cout << rub << '.' << kop;
}

int Ruble::compare(Money* mon)
{
	Ruble* other;
	int ans;
	if (other = dynamic_cast<Ruble*>(mon)) {
		int k1 = kop + rub * KOPECKS;
		int k2 = other->kop + other->rub * KOPECKS;
		if (k1 > k2)
			ans = 1;
		else if (k1 == k2)
			ans = 0;
		else
			ans = -1;
	}
	else
		ans = -2;
	return ans;
}

Galleon::Galleon(const Galleon& other)
{
	gal = other.gal;
	sickle = other.sickle;
	knat = other.knat;

}

void Galleon::select()
{
	sickle += knat / KNATS;
	knat %= KNATS;
	gal += sickle / SICKLES;
	sickle %= SICKLES;
}

bool Galleon::add(Money* mon)
{
	Galleon* other;
	bool ans;
	if (other = dynamic_cast<Galleon*>(mon)) {
		ans = true;
		gal += other->gal;
		sickle += other->sickle;
		knat += other->knat;
		select();
	}
	else
		ans = false;
	return ans;
}

bool Galleon::sub(Money* mon)
{
	Galleon* other;
	bool ans;
	if (other = dynamic_cast<Galleon*>(mon)) {
		ans = true;
		gal -= other->gal;
		sickle -= other->sickle;
		knat -= other->knat;
		select();
	}
	else
		ans = false;
	return ans;
}

bool Galleon::mod_zero(Money* mon)
{
	Galleon* other;
	bool ans = false;
	if (other = dynamic_cast<Galleon*>(mon)) {
		int k1 = knat + sickle * KNATS + gal * SICKLES * KNATS;
		int k2 = other->knat + other->sickle * KNATS + other->gal * SICKLES * KNATS;
		ans = k2 % k1 == 0;
	}
	return ans;

}

void Galleon::mul(int x)
{
	gal *= x;
	sickle *= x;
	knat *= x;
	select();
}
void Galleon::div(int x)
{
	if (x != 0) 
	{
		gal /= x;
		sickle /= x;
		knat /= x;
	}

}
void Galleon::print()
{
	std::cout << gal << '.' << sickle << '.' << knat;
}

int Galleon::compare(Money* mon)
{
	Galleon* other;
	int ans;
	if (other = dynamic_cast<Galleon*>(mon)) {
		int k1 = knat + sickle*KNATS + gal*SICKLES*KNATS;
		int k2 = other->knat + other->sickle * KNATS + other->gal * SICKLES * KNATS;
		if (k1 > k2)
			ans = 1;
		else if (k1 == k2)
			ans = 0;
		else
			ans = -1;
	}
	else
		ans = -2;
	return ans;
}
