#include "MObject.h"
#include <GLFW/glfw3.h>
#include <random> 

// �� ��ü ����
class Star : public MObject {
public:
    // �ʱ� ��ġ�� ���� ����
    Star() : xPos(0.0f), yPos(0.0f), red(0.0f), green(0.0f), blue(0.0f), scale(20) {
        // ���� ���� �����ϱ� ���� ��ü ����
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(-1.0f, 1.0f);

        // ���� ��ġ�� ���� ����
        xPos = dis(gen);
        yPos = dis(gen);
        red = dis(gen);
        green = dis(gen);
        blue = dis(gen);
    }

private:
    float xPos;     // X ��ǥ
    float yPos;     // Y ��ǥ
    float red;     
    float green;    
    float blue;    
    int scale;      // ũ��

    // ���� �׸��� �Լ�
    void render() override {
        // ���� ���� ����
        GLfloat currentColor[4];
        glGetFloatv(GL_CURRENT_COLOR, currentColor);

        // ���� ���� ����
        glColor3f(red, green, blue);

        // �� ��� �׸���
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

        // ������ ������� ����
        glColor3fv(currentColor);
    }
};
