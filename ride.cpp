/*
USACO 1.1 PROB Your Ride Is Here
ID:Ching_s1
PROG:ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void product(string &s, const char *p, int &res){
    while( (*p)!='\0' ){
        res *= *p -'A' +1;
        p++;
    }
}

int main()
{
    ifstream in("ride.in");
    ofstream out("ride.out");
    
    string s1, s2;
    in >> s1 >> s2;
    
    int l1=1,l2=1;
    const char *p1=s1.c_str(),*p2=s2.c_str();
    
    product(s1, p1, l1);
    product(s2, p2, l2);
    
    out << ( (l1%47 == l2%47 )?"GO":"STAY" ) << endl;
    
    return 0;
}
