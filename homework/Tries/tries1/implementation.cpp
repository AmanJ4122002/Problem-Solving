#include<bits/stdc++.h>
using namespace std;
struct node
{
    bool end;
    node* child[26];
    node()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
        end=false;
    }
};

class tries
{
public:
    node *root;
    tries() {
        root=new node();
    }
    
    void insert(string word) {
        node *res=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(res->child[ind]==NULL)
            {
                res->child[ind]=new node();
            }
            res=res->child[ind];
        }
        res->end=true;
    }
    
    bool search(string word) {
        node* res=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(res->child[ind]==NULL)
                return false;
            res=res->child[ind];
        }
        return res->end;
    }
    
    bool startsWith(string prefix) {
        node* res = root;
        for (char c : prefix) {
            int ind = c - 'a';
            if (res->child[ind] == NULL)
                return false;
            res=res->child[ind];
        }
        return true;
    }
};