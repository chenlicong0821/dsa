#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a) {
        val = a;
        left = NULL;
        right = NULL;
    }
};

// 二叉树前序遍历
vector<int> preOrderTranverse(TreeNode* root) {
    vector<int> v;
    stack<TreeNode*> s;
    TreeNode* node = root;
    while (node != NULL || !s.empty()) {
        while (node != NULL) {
            v.push_back(node->val);
            s.push(node);
            node = node->left;
        }
        if (!s.empty()) {
            node = s.top();
            s.pop();
            node = node->right;
        }
    }

    return v;
}

// 二叉树中序遍历
vector<int> inOrderTranverse(TreeNode* root) {
    vector<int> v;
    stack<TreeNode*> s;
    TreeNode* node = root;
    while (node != NULL || !s.empty()) {
        while (node != NULL) {
            s.push(node);
            node = node->left;
        }
        if (!s.empty()) {
            node = s.top();
            s.pop();
            v.push_back(node->val);
            node = node->right;
        }
    }

    return v;
}

const int N = 20;
// 二叉树后序遍历
vector<int> postOrderTranverse(TreeNode* root) {
    vector<int> v;
    int top = -1;
    TreeNode* Q[N];
    int flag[N] = {0};
    TreeNode* node = root;
    while (node != NULL || top != -1) {
        while (node != NULL) {
            top++;
            Q[top] = node;
            flag[top] = 1;
            node = node->left;
        }
        while (top != -1 && flag[top] == 2) {
            v.push_back(Q[top--]->val);
        }
        if (top != -1) {
            flag[top] = 2;
            node = Q[top]->right;
        }
    }

    return v;
}

// 二叉树后序遍历
vector<int> sequenceTranverse(TreeNode* root) {
    vector<int> v;
    TreeNode* Q[N];
    int front = 0, top = 0;
    TreeNode* node = root;
    if (node != NULL) {
        Q[++top] = node;
        while (front < top) {
            node = Q[++front];
            v.push_back(node->val);
            if (node->left != NULL) {
                Q[++top] = node->left;
            }
            if (node->right != NULL) {
                Q[++top] = node->right;
            }
        }
    }

    return v;
}

// 判断是否是完全二叉树
bool compTree(TreeNode* root) {
    bool compBt = true;     // 是否为完全二叉树的标志
    bool leafNode = false;  // 可能找到了叶子节点
    TreeNode* Q[N];
    int front = 0, top = 0;  // front是队头指针, top是队尾指针
    TreeNode* node = root;
    if (node != NULL) {
        Q[++top] = node;  // 将根节点压入队尾
        while (front < top) {
            node = Q[++front];
            if (node->left != NULL) {
                if (!leafNode) {            // 上一层节点均有左右孩子
                    Q[++top] = node->left;  // 左孩子进队
                    if (node->right != NULL) {
                        Q[++top] = node->right;  // 右孩子进队
                    } else {
                        // node有左孩子但没有右孩子，node->left可能是叶子节点
                        leafNode = true;
                    }
                } else {
                    // 之前已经遇到叶子节点或仅有左孩子的节点，当前节点却有左孩子、即该节点不是叶子节点，不是完全二叉树
                    compBt = false;
                    break;
                }
            } else {
                leafNode = true;  // node无左孩子，可能是叶子节点
                if (node->right != NULL) {
                    compBt = false;  // node没有左孩子但有右孩子，不是完全二叉树
                    break;
                }
            }
        }
    } else {
        compBt = false;  // 假设空树不是完全二叉树
    }

    return compBt;
}

void testTranverse(vector<int> tranverseFunc(TreeNode* root), TreeNode* root) {
    vector<int> v = tranverseFunc(root);
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

void testComp(bool compFunc(TreeNode* root), TreeNode* root) {
    cout << compFunc(root) << endl;
}

int main() {
    /*     1
         /   \
        2     3
       / \   /
      4   5 6
             \
              7 */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);

    testTranverse(preOrderTranverse, root);
    testTranverse(inOrderTranverse, root);
    testTranverse(postOrderTranverse, root);
    testTranverse(sequenceTranverse, root);

    testComp(compTree, root);

    return 0;
}
