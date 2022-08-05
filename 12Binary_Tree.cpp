#include <iostream>
using namespace std;

class Node {
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
        int check_degree() {
            if (this->left == NULL && this->right == NULL) {
                return 0;
            }
            if (this->left != NULL && this->right != NULL) {
                return 2;
            }
            return 1;
        }
    friend class Tree;
};



class Tree {
    private:
        Node* root;
    public:
        Tree() {
            root = NULL;
        }
        void insert(int data) {
            Node* newnode = new Node(data);
            if (root == NULL) {
                root = newnode;
            } else {
                Node* assist = root;
                Node* pre = NULL;
                while(assist != NULL) {
                    pre = assist;
                    if (newnode->data < assist->data) {
                        assist = assist->left;
                    } else {
                        assist = assist->right;
                    }
                }
                if (pre->data < data) {
                    pre->right = newnode;
                } else {
                    pre->left = newnode;
                }
            }
        }
        
        bool find_key(int key) {
            Node* temp = root;
            while (temp != NULL) {
                if (temp->data == key) {
                    return true;
                }
                if (key < temp->data) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
            return false;
        }

        

        void inorder() {
            Node* temp = root;
            traverse0(temp);
        }
        void traverse0(Node* temp) {
            if (temp == NULL) {
                return;
            } 
            traverse0(temp->left);
            cout << temp->data << " ";
            traverse0(temp->right);
        }

        void preorder() {
            Node* temp = root;
            traverse1(temp);
        } 
        void traverse1(Node* temp) {
            if (temp == NULL) {
                return;
            } 
            cout << temp->data << " ";
            traverse1(temp->left);
            traverse1(temp->right);
        }

        void postorder() {
            Node* temp = root;
            traverse2(temp);
        }
        void traverse2(Node* temp) {
            if (temp == NULL) {
                return;
            } 
            traverse2(temp->left);
            traverse2(temp->right);
            cout << temp->data << " ";
        }

        void remove(int data) {
            Node* assist = root;
            Node* pre = NULL;
            if (root->left == NULL && root->right == NULL && root->data == data) {
                root = NULL;
                return;
            }
            while(assist != NULL) {
                pre = assist;
                if (data < assist->data) {
                    assist = assist->left;
                } else {
                    assist = assist->right;
                }
                if (assist != NULL) {

                    if (assist->data == data) {

                        if (assist->check_degree() == 0) {
                            if (pre->left == assist) {
                                pre->left = NULL;
                            } else {
                                pre->right = NULL;
                            }
                        } else if (assist->check_degree() == 1) {
                            if (pre->left == assist) {
                                if (assist->left != NULL) {
                                    pre->left = assist->left;
                                    assist = assist->left;
                                } else {
                                    pre->left = assist->right;
                                    assist = assist->right;
                                }
                            } else {
                                if (assist->left != NULL) {
                                    pre->right = assist->left;
                                    assist = assist->left;
                                } else {
                                    pre->right = assist->right;
                                    assist = assist->right;
                                }
                            }
                        }   
                    }
                } 
            }
        }
};

int main() {
    Tree obj;
    obj.insert(10);
    obj.insert(5);
    obj.insert(13);
    // obj.insert(2);
    obj.insert(6);
    obj.insert(12);
    obj.insert(18);
    obj.inorder();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "after removing.." << endl;
    obj.remove(5);
    obj.inorder();
    cout << endl;
    obj.remove(6);
    obj.inorder();
    cout << endl;
    obj.remove(12);
    obj.inorder();
    cout << endl;
    obj.remove(13);
    obj.inorder();
    cout << endl;
    obj.remove(18);
    obj.inorder();
    cout << endl;
    obj.remove(10);
    cout << endl;
    cout << endl;
    obj.inorder();
    cout << endl;
    return 0;
}