#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include <Keyboard.h>

class Camera
{
public:
	// �����o�֐�
	// �R���X�g���N�^
	Camera(int width,int height);

	// �f�X�g���N�^
	virtual ~Camera();

	// �X�V
	virtual void Update();

	// �r���[�s����擾
	DirectX::SimpleMath::Matrix GetViewMatrix();

	// �ˉe�s����擾
	DirectX::SimpleMath::Matrix GetProjectionMatrix();

	void Seteyepos(DirectX::SimpleMath::Vector3 eyepos);
	void Setrefpos(DirectX::SimpleMath::Vector3 refpos);
	void Setupvec(DirectX::SimpleMath::Vector3 upvec);
	void SetfovY(float fovY);
	void Setaspect(float aspect);
	void SetnearClip(float nearClip);
	void SetfarClip(float farClip);

private:
	// �����o�ϐ�

	// ���_
	DirectX::SimpleMath::Vector3 m_eyepos;
	// �Q�Ɠ_/�����_ 
	DirectX::SimpleMath::Vector3 m_refpos;
	// ������x�N�g��
	DirectX::SimpleMath::Vector3 m_upvec;
	// ������������p
	float m_fovY;
	// �A�X�y�N�g��i���E�c�̔䗦�j
	float m_aspect;
	// �j�A�N���b�v�i��O�̕\�����E�����j
	float m_nearClip;
	// �t�@�[�N���b�v�i���̕\�����E�����j
	float m_farClip;
};

//// ���_
//Vector3 eyepos(0, 0, 5.0f);
//// �Q�Ɠ_/�����_
//Vector3 refpos(0, 0, 0);
//
//// ������x�N�g���i���Łj
//static float angle = 0.0f;
//angle += 0.1f;
//Vector3 upvec(cosf(angle), sinf(angle), 0);
//upvec.Normalize();	// �x�N�g���̐��K���i�������P�ɂ���j
//
//// ������x�N�g��
//Vector3 upvec(cosf(angle), sinf(angle), 0);
//// �r���[�s����쐬���đ��
//m_view = Matrix::CreateLookAt(eyepos, refpos, upvec);

//// ������������p
//float fovY = XMConvertToRadians(60.0f);
//// �A�X�y�N�g��i���E�c�̔䗦�j
//float aspect = (float)m_outputWidth / m_outputHeight;
//// �j�A�N���b�v�i��O�̕\�����E�����j
//float nearClip = 0.1f;
//// �t�@�[�N���b�v�i���̕\�����E�����j
//float farClip = 1000.0f;
//// �ˉe�s��̐����i�������e�j
//m_proj = Matrix::CreatePerspectiveFieldOfView(fovY, aspect, nearClip, farClip);