#include <stdio.h>

int main()
{
	/*先把所有状态枚举出来，从简单到复杂依次为：
	1.位于双斜杠之间的行，全部不输出
	2.位于*+/之间的行，全部不输出
	3.如果与引号相关，有可能会出现引号里出现引号，但是这个时候会有\出现在单引号前面
	4.处于引号中，是最优级别，如果在双引号之内，则全部作废不输出
	统计情况：
	1.最优级别：处于双引号之内，这个时候需要两个标志：sy1,sy2遇到一个引号而且该引号不出于单引号中那么就将其中一个赋值1，出了这个引号之后都回溯为0*/
}