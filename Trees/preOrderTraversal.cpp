#include <iostream>
#include <vector>
#include <stack>
using namespace std ;

class Node {

  public:
      int data ;
      Node* left ;
      Node* right ;

      Node(int value){
        data = value ;
        left = NULL ;
        right = NULL ;
      }
};

Node* createTree(){
    
    int value ;
    cin >> value ;

    if (value == -1){
        return NULL ;
    }

    Node* root = new Node(value);

    root-> left = createTree();
    root -> right = createTree();

    return root ;

}

// Iterative Preorder Traversal
vector<int> preorderTraversal(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top(); st.pop();
        ans.push_back(curr->data);

        if (curr->right) st.push(curr->right);  // push right first
        if (curr->left) st.push(curr->left);    // then left
    }

    return ans;
}

int main (){

    cout << "Tree Node values\n";
    Node* root = createTree();

    vector <int> ans = preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

}