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
    void reverse_recur(Node<T>* node);
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
void LinkList<T>::reverse_recur(Node<T>* node) {

    /*
        | 1 | 2 | 3 | x
        set head to node 3 when reaching the end
        scope goes back to 2
        In scope 2:
        node->next points to 3, save in temp
        change 3 pointer to node 2
        change 2 pointer to null
        scope goes back to 1
    */

    if (node->next == NULL) {
        head = node;
        return;
    }

    reverse_recur(node->next);

    Node<T>* temp = node->next;
    temp->next = node;
    node->next = NULL; 
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

/*** Main loop ***/

int main() {
    LinkList<int> list;
    list.add_node_at_end(10);
    list.add_node_at_end(5);
    list.add_node_at_end(1);
    list.print();
    Node<int>* h = list.ret_head();
    list.reverse_recur(h);
    list.print();

    return 0;
}