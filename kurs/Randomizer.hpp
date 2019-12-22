#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <time.h>
#include <stdexcept>

class Randomizer
{
public:
	Randomizer();
	~Randomizer();
  
	template<typename T>
	T randomize(const T min, const T max);

};

#endif