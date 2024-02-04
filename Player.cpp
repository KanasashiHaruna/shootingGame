#include "Player.h"
#include <Novice.h>

Player::Player() {
	Initial();
	playerRs_ = Novice::LoadTexture("./Resource/roket.png");
	bullet_ = new Bullet();
}
void Player::Initial() {
	pos_ = { 640.0f,360.0f };
	speed_ = 5;
	radius_ = 30;
	isAlive_ = true;
}
void Player::Update(char* keys,char* preKeys) {
	if (isAlive_ == true) {
		if (keys[DIK_W]) {
			pos_.y -= speed_;
		}
		if (keys[DIK_S]) {
			pos_.y += speed_;
		}
		if (keys[DIK_A]) {
			pos_.x -= speed_;
		}
		if (keys[DIK_D]) {
			pos_.x += speed_;
		}

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && bullet_->GetIsShot() == false) {
			bullet_->SetPosition(pos_.x, pos_.y);
			bullet_->SetIsShot(true);
		}
		bullet_->Update();
	}
}

void Player::SetIsAlive(bool isAlive) {
	isAlive_ = isAlive;
}
void Player::Draw() {
	if (isAlive_ == true) {
		bullet_->Draw();
		Novice::DrawSprite(
			(int)pos_.x-64, (int)pos_.y-64,
			playerRs_, 1, 1, 0.0f, WHITE
		);
		//Novice::DrawEllipse(
		//	(int)pos_.x , (int)pos_.y,
		//	radius_, radius_, 0.0f, WHITE, kFillModeWireFrame
		//);
	}
}