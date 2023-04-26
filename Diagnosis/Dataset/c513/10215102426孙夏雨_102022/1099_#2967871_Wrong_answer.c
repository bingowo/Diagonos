#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char c;
    char ma[10];
}BIAO;

int main()
{
    int T=0,num=36;
    scanf("%d",&T);
    BIAO* p=(BIAO* )malloc(num*sizeof(BIAO));
    char sA[10]={".-"};p->c='A',strcpy(p->ma,sA);
    char sB[10]={"-..."};(p+1)->c='B',strcpy((p+1)->ma,sB);
    char sC[10]={"-.-."};(p+2)->c='C',strcpy((p+2)->ma,sC);
    char sD[10]={"-.."};(p+3)->c='D',strcpy((p+3)->ma,sD);
    char sE[10]={"."};(p+4)->c='E',strcpy((p+4)->ma,sE);
    char sF[10]={"..-."};(p+5)->c='F',strcpy((p+5)->ma,sF);
    char sG[10]={"--."};(p+6)->c='G',strcpy((p+6)->ma,sG);
    char sH[10]={"...."};(p+7)->c='H',strcpy((p+7)->ma,sH);
    char sI[10]={".."};(p+8)->c='I',strcpy((p+8)->ma,sI);
    char sJ[10]={".---"};(p+9)->c='J',strcpy((p+9)->ma,sJ);
    char sK[10]={"-.-"};(p+10)->c='K',strcpy((p+10)->ma,sK);
    char sL[10]={".-.."};(p+11)->c='L',strcpy((p+11)->ma,sL);
    char sM[10]={"--"};(p+12)->c='M',strcpy((p+12)->ma,sM);
    char sN[10]={"-."};(p+13)->c='N',strcpy((p+13)->ma,sN);
    char sO[10]={"---"};(p+14)->c='O',strcpy((p+14)->ma,sO);
    char sP[10]={".--."};(p+15)->c='P',strcpy((p+15)->ma,sP);
    char sQ[10]={"--.-"};(p+16)->c='Q',strcpy((p+16)->ma,sQ);
    char sR[10]={".-."};(p+17)->c='R',strcpy((p+17)->ma,sR);
    char sS[10]={"..."};(p+18)->c='S',strcpy((p+18)->ma,sS);
    char sT[10]={"-"};(p+19)->c='T',strcpy((p+19)->ma,sT);
    char sU[10]={"..-"};(p+20)->c='U',strcpy((p+20)->ma,sU);
    char sV[10]={"...-"};(p+21)->c='V',strcpy((p+21)->ma,sV);
    char sW[10]={".--"};(p+22)->c='W',strcpy((p+22)->ma,sW);
    char sX[10]={"-..-"};(p+23)->c='X',strcpy((p+23)->ma,sX);
    char sY[10]={"-.--"};(p+24)->c='Y',strcpy((p+24)->ma,sY);
    char sZ[10]={"--.."};(p+25)->c='Z',strcpy((p+25)->ma,sZ);
    char s0[10]={"-----"};(p+26)->c='0',strcpy((p+26)->ma,s0);
    char s1[10]={".----"};(p+27)->c='1',strcpy((p+27)->ma,s1);
    char s2[10]={"..---"};(p+28)->c='2',strcpy((p+28)->ma,s2);
    char s3[10]={"...--"};(p+29)->c='3',strcpy((p+29)->ma,s3);
    char s4[10]={"....-"};(p+30)->c='4',strcpy((p+30)->ma,s4);
    char s5[10]={"....."};(p+31)->c='5',strcpy((p+31)->ma,s5);
    char s6[10]={"-...."};(p+32)->c='6',strcpy((p+32)->ma,s6);
    char s7[10]={"--..."};(p+33)->c='7',strcpy((p+33)->ma,s7);
    char s8[10]={"---.."};(p+34)->c='8',strcpy((p+34)->ma,s8);
    char s9[10]={"----."};(p+35)->c='9',strcpy((p+35)->ma,s9);
    char s[1001];
    for(int t=0;t<T;t++){
        scanf("%s",s);
        int jiange=0,len=strlen(s),n=0;
        char daiyi[10];
        printf("case #%d:\n",t);
        for(int i=0;i<len;i++){
            if(s[i]!='/'){
                if(jiange>0){
                    if(jiange==3) printf(" ");
                    else if(jiange==5) printf(".");
                }
                jiange=0;
                daiyi[n]=s[i];
                n++;
            }
            else if(s[i]=='/'){
                if(n>0) {
                    daiyi[n]=0;
                    for(int k=0;k<num;k++){
                        int x=strcmp(daiyi,(p+k)->ma);
                        if(x==0){
                            printf("%c",(p+k)->c);
                            break;
                        }
                    }
                }
                jiange++;
                n=0;
            }
            if(i==len-1) {
                if(n>0){
                    daiyi[n]=0;
                    for(int k=0;k<num;k++){
                        int x=strcmp(daiyi,(p+k)->ma);
                        if(x==0){
                            printf("%c",(p+k)->c);
                            break;
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
