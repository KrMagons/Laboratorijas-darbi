#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

/**
Kristiāns Magons, km25084

Uzrakstīt programmu, kas atrod dotajā teksta failā
visbiežāk lietotos vienburtīgos, divburtīgos, ...,  sešpadsmitburtīgos vārdus.
Programmai vārdi jāsaliek tabulā, kas realizēta kā masīvs no sarakstiem.
Saraksta elementam jāsatur vārds, skaits (cik reižu vārds sastapts tekstā) un
norāde uz nākošo elementu. Par vārdu uzskatīt tikai tos, kas sastāv no burtiem.
Vārdi failā atdalīti ar tukšumiem vai pieturas zīmēm.

Programma izveidota: 19/04/2026
*/

const int arr_size=16;
Node* words[arr_size];

/**
    Funkcija aizpilda masīvu ar nolasītajiem vārdiem simbolu virknē
*/
void add_words(string line){
    int i=0, length=line.length();
    while(i<length){
        string word="";
        bool is_word=true;
        while(i<length && line[i]!=' '){
            if(!isalpha(line[i])) is_word=false;
            word+=line[i];
            i++;
        }
        if(is_word==true){
            int len=word.length();
            if(len>0 && len<17) add_element(words[len-1], word);
        }
        if(i!=length) i++; /** Lai pārietu ' '*/
    }
}

/**
    Funkcija nolasa katru faila rindu un aizpilda words masīvu
    ar n-burtīgajiem vārdiem un to biežumiem failā
*/
void read_file(string filename){
    ifstream fin(filename);
    if(!fin){cout<<"Kluda: Neizdevas atvert failu" <<endl;return;}

    string line;
    while(getline(fin, line)) add_words(line);
    fin.close();
}

/**
    Funkcija izprintē biežāk lietotos vārdus no masīva
*/
void print_most_used_words(){
    for(int i=0; i<arr_size; i++){
        int max_count=get_max_count(words[i]);
        cout<<i+1 <<" burtigie: ";
        if(max_count!=0){
            for(Node *p=words[i]; p!=nullptr; p=p->next){
                if(p->count==max_count) cout<<p->word <<" ";
            }
        }else{
            cout<<"-";
        }
        cout<<endl;
    }
}

int main(){
    for(int i=0;i<arr_size;i++){Node *p=nullptr;words[i]=p;}
    read_file("vardi.txt");
    print_most_used_words();
    cout<<endl;
    for(int i=0;i<arr_size;i++)
        delete_list(words[i]);
}
