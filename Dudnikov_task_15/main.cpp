#include <iostream>
#include "test.h"
#include "Header.h"
//Дудников Алексей 2 курс 1 группа. Летняя практика АДМ. Задание №15
//Задача об упаковке ящиков.
//Написать программу, которая для заданного множества предметов (для кажждого предмета указан его вес)
//находит упаковку этих предметов в минимальное возможное количество ящиков заданной вместимости b.
//При упаковке суммарный вес предметов, помещаемый в один ящик, не должен превышать вместимости ящика.
//
//
//

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	try {
		
		maintest();// Запуск тестов
		
		
			
		int b;
		int c;
		vector<int> vv;
		ifstream in_file("initial_data.txt");
		if (!in_file.is_open()) {
			cerr << "couldn't open file ";
		}
		else {
			cout << "Результат работы программы с заданными данными в файле: " << endl<<endl;
			in_file >> b;
			while (!in_file.eof()) {
				in_file >> c;
				vv.push_back(c);
			}
			decision_main_in_file(vv, b);
			cout << "Успешно: Ответ находится в файле Решение.txt   (Для двух алгоритмов, отличающихся использованием копирования векторов врекурсии)" << endl<<endl;
			in_file.close();
		}
	}
	catch(const char* r)
	{
		
		cout << r << endl<<endl;
	}

	system("pause");
	return 0;
}