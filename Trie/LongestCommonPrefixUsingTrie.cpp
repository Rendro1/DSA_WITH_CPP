#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount =0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch){
        root = new TrieNode(ch);
    }


    // Insertion in Trie with the help of Recursion.
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal = true;
            return ;
        }
        // word will be in capital latter i'm assuming
        int index = word[0] - 'a';

        // This is like pointer which is keeping track of current node or last occuring char.
        TrieNode* child ;

        if(root->children[index] !=NULL){
            // if the character is present
            child = root->children[index];
        }
        else{
            // if the character is absent.
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        //Recursion
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }
    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch = str[i];

            if(root->childCount==1){
                ans.push_back(ch);
                // age jao check hole->
                int index = ch - 'a';

                root = root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
    }
};

int main(){
    Trie* t = new Trie('\0');

    vector<string>s = {"coding","codezen","codingninja","coder"};
    int n = s.size();

    for(int i=0;i<n;i++){
        t->insertWord(s[i]);
    }

    string first = s[0];
    string ans = "";

    t->lcp(first,ans);

    cout<<"Here is the longest common prefix-> "<<ans<<endl;
    return 0;
}

// TC = O(m*n);
// SC = O(m*n);