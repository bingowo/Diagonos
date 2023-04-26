#include<stdio.h>

int distrib(int *min,char *in)
{
    int a[123];
    for(int j=0;j<123;j++)
        a[j]=-1;
    int mini=1,i,c=0;
    for(i=0;in[i]!=0;i++)
           {if (a[in[i]]==-1)
            {a[in[i]]=*(min+i)=(c==1)?0:mini++;
          c++;}
            else *(min+i)=a[in[i]];}
    return mini++;


}
main()
{
    int T,i,j,n=0,pow;
    char in[10][100];int min[10][100];
   scanf("%d",&T);
    for(i=0;i<T;i++)
        scanf("%s",in[i]);
    for(i=0;i<T;i++)
    {pow=distrib(min[i],in[i]);
        for(j=0;in[i][j]!=0;j++)
        n=n*pow+min[i][j];
    printf("case #%d:\n",i);
    printf("%d",n);
    }
}
