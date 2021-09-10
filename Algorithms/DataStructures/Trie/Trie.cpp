#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

struct node {
    char currentCharacter;
    bool isWord = false;
    int countPrefix;
    struct node *childrens[27];
}*trie;

void init(){
    trie = new node();
    trie->isWord = false;
    trie->countPrefix = 0;
}

void insert(string word){
    node *currentNode = trie;
    for(int i = 0; i < word.length();i++){
        int currentChar = word[i] - 'a';
        if(currentNode->childrens[currentChar] == NULL){
            currentNode->childrens[currentChar] = new node();
                    
        }
        currentNode = currentNode->childrens[currentChar];
        currentNode->countPrefix++;
        currentNode->currentCharacter = word[i];        

    }
    currentNode->isWord = true;
}
bool searchWord(string word){
    node *currentNode = trie;
    for(int i = 0; i<word.length();i++){
        int currentChar = word[i] - 'a';
        if(currentNode->childrens[currentChar] == NULL)
            return false;
        currentNode = currentNode->childrens[currentChar];
    }
    return currentNode->isWord;
}
int searchPrefix(string word){
    node *currentNode = trie;
    for(int i = 0; i<word.length();i++){
        int currentChar = word[i] - 'a';
        if(currentNode->childrens[currentChar] == NULL)
            return 0;
        currentNode = currentNode->childrens[currentChar];
    }
    return currentNode->countPrefix;
}

char maxPrefix(){
     node *currentNode = trie;
     int maxPrefix = 0;
    for(int i = 0; i<27;i++){
        if(currentNode->childrens[i]!= NULL){
            if(currentNode->childrens[i]->countPrefix>maxPrefix){
               
        }

    }
    return 'a';
    }
}

int main(){
    init();
    insert("alan");
    insert("alanoca");
    insert("alanbrito");
    insert("alfredo");
    cout<<searchWord("alan")<<endl;
    cout<<searchWord("aln")<<endl;
    cout<<searchPrefix("alan")<<endl;
    cout<<searchPrefix("al")<<endl;
    cout<<searchPrefix("a")<<endl;
    cout<<searchWord("alfredo")<<endl;
    cout<<searchWord("alfredos")<<endl;

    return 0;
}