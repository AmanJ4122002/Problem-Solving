#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left,*right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

TreeNode* tree(vector<int>& v,int low,int high)
{
    if(low>high)
    {
        return NULL;
    }
    int mid=low+(high-low)/2;
    TreeNode* res=new TreeNode(v[mid]);
    res->left=tree(v,low,mid-1);
    res->right=tree(v,mid+1,high);
    return res;
}
TreeNode* BST(vector<int>& v) {
    return tree(v,0,v.size()-1); 
}

int main()
{
    vector<int> v={1,2,3,4,5};
    TreeNode* node=BST(v);
    cout<<node->value<<endl;
    return 0;
}