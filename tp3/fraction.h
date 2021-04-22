using namespace std;
template<class T>
class Fraction{
    public:
    Fraction(){
       this->num=0;
       this->den=1;
    }
    Fraction(T num,T den){
        this->num=num;
        this->den=(den==0?1:den);
    }
    Fraction(const Fraction &f){
        this->num=f.num;
        this->den=f.den;
    }
    //en caso de que el nuevo valor no sea valido se mantiene el viejo
    void setnum(T num){this->num=num;}
    void setden(T den){
        if(den!=0){
            this->den=den;
        }
    }
    T getnum(){return this->num;}
    T getden(){return this->den;}
    float toFloat(){
        float ret;
        ret=float(this->num)/float(this->den);
        return ret;
    }
    bool simplify(){//se pueden usar el for o 3 ifs separados---------------------------------------
        short int i;
        for(i=2;i<6;i++){
            if (this->num%i==0 && this->den%i==0){
                return true;
            }
        }
        return false;
    }
    string toString(){
        string ret="";
        ret+=to_string(this->num);
        ret+='/';
        ret+=to_string(this->den);
        return ret;
    }
    Fraction operator *(const int i){
        Fraction ret;
        ret.num=this->num*i;
        ret.den=this->den;
        return ret;
    }
    Fraction operator *(const Fraction &f){
        Fraction ret;
        ret.num=this->num*f.num;
        ret.den=this->den*f.den;
        return ret;
    }
    Fraction operator -(const Fraction &f){
        Fraction ret;
        ret.den=(this->den)*(f.den);
        ret.num=(this->num)*(f.den)-(f.num)*(this->den);
        return ret;
    }
    Fraction operator +(const Fraction &f){
        Fraction ret;
        ret.den=(this->den)*(f.den);
        ret.num=(this->num)*(f.den)+(f.num)*(this->den);
        return ret;
    }
    Fraction operator /(const Fraction &f){
        Fraction ret;
        ret.num=(this->num)*(f.den);
        ret.den=(this->den)*(f.num);
        return ret;
    }
    friend ostream& operator<<(ostream &out,const Fraction &f){
    return out<<f.num<<"/"<<f.den;
    }

    private:
        T num,den;
};
