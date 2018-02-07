#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Flight
{
public:
	Flight(int fligtNum, string origin, string destination, int time): flightNum(fligtNum), origin(origin), destination(destination), time(time){}
	int flightNum;
	string origin;
	string destination;
	int time;
};

class equalByDeparture {
public:
	int operator() (Flight a, string item) {
		if (item == a.origin)
			return true;
		return false;
	}
};

class equalByDestination {
public:
	int operator() (Flight a, string item) {
		if (item == a.destination)
			return true;
		return false;
	}
};

template <class T, class D>
vector<T> search(vector<T>& items, string val, D funct)
{
	vector<T> results;
	bool satisfies;

	for (unsigned i = 0; i < items.size(); i++)
	{
		satisfies = funct(items[i], val);
		if (satisfies == true)
			results.push_back(items[i]);
	}

	return results;
}

void outdegree(vector<Flight> objects)
{
	vector<Flight> outD;
	equalByDeparture depart;
    
	for (unsigned i = 0; i < objects.size(); i++)
	{
		if (search(objects, objects[i].origin, depart).size()>outD.size())
			outD = search(objects, objects[i].origin, depart);
	}

	cout << "City: " << outD[0].origin << " " << outD.size();
}

void otherOutdegree(vector<Flight> objects)
{
	vector<string> checked;
	int maxInd = 0;
	int max = 1;
	int counter;
	bool skip = false;

	for (unsigned i = 0; i < objects.size(); i++)
	{
		counter = 1;
		skip = false;
		for (unsigned x = 0; x < checked.size(); x++)
			if (checked[x] == objects[i].origin)
			{
				skip = true;
				x = checked.size();
			}
		if (skip == false)
		{
			checked.push_back(objects[i].origin);
			for (unsigned j = i+1; j < objects.size(); j++)
			{
				if (objects[j].origin == objects[i].origin)
					counter++;
			}
			if (counter > max)
			{
				max = counter;
				maxInd = i;
			}
		}
	}

	cout << "City: " << objects[maxInd].origin << " " << max << endl;
		
}

int main()
{
	string fileName;

	cout << "Enter file name" << endl;
	cin >> fileName;
	fstream file(fileName);

	if (!file)
	{
		cout << "Unable to open file" << endl;
	}
	else
	{
		vector<Flight> Flights;
		string line;
		int fn;
		string org;
		string des;
		int t;

		while (getline(file, line))
		{
			file >> fn;
			file >> org;
			file >> des;
			file >> t;
			Flights.push_back(*(new Flight(fn, org, des, t)));
		}
		outdegree(Flights); //Ignoring the first flight
	}

	cin.get();
	cin.get();
}