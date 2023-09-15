#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main() {
    // Create the array of pixels (800x600, 4 bytes per pixel for RGBA)
    const int width = 800;
    const int height = 600;
    const int bytesPerPixel = 4;
    const int bufferSize = width * height * bytesPerPixel;
    unsigned char* pixels = malloc(bufferSize);

    // Fill the array with pink color (RGB: 255, 192, 203)
    const unsigned char pinkColor[] = { 255, 192, 203, 255 }; // RGBA
    for (int i = 0; i < bufferSize; i += bytesPerPixel) {
        pixels[i] = pinkColor[0];     // Red
        pixels[i + 1] = pinkColor[1]; // Green
        pixels[i + 2] = pinkColor[2]; // Blue
        pixels[i + 3] = pinkColor[3]; // Alpha
    }

    // Register the window class
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "ColorWindowClass";

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window registration failed!", "Error", MB_ICONERROR);
        return 1;
    }

    // Create the window
    HWND hwnd = CreateWindow(
        "ColorWindowClass",
        "Color Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        width,
        height,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );

    if (hwnd == NULL) {
        MessageBox(NULL, "Window creation failed!", "Error", MB_ICONERROR);
        return 1;
    }

    // Display the color buffer
    HDC hdc = GetDC(hwnd);
    HBITMAP hBitmap = CreateBitmap(width, height, 1, 32, pixels);
    HDC hdcMem = CreateCompatibleDC(hdc);
    HGDIOBJ oldBitmap = SelectObject(hdcMem, hBitmap);
    BitBlt(hdc, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY);
    SelectObject(hdcMem, oldBitmap);
    DeleteDC(hdcMem);
    ReleaseDC(hwnd, hdc);

    // Show and update the window
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Cleanup
    free(pixels);

    return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
