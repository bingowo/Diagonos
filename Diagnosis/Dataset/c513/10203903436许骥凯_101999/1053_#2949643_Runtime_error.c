#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *GPS[20];
    
    int len = 0;
    do{
        char temp[100];
        scanf("%s", &temp);
        GPS[len] = (char*)malloc(sizeof(char) * strlen(temp));
        strcpy(GPS[len++], temp);
    }while(strcmp("END", GPS[len-1]));

    for (int i = len - 2; i >= 0; i--){
        int isFault = 0, j = 0; char type[10]; int typeL = 0;
        while(GPS[i][j++] != '$');
        
        int tJ = j;
        while(GPS[i][tJ++] != ',') type[typeL++] = GPS[i][tJ-1];
        type[typeL] = 0;
        if (strcmp(type, "GPRMC")) continue;

        int tloc = 0, jloc = 0, tlen = 0; char Utime[15]; char isLoc;
        for (; GPS[i][j] != '*'; j++){
            if (GPS[i][j] == ',') tloc++, jloc++;
            if (tloc == 1){
                int tj = j + 1;
                while(GPS[i][tj++] != '.') Utime[tlen++] = GPS[i][tj-1];
                Utime[tlen] = 0;
                tloc = -99999;
            }
            if (jloc == 2) isLoc = GPS[i][j+1], jloc = -99999;

            isFault = GPS[i][j] ^ isFault;
        }
        j++;
        if (isLoc == 'V') continue;
        int arg;
        sscanf(GPS[i] + j, "%x", &arg);
        isFault = ((isFault % 65536) != arg);
        if (isFault) continue;
        
        int time[3];
        time[0] = (Utime[0] - '0') * 10 + (Utime[1] - '0') + 8;
        time[1] = (Utime[2] - '0') * 10 + (Utime[3] - '0');
        time[2] = (Utime[4] - '0') * 10 + (Utime[5] - '0');
        printf("%02d:%02d:%02d\n", time[0], time[1], time[2]);
        break;
    }
    for (int i = 0; i != len; i++) free(GPS[i]);
    return 0;
}