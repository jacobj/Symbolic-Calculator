/* 
 * File:        NthRootIrrationalNumber.h
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#ifndef NTHROOTIRRATIONALNUMBER_H
#define	NTHROOTIRRATIONALNUMBER_H

class nthRootIrrational :: public Number {  
public:
  nthRootIrrational(int value, int base, int coefficient);
  simplify();
  findPrimeFactors(int number, int i, vector<int> primeFactors);
  reduceInsideRoot(vector<int> primeFactors);
private:
  int value;
  int base;
  int coefficient;
}

#endif	/* NTHROOTIRRATIONALNUMBER_H */

