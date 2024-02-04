#pragma once
#include "Vec2.h"

class BackGround {
public:
	float posX_[2];
	float posY_;
	int speed_;
	int bgRS_;
	int rule_;

public:
	BackGround();
	void Update();
	void Draw();
};
