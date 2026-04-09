#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct node{
    int num;
    node *next;
};

//Funkcija izveido un atgriez jaunu mezglu ar padoto vertibu
node* create_element(int el);

//Funkcija pievieno saraksta beigas jaunu mezglu ar padoto vertibu
void add_element(node *&first, int el);

//Funkcija pievieno mezglu ar vertibu n pec pirma mezgla ar vertibu m
void insert_after(node *&first, int n, int m);

//Funkcija izvada sarakstu
void print_list(node *first);

//Funkcija izdzes sarakstu no atminas
void delete_list(node *&first);

#endif // LIST_H_INCLUDED
