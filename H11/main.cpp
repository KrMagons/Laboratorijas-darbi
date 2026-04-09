#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio> //remove() un rename()
using namespace std;

/**
Kristiāns Magons, km25084

H11. Uzrakstīt programmu, kas ļauj izveidot un labot bināru failu,
kura ieraksta struktūra ir sekojoša:
vārds – atslēga (30 simboli), vārds – vērtība (30 simboli), ieraksta statuss (0 vai 1).
Programmai katrs jauns ieraksts jāieliek faila beigās. Jāparedz iespēja
(1) izmest faila komponenti (loģiski atzīmējot kā izmestu),
(2) izdrukāt faila esošās komponentes uz ekrāna,
(3) izmest loģiski izmestas komponentes fiziski.

Programma izveidota: 06/04/2026
*/

struct record{
    char key[30];
    char value[30];
    char status;
};

/**
    Funkcija pieprasa lietotājam ievadīt jaunu komponenti,
    un pievieno to faila beigās.
*/
void create_record(string filename){
    ofstream f(filename, ios::app | ios::binary);
    if(!f){cout<<"Neizdevas atvert failu" <<endl; return;}

    record r;
    while(true){
        cout<<"Ievadi atslegu [0-30 simboli]: ";
        cin.getline(r.key, 30);
        if(cin.fail()){
            cin.clear();
            cin.ignore(255, '\n');
            cout<<"Atslegai jabut garuma [0-30] simboli. Megini velreiz" <<endl;
            continue;
        }else break;
    }
    while(true){
        cout<<"Ievadi vertibu [0-30 simboli]: ";
        cin.getline(r.value, 30);
        if(cin.fail()){
            cin.clear();
            cin.ignore(255, '\n');
            cout<<"Vertibai jabut garuma [0-30] simboli. Megini velreiz" <<endl;
            continue;
        }else break;
    }
    r.status='1';
    f.write((char*)&r, sizeof(record));
    cout<<"Ieraksts tika pievienots faila" <<endl;
    f.close();
}

/**
    Funkcija pieprasa lietotājam ievadīt komponentes kārtas numuru,
    un izdzēš to (loģiski atzīmējot, kā izmestu).
*/
void delete_record(string filename){
    fstream f(filename, ios::in | ios::out | ios::binary);
    if(!f){cout<<"Neizdevas atvert failu" <<endl; return;}

    //Komponensu skaits = faila izmers/komponentes izmers:
    f.seekg(0, ios::end);
    int filesize=f.tellg();
    int record_count=filesize/sizeof(record);
    f.seekg(0, ios::beg);

    if(record_count==0){
        cout<<"Faila nav neviena ieraksta" <<endl;
        return;
    }

    int pos;
    while(true){
        cout<<"Ievadi dzesama ieraksta kartas numuru [1-" <<record_count <<"]: ";
        cin>>pos;
        if(pos<1 || pos>record_count){
            cin.clear();
            cin.ignore(255, '\n');
            cout<<"Nepareizi ievadits kartas numurs. Megini velreiz" <<endl;
            continue;
        }else break;
    }
    pos=(pos-1)*sizeof(record); //-1, jo kursoru vajag pirms lasāmās komponentes
    f.seekg(pos, ios::beg);
    record r;
    f.read((char*)&r, sizeof(record));
    if(r.status=='1'){
        r.status='0';
        f.seekp(pos, ios::beg);
        f.write((char*)&r, sizeof(record));
        cout<<"Ierakts tika (logiski) dzests" <<endl;
    }else{
        cout<<"Ieraksts jau ir (logiski) dzests" <<endl;
    }
    f.close();
}

/**
    Funkcija loģiski izmestas komponentes izmet fiziski.
*/
void remove_records(string filename){
    ifstream fin(filename, ios::binary);
    ofstream fout("temp.bin", ios::binary);
    if(!fin || !fout){cout<<"Neizdevas atvert failu" <<endl; return;}

    record r;
    bool has_del_records=false;
    while(fin.read((char*)&r, sizeof(record))){
        if(r.status=='1'){
            fout.write((char*)&r, sizeof(record));
        }else{
            has_del_records=true;
        }
    }

    if(has_del_records==true){
        cout<<"Visi logiski dzestie ieraksti tika fiziski izdzesti" <<endl;
    }else{
        cout<<"Faila nav dzesamu ierakstu" <<endl;
    }
    fin.close();
    fout.close();
    remove(filename.c_str());
    rename("temp.bin", filename.c_str());
}

/**
    Funkcija izdrukā failā esošās komponentes.
*/
void print_records(string filename){
    ifstream f(filename, ios::binary);
    if(!f){cout<<"Neizdevas atvert failu" <<endl; return;}

    int i=1;
    record r;
    while(f.read((char*)&r, sizeof(record))){
        cout<<i <<": " <<r.key <<" " <<r.value <<" " <<r.status <<endl;
        i++;
    }
    f.close();
}

int main(){
    //create_record("vardi.bin");
    //delete_record("vardi.bin");
    //remove_records("vardi.bin");
    //print_records("vardi.bin");
}
