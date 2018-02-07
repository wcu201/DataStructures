#include <iostream>
#include <array>
#include <map>
#include <vector>

using namespace std;

class Lock
{
public:
	Lock(int first = 0, int sec = 0, int third = 0) : first(first), sec(sec), third(third) {}
	
	Lock(Lock& anotherLock)
	{
		first = anotherLock.first;
		sec = anotherLock.sec;
		third = anotherLock.third;
	}

	void unlock(int test1, int test2, int test3)
	{
		if (locked == true)
		{
			if (test1 == first && test2 == sec && test3 == third)
			{
				locked = false;
				cout << "The lock has UNLOCKED" << endl;
			}
			else
				cout << "Wrong combo. The Lock is still LOCKED" << endl;
		}

		else
			cout << "The lock is already UNLOCKED" << endl;
	}

	void setToLocked()
	{
		locked = true;
	}

	void changeCombo(int test1, int test2, int test3)
	{
		if (test1 == first && test2 == sec && test3 == third)
		{
			int nextFirst, nextSec, nextThird;

			cout << "Please give three integers as your new combo" << endl;

			cin >> nextFirst >> nextSec >> nextThird;

			first = nextFirst;
			sec = nextSec;
			third = nextThird;

		}
		else
			cout << "Wrong combo. Access DENIED." << endl;
	}

private:
	int first;
	int sec;
	int third;

	bool locked = true;
};

template <class T>
class DynArray
{
	T* values;
	int size = 0;
	int capacity = 2;

public:

	DynArray(T):{}

	~DynArray(
	{
		delete values[];
	}

	void push_back(T newVal)
	{
		if (capacity - size <= 1)
		{
			T temp[capacity * 2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = values[i];
			}
			
			values = temp;

			capacity *= 2;
		}

		values[size] = newVal;

		size++;
	}

	void pop_back()
	{
		if (size > 0)
		{
			delete values[size - 1];
			size--;
		}
	}

	T operator [](int index)
	{
		
		T indVal = values[index];

		return indVal;
	}



};

double getCost(map<int, double> storing, vector<int>& thePurchase)
{
	double cost = 0;
	int element;

	for (int i = 0; i < thePurchase.size(); i++)
	{
		element = thePurchase[i];
		cost += storing[element];
	}

	return cost;
}

