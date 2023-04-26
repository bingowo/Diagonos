#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int del(char *t)
{
    char s1[101];
    char s2[101];
    strcpy(s1,t);
    int l1=strlen(s1),l2=0,l=0;
    int i;
    if (l1==0) {
        return 0;
    }
    s1[l1]='$';
    s1[l1+1]='\0';
    for(i=1;i<l1+1;i++)
    {
        if (s1[i]!=s1[i-1]){
            if(l==i-1)
                s2[l2++]=s1[i-1];
            l=i;
            }
}
    s2[l2]='\0';
    if (l1==l2)
        return 0;
    return  l1-l2+del(s2);

}
int max(int a,int b)
{
    if(a==b)return a;
    else if(a>b)return a;
    else return b;
}

void solve()
{
    char t1[101];
    scanf("%s",t1);
    char t2[101];
    int i,len=strlen(t1);
    int ans=0;
    for( i=0;i<len;i++)
    {
        strncpy(t2,t1,i);t2[i]='\0';strcat(t2, "A");strcat(t2, t1+i);
        ans=max(ans,del(t2));
        strncpy(t2,t1,i);t2[i]='\0';strcat(t2, "B");strcat(t2, t1+i);
        ans=max(ans,del(t2));
        strncpy(t2,t1,i);t2[i]='\0';strcat(t2, "C");strcat(t2, t1+i);
        ans=max(ans,del(t2));
    }

     printf("%d\n",ans);
}

int main(   )
{
    //char flag[]="YWV1Y3Rme2YzNzVmOWI3ZjczMGFjNmNjYWQ4YTVmYTA1MWY2NDJlfQ==";
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        solve();
    }
    return 0;
}


