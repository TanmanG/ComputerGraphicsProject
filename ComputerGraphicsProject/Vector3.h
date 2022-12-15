#pragma once

#ifndef _VECTOR_3_H_
#define _VECTOR_3_H_
#endif

#include <memory>
#include <string>

namespace Vector3 {
	class Vector3 {
	public:
		float x;
		float y;
		float z;

		Vector3(float x, float y, float z);

		void Normalize();
		std::unique_ptr<Vector3> _getnormalized();
		__declspec(property(get = _getnormalized)) std::unique_ptr<Vector3> normalized;
		float _getprop();
		__declspec(property(get = _getprop)) const float magnitude;
		std::unique_ptr<Vector3> operator + (Vector3 const& vec);
		std::unique_ptr<Vector3> operator - (Vector3 const& vec);
		std::unique_ptr<Vector3> operator * (float const& scalar);
		std::unique_ptr<Vector3> operator / (float const& scalar);
		std::unique_ptr<Vector3> Cross(Vector3 const& vec);
		float Dot(Vector3& vec);
		float Distance(Vector3& vec);
		float AngleBetween(Vector3& vecA, Vector3& vecB);
		float TangentDistance(Vector3& vecT, Vector3& vecP);
		std::unique_ptr<Vector3> TangentPoint(Vector3& vecT, Vector3& vecP);
	};
}
