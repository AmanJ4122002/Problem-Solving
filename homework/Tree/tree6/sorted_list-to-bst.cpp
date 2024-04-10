#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node()
    {
        data=0;
        next=NULL;
    }
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* BST(Node* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) return new TreeNode(head->data);
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* node=new TreeNode(slow->data);
    prev->next=nullptr;
    node->left=BST(head);
    node->right=BST(slow->next);
    return node;
}

int main()
{
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);

    TreeNode* root=BST(head);
    cout<<root->value;
    return 0;
}