/*
 * File:        Integer.h
 *
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 *
 *
 */

#ifndef INTEGER_H
#define	INTEGER_H

class Integer : public Number {
public:
    Integer(long value);
    void simplify();
    string display();
    long getValue();
    void setValue(long value);
    Integer operator+(const Integer& integer);
    Integer operator-(const Integer& integer);
    Integer operator*(const Integer& integer);
    Integer operator/(const Integer& integer);
    
private:
    long value;
};

#endif	/* INTEGER_H */

