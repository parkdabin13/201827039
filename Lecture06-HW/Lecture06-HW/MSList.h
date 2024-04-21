#pragma once
#include "MObject.h" 

// 리스트의 하나의 칸을 나타내는 노드
template <typename T>
class MSNode
{
public:
    // 노드를 만들 때 데이터를 넣고, 다음 칸은 비어있다고 설정
    MSNode(T data) : data(data), next_node(nullptr) {}
    ~MSNode() {}

    T data;                // 이 칸에 들어있는 데이터
    MSNode* next_node;     // 다음 칸으로 가는 길
};

// 여러 칸을 모아 하나의 리스트를 만든다
template <typename T>
class MSList
{
public:
    // 새로운 리스트를 만들 때는 빈 상태로 시작
    MSList() : _head(nullptr), _size(0) {}
    ~MSList() {}

    int get_size() const { return _size; } // 리스트에 몇 개의 칸이 있는지 알려줌
    void add(T data);                      // 새로운 칸에 데이터를 넣음
    T& operator[](int index);              // 특정 위치의 칸에 접근
    void clear();                          // 리스트의 모든 칸을 비움

public:
    MSNode<T>* _head; // 첫 번째 칸을 가리키는 포인터
    int _size;        // 리스트의 총 칸 수
};
