#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {
	pos_.x = 640.0f;
	pos_.y = 360.0f;
	speed_ = 10;
	bulletRS_ = Novice::LoadTexture("./Resource/star.png");
	isShot_ = false;
	radius_ = 15;
}

void Bullet::Update() {
	if (isShot_ == true) {
		pos_.y -= speed_;
	}
	if (pos_.y <= -64.0f) {
		isShot_ = false;
	}
}

void Bullet::SetPosition(float x, float y) {
	pos_.x = x;
	pos_.y = y;
}

void Bullet::SetIsShot(bool isShot) {
	isShot_ = isShot;
}
void Bullet::Draw() {
	if (isShot_ == true) {
		Novice::DrawSprite(
			(int)pos_.x-32, (int)pos_.y-32,
			bulletRS_, 1, 1, 0.0f, WHITE
		);
		Novice::DrawEllipse(
			(int)pos_.x, (int)pos_.y ,
			radius_, radius_, 0.0f, WHITE, kFillModeWireFrame
		);
	}

}