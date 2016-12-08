#include <iostream>
#include <memory>

/*
    Link List implementation

    Reference:
    http://www.sourcetricks.com/p/programming-interview-questions-and.html#.WEj4JIh948o
    https://www.youtube.com/playlist?list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P

*/

template <typename T>

class Node {
public:
    T data;
    Node<T>* next;
};

template <typename T>
class LinkList {
public:
    LinkList();
    ~LinkList();
    void add_node_at_end(const T value);
    void reverse();
    bool is_empty();
    void print();
    Node<T>* ret_head() {return head;};

private:
    Node<T>* head;
};

/*** Member function definition ***/

template <typename T>
LinkList<T>::LinkList() {
    head = NULL;
}

template <typename T>
LinkList<T>::~LinkList() {
    delete[] head;
}

template <typename T>
void LinkList<T>::add_node_at_end(const T value) {
    Node<T>* temp = new Node<T>();
    temp->data = value;
    temp->next = NULL;

    if (is_empty()) {
        head = temp;
    } else {
        Node<T>* temp1 = head;
        while(temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next=temp;
    }
}

template <typename T>
void LinkList<T>::reverse() {

    if (is_empty()) {
        std::cout<<"Reverse: List is empty"<<std::endl;
        return;
    }

    Node<T>* current = head;
    Node<T>* next = NULL;
    Node<T>* prev = NULL;
   
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template <typename T>
void LinkList<T>::print() {
    
    if (is_empty()) {
        std::cout<<"Print: List is empty"<<std::endl;
        return;
    }
    
    Node<T>* temp = head;    
    std::cout<<"Print List: ";
    while (temp!=NULL) {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;

}

template <typename T>
bool LinkList<T>::is_empty() {
    return (head==NULL);
}

/*** Function definition ***/

template <typename T>
void reverse_print(const Node<T>* node) {
    
    if (node == NULL)
        return;

    reverse_print(node->next);
    std::cout<< node->data <<" ";
}

int main() {
    LinkList<int> list;
    list.add_node_at_end(10);
    list.add_node_at_end(5);
    list.add_node_at_end(1);
    list.print();
    Node<int>* h = list.ret_head();
    reverse_print(h);

    return 0;
}