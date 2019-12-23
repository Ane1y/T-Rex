#include "resultHandler.hpp"

std::ostream& operator<< (std::ostream& out, const result_t &t)
{
	out << t.name << " " << t.result;
	return out;
}

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
	result_t res{"name", score};
	std::cout << "Enter your name\n";
	std::cin >> res.name;
	result_.push_back(res);
	resultFile << res.name << " " << res.result << "\n";

	std::sort(result_.begin(), result_.end(), [](const result_t &lhs, const result_t &rhs)
	{ return lhs.result > rhs.result; });
	if (result_.size() > Constants::maxRecordList + 1)
	{	
		result_.erase(result_.begin() + Constants::maxRecordList, result_.end());
	}
	auto tmp = std::find_if(result_.begin(), result_.begin() + Constants::maxRecordList - 1, [&res](const result_t &t)
	{ return (t.name == res.name && t.result == res.result); });
	if (!(tmp->name == res.name && tmp->result == res.result))
	{
		result_.push_back(res);
	}

}

void ResultHandler::print()
{
	std::cout << "Top 10 players:";
	std::copy(result_.begin(), result_.end(), std::ostream_iterator<result_t>(std::cout, "\n"));
  std::cout << std::endl;
}

