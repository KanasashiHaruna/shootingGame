#include <Novice.h>
#include "Player.h"
#include "BackGround.h"
#include "Enemy.h"
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LC1A_10_カナサシ_ハルナ";

enum Scene {
	TITLE,
	LOAD,
	GAME,
	GAMEOVER,
};
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player* player = new Player();
	BackGround* backRs = new BackGround();
	Enemy* enemy = new Enemy();
	Scene scene = TITLE;

	int title = Novice::LoadTexture("./Resource/titleName.png");
	int gameOver = Novice::LoadTexture("./Resource/GameOver.png");
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene) {
		case TITLE:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = LOAD;
			}
			break;
		case LOAD:
			player->Initial();
			enemy->Initial();
			scene = GAME;
			break;
		case GAME:
			backRs->Update();
			player->Update(keys, preKeys);
			enemy->Update(keys, preKeys);

			// 当たり判定　//----------------------------------------------------
			//自機と敵

			if (enemy->GetIsAlive() == true && (player->GetRadius() + enemy->GetRadius()) * (player->GetRadius() + enemy->GetRadius()) >=
				(enemy->GetPosX() - player->GetPosX()) * (enemy->GetPosX() - player->GetPosX()) +
				(enemy->GetPosY() - player->GetPosY()) * (enemy->GetPosY() - player->GetPosY())) {
				player->SetIsAlive(false);
			}

			//弾と敵
			if (enemy->GetIsAlive() == true && player->bullet_->GetIsShot() == true && (player->bullet_->GetRadius() + enemy->GetRadius()) * (player->bullet_->GetRadius() + enemy->GetRadius()) >=
				(enemy->GetPosX() - player->bullet_->GetPosX()) * (enemy->GetPosX() - player->bullet_->GetPosX()) +
				(enemy->GetPosY() - player->bullet_->GetPosY()) * (enemy->GetPosY() - player->bullet_->GetPosY())) {
				enemy->SetIsAlive(false);
			}
			if (player->GetIsAlive() == 0) {
				scene = GAMEOVER;
			}
			break;
		case GAMEOVER:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene =TITLE;
			}
			break;
		}
		Novice::ScreenPrintf(20, 20, "scene=%d", scene);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scene) {
		case TITLE:
			Novice::DrawSprite(0, 0, title, 1, 1, 0.0f, WHITE);
			break;
		case LOAD:
			break;
		case GAME:

			backRs->Draw();
			player->Draw();
			enemy->Draw();
			break;
		case GAMEOVER:
			Novice::DrawSprite(0, 0, gameOver, 1, 1, 0.0f, WHITE);
			break;
		}
		
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	delete player;
	return 0;
}
