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
        char a[81],b[81],s[81],s1[81],b1[81],a1[81];
        scanf("%s\n",a);
        scanf("%s\n",b);
        scanf("%s",s);
        int lena=strlen(a),lenb=strlen(b),lens=strlen(s);
        char *firsta=strstr(s,a);
       //firsta是a首次出现在s里的指针
       char*firstb=strstr(s,b);
       //firstb是b首次出现在s里的指针
       int t1=firsta-s,t3=firstb-s;
       
        int l1,l2,l3;
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
        for(l3=0;l3<lena;l3++)
        a1[l3]=a[lena-l3-1];
        a1[l3]='\0';
        //调换a的顺序
        char *lasta=strstr(s1,a1);
        //lasta是a1首次出现在s1里的指针
        
        int t2,t4;
        t2=lastb-s1;
        t4=lasta-s1;
        printf("case #%d:\n",i);
        int max1,max2;
        
        max1=lens-t1-t2-lena-lenb;
        max2=lens-t3-t4-lena-lenb;
        max=(max1>max2)?max1:max2;
        if(lena>=lens||lenb>=lens) max=0;
        if(firsta==NULL||lastb==NULL) max=0;
        printf("%d\n",max);
        
        
     }
     return 0;
}