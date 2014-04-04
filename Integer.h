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
	Integer(int value);
	void simplify();
	string display();
    
private:
	int value;
    
};

#endif	/* INTEGER_H */

