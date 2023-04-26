//sort\1028.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
int arr[1001];

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int ascend=TRUE;
    switch(getchar()){
    case'A':
        break;
    case'D':
        ascend=FALSE;
        break;
    }
    int num;
    while(scanf("%d",&num)!=EOF){
        if(!arr[num]){
            arr[num]=1;
        }
    }
    if(ascend){
        int i=1;
        while(i<=1000&&!arr[i])++i;
        if(i<=1000)printf("%d",i++);
        for(;i<=1000;++i){
            if(arr[i]){
                printf(" %d",i);
            }
        }
    }else{
        int i=1000;
        while(i>=1&&!arr[i])--i;
        if(i>=1)printf("%d",i--);
        for(;i>=1;--i){
            if(arr[i]){
                printf(" %d",i);
            }
        }
        for(;i>=1;--i){
            if(arr[i]){
                printf(" %d",i);
            }
        }
    }

}
