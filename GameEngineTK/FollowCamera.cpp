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
	// ���_�A�Q�Ɠ_
	Vector3 eyepos, refpos;

	// �^�[�Q�b�g�̍��W�́A�����̍��W�ɒǏ]�i����������ɂ��炷�j
	refpos = m_targetPos + Vector3(0, 2.0f, 0);
	// �^�[�Q�b�g���W����J�������W�ւ̍���
	Vector3 cameraV(0, 0, 5.0f);

	// �J�����̎��������̋t�����ɉ�]
	Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
	cameraV = Vector3::TransformNormal(cameraV, rotmat);

	// �J�������W���v�Z
	eyepos = refpos + cameraV;

	Seteyepos(eyepos);
	Setrefpos(refpos);

	// ���N���X�̍X�V
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