//math\1081.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
#define MAXLEN 550

unsigned char Adec[MAXLEN];
unsigned char Aflo[MAXLEN];
int Adlen,Aflen;
unsigned char Bdec[MAXLEN];
unsigned char Bflo[MAXLEN];
int Bdlen,Bflen;
void get_fl_num(unsigned char dec[],unsigned char flo[],int*p_declen,int*p_flolen)
{
    char c;
    int declen=0,flolen=0;
    while((c=getchar())!='.'&&c!=' '){
        dec[declen++]=c-'0';
    }//dec needs a reverse
    for(int i=0,j=declen-1;i<j;++i,--j){
        unsigned char tem=dec[i];
        dec[i]=dec[j];
        dec[j]=tem;
    }
    while(dec[declen-1]==0)--declen;
    if(declen==0){
        declen=1;
        dec[0]=0;
    }
    if(c!=' '){
        while((c=getchar())!=' '){
            flo[flolen++]=c-'0';
        }
    }
    *p_flolen=flolen;
    *p_declen=declen;
}



int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    get_fl_num(Adec,Aflo,&Adlen,&Aflen);
    get_fl_num(Bdec,Bflo,&Bdlen,&Bflen);

    int N;
    scanf("%d",&N);
    int comlen=Aflen>Bflen?Aflen:Bflen;
    for(int i=comlen-1;i>0;--i){
        Aflo[i]+=Bflo[i];
        Aflo[i-1]+=Aflo[i]/10;
        Aflo[i]%=10;
    }
    //forget to add 0 pos
    Aflo[0]+=Bflo[0];
    if(N<comlen){
        if(Aflo[N]>=5){
            if(N!=0)
                ++Aflo[N-1];
            else
                ++Adec[0];
        }
    }
    for(int i=N-1;i>0;--i){
        if(Aflo[i]>=10){
            Aflo[i-1]+=Aflo[i]/10;
            Aflo[i]%=10;
        }
    }
    Adec[0]+=Aflo[0]/10;
    Aflo[0]%=10;

    int dcomlen=Adlen>Bdlen?Adlen:Bdlen;
    for(int i=0;i<dcomlen;++i){
        Adec[i]+=Bdec[i];
        if(Adec[i]>=10){
            Adec[i+1]+=Adec[i]/10;
            Adec[i]%=10;
        }
    }
    if(Adec[dcomlen]!=0){
        ++dcomlen;
    }

    for(int i=dcomlen-1;i>=0;--i){
        printf("%d",Adec[i]);
    }
    putchar('.');
    for(int i=0;i<N;++i){
        printf("%d",Aflo[i]);
    }

}

