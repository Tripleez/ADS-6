// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
struct SYM {
  char ch;
  int prior;
};
template<typename T>
class TPQueue {
 private:
    struct Node {
        SYM data;
        Node* next;
        explicit Node(const SYM& sym) : data(sym), next(nullptr) {}
    };
    Node* head;

 public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(const SYM& sym) {
        Node* newNode = new Node(sym);
        if (!head || head->data.prior < sym.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.prior >= sym.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    SYM pop() {
        Node* temp = head;
        SYM result = head->data;
        head = head->next;
        delete temp;
        return result;
    }
};
#endif  // INCLUDE_TPQUEUE_H_
