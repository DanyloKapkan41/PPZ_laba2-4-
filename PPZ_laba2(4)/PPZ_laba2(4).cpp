#include <iostream>
using namespace std;
void filling(int*& nums, int i, int n, bool mode)
{
	if (mode) {
		if (i < n) {
			nums[i] = rand() % 10;
			i++;
			filling(nums, i, n, mode);
		}
	}
	else {
		if (i < n) {
			do { cin >> nums[i]; } while (nums[i] < 0 || nums[i]>9);
			cout << " writed...\n";
			i++;
			filling(nums, i, n, mode);
		}
	}
}
void extract(int* nums, int i, int n)
{
	if (i < n) {
		cout << nums[i] << ' ';
		i++;
		extract(nums, i, n);
	}
}
void doubling(int*& numb, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (numb[i] == 0)
		{
			for (int j = n-1; j > i+1; j--) {
				numb[j] = numb[j - 1];
			}
			numb[i + 1] = 0;
			i++;
		}
	}
}
int main()
{
	int n, modeint;
	bool mode;
	do {
		cout << "Enter array size(1 - 10000): ";
		cin >> n;
	} while (n <= 0 || n >= 10000);
	int* nums = new int[n];
	srand(time(NULL));
	do {
		cout << "Choose mode (1 - autoentering, 0 - enterig by yourself): ";
		cin >> modeint;
	} while (modeint < 0 || modeint > 1);
	mode = modeint;
	filling(nums, 0, n, mode);
	extract(nums, 0, n);
	cout << "\n";
	doubling(nums, n);
	extract(nums, 0, n);
}