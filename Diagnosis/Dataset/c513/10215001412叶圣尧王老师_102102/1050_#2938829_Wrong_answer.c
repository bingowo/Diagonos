#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T,max;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int flag1=-1,flag2=-1;
        printf("case #%d:\n",t);
        char s1[81],s2[81],s[80];
        scanf("%s%s%s",s1,s2,s);
        int i,j,head1[80],tail1[80],head2[80],tail2[80],k=0,e=0;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]==s1[0])
            {
                k=0;j=i;
                while(s[j]==s1[k]&&k<strlen(s1)){j++;k++;}
                if(k==strlen(s1)){head1[e]=i;tail1[e]=j-1;e++;flag1=1;}
            }
        }
        e=0;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]==s2[0])
            {
                k=0;j=i;
                while(s[j]==s2[k]&&k<strlen(s2)){j++;k++;}
                if(k==strlen(s2)){head2[e]=i;tail2[e]=j-1;e++;flag2=1;}
            }
        }
        if(flag1==-1||flag2==-1)printf("0");
        else
        {max=abs(head2[e-1]-tail1[0])-1;
        max=max>abs(head1[e-1]-tail2[0]-1)? max:abs(head1[e-1]-tail2[0]-1);
        printf("%d\n",max);
        }
    }
}