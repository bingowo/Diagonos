#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1005

int GCD(int m,int n)
{
    return m%n==0?n:GCD(n,m%n);
}

void fillvalley(int* a,int size,int* water,int* hz,int* hfz,int* hfm) //size->allsize of array
{
    int fz=*water;
    int width=0;int min=a[0];
    for(int i=0;i<size;++i){
        if(a[i]<min)min=a[i];
    }
    for(int i=0;i<size;++i){
        if(a[i]==min)width++;
    }
    if(*water>=width){
        *water-=width;
        for(int i=0;i<size;++i){
            if(a[i]==min)a[i]++;
        }
        *hz=*hz+1;
    }
    else{
        *hfz=fz/GCD(fz,width);
        *hfm=width/GCD(fz,width);
        *water=0;
    }
}

int main()
{
    int water,wid;
    scanf("%d%d\n",&wid,&water);
    int val[N]={0};
    for(int i=0;i<wid;++i)scanf("%d",&val[i]);
    int min=val[0];
    for(int i=0;i<wid;++i){
        if(val[i]<min)min=val[i];
    }
    int hz=min,hfz=0,hfm=0;
    while(water)fillvalley(val,wid,&water,&hz,&hfz,&hfm);
    if(hfz!=0&&hz!=0)printf("%d+%d/%d",hz,hfz,hfm);
    else if(hfz!=0&&hz==0)printf("%d/%d",hfz,hfm);
    else printf("%d",hz);
    return 0;
}
