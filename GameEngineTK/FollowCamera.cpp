#include "FollowCamera.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

FollowCamera::FollowCamera(int width, int height)
	: m_targetPos(0, 0, 0)
	,Camera(width, height)
{
	m_targetAngle = 0.0f;
}

FollowCamera::~FollowCamera()
{

}

void FollowCamera::Update()
{
	// 視点、参照点
	Vector3 eyepos, refpos;

	// ターゲットの座標は、自分の座標に追従（少し上方向にずらす）
	refpos = m_targetPos + Vector3(0, 2.0f, 0);
	// ターゲット座標からカメラ座標への差分
	Vector3 cameraV(0, 0, 5.0f);

	// カメラの視線方向の逆方向に回転
	Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
	cameraV = Vector3::TransformNormal(cameraV, rotmat);

	// カメラ座標を計算
	eyepos = refpos + cameraV;

	Seteyepos(eyepos);
	Setrefpos(refpos);

	// 基底クラスの更新
	Camera::Update();
}

void FollowCamera::SetTaegetPos(Vector3 targetPos)
{
	m_targetPos = targetPos;
}

void FollowCamera::SetTargetAngle(float targetAngle)
{
	m_targetAngle = targetAngle;
}