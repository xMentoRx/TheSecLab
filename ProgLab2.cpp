#include<iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

void idz(int arr[], int N) {
	int value_to_decrease;
	int counter_even = 0;
	int counter_odd = 0;
	int start_val = 1;
	int end_val = 9;
	srand(time(0));
	cout << "Введите значение для уменьшения четных элементов ";
	cin >> value_to_decrease;
	cout << "Выводим четные элементы, уменьшенные в процессе ";
	int random_value = (rand() % (end_val - start_val + 1) + start_val);
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			// уменьшение на заданное значение
			arr[i] = arr[i] - value_to_decrease;
			cout << arr[i] << ' ';
			// умножение четного на рандомное значение
			arr[i] = arr[i] * random_value;
			if (arr[i] % 2 == 0) {
				counter_even += 1;
			}
		}
		else if (i % 2 != 0 and arr[i] % 2 != 0) {
			counter_odd += 1;
		};
	};
	cout << endl;
	cout << "Выводим массив с четными элементами, умноженными на значение " << random_value << " : ";
	for (int i = 0; i < (N / 2); i++) {
		cout << arr[i] << " ";
	};
	cout << endl;
	cout << "Количество четных элементов имеющих четные значения: " << counter_even << endl;
	cout << "Количество нечетных элементов имеющих нечетные значения: " << counter_odd << endl;
	for (int i = 1; i < 10; i++) {
		int counter_del = 0;
		for (int j = 0; j < N; j++) {
			if (arr[j] % i == 0) {
				counter_del += 1;
			}
		};
		cout << "Количество чисел делящихся на " << i << " равно " << counter_del << endl;
	};
};
void shaker_sort(int arr[], int n) {
	bool swapped = true;
	int start = 0;
	int end = n - 1;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start_time, end_time;
	nanoseconds result;
	start_time = steady_clock::now();
	for (int a = 0; a < n / 2; a++) {
		swapped = false;

		// Проход слева направо
		for (int i = start; i < end; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}

		// Проход справа налево
		for (int i = end - 1; i >= start; --i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
	}
	end_time = steady_clock::now();
	result = duration_cast<nanoseconds>(end_time - start_time);
	cout << result.count() << " наносекунд - время сортировки с помощью shaker sort" << endl;

}
void bubble_sort(int arr[], int N) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	start = steady_clock::now();
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < N - 1 - j; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			};
		};
	};
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - время сортировки с помощью bubble sort" << endl;
}
void insert_sort(int arr[], int n) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	start = steady_clock::now();
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		// Сдвигаем элементы массива, которые больше key, на одну позицию вперед
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	};
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - время сортировки с помощью insert sort" << endl;
}
void quick_sort(int arr[], int end, int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l)
	{
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l)
		{
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l) quick_sort(arr, l, begin);
	if (f < end) quick_sort(arr, end, f);
}
void comb_sort(int arr[], int N) {
	int swap;
	float k = 1.247, S = N - 1;
	int count = 0;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start_time, end_time;
	nanoseconds result;
	start_time = steady_clock::now();
	while (S >= 1)
	{
		for (int i = 0; i + S < N; i++)
		{
			if (arr[i] > arr[int(i + S)])
			{
				swap = arr[int(i + S)];
				arr[int(i + S)] = arr[i];
				arr[i] = swap;
			}
		}
		S /= k;
	}

	while (true)
	{
		for (int i = 0; i < N - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = swap;
			}
			else count++;
		}
		if (count == N - 1)
			break;
		else
			count = 0;
	}
	end_time = steady_clock::now();
	result = duration_cast<nanoseconds>(end_time - start_time);
	cout << result.count() << " наносекунд - время сортировки с помощью comb sort" << endl;
}
void from_small_to_big_2(int arr[], int N) {
	shaker_sort(arr, N);
	insert_sort(arr, N);
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start_time, end_time;
	nanoseconds result;
	start_time = steady_clock::now();
	quick_sort(arr, N - 1, 0);
	end_time = steady_clock::now();
	result = duration_cast<nanoseconds>(end_time - start_time);
	cout << result.count() << " наносекунд - время сортировки с помощью quick sort" << endl;
	comb_sort(arr, N);
	bubble_sort(arr, N);
	cout << "Отсортированный массив: ";
	for (int a = 0; a < N; a++) {
		cout << arr[a] << ' ';
	};
	cout << endl;
};

void max_min_elems_of_arr_3(int arr[], int not_sort[], int N) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	start = steady_clock::now();
	// несортированный массив
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < N - 1 - j; i++) {
			if (not_sort[i] > not_sort[i + 1]) {
				swap(not_sort[i], not_sort[i + 1]);
			};
		};
	};
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ С НЕСОРТИРОВАННЫМ МАССИВОМ" << endl;
	cout << "Максимальный и минимальный элементы для неотсортированного массива: " << not_sort[0] << ' ' << not_sort[N - 1] << endl;
	// для отсортированного массива
	int max;
	int min;
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < N - 1 - j; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			};
		};
	};
	start = steady_clock::now();
	min = arr[0];
	max = arr[N - 1];
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ С СОРТИРОВАННЫМ МАССИВОМ" << endl;
	cout << "Максимальный и минимальный элементы для отсортированного массива: " << min << ' ' << max << endl;

};

void median_of_arr_4(int arr[], int N) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	int srednee_znachenie = (arr[0] + arr[N - 1]) / 2;
	cout << "среднее от min и max " << srednee_znachenie << endl;
	int counter = 0;
	cout << "Под каким номером есть такое же число как среднее: ";
	start = steady_clock::now();
	for (int i = 0; i < N; i++) {
		if (arr[i] == srednee_znachenie) {
			cout << i << endl;
			counter += 1;
		}

	};
	end = steady_clock::now();

	if (counter == 0) {
		cout << "нет таких элементов массива" << endl;
	}
	else {
		cout << "Всего найдено чисел: " << counter << endl;
	};
	result = duration_cast<nanoseconds>(end - start);
	cout << "Нахождение заданных элементов заняло: " << result.count() << " наносекунд" << endl;
}


void smaller_num_counter_5(int arr[], int N) {
	int num;
	int count = 0;
	cout << "ВВЕДИТЕ ЧИСЛО: ";
	cin >> num;
	cout << "ЧИСЛА МЕНЬШЕ ЧЕМ " << num << ": ";
	for (int a = 0; a < N; a++) {
		if (num > arr[a]) {
			cout << arr[a] << ' ';
			count += 1;
		}
	};
	if (count == 0) {
		cout << "НЕ НАЙДЕНО";
	};
	cout << endl;
	cout << "КОЛИЧЕСТВО ЧИСЕЛ МЕНЬШЕ ЧЕМ " << num << " РАВНО " << count << endl;
};

void bigger_num_counter_6(int arr[], int N) {
	int num2;
	int count_2 = 0;
	cout << "ВВЕДИТЕ ЧИСЛО: ";
	cin >> num2;
	cout << "ЧИСЛА БОЛЬШЕ ЧЕМ " << num2 << ": ";
	for (int a = 0; a < N; a++) {
		if (num2 < arr[a]) {
			cout << arr[a] << ' ';
			count_2 += 1;
		}
	};
	if (count_2 == 0) {
		cout << "НЕ НАЙДЕНО";
	};
	cout << endl;
	cout << "КОЛИЧЕСТВО ЧИСЕЛ БОЛЬШЕ ЧЕМ " << num2 << " РАВНО " << count_2 << endl;
};

int binarySearch(int arr[], int value, int start, int end) {
	// полный перебор
	if (end >= start) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == value) {
			return mid;
		}
		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}
		return binarySearch(arr, value, mid + 1, end);
	}
	return -1;
};

void find_number_in_arr_7(int arr[], int N) {
	int num;
	int num_in_arr = 0;
	cout << "ВВЕДИТЕ ЧИСЛО ДЛЯ ЗАДАНИЯ 7: ";
	cin >> num;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	cout << "Полным перебором: ";
	// полный перебор
	start = steady_clock::now();
	for (int a = 0; a < N; a++) {
		if (num == arr[a]) {
			num_in_arr = 1;
			break;
		}
	};
	end = steady_clock::now();
	if (num_in_arr == 1) {
		cout << "Введенное число есть в массиве!" << endl;
	}
	else {
		cout << "Введенного числа нет в массиве!" << endl;
	}
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ ОБЫЧНЫМ ПЕРЕБОРОМ" << endl;
	cout << "Бинарным поиском: ";
	start = steady_clock::now();
	// бинарный поиск
	int answer = binarySearch(arr, num, 0, N - 1);
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	if (answer == -1) {
		cout << "Введенного числа нет в массиве!" << endl;
	}
	else {
		cout << "Введенное число есть в массиве!" << endl;
	}
	cout << result.count() << " наносекунд - ВРЕМЯ ВЫПОЛНЕНИЯ БИНАРНЫМ ПОИСКОМ" << endl;

};

void change_elems_of_arr_8(int arr[], int N) {
	int elem_index_1;
	int elem_index_2;
	cout << "Введи индексы, которые хочешь поменять в массиве:";
	cin >> elem_index_1;
	cout << endl;
	cin >> elem_index_2;
	swap(arr[elem_index_1], arr[elem_index_2]);
	cout << "НУ ВОТ И ПОМЕНЯЛИСЬ" << endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	};
	cout << endl;
};


int main()
{
	setlocale(0, "");
	// 1)Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.
	const int N = 100;
	unsigned identificator;
	int Array[N];
	int not_sorted_array[N];
	unsigned int start_val = -99;
	int end_val = 99;
	srand(time(0));
	cout << "Сгенерированный массив: " << endl;
	for (int i = 0; i < N; i++) {
		Array[i] = rand() % (end_val - start_val + 1) + start_val;
		not_sorted_array[i] = Array[i];
		cout << Array[i] << ' ';
	};
	cout << endl;
	cout << "Доступные задания: " << endl;
	cout << "1.Сгенерировать массив заново" << endl;
	cout << "2. Сортировка от меньшего к большему" << endl;
	cout << "3. Поиск минимального и максимального значений" << endl;
	cout << "4. Расчет и поиск среднего значения max и min" << endl;
	cout << "5. Элементы массива меньше заданного числа" << endl;
	cout << "6. Элементы массива больше заданного числа" << endl;
	cout << "7. Найти число в массиве" << endl;
	cout << "8. Поменять элементы с заданными индексами местами" << endl;
	cout << "9. ИДЗ 5" << endl;
	cout << "10. Завершение работы программы" << endl;
	while (true) {
		cout << "ВВЕДИТЕ НОМЕР ЗАДАНИЯ: ";
		cin >> identificator;

		switch (identificator) {
		case 1:
			cout << "Новый массив" << endl;
			for (int i = 0; i < N; i++) {
				Array[i] = rand() % (end_val - start_val + 1) + start_val;
				not_sorted_array[i] = Array[i];
				cout << Array[i] << ' ';
			}
			cout << endl;
			break;

		case 2:
			cout << "Сортировка от меньшего к большему" << endl;
			from_small_to_big_2(Array, N);
			break;

		case 3:
			max_min_elems_of_arr_3(Array, not_sorted_array, N);
			break;

		case 4:
			median_of_arr_4(Array, N);
			break;

		case 5:
			smaller_num_counter_5(Array, N);
			break;

		case 6:
			bigger_num_counter_6(Array, N);
			break;

		case 7:
			find_number_in_arr_7(Array, N);
			break;

		case 8:
			change_elems_of_arr_8(Array, N);
			break;
		case 9:
			idz(Array, N);
			break;

		case 10:
			cout << "Выход!" << endl;
			return 0;

		default:
			cout << "Некорректный номер задания." << endl;
			break;
		}
	}
}