#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(char *a,char *b)
{
    if(strlen(a)>strlen(b)) return 1;
    else if(strlen(a)<strlen(b)) return -1;
    else {
        return strcmp(a,b);
    }
}
int cmp(const void *a,const void *b)
{
    char *A = (char *)a,*B = (char *)b;
    if(A[0]=='-'&&B[0]=='-')
    {
        return -compare(A+1,B+1);
    }
    else if(A[0]=='-')
        return -1;
    else if(B[0]=='-')
        return 1;
    else return compare(A,B);
}
void sub(char *a,char *b)
{
    int i,len = strlen(a),carry = 0,t,j;
    for(i = len-1,j = strlen(b)-1;j>=0;i--,j--)
    {
        t = a[i]-carry-b[j];
        carry = 0;
        if(t<0) {carry = 1;a[i] = 10+t+'0';}
        else a[i] = t+'0';
    }
    while(carry!=0&&i>=0)
    {
        t = a[i]-'0'-carry;
        carry = 0;
        if(t<0) {carry = 1;a[i] = 10+t+'0';}
        else a[i] = t;
    }

}
void add(char *a,char *b)
{
    int i,len = strlen(a),carry = 0,t,j;
    for(i = len-1,j = strlen(b)-1;j>=0;i--,j--)
    {
        t = a[i]-'0'+b[j]-'0'+carry;
        a[i] = t%10+'0';
        carry = t/10;
    }
    while(carry!=0&&i>=0)
    {
        t = a[i--]-'0'+carry;
        a[i] = t%10+'0';
        carry = t/10;
    }
    if(carry)
    {
        for(i = 0;i<strlen(a);i++)
            a[i+1] = a[i];
        a[0] = '1';
        a[i+1] = '\0';
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    char s[50][121];
    for(i = 0;i<n;i++)
        scanf("%s",s[i]);
    qsort(s,n,121,cmp);
    if(s[0][0]=='-'&&s[n-1][0]=='-')
    {sub(s[0]+1,s[n-1]+1);
        printf("%s",s[0]+1);}
    else if(s[0][0]=='-')
    {
        add(s[n-1],s[0]+1);
        printf("%s",s[n-1]);
    }
    else
    {
        sub(s[n-1],s[0]);
        printf("%s",s[n-1]);
    }
    return 0;
}
