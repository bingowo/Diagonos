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
    int n[100],i=0,a[100],m,b=1;
    scanf("%c",&c);
    while(1)
    {
        scanf("%d",&n[i++]);
        if(getchar() == '\n')  break;
    }

    a[0] = n[0];
    for(m=1;m<i;m++){
        if(n[m]!=a[0]){
            a[b] = n[m];
            b=b+1;
        }
    }
    if(c == 'A'){
        qsort(a,b,sizeof(a[0]),cmp1);
    }else if(c == 'D'){
        qsort(a,b,sizeof(a[0]),cmp2);
    }
    for(i=0;i<b;i++){
        printf("%d",a[i]);
        if(i!=b-1){
            printf(" ");
        }
    }
    return 0;
}