#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <set>
#include <string>
#include <sstream>

using namespace std;

vector<string> ans;

struct Node {
    int val;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, shared_ptr<Node> left, shared_ptr<Node> right) : val(x), left(left), right(right) {}
};

shared_ptr<Node> insert(shared_ptr<Node> root, int val) {
    if (root == nullptr) {
        return make_shared<Node>(val);
    }
    if (val > (root->val)) {
        root->right = insert(root->right, val);
    }
    else if (val < (root->val)) {
        root->left = insert(root->left, val);
    }
    return root;
}

bool find(shared_ptr<Node> root, int val) {
    if (root == nullptr) {
        return false;
    }
    if (root->val == val) {
        return true;
    }
    if (val < root->val) {
        return find(root->left, val);
    }
    else {
        return find(root->right, val);
    }
}

void traversal(shared_ptr<Node> root, int level) {
    if (root == nullptr) {
        return;
    }
    ++level;
    traversal(root->left, level);
    string s;
    for (int i = 1; i < level; ++i) {
        s += '.';
    }
    s += to_string(root->val);
    ans.push_back(s);
    traversal(root->right, level);
}

int main() {
    string s;
    shared_ptr<Node> root = nullptr;
    while (getline(cin, s)) {
        stringstream ss(s);
        string action;
        ss >> action;
        if (action == "ADD") {
            int value;
            ss >> value;
            if (find(root, value)) {
                ans.push_back("ALREADY");
            } else {
                shared_ptr<Node> current = insert(root, value);
                if (root == nullptr) {
                    root = current;
                }
                ans.push_back("DONE");
            }
        } else if (action == "SEARCH") {
            int value;
            ss >> value;
            if (find(root, value)) {
                ans.push_back("YES");
            }
            else {
                ans.push_back("NO");
            }
        } else if (action == "PRINTTREE") {
            traversal(root, 0);
        }
    }
    for (const auto& e : ans) {
        cout << e << '\n';
    }
    return 0;
}
