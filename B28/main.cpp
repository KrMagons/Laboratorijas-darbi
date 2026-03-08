#include <iostream>
#include <cmath> //sqrt()
using namespace std;

/*B28. Dots naturals skaitis n. Atrast visus tadu naturalu
skaitlu trijniekus a, b, c,a <= b <= c <= n, lai a^2+b^2=c^2.
Risinajuma izmantot funkciju, kas par tris skaitliem noskaidro,
vai tie atbilst nosacijumam.
*/

bool is_pythagorean(int a, int b, int c, int n){
    if(a<=b && b<=c && c<=n && a*a+b*b==c*c) return true;
    return false;
}

int main(){
    int n, a, b, c, ok;
    do{
        while(true){
            cout<<"Ievadi ne nulles naturalu skaitli N: ";
            cin>>n;
            if(n<1){
                cout<<"N jabut ne nulles naturalam skaitlim! Megini velreiz" <<endl;
                continue;
            }else break;
        }
        if(n>4){ //Lidz n=4 trijnieku neeksiste
            //Nulli neizskatam, jo tad bus n izvades ar a=0, b=i, c=b
            for(a=1; a<=n; a++){
                for(b=a; b<=n; b++){
                    c = sqrt(a*a+b*b);
                    if(is_pythagorean(a,b,c,n)){
                        cout<<"a: " <<a <<endl <<"b: " <<b <<endl <<"c: " <<c <<endl <<endl;
                    }
                }
            }
        }else{
            cout<<"Trijnieki a, b, c netika atrasti" <<endl;
        }

        cout<<"Turpinat (1) vai Beigt (0): ";
        cin>>ok;
    }while(ok==1);
}
