#include <iostream>
#include <vector>
using namespace std;

struct NODE{
 int key;
 NODE* p_left;
 NODE* p_right;
};

NODE* createNode(int key) {
    NODE* newNode = new NODE();
    newNode->key = key;
    newNode->p_left = nullptr;
    newNode->p_right = nullptr;
    return newNode;
}

vector<int> NLR(NODE* pRoot) {
    vector<int> result;
    if (pRoot == nullptr) {
        return result;
    }
    result.push_back(pRoot->key);
    vector<int> leftResult = NLR(pRoot->p_left);
    vector<int> rightResult = NLR(pRoot->p_right);
    result.insert(result.end(), leftResult.begin(), leftResult.end());
    result.insert(result.end(), rightResult.begin(), rightResult.end());
    return result;
}
 vector<int> LNR(NODE* pRoot) {
    vector<int> result;
    if (pRoot == nullptr) {
        return result;
    }
    vector<int> leftResult = LNR(pRoot->p_left);
    result.insert(result.end(), leftResult.begin(), leftResult.end());
    result.push_back(pRoot->key);
    vector<int> rightResult = LNR(pRoot->p_right);
    result.insert(result.end(), rightResult.begin(), rightResult.end());
    return result;
}
 vector<int> LRN(NODE* pRoot) {
    vector<int> result;
    if (pRoot == nullptr) {
        return result;
    }
    vector<int> leftResult = LRN(pRoot->p_left);
    vector<int> rightResult = LRN(pRoot->p_right);
    result.insert(result.end(), leftResult.begin(), leftResult.end());
    result.insert(result.end(), rightResult.begin(), rightResult.end());
    result.push_back(pRoot->key);
    return result;
}
vector<vector<int>> LevelOrder(NODE* pRoot)
{
    vector<vector<int>> result;
    if (pRoot == nullptr) {
        return result;
    }
    vector<NODE*> currentLevel;
    currentLevel.push_back(pRoot);
    while (!currentLevel.empty()) {
        vector<int> levelValues;
        vector<NODE*> nextLevel;
        for (NODE* node : currentLevel) {
            levelValues.push_back(node->key);
            if (node->p_left != nullptr) {
                nextLevel.push_back(node->p_left);
            }
            if (node->p_right != nullptr) {
                nextLevel.push_back(node->p_right);
            }
        }
        result.push_back(levelValues);
        currentLevel = nextLevel;
    }
    return result;
}
int countNode(NODE* pRoot)
{
    if (pRoot == nullptr) {
        return 0;
    }
    return 1 + countNode(pRoot->p_left) + countNode(pRoot->p_right);
}
int sumNode(NODE* pRoot)
{
    if (pRoot == nullptr) {
        return 0;
    }
    return pRoot->key + sumNode(pRoot->p_left) + sumNode(pRoot->p_right);
}
int heightNode(NODE* pRoot, int value)
{
    if (pRoot == nullptr) {
        return -1;
    }
    if (pRoot->key == value) {
        return 0;
    }
    int leftHeight = heightNode(pRoot->p_left, value);
    int rightHeight = heightNode(pRoot->p_right, value);
    if (leftHeight == -1 && rightHeight == -1) {
        return -1;
    }
    return 1 + max(leftHeight, rightHeight);
}
int Level(NODE* pRoot, NODE* p)
{
    if (pRoot == nullptr || p == nullptr) {
        return -1;
    }
    if (pRoot == p) {
        return 0;
    }
    int leftLevel = Level(pRoot->p_left, p);
    int rightLevel = Level(pRoot->p_right, p);
    if (leftLevel == -1 && rightLevel == -1) {
        return -1;
    }
    return 1 + max(leftLevel, rightLevel);
}
int countLeaf(NODE* pRoot)
{
    if (pRoot == nullptr) {
        return 0;
    }
    if (pRoot->p_left == nullptr && pRoot->p_right == nullptr) {
        return 1;
    }
    return countLeaf(pRoot->p_left) + countLeaf(pRoot->p_right);
}
