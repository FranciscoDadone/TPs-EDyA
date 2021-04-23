using namespace std;

/**
 * Class Hour
 * @brief contains an hour value (hh:mm:ss)
 */
class Hour {
public:
    /**
     * Constructors
     * Default: hora = minuto = segundo = 0
     * Parameterized: hora < 24 && >= 0, minuto < 60 && >= 0, segundo < 60 && >= 0
     * @param hora
     * @param minuto
     * @param segundo
     */
    Hour(short int hora = 0, short int minuto = 0, short int segundo = 0) {
        this->hora = (hora < 24 && hora >= 0 ? hora : 0);
        this->minuto = (minuto < 60 && minuto >= 0 ? minuto : 0);
        this->segundo = (segundo < 60 && segundo >= 0 ? segundo : 0);
    }

    /**
     * To set the hour.
     * If the hour is invalid, it keeps the previous.
     * @param hora
     */
    void setHora(short int hora) {
        this->hora = (hora < 24 && hora >= 0) ? hora : this->hora;
    }

    /**
     * To set the minutes.
     * If the hour is invalid, it keeps the previous.
     * @param minuto
     */
    void setMinuto(short int minuto) {
        this->minuto = (minuto < 60 && minuto >= 0) ? minuto : this->minuto;
    }

    /**
     * To set the seconds.
     * If the hour is invalid, it keeps the previous.
     * @param segundo
     */
    void setSegundo(short int segundo) {
        this->segundo = (segundo < 60 && segundo >= 0) ? segundo : this->segundo;
    }

    /**
     * Gets the hour.
     * @return hora
     */
    short int getHora() { return this->hora; }
    /**
     * Gets the minutes.
     * @return minuto
     */
    short int getMinuto() { return this->minuto; }
    /**
     * Gets the seconds.
     * @return segudos
     */
    short int getSegundo() { return this->segundo; }
    /**
     * Plus operator
     * @param h
     * @return object Hour with the sum.
     */
    Hour operator+(const Hour &h) {
        Hour ret;
        int sav; // sum of seconds
        sav = (this->hora) * 3600 + (this->minuto) * 60 + this->segundo + h.hora * 3600 + h.minuto * 60 + h.segundo;
        ret.hora = sav / 3600;
        sav -= 3600 * ret.hora;
        ret.minuto = sav / 60;
        sav -= 60 * ret.minuto;
        ret.segundo = sav;
        ret.hora %= 24;
        return ret;
    }
    /**
     * Prints to console the hour.
     * @param out
     * @param c
     * @return out
     */
    friend ostream &operator << (ostream &out, const Hour &c) {
        return out << c.hora << ":" << c.minuto << ":" << c.segundo;
    }
    /**
     * Minus operator
     * @param h
     * @return bool
     */
    bool operator < (const Hour &h) {
        return ((this->hora) * 3600 + (this->minuto) * 60 + this->segundo) < (h.hora * 3600 + h.minuto * 60 + h.segundo);
    }
    /**
     * Max operator
     * @param h
     * @return bool
     */
    bool operator > (Hour h) {
        return !(*this < h);
    }
    /**
     * Equals operator.
     * @param h
     * @return bool
     */
    bool operator == (const Hour &h) {
        return ((this->hora) * 3600 + (this->minuto) * 60 + this->segundo) == (h.hora * 3600 + h.minuto * 60 + h.segundo);
    }
    /**
     * Not equals operator
     * @param h
     * @return bool
     */
    bool operator != (const Hour &h) {
        return !(*this == h);
    }
    /**
     * Minus equal operator.
     * @param h
     * @return bool
     */
    bool operator <= (const Hour &h) {
        return (*this < h) || (*this == h);
    }
    /**
     * Minus equal operator.
     * @param h
     * @return bool
     */
    bool operator >= (const Hour &h) {
        return (*this > h) || (*this == h);
    }

private:
    short int hora, minuto, segundo;
};



