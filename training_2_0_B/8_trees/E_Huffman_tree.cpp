#include <iostream>
#include <vector>
#include <memory>

using namespace std;

vector<char> prefix;

struct Node {
	string type;
	shared_ptr<Node> left;
	shared_ptr<Node> right;
	shared_ptr<Node> up;
	Node() : type("root"), left(nullptr), right(nullptr), up(nullptr) {}
	Node(string x, shared_ptr<Node> up) : type(x), left(nullptr), right(nullptr), up(up) {}
};

void traversal(shared_ptr<Node> root, vector<string>& ans) {
	if (root->left == nullptr && root->right==nullptr) {
		string s;
		for (size_t i = 0; i != prefix.size(); ++i) {
			s.push_back(prefix[i]);
		}
		ans.push_back(s);
		return;
	}
	prefix.push_back('0');
	traversal(root->left, ans);
	prefix.pop_back();
	prefix.push_back('1');
	traversal(root->right, ans);
	prefix.pop_back();
}

int main() {
	int n;
	cin >> n;
	vector<string> serialized;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		serialized.push_back(s);
	}
	for (size_t j = 0; j != serialized.size(); ++j) {
		shared_ptr<Node> root = make_shared<Node>();
		shared_ptr<Node> current = root;
		for (int i = 0; i < serialized[j].size(); ++i) {
			if (serialized[j][i] == 'D') {
				shared_ptr<Node> newnode = make_shared<Node>("left", current);
				current->left = newnode;
				current = newnode;
			}
			else if (serialized[j][i] == 'U') {
				while (current->type == "right") {
					current = current->up;
				}
				current = current->up;
				shared_ptr<Node> newnode = make_shared<Node>("right", current);
				current->right = newnode;
				current = newnode;
			}
		}
		vector<string> ans;
		prefix = vector<char>();
		traversal(root, ans);
		cout << ans.size() << '\n';
		for (const auto& e : ans) {
			cout << e << '\n';
		}
	}
	return 0;
}
