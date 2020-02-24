#include<string>
#include<vector>
#include <iostream>
#include "common.h"

class House
{
public:
	House(const std::string& filename);

	void move(Direction D);
	bool isWall() const;
	int isDirty() const;
	void clean();
	int total_dirt_level() const;
	int max_steps() const
	{
		return _max_steps;
	}
	void print()
	{
		for (size_t row = 0; row < _num_rows; ++row)
		{
			for (size_t col = 0; col < _num_cols; ++col)
			{
				std::cout << _floor[row * _num_rows + col];
			}
			std::cout << std::endl;
		}
	}
private:
	std::vector<int> _floor;
	std::string _desc = "";
	size_t _num_rows = 0;
	size_t _num_cols = 0;
	size_t _total_dirt_level = 0;
	size_t _max_steps = 0;
	size_t _current_pos = 0;
};