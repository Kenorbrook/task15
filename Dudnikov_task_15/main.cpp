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
			decision_main_in_file(vv, b);
			cout << "�������: ����� ��������� � ����� �������.txt   (��� ���� ����������, ������������ �������������� ����������� �������� ���������)" << endl<<endl;
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