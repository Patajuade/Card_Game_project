
#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <stdlib.h> //pour le random
#include <time.h>  //pour le random
using namespace std;


class Utils {
public:
	Utils();
	~Utils();
	static int getRandomInt(int max) {
		return (rand() % max)+1;
	}
};

#endif