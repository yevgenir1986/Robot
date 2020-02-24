#include "House.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>


House::House(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	std::string str;

	std::getline(file, _desc);
	std::getline(file, str);
	_max_steps = std::stoi(str);
	std::getline(file, str);
	
	std::stringstream ss(str);
	std::string token;
	getline(ss, token, ',');
	_num_rows = std::stoi(token);
	getline(ss, token, ',');
	_num_cols = std::stoi(token);

	_floor.resize(_num_rows * _num_cols, -1);

	for (size_t row = 0; row < _num_rows; ++row)
	{
		if (!std::getline(file, str))
		{
			return;
		}
		if (row == 0 || row == _num_rows -1)
		{
			continue;
		}
		
		for (size_t col = 0; col < std::min(_num_cols, str.size()); ++col)
		{
			if (col == 0 || col == _num_cols - 1)
			{
				continue;
			}
			char c = str[col];
			size_t idx = row * _num_rows + col;
			if (isdigit(c))
			{
				int dirt_level = c - '0';
				_floor[idx] = dirt_level;
				_total_dirt_level += dirt_level;
				continue;
			}
			if(c == ' ')
			{
				_floor[idx] = 0;
				continue;
			}
			if (c == 'D')
			{
				_floor[idx] = -2;
				continue;
			}
		}
	}
}

void House::move(Direction d)
{
	switch (d)
	{
    case Direction::UP:
		if (_current_pos > _num_cols)
		{
			_current_pos -= _num_cols;
		}
		break;
	case Direction::DOWN:
		if (_current_pos > _num_rows)
		{
			_current_pos -= _num_cols;
		}
		break;
    case Direction::LEFT:
        //TODO: fill it
        break;
    case Direction::RIGHT:
        //TODO: fill it
        break;
    case Direction::STAY:
        //TODO: fill it
        break;
	}
}

bool House::isWall() const
{
//	int idx = row * _num_rows + col;
//	return (_floor[idx] == -1);
return true;
}

int House::isDirty() const
{
//	int idx = row * _num_rows + col;
//	int dirt_level = std::min(_floor[idx], 0);
//	return dirt_level;
return 0;
}

void House::clean()
{
//	int idx = row * _num_rows + col;
//
//	int& dirt_level = _floor[idx];
//	if (dirt_level > 0)
//	{
//		--dirt_level;
//		--_total_dirt_level;
//	}
}

int House::total_dirt_level() const
{
	return _total_dirt_level;
}


//int main()
//{
//	House h("h1.txt");
//	std::cout << "total: " << h.total_dirt_level() << std::endl;
//	h.print();
//	std::cout << "bye bye" << std::endl;
//	std::cin;
//}