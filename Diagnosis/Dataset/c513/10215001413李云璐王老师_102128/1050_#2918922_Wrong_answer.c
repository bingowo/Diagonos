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
        char a[81],b[81],s[81],s1[81];
        scanf("%s\n",a);
        scanf("%s\n",b);
        scanf("%s",s);
        int lena=strlen(a),lenb=strlen(b),lens=strlen(s);
        char *firsta=strstr(s,a);
        printf("%s\n",firsta);
        int l;
        for(l=0;l<lens;l++)
        s1[l]=s[lens-l-1];
        s1[l]='\0';
        char *lastb=strstr(s1,b);
        printf("%s\n",lastb);
     }
     return 0;
}