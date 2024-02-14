// g++ -std=c++11  object.cpp -o object

#include <iostream>
#include <unordered_map>
#include <cstdlib>

struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
};

class LRUCache
{
public:
    int capacity;
    std::unordered_map<int, Node *> map;
    Node *head = nullptr;
    Node *tail = nullptr;
    int length = 0;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        std::cout << "get" << std::endl;
        // check if it's in the map, if not return
        if (map.count(key) == 0)
        {
            std::cout << "there is no this key" << std::endl;
            return -1;
        }

        // if yes, put the node to the top
        Node *node = map[key];
        remove(node);
        prepend(node);

        // return value
        return node->value;
    }

    void put(int key, int value)
    {
        // check capacity, if it's smaller than capacity then add to the map
        if (length < capacity)
        {
            Node *node = createNode(value);
            prepend(node);
            std::cout << "this is head put" << head->value << std::endl;
            std::cout << "this is tail put" << tail->value << std::endl;
            map[key] = node;
        }
        else
        {

            // if it's larger, delete the last item in list
            if (tail != nullptr)
            {
                // if it's larger, delete the last item in list
                std::cout << "remove key" << tail->value << std::endl;
                map.erase(tail->value);
                remove(tail);
            }
            // add new one to unordered_map
            Node *node = createNode(value);
            prepend(node);
            map[key] = node;
        }
    }

    void prepend(Node *node)
    {

        if (head == nullptr)
        {
            head = node;
            tail = node;
            length++;
            return;
        }

        node->prev = nullptr;
        node->next = head;
        head->prev = node;
        head = node;
        length++;
    }
    void remove(Node *node)
    {
        if (node->next == nullptr)
        {
            std::cout << "node next null" << node->next << std::endl;
        }
        if (node == nullptr)
        {
            std::cerr << "Attempting to remove a null node." << std::endl;
            return;
        }
        if (length == 1) // only one element
        {
            std::cout << "node length =1" << std::endl;
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }
        if (node->next && node->prev) // the item is not the last one
        {
            std::cout << "node->next" << std::endl;
            if (node->prev)
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
        }
        else
        {

            if (node->prev && node->next == nullptr) // the item is the last one (tail)
            {
                tail = node->prev;
                node->prev->next = nullptr;
                node->prev = nullptr;
            }
            if (node->prev == nullptr && node->next)
            { // the item is the head
                head = node->next;
                node->next = nullptr;
            }
        }

        node->prev = nullptr;
        node->next = nullptr;
        length--;
        return;
    }
    Node *createNode(int value)
    {

        Node *node = new Node; // Allocate memory for the node
        node->value = value;
        node->prev = nullptr;
        node->next = nullptr;
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
