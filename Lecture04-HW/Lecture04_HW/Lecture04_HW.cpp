//idle : 화면색 검정색으로 clear
//마우스 오른쪽 KeyDown하면 : 빨간색
//마우스 오른쪽 KeyUp하면 : 원상복구
//마우스 왼쪽 KeyDown하면 : 녹색
//마우스 왼쪽 KeyUp하면 : 원상복구
//마우스 오른쪽 KeyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 KeyDown하고 드래그 중이면 : 마젠타색

#include <GLFW/glfw3.h>
#include <iostream>
#pragma comment (lib, "OpenGL32.lib")

// 마우스 오른쪽 버튼이 눌렸는지 여부를 나타내는 변수
bool RightButtonDown = false;

// 마우스 왼쪽 버튼이 눌렸는지 여부를 나타내는 변수
bool LeftButtonDown = false;

// 마우스 오른쪽 버튼을 드래그하는지 여부를 나타내는 변수
bool RightButtonDragging = false;

// 마우스 왼쪽 버튼을 드래그하는지 여부를 나타내는 변수
bool LeftButtonDragging = false;

// 마우스의 마지막 Y 위치를 저장하는 변수
double lastYPos = 0.0;

// 마우스 버튼 이벤트 콜백 함수
void OnMouseButton(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        if (action == GLFW_PRESS) {
            RightButtonDown = true;
            RightButtonDragging = false;
        }
        else if (action == GLFW_RELEASE) {
            RightButtonDown = false;
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            LeftButtonDown = true;
            LeftButtonDragging = false;
        }
        else if (action == GLFW_RELEASE) {
            LeftButtonDown = false;
        }
    }
}

// 마우스 커서 위치 콜백 함수
void OnCursorPosition(GLFWwindow* window, double xpos, double ypos) {
    if (RightButtonDown && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
        RightButtonDragging = true;
        LeftButtonDragging = false;
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 파란색 배경 설정
    }
    else if (LeftButtonDown && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        RightButtonDragging = false;
        LeftButtonDragging = true;
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 자홍색 배경 설정
    }
    else {
        RightButtonDragging = false;
        lastYPos = 0.0;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
        std::cerr << "GLFW 초기화 실패" << std::endl;
        return -1;
    }

    // GLFW 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(1280, 760, "OpenGL Window", NULL, NULL);
    if (!window) {
        std::cerr << "GLFW 윈도우 생성 실패" << std::endl;
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트를 현재 윈도우로 설정
    glfwMakeContextCurrent(window);

    // 마우스 버튼 이벤트 콜백 함수 등록
    glfwSetMouseButtonCallback(window, OnMouseButton);

    // 마우스 커서 위치 콜백 함수 등록
    glfwSetCursorPosCallback(window, OnCursorPosition);

    // 윈도우가 닫힐 때까지 반복
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // 마우스 오른쪽 버튼을 누르면 빨간색 배경 설정
        if (RightButtonDown) {
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        }
        // 마우스 왼쪽 버튼을 누르면 초록색 배경 설정
        else if (LeftButtonDown) {
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        }
        // 그 외의 경우 검은색 배경 설정
        else {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}
