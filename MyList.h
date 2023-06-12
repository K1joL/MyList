#ifndef MYLIST_H
#define MYLIST_H

class List {

    struct Node {
        Node* next;
        int value;
    };

    //Возвращает последний элемент в списке (с помощью обхода)
    Node* back();

public:

    List();

    ~List();

    //Возвращает true если список пустой
    bool empty();

    const Node *getHead() { return this->_head; }

    //Возвращает указатель на последний элемент в списке (с помощью обхода)
    const Node *cback();

    // добавить в конец
    void push_back(const int value);

    // возвращает значение последнего удалённого элемента
    int pop_back();

    //If List is empty then insert in first position
    void insert(const int position, const int value);

    // удаляем элемент по позиции
    void erase(const int position);

    // удаляем вcе узлы
    void clear();

    // сортируем наш список
    void sort();

    // размер листа
    size_t size() { return _size; }

    //Инвертирование списка
    void invert();

    //Возвращает значение среднего элемента списка
    int middle();

private:
    Node* _head = nullptr;
    size_t _size = 0;
};

#endif // !MYLIST_H
