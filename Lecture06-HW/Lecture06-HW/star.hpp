#include "MObject.h"
#include <GLFW/glfw3.h>
#include <random> 

// 별 객체 정의
class Star : public MObject {
public:
    // 초기 위치와 색상 설정
    Star() : xPos(0.0f), yPos(0.0f), red(0.0f), green(0.0f), blue(0.0f), scale(20) {
        // 랜덤 값을 생성하기 위한 객체 생성
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(-1.0f, 1.0f);

        // 랜덤 위치와 색상 설정
        xPos = dis(gen);
        yPos = dis(gen);
        red = dis(gen);
        green = dis(gen);
        blue = dis(gen);
    }

private:
    float xPos;     // X 좌표
    float yPos;     // Y 좌표
    float red;     
    float green;    
    float blue;    
    int scale;      // 크기

    // 별을 그리는 함수
    void render() override {
        // 현재 색상 저장
        GLfloat currentColor[4];
        glGetFloatv(GL_CURRENT_COLOR, currentColor);

        // 별의 색상 설정
        glColor3f(red, green, blue);

        // 별 모양 그리기
        glBegin(GL_POLYGON);
        glVertex2f((0.2f / scale) + xPos, (0.1f / scale) + yPos);
        glVertex2f(xPos + (0.8f / scale), yPos + (0.01f / scale));
        glVertex2f(xPos + (0.3f / scale), yPos - (0.3f / scale));
        glVertex2f(xPos + (0.5f / scale), yPos - (0.8f / scale));
        glVertex2f(xPos, yPos - (0.5f / scale));
        glVertex2f(xPos - (0.5f / scale), yPos - (0.8f / scale));
        glVertex2f(xPos - (0.3f / scale), yPos - (0.3f / scale));
        glVertex2f(xPos - (0.8f / scale), yPos + (0.01f / scale));
        glVertex2f(xPos - (0.2f / scale), yPos + (0.1f / scale));
        glVertex2f(xPos, yPos + (0.8f / scale));
        glEnd();

        // 색상을 원래대로 복원
        glColor3fv(currentColor);
    }
};
