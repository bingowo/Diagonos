#include <stdio.h>
#include <stdlib.h>

int cmpa(const void *a,const void *b)
{
    int *p1,*p2;
    p1 = (int*)a;
    p2 = (int*)b;
    return (*p1) - (*p2);//升序排列
}
int cmpd(const void *a,const void *b)
{
    int *p1,*p2;
    p1 = (int*)a;
    p2 = (int *)b;
    return (*p2 - *p1);//降序排列
}

int main()
{
    int s[101];
    char ch;
    scanf("%c",&ch);
    int flag = 0;
    if(ch == 'A') flag = 1;
    if(ch == 'D') flag = 0;
    int m = 0;
    char x;
    while(scanf("%d",&s[m]) == 1){
        if((x = getchar()) == EOF)break;
        m++;
    }
    for(int i = 0;i<m;i++){
        for(int j = i+1;j < m;j++){
            if(s[i] == s[j]) s[j] = -1;
        }
    }
    int s0[101];
    int cnt = 0;
    for(int i = 0;i<m+1;i++){
        int k = s[i];
        if(k != -1){
            s0[cnt++] = k;
        }
    }
    if(flag == 1) qsort(s0,cnt,sizeof(s0[0]),cmpa);
    if(flag == 0) qsort(s0,cnt,sizeof(s0[0]),cmpd);
    for(int k = 0;k<cnt-2;k++){
        printf("%d ",s0[k]);
    }
    printf("%d",s0[cnt-2]);
    return 0;
}