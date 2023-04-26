#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A;
    char a[1000];
    int s[1000];
    int B;
    int i=0;
    int j=0;
    scanf("%d ",&A);
    while(scanf("%c",&a[i])!=' ')i++;
    scanf(" %d",&B);
    int m,n=0,t=1;
    while(i>=0)
    {

        if(a[i]>='A'&&a[i]<'a')m=a[i]-'A'-'0'+10;
        else if(a[i]>='a')m=a[i]-'a'-'0'+10;
        else m=a[i]-'0';
        n=n+m*t;
        t=t*A;
        i--;

    }
    while(n!=0)
    {

       s[j]=n%B;
       n=n/B;
       j++;
    }
    while(j>=0)
    {
        if(a[j]>=10)printf("%c",s[j]-10+'A');
        else printf("%d",s[j]);
        j--;
    }
    return 0;
}
