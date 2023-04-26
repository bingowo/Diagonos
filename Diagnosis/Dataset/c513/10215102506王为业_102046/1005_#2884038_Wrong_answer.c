#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 200
int x[MAXLEN];
int y[MAXLEN];
int lenx;
int leny;
char strx[MAXLEN];
char stry[MAXLEN];
int result[MAXLEN];
void output(int highlen)
{
    for(int i=highlen-1;i>0;--i)
        printf("%d",x[i]);
    printf("%d\n",x[0]);
    for(int i=highlen-1;i>0;--i)
        printf("%d",y[i]);
    printf("%d\n",y[0]);

}
void PRresult(int highlen)
{
    for(int i=highlen-1;i>0;--i)
        printf("%d",result[i]);
    printf("%d\n",result[0]);
}

int ha_multip(int x[],int y[],int highlen)
{
    memset(result,0,MAXLEN*sizeof(result[0]));
    for(int i=0;i<highlen;++i){
        for(int j=0;j<highlen;++j){
            result[i+j]+=x[i]*y[j];
        }
    }
    for(int i=0;i<MAXLEN-2;++i){
        if(result[i]>=10){
            result[i+1]+=result[i]/10;
            result[i]%=10;
        }
    }
    int newlen=MAXLEN-1;
    while(result[newlen]==0)--newlen;
    return newlen+1;//EX:pos=5,len=6
}
int ha_addition(int x[],int y[],int highlen)
{
    memset(result,0,MAXLEN*sizeof(result[0]));
    int tem;
    for(int i=0;i<highlen;++i){
        if((tem=x[i]+y[i]+result[i])>=10)
            result[i+1]+=tem/10;
        result[i]=tem%10;
    }
    if(result[highlen]>0)
        ++highlen;
    return highlen;
}

int main()
{
    scanf("%s",strx);
    scanf("%s",stry);
    lenx=strlen(strx);
    leny=strlen(stry);
    memset(x,0,MAXLEN*sizeof(x[0]));
    memset(y,0,MAXLEN*sizeof(y[0]));
    for(int ix=lenx-1;ix>=0;--ix)
        x[lenx-1-ix]=strx[ix]-'0';
    for(int iy=leny-1;iy>=0;--iy)
        y[leny-1-iy]=stry[iy]-'0';
    //x and y ×îµÍÎ»ÔÚ0
    int highlen=lenx>leny?lenx:leny;
    int reslen=ha_addition(x,y,highlen);
    PRresult(reslen);
    reslen=ha_multip(x,y,highlen);
    PRresult(reslen);
}
