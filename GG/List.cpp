#include <iostream>
#include "List.h"
using namespace std;

node* create_element(int el){
    node *p = new node;
    p->num = el;
    p->next = nullptr;
    return p;
}

void add_element(node *&first, int el){
    node *p = create_element(el);
    if(first == nullptr){
        first = p;
    }else{
        node *q = first;
        while(q->next != nullptr) q=q->next;
        q->next = p;
    }
}

/*
1)Ja saraksts ir tukss, tad saraksts nemainas,
bet tiek izmesta iznemumsituacija "Saraksts ir tukss!"

2)Ja saraksta nav elementa m, tad saraksts nemainas,
bet tiek izmesta iznemumsituacija "Saraksta nav elementa m"
*/
void insert_after(node *&first, int n, int m){
    if(first==nullptr){
        //pielikts vienibtestesanai, jo vajag iznemuma apstradi:
        throw "Saraksts ir tukss!\n";
        return;
    }

    node *q;
    for(q=first; q!=nullptr; q=q->next){
        if(q->num == m){
            node *p = create_element(n);
            p->next = q->next;
            q->next = p;
            return;
        }
    }

    //pielikts vienibtestesanai, jo vajag iznemuma apstradi:
    throw "Saraksta nav elementa m\n";
}

void print_list(node *first){
    if(first == nullptr) cout<<"Tukss" <<endl;
    else{
        while(first != nullptr){
            cout<<first->num <<" ";
            first = first->next;
        }
        cout<<endl;
    }
}

void delete_list(node *&first){
    node *p = first;
    while(p != nullptr){
        first = first->next;
        delete p;
        p = first;
    }
    cout<<"Saraksts izdzests" <<endl;
}
