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
    public:
        void simplify();
        void display();
    
        int getCoefficient();
        int getLastValue();
        vector<int> getValues();
        Number getBase();
        void setCoefficient(int coefficient);
        void setValue(int value);
        void setValues(vector<int> values);
        void setBase(Number base);

    private:
        Number coefficient;
        vector<int> values;
        Number base;
};


#endif	/* LOGARITHM_H */

