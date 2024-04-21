#pragma once
#include "MObject.h" 

// ����Ʈ�� �ϳ��� ĭ�� ��Ÿ���� ���
template <typename T>
class MSNode
{
public:
    // ��带 ���� �� �����͸� �ְ�, ���� ĭ�� ����ִٰ� ����
    MSNode(T data) : data(data), next_node(nullptr) {}
    ~MSNode() {}

    T data;                // �� ĭ�� ����ִ� ������
    MSNode* next_node;     // ���� ĭ���� ���� ��
};

// ���� ĭ�� ��� �ϳ��� ����Ʈ�� �����
template <typename T>
class MSList
{
public:
    // ���ο� ����Ʈ�� ���� ���� �� ���·� ����
    MSList() : _head(nullptr), _size(0) {}
    ~MSList() {}

    int get_size() const { return _size; } // ����Ʈ�� �� ���� ĭ�� �ִ��� �˷���
    void add(T data);                      // ���ο� ĭ�� �����͸� ����
    T& operator[](int index);              // Ư�� ��ġ�� ĭ�� ����
    void clear();                          // ����Ʈ�� ��� ĭ�� ���

public:
    MSNode<T>* _head; // ù ��° ĭ�� ����Ű�� ������
    int _size;        // ����Ʈ�� �� ĭ ��
};
