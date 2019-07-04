#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h> 
// ���� � ����������� ������� ������ �������.

//������ �������� ������� ������
int decision_1(std::vector<int> vec, int b) {
	bool flag = false;
	int max = 0;
	std::vector<int> boxes;
	boxes.push_back(0);
	//���������� ������� ������ ������, ��� ����������� ��������� � �������� ���� ��������� ���������� �������
	auto it = std::max_element(vec.begin(), vec.end());
	// ���� ��� �������� �� ��������
	while (vec.size()) {
		flag = false;
		max = std::distance(vec.begin(), it);
		if (vec[max] > b)
			throw "��� �������� ������ ������� �����";
		if (vec[0] < 0)
			throw "��� �������� ������ ����";
		// ���������� ������ � ��������� ��������� ��� �� �����������
		for(int j=0; j<boxes.size(); j++)
			if (boxes[j] + vec[max] <= b) {
				boxes[j] += vec[max];
				j = boxes.size();
				vec.erase(vec.begin()+max);
				flag = true;
			}
		if (!flag) {
			boxes.push_back(vec[max]);
			vec.erase(vec.begin() + max);
		}
		
		it = std::max_element(vec.begin(), vec.end());
	}
	int res=boxes.size();
	if (boxes[boxes.size() - 1])
		return res;
	return res - 1;
	
}


void decision_1_in_file(std::vector<int> vec, int b) {
	std::ofstream in_file("�������1.txt");
	clock_t start = clock();
	int res = decision_1( vec,  b);
	clock_t end = clock();
	in_file << res << " ";
	in_file << (double)(end - start) / CLOCKS_PER_SEC<<std::endl ;
	in_file.close();
}






int decision_2(std::vector<int> vec, int b, std::vector<int> &boxes) {
	if (vec.size()) {
		if (vec[0] > b)
			throw "��� �������� ������ ������� �����";
		if (vec[0] < 0)
			throw "��� �������� ������ ����";
		for(int i =0; i<boxes.size(); i++)
			if (vec[0] + boxes[i] <= b) {
				boxes[i] += vec[0];
				vec.erase(vec.begin());
				return decision_2(vec, b, boxes);
			}
		boxes.push_back(0);
		return 1 + decision_2(vec, b, boxes);
	}
	else
		return 0;
}

int decision_2_main(std::vector<int> vec, int b) {
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	std::vector<int> boxes;
	boxes.push_back(0);
	int res = decision_2(vec, b, boxes);
	if (boxes[boxes.size() - 1])
		res++;
	return res;
}
//������ �������� ������� ������
void decision_2_in_file(std::vector<int> vec, int b) {
	std::ofstream in_file("�������2.txt");
	clock_t start = clock();
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	std::vector<int> boxes;
	boxes.push_back(0);
	int res = decision_2(vec, b, boxes);
	if (boxes[boxes.size()-1])
		res++;
	clock_t end = clock();
	in_file << res << " ";
	in_file << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
	in_file.close();
}