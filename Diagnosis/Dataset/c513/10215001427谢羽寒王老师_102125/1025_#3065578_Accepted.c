#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int cmp(const void *a,const void *b)
{
    char *p1,*p2;
    char d1,d2;
    int c1,c2,i=1;
    p1=*((char**)a);
    p2=*((char**)b);
    d1=*p1;      //首字符
    d2=*p2;
    c1=count(p1);
    c2=count(p2);
    while(d1==d2){  //如果首字符相同，下一位，以此类推
        d1=*(p1+i);
    d2=*(p2+i);
    i++;
    }

    if(c1==c2) return d1-d2 ;   //大于0交换
    else return c2-c1;

}
int count(const char *p)
{
    int len,i,j,c=0;
    len = strlen(p);
    for(i=1;i<len;i++){
            c++;
        for(j=0;j<i;j++){
            if(p[i]==p[j]){ c--;break;}

        }

    }
    return c;


}








int main()
{
    int T,n,i,j,k,count;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&n);
        char **all;
        all=(char**)malloc(n*sizeof(char*));
        int len;
        char s[21],*p;    //从数组到指针？

        for(j=0;j<n;j++){      //输入 存到数组
        scanf("%s",s);
        len=strlen(s);
        p=(char*)malloc((len+1)*sizeof(char));     //为什么不能为len？ 等于 len+1 * sizeof(char)
                                   //动态分配邮件地址储存空间
        strcpy(p,s);            //把刚刚输入的字符串复制到动态申请的空间中
        *(all+j)=p;           //赋值到大的指针数组空间中
        }

        qsort(all,n,sizeof(char*),cmp);
         printf("case #%d:\n",i);
    for(k=0;k<n;k++){                  //输出
        printf("%s\n",all[k]);

    }

   p=NULL;all=NULL;
   free(p);free(all);







    }

}