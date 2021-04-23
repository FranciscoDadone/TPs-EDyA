/*************************
    Trabajo Práctico 3
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

template<class T>
/**
 * Class Fraction to manage a fractional number.
 * DOUBLE || FLOAT || INT
 * @class Fraction
 */
class Fraction {
public:
    /**
     * Constructors:
     *   - Default: num = 0; den = 1;
     *   - Parameterized: Takes the numerator and denominator and checks if the denominator is 0 or not.
     *   - Copy: Copies another object to himself.
     */
    Fraction() {
        this->num = 0;
        this->den = 1;
    }
    Fraction(T num, T den) {
        this->num = num;
        this->den = (den ? den : 1);
    }
    Fraction(const Fraction &f) {
        this->num = f.num;
        this->den = f.den;
    }

    /**
     * Sets the numerator.
     * @param num
     */
    void setNum(T newNum) { this->num = newNum; }
    /**
     * Sets the denominator.
     * If it's 0, it returns the previous one.
     * @param den
     */
    void setDen(T newDen) {
        this->den = (newDen) ? newDen : this->den;
    }

    /**
     * Gets the numerator
     * @return num
     */
    T getNum() { return this->num; }
    /**
     * Gets the denominator.
     * @return den
     */
    T getDen() { return this->den; }

    /**
     * toFloat
     * @return the number in float
     */
    float toFloat() {
        return float(this->num) / float(this->den);
    }

    /**
     * Simplifies the fraction if it's possible.
     * @return bool if the operation succeeded.
     */
    bool simplify() {
        bool canItBeSimplified = false;
        for(short int i = 2; i < 6; i++){
            if(this->num % i == 0 && this->den % i == 0) {
                this->num /= i;
                this->den /= i;
                i = 1;
                canItBeSimplified = true;
            }
        }
        return canItBeSimplified;
    }
    /**
     * Converts the fraction to string.
     * @return
     */
    std::string toString() {
        return to_string(this->num) + "/" + to_string(this->den);
    }

    /**
     * Multiply by int
     * @param i
     * @return Object
     */
    Fraction operator * (const int i) {
        return { this->num * i, this->den };
    }
    /**
     * Multiply by another fraction.
     * @param f
     * @return Object
     */
    Fraction operator * (const Fraction &f) {
        return { (this->num * f.num), (this->den * f.den) };
    }
    /**
     * Minus operator.
     * @param f
     * @return Object
     */
    Fraction operator - (const Fraction &f) {
        return { (this->num) * (f.den) - (f.num) * (this->den), (this->den) * (f.den) };
    }
    /**
     * Plus operator.
     * @param f
     * @return Object
     */
    Fraction operator + (const Fraction &f) {
        return { (this->num) * (f.den) + (f.num) * (this->den), (this->den) * (f.den) };
    }
    /**
     * Divide operator.
     * @param f
     * @return Object
     */
    Fraction operator / (const Fraction &f) {
        return { (this->num) * (f.den), (this->den) * (f.num) };
    }
    /**
     * Outputs to console the fraction.
     * @param out
     * @param f
     * @return out
     */
    friend std::ostream & operator << (std::ostream &out, Fraction f) {
        return out << f.toString();
    }

private:
    T num, den;
};
