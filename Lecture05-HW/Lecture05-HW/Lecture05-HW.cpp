#include <GLFW/glfw3.h>
#include <iostream>
#pragma comment (lib, "Opengl32.lib")

// 초기화
float moveX = 0.0f; // X축 이동량
float moveY = 0.0f; // Y축 이동량
float scaleFactor = 1.0f; // 크기 조절량
bool isLeftMouseDown = false; // 왼쪽 마우스 버튼이 눌려있는지 여부
bool isRightMouseDown = false; // 오른쪽 마우스 버튼이 눌려있는지 여부
double prevXPos, prevYPos; // 이전 마우스 위치 저장 변수

// 함수 선언
void errorCallback(int error, const char* description);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
void render();

int main(void)
{
    // GLFW 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    // 윈도우 생성 실패 시
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // 윈도우 컨텍스트 설정
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents(); // 이벤트 처리
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 배경색 설정
        glClear(GL_COLOR_BUFFER_BIT); // 화면 지우기

        render(); // 렌더링 함수 호출

        glfwSwapBuffers(window); // 버퍼 스왑
    }

    glfwTerminate(); // GLFW 종료
    return 0;
}

// GLFW 에러 콜백 함수
void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW 에러: " << description << std::endl;
}

// 키 입력 콜백 함수
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

// 마우스 버튼 입력 콜백 함수
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
        {
            isLeftMouseDown = true;
            glfwGetCursorPos(window, &prevXPos, &prevYPos);
        }
        else if (action == GLFW_RELEASE)
            isLeftMouseDown = false;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            isRightMouseDown = true;
            glfwGetCursorPos(window, &prevXPos, &prevYPos);
        }
        else if (action == GLFW_RELEASE)
            isRightMouseDown = false;
    }
}

// 마우스 이동 콜백 함수
void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (isLeftMouseDown)
    {
        moveX += (xpos - prevXPos) / 1280.0f;
        moveY -= (ypos - prevYPos) / 768.0f;
    }
    else if (isRightMouseDown)
    {
        scaleFactor += (xpos - prevXPos) / 640.0f;
    }

    prevXPos = xpos;
    prevYPos = ypos;
}

// 다각형을 그리는 함수
void render()
{
    glBegin(GL_POLYGON); // 다각형 시작

    glColor3f(1.0f, 1.0f, 1.0f); // 색상 설정

    // 각 꼭지점을 차례대로 설정
    // 꼭지점 1
    glVertex2f((0.2f + moveX) * scaleFactor, (0.1f + moveY) * scaleFactor);
    // 꼭지점 2
    glVertex2f((1.0f + moveX) * scaleFactor, (0.1f + moveY) * scaleFactor);
    // 꼭지점 3
    glVertex2f((0.4f + moveX) * scaleFactor, (-0.4f + moveY) * scaleFactor);
    // 꼭지점 4
    glVertex2f((0.6f + moveX) * scaleFactor, (-1.0f + moveY) * scaleFactor);
    // 꼭지점 5
    glVertex2f((0.0f + moveX) * scaleFactor, (-0.6f + moveY) * scaleFactor);
    // 꼭지점 6
    glVertex2f((-0.6f + moveX) * scaleFactor, (-1.0f + moveY) * scaleFactor);
    // 꼭지점 7
    glVertex2f((-0.4f + moveX) * scaleFactor, (-0.4f + moveY) * scaleFactor);
    // 꼭지점 8
    glVertex2f((-1.0f + moveX) * scaleFactor, (0.1f + moveY) * scaleFactor);
    // 꼭지점 9
    glVertex2f((-0.2f + moveX) * scaleFactor, (0.1f + moveY) * scaleFactor);
    // 꼭지점 10
    glVertex2f((0.0f + moveX) * scaleFactor, (1.0f + moveY) * scaleFactor);

    glEnd(); // 다각형 종료
}
