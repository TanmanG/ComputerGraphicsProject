// ComputerGraphicsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <vector>

#include "Vector3.h"
#include "Matrix4x4.h"
#include "Triangle.h"
#include "Mesh.h"

using namespace std;

// Declare & Initialize the cube
Vector3::Vector3 cubeVertices[8]{ // As viewed from -z toward +z, TY & TX axes
    {0, 0, 0}, // Front bottom left
    {1, 0, 0}, // Front bottom right
    {0, 1, 0}, // Front top left
    {1, 1, 0}, // Front top right
    {0, 0, 1}, // Back bottom left
    {1, 0, 1}, // Back bottom right
    {0, 1, 1}, // Back top left
    {1, 1, 1}, // Back top right
};
// Declare & Initialize Camera position & rotation
Vector3::Vector3 cameraPosition{
    {3}, // X
    {1}, // Y
    {-3},// Z
};
Vector3::Vector3 cameraLookDirection{
    {-1},// X
    {0}, // Y
    {1}, // Z
};

// Declare & Initialize Screen Resolution
const int screen_width = 88;
const int screen_height = 60;

void MoveCamera();
void RenderFrame();

// Main Function
int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) {

    const auto pClassName = L"3DRenderer";
    // Register Window Class
        // Make Descriptors
    WNDCLASSEX wc = { 0 }; // Good practice to 'zero out' a structure when init
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC; // "Buncha bullshit"
    wc.lpfnWndProc = DefWindowProc; // "Most important" - "Long pointer to function window proc". Function that handles all messages to window
                                    //Process determines behaviour AND looks- as draw is a part!
    wc.cbClsExtra = 0; // How many extra bytes to allocate for us to use- we dont need these
    wc.cbWndExtra = 0; // Extra bytes for every window of this class- we dont need these
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;
        // Register Window Class
    RegisterClassEx(&wc);

    // Create instance of Window Class
    // Create a handle for the window
    HWND hWnd = CreateWindowEx(
        0, pClassName, // Window class
        L"Happy Rendering Window", // Window name
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, // Display options
        200, 200, 640, 480, // Screen dimensions
        nullptr, nullptr, hInstance, nullptr
    );

    // "Activate" the window and display it on-screen
    ShowWindow(hWnd, SW_SHOW);

    // Rendering Loop
    while (true)
    {
        //RenderFrame();

        MoveCamera();
    }

    // Matrix Testing
    float testValues[4][4] = { {1, 2, 3, 4},
                                {5, 6, -7, 8},
                                {11, -12, 13, 12},
                                {13, 14, 15, 16}, };
    Matrix4x4::Matrix4x4 matrixA = Matrix4x4::Matrix4x4(testValues);


    return 0;
}

void MoveCamera() {
    _kbhit();

    switch (_getch()) {
    case 'a':
        cameraPosition = *(cameraPosition + Vector3::Vector3(-0.1, 0, 0));
        break;
    case 'd':
        cameraPosition = *(cameraPosition + Vector3::Vector3(0.1, 0, 0));
        break;
    case 'w':
        cameraPosition = *(cameraPosition + Vector3::Vector3(0, 0, 0.1));
        break;
    case 's':
        cameraPosition = *(cameraPosition + Vector3::Vector3(0, 0, -0.1));
        break;
    case ' ':
        cameraPosition = *(cameraPosition + Vector3::Vector3(0, 0.01, 0));
        break;
    case 'c':
        cameraPosition = *(cameraPosition + Vector3::Vector3(0, -0.01, 0));
        break;
    case 'i':
        cameraLookDirection = *(cameraLookDirection + Vector3::Vector3(0, 0.1, 0));
        break;
    case 'j':
        cameraLookDirection = *(cameraLookDirection + Vector3::Vector3(-0.1, 0, 0));
        break;
    case 'k':
        cameraLookDirection = *(cameraLookDirection + Vector3::Vector3(0, -0.1, 0));
        break;
    case 'l':
        cameraLookDirection = *(cameraLookDirection + Vector3::Vector3(0.1, 0, 0));
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