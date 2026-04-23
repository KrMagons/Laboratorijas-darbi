#include <iostream>
#include "List.h"
using namespace std;

Node* create_node(string word, int count){
    Node *p = new Node;
    p->word = word;
    p->count = count;
    p->next = nullptr;
    return p;
}

void add_element(Node *&first, string word){
    if(first==nullptr){
        first=create_node(word, 1);
        return;
    }
    Node *q=first;
    while(true){
        if(q->word==word){
            q->count++;
            return;
        }
        if(q->next==nullptr) break;
        q=q->next;
    }
    q->next=create_node(word, 1);
}

int get_max_count(Node *&first){
    int max_count=0;
    for(Node *p=first; p!=nullptr; p=p->next){
        if(p->count>max_count)
            max_count=p->count;
    }
    return max_count;
}

void print_list(Node *first){
    cout<<"Saraksts: ";
    if(first==nullptr) cout<<"Tukss";
    else{
        while(first!=nullptr){
            cout<<first->word <<": " <<first->count <<" ";
            first=first->next;
        }
    }
    cout<<endl;
}

void delete_list(Node *&first){
    Node *p=first;
    while(first!=nullptr){
        first=first->next;
        delete p;
        p=first;
    }
    cout<<"Saraksts dzests" <<endl;
}
