/* 
 * File:        RationalNumber.h
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#ifndef RATIONALNUMBER_H
#define	RATIONALNUMBER_H

class RationalNumber : public Number {

public:
  RationalNumber(Number numerator, Number denominator);
  void simplify();
  int simplify(int a, int b);
  
private:
  // These will probably need to be pointers.
  Number numerator;
  Number denominator;
};

#endif	/* RATIONALNUMBER_H */
