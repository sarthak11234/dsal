#include<iostream>
#include<stack>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode *left, *right;
    TreeNode(char d) {
        data = d;
        left = right = NULL;
    }
};

class ExpressionTree {
private:
    TreeNode* root;

public:
    ExpressionTree() {
        root = NULL;
    }

    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    void buildTree(string prefix) {
        stack<TreeNode*> st;
        for (int i = prefix.length() - 1; i >= 0; i--) {
            char c = prefix[i];
            TreeNode* node = new TreeNode(c);

            if (isOperator(c)) {
                node->left = st.top(); st.pop();
                node->right = st.top(); st.pop();
            }
            st.push(node);
        }
        root = st.top();
    }

    void postOrderNonRecursive() {
        if (root == NULL)
            return;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }

        cout << "Postorder (non-recursive): ";
        while (!s2.empty()) {
            cout << s2.top()->data;
            s2.pop();
        }
        cout << endl;
    }

    void deleteTree(TreeNode* node) {
        if (node == NULL)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    void deleteEntireTree() {
        deleteTree(root);
        root = NULL;
        cout << "Tree deleted successfully.\n";
    }
};

int main() {
    string prefix;
    ExpressionTree et;

    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    et.buildTree(prefix);

    et.postOrderNonRecursive();

    et.deleteEntireTree();

    return 0;
}
