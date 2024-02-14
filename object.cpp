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
        // check if it's in the map, if not return
        if (map.count(key) == 0)
        {
            std::cout << "there is no this key" << std::endl;
            return -1;
        }
        std::cout << "key:" << key << std::endl;
        std::cout << "map value:" << map[key] << std::endl;

        // if yes, put the node to the top
        Node *node = map[key];
        prepend(node);

        // return value
        std::cout << "node value is " << node->value << std::endl;
        return node->value;
    }

    void put(int key, int value)
    {
        // check capacity, if it's smaller than capacity then add to the map
        if (length < capacity)
        {
            Node *node = createNode(value);
            prepend(node);
            map[key] = node;
        }
        else
        {

            // if it's larger, delete the last item in list
            int num = tail -> value;
            map.erase(num);
            remove(tail);


            // add new one to unordered_map
            Node *node = createNode(value);
            prepend(node);
            map[key] = node;
        }
    }

    Node *createNode(int value)
    {
        length++;
        Node *node = new Node;
        node->value = value;
        node->prev = nullptr;
        node->next = nullptr;
        return node;
    }
    void prepend(Node *node)
    {

        if (length == 0)
        {
            head = node;
        }

        head->prev = node;
        node->next = head;
        head = node;
    }
    void remove(Node *node)
    {
        if (node == nullptr)
        {
            std::cerr << "Attempting to remove a null node." << std::endl;
            return;
        }
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }
        if (node->next) // the item is not the last one (tail)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        else
        {
            node->prev->next = nullptr;
            tail = node->prev;
            node ->prev = nullptr;
  
        }
        node->prev = nullptr;
        node->next = nullptr;
        length--;
        return;
    }
};

int main()
{
    LRUCache *object = new LRUCache(4);
    return 0;
}
