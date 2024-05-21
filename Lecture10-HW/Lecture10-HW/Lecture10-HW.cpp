#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <cmath>

const double PI = 3.14159265358979323846;

// 별 그리는 함수
void drawStar(float centerX, float centerY, float size) {
    float x, y, angle;
    const int numPoints = 5;
    const float PI = 3.14159265358979323846f;
    const float angleOffset = PI / 2.0f;
    const float outerRadius = size;
    const float innerRadius = size * 0.382f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(centerX, centerY);

    for (int i = 0; i <= numPoints * 2; ++i) {
        angle = i * 2 * PI / (numPoints * 2) + angleOffset;
        if (i % 2 == 0) {
            x = centerX + outerRadius * cos(angle);
            y = centerY + outerRadius * sin(angle);
        }
        else {
            x = centerX + innerRadius * cos(angle);
            y = centerY + innerRadius * sin(angle);
        }

        glVertex2f(x, y);
    }

    glEnd();
}

int main() {
    // GLFW 라이브러리를 초기화
    if (!glfwInit())
        return -1;

    // 창 모드 윈도우와 OpenGL 컨텍스트 생성
    GLFWwindow* window = glfwCreateWindow(900, 700, "Canvas Rotation", NULL, NULL);
    if (!window) {
        // 윈도우 생성 실패 시 GLFW 종료
        glfwTerminate();
        return -1;
    }

    // 윈도우의 컨텍스트를 현재로 설정
    glfwMakeContextCurrent(window);

    // 이전 시간 저장 변수 (프레임 간 시간 차이를 계산하기 위해)
    double previousTime = glfwGetTime();

    // 사용자가 윈도우를 닫을 때까지 루프 실행
    while (!glfwWindowShouldClose(window)) {
        // 현재 시간과 deltaTime 계산
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - previousTime;
        previousTime = currentTime;

        // 컬러 버퍼를 지우기
        glClear(GL_COLOR_BUFFER_BIT);

        // 프레임버퍼 크기 가져오기
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        // 뷰포트 설정
        glViewport(0, 0, width, height);

        // 투영 행렬 설정
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, height, 0, -1, 1);

        // 모델뷰 행렬 설정
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // 화면의 중심 좌표 계산
        double centerX = width / 2.0;
        double centerY = height / 2.0;

        // 지구와 달의 공전 반경 설정
        double earthOrbitRadius = 300; // 지구 공전 반경
        double moonOrbitRadius = 60;   // 달 공전 반경

        // 태양의 반지름 설정
        double sunRadius = height / 6.0;

        // 각도 초기화
        static double sunRotation = 0;
        static double earthOrbitAngle = 0;
        static double earthRotation = 0;
        static double moonOrbitAngle = 0;

        // 회전 속도 설정 (라디안/초)
        const double sunRotationSpeed = 2 * PI / 30.0;    // 태양 자전 속도
        const double earthOrbitSpeed = 2 * PI / 60.0;     // 지구 공전 속도
        const double earthRotationSpeed = 2 * PI / 10.0;  // 지구 자전 속도
        const double moonOrbitSpeed = 2 * PI / 3.0;       // 달 공전 속도
        const double moonRotationSpeed = 2 * PI / 3.0;    // 달 자전 속도

        // 각도 업데이트
        sunRotation += sunRotationSpeed * deltaTime;
        earthOrbitAngle += earthOrbitSpeed * deltaTime;
        earthRotation += earthRotationSpeed * deltaTime;
        moonOrbitAngle += moonOrbitSpeed * deltaTime;

        // 태양 그리기 시작
        glPushMatrix();
        glTranslatef(centerX, centerY, 0.0); // 중심으로 이동
        glRotatef(sunRotation * 180.0 / PI, 0.0, 0.0, 1.0); // 태양 자전

        // 태양을 노란색 원으로 그리기
        glColor3ub(255, 217, 102);
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < 360; i++) {
            double theta = i * PI / 180.0;
            glVertex2f(sunRadius * cos(theta), sunRadius * sin(theta));
        }
        glEnd();

        // 태양에 작은 원 패턴 그리기
        glColor3ub(255, 230, 153);
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < 360; i++) {
            double theta = i * PI / 180.0;
            glVertex2f(-sunRadius / 2.5 + sunRadius / 2.5 * cos(theta), sunRadius / 2.5 * sin(theta));
        }
        glEnd();

        // 태양에 작은 타원 패턴 그리기
        glPushMatrix();
        glColor3ub(255, 192, 0);
        glTranslatef(sunRadius * 0.9, 0.0, 0.0); // 태양 표면의 위치로 이동
        glRotatef(90.0, 0.0, 0.0, 1.0); // 타원을 90도 회전
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < 360; i++) {
            double theta = i * PI / 180.0;
            glVertex2f(sunRadius / 4.0 * cos(theta), sunRadius / 15.0 * sin(theta));
        }
        glEnd();
        glPopMatrix();

        // 태양의 윤곽선 그리기
        glColor3ub(197, 90, 17);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++) {
            double theta = i * PI / 180.0;
            glVertex2f(sunRadius * cos(theta), sunRadius * sin(theta));
        }
        glEnd();

        glPopMatrix(); // 태양 변환 종료

        // 지구 (파란색 사각형) 태양 주위를 공전
        glPushMatrix();
        glTranslatef(centerX, centerY, 0.0); // 중심으로 이동
        glRotatef(earthOrbitAngle * 180.0 / PI, 0.0, 0.0, 1.0); // 지구 공전
        glTranslatef(earthOrbitRadius, 0.0, 0.0); // 지구 공전 반경만큼 이동
        glRotatef(earthRotation * 180.0 / PI, 0.0, 0.0, 1.0); // 지구 자전
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_QUADS);
        glVertex2f(-25.0, -25.0);
        glVertex2f(25.0, -25.0);
        glVertex2f(25.0, 25.0);
        glVertex2f(-25.0, 25.0);
        glEnd();

        // 달 (노란색 별) 지구 주위를 공전
        glPushMatrix();
        glRotatef(moonOrbitAngle * 180.0 / PI, 0.0, 0.0, 1.0); // 달 공전
        glTranslatef(moonOrbitRadius, 0.0, 0.0); // 달 공전 반경만큼 이동
        glRotatef(moonOrbitAngle * 180.0 / PI, 0.0, 0.0, -1.0); // 달 자전
        drawStar(0.0f, 0.0f, 15.0f); // 달을 별 모양으로 그리기
        glPopMatrix();
        glPopMatrix();

        // 프론트와 백 버퍼를 교체하여 화면에 그린 내용을 표시
        glfwSwapBuffers(window);

        // 이벤트 처리
        glfwPollEvents();
    }

    // GLFW 종료
    glfwTerminate();

    return 0;
}