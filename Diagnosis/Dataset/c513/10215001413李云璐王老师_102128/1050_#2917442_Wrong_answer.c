#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char a[81],b[81],s[81];
        scanf("%s\n",a);
        scanf("%s\n",b);
        scanf("%s",s);
        int lena=strlen(a),lenb=strlen(b),lens=strlen(s),firsta=0,lastb=lens-1;
        char*p=s;
        char a1[lena+1],b1[lenb+1];
        while(*p)
        {
            if(firsta<=lens-lena+1)
            strncpy(a1,p,lena);
            if(strcmp(a1,a)==0) break;
            p++;
            firsta++;
            
        }
        
        printf("%d\n",firsta);
        *p=s+lens-1;
        while(*p)
        {
            if(lastb>=lenb+1)
            strncpy(b1,p-lenb+1,lenb);
            if(strcmp(b1,b)==0) break;
            p--;
            lastb--;
        }
        printf("%d\n",lastb);
        int max;
        max=abs(lastb-firsta)-lenb-lena+2;
        if(firsta==lens-lena||lastb==lenb) max=0;
        printf("case #%d:\n",i);
        printf("%d\n",max);
     }
     return 0;
}