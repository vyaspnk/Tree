//
//  View_of_Tree.cpp
//  Tree
//
//  Created by Vijetha Malla on 2/16/17.
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
class Solution2 {
    Node *root;
    
public:
    Solution2() {
        root=NULL;
    }
    Node *addToTree(int val){
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
    void printLeftView(Node *);
    void printRightView(Node *);
    void printTopView(Node *);
    void printBottomView(Node *);
    Node *getRoot(){
        return root;
    }
};
void
Solution2::printRightView(Node *root) {
    if(!root)
        return;
    Node *curr = root;
    myq.clear();
    myq.push_back(curr);
    int nodecount=0;
    while((nodecount = (int)myq.size())){
        bool not_shown = true;
        while(nodecount) {
            curr = myq.front();
            myq.pop_front();
            nodecount--;
            if(not_shown){
                cout << curr->val << " ";
                not_shown = false;
            }
            if(curr->right)
                myq.push_back(curr->right);
            if(curr->left)
                myq.push_back(curr->left);
        }
        
    }
    cout << endl;
}
void
Solution2::printLeftView(Node *) {
    if(!root)
        return;
    int nodecount =0;
    Node* curr = root;
    myq.push_back(curr);
    while(myq.size()){
        nodecount = (int)myq.size();
        if(nodecount==0)
            return;
        else {
            bool not_shown = true;
            while(nodecount) {
                curr = myq.front();
                myq.pop_front();
                nodecount--;
                if(not_shown) {
                    cout << curr->val << " ";
                    not_shown = false;
                }
                if(curr->left)
                    myq.push_back(curr->left);
                if(curr->right)
                    myq.push_back(curr->right);
            }
        }
    }
    cout << endl;
}
void
Solution2::printTopView(Node * root) {
    if(!root)
        return;
    myq.clear();
    Node *curr = root;
    myq.push_back(curr);
    deque<Node *> topelem;
    topelem.push_back(curr);
    while(myq.size()) {
        int nodecount = (int)myq.size();
        
        while(nodecount){
            curr = myq.front();
            myq.pop_front();
            if(topelem.back()->val > curr->val){
                topelem.push_back(curr);
            }
            if(topelem.front()->val < curr->val){
                topelem.push_front(curr);
            }
            nodecount--;
            if(curr->left)
                myq.push_back(curr->left);
            if(curr->right)
                myq.push_back(curr->right);
            }
    }
    for(auto it: topelem){
        cout << it->val << " ";
    }
	cout << endl;
}
void
Solution2::printBottomView(Node * root) {
    if(!root)
        return;
    
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
    
    Solution2 s;
    for(auto it:V)
        s.addToTree(it);
    cout << "Left view of the Tree : ";
    s.printLeftView(s.getRoot());
    cout << "Right view of the Tree : ";
    s.printRightView(s.getRoot());
    cout << "Top view of the Tree : ";
    s.printTopView(s.getRoot());
//    cout << "In Order Traversal :" ;
//    s.printInOrderTraversal(s.getRoot());
//    cout << "Pre Order Traversal :" ;
//    s.printPreOrderTraversal(s.getRoot());
//    cout << "Post Order Traversal :" ;
//    s.printPostOrderTraversal(s.getRoot());
//    cout << "Breadth First Traversal :" ;
//    s.printBFTraversal(s.getRoot());
//    cout << "Height of the Tree is " << s.heightOfNode(s.getRoot()) << endl;
//    cout << "Depth of Node(5) " << s.depthOfNode(s.searchForNode(5)) << endl;
//    cout << "Sum of Leaf Node of Sub Tree(2) " << s.sumOfLeafNodes(s.searchForNode(2))
//    << endl;
    return 0;
}
