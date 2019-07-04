#include <iostream>
#include "test.h"
#include "Header.h"
//�������� ������� 2 ���� 1 ������. ������ �������� ���. ������� �15
//������ �� �������� ������.
//�������� ���������, ������� ��� ��������� ��������� ��������� (��� �������� �������� ������ ��� ���)
//������� �������� ���� ��������� � ����������� ��������� ���������� ������ �������� ����������� b.
//��� �������� ��������� ��� ���������, ���������� � ���� ����, �� ������ ��������� ����������� �����.
//
//
//

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	try {
		maintest();// ������ ������
		vector<int> v;//��������� ������� ��� 1 ���������
		vector<int> v2;
		vector<int> v1;
		for (int i = 0; i < 1000; i++) {
			v.push_back((int)(rand()+1)/1000);
		}
		clock_t start = clock();
		int res = decision_1(v, 33);
		clock_t end = clock();
		for (int i = 0; i < 10000; i++) {
			v1.push_back((int)(rand() + 1) / 1000);
		}
		clock_t start1 = clock();
		res = decision_1(v1, 33);
		clock_t end1 = clock();
		for (int i = 0; i < 100000; i++) {
			v2.push_back((int)(rand() + 1) / 1000);
		}
		clock_t start2 = clock();
		res = decision_1(v2, 70);
		clock_t end2 = clock();
		cout << "����� ������ 1 ���������:" << endl << "��� 1000 ���������: " << (double)(end - start) / CLOCKS_PER_SEC <<endl<<"��� 10000 ���������: "
			<< (double)(end1 - start1) / CLOCKS_PER_SEC<<endl << "��� 100000 ���������: " << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;
		//��������� ������� ��� �������(������������) ���������
		vector<int> v0;//��������� ������� ��� 1 ���������
		vector<int> v20;
		vector<int> v10;
		for (int i = 0; i < 1000; i++) {
			v0.push_back((int)(rand() + 1) / 1000);
		}
		std::vector<int> boxes;
		boxes.push_back(0);
		clock_t start10 = clock();
		 res = decision_2_main(v0, 33);
		clock_t end10 = clock();
		
		
		for (int i = 0; i < 10000; i++) {
			v10.push_back((int)(rand() + 1) / 1000);
		}
		
		std::vector<int> boxes1;
		boxes1.push_back(0);
		clock_t start11 = clock();
		 res = decision_2_main(v10, 33);
		clock_t end11 = clock();
	

		 
		cout << "����� ������ 2 ���������:" << endl << "��� 1000 ���������: " << (double)(end10 - start10) / CLOCKS_PER_SEC << endl << "��� 10000 ���������: "
			<< (double)(end11 - start11) / CLOCKS_PER_SEC << endl<<endl;
		cout << "��� ������� ����������� ���������� ����� �� ��������, �������� ������ ������� �������" << endl << endl;
			
		int b;
		int c;
		vector<int> vv;
		ifstream in_file("initial_data.txt");
		if (!in_file.is_open()) {
			cerr << "couldn't open file ";
		}
		else {
			cout << "��������� ������ ��������� � ��������� ������� � �����: " << endl<<endl;
			in_file >> b;
			while (!in_file.eof()) {
				in_file >> c;
				vv.push_back(c);
			}
			vector<int> newVec;
			newVec.reserve(vv.size());
			copy(vv.begin(),vv.end(), back_inserter(newVec));
			decision_1_in_file(vv, b);
			
			decision_2_in_file(newVec, b);
			cout << "�������: ����� ��������� � ����� �������1.txt ��� 1 ��������� �������2.txt ��� 2-������������ ���������." << endl<<endl;
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