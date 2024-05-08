#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> nebor;
    Node(int data)
    {
        val=data;
        nebor=vector<Node*>();
    }
};
void dfs(Node* node,unordered_map<Node*,Node*>& mp)
{
    Node* copy=new Node(node->val);
    mp[node]=copy;
    for(auto it:node->nebor)
    {
        if(mp.find(it)==mp.end())
            dfs(it,mp);
        copy->nebor.push_back(mp[it]);
    }
}
Node* clone(Node* node) {
    unordered_map<Node*,Node*> mp;
    if(node==NULL)
        return NULL;
    dfs(node,mp);
    return mp[node];
}