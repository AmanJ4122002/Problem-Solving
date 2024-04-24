#include <bits/stdc++.h>
using namespace std;

struct node
{
    node* child[2];
    long long count;
};

void insert(int Xor, node* root)
{
    node* temp = root;
    for(int i=31;i>=0;i--)
    {
        bool val=Xor&(1<<i);
        if(temp->child[val]==NULL)
            temp->child[val]=new node();
        temp=temp->child[val];
        temp->count++;
    }
}

long long lessThanK(int Xor, node* root, int k)
{
    node* temp = root;
    long long res = 0;
    for(int i=31;i>=0;i--)
    {
        bool val=Xor&(1<<i);
        bool kval=k&(1<<i);
        if(kval==0)
        {
            if(temp->child[val]!=NULL)
            {
                temp=temp->child[val];
            } 
            else
            {
                break;
            }
        }
        else
        {
            if(temp->child[val]!=NULL)
            {
                res+=temp->child[val]->count;
            }
            if(temp->child[1-val]!=NULL)
            {
                temp=temp->child[1-val];
            }
            else
            {
                break;
            }
        }
    }
    return res;
}

long long subarrayXor(vector<int> arr, int n, int k)
{
    node* root = new node();
    insert(0, root);
    long long res = 0;
    int Xor =0;
    for (int i=0;i<n;i++)
    {
        Xor=Xor^arr[i];
        res+=lessThanK(Xor,root,k);
        insert(Xor,root);
    }
    return res;
}

int main() {
	int num;
	cin >> num;    
	for(int i=0;i<num;i++)
	{
		int n,k;
		cin>>n>>k;
		vector<int> arr;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			arr.push_back(a);
		}
		cout<<subarrayXor(arr,n,k)<<endl;
	}
}