#include <iostream>
using namespace std;

/*
Kristiāns Magons, km25084
G20. Uzrakstīt funkciju, kas ieliek sarakstā elementu ar vērtību n
pēc pirmā elementa ar vērtību m.
Programma izveidota: 26/02/2026
*/

struct node{
    int num;
    node *next;
};

//Funkcija izveido un atgriez jaunu mezglu ar padoto vertibu
node* create_element(int el){
    node *p = new node;
    p->num = el;
    p->next = nullptr;
    return p;
}

//Funkcija pievieno saraksta beigas jaunu mezglu ar padoto vertibu
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

//Funkcija pievieno mezglu ar vertibu n pec pirma mezgla ar vertibu m
void insert_after(node *&first, int n, int m){
    node *q;
    for(q=first; q!=nullptr; q=q->next){
        if(q->num == m){
            node *p = create_element(n);
            p->next = q->next;
            q->next = p;
            cout<<"Elements n tika pievienots sarakstam" <<endl;
            return;
        }
    }
    cout<<"Saraksta nav elementa m: " <<m <<endl;
}

//Funkcija izvada sarakstu
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

//Funkcija izdzes sarakstu no atminas
void delete_list(node *&first){
    node *p = first;
    while(p != nullptr){
        first = first->next;
        delete p;
        p = first;
    }
    cout<<"Saraksts izdzests" <<endl;
}

int main(){
    node *first = nullptr;
    int len, el, n, m, ok;

    do{
        while(true){
            cout<<"Ievadiet saraksta garumu: ";
            cin>>len;
            if(len < 0){
                cout<<"Saraksta garums nevar but negativs! Meginiet velreiz" <<endl;
            }else break;
        }

        for(int i=0; i<len; i++){
            cout<<"Ievadiet saraksta elementu (" <<i+1 <<"/" <<len <<"): ";
            cin>>el;
            add_element(first, el);
        }

        cout<<"Saraksts (pirms): ";
        print_list(first);

        cout<<endl <<"Ievadiet n: ";
        cin>>n;
        cout<<"Ievadiet m: ";
        cin>>m;

        insert_after(first, n, m);
        cout<<"Saraksts (pec): ";
        print_list(first);

        cout<<endl;
        delete_list(first);

        cout<<endl;
        cout<<"Turpinat (1) vai Beigt (0): ";
        cin>>ok;
    }while(ok == 1);
}
