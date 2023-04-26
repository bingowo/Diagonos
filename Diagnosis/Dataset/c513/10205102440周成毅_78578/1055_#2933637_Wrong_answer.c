#include <stdio.h>
char s[1000001];
int main() {
    int exist[128]={0};
    int place[128]={-1};
    int len = 0,temp=0, start=0,head=0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (!exist[s[i]] || place[s[i]]<head-1) {
            temp++;
            place[s[i]] = i;
            exist[s[i]] = 1;
        }
        else {
            if(temp>len) {
                len = temp;
                start = head;
            }
            head=place[s[i]]+1;
            temp=i-place[s[i]];
        }
    }
    if(len==0)
        len=temp;
    for(int i=start;i<start+len;i++)
        printf("%c",s[i]);
    printf("\n");
    return 0;
}
