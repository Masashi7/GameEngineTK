#pragma once

#include "Camera.h"

class FollowCamera :public Camera
{
private:
	static const float CAMERA_DISTANCE;

protected:

	DirectX::SimpleMath::Vector3 m_targetPos;

	float m_targetAngle;

public:

	FollowCamera(int width, int height);

	virtual ~FollowCamera();

	void Update();

	void SetTaegetPos(DirectX::SimpleMath::Vector3 targetPos);

	void SetTargetAngle(float targetAngle);
};