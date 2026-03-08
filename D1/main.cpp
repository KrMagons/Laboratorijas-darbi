#include <iostream>
#include "KomplekssSkaitlis.h"
using namespace std;

int main(){
    KomplekssSkaitlis k(1, 2);
    k.drukat();
    k.pieskaitit(2, 2);
    k.drukat();
    k.reizinat(2, 2);
    k.drukat();
}
