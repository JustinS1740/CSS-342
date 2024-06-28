// Justin Singsanavong
#ifndef LIST342_H_
#define LIST342_H_
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

template<class T>
class List342 {
public:
    //constructors
    List342();
    List342( const List342& rhs);
    ~List342();

    //functions
    bool BuildList(string file_name);
    bool Insert(T* obj);
    bool Remove(T target, T& result);
    bool Peek(T target, T& result) const;
    int Size() const;
    void DeleteList();
    bool Merge(List342<T>& list1);

    //overloads
    friend ostream& operator<< (ostream& stream, const List342<T>& list) {
        Node* cur = list.head_;
        while (cur != nullptr) {
            stream << *cur->data;
            cur = cur->next;
        }
        return stream;
    }
    List342<T> operator+(const List342<T>& list) const;
    List342<T>& operator+=(const List342<T>& list);
    bool operator==(const List342<T>& list);
    bool operator!=(const List342<T>& list);
    List342<T>& operator=(const List342<T>& list);

private:
    struct Node {
        T* data = nullptr;
        Node* next = nullptr;
    };
    //data members
    Node* head_;
};

//IMPLMENTATIONS
//constructors
template <class T>
List342<T>::List342() {
    head_ = nullptr;
}

//copy contructor
template <class T>
List342<T>::List342(const List342& rhs) {
    head_ = nullptr;
    *this = rhs;
}

template <class T>
List342<T>::~List342() {
    DeleteList();
}

//functions
template <class T>
bool List342<T>::BuildList(string file_name) {
    ifstream in_file;
    in_file.open(file_name);

    if (in_file.is_open()) {
        while (!in_file.eof()) { 
            T* item = new T();
            in_file >> *item;
            Insert(item);
        }
        return true;
        in_file.close();
    }

    else {
        cout << "Error: file " << file_name << " not found." << endl;
        return false;
    }
}

template <class T>
bool List342<T>::Insert(T* obj) {
    Node* ins_node = new Node;
    ins_node->data = obj;

    //list is empty
    if (head_ == nullptr) {
        head_ = ins_node;
        return true;
    }
    //check duplicate
    Node* temp = head_;
    while (temp != nullptr) {
        if (*temp->data == *obj) {
            return false;
        }
        else {
            temp = temp->next;
        }  
    }

    Node* cur = head_;
    if ((head_ == nullptr) || ((*head_->data) > (*ins_node->data))) {
        if (*cur->data == *obj) {
            return false;
        }
        ins_node->next = head_;
        head_ = ins_node;
    }

    else {
        if (*cur->data == *obj) {
            return false;
        } 
        while ((cur->next != nullptr) && ((*cur->next->data) < (*ins_node->data))) {
            cur = cur->next;
        }
        ins_node->next = cur->next;
        cur->next = ins_node;
    }
    return true;
}


template <class T>
bool List342<T>::Remove(T target, T& result) {
    //empty list
    if (head_ == nullptr) {
        return false;
    }
    
    //first in line
    Node* cur = head_;
    if (*head_->data == target) {
        head_ = head_->next;
        result = *cur->data;
        delete cur;
        return true;
    }

    Node* p_node = head_;
    while (p_node->next != nullptr && *p_node->next->data < target) {
        p_node = p_node->next;
    }

    if ((p_node->next != nullptr) && (*p_node->next->data == target)) {
        cur = p_node->next;
        result = *cur->data;
        p_node->next = p_node->next->next;
        delete cur;
        return true;
    }
    return false;
}

template <class T>
bool List342<T>::Peek(T target, T& result) const {
    //empty list
    if (head_ == nullptr) {
        return false;
    }

    //first in line
    if (*head_->data == target) {
        result = *head_->data;
        return true;
    }

    Node* cur = head_;
    while (cur->next != nullptr && *cur->next->data != target) {
        cur = cur->next;
    }
    if (cur->next != nullptr) {
        Node* temp = cur->next;
        cur->next = cur->next->next;
        result = *temp->data;
        return true;
    }
    return false;
}

template <class T>
void List342<T>::DeleteList() {
    while (!(head_ == nullptr)) {
        Node* cur = new Node;
        cur = head_;
        head_ = head_->next;
        delete(cur);
        cur = nullptr;
    }
}

template <class T>
int List342<T>::Size() const {
    int count = 0;
    Node* cur = head_;
    while (cur) {
        count++;
        cur = cur->next;
    }
    return count;
}

template <class T>
bool List342<T>::Merge(List342<T>& list1) {
    //check if same list
    if (*this == list1) {
        return false;
    }   

    Node* cur = head_;
    while ((cur != nullptr) && (list1.head_ != nullptr)) {
        if (cur->next == nullptr) {
            cur->next = list1.head_;
            list1.head_ = nullptr;
            return true;
        }

        //check duplicates
        else if (*head_->data == *list1.head_->data) {
            Node* temp = list1.head_;
            list1.head_ = list1.head_->next;
            delete temp;
        }

        //first in line
        else if (*head_->data > *list1.head_->data) {
            head_ = list1.head_;
            list1.head_ = list1.head_->next;
            head_->next = cur;
            cur = head_;
        }

        //check duplicates
        else if (*cur->next->data == *list1.head_->data) {
            Node* temp = cur->next;
            temp = list1.head_;
            list1.head_ = list1.head_->next;
            delete temp;
        }

        else if (*cur->next->data > *list1.head_->data) {
            Node* temp = cur->next;
            cur->next = list1.head_;
            list1.head_ = list1.head_->next;
            cur = cur->next;
            cur->next = temp;
        }
        else {
            cur = cur->next;
        }
    }
    return true;
}

//overloads
template<class T>
List342<T> List342<T>::operator+(const List342<T>& rhs) const {
    List342<T> tempList;

    tempList = *this;
    tempList += rhs;

    return tempList;
}

template <class T>
List342<T>& List342<T>::operator+=(const List342<T>& rhs) {
    List342<T> rhs_copy;
    rhs_copy = rhs;
    Merge(rhs_copy);
    return *this;
}

template <class T>
bool List342<T>::operator==(const List342<T>& rhs) {
    Node* lhs = head_;
    Node* new_rhs = rhs.head_;

    while ((lhs != nullptr) && (new_rhs != nullptr)) {
        if (lhs->data != new_rhs->data) {
            return false;
        }
        lhs = lhs->next;
        new_rhs = new_rhs->next;
    }

    return ((lhs == nullptr) && (new_rhs == nullptr));
}

template <class T>
bool List342<T>::operator!=(const List342<T>& rhs) {
    if (*this == rhs) {
        return false;
    }
    return true;
}

template <class T>
List342<T>& List342<T>::operator=(const List342<T>& rhs) {
    T ans = *rhs.head_->data;
    T result;

    while (Remove(ans, result));
    Node* s_node = nullptr;
    Node* ins_node = nullptr;

    //empty list
    if (rhs.head_ == nullptr) {
        return *this;
    }

    Node* d_node = new Node;
    d_node->data = rhs.head_->data;
    head_ = d_node;
    s_node = rhs.head_->next;

    while (!(s_node == nullptr)) {
        ins_node = new Node;
        ins_node->data = s_node->data;
        d_node->next = ins_node;
        d_node = d_node->next;
        s_node = s_node->next;
    }
    return *this;
}
#endif