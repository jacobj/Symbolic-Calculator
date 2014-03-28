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
};


#endif	/* LOGARITHM_H */

