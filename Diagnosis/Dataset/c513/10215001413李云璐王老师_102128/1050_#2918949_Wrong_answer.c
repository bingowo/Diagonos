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
        char a[81],b[81],s[81],s1[81],b1[81];
        scanf("%s\n",a);
        scanf("%s\n",b);
        scanf("%s",s);
        int lena=strlen(a),lenb=strlen(b),lens=strlen(s);
        char *firsta=strstr(s,a);
       //firsta是a首次出现在s里的指针
       int t=firsta-s;
       printf("%d\n",t);
        int l1,l2;
        for(l1=0;l1<lens;l1++)
        s1[l1]=s[lens-l1-1];
        s1[l1]='\0';
       //调换s的顺序
        for(l2=0;l2<lenb;l2++)
        b1[l2]=b[lenb-l2-1];
        b1[l2]='\0';
        //调换b的顺序
        char *lastb=strstr(s1,b1);
        //lastb是b1首次出现在s1里的指针
        
        
     }
     return 0;
}