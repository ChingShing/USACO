/*
 USACO 1.1 PROB Friday the Thirteenth
 ID:Ching_s1
 PROG:friday
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void dateTo7(const int &days_sum, int week[], const bool &leap_year)
{
    //小心这里是12，表示第十三天
    int pin=days_sum+12;//used for counting each 13th
    //1.13
    week[pin%7]++;
    //2.13
    pin+=31;
    week[pin%7]++;
    //3.13
    pin+= leap_year?29:28;
    week[pin%7]++;
    //4.13
    pin+=31;
    week[pin%7]++;
    //5.13
    pin+=30;
    week[pin%7]++;
    //6.13
    pin+=31;
    week[pin%7]++;
    //7.13
    pin+=30;
    week[pin%7]++;
    //8.13
    pin+=31;
    week[pin%7]++;
    //9.13
    pin+=31;
    week[pin%7]++;
    //10.13
    pin+=30;
    week[pin%7]++;
    //11.13
    pin+=31;
    week[pin%7]++;
    //12.13
    pin+=30;
    week[pin%7]++;
}

int main()
{
    ifstream in("friday.in");
    ofstream out("friday.out");
    
    int n;
    in >> n;
    
    int week[7]={0};
    int year=1900;
    int days_sum=0;
    bool leap_year=true;
    
    for(int i=0;i<n;++i)
    {
        //把取余号打成除号，一直找不出bug哈哈
        leap_year=((year%4==0)&&((year%100!=0)||(year%400==0)))?true:false;
        dateTo7(days_sum,week,leap_year);
        days_sum+=leap_year?366:365;
        year++;
    }
    for (int i = 0; i < 6; ++i)
    {
        out << week[(i+5)%7] << " ";
    }
    out << week[4] << endl;
    
    return 0;
}
