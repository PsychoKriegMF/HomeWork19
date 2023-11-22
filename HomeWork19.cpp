#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>



int divider(int num1, int num2) {
	if (num1 > num2)
		std::swap(num1, num2);
	for(int i = num1; i > 0; i--)
		if(num1 % i == 0 && num2 % i == 0)
	return i;
		

}
int mirror_number(int num1) {
	int number = 0;
	while (num1) {
		number = number * 10 + num1 % 10;
		num1 /= 10;
	}
	return number;
}
void print_arr(int arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
void sorted_arr(int arr[], const int length, int num) {
	int first_position = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == num) {
			first_position = i;
			std::cout << "Первая позиция числа: " << num << " = " << i << '\n';
			break;
		}
	for (int i = length - 1; i > first_position; i--)
		for(int j = first_position + 1; j < i; j++ )
			if (arr[j] > arr[j + 1]) 
				std::swap(arr[j], arr[j + 1]);
	
}
void add_arr(int arr[], const int length, int a, int b) {
	srand(time(NULL));
	if (a > b)
		std::swap(a, b);
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (b + 1 - a) + a;
}



int main() {
	setlocale(LC_ALL, "ru");

	std::cout << "Задача 1. Наибольший общий делитель.\n";
	std::cout << divider(12,48) << std::endl;

	std::cout << "Задача 2. Отражение числа.\n";
	std::cout << mirror_number(987) << std::endl;

	std::cout << "Задача 3. Сортировка от значения.\n";
	const int size = 10;
	int arr[size]{8,6,2,7,9,5,3,4,1,10};	
	std::cout << "Массив: ";
	print_arr(arr, size);
	std::cout << "От какого числа сортировать -> ";
	int n;
	std::cin >> n;
	sorted_arr(arr, size, n);
	std::cout << "Отсортированный от заданного числа массив: \n";
	print_arr(arr, size);
	
	std::cout << "\nЗадача 4. Заполнение массива в диапазоне.\n";
	const int size1 = 10;
	int arr1[size1]{};
	add_arr(arr1, size1, 50, 155);
	print_arr(arr1, size1);


	return 0;
}