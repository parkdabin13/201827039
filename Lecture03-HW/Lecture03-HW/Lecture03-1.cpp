#include <iostream>

// 열거형을 사용하여 색깔을 지정하는 상수 정의
enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};
int main() {
    int i = 0;
    
    // 무한 루프 시작
    for (;;) {
        // ANSI 이스케이프 시퀀스를 사용하여 화면에 색상 지정
        std::cout << "\x1b[" << White << "m" << "아름다운 색!! 우왕\n";
        std::cout << "흰색 블록을 그리는 키코드 : 1 (1)\n";
        std::cout << "빨강색 블록을 그리는 키코드 : 2 (10)\n";
        std::cout << "녹색 블록을 그리는 키코드 : 4 (100)\n";
        std::cout << "노란색 블록을 그리는 키코드 : 8 (1000)\n";
        std::cout << "청록색 블록을 그리는 키코드 : 16 (10000)\n";
        std::cout << "마젠타색 블록을 그리는 키코드 : 32 (100000)\n";
        std::cout << "프로그램 종료 : 64 (1000000)\n\n";
        std::cout << "화면에 그림을 그리는 프로그램입니다.\n";
        std::cout << "학번 : 201827039\n";
        std::cout << "이름 : 박다빈\n\n";
        std::cout << "화면에 그릴 물체코드를 입력하세요: ";
        
        // 사용자 입력 받기
        std::cin >> i;
        
        // 입력이 64이면 무한 루프 종료
        if (i == 64)
            break;

        // 입력에 따라 적절한 색상의 블록 출력
        if (i == 1) {
            std::cout << "흰색 블록을 그립니다.\n";
            for (int j = 0; j < 1; j++) {
            std::cout << "■";
            }
                std::cout << "\n";
        }
        else if (i == 2) {
            std::cout << "빨강색 블록을 그립니다.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Red << "m" << "■" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else if (i == 4) {
            std::cout << "녹색 블록을 그립니다.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Green << "m" << "■" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else if (i == 8) {
            std::cout << "노란색 블록을 그립니다.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Yellow << "m" << "■" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else if (i == 16) {
            std::cout << "청록색 블록을 그립니다.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Cyan << "m" << "■" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else if (i == 32) {
            std::cout << "마젠타색 블록을 그립니다.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Magenta << "m" << "■" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else {
            std::cout << "유효하지 않은 입력입니다. 다시 시도하세요.\n";
        }
    }
    return 0;
}