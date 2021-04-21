#include <fstream>
#include <sstream>
#include <map>

namespace ariel {
    class NumberWithUnits {
        private:
            double num;
            std::string unit;

        public:
            static std::map<std::string, std::map<std::string, double> > units;

            NumberWithUnits() {}
            NumberWithUnits(double i, std::string s): num(i), unit(s) {}
            ~ NumberWithUnits() {}
            

            static void read_units(std::ifstream &units);
            

            // unary operators
            const NumberWithUnits operator -() const {
                return NumberWithUnits(-num, unit);
            }
            const NumberWithUnits operator +() const {
                return *this ;  // NumberWithUnits(num, unit);
            }


            // binary operators
            const NumberWithUnits operator -(const NumberWithUnits& other) const;
            const NumberWithUnits operator +(const NumberWithUnits& other) const;

            NumberWithUnits& operator -=(const NumberWithUnits& other);
            NumberWithUnits& operator +=(const NumberWithUnits& other);


            // prefix increment
            NumberWithUnits& operator ++(){
                num++;
                return *this;
            }
            // posfic increment
            const NumberWithUnits operator ++(int dummy_flag){
                NumberWithUnits copy = *this;
                num++;
                return copy;
            }
            // prefix decrement
            NumberWithUnits& operator --(){
                num--;
                return *this;
            }
            // posfic decrement
            const NumberWithUnits operator --(int dummy_flag){
                NumberWithUnits copy = *this;
                num--;
                return copy;
            }

            const NumberWithUnits operator *(double d){
                num *= d;
                return *this;
            }
            friend const NumberWithUnits operator *(double d, const NumberWithUnits& n){
                return NumberWithUnits(n.num*d, n.unit);
            }


            // friend global binary operators
           friend bool operator ==(const NumberWithUnits& n1, const NumberWithUnits& n2);
           friend bool operator !=(const NumberWithUnits& n1, const NumberWithUnits& n2);
           friend bool operator >=(const NumberWithUnits& n1, const NumberWithUnits& n2);
           friend bool operator <=(const NumberWithUnits& n1, const NumberWithUnits& n2);
           friend bool operator <(const NumberWithUnits& n1, const NumberWithUnits& n2);
           friend bool operator >(const NumberWithUnits& n1, const NumberWithUnits& n2);


            // friend global IO operators
            friend std::ostream& operator <<(std::ostream& os, const NumberWithUnits& n){
                return os << n.num << "[" << n.unit << "]";
            }
            friend std::istream& operator >>(std::istream& is, const NumberWithUnits& n);


    };
};