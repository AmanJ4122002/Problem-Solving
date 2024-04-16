#include<bits/stdc++.h>
using namespace std;

struct node
{
        int lessLen=0;
        node* child[26];
};
void insert(node*root,int i,vector<string>& wordsContainer)
{
    node* curr=root;
    if(wordsContainer[i].length() < wordsContainer[curr->lessLen].length())
        curr->lessLen= i;
    for(int j = wordsContainer[i].length() - 1; j >= 0; j--) {
        int ch = (wordsContainer[i][j] - 'a');
        if(curr->child[ch] == NULL) {
            curr->child[ch] = new node(i);
        } 
        curr = curr -> child[ch];
        if(wordsContainer[i].length() < wordsContainer[curr->lessLen].length()) 
            curr->lessLen=i;
    }
}
int search(node *root, string word) {
    node* curr = root;
    for(int i = word.size() - 1; i >= 0; i--) {
        int ch = word[i] - 'a';
        if(curr -> child[ch] == NULL) {
            return curr->lessLen;
        } 
        curr = curr->child[ch];
    }
    return curr->lessLen;
}
vector<int> indices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    node *root = new node(0);
    for(int i = 0; i < wordsContainer.size(); i++) {
        insert(root, i, wordsContainer);
    }
    vector<int> ans;
    for(int i = 0; i < wordsQuery.size(); i++) {
        ans.push_back(search(root, wordsQuery[i]));
    }
    return ans;
}