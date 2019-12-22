#ifndef RESULT_HANDLER_HPP
#define RESULT_HANDLER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <fstream>

#include <algorithm>
struct result_t
{
	std::string name;
	int result;	/*
	result_t& operator= (const result_t &);
	result_t& operator= (result_t &&);
	bool operator== (const result_t &) const;
	*/

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
//bool operator > (const result_t &rhs, const result_t &lhs);

#endif