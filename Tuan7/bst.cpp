#include <iostream>
#include <vector>
using namespace std;

 struct NODE{
 int key;
 NODE* p_left;
 NODE* p_right;
 };

NODE* Search(NODE* pRoot, int x)
{
 if (pRoot == nullptr || pRoot->key == x) {
    return pRoot;
 }
 NODE* leftResult = Search(pRoot->p_left, x);
 if (leftResult != nullptr) {
    return leftResult;
 }
return Search(pRoot->p_right, x);
}
void Insert(NODE* &pRoot, int x)
{
 if (pRoot == nullptr) {
    pRoot = new NODE();
    pRoot->key = x;
    pRoot->p_left = nullptr;
    pRoot->p_right = nullptr;
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
NODE* createTree(int a[], int n)
{
    NODE* pRoot = nullptr;
    for (int i = 0; i < n; i++) {
        Insert(pRoot, a[i]);
    }
    return pRoot;
}
void removeTree(NODE* &pRoot)
{
    if (pRoot != nullptr) {
        removeTree(pRoot->p_left);
        removeTree(pRoot->p_right);
        delete pRoot;
        pRoot = nullptr;
    }
}
int Height(NODE* pRoot)
{
    if (pRoot == nullptr) {
        return 0;
    }
    int leftHeight = Height(pRoot->p_left);
    int rightHeight = Height(pRoot->p_right);
    return 1 + max(leftHeight, rightHeight);
}
int countLess(NODE* pRoot, int x)
{
    if (pRoot == nullptr) {
        return 0;
    }
    if (pRoot->key < x) {
        return 1 + countLess(pRoot->p_left, x) + countLess(pRoot->p_right, x);
    } else {
        return countLess(pRoot->p_left, x);
    }
}
int countGreater(NODE* pRoot, int x)
{
    if (pRoot == nullptr) {
        return 0;
    }
    if (pRoot->key > x) {
        return 1 + countGreater(pRoot->p_left, x) + countGreater(pRoot->p_right, x);
    } else {
        return countGreater(pRoot->p_right, x);
    }
}
bool isBST(NODE* pRoot)
{
    if (pRoot == nullptr) {
        return true;
    }
    if (pRoot->p_left != nullptr && pRoot->p_left->key >= pRoot->key) {
        return false;
    }
    if (pRoot->p_right != nullptr && pRoot->p_right->key <= pRoot->key) {
        return false;
    }
    return isBST(pRoot->p_left) && isBST(pRoot->p_right);
}
bool isFullBST(NODE* pRoot)
{
    if (pRoot == nullptr) {
        return true;
    }
    if ((pRoot->p_left == nullptr && pRoot->p_right != nullptr) || (pRoot->p_left != nullptr && pRoot->p_right == nullptr)) {
        return false;
    }
    return isFullBST(pRoot->p_left) && isFullBST(pRoot->p_right);
} 
