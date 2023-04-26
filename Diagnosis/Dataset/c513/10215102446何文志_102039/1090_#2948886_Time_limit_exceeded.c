#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void iToFirstNs(int num, int firstLen, char* s){
    char t[20];memset(t,0,20*sizeof(char));
    sprintf(t,"%d",num);
    //printf("t = %s\n",t);
    while(strlen(t)<firstLen){
        char tmp[20] = "0";
        strcat(tmp,t);
        strcpy(t,tmp);
    }
    //printf("t = %s\n",t);

    strncpy(s,t,firstLen);
    return;
}

void SmultTtoR(char *s,char *t,char *r){
    //int res = 0,slen = strlen(s),tlen = strlen(t);
    //res = (s[0]-'0')*(t[0]-'0')*10+(s[0]-'0')*(t[1]-'0')+(s[1]-'0')*(t[0]-'0');
    int N = 0,M = 0,res = 0;
    sscanf(s,"%d",&N);sscanf(t,"%d",&M);
    res = N*M;
    //printf("res1 = %d\n",res);
    iToFirstNs(res,3,r);
}

//char* NmulMtoR(int N,int M,int R){
//    char sN[3];memset(sN,0,3*sizeof(char));iToFirstNs(N,3,sN);
//    char sM[3];memset(sM,0,3*sizeof(char));iToFirstNs(M,3,sM);
//    char sR[3];memset(sR,0,3*sizeof(char));iToFirstNs(R,3,sR);

//}

int main()
{
    int N = 1;
    while(N!=0){
        scanf("%d",&N);
        if(N==0){break;}
        char sN[10];memset(sN,0,10*sizeof(char));
        iToFirstNs(N,2,sN);
        char res[10];memset(res,0,10*sizeof(char));
        strcpy(res,sN);

        for(int i = 1;i<N;i++){
            char tmp[10];memset(tmp,0,10*sizeof(char));
            SmultTtoR(sN,res,tmp);
            strcpy(res,tmp);
            //printf("tmp = %s, res = %s\n",tmp,res);

        }
        //printf("sN = %s\n",sN);
        //printf("res = %s\n",res);

        //char tmp[10];memset(tmp,0,10*sizeof(char));
        //SmultTtoR(sN,res,tmp);
        //strcpy(res,tmp);
        //printf("tmp = %s, res = %s\n",tmp,res);
        for(int j = 0;j<strlen(res);j++){
            if(res[j]!='0'){
                printf("%c\n",res[j]);
                break;
            }
        }

    }
    return 0;
}
