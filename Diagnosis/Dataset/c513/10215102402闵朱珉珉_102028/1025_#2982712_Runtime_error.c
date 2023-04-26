#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char **a1=(char **)a,**b1=(char **)b;
    int suma=0,sumb=0;
    for (char i='A';i<='Z';i++)
    {
        while (**a1)
        {
            if (**a1==i)
            {
                suma++;
                break;
            }
            (a1)++;
        }
        while (**b1)
        {
            if (**b1==i)
            {
                sumb++;
                break;
            }
            (b1)++;
        }
    }
    if (suma!=sumb) return sumb-suma;
    else return strcmp(*a1,*b1);

}
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        char s[101][21];
        for (int j=0;j<n;j++)
        {
            scanf("%s",s[j]);
        }//in
        qsort(s,n,sizeof(s[0]),cmp);//sort
        printf ("case #%d:\n",i);
        for (int j=0;j<n;j++)
            scanf("%s\n",s[j]);
    }
    return 0;
}
