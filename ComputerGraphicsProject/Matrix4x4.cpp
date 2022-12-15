#pragma once

#include "Matrix4x4.h"
#include <sstream>

namespace Matrix4x4
{
    Matrix4x4::Matrix4x4(float(&initValues)[4][4]) {
        float* currRowA = values[0];
        float* currRowB = initValues[0];
        currRowA[0] = currRowB[0];
        currRowA[1] = currRowB[1];
        currRowA[2] = currRowB[2];
        currRowA[3] = currRowB[3];

        currRowA = values[1];
        currRowB = initValues[1];
        currRowA[0] = currRowB[0];
        currRowA[1] = currRowB[1];
        currRowA[2] = currRowB[2];
        currRowA[3] = currRowB[3];

        currRowA = values[2];
        currRowB = initValues[2];
        currRowA[0] = currRowB[0];
        currRowA[1] = currRowB[1];
        currRowA[2] = currRowB[2];
        currRowA[3] = currRowB[3];

        currRowA = values[3];
        currRowB = initValues[3];
        currRowA[0] = currRowB[0];
        currRowA[1] = currRowB[1];
        currRowA[2] = currRowB[2];
        currRowA[3] = currRowB[3];
    }

    void Matrix4x4::Add(Matrix4x4& matrix) {
        float* matrixValues = (float*)(matrix.values);

        // Row 1
        float* currRowA = values[0];
        float* currRowB = &matrixValues[0];
        currRowA[0] += currRowB[0];
        currRowA[1] += currRowB[1];
        currRowA[2] += currRowB[2];
        currRowA[3] += currRowB[3];

        // Row 2
        currRowA = values[1];
        currRowB = &matrixValues[1];
        currRowA[0] += currRowB[0];
        currRowA[1] += currRowB[1];
        currRowA[2] += currRowB[2];
        currRowA[3] += currRowB[3];

        // Row 3
        currRowA = values[2];
        currRowB = &matrixValues[2];
        currRowA[0] += currRowB[0];
        currRowA[1] += currRowB[1];
        currRowA[2] += currRowB[2];
        currRowA[3] += currRowB[3];

        // Row 4
        currRowA = values[3];
        currRowB = &matrixValues[3];
        currRowA[0] += currRowB[0];
        currRowA[1] += currRowB[1];
        currRowA[2] += currRowB[2];
        currRowA[3] += currRowB[3];
    }
    void Matrix4x4::Subtract(Matrix4x4 const& matrix) {
        float* matrixValues = (float*)(matrix.values);

        // Row 1
        float* currRowA = values[0];
        float* currRowB = &matrixValues[0];
        currRowA[0] -= currRowB[0];
        currRowA[1] -= currRowB[1];
        currRowA[2] -= currRowB[2];
        currRowA[3] -= currRowB[3];

        // Row 2
        currRowA = values[1];
        currRowB = &matrixValues[1];
        currRowA[0] -= currRowB[0];
        currRowA[1] -= currRowB[1];
        currRowA[2] -= currRowB[2];
        currRowA[3] -= currRowB[3];

        // Row 3
        currRowA = values[2];
        currRowB = &matrixValues[2];
        currRowA[0] -= currRowB[0];
        currRowA[1] -= currRowB[1];
        currRowA[2] -= currRowB[2];
        currRowA[3] -= currRowB[3];

        // Row 4
        currRowA = values[3];
        currRowB = &matrixValues[3];
        currRowA[0] -= currRowB[0];
        currRowA[1] -= currRowB[1];
        currRowA[2] -= currRowB[2];
        currRowA[3] -= currRowB[3];
    }
    void Matrix4x4::Multiply(Matrix4x4 const& matrix) {
        float* matrixValues = (float*)(matrix.values);
        float vals[4][4] = {};

        // Source matrix row 1
        float* currColLeft = values[0];
        vals[0][0] = currColLeft[0] * matrix.values[0][0]
            + currColLeft[1] * matrix.values[1][0]
            + currColLeft[2] * matrix.values[2][0]
            + currColLeft[3] * matrix.values[3][0];
        vals[0][1] = currColLeft[0] * matrix.values[0][1]
            + currColLeft[1] * matrix.values[1][1]
            + currColLeft[2] * matrix.values[2][1]
            + currColLeft[3] * matrix.values[3][1];
        vals[0][2] = currColLeft[0] * matrix.values[0][2]
            + currColLeft[1] * matrix.values[1][2]
            + currColLeft[2] * matrix.values[2][2]
            + currColLeft[3] * matrix.values[3][2];
        vals[0][3] = currColLeft[0] * matrix.values[0][3]
            + currColLeft[1] * matrix.values[1][3]
            + currColLeft[2] * matrix.values[2][3]
            + currColLeft[3] * matrix.values[3][3];

        // Source matrix row 2
        currColLeft = values[1];
        vals[1][0] = currColLeft[0] * matrix.values[0][0]
            + currColLeft[1] * matrix.values[1][0]
            + currColLeft[2] * matrix.values[2][0]
            + currColLeft[3] * matrix.values[3][0];
        vals[1][1] = currColLeft[0] * matrix.values[0][1]
            + currColLeft[1] * matrix.values[1][1]
            + currColLeft[2] * matrix.values[2][1]
            + currColLeft[3] * matrix.values[3][1];
        vals[1][2] = currColLeft[0] * matrix.values[0][2]
            + currColLeft[1] * matrix.values[1][2]
            + currColLeft[2] * matrix.values[2][2]
            + currColLeft[3] * matrix.values[3][2];
        vals[1][3] = currColLeft[0] * matrix.values[0][3]
            + currColLeft[1] * matrix.values[1][3]
            + currColLeft[2] * matrix.values[2][3]
            + currColLeft[3] * matrix.values[3][3];

        // Source matrix row 3
        currColLeft = values[2];
        vals[2][0] = currColLeft[0] * matrix.values[0][0]
            + currColLeft[1] * matrix.values[1][0]
            + currColLeft[2] * matrix.values[2][0]
            + currColLeft[3] * matrix.values[3][0];
        vals[2][1] = currColLeft[0] * matrix.values[0][1]
            + currColLeft[1] * matrix.values[1][1]
            + currColLeft[2] * matrix.values[2][1]
            + currColLeft[3] * matrix.values[3][1];
        vals[2][2] = currColLeft[0] * matrix.values[0][2]
            + currColLeft[1] * matrix.values[1][2]
            + currColLeft[2] * matrix.values[2][2]
            + currColLeft[3] * matrix.values[3][2];
        vals[2][3] = currColLeft[0] * matrix.values[0][3]
            + currColLeft[1] * matrix.values[1][3]
            + currColLeft[2] * matrix.values[2][3]
            + currColLeft[3] * matrix.values[3][3];

        // Source matrix row 4
        currColLeft = values[3];
        vals[3][0] = currColLeft[0] * matrix.values[0][0]
            + currColLeft[1] * matrix.values[1][0]
            + currColLeft[2] * matrix.values[2][0]
            + currColLeft[3] * matrix.values[3][0];
        vals[3][1] = currColLeft[0] * matrix.values[0][1]
            + currColLeft[1] * matrix.values[1][1]
            + currColLeft[2] * matrix.values[2][1]
            + currColLeft[3] * matrix.values[3][1];
        vals[3][2] = currColLeft[0] * matrix.values[0][2]
            + currColLeft[1] * matrix.values[1][2]
            + currColLeft[2] * matrix.values[2][2]
            + currColLeft[3] * matrix.values[3][2];
        vals[3][3] = currColLeft[0] * matrix.values[0][3]
            + currColLeft[1] * matrix.values[1][3]
            + currColLeft[2] * matrix.values[2][3]
            + currColLeft[3] * matrix.values[3][3];

        // Assign the calculated multiplications to this
        float* currColAssign = values[0];
        currColLeft = vals[0];
        currColAssign[0] = currColLeft[0];
        currColAssign[1] = currColLeft[1];
        currColAssign[2] = currColLeft[2];
        currColLeft[3] = currColLeft[3];

        currColAssign = values[1];
        currColLeft = vals[1];
        currColAssign[0] = currColLeft[0];
        currColAssign[1] = currColLeft[1];
        currColAssign[2] = currColLeft[2];
        currColAssign[3] = currColLeft[3];

        currColAssign = values[2];
        currColLeft = vals[2];
        currColAssign[0] = currColLeft[0];
        currColAssign[1] = currColLeft[1];
        currColAssign[2] = currColLeft[2];
        currColAssign[3] = currColLeft[3];

        currColAssign = values[3];
        currColLeft = vals[3];
        currColAssign[0] = currColLeft[0];
        currColAssign[1] = currColLeft[1];
        currColAssign[2] = currColLeft[2];
        currColAssign[3] = currColLeft[3];
    }
    void Matrix4x4::Invert() {
        float inverse[4][4] = {};
        float inverseDeterminant;
        float* currColRight;
        float currColLeft;

        // Pre-compute Cached Values for A~
        currColRight = values[1];
        currColLeft = values[0][0];
        float cache_1122 = currColLeft * currColRight[1];
        float cache_1123 = currColLeft * currColRight[2];
        float cache_1124 = currColLeft * currColRight[3];

        currColLeft = values[0][1];
        float cache_1221 = currColLeft * currColRight[0];
        float cache_1223 = currColLeft * currColRight[2];
        float cache_1224 = currColLeft * currColRight[3];

        currColLeft = values[0][2];
        float cache_1321 = currColLeft * currColRight[0];
        float cache_1322 = currColLeft * currColRight[1];
        float cache_1324 = currColLeft * currColRight[3];

        currColLeft = values[0][3];
        float cache_1421 = currColLeft * currColRight[0];
        float cache_1422 = currColLeft * currColRight[1];
        float cache_1423 = currColLeft * currColRight[2];

        currColRight = values[3];
        currColLeft = values[2][0];
        float cache_3142 = currColLeft * currColRight[1];
        float cache_3143 = currColLeft * currColRight[2];
        float cache_3144 = currColLeft * currColRight[3];

        currColLeft = values[2][1];
        float cache_3241 = currColLeft * currColRight[0];
        float cache_3243 = currColLeft * currColRight[2];
        float cache_3244 = currColLeft * currColRight[3];

        currColLeft = values[2][2];
        float cache_3341 = currColLeft * currColRight[0];
        float cache_3342 = currColLeft * currColRight[1];
        float cache_3344 = currColLeft * currColRight[3];

        currColLeft = values[2][3];
        float cache_3441 = currColLeft * currColRight[0];
        float cache_3442 = currColLeft * currColRight[1];
        float cache_3443 = currColLeft * currColRight[2];

        // Compute Cache Differences
        float cacheDiff_3443_3344 = cache_3443 - cache_3344;
        float cacheDiff_3244_3442 = cache_3244 - cache_3442;
        float cacheDiff_3342_3243 = cache_3342 - cache_3243;
        float cacheDiff_1223_1322 = cache_1223 - cache_1322;
        float cacheDiff_1324_1423 = cache_1324 - cache_1423;
        float cacheDiff_1422_1224 = cache_1422 - cache_1224;
        float cacheDiff_3441_3144 = cache_3441 - cache_3144;
        float cacheDiff_3143_3341 = cache_3143 - cache_3341;
        float cacheDiff_1123_1321 = cache_1123 - cache_1321;
        float cacheDiff_1421_1124 = cache_1421 - cache_1124;
        float cacheDiff_3241_3142 = cache_3241 - cache_3142;
        float cacheDiff_1221_1122 = cache_1221 - cache_1122;

        // Row 1
        float* currColAssign;
        currColAssign = inverse[0];
        currColRight = values[0];
        currColAssign[1] = currColRight[1] * (cacheDiff_3443_3344)
                        + currColRight[2] * (cacheDiff_3244_3442)
                        + currColRight[3] * (cacheDiff_3342_3243);
        currColRight = values[1];
        currColAssign[0] = currColRight[1] * (-cacheDiff_3443_3344)
                        + currColRight[2] * (-cacheDiff_3244_3442)
                        + currColRight[3] * (-cacheDiff_3342_3243);

        currColRight = values[3];
        currColAssign[2] = currColRight[3] * (cacheDiff_1223_1322)
                        + currColRight[1] * (cacheDiff_1324_1423)
                        + currColRight[2] * (cacheDiff_1422_1224);
        currColRight = values[2];
        currColAssign[3] = currColRight[3] * (-cacheDiff_1223_1322)
                        + currColRight[1] * (-cacheDiff_1324_1423)
                        + currColRight[2] * (-cacheDiff_1422_1224);

        // Row 2
        currColAssign = inverse[1];
        currColRight = values[0];
        currColAssign[1] = currColRight[0] * (-cacheDiff_3443_3344)
                        + currColRight[2] * (cacheDiff_3441_3144)
                        + currColRight[3] * (cacheDiff_3143_3341);
        currColRight = values[1];
        currColAssign[0] = currColRight[0] * (cacheDiff_3443_3344)
                        + currColRight[2] * (-cacheDiff_3441_3144)
                        + currColRight[3] * (-cacheDiff_3143_3341);


        currColRight = values[2];
        currColAssign[3] = currColRight[3] * (cacheDiff_1123_1321)
                        + currColRight[0] * (cacheDiff_1324_1423)
                        + currColRight[2] * (cacheDiff_1421_1124);
        currColRight = values[3];
        currColAssign[2] = currColRight[3] * (-cacheDiff_1123_1321)
                        + currColRight[0] * (-cacheDiff_1324_1423)
                        + currColRight[2] * (-cacheDiff_1421_1124);

        // Row 3
        currColAssign = inverse[2];
        currColRight = values[0];
        currColAssign[1] = currColRight[0] * (-cacheDiff_3244_3442)
                        + currColRight[1] * (-cacheDiff_3441_3144)
                        + currColRight[3] * (cacheDiff_3241_3142);

        currColRight = values[1];
        currColAssign[0] = currColRight[0] * (cacheDiff_3244_3442)
                        + currColRight[1] * (cacheDiff_3441_3144)
                        + currColRight[3] * (-cacheDiff_3241_3142);


        
        currColRight = values[2];
        currColAssign[3] = currColRight[3] * (cacheDiff_1221_1122)
                        + currColRight[0] * (cacheDiff_1422_1224)
                        + currColRight[1] * (-cacheDiff_1421_1124);

        currColRight = values[3];
        currColAssign[2] = currColRight[3] * (-cacheDiff_1221_1122)
                        + currColRight[0] * (-cacheDiff_1422_1224)
                        + currColRight[1] * (cacheDiff_1421_1124);

        // Row 4
        currColAssign = inverse[3];
        currColRight = values[0];
        currColAssign[1] = currColRight[0] * (-cacheDiff_3342_3243)
                        + currColRight[1] * (-cacheDiff_3143_3341)
                        + currColRight[2] * (-cacheDiff_3241_3142);

        currColRight = values[1];
        currColAssign[0] = currColRight[0] * (cacheDiff_3342_3243)
                        + currColRight[1] * (cacheDiff_3143_3341)
                        + currColRight[2] * (cacheDiff_3241_3142);

        currColRight = values[2];
        currColAssign[3] = currColRight[0] * (cacheDiff_1223_1322)
                        + currColRight[1] * (-cacheDiff_1123_1321)
                        + currColRight[2] * (-cacheDiff_1221_1122);

        currColRight = values[3];
        currColAssign[2] = currColRight[0] * (-cacheDiff_1223_1322)
                        + currColRight[1] * (cacheDiff_1123_1321)
                        + currColRight[2] * (cacheDiff_1221_1122);

        // Compute Determinant
        float* inverseRow = inverse[0];
        inverseDeterminant = 1 / (values[0][0] * inverseRow[0]
                            + values[1][0] * inverseRow[1]
                            + values[2][0] * inverseRow[2]
                            + values[3][0] * inverseRow[3]);

        // Apply determinant
        values[0][0] = inverseRow[0] * inverseDeterminant;
        values[0][1] = inverseRow[1] * inverseDeterminant;
        values[0][2] = inverseRow[2] * inverseDeterminant;
        values[0][3] = inverseRow[3] * inverseDeterminant;

        inverseRow = inverse[1];
        values[1][0] = inverseRow[0] * inverseDeterminant;
        values[1][1] = inverseRow[1] * inverseDeterminant;
        values[1][2] = inverseRow[2] * inverseDeterminant;
        values[1][3] = inverseRow[3] * inverseDeterminant;

        inverseRow = inverse[2];
        values[2][0] = inverseRow[0] * inverseDeterminant;
        values[2][1] = inverseRow[1] * inverseDeterminant;
        values[2][2] = inverseRow[2] * inverseDeterminant;
        values[2][3] = inverseRow[3] * inverseDeterminant;

        inverseRow = inverse[3];
        values[3][0] = inverseRow[0] * inverseDeterminant;
        values[3][1] = inverseRow[1] * inverseDeterminant;
        values[3][2] = inverseRow[2] * inverseDeterminant;
        values[3][3] = inverseRow[3] * inverseDeterminant;

    }

    std::unique_ptr<Matrix4x4> Matrix4x4::operator + (Matrix4x4 const& matrix) {
        auto matrixValues = matrix.values;
        float vals[4][4] = {};

        float* currColAssign = vals[0];
        float* currColLeft = values[0];
        float const* currColRight = matrixValues[0];
        currColAssign[0] = currColLeft[0] + currColRight[0];
        currColAssign[1] = currColLeft[1] + currColRight[1];
        currColAssign[2] = currColLeft[2] + currColRight[2];
        currColAssign[3] = currColLeft[3] + currColRight[3];

        currColAssign = vals[1];
        currColLeft = values[1];
        currColRight = matrixValues[1];
        currColAssign[0] = currColLeft[0] + currColRight[0];
        currColAssign[1] = currColLeft[1] + currColRight[1];
        currColAssign[2] = currColLeft[2] + currColRight[2];
        currColAssign[3] = currColLeft[3] + currColRight[3];

        currColAssign = vals[2];
        currColLeft = values[2];
        currColRight = matrixValues[2];
        currColAssign[0] = currColLeft[0] + currColRight[0];
        currColAssign[1] = currColLeft[1] + currColRight[1];
        currColAssign[2] = currColLeft[2] + currColRight[2];
        currColAssign[3] = currColLeft[3] + currColRight[3];

        currColAssign = vals[3];
        currColLeft = values[3];
        currColRight = matrixValues[3];
        currColAssign[0] = currColLeft[0] + currColRight[0];
        currColAssign[1] = currColLeft[1] + currColRight[1];
        currColAssign[2] = currColLeft[2] + currColRight[2];
        currColAssign[3] = currColLeft[3] + currColRight[3];

        return std::unique_ptr<Matrix4x4>(new Matrix4x4(vals));
    }
    std::unique_ptr<Matrix4x4> Matrix4x4::operator - (Matrix4x4 const& matrix) {
        auto matrixValues = matrix.values;
        float vals[4][4] = {};

        float* currColAssign = vals[0];
        float* currColLeft = values[0];
        float const* currColRight = matrixValues[0];
        currColAssign[0] = currColLeft[0] - currColRight[0];
        currColAssign[1] = currColLeft[1] - currColRight[1];
        currColAssign[2] = currColLeft[2] - currColRight[2];
        currColAssign[3] = currColLeft[3] - currColRight[3];

        currColAssign = vals[1];
        currColLeft = values[1];
        currColRight = matrixValues[1];
        currColAssign[0] = currColLeft[0] - currColRight[0];
        currColAssign[1] = currColLeft[1] - currColRight[1];
        currColAssign[2] = currColLeft[2] - currColRight[2];
        currColAssign[3] = currColLeft[3] - currColRight[3];

        currColAssign = vals[2];
        currColLeft = values[2];
        currColRight = matrixValues[2];
        currColAssign[0] = currColLeft[0] - currColRight[0];
        currColAssign[1] = currColLeft[1] - currColRight[1];
        currColAssign[2] = currColLeft[2] - currColRight[2];
        currColAssign[3] = currColLeft[3] - currColRight[3];

        currColAssign = vals[3];
        currColLeft = values[3];
        currColRight = matrixValues[3];
        currColAssign[0] = currColLeft[0] - currColRight[0];
        currColAssign[1] = currColLeft[1] - currColRight[1];
        currColAssign[2] = currColLeft[2] - currColRight[2];
        currColAssign[3] = currColLeft[3] - currColRight[3];

        return std::unique_ptr<Matrix4x4>(new Matrix4x4(vals));
    }
    std::unique_ptr<Matrix4x4> Matrix4x4::operator * (Matrix4x4 const& matrix) {
        float* matrixValues = (float*)(matrix.values);
        float vals[4][4] = {};

        // Source matrix row 1
        float* currColLeft = values[0];
        vals[0][0] = currColLeft[0] * matrix.values[0][0]
                    + currColLeft[1] * matrix.values[1][0]
                    + currColLeft[2] * matrix.values[2][0]
                    + currColLeft[3] * matrix.values[3][0];
        vals[0][1] = currColLeft[0] * matrix.values[0][1]
                    + currColLeft[1] * matrix.values[1][1]
                    + currColLeft[2] * matrix.values[2][1]
                    + currColLeft[3] * matrix.values[3][1];
        vals[0][2] = currColLeft[0] * matrix.values[0][2]
                    + currColLeft[1] * matrix.values[1][2]
                    + currColLeft[2] * matrix.values[2][2]
                    + currColLeft[3] * matrix.values[3][2];
        vals[0][3] = currColLeft[0] * matrix.values[0][3]
                    + currColLeft[1] * matrix.values[1][3]
                    + currColLeft[2] * matrix.values[2][3]
                    + currColLeft[3] * matrix.values[3][3];

        // Source matrix row 2
        currColLeft = values[1];
        vals[1][0] = currColLeft[0] * matrix.values[0][0]
                    + currColLeft[1] * matrix.values[1][0]
                    + currColLeft[2] * matrix.values[2][0]
                    + currColLeft[3] * matrix.values[3][0];
        vals[1][1] = currColLeft[0] * matrix.values[0][1]
                    + currColLeft[1] * matrix.values[1][1]
                    + currColLeft[2] * matrix.values[2][1]
                    + currColLeft[3] * matrix.values[3][1];
        vals[1][2] = currColLeft[0] * matrix.values[0][2]
                    + currColLeft[1] * matrix.values[1][2]
                    + currColLeft[2] * matrix.values[2][2]
                    + currColLeft[3] * matrix.values[3][2];
        vals[1][3] = currColLeft[0] * matrix.values[0][3]
                    + currColLeft[1] * matrix.values[1][3]
                    + currColLeft[2] * matrix.values[2][3]
                    + currColLeft[3] * matrix.values[3][3];
        
        // Source matrix row 3
        currColLeft = values[2];
        vals[2][0] = currColLeft[0] * matrix.values[0][0]
                    + currColLeft[1] * matrix.values[1][0]
                    + currColLeft[2] * matrix.values[2][0]
                    + currColLeft[3] * matrix.values[3][0];
        vals[2][1] = currColLeft[0] * matrix.values[0][1]
                    + currColLeft[1] * matrix.values[1][1]
                    + currColLeft[2] * matrix.values[2][1]
                    + currColLeft[3] * matrix.values[3][1];
        vals[2][2] = currColLeft[0] * matrix.values[0][2]
                    + currColLeft[1] * matrix.values[1][2]
                    + currColLeft[2] * matrix.values[2][2]
                    + currColLeft[3] * matrix.values[3][2];
        vals[2][3] = currColLeft[0] * matrix.values[0][3]
                    + currColLeft[1] * matrix.values[1][3]
                    + currColLeft[2] * matrix.values[2][3]
                    + currColLeft[3] * matrix.values[3][3];

        // Source matrix row 4
        currColLeft = values[3];
        vals[3][0] = currColLeft[0] * matrix.values[0][0]
                    + currColLeft[1] * matrix.values[1][0]
                    + currColLeft[2] * matrix.values[2][0]
                    + currColLeft[3] * matrix.values[3][0];
        vals[3][1] = currColLeft[0] * matrix.values[0][1]
                    + currColLeft[1] * matrix.values[1][1]
                    + currColLeft[2] * matrix.values[2][1]
                    + currColLeft[3] * matrix.values[3][1];
        vals[3][2] = currColLeft[0] * matrix.values[0][2]
                    + currColLeft[1] * matrix.values[1][2]
                    + currColLeft[2] * matrix.values[2][2]
                    + currColLeft[3] * matrix.values[3][2];
        vals[3][3] = currColLeft[0] * matrix.values[0][3]
                    + currColLeft[1] * matrix.values[1][3]
                    + currColLeft[2] * matrix.values[2][3]
                    + currColLeft[3] * matrix.values[3][3];

        return std::unique_ptr<Matrix4x4>(new Matrix4x4(vals));
    }
    
    std::unique_ptr<Matrix4x4> Matrix4x4::Inverse() {
        float inverse[4][4] = {};
        float inverseDeterminant;
        float* currColRight;
        float currColLeft;

        // Pre-compute Cached Values for A~
        currColRight = values[1];
        currColLeft = values[0][0];
        float cache_1122 = currColLeft * currColRight[1];
        float cache_1123 = currColLeft * currColRight[2];
        float cache_1124 = currColLeft * currColRight[3];

        currColLeft = values[0][1];
        float cache_1221 = currColLeft * currColRight[0];
        float cache_1223 = currColLeft * currColRight[2];
        float cache_1224 = currColLeft * currColRight[3];

        currColLeft = values[0][2];
        float cache_1321 = currColLeft * currColRight[0];
        float cache_1322 = currColLeft * currColRight[1];
        float cache_1324 = currColLeft * currColRight[3];

        currColLeft = values[0][3];
        float cache_1421 = currColLeft * currColRight[0];
        float cache_1422 = currColLeft * currColRight[1];
        float cache_1423 = currColLeft * currColRight[2];

        currColRight = values[3];
        currColLeft = values[2][0];
        float cache_3142 = currColLeft * currColRight[1];
        float cache_3143 = currColLeft * currColRight[2];
        float cache_3144 = currColLeft * currColRight[3];

        currColLeft = values[2][1];
        float cache_3241 = currColLeft * currColRight[0];
        float cache_3243 = currColLeft * currColRight[2];
        float cache_3244 = currColLeft * currColRight[3];

        currColLeft = values[2][2];
        float cache_3341 = currColLeft * currColRight[0];
        float cache_3342 = currColLeft * currColRight[1];
        float cache_3344 = currColLeft * currColRight[3];

        currColLeft = values[2][3];
        float cache_3441 = currColLeft * currColRight[0];
        float cache_3442 = currColLeft * currColRight[1];
        float cache_3443 = currColLeft * currColRight[2];

        // Compute Cache Differences
        float cacheDiff_3443_3344 = cache_3443 - cache_3344;
        float cacheDiff_3244_3442 = cache_3244 - cache_3442;
        float cacheDiff_3342_3243 = cache_3342 - cache_3243;
        float cacheDiff_1223_1322 = cache_1223 - cache_1322;
        float cacheDiff_1324_1423 = cache_1324 - cache_1423;
        float cacheDiff_1422_1224 = cache_1422 - cache_1224;
        float cacheDiff_3441_3144 = cache_3441 - cache_3144;
        float cacheDiff_3143_3341 = cache_3143 - cache_3341;
        float cacheDiff_1123_1321 = cache_1123 - cache_1321;
        float cacheDiff_1421_1124 = cache_1421 - cache_1124;
        float cacheDiff_3241_3142 = cache_3241 - cache_3142;
        float cacheDiff_1221_1122 = cache_1221 - cache_1122;

        // Row 1
        float* currColAssign;
        currColAssign = inverse[0];
        currColRight = values[0];
        currColAssign[1] = currColRight[1] * (cacheDiff_3443_3344)
                        + currColRight[2] * (cacheDiff_3244_3442)
                        + currColRight[3] * (cacheDiff_3342_3243);
        currColRight = values[1];
        currColAssign[0] = currColRight[1] * (-cacheDiff_3443_3344)
                        + currColRight[2] * (-cacheDiff_3244_3442)
                        + currColRight[3] * (-cacheDiff_3342_3243);

        currColRight = values[3];
        currColAssign[2] = currColRight[3] * (cacheDiff_1223_1322)
                        + currColRight[1] * (cacheDiff_1324_1423)
                        + currColRight[2] * (cacheDiff_1422_1224);
        currColRight = values[2];
        currColAssign[3] = currColRight[3] * (-cacheDiff_1223_1322)
                        + currColRight[1] * (-cacheDiff_1324_1423)
                        + currColRight[2] * (-cacheDiff_1422_1224);

        // Row 2
        currColAssign = inverse[1];
        currColRight = values[0];
        currColAssign[1] = currColRight[0] * (-cacheDiff_3443_3344)
                        + currColRight[2] * (cacheDiff_3441_3144)
                        + currColRight[3] * (cacheDiff_3143_3341);
        currColRight = values[1];
        currColAssign[0] = currColRight[0] * (cacheDiff_3443_3344)
                        + currColRight[2] * (-cacheDiff_3441_3144)
                        + currColRight[3] * (-cacheDiff_3143_3341);


        currColRight = values[2];
        currColAssign[3] = currColRight[3] * (cacheDiff_1123_1321)
                        + currColRight[0] * (cacheDiff_1324_1423)
                        + currColRight[2] * (cacheDiff_1421_1124);
        currColRight = values[3];
        currColAssign[2] = currColRight[3] * (-cacheDiff_1123_1321)
                        + currColRight[0] * (-cacheDiff_1324_1423)
                        + currColRight[2] * (-cacheDiff_1421_1124);

        // Row 3
        currColAssign = inverse[2];
        currColRight = values[0];
        currColAssign[1] = currColRight[0] * (-cacheDiff_3244_3442)
                        + currColRight[1] * (-cacheDiff_3441_3144)
                        + currColRight[3] * (cacheDiff_3241_3142);

        currColRight = values[1];
        currColAssign[0] = currColRight[0] * (cacheDiff_3244_3442)
                        + currColRight[1] * (cacheDiff_3441_3144)
                        + currColRight[3] * (-cacheDiff_3241_3142);


        
        currColRight = values[2];
        currColAssign[3] = currColRight[3] * (cacheDiff_1221_1122)
                        + currColRight[0] * (cacheDiff_1422_1224)
                        + currColRight[1] * (-cacheDiff_1421_1124);

        currColRight = values[3];
        currColAssign[2] = currColRight[3] * (-cacheDiff_1221_1122)
                        + currColRight[0] * (-cacheDiff_1422_1224)
                        + currColRight[1] * (cacheDiff_1421_1124);

        // Row 4
        currColAssign = inverse[3];
        currColRight = values[0];
        currColAssign[1] = currColRight[0] * (-cacheDiff_3342_3243)
                        + currColRight[1] * (-cacheDiff_3143_3341)
                        + currColRight[2] * (-cacheDiff_3241_3142);

        currColRight = values[1];
        currColAssign[0] = currColRight[0] * (cacheDiff_3342_3243)
                        + currColRight[1] * (cacheDiff_3143_3341)
                        + currColRight[2] * (cacheDiff_3241_3142);

        currColRight = values[2];
        currColAssign[3] = currColRight[0] * (cacheDiff_1223_1322)
                        + currColRight[1] * (-cacheDiff_1123_1321)
                        + currColRight[2] * (-cacheDiff_1221_1122);

        currColRight = values[3];
        currColAssign[2] = currColRight[0] * (-cacheDiff_1223_1322)
                        + currColRight[1] * (cacheDiff_1123_1321)
                        + currColRight[2] * (cacheDiff_1221_1122);

        // Compute Determinant
        float* inverseRow = inverse[0];
        inverseDeterminant = 1 / (values[0][0] * inverseRow[0]
                    + values[1][0] * inverseRow[1]
                    + values[2][0] * inverseRow[2]
                    + values[3][0] * inverseRow[3]);

        // Apply determinant
        inverseRow[0] *= inverseDeterminant;
        inverseRow[1] *= inverseDeterminant;
        inverseRow[2] *= inverseDeterminant;
        inverseRow[3] *= inverseDeterminant;

        inverseRow = inverse[1];
        inverseRow[0] *= inverseDeterminant;
        inverseRow[1] *= inverseDeterminant;
        inverseRow[2] *= inverseDeterminant;
        inverseRow[3] *= inverseDeterminant;

        inverseRow = inverse[2];
        inverseRow[0] *= inverseDeterminant;
        inverseRow[1] *= inverseDeterminant;
        inverseRow[2] *= inverseDeterminant;
        inverseRow[3] *= inverseDeterminant;

        inverseRow = inverse[3];
        inverseRow[0] *= inverseDeterminant;
        inverseRow[1] *= inverseDeterminant;
        inverseRow[2] *= inverseDeterminant;
        inverseRow[3] *= inverseDeterminant;

        return std::make_unique<Matrix4x4>(inverse);
    }

    std::string Matrix4x4::toString() {
        float* values0 = values[0];
        float* values1 = values[1];
        float* values2 = values[2];
        float* values3 = values[3];

        return (std::stringstream()
            << "[" << values0[0] << ", " << values0[1] << ", " << values0[2] << ", " << values0[3] << "]" << '\n'
            << "[" << values1[0] << ", " << values1[1] << ", " << values1[2] << ", " << values1[3] << "]" << '\n'
            << "[" << values2[0] << ", " << values2[1] << ", " << values2[2] << ", " << values2[3] << "]" << '\n'
            << "[" << values3[0] << ", " << values3[1] << ", " << values3[2] << ", " << values3[3] << "]" << '\n').str();
    }
};