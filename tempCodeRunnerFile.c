#include <string.h>
#include <stdio.h>

int main(){

    char tanggal[100];

    strcpy(tanggal, __DATE__);

    for(int i = 0; i< strlen(tanggal); i++){
        if(tanggal[i] == ' '){
            tanggal[i] = '-';
        }
    }

    printf("%s %s\n", __TIME__, tanggal);

    return 0;
}