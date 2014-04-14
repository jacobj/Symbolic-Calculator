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

#include "Number.h"
#include "RationalNumber.h"

using namespace std;

class Integer : public Number {
private:
    long value;

public:
    Integer(long);
    Integer(string);
    Integer();
    
    long getValue();
    void setValue(long);
    void display();
    double toDouble();
    string toString();

    // Implemented to satisfy Number.h
    map<string, Number*> getValues();
    void setValues(string key, Number* val);
    string getTranscendentalValue();
    void setTranscendentalValue(string value); 
    vector<Number*> getLogValues();
    void setLogValues(int index, Number* val);
    void simplify();
    //TODO change to Number*
    Number* add(Integer*);

    // Abstract operation methods
    Number* add(Number*);
    Number* subtract(Number*);
    Number* multiply(Number*);
    Number* divide(Number*);
    Number* exponentiate(Number*);
};

#endif	/* INTEGER_H */

