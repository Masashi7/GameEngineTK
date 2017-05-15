#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include <Keyboard.h>

class Camera
{
public:
	// メンバ関数
	// コンストラクタ
	Camera(int width,int height);

	// デストラクタ
	virtual ~Camera();

	// 更新
	virtual void Update();

	// ビュー行列を取得
	DirectX::SimpleMath::Matrix GetViewMatrix();

	// 射影行列を取得
	DirectX::SimpleMath::Matrix GetProjectionMatrix();

	void Seteyepos(DirectX::SimpleMath::Vector3 eyepos);
	void Setrefpos(DirectX::SimpleMath::Vector3 refpos);
	void Setupvec(DirectX::SimpleMath::Vector3 upvec);
	void SetfovY(float fovY);
	void Setaspect(float aspect);
	void SetnearClip(float nearClip);
	void SetfarClip(float farClip);

private:
	// メンバ変数

	// 視点
	DirectX::SimpleMath::Vector3 m_eyepos;
	// 参照点/注視点 
	DirectX::SimpleMath::Vector3 m_refpos;
	// 上方向ベクトル
	DirectX::SimpleMath::Vector3 m_upvec;
	// 垂直方向視野角
	float m_fovY;
	// アスペクト比（横・縦の比率）
	float m_aspect;
	// ニアクリップ（手前の表示限界距離）
	float m_nearClip;
	// ファークリップ（奥の表示限界距離）
	float m_farClip;
};

//// 視点
//Vector3 eyepos(0, 0, 5.0f);
//// 参照点/注視点
//Vector3 refpos(0, 0, 0);
//
//// 上方向ベクトル（回るで）
//static float angle = 0.0f;
//angle += 0.1f;
//Vector3 upvec(cosf(angle), sinf(angle), 0);
//upvec.Normalize();	// ベクトルの正規化（長さを１にする）
//
//// 上方向ベクトル
//Vector3 upvec(cosf(angle), sinf(angle), 0);
//// ビュー行列を作成して代入
//m_view = Matrix::CreateLookAt(eyepos, refpos, upvec);

//// 垂直方向視野角
//float fovY = XMConvertToRadians(60.0f);
//// アスペクト比（横・縦の比率）
//float aspect = (float)m_outputWidth / m_outputHeight;
//// ニアクリップ（手前の表示限界距離）
//float nearClip = 0.1f;
//// ファークリップ（奥の表示限界距離）
//float farClip = 1000.0f;
//// 射影行列の生成（透視投影）
//m_proj = Matrix::CreatePerspectiveFieldOfView(fovY, aspect, nearClip, farClip);