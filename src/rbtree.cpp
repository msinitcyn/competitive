#include <stack>
class RBTreeNode {
public:
    int val;
    RBTreeNode* left;
    RBTreeNode* right;
    bool isBlack;
};

namespace RBTree {

    RBTreeNode* add(RBTreeNode* root, int val) {
        RBTreeNode* newNode = new RBTreeNode();
        newNode->val = val;

        if (!root) {
            newNode->isBlack = false;
            return newNode;
        }

        RBTreeNode* parent = root;
        std::stack<RBTreeNode*> parents;
        parents.push(parent);
        while(parent) {
            if (parent->val > newNode->val) {
                parent = parent->left;
            } else {
                parent = parent->right;
            }
        }

        parent = parents.top();
        parents.pop();
        if (parent->val > newNode->val) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        RBTreeNode* current = newNode;
        while (true) {
            RBTreeNode* grandParent = nullptr;
            if (parents.size()) {
                grandParent = parents.top();
            }
            if (!current->isBlack && parent->right == current) {
                parent->right = current->left;
                parent->isBlack = false;
                current->left = parent;
                parent->isBlack = true;
                if (grandParent) {
                    if (grandParent->left == parent) {
                        grandParent->left = current;
                    } else {
                        grandParent->right = current;
                    }
                }
            }
        }

        return nullptr;
    }

    void remove(RBTreeNode* root, int val) {

    }
};
