#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include "Star.hpp"
#include "MSList.cpp"

// 이동과 스케일 조절을 위한 변수
float moveFactor = 0.0f;
float scaleFactor = 1.0f;

// 객체 목록 생성
MSList<MObject*> list;

// GLFW 오류 콜백 함수
void errorCallback(int error, const char* description)
{
	std::cerr << "\033[1;31mGLFW Error: " << description << "\033[0m" << std::endl;
}

// 키 입력 콜백 함수
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// ESC 키로 창 닫기
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	// 위쪽 화살표 키로 이동 요소 증가
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		moveFactor += 0.01f;
	}
	// 오른쪽 화살표 키로 스케일 요소 증가
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		scaleFactor += 0.1f;
	}
}

// 초기화 함수
void initialize() {
	const int numStars = 300;
	for (int i = 0; i < numStars; ++i) {
		list.add(new Star());
	}
}

// 해제 함수
void release() {
	for (int i = 0; i < list.get_size(); ++i) {
		delete list[i];
	}
	list.clear();
}

// 업데이트 함수
int update()
{
	return 0;
}

// 렌더링 함수
void render() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// 객체 목록을 순회하며 렌더링
	for (int i = 0; i < list.get_size(); ++i) {
		MObject* obj = list[i];
		obj->render();
	}
}

int main()
{
	// GLFW 초기화
	if (!glfwInit())
		return -1;

	// 창 생성
	GLFWwindow* window = glfwCreateWindow(1280, 768, "", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// 현재 컨텍스트 설정
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	// 초기화 함수 호출
	initialize();

	// 메인 루프
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render();
		glfwSwapBuffers(window);
	}

	// 해제 함수 호출
	release();
	glfwTerminate();
	return 0;
}
