#include <iostream>
#include <cstring> //strcmp()
#include "List.cpp"
using namespace std;

/*
Kristiāns Magons, km25084

G20. Uzrakstīt funkciju, kas ieliek sarakstā elementu ar vērtību n
pēc pirmā elementa ar vērtību m.

GG. GG – STL list un saistītais saraksts ar izņēmumsituāciju apstrādi un
vienībtestēšanu**.

Programma izveidota/papildināta: 10/03/2026
*/

/*
Testejama funkcija: insert_after(first, n, m)
Tests: Elementa n pievienosana pec m, ja elements m ir saraksta sakuma
*/

void test1(){
    node *first=nullptr;
    add_element(first, 11);
    add_element(first, 33);
    add_element(first, 44);
    insert_after(first, 22, 11);
    int expected_result[4] = {11, 22, 33, 44}; //Sagaidamais rezultats

    node *p = first;
    for(int i=0; i<4 && p!=nullptr; i++){
        if(p->num != expected_result[i]) break;
        p=p->next;
    }

    if(p==nullptr) cout<<1 <<" ";
    else cout<<0 <<" ";
    delete_list(first);
}

/*
Testejama funkcija: insert_after(first, n, m)
Tests: Elementa n pievienosana pec m, ja elements m ir saraksta vidu
*/
void test2(){
    node *first=nullptr;
    add_element(first, -10);
    add_element(first, -20);
    add_element(first, -40);
    add_element(first, -50);
    insert_after(first, -30, -20);
    int expected_result[5] = {-10, -20, -30, -40, -50}; //Sagaidamais rezultats

    node *p = first;
    for(int i=0; i<5 && p!=nullptr; i++){
        if(p->num != expected_result[i]) break;
        p=p->next;
    }

    if(p==nullptr) cout<<1 <<" ";
    else cout<<0 <<" ";
    delete_list(first);
}

/*
Testejama funkcija: insert_after(first, n, m)
Tests: Elementa n pievienosana pec m, ja elements m ir saraksta beigas
*/
void test3(){
    node *first=nullptr;
    add_element(first, 2);
    add_element(first, 4);
    add_element(first, 8);
    insert_after(first, 16, 8);
    int expected_result[4] = {2, 4, 8, 16}; //Sagaidamais rezultats

    node *p = first;
    for(int i=0; i<4 && p!=nullptr; i++){
        if(p->num != expected_result[i]) break;
        p=p->next;
    }

    if(p==nullptr) cout<<1 <<" ";
    else cout<<0 <<" ";
    delete_list(first);
}

/*
Testejama funkcija: insert_after(first, n, m)
Tests: Elementa n pievienosana pec m, ja elements m neeksiste saraksta
*/
void test4(){
    node *first=nullptr;
    try{
        add_element(first, 1);
        add_element(first, 2);
        add_element(first, 3);
        insert_after(first, 5, 4); //Meginajums ievietot 5 pec neeksistejosa 4
        cout<<0 <<" "; //Ja neizmet iznemumsituaciju
    }
    catch(const char *s){
        if(strcmp(s, "Saraksta nav elementa m\n")==0){
            cout<<1 <<" ";
        }else cout<<0 <<" ";
    }
    catch(...){
        cout<<"Negaidita kluda\n";
        cout<<0 <<" ";
    }
    delete_list(first);
}

/*
Testejama funkcija: insert_after(first, n, m)
Tests: Elementa n pievienosana pec m, ja saraksts ir tukss
*/
void test5(){
    node *first=nullptr;
    try{
        insert_after(first, 6, 7); //Meginajums ievietot tuksa saraksta
        cout<<0 <<" "; //Ja neizmet iznemumsituaciju
    }
    catch(const char *s){
        if(strcmp(s, "Saraksts ir tukss!\n")==0){
            cout<<1 <<" ";
        }else cout<<0 <<" ";
    }
    catch(...){
        cout<<"Negaidita kluda\n";
        cout<<0 <<" ";
    }
    delete_list(first);
}

int main(){
    cout<<"Funkcijas insert_after() testa rezultati:\n";
    test1(); //1 Saraksts izdests
    test2(); //1 Saraksts izdzests
    test3(); //1 Saraksts izdzests
    test4(); //1 Saraksts izdzests
    test5(); //1 Saraksts izdzests
}
