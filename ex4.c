#include<stdio.h>

//lunghezza stringa
int len(char* s, int i){
    if(s[i]=='\0') return i;
    return len(s, i+1);
}

//verificare se la stringa in input è palindroma
int palindroma(char* s){
    int l = len(s,0);
    int pal = 1;
    int i = 0;
    while(i<(l/2-1) && pal){
        if(s[i] != s[l-i-1]) pal = 0;
        i++;
    }
    return pal;
}

int main(){
    char s[5] = {'a', 'n', 'n', 'a'};
    int p = palindroma(s);
    if(p) printf("La stringa in input è palindroma\n");
    else printf("La stringa in input non è palindroma\n");
    return 0; 
}