#include<stdio.h>
#include<string.h>
int main()
{
    int t,I=0;
    weight[25]={2,3,5,7,11, 13,17,19,23,29, 31,37,41,43,47, 53,59,61,67,71, 73,79,83,89,97};
    scanf("%d\n",&t);
    for(I=0;I<t;I++)
    {
        char s1[100],s2[100];
        int n1[26],n2[26];
        scanf("%s %s",s1,s2);
        int l1=strlen(s1);
        int l2=strlen(s2);
        int i,j,cnt=0;
        for(i=l1-1,cnt=0,j=1;i>=0;i--)
        {
            if(s1[i]==',') 
            {
                j=1;
                cnt++;
            }
            else
            {
                n1[cnt]+=(s1[i]-'0')*j;
                j*=10;
            }
        }
        for(i=l2-1,cnt=0,j=1;i>=0;i++)
        {
            if(s2[i]==',') 
            {
                j=1;
                cnt++;
            }
            else
            {
                n2[cnt]+=(s2[i]-'0')*j;
                j*=10;
            }
        }
        for(i=0;i<25;i++)
        {
            n1[i]+=n2[i];
            if(n1[i]>=weight[i])
            {
                n1[i+1]+=n1[i]/weight[i];
                n1[i]%=weight[i];
            }
        }
        printf("case #%d:\n",I);
        for(i=25;i>0;i--) printf("%d",n1[i]);
        printf("%d\n",n1[i]);
    }
    return 0;
}