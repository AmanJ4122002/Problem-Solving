#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node *child[26];
    bool end;
    set<string> contact;
};

void insert(node* root,string _contact)
{
    node* curr=root;
    for (int i=0;i<_contact.length();i++) {
        int j=_contact[i]-'a';
        if (!curr->child[j])
        {
            curr->child[j] = new node();
        }
        curr=curr->child[j];
        curr->contact.insert(_contact);
    }
    curr->end=true;
}
vector<vector<string>> display(int n, string contact[], string s)
{
    node* root=new node();
    for(int i=0;i<n;i++)
    {
        insert(root,contact[i]);
    }
    node* curr=root;
    vector<vector<string>> res;
    string pre="";
    for(int i=0;i<s.length();i++)
    {
        int k=s[i]-'a';
        if(!curr->child[k])
        {
            for(int j=i;j<s.length();j++)
            {
                res.push_back({"0"});
            }
            return res;
        }
        curr=curr->child[k];
        vector<string> v(curr->contact.begin(), curr->contact.end());
        res.push_back(v);
    }
    return res;
}