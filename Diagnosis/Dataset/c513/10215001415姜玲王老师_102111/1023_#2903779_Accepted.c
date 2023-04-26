#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int number(char*a)
{int i,t=0,num=0;
    for(i=0;i<strlen(a);i++)
    {if(a[i]>='0'&&a[i]<='9'){t++;num=num*10+a[i]-'0';}
    }
    if(t) return num;
    else return -1;
}
int strnumcmp(const void *a,const void *b)
{int num1,num2;
    char*s1=(char*)a;
    char*s2=(char*)b;
    num1=number(s1);
    num2=number(s2);
    if(num1==num2) return strcmp(s1,s2);
    else{if(num1>num2)return 1;
    else return -1;}

}
int main()
{char a[100][31];
int i=0,j;
while(scanf("%s",a[i])!=EOF) i++;
qsort(a,i,sizeof(a[0]),strnumcmp);
for(j=0;j<i-1;j++)
    printf("%s ",a[j]);
printf("%s\n",a[j]);
}
