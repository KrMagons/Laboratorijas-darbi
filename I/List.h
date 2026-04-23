#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct Node{
    std::string word;
    int count;
    Node *next;
};

/**
    Funkcija izveido un atgriež jaunu saraksta mezglu,
    ar padoto parametru vērtībām
*/
Node* create_node(std::string word, int count);

/**
    Funkcija pievieno sarakstam jaunu vārdu. Ja šāds
    vārds jau ir sarakstā, tad palielina tā skaitu ++
*/
void add_element(Node *&first, std::string word);

/**
    Funkcija atgriež maksimālo vārdu biežumu
*/
int get_max_count(Node *&first);

/**
    Funkcija izvada saraksta elementus (un to biežumus)
*/
void print_list(Node *first);

/**
    Funkcija izdzēš sarakstu
*/
void delete_list(Node *&first);

#endif // LIST_H_INCLUDED
