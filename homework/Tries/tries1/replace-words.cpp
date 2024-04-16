#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* child[26]={NULL};
    bool end=false;
};

void insert(node* root, string word)
{
    for(int i=0;i<word.length();i++)
    {
        int ind=word[i]-'a';
        if(root->child[ind]==NULL)
            root->child[ind]=new node();
        root=root->child[ind];
    }
    root->end=true;
}
void search(node* root , string word,string& ans){
    int n=word.size();
    string t;
    for(int i=0;i<word.length();i++){
        int ind=word[i]-'a';
        if(root->child[ind]==NULL){
            ans+=word;
            return;
        }
        t+=word[i];
        root=root->child[ind];
        if(root->end)
        {
            ans+=t;
            return;
        }
    }
    ans+=word;
}
string replaceWords(vector<string>& dictionary, string sentence) {
    node* root=new node();
    for(int i=0;i<dictionary.size();i++)
    {
        insert(root,dictionary[i]);
    }
    string ans="";
    string t;
    for(int i=0;i<sentence.length();i++)
    {
        if(sentence[i]==' ')
        {
            search(root,t,ans);
            ans+=' ';
            t="";
        }
        else
        {
            t+=sentence[i];
        }
    }
    search(root,t,ans);
    return ans;
}