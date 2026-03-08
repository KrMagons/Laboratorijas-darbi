#include <iostream>
#include "KomplekssSkaitlis.h"
using namespace std;

KomplekssSkaitlis::KomplekssSkaitlis(double a, double b){
    this->a = a;
    this->b = b;
}

KomplekssSkaitlis::~KomplekssSkaitlis(){
    cout<<"Objekts izdzests" <<endl;
}

void KomplekssSkaitlis::pieskaitit(double c, double d){
    this->a += c;
    this->b += d;
}

void KomplekssSkaitlis::reizinat(double c, double d){
    double a_cpy = this->a;
    double b_cpy = this->b;
    this->a = a_cpy*c - b_cpy*d;
    this->b = b_cpy*c + a_cpy*d;
}

void KomplekssSkaitlis::drukat(){
    if(b<0) cout<<a <<b <<"i" <<endl;
    else cout<<a <<"+" <<b <<"i" <<endl;
}
