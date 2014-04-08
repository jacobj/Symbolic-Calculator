/* 
 * File:        Logarithm.h
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#ifndef LOGARITHM_H
#define	LOGARITHM_H
#include "Number.h"

class Logarithm: public Number
{
    protected:
        Number base;
        Number argument;
        
    public:
        void simplify();
        void display();
    
        int getCoefficient();
        int getValue();
        vector<int> getValues();
        Number getBase();
        void setCoefficient(int coefficient);
        void setValue(int value);
        void setValues(vector<int> values);
        void setBase(Number base);
};


#endif	/* LOGARITHM_H */

