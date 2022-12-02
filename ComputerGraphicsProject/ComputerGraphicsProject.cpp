// ComputerGraphicsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <list>
#include <conio.h>

using namespace std;

class Vector3 {
public:
    // Variables
    float x;
    float y;
    float z;

    // Constructor
    Vector3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Member Functions
    void Normalize() {
        // Store the magnitude.
        float normalizor = magnitude;

        // Normalize each variable in the struct.
        this->x /= normalizor;
        this->y /= normalizor;
        this->z /= normalizor;
    }

    // Normalized property!
    unique_ptr<Vector3> _getnormalized()
    {        
        // Return a pointer to a new, normalized Vector3
        return *this / magnitude;
    }
    __declspec(property(get = _getnormalized)) unique_ptr<Vector3> normalized;

    // Magnitude property!
    float _getprop() {
        return sqrt(x*x + y*y + z*z);
    }
    __declspec(property(get = _getprop)) const float magnitude;

    // Get the cross product of this vector with another
    unique_ptr<Vector3> Cross(Vector3 const& vec) {
        return unique_ptr<Vector3>(new Vector3{
            {y * vec.z - z * vec.y},
            {z * vec.x - x * vec.z},
            {x * vec.y - y * vec.x},
            });
    }

    // Get the dot product of this vector with another
    float Dot(Vector3 & vec) {
        return (x * vec.x + y * vec.y + z * vec.z);
    }

    // Operator Implementations
    unique_ptr<Vector3> operator + (Vector3 const& vec) {
        return unique_ptr<Vector3>(new Vector3{
            {x + vec.x},
            {y + vec.y},
            {z + vec.z},
            });
    }
    unique_ptr<Vector3> operator - (Vector3 const& vec) {
        return unique_ptr<Vector3>(new Vector3{
            {x - vec.x},
            {y - vec.y},
            {z - vec.z},
            });
    }
    unique_ptr<Vector3> operator * (float const& scalar) {
        return unique_ptr<Vector3>(new Vector3{
            {x * scalar},
            {y * scalar},
            {z * scalar},
            });
    }
    unique_ptr<Vector3> operator / (float const& scalar) {
        return unique_ptr<Vector3>(new Vector3{
            {x / scalar},
            {y / scalar},
            {z / scalar},
            });
    }

    // Get the distance between this and the provided vector.
    float Distance(Vector3& vec) {
        return (*this - vec)->magnitude;
    }

    float AngleBetween(Vector3& vecA, Vector3& vecB) {
        auto shiftedVecA = vecA - *this;
        auto shiftedVecB = vecB - *this;
        return acosf(shiftedVecB->Dot(*shiftedVecA) / (shiftedVecA->magnitude * shiftedVecB->magnitude));
    }

    // Returns the distance to the point along vecT's direction that's nearest to point vecP.
    float TangentDistance(Vector3& vecT, Vector3& vecP) {
        return this->Distance(vecP) * cos(this->AngleBetween(*(vecT + *this), vecP));
    }

    // Returns a Vector3 representing the nearest point to vecP along vecT's path, which starts from the calling vectors position.
    unique_ptr<Vector3> TangentPoint(Vector3& vecT, Vector3& vecP) {
        return *(vecT + *this)->normalized * this->TangentDistance(vecT, vecP);
    }
};

class Matrix4x4
{
public:
    float values[4][4] = {};

    Matrix4x4(float(&initValues)[4][4]) {
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

    void Add(Matrix4x4& matrix) {
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
    void Subtract(Matrix4x4 const& matrix) {
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
    void Multiply(Matrix4x4 const& matrix) {
        float* matrixValues = (float*)(matrix.values);
        float vals[4][4] = {};

        // Source matrix row 1
        float* currCol = &matrixValues[0];
        vals[0][0] = values[0][0] * currCol[0]
            + values[1][0] * currCol[1]
            + values[2][0] * currCol[2]
            + values[3][0] * currCol[3];
        vals[0][1] = values[0][1] * currCol[0]
            + values[1][1] * currCol[1]
            + values[2][1] * currCol[2]
            + values[3][1] * currCol[3];
        vals[0][2] = values[0][2] * currCol[0]
            + values[1][2] * currCol[1]
            + values[2][2] * currCol[2]
            + values[3][2] * currCol[3];
        vals[0][3] = values[0][3] * currCol[0]
            + values[1][3] * currCol[1]
            + values[2][3] * currCol[2]
            + values[3][3] * currCol[3];

        // Source matrix row 2
        currCol = &matrixValues[1];
        vals[1][0] = values[0][0] * currCol[0]
            + values[1][0] * currCol[1]
            + values[2][0] * currCol[2]
            + values[3][0] * currCol[3];
        vals[1][1] = values[0][1] * currCol[0]
            + values[1][1] * currCol[1]
            + values[2][1] * currCol[2]
            + values[3][1] * currCol[3];
        vals[1][2] = values[0][2] * currCol[0]
            + values[1][2] * currCol[1]
            + values[2][2] * currCol[2]
            + values[3][2] * currCol[3];
        vals[1][3] = values[0][3] * currCol[0]
            + values[1][3] * currCol[1]
            + values[2][3] * currCol[2]
            + values[3][3] * currCol[3];

        // Source matrix row 3
        currCol = &matrixValues[2];
        vals[2][0] = values[0][0] * currCol[0]
            + values[1][0] * currCol[1]
            + values[2][0] * currCol[2]
            + values[3][0] * currCol[3];
        vals[2][1] = values[0][1] * currCol[0]
            + values[1][1] * currCol[1]
            + values[2][1] * currCol[2]
            + values[3][1] * currCol[3];
        vals[2][2] = values[0][2] * currCol[0]
            + values[1][2] * currCol[1]
            + values[2][2] * currCol[2]
            + values[3][2] * currCol[3];
        vals[2][3] = values[0][3] * currCol[0]
            + values[1][3] * currCol[1]
            + values[2][3] * currCol[2]
            + values[3][3] * currCol[3];

        // Source matrix row 4
        currCol = &matrixValues[3];
        vals[3][0] = values[0][0] * currCol[0]
            + values[1][0] * currCol[1]
            + values[2][0] * currCol[2]
            + values[3][0] * currCol[3];
        vals[3][1] = values[0][1] * currCol[0]
            + values[1][1] * currCol[1]
            + values[2][1] * currCol[2]
            + values[3][1] * currCol[3];
        vals[3][2] = values[0][2] * currCol[0]
            + values[1][2] * currCol[1]
            + values[2][2] * currCol[2]
            + values[3][2] * currCol[3];
        vals[3][3] = values[0][3] * currCol[0]
            + values[1][3] * currCol[1]
            + values[2][3] * currCol[2]
            + values[3][3] * currCol[3];

        // Assign the calculated multiplications to this
        float* currColLeft = values[0];
        currCol = vals[0];
        currColLeft[0] = currCol[0];
        currColLeft[1] = currCol[1];
        currColLeft[2] = currCol[2];
        currColLeft[3] = currCol[3];

        currColLeft = values[1];
        currCol = vals[1];
        currColLeft[0] = currCol[0];
        currColLeft[1] = currCol[1];
        currColLeft[2] = currCol[2];
        currColLeft[3] = currCol[3];

        currColLeft = values[2];
        currCol = vals[2];
        currColLeft[0] = currCol[0];
        currColLeft[1] = currCol[1];
        currColLeft[2] = currCol[2];
        currColLeft[3] = currCol[3];

        currColLeft = values[3];
        currCol = vals[3];
        currColLeft[0] = currCol[0];
        currColLeft[1] = currCol[1];
        currColLeft[2] = currCol[2];
        currColLeft[3] = currCol[3];
    }

    unique_ptr<Matrix4x4> operator + (Matrix4x4 const& matrix) {
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

        return unique_ptr<Matrix4x4>(new Matrix4x4(vals));
    }
    unique_ptr<Matrix4x4> operator - (Matrix4x4 const& matrix) {
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

        return unique_ptr<Matrix4x4>(new Matrix4x4(vals));
    }
    unique_ptr<Matrix4x4> operator * (Matrix4x4 const& matrix) {
        float* matrixValues = (float*)(matrix.values);
        float vals[4][4] = {};

        // Source matrix row 1
        float* currCol = &matrixValues[0];
        vals[0][0] = values[0][0] * currCol[0]
                    + values[1][0] * currCol[1]
                    + values[2][0] * currCol[2]
                    + values[3][0] * currCol[3];
        vals[0][1] = values[0][1] * currCol[0]
                    + values[1][1] * currCol[1]
                    + values[2][1] * currCol[2]
                    + values[3][1] * currCol[3];
        vals[0][2] = values[0][2] * currCol[0]
                    + values[1][2] * currCol[1]
                    + values[2][2] * currCol[2]
                    + values[3][2] * currCol[3];
        vals[0][3] = values[0][3] * currCol[0]
                    + values[1][3] * currCol[1]
                    + values[2][3] * currCol[2]
                    + values[3][3] * currCol[3];

        // Source matrix row 2
        currCol = &matrixValues[1];
        vals[1][0] = values[0][0] * currCol[0]
                    + values[1][0] * currCol[1]
                    + values[2][0] * currCol[2]
                    + values[3][0] * currCol[3];
        vals[1][1] = values[0][1] * currCol[0]
                    + values[1][1] * currCol[1]
                    + values[2][1] * currCol[2]
                    + values[3][1] * currCol[3];
        vals[1][2] = values[0][2] * currCol[0]
                    + values[1][2] * currCol[1]
                    + values[2][2] * currCol[2]
                    + values[3][2] * currCol[3];
        vals[1][3] = values[0][3] * currCol[0]
                    + values[1][3] * currCol[1]
                    + values[2][3] * currCol[2]
                    + values[3][3] * currCol[3];

        // Source matrix row 3
        currCol = &matrixValues[2];
        vals[2][0] = values[0][0] * currCol[0]
                    + values[1][0] * currCol[1]
                    + values[2][0] * currCol[2]
                    + values[3][0] * currCol[3];
        vals[2][1] = values[0][1] * currCol[0]
                    + values[1][1] * currCol[1]
                    + values[2][1] * currCol[2]
                    + values[3][1] * currCol[3];
        vals[2][2] = values[0][2] * currCol[0]
                    + values[1][2] * currCol[1]
                    + values[2][2] * currCol[2]
                    + values[3][2] * currCol[3];
        vals[2][3] = values[0][3] * currCol[0]
                    + values[1][3] * currCol[1]
                    + values[2][3] * currCol[2]
                    + values[3][3] * currCol[3];

        // Source matrix row 4
        currCol = &matrixValues[3];
        vals[3][0] = values[0][0] * currCol[0]
                    + values[1][0] * currCol[1]
                    + values[2][0] * currCol[2]
                    + values[3][0] * currCol[3];
        vals[3][1] = values[0][1] * currCol[0]
                    + values[1][1] * currCol[1]
                    + values[2][1] * currCol[2]
                    + values[3][1] * currCol[3];
        vals[3][2] = values[0][2] * currCol[0]
                    + values[1][2] * currCol[1]
                    + values[2][2] * currCol[2]
                    + values[3][2] * currCol[3];
        vals[3][3] = values[0][3] * currCol[0]
                    + values[1][3] * currCol[1]
                    + values[2][3] * currCol[2]
                    + values[3][3] * currCol[3];

        return unique_ptr<Matrix4x4>(new Matrix4x4(vals));
    }
    
    unique_ptr<Matrix4x4> Inverse() {
        float inverse[4][4] = {};
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


        // Compute A~
        // TO-DO: FIX NOTATION, MATRIX NOTATION IS [Y, X] AAAAAHHHHHH
    }
};

// Declare & Initialize the cube
Vector3 cubeVertices[8]{ // As viewed from -z toward +z, TY & TX axes
    {0, 0, 0}, // Front bottom left
    {1, 0, 0}, // Front bottom right
    {0, 1, 0}, // Front top left
    {1, 1, 0}, // Front top right
    {0, 0, 1}, // Back bottom left
    {1, 0, 1}, // Back bottom right
    {0, 1, 1}, // Back top left
    {1, 1, 1}, // Back top right
};

// Declare & Initialize Camera position
Vector3 cameraPosition{
    {3}, // X
    {1}, // Y
    {-3},// Z
};

Vector3 cameraLookDirection{
    {-1},// X
    {0}, // Y
    {1}, // Z
};

// Declare & Initialize Screen Resolution
const int screen_width = 88;
const int screen_height = 60;

void MoveCamera();
void RenderFrame();

int main()
{
    /*
    while (true)
    {
        RenderFrame();
        
        MoveCamera();
    }
    */
    float testValues[4][4] = { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, };

    Matrix4x4 matrixA = Matrix4x4(testValues);
    Matrix4x4 matrixB = Matrix4x4(testValues);
    Matrix4x4 matrixC = *(matrixA + matrixB);

    cout << matrixC.values[0][1];

    return 0;
}

void MoveCamera() {
    _kbhit();

    switch (_getch()) {
    case 'a':
        cameraPosition = *(cameraPosition + Vector3(-0.1, 0, 0));
        break;
    case 'd':
        cameraPosition = *(cameraPosition + Vector3(0.1, 0, 0));
        break;
    case 'w':
        cameraPosition = *(cameraPosition + Vector3(0, 0, 0.1));
        break;
    case 's':
        cameraPosition = *(cameraPosition + Vector3(0, 0, -0.1));
        break;
    case ' ':
        cameraPosition = *(cameraPosition + Vector3(0, 0.01, 0));
        break;
    case 'c':
        cameraPosition = *(cameraPosition + Vector3(0, -0.01, 0));
        break;
    case 'i':
        cameraLookDirection = *(cameraLookDirection + Vector3(0, 0.1, 0));
        break;
    case 'j':
        cameraLookDirection = *(cameraLookDirection + Vector3(-0.1, 0, 0));
        break;
    case 'k':
        cameraLookDirection = *(cameraLookDirection + Vector3(0, -0.1, 0));
        break;
    case 'l':
        cameraLookDirection = *(cameraLookDirection + Vector3(0.1, 0, 0));
        break;
    }

    return;
}

void RenderFrame() {
    // Declare a map of all pixels
    list<pair<int, int>> vertices{};

    // Compute all vertices
    for (int i = 0; i < 8; i++) {
        float zDepth = cameraPosition.TangentDistance(cameraLookDirection, cubeVertices[i]);
        
        float x_projection = ((cubeVertices[i].x - cameraPosition.x) / zDepth + 1) / 2 * screen_width;
        float y_projection = ((cubeVertices[i].y - cameraPosition.y) / zDepth + 1) / 2 * screen_height;
        
        vertices.push_back(make_pair((int)x_projection, (int)y_projection));
    };

    // Make an empty screen
    string pixels[screen_height] = {};
    for (int i = 0; i < screen_height; i++)
    {
        pixels[i] = string(screen_width, ' ');
    }

    // Insert vertices onscreen
    for (pair<int, int>& vertex : vertices)
    {
        if (vertex.first <= screen_width && vertex.second <= screen_height
            && vertex.first > 0 && vertex.second > 0)
            pixels[vertex.second - 1].replace(vertex.first, 1, "X");
    }

    // Print each line to the screen
    for (int i = screen_height - 1; i > -1; i--)
    {
        cout << pixels[i] << endl;
    }

    // Emulate 20 FPS
    Sleep(50);
}