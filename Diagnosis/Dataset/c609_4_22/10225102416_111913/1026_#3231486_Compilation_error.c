#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Str{
    char x[25];
}str;
int cmp(const void *a, const void *b);
int num(char a[])
{
    int b=0;
    int len = strlen(a),flag=1,i,j;
    for(i=0;i<len;i++){
        falg = 1;
        for(j=i+1;j<len;j++){
            if(a[i]==a[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1) b=b+1;
    }
    return b;
}
int main()
{
    int T,N;
    int i,m;
    scanf("%d",&T);  //T表示问题个数,也表示行数
    for(i = 0;i<T;i++){
        scanf("%d",&N); //N表示待排序数的个数
        str a[N];
        for(m = 0;m<N;m++){
            scanf("%s",&a[m].x);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(m = 0;m<N;m++){
            printf("%s",a[m].x);
            printf("\n");
        }
    }
    return 0;
}
int cmp(const void *a, const void *b){
    str A = (*(str *)a);
    str B = (*(str *)b);
    if(num(A.x)!=num(B.x)){
        return num(B.x)-num(A.x); //按不同字符个数降序
    }
    else{ //不同字符个数相同，按strcmp升序
        return strcmp(A.x,B.x);
    }
}
