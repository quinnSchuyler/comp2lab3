#ifndef Q10P6_H
#define Q10P6_H
 
#include <cstdint>
class Q10p6{
public:
    // its to the right of the point
    static const int Q = 6;
    // 2^Q, scale factor
    static const int SCALE = (1 << Q);

    //constructors
    Q10p6();
    Q10p6(int value);
    Q10p6(float value);
    Q10p6(double value);

    //conversions
    int toInt() const;
    float toFloat() const;
    double toDouble() const;
    int16_t toRaw() const;
    
    //debugging utility to take an exact value without conversion
    static Q10p6 fromRaw(int16_t rawValue);

    //operators
    // when doing an operation it returns as the Q10p6 type
    // reference right hand side (rhs)
    // keep constant don't touch original
    Q10p6 operator+(const Q10p6& rhs) const;
    Q10p6 operator-(const Q10p6& rhs) const;
    Q10p6 operator*(const Q10p6& rhs) const;
    Q10p6 operator/(const Q10p6& rhs) const;
    bool  operator==(const Q10p6& rhs) const;
 



private:
    int16_t value; // what the actual data looks like 
};

 
#endif // Q10P6_H
