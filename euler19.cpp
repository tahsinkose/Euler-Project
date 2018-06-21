#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int Zellercongruence(int day, int month,
                     unsigned long long int year)
{
    if (month == 1)
    {
        month = 13;
        year--;
    }
    if (month == 2)
    {
        month = 14;
        year--;
    }
    int q = day;
    int m = month;
    int k = year % 100;
    unsigned long long int j = year / 100;
    unsigned long long int h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j;
    h = h % 7;
    return h;
}

int main() {
    int t;
    cin>>t;
    
    
    for(int i=0;i<t;i++){
        unsigned long long int y1,y2;
        int m1,m2,d1,d2;
        cin>>y1>>m1>>d1;
        cin>>y2>>m2>>d2;
        int total = 0;
        if(y1==y2){
            if(d1==1)
                for(int k=m1;k<=m2;k++)
                    total += Zellercongruence(1,k,y1)==1 ? 1 : 0;
            else
                for(int k=m1+1;k<=m2;k++)
                    total += Zellercongruence(1,k,y1)==1 ? 1 : 0;
        }
        else{
            if(d1==1)
                for(int k=m1;k<=12;k++)
                    total += Zellercongruence(1,k,y1)==1 ? 1 : 0;
            else
                for(int k=m1+1;k<=12;k++)
                    total += Zellercongruence(1,k,y1)==1 ? 1 : 0;
            for(unsigned long long int k=y1+1;k<y2;k++)
                for(int l=1;l<=12;l++)
                    total += Zellercongruence(1,l,k)==1 ? 1 : 0;
            for(int k=1;k<=m2;k++)
                total +=  Zellercongruence(1,k,y2)==1 ? 1 : 0;
        }
        cout<<total<<endl;
    }    
    return 0;
}
