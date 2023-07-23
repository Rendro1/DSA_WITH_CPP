// Trie is a data structure where we can store data.It looks like tree here are node aslo and there are 3 operations insertion, deletion and searching.

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }


    // Insertion in Trie with the help of Recursion.
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal = true;
            return ;
        }
        // word will be in capital latter i'm assuming
        int index = word[0] - 'A';

        // This is like pointer which is keeping track of current node or last occuring char.
        TrieNode* child ;

        if(root->children[index] !=NULL){
            // if the character is present
            child = root->children[index];
        }
        else{
            // if the character is absent.
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //Recursion
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0]-'A';
        TrieNode* child;

        if(root->children[index] !=NULL){
            // if the character is present
            child = root->children[index];
        }
        else{
            // if the character is absent.
            return false;
        }
        //Recursion
        return searchUtil(child,word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root,word);
    }
};

int main(){
    Trie* t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("ARKA");
    cout<<"Present or not->"<<t->searchWord("ABCD")<<endl;
    cout<<"Present or not->"<<t->searchWord("ARKA")<<endl;
    return 0;
}