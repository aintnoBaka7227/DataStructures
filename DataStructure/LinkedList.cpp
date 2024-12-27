#include <iostream>

class Node {
    private:
    int data;
    Node* next;
    friend class LinkedList;
    public: 
    Node() {}
    Node(int data, Node* next) : data(data), next(next) {}
};

class LinkedList {
    private:
    Node* head;
    public: 
    LinkedList() : head(nullptr) {};

    void traversal() {
        if (head) {
            Node* curr = head; 
            std::cout << curr->data << " ";
            while (curr->next) {
                curr = curr->next;
                std::cout << curr->data << " ";
            }
            std::cout << std::endl;
        }
    }

    bool insert(int data) {
        if (!head) {
            head = new Node(data, nullptr);
            return true;
        }
        Node* curr = head;
        if (curr->data == data) return false;
        while (curr->next) {
            curr = curr->next;
            if (curr->data == data) {
                return false;
            }
        }
        curr->next = new Node(data, nullptr);
        return true;
    }

    void insertHead(int data) {
        if (!head) {
            head = new Node(data, nullptr);
        }
        else {
            Node* newNode = new Node(data, head);
            head = newNode; 
        }
    }

    bool insertPosition(int data, int pos) {
        if (pos == 0) {
            insertHead(data);
            return true;
        }

        int count = 0; 
        Node* prev = head; 

        while(count < pos - 1 && prev != nullptr) {
            prev = prev->next; 
            count++;
        } 

        if (prev == nullptr) {
            return false; 
        }

        Node* newNode = new Node(data, prev->next);
        prev->next = newNode; 
        return true;
    }

    bool remove(int data) {
        if (!head) {
            return false;
        }    
        Node* curr = head; 
        if (curr->data == data) {
            head = head->next;
            delete curr;
            return true;
        }
        Node* prev = curr;
        while (curr->next) {
            prev = curr; 
            curr = curr->next;
            if (curr->data == data) {
                prev->next = curr->next;
                delete curr;
                return true;
            }
        }
        return false;
    }

    bool search(int data) {
        if (head) {
            int count = 0;
            Node* curr = head; 
            if (curr->data == data) {
                std::cout<< count << std::endl; 
                return true;
            }
            while (curr->next) {
                count++; 
                curr = curr->next;
                if (curr->data == data) {
                    std::cout << count << std::endl; 
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    LinkedList test; 
    std::cout << test.remove(1) << std::endl;
    std::cout << test.insert(1) << std::endl; 
    std::cout << test.insert(2) << std::endl; 
    std::cout << test.insert(3) << std::endl; 
    std::cout << test.insert(4) << std::endl; 
    std::cout << test.insert(5) << std::endl; 
    test.traversal();
    std::cout << test.search(1) << std::endl;
    std::cout << test.search(3) << std::endl;
    std::cout << test.search(5) << std::endl;
    // std::cout << test.remove(1) << std::endl;
    // test.traversal();
    // std::cout << test.remove(2) << std::endl;
    // test.traversal();
    std::cout << test.remove(5) << std::endl;
    test.traversal();
    std::cout << test.insertPosition(5,5) << std::endl;
    test.traversal();
    return 0;
}