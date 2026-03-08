#include <iostream>
using namespace std;

/*
A8. Dots naturals skaitlis n. Izdrukat tos skaitla n reizinatajus,
kuri ir kada naturala skaitla kvadrati.
*/

int main(){
   int n, ok;
   do{
        while(true){
            cout<<"Ievadi ne nulles naturalu skaitli N: ";
            cin>>n;
            if(n<1){
                cout<<"N ir jabut ne nulles naturalam skaitlim! Megini velreiz" <<endl;
                continue;
            }else break;
        }
        for(int i=1; i<=n; i++){
            if(n%i==0){
                for(int j=1; j<=i; j++){
                    if(j*j==i){
                        cout<<"Reizinatajs " <<i <<" ir " <<j <<"^2" <<endl;
                    }
                }
            }
        }
    cout<<"Turpinat (1) vai Beigt (0): ";
    cin>>ok;
   }while(ok==1);
}
