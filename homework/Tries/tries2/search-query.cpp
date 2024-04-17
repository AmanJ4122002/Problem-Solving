#include<bits/stdc++.h>
using namespace std;

struct node
{
    map<char, node*> child;
    bool end=false;
    int freq=0;
};

class autoComplete 
{
    node* root;
    string curr;
    public:
        autoComplete(vector<string>& sentence, vector<int>& times) {
            root = new node();
            for (int i=0;i<sentence.size();i++)
            {
                insert(sentence[i],times[i]);
            }
        }
        
        void insert(string sentence, int times)
        {
            node* res=root;
            for (int i=0;i<sentence.length();i++)
            {
                int ind= sentence[i]-'a';
                if (!res->child.count(ind)) {
                    res->child[ind]=new node();
                }
                res=res->child[ind];
            }
            res->end=true; 
            res->freq+=times; 
        }
        
        void insertWord(node* res, string sentence, vector<pair<int, string>>& sentences) {
            if (res->end)
            {
                sentences.push_back({res->freq,sentence});
            }
            for(auto& it:res->child)
            {
                insertWord(it.second,sentence+it.first,sentences);
            }
        }
    
        vector<string> input(char c)
        {
            if(c=='#')
            {
                insert(curr,1);
                curr=""; 
                return {}; 
            }
    
            curr+=c; 
            node* res=root;
            vector<pair<int, string>> sentences;     
            for(char ch:curr)
            {
                if (!res->child.count(ch))
                {
                    return {}; 
                }
                res=res->child[ch];
            }
            insertWord(res,curr,sentences);
            sort(sentences.begin(), sentences.end(), [](pair<int, string>& a, pair<int, string>& b)
            {
                return a.first > b.first || (a.first == b.first && a.second < b.second);
            });
    
            vector<string> result;
            for (int i = 0; i < min(3, (int)sentences.size()); ++i) {
                result.push_back(sentences[i].second);
            }
            return result;
        }
};