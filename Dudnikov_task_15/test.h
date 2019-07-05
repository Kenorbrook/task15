#pragma once
#include <iostream>
#include <cassert>
#include "Header.h"


void maintest() {
	std::vector<int> v = { 0,0,0,0 };
	assert(main_decision(v, 1) == 0);
	std::cerr << "test 1 successfully" << std::endl;
	
	
	

	std::vector<int> v3 = { 40,0 ,0,0,0,2 };
	
	assert(main_decision(v3, 40) == 2);
	std::cerr << "test 2 successfully" << std::endl;

	std::vector<int> v2 = { 7,7 ,7,4,4,4,4,4,4 };

	assert(main_decision(v2,15) == 3);
	std::cerr << "test 3 successfully" << std::endl;
}