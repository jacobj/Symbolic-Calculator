/* 
 * File:        Exponential.cpp
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#include "Exponential.h"

using namespace std;

Exponential::Exponential(Number* value, Number* exponent, Number* coefficient) {
    this->values["value"] = value;
    this->values["exponent"] = exponent;
    this->values["coefficient"] = coefficient;
    // All classes should definitly run this after construction.
    simplify();
}

Exponential:: Exponential(string expression) {
    /********************************************
     Currently only evaluates simple expressions
     containing only TNs or Ints
     ********************************************/
    
    // searches for the position of the valid operator
    int pos = expression.find_first_of("^");
    
    // checks if a valid operator was entered
    if (pos == -1) {
        string exception = "ERROR! Enter a valid operator! (+ - * / ^) \n";
        throw exception;
    }
    // Obtains expression substrings -- one for value, one for exponent
    string base = expression.substr(0, pos);
    string expo = expression.substr(pos+1, expression.size());
    Number* value;
    Number* exponent;
    // Number* coefficient;
    
    // Checks Number type for value/base
    if(base == "e") {
        value = new TranscendentalNumber(base);
    }
    else if (base == "pi" || base == "PI") {
        value = new TranscendentalNumber(base);
    }
    else {
        value = new Integer(base);
    }
    
    // Checks Number type for exponent
    if(expo == "e") {
        exponent = new TranscendentalNumber(expo);
    }
    else if(expo == "pi" || expo == "PI") {
        exponent = new TranscendentalNumber(expo);
    }
    else {
        exponent = new Integer(expo);
    }
    
    // Creates Exponential object
    // this->values["coefficient"] = coefficient;
    this->values["value"] = value;
    this->values["exponent"] = exponent;
}

Exponential::~Exponential() {
    delete values["value"];
    delete values["exponent"];
    delete values["coefficient"];
}

map<string, Number*> Exponential::getValues() {
    return values;
}

void Exponential::setValues(string key, Number* val) {
    values[key] = val;
}

double Exponential::toDouble(){
    return values["coefficient"]->toDouble() * pow(values["value"]->toDouble(), values["exponent"]->toDouble());
}

string Exponential::toString(){
	stringstream valueStream;
    valueStream << values["coefficient"]->toString() << values["value"]->toString()<< "^" << values["exponent"]->toString();
	string str = valueStream.str();
	return str;
}
  
// Simplify method.
void Exponential::simplify() {
    // If the value is an Integer,
    if (typeid(*values["value"]) == typeid(Integer)) {
    
        // If the exponent is a RationalNumber,
        if (typeid(*values["exponent"]) == typeid(RationalNumber)) { 
            
            // If the exponent's numerator is an Integer,
            if (typeid(*values["exponent"]->getValues()["numerator"]) == typeid(Integer)) {
            
                // Raise the value to nth power and set the exponent to 1.
                values["value"]->setValue(((long)pow(values["value"]->getValue(), 
                                                     values["exponent"]->getValues()["numerator"]->getValue())));
                                                     
                // Set the numerator of the exponent to 1, as it has already been raised appropriately.
                values["exponent"]->getValues()["numerator"]->setValue(1);
            }
           
            // If the exponent's denominator is an Integer,
            if (typeid(*values["exponent"]->getValues()["denominator"]) == typeid(Integer)) {
            
                // Break up value into it's prime factors.
                vector<int> primes; 
                primes = findPrimeFactors(values["value"]->getValue(), 
                                          2, primes);
                                          
                // Sort results in descending order.
                sort(primes.begin(), primes.end());
                int value = values["value"]->getValue();

                // If the coefficient is an Integer.
                if (typeid(values["coefficient"]) == typeid(Integer)) {
                
                    int coefficient = values["coefficient"]->getValue();
                    reduceInsideRoot(value, coefficient, 
                                     values["exponent"]->getValues()["denominator"]->getValue(), primes);
                                     
                    // Set value and coeffient to the returned values from reduceInsideRoot.
                    values["value"]->setValue(value);
                    values["coefficient"]->setValue(coefficient);
                }       
            }
            // What if the denominator is not an Integer? For now let's just leave it alone.
        }
        
        // Else, if the exponent is an Integer
        else if (typeid(*values["exponent"]) == typeid(Integer)) {
            long num = (long) pow(values["value"]->getValue(), values["exponent"]->getValue());
            values["value"] = new Integer(num);
            values["exponent"] = new Integer(1);
        }
        
    }
    // Else, if the value is a rational
    else if (typeid(*values["value"]) == typeid(RationalNumber)) {
    
        // And the numerator of the value is an Integer,
        if (typeid(*values["value"]->getValues()["numerator"]) == typeid(Integer) && 
            typeid(*values["value"]->getValues()["denominator"]) == typeid(Integer)) {
            
            // And the exponent is an Integer,
            if (typeid(*values["exponent"]) == typeid(Integer)) {
            
                // Square both denominator and numerator.
                values["value"]->getValues()["denominator"]->setValue((long)pow(values["value"]->getValues()["denominator"]->getValue(),
                                                                                values["exponent"]->getValue()));
                                                                              
                values["value"]->getValues()["numerator"]->setValue((long)pow(values["value"]->getValues()["numerator"]->getValue(),
                                                                              values["exponent"]->getValue()));
                                                                              
                // Simplify the value using the RationalNumber simplify method.
                values["value"]->simplify();
                values["exponenet"]->setValue(1); 
            }
            // Raise a rational to a rational
            // If the exponent is a rational.
            else if (typeid(*values["exponent"]) == typeid(RationalNumber)) {
            
                // If the exponent's numerator is an integer.
                if (typeid(*values["exponent"]->getValues()["numerator"]) == typeid(Integer)) { 
                
                    values["value"]->getValues()["denominator"]->setValue((long)pow(values["value"]->getValues()["denominator"]->getValue(),
                                                                                    values["exponent"]->getValues()["numerator"]->getValue()));
                    values["value"]->getValues()["numerator"]->setValue((long)pow(values["value"]->getValues()["numerator"]->getValue(),
                                                                                  values["exponent"]->getValues()["numerator"]->getValue()));
                    values["value"]->simplify();
                    
                    values["exponent"]->getValues()["numerator"]->setValue(1); 
                    
                    // If the exponents's denominator is an Integer.
                    if (typeid(*values["exponent"]->getValues()["denominator"]) == typeid(Integer)) {                    
                        // This needs to root both the numerator and denominator value.
                        /*
                          vector<int> primes1;
                          primes1 = findPrimeFactors(denominatorptr->getValue(), 2, primes1); 
                          vector<int> primes2;
                          primes2 = findPrimeFactors(numeratorptr->getValue(), 2, primes2);
                        */
                    }
                } 
            }      
        }
        else {
            // Split into two seperate expoentials
            values["value"]->getValues()["denominator"] = new Exponential(values["value"]->getValues()["denominator"], 
                                                                          values["exponent"], values["coefficient"]);
            values["value"]->getValues()["numerator"] = new Exponential(values["value"]->getValues()["numerator"], 
                                                                        values["exponent"], values["coefficient"]);
        }
    }
}

// Find the primes. Helper method.
vector<int> Exponential::findPrimeFactors(int number, int i, vector<int> primeFactors) {
    if (number < i) {
        return primeFactors;
    } else if (number % i == 0) {
        primeFactors.push_back(i);
        return findPrimeFactors(number / i, 2, primeFactors);
    } else {
        return findPrimeFactors(number, i++, primeFactors);
    }
}

// Reduce value and multiply coefficients. Helper Method.
void Exponential::reduceInsideRoot(int &value, int &coefficient, int root, vector<int> primeFactors) {
    int counter = 1;
    int current = primeFactors[0];
    for (int i = 0; i < primeFactors.size(); i++) {
        if (current == primeFactors[i]) {
            counter++;
        } else {
            current = primeFactors[i];
            counter = 1;
        }
        if (counter == root) {
            coefficient *= primeFactors[i];
            for (int j = 0; j < root; j++) {
                value /= primeFactors[i];
            }
            counter = 0;
        }
    }
}

/*
vector<Number*> Exponential::getLogValues() {
    return;
}

void Exponential::setLogValues(int index, Number* val) {
    return;
}
*/

string Exponential::getTranscendentalValue() {
    return "";
}

void Exponential::setTranscendentalValue(string value) {
    return;
}

//Operation methods
Number* Exponential::add(Number* val) {
	if (typeid(*val) == typeid(Integer)) {

	}
	else if (typeid(*val) == typeid(Exponential)) {

	}
	else if (typeid(*val) == typeid(Expression)) {

	}
	else if (typeid(*val) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*val) == typeid(RationalNumber)) {

	}
	else if (typeid(*val) == typeid(Logarithm)) {

	}
	else {

	}
}
Number* Exponential::subtract(Number* val) {
	if (typeid(*val) == typeid(Integer)) {

	}
	else if (typeid(*val) == typeid(Exponential)) {

	}
	else if (typeid(*val) == typeid(Expression)) {

	}
	else if (typeid(*val) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*val) == typeid(RationalNumber)) {

	}
	else if (typeid(*val) == typeid(Logarithm)) {

	}
	else {

	}
}
Number* Exponential::multiply(Number* val) {
	if (typeid(*val) == typeid(Integer)) {

	}
	else if (typeid(*val) == typeid(Exponential)) {

	}
	else if (typeid(*val) == typeid(Expression)) {

	}
	else if (typeid(*val) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*val) == typeid(RationalNumber)) {

	}
	else if (typeid(*val) == typeid(Logarithm)) {

	}
	else {

	}
}
Number* Exponential::divide(Number* val) {
	if (typeid(*val) == typeid(Integer)) {

	}
	else if (typeid(*val) == typeid(Exponential)) {

	}
	else if (typeid(*val) == typeid(Expression)) {

	}
	else if (typeid(*val) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*val) == typeid(RationalNumber)) {

	}
	else if (typeid(*val) == typeid(Logarithm)) {

	}
	else {

	}
}
Number* Exponential::exponentiate(Number* val) {
	if (typeid(*val) == typeid(Integer)) {

	}
	else if (typeid(*val) == typeid(Exponential)) {

	}
	else if (typeid(*val) == typeid(Expression)) {

	}
	else if (typeid(*val) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*val) == typeid(RationalNumber)) {

	}
	else if (typeid(*val) == typeid(Logarithm)) {

	}
	else {

	}
}
