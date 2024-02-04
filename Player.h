#pragma once
#include "Vec2.h"
#include "Bullet.h"
class Player
{
private:
	Vec2 pos_;
	int speed_;
	int playerRs_;
	int radius_;
	bool isAlive_;

public:
	Player();
	void Initial();
	void Update(char* keys,char* preKeys);
	void Draw();
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	int GetRadius() { return radius_; };
	float GetIsAlive() { return isAlive_; };

	void SetIsAlive(bool isAlive);

public:
	Bullet* bullet_;
};

