#include<stdio.h>
#include<string.h>

int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

int main()
{
    int T;
    scanf("%d",&T);
	int a[26],b[26],c[26];
	char s1[101],s2[101];
    for(int z = 0; z < T; z++)
    {
        scanf("%s %s",s1,s2);
        printf("case #%d:\n",z);
        if(strcmp(s1,"0") == 0 && strcmp(s2,"0") == 0)
            printf("0\n");
        else
        {
            int l1 = strlen(s1);
            int l2 = strlen(s2);
            s1[l1]=',',s1[++l1]=0;
            s2[l2]=',',s2[++l2]=0;
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            int t1 = 0;
            int t = 0;
            int i,j,k;
            for(i=0;s1[i];i++)
            {
                if(s1[i]==',')
                {
                    a[t1++]=t;
                    t=0;
                }
                else if(s1[i]>='0'&&s1[i]<='9')
                {
                    t=t*10+s1[i]-'0';
                }
            }
            for(i=0,j=t1-1;i<j;i++,j--)
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
            int t2 = 0;
            t = 0;
            for(i = 0; s2[i]; i++)
            {
                if(s2[i] == ',')
                {
                    b[t2++] = t;
                    t = 0;
                }
                else if(s2[i] >= '0' && s2[i] <= '9')
                {
                    t = t * 10 + s2[i] - '0';
                }
            }
            for(i = 0,j = t2 - 1; i < j; i++,j--)
            {
                t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
            memset(c,0,sizeof(c));
            i = 0;
            int carry;
            carry = 0;
            while(i < t1 || i < t2)
            {
                t = a[i] + b[i];
                t += carry;
                if(t >= prime[i])
                {

                    c[i] = t % prime[i];
                    carry = t / prime[i];
                }
                else
                {
                    c[i] = t;
                    carry = 0;
                }
                i++;
            }
            if(carry != 0)
                c[i++] = carry;
            for(int j = i - 1; j > 0; j--)
                printf("%d,",c[j]);
            printf("%d\n",c[0]);
        }

    }
    return 0;
}
