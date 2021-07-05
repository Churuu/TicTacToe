#pragma once

#include <string>

class Brick {
public:
	enum BrickType {
		Q = 0,
		X = 1,
		O = 2
	};
	
	BrickType GetBrickType();
	BrickType brickType;
};
