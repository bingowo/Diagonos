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
    int m=0,b=0;
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
    for (m = 0; m < i - 1; m++)
    {
        if (n[m] == n[m + 1])
        {
            int k = 0;
            for (k = m; k < i - 1; k++)
            {
                n[k] = n[k + 1];
            }
            i--;
            m--;
        }
    }
    for(m=0;m<i;m++){
        printf("%d ",n[m]);
    }
    return 0;
}