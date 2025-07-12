#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Add new node right after head
    void addNode(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    // Delete a node from the list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];
        int result = node->value;

        // Move the node to front (most recently used)
        deleteNode(node);
        addNode(node);

        return result;
    }

    void put(int key, int value) {
        // If key already exists, delete it first
        if (cache.find(key) != cache.end()) {
            Node* oldNode = cache[key];
            deleteNode(oldNode);
            cache.erase(key);
        }

        // If capacity full, remove least recently used from back
        if (cache.size() == capacity) {
            Node* lruNode = tail->prev;
            deleteNode(lruNode);
            cache.erase(lruNode->key);
        }

        // Insert new node at front
        Node* newNode = new Node(key, value);
        addNode(newNode);
        cache[key] = newNode;
    }
};


int main() {
    LRUCache cache(2); // capacity 2

    cache.put(1, 10);
    cache.put(2, 20);
    cout << "Get 1: " << cache.get(1) << endl; // 10

    cache.put(3, 30); // evicts key 2

    cout << "Get 2: " << cache.get(2) << endl; // -1 (not found)
    cout << "Get 3: " << cache.get(3) << endl; // 30

    cache.put(4, 40); // evicts key 1
    cout << "Get 1: " << cache.get(1) << endl; // -1
    cout << "Get 3: " << cache.get(3) << endl; // 30
    cout << "Get 4: " << cache.get(4) << endl; // 40

}
