#include<bits/stdc++.h>
using namespace std;

struct node
{
    int count=0;
    node *child[26]={NULL}; 
};
void insert(node* root, string word)
{
    for(int i=0;i<word.length();i++)
    {
        int ind=word[i]-'a';
        if(root->child[ind]==NULL){
            root->child[ind]=new node();
        }
        root=root->child[ind];
        root->count=root->count+1;
    }
}
void countPrefix(node* root,int& cnt,string s)
{
    node* curr=root;
    for(int i=0;i<s.length();i++)
    {
        int ind=s[i]-'a';
        curr=curr->child[ind];
        cnt+=curr->count;
    }
}
vector<int> sum(vector<string>& words) {
    node* root=new node();
    for(int i=0;i<words.size();i++)
    {
        insert(root,words[i]);
    }
    vector<int> ans;
    int count;
    for(int i=0;i<words.size();i++)
    {
        count=0;
        countPrefix(root,count,words[i]);
        ans.push_back(count);
    }
    return ans;      
}