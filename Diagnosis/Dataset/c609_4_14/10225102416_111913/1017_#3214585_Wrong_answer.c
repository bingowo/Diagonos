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
    int n[100],i=0,a[100],m,b,num=1;
    scanf("%c",&c);
    while(1)
    {
        scanf("%d",&n[i++]);
        if(getchar() == '\n')  break;
    }
    a[0] = n[0];
    for(m=1;m<i;m++){
        for(b=0;b<i;b++){
            if(n[m]!=a[b]) a[num++] = n[m];
        }
    }
    if(c == 'A'){
        qsort(a,num,sizeof(a[0]),cmp1);
    }else if(c == 'D'){
        qsort(a,num,sizeof(a[0]),cmp2);
    }
    for(i=0;i<num;i++){
        printf("%d",a[i]);
        if(i!=b-1){
            printf(" ");
        }
    }
    return 0;
}