#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    return (int)a-(int)b;
}
void zuhe(char alp[],char out[],int lena,int m1,int m2)
{
    int i;
    for(i=m1;i<lena;i++)
    {
        out[m2]=alp[i];
        out[m2+1]='\0';
        printf("%s\n",out);
        zuhe(alp,out,lena,i+1,m2+1);
    }
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char s[17],alp[17]={0};
        gets(s);
        int i,j,j2,flag,lens=strlen(s);
        for(i=0,j=0;i<lens;i++)
        {
            flag=1;
            for(j2=0;j2<j;j2++)
            {
                if(s[i]==alp[j2])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                alp[j]=s[i];
                j++;
            }
        }
        int lena=strlen(alp);
        qsort(alp,lena,sizeof(alp[0]),cmp);
        char out[17];
        zuhe(alp,out,lena,0,0);
    }
    return 0;
}
