#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    int a[1002];
    char c;
    scanf("%c",&c);
    int b,n=0;
    memset(a,0,sizeof(a));
    while(scanf("%d",&b)!=EOF){
        a[b]++;
        if (a[b]==1) n++;
    }
    if (c=='A'){
        for (int i=0;i<=1000;i++)
            if (a[i]>0)
            if(n>1) {printf("%d ",i);n--;}
            else {printf("%d\n",i);break;}
    }
    else{
        for (int i=1000;i>=0;i--)
            if (a[i]>0)
            if(n>1) {printf("%d ",i);n--;}
            else {printf("%d\n",i);break;}
    }

    return 0;
}
