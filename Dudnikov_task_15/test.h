#pragma once
#include <iostream>
#include <cassert>
#include "Header.h"


void maintest() {
	std::vector<int> v1 = { 0,0 ,0,0,0, 0};
	std::vector<int> boxes0;
	std::vector<int> boxes5;
	boxes0.push_back(0);
	assert(decision_1(v1, 5) == 0);
	assert(decision_2_main(v1, 5) == 0);
	std::vector<int> boxes;
	boxes.push_back(0);
	boxes5.push_back(0);
	std::cerr << "test 1 successfully" << std::endl;
	std::vector<int> v2 = { -432,40 ,30,20,2,3 };
	try { decision_1(v2, 950); }
	catch (const char*) { std::cerr << "test 2 successfully" << std::endl; }
	
	
	

	std::vector<int> v3 = { 40,0 ,0,0,0,2 };
	try { decision_1(v3, 4); }
	catch (const char*) {
		std::cerr << "test 3 successfully" << std::endl;
	}
	std::vector<int> v4 = { 2,3,5,2,3 };
	std::vector<int> v5 = { 2,3,5,3,2 };
	assert(decision_1(v4, 5) == 3);
	
	std::cerr << "test 4 successfully" << std::endl;
	assert(decision_2_main(v5, 5) == 3);
	std::vector<int> v = { 1,1,1,5,3,4 };
	assert(decision_1(v, 5) == 3);
	std::vector<int> boxes1;
	boxes1.push_back(0);
	v = { 1,1,1,5,3,4 };
	assert(decision_2_main(v, 5) == 3);
	std::cerr << "test 5 successfully" << std::endl;
}