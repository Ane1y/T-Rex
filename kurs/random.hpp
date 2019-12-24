#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

class Random
{
public:
	int operator ()(int min, int max);

private:
	std::mt19937 reg{ std::random_device{}() };
};

#endif