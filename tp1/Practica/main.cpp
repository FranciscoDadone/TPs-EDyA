#include <iostream>
#include <math.h>
#include"date.h"
using namespace std;
enum orden{asc,desc};
void sort(Date *dates, size_t N, orden o=asc){
    Date sav;
    int i,j,ord;
    if(o=asc){
        ord=-1;
    }
    else{
        ord=1;
    }
    for (i=0;i<N;i++){
        sav=dates[i];
        for (j=i;j<N;j++){
            if(getDifference(sav,dates[j])==ord){
                sav=dates[j];
            }
        }
        dates[i]=sav;
    }

}
int main(){
    size_t N=5;
    int i;
    Date *dates=new Date[N];
    dates[0]={1,January,1970};
    dates[1]={18,July,2001};
    dates[2]={12,May,2019};
    dates[3]={7,June,1980};
    dates[4]={26,October,1990};

    sort(dates,N);

    for (i=0;i<N;i++){
        cout<<dates[i].day<<"  "<<dates[i].month<<"  "<<dates[i].year;
        cout<<endl;
    }

    return 0;
}
