#include "Q10p6.h"
#include <iostream>

// constructors
Q10p6::Q10p6() {
    value = 0;
}

//takes the int input, scales it and casts it to 16 as is needed for a Qval
Q10p6::Q10p6(int inputVal) {
    value = static_cast<int16_t>(inputVal * SCALE);
}

// casts scale to match inputval, then casts to int16_t as needed
Q10p6::Q10p6(float inputVal) {
    value = static_cast<int16_t>(inputVal * static_cast<float>(SCALE));
}

//same as float
Q10p6::Q10p6(double inputVal) {
    value = static_cast<int16_t>(inputVal * static_cast<double>(SCALE));
}

//put value straight in without converting or touching it
// intended for debugging
Q10p6 Q10p6::fromRaw(int16_t rawValue) {
    Q10p6 result;
    result.value = rawValue; 
    return result;
}

// conversions
int Q10p6::toInt() const {
    int rawAsInt = static_cast<int>(value);
    int finalInt = rawAsInt / SCALE; // division removes the scaling factor
    return finalInt;
}

float Q10p6::toFloat() const {
    float rawAsFloat = static_cast<float>(value);
    float scaleFloat = static_cast<float>(SCALE);
    float finalFloat = rawAsFloat / scaleFloat;
    return finalFloat;
}

double Q10p6::toDouble() const {
    double rawAsDouble = static_cast<double>(value);
    double scaleDouble = static_cast<double>(SCALE);
    double finalDouble = rawAsDouble / scaleDouble;
    return finalDouble;
}

int16_t Q10p6::toRaw() const{
    double rawAsDouble = static_cast<double>(value);
    return rawAsDouble;
}

//operators
Q10p6 Q10p6::operator+(const Q10p6& rhs) const {
    // make 32-bit so adding big numbers won't overflow 16 bits
    int32_t leftVal = static_cast<int32_t>(value);
    int32_t rightVal = static_cast<int32_t>(rhs.value);
    
    // add raw values together
    int32_t rawSum = leftVal + rightVal;
    
    //shrink back to 16 bits
    int16_t truncatedSum = static_cast<int16_t>(rawSum);
    return Q10p6::fromRaw(truncatedSum);
}

Q10p6 Q10p6::operator-(const Q10p6& rhs) const {
    int32_t leftVal = static_cast<int32_t>(value);
    int32_t rightVal = static_cast<int32_t>(rhs.value);
    
    int32_t rawDiff = leftVal - rightVal;
    
    int16_t truncatedDiff = static_cast<int16_t>(rawDiff);
    return Q10p6::fromRaw(truncatedDiff);
}

Q10p6 Q10p6::operator*(const Q10p6& rhs) const {
    int32_t leftVal = static_cast<int32_t>(value);
    int32_t rightVal = static_cast<int32_t>(rhs.value);
    
    //multiply
    int32_t rawProduct = leftVal * rightVal;
    
    // shift right to remove the extra scale 
    int32_t adjustedProduct = rawProduct >> Q;
    
    int16_t truncatedProduct = static_cast<int16_t>(adjustedProduct);
    return Q10p6::fromRaw(truncatedProduct);
}

Q10p6 Q10p6::operator/(const Q10p6& rhs) const {
    int32_t leftVal = static_cast<int32_t>(value);
    int32_t rightVal = static_cast<int32_t>(rhs.value);
    
    // shift left
    int32_t scaledNumerator = leftVal << Q;
    
    //divide
    int32_t rawDivision = scaledNumerator / rightVal;
    
    int16_t truncatedDivision = static_cast<int16_t>(rawDivision);
    return Q10p6::fromRaw(truncatedDivision);
}

bool Q10p6::operator==(const Q10p6& rhs) const {
    //same format so just fine to compare as is
    bool areEqual = (value == rhs.value);
    return areEqual;
}