#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const char *table[12]={"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};
    long long int buf[30];
    for(int i=0;i<30;i++) buf[i]=0;
    while(1)
    {
        char s[4];
        int i,j;
        if(scanf("%s ",s)==EOF) break;
        for(i=0;i<12;i++)
        {
            if(strcmp(s,table[i])==0) j=i;
        }
        int var1,var2,var3,n;
        long long temp=0;
        char str[3];
        char str1[3],str2[3],str3[3];
        switch(j)
        {
            case 0:
                scanf("%[^,]",str);
                scanf("%c%d",&n,&n);
                var1=str[0]-'A';
                buf[var1]=n;
                break;
            case 1:
                scanf("%s",str);
                var1=str[0]-'A';
                printf("%d\n",buf[var1]);
                break;
            case 2:
                scanf("%[^,]%c%s",str1,str2,str2);
                var1=str1[0]-'A';
                var2=str2[0]-'A';
                buf[var1]=buf[var2];
                break;
            case 3:
                scanf("%[^,]%c%s",str1,str2,str2);
                var1=str1[0]-'A';
                var2=str2[0]-'A';
                var3=buf[var2];
                buf[var2]=buf[var1];
                buf[var1]=var3;
                break;
            case 4:
                if(scanf("%[^,]%c%s",str1,str2,str2))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    buf[var1]=buf[var1]+buf[var2];
                }
                else if(scanf("%[^,]%c%[^,]%c%s",str1,str2,str2,str3,str3))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    var3=str3[0]-'A';
                    buf[var1]=buf[var2]+buf[var3];
                }
                break;
            case 5:
                if(scanf("%[^,]%c%s",str1,str2,str2))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    buf[var1]=buf[var1]-buf[var2];
                }
                else if(scanf("%[^,]%c%[^,]%c%s",str1,str2,str2,str3,str3))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    var3=str3[0]-'A';
                    buf[var1]=buf[var2]-buf[var3];
                }
                break;
            case 6:
                if(scanf("%[^,]%c%s",str1,str2,str2))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    buf[var1]=buf[var1]*buf[var2];
                }
                else if(scanf("%[^,]%c%[^,]%c%s",str1,str2,str2,str3,str3))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    var3=str3[0]-'A';
                    buf[var1]=buf[var2]*buf[var3];
                }
                break;
            case 7:
                if(scanf("%[^,]%c%s",str1,str2,str2))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    buf[var1]=buf[var1]/buf[var2];
                }
                else if(scanf("%[^,]%c%[^,]%c%s",str1,str2,str2,str3,str3))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    var3=str3[0]-'A';
                    buf[var1]=buf[var2]/buf[var3];
                }
                break;
            case 8:
                if(scanf("%[^,]%c%s",str1,str2,str2))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    buf[var1]=buf[var1]%buf[var2];
                }
                else if(scanf("%[^,]%c%[^,]%c%s",str1,str2,str2,str3,str3))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    var3=str3[0]-'A';
                    buf[var1]=buf[var2]%buf[var3];
                }
                break;
            case 9:
                if(scanf("%[^,]%c%s",str1,str2,str2))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    buf[var1]=buf[var1]&buf[var2];
                }
                else if(scanf("%[^,]%c%[^,]%c%s",str1,str2,str2,str3,str3))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    var3=str3[0]-'A';
                    buf[var1]=buf[var2]&buf[var3];
                }
                break;
            case 10:
                if(scanf("%[^,]%c%s",str1,str2,str2))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    buf[var1]=buf[var1]|buf[var2];
                }
                else if(scanf("%[^,]%c%[^,]%c%s",str1,str2,str2,str3,str3))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    var3=str3[0]-'A';
                    buf[var1]=buf[var2]|buf[var3];
                }
                break;
            case 11:
                if(scanf("%[^,]%c%s",str1,str2,str2))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    buf[var1]=buf[var1]^buf[var2];
                }
                else if(scanf("%[^,]%c%[^,]%c%s",str1,str2,str2,str3,str3))
                {
                    var1=str1[0]-'A';
                    var2=str2[0]-'A';
                    var3=str3[0]-'A';
                    buf[var1]=buf[var2]^buf[var3];
                }
                break;
        }

    }
    return 0;
}
