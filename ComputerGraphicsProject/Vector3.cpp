#pragma once

#include "Vector3.h"

namespace Vector3 {
    // Constructor
    Vector3::Vector3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Member Functions
    void Vector3::Normalize() {
        // Store the magnitude.
        float normalizor = this->magnitude;

        // Normalize each variable in the struct.
        this->x /= normalizor;
        this->y /= normalizor;
        this->z /= normalizor;
    }

    // Normalized property!
    std::unique_ptr<Vector3> Vector3::_getnormalized()
    {
        // Return a pointer to a new, normalized Vector3
        return *this / magnitude;
    }
    // Magnitude property!
    float Vector3::_getprop() {
        return sqrt(x * x + y * y + z * z);
    }

    // Get the cross product of this vector with another
    std::unique_ptr<Vector3> Vector3::Cross(Vector3 const& vec) {
        return std::unique_ptr<Vector3>(new Vector3{
            {y * vec.z - z * vec.y},
            {z * vec.x - x * vec.z},
            {x * vec.y - y * vec.x},
            });
    }

    // Get the dot product of this vector with another
    float Vector3::Dot(Vector3& vec) {
        return (x * vec.x + y * vec.y + z * vec.z);
    }

    // Operator Implementations
    std::unique_ptr<Vector3> Vector3::operator + (Vector3 const& vec) {
        return std::unique_ptr<Vector3>(new Vector3{
            {x + vec.x},
            {y + vec.y},
            {z + vec.z},
            });
    }
    std::unique_ptr<Vector3> Vector3::operator - (Vector3 const& vec) {
        return std::unique_ptr<Vector3>(new Vector3{
            {x - vec.x},
            {y - vec.y},
            {z - vec.z},
            });
    }
    std::unique_ptr<Vector3> Vector3::operator * (float const& scalar) {
        return std::unique_ptr<Vector3>(new Vector3{
            {x * scalar},
            {y * scalar},
            {z * scalar},
            });
    }
    std::unique_ptr<Vector3> Vector3::operator / (float const& scalar) {
        return std::unique_ptr<Vector3>(new Vector3{
            {x / scalar},
            {y / scalar},
            {z / scalar},
            });
    }

    // Get the distance between this and the provided vector.
    float Vector3::Distance(Vector3& vec) {
        return (*this - vec)->magnitude;
    }

    float Vector3::AngleBetween(Vector3& vecA, Vector3& vecB) {
        auto shiftedVecA = vecA - *this;
        auto shiftedVecB = vecB - *this;
        return acosf(shiftedVecB->Dot(*shiftedVecA) / (shiftedVecA->magnitude * shiftedVecB->magnitude));
    }

    // Returns the distance to the point along vecT's direction that's nearest to point vecP.
    float Vector3::TangentDistance(Vector3& vecT, Vector3& vecP) {
        return this->Distance(vecP) * cos(this->AngleBetween(*(vecT + *this), vecP));
    }

    // Returns a Vector3 representing the nearest point to vecP along vecT's path, which starts from the calling vectors position.
    std::unique_ptr<Vector3> Vector3::TangentPoint(Vector3& vecT, Vector3& vecP) {
        return *(vecT + *this)->normalized * this->TangentDistance(vecT, vecP);
    }
};