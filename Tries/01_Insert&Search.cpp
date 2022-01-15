#include<bits/stdc++.h>
using namespace std;

const int size = 26;
struct node{
    struct node* children[size];
    bool isEnd;
};

struct node* createNode(){
    struct node* ptr = new node;
    ptr->isEnd = false;
    
    for(int i = 0; i < size; i++){
        ptr->children[i] = NULL;
    }
    return ptr;
}

void insert(struct node* root, string word){
    struct node* current = root;
    int n = word.size();
    
    for(int i = 0; i < n; i++){
        int idx = word[i] - 'a';
        
        if(current->children[idx] == NULL){
            current->children[idx] = createNode();
        }
        
        current = current->children[idx];
    }
    
    current->isEnd = true;
}

bool search(struct node* root, string prefix){
    struct node* current = root;
    int n = prefix.size();
    
    for(int i = 0; i < n; i++){
        int idx = prefix[i] - 'a';
        if(!current->children[idx]){
            return false;
        }
        current = current->children[idx];
    }
    if(current->isEnd){
        return true;
    }
    return false;
}

bool startsWith(struct node* root, string prefix){
    struct node* current = root;
    int n = prefix.size();
    
    for(int i = 0; i < n; i++){
        int idx = prefix[i] - 'a';
        
        if(!current->children[idx]){
            return false;
        }
        current = current->children[idx];
    }
    return true;
}

int BF(string s[], string prefix, int n){
    int prefixLetters = 0;
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < prefix.size(); j++){
            if(s[i][j] == prefix[j]){
                prefixLetters++;
            }
        }
        
        if(prefixLetters == prefix.size()){
            ans++;
        }
        
        prefixLetters = 0;
    }
    return ans;
}

int main(){
    string s[] = {"apple", "app", "application", "the", "this", "hello", "hull", "his", "her", "android"};
    int n = 10;
    struct node* root = createNode();
    
    for(int i = 0; i < n; i++){
        insert(root, s[i]);
    }
    
    cout << search(root, "appli") << endl;
    cout << startsWith(root, "appli") << endl;
    return 0;
}