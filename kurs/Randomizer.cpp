#include "Randomizer.hpp"

Randomizer::Randomizer()
{
	srand(time(NULL));
}

Randomizer::~Randomizer()
{}

template<typename T>
T Randomizer::randomize(const T min, const T max)
{
	if (min > max)
	{
		throw std::range_error("Randomizer min value more than max");
	}
	return (min + rand() % (max - min + 1));
}

