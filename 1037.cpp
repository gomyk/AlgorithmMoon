#include <iostream>
using namespace std;

int main()
{
	//��� ����
	int divisor_count;
	cin >> divisor_count;

	int* arr = new int[divisor_count];

	long divisor; //���
	for (int i = 0; i < divisor_count; i++)
	{
		//��¥ ��� �Է�
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