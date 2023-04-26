#include<stdio.h>
#include<string.h>

void GPS(char *s, int *time){
    int isFault = 0, j = 0; char type[10]; int typeL = 0;
    while(s[j++] != '$');
    
    int tJ = j;
    while(s[tJ++] != ',') type[typeL++] = s[tJ-1];
    type[typeL] = 0;
    if (strcmp(type, "GPRMC")) return;

    int tloc = 0, jloc = 0, tlen = 0; char Utime[15]; char isLoc;
    for (; s[j] != '*'; j++){
        if (s[j] == ',') tloc++, jloc++;
        if (tloc == 1){
            int tj = j + 1;
            while(s[tj++] != '.') Utime[tlen++] = s[tj-1];
            Utime[tlen] = 0;
            tloc = -99999;
        }
        if (jloc == 2) isLoc = s[j+1], jloc = -99999;

        isFault = s[j] ^ isFault;
    }
    j++;
    if (isLoc == 'V') return;
    int arg;
    sscanf(s + j, "%x", &arg);
    isFault = ((isFault % 65536) != arg);
    if (isFault) return ;
    
    time[0] = (Utime[0] - '0') * 10 + (Utime[1] - '0') + 8;
    time[1] = (Utime[2] - '0') * 10 + (Utime[3] - '0');
    time[2] = (Utime[4] - '0') * 10 + (Utime[5] - '0');
}
int main(){
    int time[3];
    char temp[10000] = {0};
    while(strcmp("END", temp)){
        scanf("%s", &temp);
        GPS(temp, time);
    };
    printf("%02d:%02d:%02d\n", time[0], time[1], time[2]);
    return 0;
}