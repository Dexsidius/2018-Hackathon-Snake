#pragma once
#include <iostream>

class Snake{
private:
	int points;
	int current_size;
	bool win_state;
	bool touching;

	void set_points(int);
	void set_current_size(int);

		

public:
	int get_points(int);
	int get_current_size(int);
	
};
