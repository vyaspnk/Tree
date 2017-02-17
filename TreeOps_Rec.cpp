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
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int a) : val(a), left(NULL), right(NULL){}
};
class Solution {
    Node *root;
    
public:
    Solution() {
        root=NULL;
    }
    Node *addToTree(int);
    void printTree(Node *root);
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
        return 1;
    return std::max(heightOfNode(root->left),heightOfNode(root->right)+1);
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
Solution::printTree(Node *root){
    
    //print PreOrderTraversal
    if(!root)
        return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
int
Solution::sumOfLeafNodes(Node *root) {
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->val;
    return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
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

    Solution s;
    for(auto it:V)
    	s.addToTree(it);
    s.printTree(s.getRoot());
    cout << "Height of the Tree is " << s.heightOfNode(s.getRoot()) << endl;
    cout << "Depth of Node(5) " << s.depthOfNode(s.searchForNode(5)) << endl;
    cout << "Sum of Leaf Node of Sub Tree(2) " << s.sumOfLeafNodes(s.searchForNode(2))
    		<< endl;
    return 0;
}
