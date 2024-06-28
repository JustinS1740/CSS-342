// Justin Singsanavong
#ifndef BS_TREE_H_
#define BS_TREE_H_
#include "account.h"

class BSTree {
public:
    BSTree() : root_(nullptr) {}
    ~BSTree();
    bool Insert(Account* account);
    bool Retrieve(const int& account_id, Account*& account) const;
    void Display() const;

private:
    struct Node {
        Account* p_acct;
        Node* right;
        Node* left;
        Node(Account* account) : p_acct(account), right(nullptr), left(nullptr) {}
    };
    Node* root_;

    void destroy(Node* node);
    void display(Node* node) const;
};
#endif
