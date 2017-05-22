#include "Obj3D.h"

using namespace DirectX;

// 静的メンバ変数の実態
// デバイス
Microsoft::WRL::ComPtr<ID3D11Device>            Obj3D::m_d3dDevice;
// デバイスコンテキスト
Microsoft::WRL::ComPtr<ID3D11DeviceContext>     Obj3D::m_d3dContext;
// カメラ
Camera*											Obj3D::m_Camera;
// 汎用描画ステート
std::unique_ptr<CommonStates>			Obj3D::m_states;
// エフェクトファクトリ
std::unique_ptr<EffectFactory>			Obj3D::m_factory;

// コンストラクタ
Obj3D::Obj3D()
{

}

void Obj3D::LoadModel(const wchar_t* fileName)
{

}

// 更新
void Obj3D::Update()
{
	// 主に行列の計算
}

// 描画
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

	// 汎用描画ステート生成
	m_states = std::make_unique<CommonStates>(m_d3dDevice.Get());

	// エフェクトファクトリ生成
	m_factory = std::make_unique<EffectFactory>(m_d3dDevice.Get());
	// テクスチャの読み込みパスを設定
	m_factory->SetDirectory(L"Resources");
}