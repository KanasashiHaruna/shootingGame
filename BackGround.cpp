#include "BackGround.h"
#include "Novice.h"

BackGround::BackGround() {
	
	posX_[0] = 0.0f;
	posX_[1] = 1280.0f;
	posY_ = 0.0f;
	speed_ = 1;
	bgRS_ = Novice::LoadTexture("./Resource/TITLE.png");
	rule_ = Novice::LoadTexture("./Resource/rule.png");
}
void BackGround::Update() {
	for (int i = 0; i < 2; i++) {
		posX_[i] = posX_[i] - speed_;
		if (posX_[i] <= -1280.0f) {
			posX_[i] = 1280.0f;
		}
	}
}
void BackGround::Draw() {
	for (int i = 0; i < 2; i++) {
		Novice::DrawSprite(
			(int)posX_[i], (int)posY_,
			bgRS_, 1, 1, 0.0f, WHITE
		);
	}
	Novice::DrawSprite(
		0, 0, rule_, 1, 1, 0.0f, WHITE
	);
}