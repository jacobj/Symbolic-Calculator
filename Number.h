/* 
 * File:   Number.h
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#ifndef NUMBER_H
#define	NUMBER_H

#include <iostream>
#include <fstream>

class Number
{
public:
    virtual void simplify() = 0;
    virtual void display() = 0;
};

#endif	/* NUMBER_H */

