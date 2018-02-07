#include <iostream>
#include <vector>

using namespace std;

template <class T>
void selectSort(vector <T>& values)
{
	for (int i = 0; i < values.size(); i++)
	{
		T min = values[i];
		int minInd = i;
		for (int j = i; j < values.size(); j++)
		{
			if (values[j] < min)
			{
				min = values[j];
				minInd = j;
			}
		}
		T temp = values[i];
		values[i] = values[minInd];
		values[minInd] = temp;
	}
}

template <class S>
void insertSort(vector <S>& values)
{ 
	if (values.size() == 1)
		return;
	for (int i = 1; i < values.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (values[i] < values[j - 1])
				if(j-1==0||values[j-2]<values[i])
			{
				S temp = values[i];
				values[i] = values[j - 1];
				values[j - 1] = temp;
				j = 0;
				i--;
			}
		}
	}
}

template <class R>
void shellSort(vector <R>& values)
{
	for (int i = 0; i < values.size() / 2; i++)
	{

	}
}

int main()
{
	vector<int> test = { 5,3,4,1,2 };
	cout << test[0] << test[1] << test[2] << test[3] << test[4] << endl;
	insertSort(test);
	cout << test[0] << test[1] << test[2] << test[3] << test[4] << endl;
	cin.get();
}