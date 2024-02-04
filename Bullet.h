#pragma once
#include "Vec2.h"

class Bullet {
private:
	Vec2 pos_;
	int speed_;
	int bulletRS_;
	bool isShot_;
	int radius_;

public:
	Bullet();
	void Update();
	void Draw();

	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	bool GetIsShot() { return isShot_; };
	int GetRadius() { return radius_; };

	void SetPosition(float x, float y);
	void SetIsShot(bool isShot);
};