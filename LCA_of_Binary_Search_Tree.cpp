//
//  LCA_of_Binary_Search_Tree.cpp
//  Tree
//
//  Created by Vyas on 2/16/17.
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
class Solution3 {
    Node *root;
    Node* broot;
    
public:
    Solution3() {
        root=NULL;
        broot=NULL;
    }
    void addToBTree(int val) {
        if(!broot) {
            myq.clear();
            broot  = new Node(val);
            myq.push_back(broot);
            return;
        }
        Node *curr = myq.front();
        if(!curr->left){
            curr->left = new Node(val);
            myq.push_back(curr->left);
        } else if(!curr->right){
            curr->right = new Node(val);
            myq.push_back(curr->right);
            myq.pop_front();
        }
        return;
    }
    Node * addToTree(int val){
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
    int lca(Node *, int, int);
    int lca_btree(Node *, int, int);
    Node * searchForNode(int val){
        Node *curr = root;
        while(curr && curr->val !=val) {
            if(val<curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return curr;
    }
    vector<Node *> pathToNodeInBTree(int val){
        vector<Node*> path;
        if(!broot)
            return path;
        
    }
    
//    void printTree(Node *root);
//    void printInOrderTraversal(Node *);
//    void printPreOrderTraversal(Node *);
//    void printPostOrderTraversal(Node *);
//    void printBFTraversal(Node *);
    Node *getRoot(){
        return root;
    }
    int heightOfNode(Node *root);
//    int depthOfNode(Node *);
//    Node * searchForNode(int val);
//    int sumOfLeafNodes(Node *root);
};
int
Solution3::lca(Node * root, int a, int b) {
    if(!root )
        return -1;

    Node *curr = root;
    while(curr){
        if(curr->val > a && curr->val > b){
            curr = curr->left;
        	continue;
        } else if( curr->val < a && curr->val < b) {
            curr = curr->right;
            continue;
        } else
            break;
    }
    return (curr?curr->val:-1);
}
int Solution3::lca_btree(Node *root, int a, int b) {
    if(!root)
        return -1;
    
    return -1;
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
    
    Solution3 s;
    for(auto it:V) {
        s.addToTree(it);
        s.addToBTree(it);
    }
    myq.clear();
    cout << "LCA of 8 and 14 :" << s.lca(s.searchForNode(1), 8, 14) << endl;;
    return 0;
}
