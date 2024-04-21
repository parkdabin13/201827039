#pragma once
#include "MSList.h"

// 리스트에 데이터 추가
template <typename T>
void MSList<T>::add(T data)
{
    // 새 노드 생성
    MSNode<T>* new_node = new MSNode<T>(data);

    // 리스트가 비어있는 경우
    if (!_head)
    {
        _head = new_node;
    }
    else
    {
        // 마지막 노드 찾기
        MSNode<T>* current = _head;
        while (current->next_node)
        {
            current = current->next_node;
        }
        // 새 노드를 마지막 노드로 연결
        current->next_node = new_node;
    }
    _size++;
}

// 인덱스로 데이터에 접근하는 연산자 오버로딩
template <typename T>
T& MSList<T>::operator[](int index)
{
    MSNode<T>* current = _head;
    // 해당 인덱스의 노드까지 이동
    for (int i = 0; i < index; ++i)
    {
        current = current->next_node;
    }
    return current->data;
}

// 리스트의 모든 노드 삭제
template <typename T>
void MSList<T>::clear()
{
    // 리스트의 모든 노드를 삭제하고 메모리 해제
    while (_head)
    {
        MSNode<T>* temp = _head;
        _head = _head->next_node;
        delete temp;
    }
    _size = 0;
}