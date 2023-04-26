#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    int end1[21],end0[21];
    int n;
    end1[1]=end0[1]=1;
    end1[2]=end0[2]=2;
    end1[3]=3;end0[3]=4;
    for(int i=4;i<21;i++){
        end0[i]=end0[i-1]+end1[i-1];
        end1[i]=end1[i-1]+(end0[i-1]-end1[i-2]);
    }
    do{
        scanf("%d",&n);
        if(n!=-1)printf("%d\n",end1[n]+end0[n]);
    }while(n!=-1);
    return 0;
}
