//*****************
//Program Name: Lab 4 (Pointers)
//Author: Clarissa Cheung
//IDE Used: Eclipse
//Program description: reviewing pointers
//*****************
#include <iostream>
using namespace std;
const int SIZE = 5;

//Part One
//switchOperands(): switching the elements given
//Arguments: *x, *y (int) | Returns: void
void switchOperands(int *x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

//Part Two
//enterArrayData(): receives a pointer to the array, and allows the user to enter data into the array
//Arguments: *arr (int) | Returns: void
void enterArrayData(int *arr){
	int num;
	for (int i = 0; i < SIZE; i++){
		cout << "Element " << i+1 << ": ";
		cin >> num;
		if(num > 0)
			*(arr + i) = num;
	}
	cout << endl;
}

//outputArrayData(): receives a pointer to the array, and simply outputs the array elements
//Arguments: *arr (int) | Returns: void
void outputArrayData(int *arr){
	for (int i = 0; i < SIZE; i++)
		cout << "Element " << i+1 << ": " << *(arr + i) << endl;
	cout << endl;
}

//sumArray(): receives a pointer to the array, and simply outputs the sum of the array elements
//Arguments: *arr (int) | Returns: sum (int)
int sumArray(int *arr){
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += *arr++;
	return sum;
}

//Part 3
/* I wasn't sure how you wanted us to process the array without knowing the length.
 * I tried finding solutions to process them based on the size they already are
 * rather send the functions a set size, but I had trouble, so I just used a
 * const int global variable for size.
 * (*(&arr + 1) - arr - 1)   sizeof(arr)/sizeof(arr[0])
*/

//copy(): copying the array but in reverse order
//Arguments: *arr (T) | Returns: *newArr (T)
template <typename T>
T* copy(T* arr){
	T* newArr  = new T[SIZE];
	//I used auto instead T because T may be a char or a string
	for(auto i = 0; i < SIZE; i++)
		*(newArr+i) = *(arr + (SIZE - i - 1));
	return newArr;
}

//print(): prints out given arrays
//Arguments: *arr (T) | Returns: void
template <typename T>
void print(T* arr){
	for(auto i = 0; i < SIZE; ++i)
		cout << "Element " << i+1 << ": " << *(arr + i) << endl;
	cout << endl;
}

int main() {
	cout << "Part One:\n----------------------\n";
	int num1 = 2, num2 = 3;
	cout << "Number 1: " << num1 << "\t" << "Number 2: " << num2 << "\n";
	switchOperands(&num1,&num2);
	cout << "Number 1: " << num1 << "\t" << "Number 2: " << num2 << "\n\n";

	cout << "Part Two:\n----------------------\n";
	int numbers[SIZE];
	enterArrayData(numbers);
	outputArrayData(numbers);
	cout << "Sum: " << sumArray(numbers) << endl << endl;

	cout << "Part Three:\n----------------------\n";
	cout << "Trying a double array...\n";
	double arr1[SIZE] = {7.3, 2, 9.7, 4.5, 3.2};
	print(arr1);
	double * arr2 = copy(arr1);
	print(arr2);

	cout << "Trying a char array...\n";
	char array1[SIZE] = {'c', 'k', 'a', 'l', 'r'};
	print(array1);
	char* array2 = copy(array1);
	print(array2);
	cout << "This is my original work; apart from standard tutoring or class collaboration, \nI neither received help nor copied this code from another source.";
	return 0;
}
