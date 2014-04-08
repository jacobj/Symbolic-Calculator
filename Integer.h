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
	Integer(int coefficient);
	void simplify();
	string display();
    int getCoefficient();
    void setCoefficient(int coefficient);
    
private:
	int coefficient;
    
};

#endif	/* INTEGER_H */

