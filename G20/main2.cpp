#include <iostream>
#include <list>
using namespace std;

/*
Kristiāns Magons, km25084
G20. Uzrakstīt funkciju, kas ieliek sarakstā elementu ar vērtību n
pēc pirmā elementa ar vērtību m.
Programma izveidota: 26/02/2026
*/

//Funkcija ievieto elementu ar vertibu n, pec pirma elementa ar vertibu m
void insert_after(list<int> &numbers, int n, int m){
    for(auto it=numbers.begin(); it!=numbers.end(); it++){
        if(*it==m){
            it++; //Jo insert pievieno pirms padota iteratora pozicijas
            numbers.insert(it, n);
            cout<<"Elements n tika pievienots sarakstam" <<endl;
            return;
        }
    }
    cout<<"Saraksta nav elementa m: " <<m <<endl;
    return;
}

//Funkcija izdruka sarakstu
void print_list(list<int> &numbers){
    if(numbers.empty()) cout<<"Tukss";
    else{
        for(auto el : numbers) cout<<el <<" ";
    }
    cout<<endl;
}

int main(){
    list<int> numbers;
    int length, el, n, m, ok;

    do{
        while(true){
            cout<<"Ievadiet saraksta garumu: ";
            cin>>length;
            if(length < 0){
                cout<<"Saraksta garums nevar but negativs! Meginiet velreiz" <<endl;
                continue;
            }else break;
        }

        for(int i=0; i<length; i++){
            cout<< "Ievadiet elementu (" <<i+1 <<"/" <<length <<"): ";
            cin>>el;
            numbers.push_back(el);
        }

        cout<<endl <<"Saraksts (pirms): ";
        print_list(numbers);

        cout<<endl <<"Ievadiet n: ";
        cin>>n;
        cout<<"Ievadiet m: ";
        cin>>m;

        insert_after(numbers, n, m);
        cout<<endl <<"Saraksts (pec): ";
        print_list(numbers);

        cout<<endl;
        numbers.clear();
        cout<<"Saraksts izdzests" <<endl;

        cout<<endl;
        cout<<"Turpinat (1) vai Beigt (0): ";
        cin>>ok;
    }while(ok==1);
}
