#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h> 
// Файл с алгоритмами решения задачи решения.
/*
//Первый алгоритм решения задачи
int decision_1(std::vector<int> vec, int b) {
	bool flag = false;
	int max = 0;
	std::vector<int> boxes;
	boxes.push_back(0);
	//Заполнение массива ящиков нулями, для возможности сравнения и проверка веса предметов начального массива
	auto it = std::max_element(vec.begin(), vec.end());
	// Пока все элементы не обнулили
	while (vec.size()) {
		flag = false;
		max = std::distance(vec.begin(), it);
		if (vec[max] > b)
			throw "Вес предмета больше размера ящика";
		if (vec[0] < 0)
			throw "Вес предмета меньше нуля";
		// Заполнение ящиков и обнуление элементов при их перемещении
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
	std::ofstream in_file("Решение1.txt");
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
			throw "Вес предмета больше размера ящика";
		if (vec[0] < 0)
			throw "Вес предмета меньше нуля";
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
//Второй алгоритм решения задачи
void decision_2_in_file(std::vector<int> vec, int b) {
	std::ofstream in_file("Решение2.txt");
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

*/


int decision_rekurs1(std::vector<int> vec, std::vector<int> boxes, int b,  int j) 
{
	if (vec.size() != 0)
	{
		int a, c;
		std::vector<int> newVec;
		newVec.reserve(vec.size());
		copy(vec.begin(), vec.end(), back_inserter(newVec));
		std::vector<int> newBox;
		newBox.reserve(boxes.size());
		copy(boxes.begin(), boxes.end(), back_inserter(newBox));
		if (vec[0] + boxes[j] <= b)
		{
			boxes[j] += vec[0];
			vec.erase(vec.begin() );
			a = decision_rekurs1(vec, boxes, b,  0);
		}
		else
		{
			if (j == boxes.size() - 1)
			{
				boxes.push_back(vec[0]);
				vec.erase(vec.begin());
				a = 1 + decision_rekurs1(vec, boxes, b,  0);
			}
			else
				a = decision_rekurs1(vec, boxes, b,  ++j);
		}

		if (j == newBox.size() - 1)
		{
			newBox.push_back(newVec[0]);
			newVec.erase(newVec.begin() );
			c = 1 + decision_rekurs1(newVec, newBox, b, 0);
		}
		else
			c = decision_rekurs1(newVec, newBox, b, ++j);
		if (a > c)
			return c;
		return a;
	}
	else
		return 0;
}




int decision_rekurs(std::vector<int> vec, std::vector<int> boxes, int b,int i, int j)
{
	if (i != vec.size())
	{
		int a, c;
	
		std::vector<int> newBox;
		newBox.reserve(boxes.size());
		copy(boxes.begin(), boxes.end(), back_inserter(newBox));
		if (vec[i] + boxes[j] <= b)
		{
			boxes[j] += vec[i];
			
			a = decision_rekurs(vec, boxes, b, i+1, 0);
		}
		else
		{
			if (j == boxes.size() - 1)
			{
				boxes.push_back(vec[i]);
			
				a = 1 + decision_rekurs(vec, boxes, b,i+1, 0);
			}
			else
				a = decision_rekurs(vec, boxes, b, i,j+1);
		}

		if (j == newBox.size() - 1)
		{
			newBox.push_back(vec[i]);
			
			c = 1 + decision_rekurs(vec, newBox, b,i+1, 0);
		}
		else
			c = decision_rekurs(vec, newBox, b,i, j+1);
		if (a > c)
			return c;
		return a;
	}
	else
		return 0;
}



int main_decision(std::vector<int> vec, int b) {
	std::vector<int> boxes;
	int i = 0;
	while (vec[i] == 0 && i<vec.size())
		i++;
	if (i == vec.size())
		return 0;
	boxes.push_back(vec[0]);
	vec.erase(vec.begin());
	int res = 1 + decision_rekurs(vec, boxes, b,0, 0);
	
	return res;
}

int main_decision1(std::vector<int> vec, int b) {
	std::vector<int> boxes;
	int i = 0;
	while (vec[i] == 0 && i < vec.size())
		i++;
	if (i == vec.size())
		return 0;
	boxes.push_back(vec[0]);
	vec.erase(vec.begin());
	int res = 1 + decision_rekurs1(vec, boxes, b,  0);

	return res;
}


void decision_main_in_file(std::vector<int> vec, int b)
{
	std::ofstream in_file("Решение.txt");
	clock_t start = clock();
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	

	int res = main_decision(vec, b);
	clock_t end = clock();
	in_file << res << " ";
	in_file << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
	clock_t start1 = clock();
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	
	
	res = main_decision1(vec, b);
	clock_t end1 = clock();
	in_file << res << " ";
	in_file << (double)(end1 - start1) / CLOCKS_PER_SEC << std::endl;
	in_file.close();
}