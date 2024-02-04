#include "Enemy.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy() {
	Initial();
	enemyRs_ = Novice::LoadTexture("./Resource/space_cat.png");
}

void Enemy::Initial() {
	pos_ = { -256.0f,200.0f };
	speed_ = 3;
	theta_ = 0.0f;
	amplitude_ = 20.0f;
	isAlive_ = true;
	radius_ = 60;
}
void Enemy::Update(char* keys, char* preKeys) {
	if (isAlive_ == true) {
		pos_.x += speed_;
		pos_.y = sinf(theta_) * amplitude_ + 128.0f;
		theta_ += (float)M_PI / 30.0f;

		if (pos_.x >= 1536) {
			pos_.x = -256.0f;
		}
	}
	if (keys[DIK_R] && preKeys[DIK_R] == 0) {
		isAlive_ = 1;
	}
}

void Enemy::SetIsAlive(bool isAlive) {
	isAlive_ = isAlive;
}

void Enemy::Draw() {
	if (isAlive_ == true) {
		Novice::DrawSprite(
			(int)pos_.x-128, (int)pos_.y-128,
			enemyRs_, 1, 1, 0.0f, WHITE
		);
		//Novice::DrawEllipse(
		//	(int)pos_.x , (int)pos_.y,
		//	radius_, radius_, 0.0f, WHITE, kFillModeWireFrame
		//);
	}
}