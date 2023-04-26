#include <stdio.h>
#include <stdlib.h>


int cmp(const void* a,const void* b)
{
    int* pa=(int*) a; int* pb=(int*)b;
    return (*pa-*pb);
}

int main()
{
    int n,m;
    scanf("%d",&n);
    int** store=(int**)malloc(n*sizeof(int*));
    int* mm=(int*)malloc(n*sizeof(int));
    int max=0,min=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&m);
        mm[i]=m;
        store[i]=(int*)malloc(m*sizeof(int));
        for (int j=0;j<m;j++)
            scanf("%d",&store[i][j]);
        qsort(store[i],m,sizeof(int),cmp);
        if (store[i][m-1]>max)
            max=store[i][m-1];
        if (store[i][0]<min)
            min=store[i][0];
    }
    int d=0;
    char* s=(char*)malloc(n*sizeof(char));
    for (int i=min;i<=max;i++)
    {
        int cnt=0;
        for (int j=0;j<n;j++)
        {
            if (store[j][0]>i)
                break;
            else
            {
                if (i>store[j][mm[j]/2])
                    for (int k=mm[j]-1;k>=mm[j]/2;k--)
                    {
                        if (store[j][k]==i)
                        {
                            cnt++;
                            break;
                        }
                        if (store[j][k]<i)
                            break;
                    }
                else
                {for (int k=0;k<=mm[j]/2;k++)
                {
                    if (store[j][k]==i)
                        {
                            cnt++;
                            break;
                        }
                    if (store[j][k]>i)
                            break;
                }}

            }
        }
        if (cnt==n)
            s[d++]=i+'0';
    }
    s[d]=0;
    for (int i=0;i<strlen(s);i++)
        printf("%c%c",s[i],(i==strlen(s)-1)?'\n':' ');
    return 0;
}
