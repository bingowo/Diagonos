#include<stdio.h>
#include<stdlib.h>
char *month[] = 
{
    "pop","no","zip", "zotz", "tzec", "xul",
    "yoxkin", "mol", "chen", "yax", "zac", 
    "ceh", "mac", "kankin", "muan", "pax", 
    "koyab", "cumhu","uayet"
};
int cmp(const void* A, const void* B)
{
    char* a = (char*) A;
    char* b = (char*) B;
    int l1=0;
    int l2=0;
    long long int aa=abs(*a);
    long long int bb=abs(*b);
    if(*a==0){
          l1=0;
    }
    else{
        while(aa){
          aa=aa/10;
          l1++;
        }
    }
    if(*b==0){
          l1=0;
    }
    else{
        while(bb){
          bb=bb/10;
          l2++;
        }
    }
    if(l1==l2)
    {
        if(*a>*b)
            return 1;//a所指的元素排在b所指元素的右边
        else
            return -1;//左边
    }
    else
        return l2-l1;//按1的数目来排序

}
int main()
{
    int t;//问题数
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;//比较的年份
        scanf("%d",&n);
        char s[20];
        int j=0;
        for(int k=0;k<n;k++){
            while(scanf("%c",&s)==1){
                j++;
        }
        qsort(s,j,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s",s);
        }
        
    }
    return 0;
}