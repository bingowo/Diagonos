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
    int m,g,h;
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
    for ( m = 0; m < i-1; m++)
    {
        for (g = m + 1; g < i; g++)
        {
            if (n[m] == n[g])
            {
                for ( h = g; h < i-1; h++)
                    n[h] = n[h + 1];
                i--;
                g--;
            }
        }
    }
    for(m=0;m<i;m++){
        printf("%d",n[i]);
        if(m!=i-1){
            printf(" ");}
    }
    return 0;
}
