#ifndef RESULT_HANDLER_HPP
#define RESULT_HANDLER_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "constants.hpp"

struct result_t
{
	std::string name;
	int result;
};

class ResultHandler
{
public:	
	ResultHandler();
	~ResultHandler() = default;

	void update(const int score);
	void print();

private:
	std::vector<result_t> result_;
};

std::ostream& operator<< (std::ostream& out, const result_t &t);


#endif