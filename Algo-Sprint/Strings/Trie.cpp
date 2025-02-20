#include <bits/stdc++.h>
#include <cstddef>
using namespace std;


struct Trie{
    Trie* children[26];
    int wordCount = 0;

    Trie(){
        for(auto i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

void insert_key(Trie* root, string s){
    Trie* current_node = root;

    for(auto &ch : s){
        if(current_node->children[ch-'a']==NULL){
            Trie* new_node = new Trie();
            current_node->children[ch-'a']= new_node;
        }

        current_node = current_node->children[ch-'a'];
    }
    current_node->wordCount++;
}


bool prefix_exist(Trie* root, string s){
    Trie* current_node = root;

    for(auto &ch : s){
        if(current_node->children[ch-'a']==NULL){
            return false;
        }

        current_node = current_node->children[ch-'a'];
    }

    return true;
}


bool search_key(Trie* root, string s){
    Trie* current_node = root;

    for(auto &ch : s){
        if(current_node->children[ch-'a']==NULL){
            return false;
        }

        current_node = current_node->children[ch-'a'];
    }

    return current_node->wordCount>0;
}


bool delete_key(Trie* root, string s){
    Trie* current_node = root;
    Trie* lastBranchNode = NULL;
    char lastBranchChar = 'a';


    for(auto c : s){
        /*
            If the current char is not present in the string
            We return false since that word does not exist
        */
        if(current_node->children[c-'a']==NULL){
            return false;
        }else{

            int count = 0;

            /*
                Check whether the current node (word) which is to be deleted is
                prefix to anyother word

                Eg:- We have to delete "an", which could be prefix to "and" & "ant"

                So we are counting how many branching is present here

                We're trying to find last node where branching is occuring
            */
            for(auto i=0;i<26;i++){
                if(current_node->children[i]!=NULL){
                    count++;
                }
            }

            // Multiple branching at this node
            if(count>1){
                lastBranchNode = current_node;
                lastBranchChar = c;
            }

            current_node = current_node->children[c-'a'];
        }
    }

    /*
        Now we are the end node i.e at the last character of the word to be deleted
        Eg:- For "and" we are at "d" node
    */
    int count = 0;

    /*
        Check whether there is branching for d and whether it exists as prefix for
        other word.
    */
    for(auto i=0;i<26;i++){
        if(current_node->children[i]!=NULL)
            count++;
    }

    // That is word to be deleted is prefix of possibly multiple words
    // We mark the wordcount as negative and return true
    if (count>0){
        current_node->wordCount--;
        return true;
    }

    // There might be parent for this d node for which there is branching
    // Like and & ant have "an" , where for n multiple branching
    // So we'll just mark the n->d node as null
    if(lastBranchNode!=NULL){
        lastBranchNode->children[lastBranchChar] = NULL;
        return true;
    }
    // Delete the whole word
    else{
        root->children[s[0]]=NULL;
        return true;
    }
}
