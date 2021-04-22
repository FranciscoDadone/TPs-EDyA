using namespace std;
class Hour{
    public:
        Hour(){
            this->hora=0;
            this->minuto=0;
            this->segundo=0;
        }
        Hour(short int hora,short int minuto,short int segundo){
            this->hora=(hora<24 && hora>=0?hora:0);
            this->minuto=(minuto<60 && minuto>=0?minuto:0);
            this->segundo=(segundo<60 && segundo>=0?segundo:0);
        }
        //En caso de que el nuevo valor no sea valido, se mantien viejo
        void sethora(short int hora){
            if(hora<24 && hora>=0){
                this->hora=hora;
            }
        }
        void setminuto(short int minuto){
            if(minuto<60 && minuto>=0){
                this->minuto=minuto;
            }
        }
        void setsegundo(short int segundo){
            if(segundo<60 && segundo>=0){
                this->segundo=segundo;
            }
        };
        short int gethora(){return this->hora;}
        short int getminuto(){return this->minuto;}
        short int getsegundo(){return this->segundo;}
        //Forma 1
        /*Hour operator +(const Hour &h){
            Hour ret;
            ret.segundo=this->segundo+h.segundo;
            if(ret.segundo>=60){
                ret.segundo-=60;
                ret.minuto=this->minuto+h.minuto+1;
            }
            else{
               ret.minuto=this->minuto+h.minuto;
            }
            if(ret.minuto>=60){
                ret.minuto-=60;
                ret.hora=this->hora+h.hora+1;
            }
            else{
                ret.hora=this->hora+h.hora;
            }
            if(ret.hora>=24){
                ret.hora-=24;
            }
            return ret;
        }*/
        //Forma 2
        Hour operator +(const Hour &h){
            Hour ret;
            int sav;
            sav=(this->hora)*3600+(this->minuto)*60+this->segundo+h.hora*3600+h.minuto*60+h.segundo;
            ret.hora=sav/3600;
            sav=sav-(3600*ret.hora);
            ret.minuto=sav/60;
            sav=sav-(60*ret.minuto);
            ret.segundo=sav;
            return ret;
        }
        friend ostream& operator<<(ostream& out, const Hour &c){
            return out<<c.hora<<":"<<c.minuto<<":"<<c.segundo;
        }
        bool operator <(const Hour &h){
            int sav1,sav2;
            sav1=(this->hora)*3600+(this->minuto)*60+this->segundo;
            sav2=h.hora*3600+h.minuto*60+h.segundo;
            if (sav1<sav2){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator >(const Hour &h){
            int sav1,sav2;
            sav1=(this->hora)*3600+(this->minuto)*60+this->segundo;
            sav2=h.hora*3600+h.minuto*60+h.segundo;
            if (sav1>sav2){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator <=(const Hour &h){
            int sav1,sav2;
            sav1=(this->hora)*3600+(this->minuto)*60+this->segundo;
            sav2=h.hora*3600+h.minuto*60+h.segundo;
            if (sav1<=sav2){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator >=(const Hour &h){
            int sav1,sav2;
            sav1=(this->hora)*3600+(this->minuto)*60+this->segundo;
            sav2=h.hora*3600+h.minuto*60+h.segundo;
            if (sav1>=sav2){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator ==(const Hour &h){
            int sav1,sav2;
            sav1=(this->hora)*3600+(this->minuto)*60+this->segundo;
            sav2=h.hora*3600+h.minuto*60+h.segundo;
            if (sav1==sav2){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator !=(const Hour &h){
            int sav1,sav2;
            sav1=(this->hora)*3600+(this->minuto)*60+this->segundo;
            sav2=h.hora*3600+h.minuto*60+h.segundo;
            if (sav1!=sav2){
                return true;
            }
            else{
                return false;
            }
        }
    private:
        short int hora,minuto,segundo;
};



