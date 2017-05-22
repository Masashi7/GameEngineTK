/// <summary>
/// 3D�I�u�W�F�N�g�̃N���X
/// </summary>
#pragma once

#include <windows.h>
#include <wrl/client.h>
#include <d3d11_1.h>
#include <CommonStates.h>
#include <Effects.h>
#include <Model.h>
#include <SimpleMath.h>

#include "Camera.h"

class Obj3D
{
public:
	// �ÓI�I�����o�ϐ��̏�����
	static void InitializeStatic(
		Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice,
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext,
		Camera* camera);

private:
	// �ÓI�����o
	// �f�o�C�X
	static Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
	// �f�o�C�X�R���e�L�X�g
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
	// �J����
	static Camera*										   m_Camera;
	// �ėp�`��X�e�[�g
	static std::unique_ptr<DirectX::CommonStates>		   m_states;
	// �G�t�F�N�g�t�@�N�g��
	static std::unique_ptr<DirectX::EffectFactory>		   m_factory;

public:
	// �R���X�g���N�^
	Obj3D();
	// ���f���̃��[�h
	void LoadModel(const wchar_t* fileName);
	// �X�V
	void Update();
	// �`��
	void Draw();

	// Setter
	// �X�P�[�����O

	// ��]�p(XYZ)

	// ���s�ړ�(XYZ)

	// getter
	// �X�P�[�����O

	// ��]�p(xyz)

	// ���[���h�s��

	// ���s�ړ�(XYZ)

private:
	// �����o�ϐ�
	// 3D���f��

	// �X�P�[�����O

	// ��]�p(xyz)

	// ���[���h�s��

	// ���s�ړ�(XYZ)
};