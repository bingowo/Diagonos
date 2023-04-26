#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char c;
    int a[26]={0};
    int num=-1,i=0;
    while((c=getchar())!='\n'&&c!=EOF)
    {
        if(c==',') {a[++num]=i;i=0;}
        else{i=c-'0'+i*10;}
    }
    a[++num]=i;
    
    //数组从零开始，直到num
    int prime[26]=
    {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

    int data[10000]={0},wei=1;
    for(int l=0,k=num+1;l<num+1;l++,k--)
    {
        for(int h=0;h<wei;h++)
        data[h]*=prime[k];
        data[0]+=a[l];
        for(int h=0;h<wei;h++)
        {
            int yu=0;
            if(data[h]>10)
            {
               int z=data[h];
               data[h]=(z+yu)%10;
               yu=(z+yu)/10;
            }
        }
        if(yu>0) {while(yu>0) {data[wei]=yu%10;yu=yu/10;wei++;}}
    }
    for(int j=wei-1;j>=0;j--)
    printf("%d",data[j]);
    
    return 0;
}

