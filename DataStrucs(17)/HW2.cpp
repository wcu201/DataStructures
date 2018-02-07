
/*
William Uchegbu
Section A
*/
#include <iostream>
#include <ctime>

using namespace std;

class timer {
private:
	double start;
public:
	timer() { start = clock(); }
	double elapsed() { return (clock() - start) / CLOCKS_PER_SEC; }
	void reset() { start = clock(); }
};

bool is_prime1(int num, int n)
{
	if (n <= 2)
	{
		//cout << "Prime" << endl;
		return true;
	}
	if (num%(n-1) == 0)

	{
		//cout << "Not Prime" << endl;
		return false;
	}
	else
		return is_prime1(num, n-1);
}

double count_primes1(int n)
{
	timer t;
	double elapsed;
	t.reset();
	int count = 1;
	for (int m = n - 1; m > 2; m-- )
	{
		if (is_prime1(m, m) == true)
		{
			count++;
		}
	}
	elapsed = t.elapsed();
	cout << "There are " << count << " prime numbers between 2 and " << n << endl; 
		cout << "Time to compute: approx. " << elapsed << "s" << endl;
	return elapsed;
}

int is_prime2(int num)
{
	int n = num;
	for (int i = num - 1; i > 0; i--)
	{
		if (num%i == 0)
		{
			//cout << "Not Prime. Divisor: " << i << endl;
			return i;
		}
	}

	//cout << "Prime" << endl;
	return 0;
}

double count_primes2(int n)
{
	timer t;
	double elapsed;
	t.reset();
	int count = 1;
	for (int m = n - 1; m > 2; m--)
	{
		if (is_prime2(m) == true)
		{
			count++;
		}
	}
	elapsed = t.elapsed();
	cout << "There are " << count << " prime numbers between 2 and " << n << endl;
	cout << "Time to compute: approx. " << elapsed << "s" << endl;
	return elapsed;
}

int is_prime3(int num)
{
	int n = num;
	for (int i = num - 1; i > 0; i--)
	{
		if (num%i == 0)
		{
			//cout << "Not Prime. Divisor: " << i << endl;
			return i;
		}
	}

	//cout << "Prime" << endl;
	return 0;
}

double count_primes3(int n)
{
	timer t;
	double elapsed;
	t.reset();
	int count = 1;
	for (int m = n - 1; m > 2; m--)
	{
		if (m ^ 2 >= n && is_prime3(m) == true)
		{
			count++;
		}
	}
	elapsed = t.elapsed();
	cout << "There are " << count << " prime numbers between 2 and " << n << endl;
	cout << "Time to compute: approx. " << elapsed << "s" << endl;
	return elapsed;
}

int main()
{
	int meth;
	int param;
	bool exit = false;


	while (exit == false)
	{
		cout << "Which method (1,2,3 or 0=exit): ";
		cin >> meth;
		if (meth == 0)
			exit = true;
		else
		{
			cout << endl << "Enter the value of n: ";
			cin >> param;
			cout << endl;
			if (meth == 1)
				count_primes1(param);
			if (meth == 2)
				count_primes2(param);
			if (meth == 3)
				count_primes3(param);
		}

		cin.get();
	}
	cout << "Thank you." << endl;
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
}

/*
1) n=100  p1:.083s,p2:.119s,p3:.119s
   n=1000 p1:.292s,p2:.492s,p3:.492s
   n=2000 p1:.398s,p2:.632s,p3:.632s
   n=5000 p1:.576s,p2:.942s,p3:.942s


2) is_prime2() - O(n)

3)
log (n^5) = O(log(n))
300 n^2 + 20 n + n^4 = O(n^4)
n * log (n+12) = O(nlog(n))
100n + 4n^2 + 12 log n = O(n^2)
log n + n/100 = O(nlog(n))
sqrt(6n) * ( log n + 10) = O(log(n))
n + (n-1) + (n-2) + ... + 1 = O(n^2)

4)
A - O(n^2)
B – O(nlog(n))
C – O(log(n))

*/