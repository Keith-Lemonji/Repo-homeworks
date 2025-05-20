#include <iostream>
#include <vector>
using namespace std;

struct NODE{
    int key;
    NODE* p_left;
    NODE* p_right;
    int height;
};

NODE* createNode(int key) {
    NODE* newNode = new NODE();
    newNode->key = key;
    newNode->p_left = nullptr;
    newNode->p_right = nullptr;
    return newNode;
}
void Insert(NODE* &pRoot, int x)
{
    if (pRoot == nullptr) {
        pRoot = new NODE();
        pRoot->key = x;
        pRoot->p_left = nullptr;
        pRoot->p_right = nullptr;
        pRoot->height = 1;
    } else if (x < pRoot->key) {
        Insert(pRoot->p_left, x);
    } else {
        Insert(pRoot->p_right, x);
    }
}
void Remove(NODE* &pRoot, int x)
{
    if (pRoot == nullptr) {
        return;
    }
    if (x < pRoot->key) {
        Remove(pRoot->p_left, x);
    } else if (x > pRoot->key) {
        Remove(pRoot->p_right, x);
    } else {
        if (pRoot->p_left == nullptr) {
            NODE* temp = pRoot;
            pRoot = pRoot->p_right;
            delete temp;
        } else if (pRoot->p_right == nullptr) {
            NODE* temp = pRoot;
            pRoot = pRoot->p_left;
            delete temp;
        } else {
            NODE* minNode = pRoot->p_right;
            while (minNode->p_left != nullptr) {
                minNode = minNode->p_left;
            }
            pRoot->key = minNode->key;
            Remove(pRoot->p_right, minNode->key);
        }
    }
}
bool isAVL(NODE* pRoot)
{
    if (pRoot == nullptr) {
        return true;
    }
    int leftHeight = pRoot->p_left ? pRoot->p_left->height : 0;
    int rightHeight = pRoot->p_right ? pRoot->p_right->height : 0;
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    return isAVL(pRoot->p_left) && isAVL(pRoot->p_right);
}
int main()
{
    NODE* pRoot = nullptr;
    int a[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        Insert(pRoot, a[i]);
    }
    cout << "Is AVL: " << (isAVL(pRoot) ? "Yes" : "No") << endl;
    Remove(pRoot, 20);
    cout << "Is AVL after removal: " << (isAVL(pRoot) ? "Yes" : "No") << endl;
    return 0;
}
