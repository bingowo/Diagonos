#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *pa,const void *pb)
{
    char *a=(char*)pa;
    char *b=(char*)pb;
    //if((*a==20||*a>=65)&&(*b==20||*b>=65))
    if(*a>*b)
        return 1;
    else
    {
        return -1;
    }
}

int main()
{
    int T,i,k,j,cnt,cnt0,cnt1,cnt2,c,p,cnt3;
    char s[201],ret[201],s1[201];
    int r[201],a[201];
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++)
    {
        memset(ret,'\0',sizeof(ret));
        k=0;
        cnt1=0;
        cnt2=0;
        scanf("%[^\n]",s);
        for(j=0;j<strlen(s);j++)
        {
            if(s[j]>32&&s[j]<65)
            {
                a[cnt2++]=j;
                //printf("%d %d\n",j,cnt2);
            }
            else if(isspace(s[j]))
            {
                r[k++]=j;
                //printf("%d %dtt\n",j,k);
            }
            if(j==strlen(s)-1)
                r[k++]=j;
        }
        strcpy(s1,s);
        qsort(s,strlen(s),sizeof(char),cmp);
        //printf("%s\n",s);
        for(cnt=0;s[cnt]<65;cnt++);
        //printf("%dhh\n",cnt);
        for(j=0;j<k;j++)
        {
            cnt3=0;
            if(j==0)
                p=r[j];
            else if(j==k-1)
                p=r[j]-r[j-1]+1;
            else
                p=r[j]-r[j-1]-1;
            for(cnt0=0;cnt0<p;cnt0++)
            {
                for(c=0;c<cnt2;c++)
                {
                    if(cnt1==a[c])
                    {
                        ret[cnt1++]=s1[a[c]];
                        cnt3++;
                        break;
                    }
                }
                if(c==cnt2)
                {
                    ret[cnt1++]=s[cnt+cnt0];
                }
            }
            cnt+=p-cnt3;
            //printf("%d\n",cnt);
            ret[cnt1++]=' ';
        }
        printf("case #%d:\n",i);
        printf("%s\n",ret);
    }
    return 0;
}
