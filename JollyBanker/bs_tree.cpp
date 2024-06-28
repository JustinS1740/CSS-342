// Justin Singsanavong
#include "bs_tree.h"

BSTree::~BSTree() {
    destroy(root_);
}

void BSTree::destroy(Node* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node->p_acct;
        delete node;
    }
}

bool BSTree::Insert(Account* account) {
    if (!root_) {
        root_ = new Node(account);
        return true;
    }
    Node* current = root_;
    while (current) {
        if (account->getId() < current->p_acct->getId()) {
            if (!current->left) {
                current->left = new Node(account);
                return true;
            }
            current = current->left;
        }
        else if (account->getId() > current->p_acct->getId()) {
            if (!current->right) {
                current->right = new Node(account);
                return true;
            }
            current = current->right;
        }
        else {
            return false;
        }
    }
    return false;
}

bool BSTree::Retrieve(const int& account_id, Account*& account) const {
    Node* current = root_;
    while (current) {
        if (account_id < current->p_acct->getId()) {
            current = current->left;
        }
        else if (account_id > current->p_acct->getId()) {
            current = current->right;
        }
        else {
            account = current->p_acct;
            return true;
        }
    }
    return false;
}

void BSTree::Display() const {
    cout << "FINAL BALANCES:" << endl;
    display(root_);
}

void BSTree::display(Node* node) const {
    if (node) {
        display(node->left);
        node->p_acct->displayAccountSummary();
        display(node->right);
    }
}
