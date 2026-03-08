#include <iostream>
#include <fstream>
using namespace std;

/*
Kristiāns Magons, km25084

F22. Dots netukšs teksta fails. Uzrakstīt programmu, kura izvada failā
ieejas tekstu, izmetot no tā visus liekos tukšumus un tabulācijas
(starp vārdiem atstājot tikai vienu tukšumu vai tabulāciju). Bez tam
visas tukšo simbolu virknes, kas satur kaut vienu jaunās rindiņas simbolu
(tātad, tukšie simboli – tukšums, tabulācija, jaunas rindiņas simbols),
pārveidot par vienu jaunās rindiņas simbolu.

Programma izveidota: 2026/02/17
*/

//Funkcija atgriez patiess, ja simbols ir tuksuma simbols
bool isWhiteSpace(char c){
    if(c==' ' || c=='\t' || c=='\n') return true;
    return false;
}

/*Funkcija atgriez patiess, ja simbolu virkne sastav tikai
no tuksuma simboliem*/
bool isWhiteSpaceOnly(string s){
    for(char c : s){
        if(!isWhiteSpace(c)) return false;
    }
    return true;
}

int main(){
    ifstream fin;
    ofstream fout;

    fin.open("ieejas_teksts.txt", ios::in);
    fout.open("izejas_teksts.txt", ios::out);

    if(!fin){
        cout<<"Kluda: nevareja atvert ieejas teksta failu" <<endl;
        return 1;
    }

    if(!fout){
        cout<<"Kluda: nevareja atvert izejas teksta failu" <<endl;
        return 1;
    }

    string line;
    getline(fin, line);
    while(!fin.eof()){
        //Ejam cauri rindai tikai tad, ja ta nesatur tuksuma simbolus
        if(!isWhiteSpaceOnly(line)){
            char prev = 0;
            int len = line.length();
            for(int i=0; i<len; i++){
                //Ja ir divi tuksuma simboli, neko neizvadam
                if(isWhiteSpace(line[i]) && isWhiteSpace(prev)){
                    prev = line[i];
                }else{
                    fout<<line[i];
                    prev = line[i];
                }
            }
        }
        fout<<'\n';
        getline(fin, line);
    }
    fin.close();
    fout.close();
    cout<<"Izejas teksts tika veiksmigi izvadits faila";
    return 0;
}
