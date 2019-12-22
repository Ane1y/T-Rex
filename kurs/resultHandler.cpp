#include "resultHandler.hpp"
/*
bool operator > (const result_t &rhs, const result_t &lhs)
{
	return (rhs.result > lhs.result);
}
*/
std::ostream& operator<< (std::ostream& out, const result_t &t)
{
	out << t.name << " " << t.result;
	return out;
}
/*
result_t &result_t::operator=(const result_t &rhs)
{
	this->name = rhs.name;
	this->result = rhs.result;

	return *this;
}

result_t & result_t::operator=(result_t &&rhs)
{
	this->name = rhs.name;
	this->result = rhs.result;

	return *this;
}

bool result_t::operator==(const result_t &rhs)  const
{
	return (rhs.name == this->name) && (rhs.result == this->result);
}
*/
ResultHandler::ResultHandler()
{
	std::ifstream file;
	file.open("result.txt");
	result_t tmp;
	while (!file.eof())
	{
		file >> tmp.name >> tmp.result;
		result_.push_back(tmp);
	}
}



void ResultHandler::update(const int score)
{
	std::ofstream resultFile;
	resultFile.open("result.txt", std::ios::app);
	std::string name;
	std::cout << "Enter your name\n";
	std::cin >> name;
	result_.push_back({ name, score });
	resultFile << name << " " << score << "\n";

	std::sort(result_.begin(), result_.end(), [](const result_t &lhs, const result_t &rhs)
	{ return lhs.result > rhs.result; });

	//std::copy(result_.begin(), result_.end(), std::ostream_iterator<std::pair<std::string, int> >(std::cout, "\n"));
}

void ResultHandler::print()
{
  
	std::copy(result_.begin(), result_.end(), std::ostream_iterator<result_t>(std::cout, "\n"));
  std::cout << std::endl;
}

