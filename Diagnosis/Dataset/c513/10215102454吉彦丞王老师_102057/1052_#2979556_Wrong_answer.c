#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
}
int find(char a[],char s[])
{
    int l1=strlen(a);
    int l2=strlen(s);
    int b[l1];
    for(int i=0;i<l1;i++)
    {
        b[i]=0;
    }
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            if(a[i]==s[j])
            {
                b[i]++;
            }
        }
    }
    qsort(b,l1,sizeof(int),cmp);
    return b[0];
}
int main()
{
    int number;
    scanf("%d",&number);
    static char* n[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
    for(int i=0;i<number;i++)
    {
        char s[20];
        scanf("%s",&s);
        int l=strlen(s);
        int a[l];
        for(int j=0;j<l;j++)
        {
        	a[j]=-1;
		}
        int m=0;
        for(int j=0;j<10;j++)
        {
            if(find(n[j],s)>0)
            {
                for(int k=m;k<m+find(n[j],s);k++)
                {
                    a[k]=j;
                }
                m=m+find(n[j],s);
            }
        }
        qsort(a,l,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<l;j++)
        {
            if(a[j]!=-1)
            {
                printf("%d",a[j]);
            }
            else
            {
            	continue;
			}
        }
        printf("\n");
    }
    return 0;
}