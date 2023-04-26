#include<stdio.h>
#include<stdlib.h>
struct F
{ char c[30];
int a[30];
}stu[200];
int cmp(const void*a,const void *b)
{ int i;
    struct F*aa=(struct F*)a;
    struct F*bb=(struct F*)b;
    for(i=0;i<=29;i++)
    {if(aa->a[i]!=bb->a[i]){return(aa->a[i]-bb->a[i]);}
}
return 0;
}
int main()
{char s[26];
 while(scanf("%s",s)!=-1)
 {int i=0,m;
 for(m=0;m<=199;m++){for(int x=0;x<=29;x++){stu[m].a[x]=0;}}
 while(scanf("%s",stu[i].c)&&getchar()!='\n'){i++;}
 for(int j=0;j<=i;j++)
    { for(m=0;m<=29;m++)
        {for(int n=0;n<=25;n++){if(stu[j].c[m]==s[n]||stu[j].c[m]==s[n]+32){stu[j].a[m]=n+1;break;}}
        }
    }

qsort(stu,i+1,sizeof(stu[0]),cmp);
for(int q=0;q<=i;q++) {printf("%s ",stu[q].c);}
printf("\n");

 }
return 0;
}

