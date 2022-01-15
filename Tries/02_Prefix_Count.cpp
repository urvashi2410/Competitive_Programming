#include <bits/stdc++.h>
using namespace std;

const int size = 26;

struct node{
    struct node* children[size];
    bool isEnd;
    int prefixCount;
};

struct node* createNode(){
    struct node* root = new node;
    root->isEnd = false;
    
    for(int i = 0; i < size; i++){
        root->children[i] = NULL;
    }
    
    root->prefixCount = 0;
    return root;
}

void insert(struct node* root, string prefix){
    int n = prefix.size();
    struct node* current = root;
    
    for(int i = 0; i < n; i++){
        int idx = prefix[i] - 'a';
        
        if(!current->children[idx]){
            current->children[idx] = createNode();
        }
        
        current->prefixCount++;
        current = current->children[idx];
    }
    current->isEnd = true;
} 

int prefix_count(struct node* root, string prefix){
    struct node* current = root;
    for(int i = 0; i < prefix.size(); i++){
        int idx = prefix[i] - 'a';
        
        if(!current->children[idx]){
            return 0;
        }
        
        current = current->children[idx];
    }
    return current->prefixCount;
}

int main(){
    string s[] = {"ram", "ramlal", "ramdev", "ramdas"};
    
    int n = sizeof(s)/sizeof(s[0]);
    struct node* root = createNode();
    
    for(int i = 0; i < n; i++){
        insert(root, s[i]);
    }
    
    cout << prefix_count(root, "ram");
    return 0;
}