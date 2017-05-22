#include "Obj3D.h"

using namespace DirectX;

// �ÓI�����o�ϐ��̎���
// �f�o�C�X
Microsoft::WRL::ComPtr<ID3D11Device>            Obj3D::m_d3dDevice;
// �f�o�C�X�R���e�L�X�g
Microsoft::WRL::ComPtr<ID3D11DeviceContext>     Obj3D::m_d3dContext;
// �J����
Camera*											Obj3D::m_Camera;
// �ėp�`��X�e�[�g
std::unique_ptr<CommonStates>			Obj3D::m_states;
// �G�t�F�N�g�t�@�N�g��
std::unique_ptr<EffectFactory>			Obj3D::m_factory;

// �R���X�g���N�^
Obj3D::Obj3D()
{

}

void Obj3D::LoadModel(const wchar_t* fileName)
{

}

// �X�V
void Obj3D::Update()
{
	// ��ɍs��̌v�Z
}

// �`��
void Obj3D::Draw()
{

}

void Obj3D::InitializeStatic(
	Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice,
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext,
	Camera* camera)
{
	m_d3dDevice = d3dDevice;
	m_d3dContext = d3dContext;
	m_Camera = camera;

	// �ėp�`��X�e�[�g����
	m_states = std::make_unique<CommonStates>(m_d3dDevice.Get());

	// �G�t�F�N�g�t�@�N�g������
	m_factory = std::make_unique<EffectFactory>(m_d3dDevice.Get());
	// �e�N�X�`���̓ǂݍ��݃p�X��ݒ�
	m_factory->SetDirectory(L"Resources");
}