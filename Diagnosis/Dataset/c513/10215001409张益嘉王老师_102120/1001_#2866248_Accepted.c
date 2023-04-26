#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char a[])
{
    int num;
    char b;
    num=strlen(a);
    for(int i=0;i<num/2;i++)
    {
        b=a[i];
        a[i]=a[num-1-i];
        a[num-1-i]=b;
    }
    a[num]=0;
}

int main()
{
    int t,i,z,j;
    scanf("%d",&t);
    //printf("t=%d\n",t);
    int* n=(int*)malloc(t*sizeof(int));
    int* r=(int*)malloc(t*sizeof(int));
    char re[100];
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&n[i],&r[i]);
        //printf("n=%d r=%d i=%d\n",n[i],r[i],i);
    }
    for(i=0;i<t;i++)
    {
        j=0;
        if(n[i]>0)
    {
        while(n[i]>0)
        {
            z=n[i]%r[i];
            if(z<10) re[j]=z+'0';
            else re[j]=z-10+'A';
            n[i]=n[i]/r[i];
            j++;
            //printf("ceshi1 re=%c j=%d\n",re[j],j);
        }
        re[j]=0;
        //printf("1=%s\n",re);
       reverse(re);
        printf("%s\n",re);
    }
    else
    {
        n[i]=-n[i];
        while(n[i]>0)
        {
            z=n[i]%r[i];
            if(z<10) re[j]=z+'0';
            else re[j]=z-10+'A';
            n[i]=n[i]/r[i];
            j++;
            //printf("ceshi1 re=%c j=%d\n",re[j],j);
        }
        re[j]=0;
        //printf("1=%s\n",re);
       reverse(re);
        printf("-%s\n",re);
    }

    }

    return 0;

}
