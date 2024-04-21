#pragma once
#include "MSList.h"

// ����Ʈ�� ������ �߰�
template <typename T>
void MSList<T>::add(T data)
{
    // �� ��� ����
    MSNode<T>* new_node = new MSNode<T>(data);

    // ����Ʈ�� ����ִ� ���
    if (!_head)
    {
        _head = new_node;
    }
    else
    {
        // ������ ��� ã��
        MSNode<T>* current = _head;
        while (current->next_node)
        {
            current = current->next_node;
        }
        // �� ��带 ������ ���� ����
        current->next_node = new_node;
    }
    _size++;
}

// �ε����� �����Ϳ� �����ϴ� ������ �����ε�
template <typename T>
T& MSList<T>::operator[](int index)
{
    MSNode<T>* current = _head;
    // �ش� �ε����� ������ �̵�
    for (int i = 0; i < index; ++i)
    {
        current = current->next_node;
    }
    return current->data;
}

// ����Ʈ�� ��� ��� ����
template <typename T>
void MSList<T>::clear()
{
    // ����Ʈ�� ��� ��带 �����ϰ� �޸� ����
    while (_head)
    {
        MSNode<T>* temp = _head;
        _head = _head->next_node;
        delete temp;
    }
    _size = 0;
}