#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    int A = *(int*)a,B = *(int*)b;
    return A-B;
}
int cmp2(const void *a,const void *b)
{
    int A = *(int*)a,B = *(int*)b;
    return B-A;
}



int main()
{
    char c = 0;
    scanf("%c",&c);
    int n[1001];memset(n,0,1001*sizeof(int));
    int cnt = 0;
    while(scanf("%d",&n[cnt++])!=EOF);
    cnt--;
    //printf("cnt = %d\n",cnt);

    int n1[1001];memset(n1,0,1001*sizeof(int));
    int cnt1 = 0;
    for(int i = 0;i<cnt;i++)
    {
        int flag = 0;
        for(int j = i+1;j<cnt;j++)
        {
            if(n[i] == n[j]){flag = 1;break;}
        }
        if(flag == 0){n1[cnt1++] = n[i];}
    }
    if(c=='A'){qsort(n1,cnt1,sizeof(int),cmp1);}
    else if(c == 'D'){qsort(n1,cnt1,sizeof(int),cmp2);}
    for(int i = 0;i<cnt1;i++)
    {
        printf("%d ",n1[i]);
    }
    //printf("%d",n1[cnt-1]);
    return 0;
}
