#include <stdio.h>
#include <string.h>
void add(char *s)
{
   int i = strlen(s)-1,t,carry,j;
   t = s[i]-'0'+1;
   carry = t/10;
   s[i] = t%10 + '0';
   while(carry!=0&&i>=0)
   {
      t = s[--i] -'0'+1;
      carry = t/10;
      s[i] = t%10 + '0';
   }
   if(carry)
   {
       int num = strlen(s);
       for(j = 1;j<=num;j++)
        s[j] = s[j-1];
       s[0] = '1';
       s[j] = '\0';
   }
}
int find(char a[])
 {
     int i,n;
     for(i = 1;i<strlen(a);i++)
     {
         if(a[i]==a[i-1]) {n = i;return n;}
     }
     return 0;
 }
int main()
{
    int T,t,m,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[101];
        scanf("%s",s);
        add(s);
        m = find(s);
        //printf("%d ",m);
        int carry;
        while(m)
        {t = s[m]-'0'+ 1;
        carry = t/10;
        while(carry!=0&&m>=0)
        {
            t= s[--m] - '0'+1;
            carry = t/10;
        }
        //printf("%d ",m);
        if(m>=0) s[m]+=1;
        for(j = m+1;j<strlen(s);j++)
        {
            if((j-m)%2==1) s[j] = '0';
            else s[j] = '1';
        }
        if(carry)
        {
         for(j = 1;j<=i+1;j++)
        s[j] = s[j-1];
        s[0] = '1';
        s[j] = '\0';
        }m = find(s);
        }
        printf("case #%d:\n%s\n",i,s);

    }
    return 0;

}
