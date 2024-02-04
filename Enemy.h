#pragma once
#include "Vec2.h"

class Enemy {
private:
	Vec2 pos_;
	int speed_;
	int enemyRs_;
	float theta_;
	float amplitude_;
	bool isAlive_;
	int radius_;

public:
	Enemy();
	void Initial();
	void Update(char* keys, char* preKeys);
	void Draw();
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	int GetRadius() { return radius_; };
	bool GetIsAlive() { return isAlive_; };

	void SetIsAlive(bool isAlive);
};
