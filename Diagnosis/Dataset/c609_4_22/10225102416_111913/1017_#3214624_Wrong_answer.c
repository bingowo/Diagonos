#include<stdio.h>
#include<stdlib.h>

int cmp1(const void *a, const void *b){//升序
    return *(int *)a-*(int *)b;
}
int cmp2(const void *a, const void *b){//降序
    return *(int *)b-*(int *)a;
}
int main()
{
    char c;
    int n[100],i=0,a[100];
    int m,b=0;
    scanf("%c",&c);
    while(1)
    {
        scanf("%d",&n[i++]);
        if(getchar() == '\n')  break;
    }
    if(c == 'A'){
        qsort(n,i,sizeof(n[0]),cmp1);
    }else if(c == 'D'){
        qsort(n,i,sizeof(n[0]),cmp2);
    }
    a[0]=n[0];
    for(m=0;m<i-1;m++){
        if(n[m]!=n[m+1]){
            a[b++]=n[m];
        } 
        if(m==i-2){
            if(n[m]!=n[m+1]) a[b++]=n[m+1];
        }
    }
    for(i=0;i<b;i++){
        printf("%d",a[i]);
        if(i!=b-1){
            printf(" ");
        }
    }
    return 0;
}