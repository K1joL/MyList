#ifndef MYLIST_H
#define MYLIST_H

class List {

    struct Node {
        Node* next;
        int value;
    };

    //���������� ��������� ������� � ������ (� ������� ������)
    Node* back();

public:

    List();

    ~List();

    //���������� true ���� ������ ������
    bool empty();

    const Node *getHead() { return this->_head; }

    //���������� ��������� �� ��������� ������� � ������ (� ������� ������)
    const Node *cback();

    // �������� � �����
    void push_back(const int value);

    // ���������� �������� ���������� ��������� ��������
    int pop_back();

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

private:
    Node* _head = nullptr;
    size_t _size = 0;
};

#endif // !MYLIST_H
