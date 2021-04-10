enum Month{
        January=1,February,March,April,
        May,June,July,August,September,
        October,November,December
    };
struct Date{
    unsigned short int day;
    enum Month month;
    unsigned int year;
};
Month next(Month m){
    switch(m){
    case 1:
        m=February;
    break;
    case 2:
        m=March;
    break;
    case 3:
        m=April;
    break;
    case 4:
        m=May;
    break;
    case 5:
        m=June;
    break;
    case 6:
        m=July;
    break;
    case 7:
        m=August;
    break;
    case 8:
        m=September;
    break;
    case 9:
        m=October;
    break;
    case 10:
        m=November;
    break;
    case 11:
        m=December;
    break;
    case 12:
        m=January;
    break;
    }
    return m;
}
Month previus(Month m){
    switch(m){
    case 1:
        m=December;
    break;
    case 2:
        m=January;
    break;
    case 3:
        m=February;
    break;
    case 4:
        m=March;
    break;
    case 5:
        m=April;
    break;
    case 6:
        m=May;
    break;
    case 7:
        m=June;
    break;
    case 8:
        m=July;
    break;
    case 9:
        m=August;
    break;
    case 10:
        m=September;
    break;
    case 11:
        m=October;
    break;
    case 12:
        m=November;
    break;
    }
    return m;
}
unsigned short to_int(Month m){
    int x;
    x=m;
    return x;
}
char* to_str(Month m){
    char* str;
    switch(m){
    case 1:
        str="January";
    break;
    case 2:
        str="February";
    break;
    case 3:
        str="March";
    break;
    case 4:
        str="April";
    break;
    case 5:
        str="May";
    break;
    case 6:
        str="June";
    break;
    case 7:
        str="July";
    break;
    case 8:
        str="August";
    break;
    case 9:
        str="September";
    break;
    case 10:
        str="October";
    break;
    case 11:
        str="November";
    break;
    case 12:
        str="December";
    break;
        default:
            str=NULL;
    }

    return str;
}
Month to_month(unsigned short m){
    Month x;
    switch(m){
    case 1:
        x=January;
    break;
    case 2:
        x=February;
    break;
    case 3:
        x=March;
    break;
    case 4:
        x=April;
    break;
    case 5:
        x=May;
    break;
    case 6:
        x=June;
    break;
    case 7:
        x=July;
    break;
    case 8:
        x=August;
    break;
    case 9:
        x=September;
    break;
    case 10:
        x=October;
    break;
    case 11:
        x=November;
    break;
    case 12:
        x=December;
    break;

    }
    return x;
}
char *strcat (char *dest, const char *src){
    const char *p;
    char *q;

    for (q = dest; *q != '\0'; q++);

    for(p = src; *p != '\0'; p++, q++){
       *q = *p;
    }
    *q = '\0';

    return dest;
  }
char* int_to_str(int x){
    int c=0,bit=0,cop=x,i,j=1;
    char sav[2];
    char* ret;
    while (bit==0){
        cop=cop/10;
        c++;
        if(cop==0){
            bit=1;
        }
    }
    ret=(char*)malloc(c*sizeof(char));
    *ret=0;
    bit=pow(10,c-1);

    for(i=0;i<c;i++){
        cop=(x/(bit/j))%10;
        j=j*10;
        sav[0]=cop+48;
        sav[1]='\0';
        ret=strcat(ret,sav);
        }
        return ret;
    }
char *to_str(Date d){
    char *day,*month,*year,*rta;
    day=int_to_str(d.day);
    month=int_to_str(d.month);
    year=int_to_str(d.year);
    rta=strcat(day,"/");
    rta=strcat(rta,month);
    rta=strcat(rta,"/");
    rta=strcat(rta,year);


    return rta;
}
Date to_date(char *str){
    Date ret;
    short int c=0;
    int day=0,month=0,year=0;
    char *sav;
    for(sav=str;*sav!='\0';sav++){
        if(*sav!='/'){
            switch(c){
                case(0):
                    day=day*10;
                    day=day+(*sav-48);
                break;
                case(1):
                    month=month*10;
                    month=month+(*sav-48);
                break;
                case(2):
                    year=year*10;
                    year=year+(*sav-48);
                break;
            }
        }
        else{
            c++;
        }
    }
    ret.day=day;
    ret.month=Month(month);
    ret.year=year;
    return ret;
}
bool LeapYear(Date d){
    int a,b,c,y;
    bool r;
    y=d.year;
    a=y%4;
    b=y%100;
    c=y%400;
    if (a==0 and (b!=0 or c==0)){
        r=true;
    }
    else{
        r=false;
    }
    return r;
}
bool isValidDate(Date d){
    bool ret,leap;
    int i;
    switch(d.month){
        case(1):
            if (d.day>31){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(2):
            leap=LeapYear(d);
            if(leap==true){
                i=29;
            }
            else{
                i=28;
            }
            if (d.day>i){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(3):
            if (d.day>31){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(4):
            if (d.day>30){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(5):
            if (d.day>31){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(6):
            if (d.day>30){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(7):
            if (d.day>31){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(8):
            if (d.day>31){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(9):
            if (d.day>30){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(10):
            if (d.day>31){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(11):
            if (d.day>30){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
        case(12):
            if (d.day>31){
                ret=false;
            }
            else{
                ret=true;
            }
        break;
    }
    return ret;
}
unsigned int dayOfYear(Date d){
    int tot,i;
    int vect[]={31,28,31,30,31,30,31,31,30,31,30,31};;
    bool r;
    tot=0;
    r=LeapYear(d);
    if(r==true){
        vect[1]=29;
    }
    for (i=0;i<d.month-1;i++){
        tot=tot+vect[i];
    }
    tot=tot+d.day;
    return tot;
}
int getDifference(Date dt1,Date dt2){
    short int dif;
    int sav1,sav2;
        sav1= 380*dt1.year+31*dt1.month+dt1.day;
        sav2= 380*dt2.year+31*dt2.month+dt2.day;
        if(sav1>sav2){
            dif=-1;
        }
        else{
            dif=1;
        }
    return dif;
}


