#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Readmunber(char s[],int a[])
{
    int m;
    m=strlen(s);
    for(int i=0;i>=0;i++)
    {

        a[26-i]=s[i];
    }
}
void Add (int a[26],int b[26],int c[26])
{
    int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51,53,57,59,61,67,71,73,79,83,87};
    int carry=0;
    int k;
    for( k=26;k>=0;k--)
       {    while(a[k]||b[k])
            {
                int left;
                left=(a[k]+b[k]+carry)%(prime[26-k]);
                carry =(a[k]+b[k]+carry)/(prime[26-k]);
                c[k]=left;


            }
       }
    a[k]+=carry;
}
int * output(int a[])
{

    int i,m;
    for(i=0;i<=26;i++)
    {
        if(a[i]>0){m=i;break;}
    }
    for(m=i;m<=26;i++)
        printf("%d",a[m]);
        if(m!=26){printf(",");}

}
int main()
{
    int n;scanf("%d",n);
    for (int i=0;i<n;i++)
    {

        int a[26];int b[26];int c[26];
        char s[100];
        scanf("%s",s);
        Readmunber(s,a);
        Readmunber(s,b);
        Add(a,b,c);
        printf("case#%d:",i);
        output(c);

    }
    return 0;
}
