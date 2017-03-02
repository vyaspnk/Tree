//
//  Form_a_tree.cpp
//  Tree
//
//  Created by Vijetha Malla on 2/15/17.
//  Copyright © 2017 vyas. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int a) : val(a), left(NULL), right(NULL){}
};
vector<Node*> stack;
deque<Node*> myq;
class Solution {
    Node *root;
    
public:
    Solution() {
        root=NULL;
    }
    Node *addToTree(int);
    void printTree(Node *root);
    void printInOrderTraversal(Node *);
    void printPreOrderTraversal(Node *);
    void printPostOrderTraversal(Node *);
    void printBFTraversal(Node *);
    Node *getRoot(){
        return root;
    }
    int heightOfNode(Node *root);
    int depthOfNode(Node *);
    Node * searchForNode(int val);
    int sumOfLeafNodes(Node *root);
};
int
Solution::heightOfNode(Node *root) {
    if(!root)
        return 0;
    int nodecount=1;
    int height=0;
    Node *curr = root;
    myq.clear();
    myq.push_back(curr);
    while(curr){
        nodecount = (int)myq.size();
        if(nodecount==0)
            return height;
        else
            height++;
        while(nodecount>0){
            curr = myq.front();
            nodecount--;
            myq.pop_front();
            if(curr->left)
                myq.push_back(curr->left);
            if(curr->right)
                myq.push_back(curr->right);
        }
    }
    return height;
}
int
Solution::depthOfNode(Node *node){
    Node *curr = root;
    if(!node)
        return -1;
    int depth=0;
    while(curr){
        if(curr == node)
            return depth;
        else {
            if(curr->val < node->val)
                curr = curr->right;
            else
                curr = curr->left;
            depth++;
        }
    }
    return depth;
}
Node *
Solution::searchForNode(int val){
    Node *curr = root;
    while(curr && curr->val !=val) {
        if(val<curr->val)
            curr = curr->left;
            else
                curr = curr->right;
                }
    return curr;
}
Node *
Solution::addToTree(int val){
    if(!root) {
        root  = new Node(val);
        return root;
    }
    Node *curr = root;
    while(curr) {
        if(val < curr->val) {
            if(curr->left)
                curr = curr->left;
            else {
                curr->left = new Node(val);
                break;
            }
        } else {
            if(curr->right)
                curr = curr->right;
            else {
                curr->right = new Node(val);
                break;
            }
        }
    }
    return root;
}
void
Solution::printInOrderTraversal(Node *root) {
    if(!root)
        return;
    
    Node *curr = root;
    while(1) {
    	while(curr){
            stack.push_back(curr);
            curr = curr->left;
        }
        
        if(!stack.size())
            break;
        curr = stack.back();
        stack.pop_back();
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}
void
Solution::printPreOrderTraversal(Node *root) {
    if(!root)
        return;
    Node *curr = root;
    while(1) {
        while(curr){
            cout << curr->val << " ";
            if(curr->right)
                stack.push_back(curr->right);
            curr = curr->left;
        }
        if(!stack.size())
            break;
        curr = stack.back();
        stack.pop_back();
    }
    cout << endl;
}
void
Solution::printPostOrderTraversal(Node * root) {
    if(!root)
        return;
    Node *curr = root;
    while(1){
        while(curr){
            if(curr->right)
                stack.push_back(curr->right);
            stack.push_back(curr);
            curr = curr->left;
        }
        if(!stack.size())
            break;
        curr = stack.back();
        stack.pop_back();
        if( stack.size() && curr->right == stack.back() ) {
            Node *tmp = curr;
            curr = stack.back();
            stack.pop_back();
            stack.push_back(tmp);
        } else {
            cout << curr->val << " ";
            curr = NULL;
        }
    }
    cout << endl;
}
void
Solution::printBFTraversal(Node * root) {
    if(!root)
        return;
    Node *curr = root;
    myq.push_back(curr);
    while(myq.size()) {
        curr = myq.front();
        myq.pop_front();
        cout << curr->val << " ";
        if(curr->left)
            myq.push_back(curr->left);
        if(curr->right)
            myq.push_back(curr->right);
    }
    cout << endl;
}
void
Solution::printTree(Node *root){
    //print InOrderTraversal
    if(!root)
        return;
    int max=1;
    Node *curr = root;
    while(1) {
        while(curr){
            stack.push_back(curr);
            curr = curr->left;
        }
        if(!stack.size())
            break;
        curr = stack.back();
        stack.pop_back();
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << "Max Stack Size = " << max << endl;
}
struct less_than_equal {
    inline bool operator()(const Node* &a, const Node* &b) {
        return a->val < b->val;
    }
};
int
Solution::sumOfLeafNodes(Node *root) {
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->val;
    Node *curr = root;
    myq.clear();
    myq.push_back(curr);
    deque<Node *> leafnodes;
    int sum = 0;
    while(myq.size()) { //do level order traversal and add up values of leaf nodes
        int nodecount = (int)myq.size();
        while(nodecount){
            curr = myq.front();
            myq.pop_front();
            nodecount--;
            if(!curr->left && !curr->right) {
                sum += curr->val;
                leafnodes.push_back(curr);
            }
            else {
                if(curr->left)
                    myq.push_back(curr->left);
                if(curr->right)
                    myq.push_back(curr->right);
            }
        }
        
    }
    cout << "Leaf Nodes (Bottom View) of the Tree: " ;
    //std::sort(leafnodes.begin(),leafnodes.end(),less_than_equal());
    for(auto it:leafnodes)
        cout << it->val << " ";
    cout<<endl;
    return sum;
}
int main(){
    vector<int> V;
    V.push_back(5);
    V.push_back(1);

    V.push_back(7);

    V.push_back(2);
    V.push_back(10);
    V.push_back(9);
    V.push_back(8);
    V.push_back(6);
    V.push_back(4);
    V.push_back(11);
    V.push_back(12);
    V.push_back(13);
    V.push_back(14);

    Solution s;
    for(auto it:V)
    	s.addToTree(it);
    cout << "In Order Traversal :" ;
    s.printInOrderTraversal(s.getRoot());
    cout << "Pre Order Traversal :" ;
    s.printPreOrderTraversal(s.getRoot());
    cout << "Post Order Traversal :" ;
    s.printPostOrderTraversal(s.getRoot());
    cout << "Breadth First Traversal :" ;
    s.printBFTraversal(s.getRoot());
    cout << "Height of the Tree is " << s.heightOfNode(s.getRoot()) << endl;
    cout << "Depth of Node(5) " << s.depthOfNode(s.searchForNode(5)) << endl;
    cout << "Sum of Leaf Node of Sub Tree(5) " << s.sumOfLeafNodes(s.searchForNode(5))
    		<< endl;
    return 0;
}
