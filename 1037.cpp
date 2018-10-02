#include <iostream>
using namespace std;

int main()
{
	//약수 개수
	int divisor_count;
	cin >> divisor_count;

	int* arr = new int[divisor_count];

	long divisor; //약수
	for (int i = 0; i < divisor_count; i++)
	{
		//진짜 약수 입력
		cin >> divisor;
		arr[i] = divisor;
	}

	int max;
	int min;
	max = arr[0];
	min = arr[0];
	for (int j = 0; j < divisor_count; j++)
	{
		if (arr[j] > max)
		{
			max = arr[j];
		}

		if (arr[j] < min)
		{
			min = arr[j];
		}
	}
	cout << max*min << endl;
	return 0;
}