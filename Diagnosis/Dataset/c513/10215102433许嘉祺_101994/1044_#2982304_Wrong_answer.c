#include<stdio.h>
#include<string.h>


int main()
{
    char s[100001];
    scanf("%s",s);
    int find=0;
    char* point=strstr(s,"0x");
    while (point!=NULL){
        char*point1=strstr(point+1,"0x");
        if (point1==NULL) point1=strlen(point)+point;
        point=point+2;
        if (s[point-s]==0) break;
        unsigned int ans=0;
        while (s[point-s]=='0'&&point<point1) point++;
        for (;point<=point1&&((s[point-s]>='0'&&s[point-s]<='9')||(s[point-s]<='f'&&s[point-s]>='a'));point++){
            if (find==0) find++;
            ans=ans*16;
            if (s[point-s]>='a'&&s[point-s]<='f') ans=ans+s[point-s]-'a'+10;
            else ans=ans+s[point-s]-'0';
         }

        printf("%u\n",ans);
        point=strstr(point,"0x");
    }
    if (find==0) printf("-1\n");
    return 0;
}