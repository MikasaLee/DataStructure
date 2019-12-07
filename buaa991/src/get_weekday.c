/*************************************************************************
	> File Name: get_weekday.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 07 Dec 2019 09:00:12 PM CST
 ************************************************************************/

/**
 * 请编写一C语言函数get_weekday,该函数用于计算某一天是星期几。函数接收三个整形参数，分别表示年(year) 月(month)与日(day);并返回一个整数表示星期几，用0，1-6分别表示星期日，星期1到星期6
 * 说明：已知公元元年(即1年)1月1日为星期一。为了简化问题，只考虑公元后的日期，即年大于等于1
 */
#include "stdio.h"
#include "stdlib.h"

int main(int argc,char **argv){
	int run_y[]={31,29,31,30,31,30,31,31,30,31,30,31},
		ping_y[]={31,28,31,30,31,30,31,31,30,31,30,31};

	int year,month,day,*isyear,i,days;
	printf("请输入年份：");
	scanf("%d",&year);
	printf("请输入月份：");
	scanf("%d",&month);
	printf("请输入日期：");
	scanf("%d",&day);
	
	if(year < 1){
		printf("年份错误！");
		exit(1);
	}
	if(month < 1 || month > 12){
		printf("月份错误！");
		exit(1);
	}
	if(((year%4 == 0) && (year % 100) != 0)
			|| (year % 400 == 0))
		isyear = run_y;
	else isyear = ping_y;
	if(day< 1 || day > isyear[month-1]){
		printf("年份错误！");
		exit(1);
	}

	//得到总天数
	for(i = 1,days = 0;i<year;i++){	//前year-1年
		if(((i%4 == 0) && (i % 100) != 0)
				|| (i % 400 == 0))
			days+=366;
		else days+=365;
	}
	//第year年,加月份
	for(i = 0;i < month-1;i++){
		days += isyear[i];
	}
	//加日期
	days += day;
	printf("%d年%d月%d日是星期%d\n",year,month,day,days%7);


	return 0;
}
