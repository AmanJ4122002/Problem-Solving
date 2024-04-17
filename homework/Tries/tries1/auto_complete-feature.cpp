#include <bits/stdc++.h>
using namespace std;
#define size (26)
#define char_to_ind(c) ((int)c - (int)'a')
struct node
{
    struct node* child[size];
    bool end;
};

struct node* getNode(void)
{
    struct node* pNode = new node;
    pNode->end = false;
    for (int i=0;i<size;i++)
        pNode->child[i] = NULL;
    return pNode;
}
 
void insert(struct node* root, const string key)
{
    struct node* pCrawl = root;
    for (int level=0;level<key.length();level++) {
        int i = char_to_ind(key[level]);
        if (!pCrawl->child[i])
            pCrawl->child[i]=getNode();
 
        pCrawl=pCrawl->child[i];
    }
    pCrawl->end=true;
}
 
bool isLast(struct node* root)
{
    for (int i=0;i<size;i++)
        if (root->child[i])
            return 0;
    return 1;
}
 
void suggestions(struct node* root, string currPrefix)
{
    if (root->end)
        cout << currPrefix << endl;
 
    for (int i = 0; i < size; i++)
        if (root->child[i]) {
            char c='a'+i;
            suggestions(root->child[i],currPrefix+c);
        }
}
int printAutoSuggestions(node* root, const string query)
{
    struct node* pCrawl = root;
    for (char c : query) {
        int ind = char_to_ind(c);
        if (!pCrawl->child[ind])
            return 0;
 
        pCrawl = pCrawl->child[ind];
    }
    if (isLast(pCrawl)) {
        cout << query << endl;
        return -1;
    }
    suggestions(pCrawl, query);
    return 1;
}