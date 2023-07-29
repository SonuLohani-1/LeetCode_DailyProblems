#include <bits/stdc++.h>
using namespace std;

// This is daily problem 18 on leetcode
// https://leetcode.com/problems/lru-cache/

// The logic behind the problem is that we will use a doubly linked list and a hashmap to store the key value pairs
// The doubly linked list will store the key value pairs in the order of their usage
// The hashmap will store the address of the node in the doubly linked list
// So when we want to access a key we will first check if it is present in the hashmap or not
// If it is present then we will return the value and move the node to the front of the doubly linked list
// If it is not present then we will return -1
// When we want to insert a key value pair then we will first check if the key is present in the hashmap or not
// If it is present then we will update the value and move the node to the front of the doubly linked list
// If it is not present then we will insert the key value pair at the front of the doubly linked list
// If the size of the doubly linked list exceeds the capacity then we will remove the last node from the doubly linked list and remove the key from the hashmap

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
public:
    int capacity;
    unordered_map<int, Node *> dict;

    // this head and tail are sentinals for making our work easy
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (dict.find(key) == dict.end()) // means the key was not there
        {
            return -1;
        }

        Node *node = dict[key];
        remove(node); // remove the node from the old position in list
        add(node);    // adds the node at the last postion
        return node->val;
    }

    void put(int key, int value)
    {
        if (dict.find(key) != dict.end()) // key is already present first remove it before inserting
        {
            Node *oldNode = dict[key];
            remove(oldNode);
        }
        Node *node = new Node(key, value);
        dict[key] = node;
        add(node);

        if (dict.size() > capacity) // check if the insertion has crossed the capacity
        {
            Node *nodeToDelete = head->next;
            remove(nodeToDelete);
            dict.erase(nodeToDelete->key);
        }
    }

    void add(Node *node)
    {
        Node *previousEnd = tail->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = tail;
        tail->prev = node;
    }

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
    return 0;
}