#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

// ”зел двоичного дерева с данными типа int.
struct BNode {
	int key;
	BNode *left;
	BNode *right;

	//BNode(int _k) {
	//	key = _k;
	//	left = NULL;
	//	right = NULL;
	//}
};

// ¬ставка. 
void binary_add(BNode*& root, int k) {
	if (root == NULL) {
		root = new BNode;
		root->key = k;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (root->key > k)
		binary_add(root->left, k);
	else
		binary_add(root->right, k);
};

// pre-order
void show(BNode* root) {
	if (root == NULL)
		return;
	stack<BNode *> s;
	s.push(root);
	while (!s.empty()) {
		BNode *node = s.top();
		s.pop();
		cout << node->key << " ";
		if (node->right != NULL) {
			s.push(node->right);
		}
		if (node->left != NULL) {
			s.push(node->left);
		}
	}
};

// pre-order
void show_to_file(BNode* root) {
	if (root == NULL)
		return;
	ofstream myfile;
	myfile.open("out.txt", ios_base::app);
	stack<BNode *> s;
	s.push(root);
	while (!s.empty()) {
		BNode *node = s.top();
		s.pop();	
		myfile << node->key << " ";
		if (node->right != NULL) {
			s.push(node->right);
		}
		if (node->left != NULL) {
			s.push(node->left);
		}
	}
	myfile << endl;
	myfile.close();
};

//delete tree
void binary_delete(BNode* root) {
	if (root == NULL)
		return;
	stack<BNode *> s;
	s.push(root);
	while (!s.empty()) {
		BNode *node = s.top();
		s.pop();
		if (node->right != NULL) {
			s.push(node->right);
		}
		if (node->left != NULL) {
			s.push(node->left);
		}
		delete node;
		node = nullptr;
	}
};

int main()
{	
	//наивное бинарное дерево поиска
	//нерекурсивный обход в глубину pre-order
	//нерекурсивный обход дл€ освобождени€ пам€ти
	BNode *node = new BNode;
	node = NULL;
	int N;
	int key;
	ifstream myfile("in.txt");
	//cin >> N;
	//for (int i = 0; i < N; ++i) {
	//	cin >> key;
	//	binary_add(node, key);
	//}
	
	while (!myfile.eof()) {
		myfile >> N; 
		for (int i = 0; i < N; ++i) {
			myfile >> key;
			binary_add(node, key);
			//cout << key << " ";
		}
		//cout << endl;
		show_to_file(node);
		binary_delete(node);
		//BNode *node = new BNode;
		node = NULL;
	}
	binary_delete(node);
	myfile.close();
	//show(node);
	//show_to_file(node);
	//binary_delete(node);
	system("pause");
}