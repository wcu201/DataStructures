#include <iostream>
#include <vector>
#include <string>
#include <list>
#include<math.h>


using namespace std;

int hash(int val)
{
	int hashVal = val % 10;

	return hashVal;
}



template <class T, class P>
class map
{
private:
	T key;
	vector<list<P>> vals;
public:
	map(T key, P val) : key(key) {}

	list<int> s;

	

	P operator[] (T k)
	{
		P val;

		val = vals[hash(k)].front();

		return val;
	}

	void insert(P newVal)
	{
		int other = rand;
		vals[hash(rand)].push_back(newVal);
	}

	void remove(T k)
	{
		vals[hash(k)].pop_back();
	}
};

int main()
{
	

	

	cin.get();
}