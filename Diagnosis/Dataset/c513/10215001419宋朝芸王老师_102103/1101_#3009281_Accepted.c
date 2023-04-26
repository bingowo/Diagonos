#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readBlood(){
    char s[5] = {'\0'};
    scanf("%s",s);
    if(strlen(s) == 1 && s[0] == '?') return 0;

    if(!strcmp(s,"A+")) return 1;
    if(!strcmp(s,"A-")) return -1;
    if(!strcmp(s,"AB+")) return 2;
    if(!strcmp(s,"AB-")) return -2;
    if(!strcmp(s,"B+")) return 3;
    if(!strcmp(s,"B-")) return -3;
    if(!strcmp(s,"O+")) return 4;
    if(!strcmp(s,"O-")) return -4;

    return 0;
}

void output(int i, int cases){
    char flag = '+';
    if(i < 0) {i = -i; flag = '-';}
    if(i == 1) printf("A%c",flag);
    else if(i == 2) printf("AB%c",flag);
    else if(i == 3) printf("B%c",flag);
    else if(i == 4) printf("O%c",flag);

    if(cases > 1) printf(",");

}

void write(int ABO[4], int Rh[2]){
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 4; i++) cnt1 += ABO[i];
    for(int i = 0; i < 2; i++) cnt2 += Rh[i];

    if(cnt1*cnt2 == 0) {printf("impossible");return;}

    else if(cnt1*cnt2 == 1){
        for(int i = 0; i < 4; i++){
            if(ABO[i]){
                if(Rh[0]) output(i+1,0);
                else if(Rh[1]) output(-i-1,0);
                return;
            }
        }
    }

    else if(cnt1*cnt2 > 1){
        int cnt = cnt1*cnt2;
        printf("{");
        for(int i = 0; i < 4; i++){
            if(ABO[i]){
                if(Rh[0]) output(i+1,cnt--);
                if(Rh[1]) output(-i-1,cnt--);
            }
        }
        printf("}");
    }
}

int main(){
//A - 0, AB - 1, B - 2, O - 3
    const int ABO[4][4][4]={
    //father mother kid yes/no
    1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
    1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,
    1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1,
    1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};

//Rh+ - 0, Rh- - 1
    const int Rh[2][2][2]={
    //father mother kid yes/no
    1,1,  1,1,
    1,1,  0,1};

    int T;
    scanf("%d",&T);
    for(int R = 0; R < T; R++){
        //input
        int fa, mo, kid;
        fa = readBlood();
        mo = readBlood();
        kid = readBlood();

         //find ans
        int ans_ABO[4] = {0}, ans_Rh[2] = {0};
        if(fa == 0){
            int morh, kidrh, moabo, kidabo;
            int t1 = mo, t2 = kid;
            //rh
            if(t1 > 0) morh = 0;
            else t1 = -t1, morh = 1;
            if(t2 > 0) kidrh = 0;
            else t2 = -t2, kidrh = 1;

            //abo
            moabo = t1 - 1; kidabo = t2 - 1;

            //find Rh
            for(int i = 0; i < 2; i++) ans_Rh[i] = Rh[i][morh][kidrh];

            //find ABO
            for(int i = 0; i < 4; i++) ans_ABO[i] = ABO[i][moabo][kidabo];
        }

        else if(mo == 0){
            int farh, kidrh, faabo, kidabo;
            int t1 = fa, t2 = kid;

            //rh
            if(t1 > 0) farh = 0;
            else t1 = -t1, farh = 1;
            if(t2 > 0) kidrh = 0;
            else t2 = -t2, kidrh = 1;

            //abo
            faabo = t1 - 1; kidabo = t2 - 1;

            //find Rh
            for(int i = 0; i < 2; i++) ans_Rh[i] = Rh[farh][i][kidrh];

            //find ABO
            for(int i = 0; i < 4; i++) ans_ABO[i] = ABO[faabo][i][kidabo];
        }

        else if(kid == 0){
            int farh, morh, faabo, moabo;
            int t1 = fa, t2 = mo;

            //rh
            if(t1 > 0) farh = 0;
            else t1 = -t1, farh = 1;
            if(t2 > 0) morh = 0;
            else t2 = -t2, morh = 1;

            //abo
            faabo = t1 - 1; moabo = t2 - 1;

            //find Rh
            for(int i = 0; i < 2; i++) ans_Rh[i] = Rh[farh][morh][i];

            //find ABO
            for(int i = 0; i < 4; i++) ans_ABO[i] = ABO[faabo][moabo][i];
        }

        //output
        if(fa != 0) output(fa,0);
        else write(ans_ABO,ans_Rh);
        printf(" ");

        if(mo != 0) output(mo,0);
        else write(ans_ABO,ans_Rh);
        printf(" ");

        if(kid != 0) output(kid,0);
        else write(ans_ABO,ans_Rh);
        printf("\n");
    }
    return 0;
}
