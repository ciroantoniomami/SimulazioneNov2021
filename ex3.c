#include<stdio.h>

//calcolare la lunghezzza di una stringa, escluso ultimo carattere
int len(char* s, int i){
    if(s[i]=='\0') return i;
    return len(s, i+1);
}

int main(){
    char c[7] = {'G', 'i', 'u', 'l', 'i', 'o'};
    int l = len(c, 0);
    printf("Lunghezza stringa: %d\n", l);
    return 0;
}