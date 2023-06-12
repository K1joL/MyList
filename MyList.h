#ifndef MYLIST_H
#define MYLIST_H

class List {

    struct Node {
        Node* next;
        Node* another;
        int value;
    };

    //���������� ��������� ������� � ������ (� ������� ������)
    Node* back();

private:
    Node* _head = nullptr;
    size_t _size = 0;

public:

    List();
    
    List(int num);

    ~List();

    //���������� true ���� ������ ������
    bool empty();

    const Node* getHead() { return this->_head; }

    //���������� ��������� �� ��������� ������� � ������ (� ������� ������)
    const Node *cback();

    // �������� � �����
    void push_back(const int value);

    // ���������� �������� ���������� ��������� ��������
    int pop_back();

    //Insert element in next position (position+1)
    //If List is empty then insert in first position
    void insert(const int position, const int value);

    // ������� ������� �� �������
    void erase(const int position);

    // ������� �c� ����
    void clear();

    // ��������� ��� ������
    void sort();

    // ������ �����
    size_t size() { return _size; }

    //�������������� ������
    void invert();

    //���������� �������� �������� �������� ������
    int middle();

    List* copy();

};

#endif // !MYLIST_H
