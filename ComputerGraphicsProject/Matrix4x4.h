#pragma once

#ifndef _MATRIX_4X4_H_
#define _MATRIX_4X4_H_
#endif

#include <memory>
#include <string>

namespace Matrix4x4 {
	class Matrix4x4 {
	public:
		float values[4][4] = {};

		Matrix4x4(float(&initValues)[4][4]);

		void Add(Matrix4x4& matrix);
		void Subtract(Matrix4x4 const& matrix);
		void Multiply(Matrix4x4 const& matrix);
		void Invert();

		std::unique_ptr<Matrix4x4> operator + (Matrix4x4 const& matrix);
		std::unique_ptr<Matrix4x4> operator - (Matrix4x4 const& matrix);
		std::unique_ptr<Matrix4x4> operator * (Matrix4x4 const& matrix);

		std::unique_ptr<Matrix4x4> Inverse();

		std::string toString();
	};
}