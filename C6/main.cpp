#include <iostream>
using namespace std;

/*
C6. Doti naturals skaitlis n un veseli skaitli a(1), a(2), ... a(n).
Atrast skaitli, kurs dotaja virkne atkartojas  visvairak reizu pec kartas.
Cik reizes? Ja tadi skaitli ir vairaki, tad izdrukat lielako.
*/

//Funkcija atgriez maksimalo atkartosanas reizu skaitu masiva
int get_max_recurring_count(int *arr, int arr_size){
    int max_recurrence=0;
    for(int i=0; i<arr_size; i++){
        int recurrence=0;
        for(int j=0; j<arr_size; j++){
            if(arr[j]==arr[i]) recurrence++;
        }
        if(recurrence>max_recurrence) max_recurrence = recurrence;
    }
    return max_recurrence;
}

//Funkcija atgriez padota skaitla atkartosanas reizu skaitu masiva
int get_recurring_count(int *arr, int arr_size, int num){
    int recurrence = 0;
    for(int i=0; i<arr_size; i++) if(arr[i]==num) recurrence++;
    return recurrence;
}

int main(){
    int n, ok;
    do{
        while(true){
            cout<<"Ievadiet ne nulles naturalu skaitli N: ";
            cin>>n;
            if(n<1){
                cout<<"N jabut ne nulles naturalam skaitlim! Megini velreiz" <<endl;
                continue;
            }else break;
        }

        int *arr = new int[n];
        cout<<"Ievadi veselu skaitli (1/" <<n <<"): ";
        cin>>arr[0];
        int min_num = arr[0];
        for(int i=1; i<n; i++){
            cout<<"Ievadi veselu skaitli (" <<i+1 <<"/" <<n <<"): ";
            cin>>arr[i];
            if(arr[i]<min_num) min_num=arr[i];
        }

        int max_num = min_num; //Vai nu mazakais atkartosies visvairak, vai tas, kurs atkartosies visvairak bus lielaks
        int max_recurrence = get_max_recurring_count(arr, n);
        for(int i=0; i<n; i++){
            if(get_recurring_count(arr, n, arr[i])==max_recurrence && arr[i]>max_num){
                max_num = arr[i];
            }
        }
        cout<<"Atkartotakais skaitlis: " <<max_num <<endl;
        delete[] arr;

        cout<<"Turpinat (1) vai Beigt (0): ";
        cin>>ok;
    }while(ok==1);
}
