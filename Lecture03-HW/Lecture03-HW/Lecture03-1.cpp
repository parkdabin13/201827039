#include <iostream>

// �������� ����Ͽ� ������ �����ϴ� ��� ����
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
    
    // ���� ���� ����
    for (;;) {
        // ANSI �̽������� �������� ����Ͽ� ȭ�鿡 ���� ����
        std::cout << "\x1b[" << White << "m" << "�Ƹ��ٿ� ��!! ���\n";
        std::cout << "��� ����� �׸��� Ű�ڵ� : 1 (1)\n";
        std::cout << "������ ����� �׸��� Ű�ڵ� : 2 (10)\n";
        std::cout << "��� ����� �׸��� Ű�ڵ� : 4 (100)\n";
        std::cout << "����� ����� �׸��� Ű�ڵ� : 8 (1000)\n";
        std::cout << "û�ϻ� ����� �׸��� Ű�ڵ� : 16 (10000)\n";
        std::cout << "����Ÿ�� ����� �׸��� Ű�ڵ� : 32 (100000)\n";
        std::cout << "���α׷� ���� : 64 (1000000)\n\n";
        std::cout << "ȭ�鿡 �׸��� �׸��� ���α׷��Դϴ�.\n";
        std::cout << "�й� : 201827039\n";
        std::cout << "�̸� : �ڴٺ�\n\n";
        std::cout << "ȭ�鿡 �׸� ��ü�ڵ带 �Է��ϼ���: ";
        
        // ����� �Է� �ޱ�
        std::cin >> i;
        
        // �Է��� 64�̸� ���� ���� ����
        if (i == 64)
            break;

        // �Է¿� ���� ������ ������ ��� ���
        if (i == 1) {
            std::cout << "��� ����� �׸��ϴ�.\n";
            for (int j = 0; j < 1; j++) {
            std::cout << "��";
            }
                std::cout << "\n";
        }
        else if (i == 2) {
            std::cout << "������ ����� �׸��ϴ�.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Red << "m" << "��" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else if (i == 4) {
            std::cout << "��� ����� �׸��ϴ�.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Green << "m" << "��" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else if (i == 8) {
            std::cout << "����� ����� �׸��ϴ�.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Yellow << "m" << "��" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else if (i == 16) {
            std::cout << "û�ϻ� ����� �׸��ϴ�.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Cyan << "m" << "��" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else if (i == 32) {
            std::cout << "����Ÿ�� ����� �׸��ϴ�.\n";
            for (int j = 0; j < 1; j++) {
                std::cout << "\x1b[" << Magenta << "m" << "��" << "\x1b[" << Default << "m";
            }
            std::cout << "\n";
        }
        else {
            std::cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n";
        }
    }
    return 0;
}