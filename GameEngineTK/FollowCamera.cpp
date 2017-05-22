#include "FollowCamera.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

const float FollowCamera::CAMERA_DISTANCE = 5.0f;

FollowCamera::FollowCamera(int width, int height)
	: m_targetPos(0, 0, 0)
	,Camera(width, height)
{
	m_targetAngle = 0.0f;
	m_keyboard = nullptr;
	m_isChangeFPS = false;
}

FollowCamera::~FollowCamera()
{

}

void FollowCamera::Update()
{
	// �L�[�{�[�h�̏�Ԏ擾
	Keyboard::State keyboardState = m_keyboard->GetState();
	m_keyboardTracker.Update(keyboardState);

	if (m_keyboardTracker.IsKeyPressed(Keyboard::Keys::C))
	{
		// �t���O�؂�ւ�
		m_isChangeFPS = !m_isChangeFPS;
	}

	if (m_isChangeFPS == true)
	{
		// ���_�A�Q�Ɠ_
		Vector3 eyepos, refpos;

		// �^�[�Q�b�g�̍��W�́A�����̍��W�ɒǏ]�i����������ɂ��炷�j
		eyepos = m_targetPos + Vector3(0, 0.75f, 0);
		// �^�[�Q�b�g���W����J�������W�ւ̍���
		Vector3 cameraV(0, 0, CAMERA_DISTANCE);

		// �J�����̎��������̋t�����ɉ�]
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		cameraV = Vector3::TransformNormal(cameraV, rotmat);

		// �J�������W���v�Z
		refpos = eyepos + cameraV;

		Seteyepos(eyepos);
		Setrefpos(refpos);

		// ���N���X�̍X�V
		Camera::Update();
	}
	else
	{
		// ���_�A�Q�Ɠ_
		Vector3 eyepos, refpos;

		// �^�[�Q�b�g�̍��W�́A�����̍��W�ɒǏ]�i����������ɂ��炷�j
		refpos = m_targetPos + Vector3(0, 2.0f, 0);
		// �^�[�Q�b�g���W����J�������W�ւ̍���
		Vector3 cameraV(0, 0, CAMERA_DISTANCE);

		// �J�����̎��������̋t�����ɉ�]
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		cameraV = Vector3::TransformNormal(cameraV, rotmat);

		// �J�������W���v�Z
		eyepos = refpos + cameraV;

		// ���_�����݈ʒu����⊮����
		eyepos = m_eyepos + (eyepos - m_eyepos) * 0.05f;
		// �Q�Ɠ_�����݈ʒu����⊮����
		refpos = m_refpos + (refpos - m_refpos) * 0.2f;

		Seteyepos(eyepos);
		Setrefpos(refpos);

		// ���N���X�̍X�V
		Camera::Update();
	}

}

void FollowCamera::SetTaegetPos(Vector3 targetPos)
{
	m_targetPos = targetPos;
}

void FollowCamera::SetTargetAngle(float targetAngle)
{
	m_targetAngle = targetAngle;
}

void FollowCamera::SetKeyboard(DirectX::Keyboard* keyboard)
{
	m_keyboard = keyboard;
}

// TPS�S���R�J�����}��
/*
// ���_�A�Q�Ɠ_
Vector3 eyepos, refpos;

// �^�[�Q�b�g�̍��W�́A�����̍��W�ɒǏ]�i����������ɂ��炷�j
refpos = m_targetPos + Vector3(0, 2.0f, 0);
// �^�[�Q�b�g���W����J�������W�ւ̍���
Vector3 cameraV(0, 0, CAMERA_DISTANCE);

// �J�����̎��������̋t�����ɉ�]
Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
cameraV = Vector3::TransformNormal(cameraV, rotmat);

// �J�������W���v�Z
eyepos = refpos + cameraV;

// ���_�����݈ʒu����⊮����
eyepos = m_eyepos + (eyepos - m_eyepos) * 0.05f;
// �Q�Ɠ_�����݈ʒu����⊮����
refpos = m_refpos + (refpos - m_refpos) * 0.2f;

Seteyepos(eyepos);
Setrefpos(refpos);

// ���N���X�̍X�V
Camera::Update();
*/

// FPS�J�����}��
/*
// ���_�A�Q�Ɠ_
Vector3 eyepos, refpos;

// �^�[�Q�b�g�̍��W�́A�����̍��W�ɒǏ]�i����������ɂ��炷�j
eyepos = m_targetPos + Vector3(0, 0.25f, 0);
// �^�[�Q�b�g���W����J�������W�ւ̍���
Vector3 cameraV(0, 0, CAMERA_DISTANCE);

// �J�����̎��������̋t�����ɉ�]
Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
cameraV = Vector3::TransformNormal(cameraV, rotmat);

// �J�������W���v�Z
refpos = eyepos + cameraV;

Seteyepos(eyepos);
Setrefpos(refpos);

// ���N���X�̍X�V
Camera::Update();
*/