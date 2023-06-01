#include "MyList.h"
#include <stdexcept>

List::List()
    : _head{ nullptr }, _size{ 0 }
{
}

List::~List()
{
    clear();
}

bool List::empty()
{
    return (_head == nullptr) ? true : false;
}

const List::Node* List::cback()
{
    const Node *lastNode = back();
    return lastNode;
}

List::Node *List::back()
{
    if (empty())
        return _head;
    Node* currentNode = _head;
    while (currentNode->next != nullptr)
        currentNode = currentNode->next;
    return currentNode;
}

void List::push_back(const int value)
{
    if (empty())
    {
        _head = new Node{ nullptr, value };
        ++_size;
    }
    else
    {
        Node* lastNode = back();
        lastNode->next = new Node{nullptr, value};
        ++_size;
    }
}

int List::pop_back()
{
    if (empty())
        throw std::out_of_range("List is empty!");
    Node* currentNode = _head;
    Node* previousNode = nullptr;
    while (currentNode->next != nullptr)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    int value = currentNode->value;
    delete currentNode;
    --_size;
    if (previousNode != nullptr)
        previousNode->next = nullptr;
    else
        _head = nullptr;

    return value;
}

void List::insert(const int position, const int value)
{
	if (empty())
	{
		_head = new Node{ nullptr, value };
		++_size;
	}
	else
	{
		size_t i = 0;
		Node* currentNode = _head;
		while (currentNode->next != nullptr && i < position)
		{
			currentNode = currentNode->next;
			i++;
		}
		if (i != position)
			throw std::out_of_range("Invalid position!");
		Node* nextNode = currentNode->next;
		currentNode->next = new Node{ nextNode, value };
		++_size;
	}
}

void List::erase(const int position)
{
    if (empty())
        throw std::out_of_range("List is empty!");
    int i = 0;
    Node* currentNode = _head;
    Node* previousNode = nullptr;
    while (currentNode->next != nullptr && i < position)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
        i++;
    }
    if (i != position)
        throw std::out_of_range("Invalid position!");
    Node *nextNode = currentNode->next; //next Node of Node in position
    delete currentNode;
    --_size;
    if (previousNode != nullptr)
        previousNode->next = nextNode;
    else
        _head = nextNode;
}

void List::clear()
{
    if (!empty())
    {
        Node* currentNode = _head;
        while (currentNode->next != nullptr)
        {
            Node* tempNode = currentNode->next;
            delete currentNode;
            currentNode = tempNode;
            --_size;
        }
        delete currentNode;
        --_size;
        _head = nullptr;
    }
}

void List::sort()
{
    if (empty())
        throw std::logic_error("List is empty!");
    if(_size > 1)
    {
        for(int i = 0; i < _size-1; i++)
        {
            Node* currentNode = _head;
            Node* previousNode = nullptr;
            while (currentNode->next != nullptr)
            {
                if (currentNode->value > currentNode->next->value)
                {
                    Node* tempNode = currentNode->next;
                    currentNode->next = currentNode->next->next;
                    tempNode->next = currentNode;
                    if (previousNode != nullptr)
                        previousNode->next = tempNode;
                    else
                        _head = tempNode;
                }
                previousNode = currentNode;
                if(currentNode->next != nullptr)
                    currentNode = currentNode->next;
            }
        }
    }
    else if(_size = 2)
    {
        if (_head->value > _head->next->value)
        {
            _head->next->next = _head;
            _head = _head->next;
            _head->next->next = nullptr;
        }
    }
}

void List::invert()
{
    if (empty())
        throw std::out_of_range("List is empty!");
    if (_size > 2)
    {
        Node *previousNode = _head;
        Node *currentNode = _head->next;
        while (_head->next != nullptr)
        {
            currentNode = _head->next;
            _head->next = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
        }
        _head = currentNode;
    }
    else if(_size > 1)
    {
        Node *temp = _head->next;
        temp->next = _head;
        _head->next = nullptr;
        _head = temp;
    }
}

int List::middle()
{
    if(empty())
        throw std::out_of_range("List is empty!");
    if (_size < 3)
        return _head->value;

    Node *currentNode1 = _head;
    Node *currentNode2 = _head;
    while(currentNode2->next != nullptr && currentNode2->next->next != nullptr)
    {
        currentNode1 = currentNode1->next;
        currentNode2 = currentNode2->next->next;
    } 

    return currentNode1->value;
}