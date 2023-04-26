#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int turn(char s[])
{
    int sum,jz=0,i,j,l=strlen(s),flag=0,wa=0;
    for(i=0;i<l;i++)
    {
        for(j=i+1,flag=0;j<l;j++)
        {
            if(s[i]==s[j]) flag=1;
        }
        if(flag==0) jz+=1;
    }
    for(i=0;i<l;i++)
    {
        if(i==0) sum+=pow(jz,l-1);
        else
        {
            for(j=0,flag=0;j<i;j++)
            {
                if(s[i]==s[j])
                {
                    if(j==0){sum+=pow(jz,l-1-i);flag=1,wa+=1;break;}
                    if(j==1){sum+=0;flag=1,wa+=1;break;}
                    else {sum+=pow(jz,l-1-i)*j;flag=1,wa+=1;break;}
                }
            }
            if(flag==0&&i==1) sum+=0;
            else if(flag==0) sum+=pow(jz,l-1-i)*(i-wa);
        }

    }
    return sum;
}

int main()
{
    int N,i;
    char s[100][100];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",s[i]);
    }
    for(i=0;i<N;i++)
    {
        printf("case #%d:\n",i);
        printf("%d\n",turn(s[i]));
    }

    return 0;
}
