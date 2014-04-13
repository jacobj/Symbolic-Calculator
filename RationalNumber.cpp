/* 
 * File:        RationalNumber.cpp
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#include "RationalNumber.h"

RationalNumber::RationalNumber(Number* numerator, Number* denominator) {
    this->values["numerator"] = numerator;
    this->values["denominator"] = denominator;
}

RationalNumber::~RationalNumber() {
    delete values["numerator"];
    delete values["denominator"];
}

map<string, Number*> RationalNumber::getValues() {
    return values;
}

void RationalNumber::setValues(string key, Number* val) {
    values[key] = val;
}

double RationalNumber::toDouble(){
    return values["numerator"]->toDouble() / values["denominator"]->toDouble();
}

string RationalNumber::toString(){
	stringstream valueStream;
	valueStream << values["numerator"]->toString() << "/" << values["denominator"]->toString();
	string str = valueStream.str();
	return str;
}

//Operation Methods
Number* RationalNumber::add(Number* value){
	if (typeid(*value) == typeid(Integer)) {

	}
	else if (typeid(*value) == typeid(Exponential)) {

	}
	else if (typeid(*value) == typeid(Expression)) {

	}
	else if (typeid(*value) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*value) == typeid(RationalNumber)) {

	}
	else if (typeid(*value) == typeid(Logarithm)) {

	}
	else {

	}

}
Number* RationalNumber::subtract(Number* value){
	if (typeid(*value) == typeid(Integer)) {

	}
	else if (typeid(*value) == typeid(Exponential)) {

	}
	else if (typeid(*value) == typeid(Expression)) {

	}
	else if (typeid(*value) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*value) == typeid(RationalNumber)) {

	}
	else if (typeid(*value) == typeid(Logarithm)) {

	}
	else {

	}
}
Number* RationalNumber::multiply(Number* value){
	if (typeid(*value) == typeid(Integer)) {

	}
	else if (typeid(*value) == typeid(Exponential)) {

	}
	else if (typeid(*value) == typeid(Expression)) {

	}
	else if (typeid(*value) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*value) == typeid(RationalNumber)) {

	}
	else if (typeid(*value) == typeid(Logarithm)) {

	}
	else {

	}
}
Number* RationalNumber::divide(Number* value){
	if (typeid(*value) == typeid(Integer)) {

	}
	else if (typeid(*value) == typeid(Exponential)) {

	}
	else if (typeid(*value) == typeid(Expression)) {

	}
	else if (typeid(*value) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*value) == typeid(RationalNumber)) {

	}
	else if (typeid(*value) == typeid(Logarithm)) {

	}
	else {

	}
}
Number* RationalNumber::exponentiate(Number* value){
	if (typeid(*value) == typeid(Integer)) {

	}
	else if (typeid(*value) == typeid(Exponential)) {

	}
	else if (typeid(*value) == typeid(Expression)) {

	}
	else if (typeid(*value) == typeid(TranscendentalNumber)) {

	}
	else if (typeid(*value) == typeid(RationalNumber)) {

	}
	else if (typeid(*value) == typeid(Logarithm)) {

	}
	else {

	}
}

// Simplify helper method.
void RationalNumber::simplify() {
    // If the denominator is an Integer and the numerator is an Integer.
    if (typeid(*values["denominator"]) == typeid(Integer) &&
        typeid(*values["numerator"]) == typeid(Integer)) {
        // Find the the common factor via Euclid's method.
        int gcd = findGCD(values["denominator"]->getValue(), 
                          values["numerator"]->getValue());
        // Divide the values by that factor to simplify.
        values["denominator"]->setValue(values["denominator"]->getValue() / gcd);
        values["numerator"]->setValue(values["numerator"]->getValue() / gcd);
    }
    // If the denominator is an Integer and the numerator is not.
    else if (typeid(*values["denominator"]) == typeid(Integer) &&
             typeid(*values["numerator"]) != typeid(Integer)) {
        // And the numerator's coefficient is an Integer
        if (typeid(*values["numerator"]->getValues()["coefficient"]) == typeid(Integer)) {
            int gcd = findGCD(values["denominator"]->getValue(),
                              values["numerator"]->getValues()["coefficient"]->getValue());
            values["denominator"]->setValue(values["denominator"]->getValue() / gcd);
            values["numerator"]->getValues()["coefficient"]->setValue(values["numerator"]->getValues()["coefficient"]->getValue() / gcd);
        }
    }
    // If the denominator is not and Integer and the numerator is.
    else if (typeid(*values["denominator"]) != typeid(Integer) &&
             typeid(*values["numerator"]) == typeid(Integer)) {
        // And the denominator's coefficient is an Integer.
        if (typeid(*values["denominator"]->getValues()["coefficient"]) == typeid(Integer)) {
            int gcd = findGCD(values["numerator"]->getValue(),
                              values["denominator"]->getValues()["coefficient"]->getValue());
            values["numerator"]->setValue(values["numerator"]->getValue() / gcd);
            values["denominator"]->getValues()["coefficient"]->setValue(values["denominator"]->getValues()["coefficient"]->getValue() / gcd);
        }
    }
    // If the numerator and denominator are both not Integers.
    else if (typeid(*values["denominator"]) != typeid(Integer) &&
             typeid(*values["numerator"]) != typeid(Integer)) {
        // And both coeffcients are are Integers.
        if (typeid(*values["denominator"]->getValues()["coefficient"]) == typeid(Integer) &&
            typeid(*values["numerator"]->getValues()["coefficient"]) == typeid(Integer)) {
            int gcd = findGCD(values["denominator"]->getValues()["coefficient"]->getValue(),
                              values["numerator"]->getValues()["coefficient"]->getValue());
            values["denominator"]->getValues()["coefficient"]->setValue(values["denominator"]->getValues()["coefficient"]->getValue() / gcd);
            values["numerator"]->getValues()["coefficient"]->setValue(values["numerator"]->getValues()["coefficient"]->getValue() / gcd);
        }
    }
    if (typeid(*values["denominator"]) == typeid(TranscendentalNumber) &&
        typeid(*values["numerator"]) == typeid(TranscendentalNumber)) {
        if (values["denominator"]->getTranscendentalValue() == 
            values["numerator"]->getTranscendentalValue()) {
            values["numerator"] = values["coefficient"];
            values["denominator"] = values["coefficient"];
        }
    }
    // If both the denominator and numerator are exponentials,
    else if (typeid(*values["denominator"]) == typeid(Exponential) &&
             typeid(*values["numerator"]) == typeid(Exponential)) {
        // If the both the denominator's and numerator's exponential's contain a value that is in fact an integer,
        if (typeid(*values["denominator"]->getValues()["value"]) == typeid(Integer) &&
            typeid(*values["numerator"]->getValues()["value"]) == typeid(Integer)) {
            // And the values are equal,
            if (values["denominator"]->getValues()["value"]->getValue() == 
                values["numerator"]->getValues()["value"]->getValue()) {
                // And the exponents of each are both RationalNumbers,
                if (typeid(*values["denominator"]->getValues()["exponent"]) == typeid(RationalNumber) &&
                    typeid(*values["numerator"]->getValues()["exponent"]) == typeid(RationalNumber)) {
                    // of which the denominator and numerator are Integers
                    if (typeid(*values["denominator"]->getValues()["exponent"]->getValues()["denominator"]) == typeid(Integer) &&
                        typeid(*values["denominator"]->getValues()["exponent"]->getValues()["numerator"]) == typeid(Integer) &&
                        typeid(*values["numerator"]->getValues()["exponent"]->getValues()["demominator"]) == typeid(Integer) &&
                        typeid(*values["numerator"]->getValues()["exponent"]->getValues()["numerator"]) == typeid(Integer)) {
                        // And the values of the denominator's of the exponents are equal,
                        if (values["numerator"]->getValues()["exponent"]->getValues()["demominator"]->getValue() == 
                            values["denominator"]->getValues()["exponent"]->getValues()["demominator"]->getValue()) {
                            // Set the denominator and numerator equal to only the coefficients.
                            values["numerator"] = values["numerator"]->getValues()["coefficient"];
                            values["denominator"] = values["denominator"]->getValues()["coefficient"];
                        }
                    }
                }
                // Or if the exponents of each are TranscendentalNumbers,
                else if (typeid(*values["denominator"]->getValues()["exponent"]) == typeid(TranscendentalNumber) &&
                         typeid(*values["numerator"]->getValues()["exponent"]) == typeid(TranscendentalNumber)) {
                    // And the exponents are equal.
                    if (values["denominator"]->getValues()["exponent"]->getTranscendentalValue() ==
                        values["numerator"]->getValues()["exponent"]->getTranscendentalValue()) {
                        // Set the denominator and numerator equal to only the coefficients.
                        values["numerator"] = values["numerator"]->getValues()["coefficient"];
                        values["denominator"] = values["denominator"]->getValues()["coefficient"];
                    }
                }
                // Or if the exponents
            }
        }
        // The denominator's and numerator's values are both trascendental,
        else if (typeid(*values["denominator"]->getValues()["value"]) == typeid(Integer) &&
                 typeid(*values["numerator"]->getValues()["value"]) == typeid(Integer)) {
            // The values of which are equal,
            if (values["denominator"]->getValues()["value"]->getTranscendentalValue() == 
                values["numerator"]->getValues()["value"]->getTranscendentalValue()) {
                // And the exponents of each are both RationalNumbers,
                if (typeid(*values["denominator"]->getValues()["exponent"]) == typeid(RationalNumber) &&
                    typeid(*values["numerator"]->getValues()["exponent"]) == typeid(RationalNumber)) {
                    // of which the denominator and numerator are Integers
                    if (typeid(*values["denominator"]->getValues()["exponent"]->getValues()["denominator"]) == typeid(Integer) &&
                        typeid(*values["denominator"]->getValues()["exponent"]->getValues()["numerator"]) == typeid(Integer) &&
                        typeid(*values["numerator"]->getValues()["exponent"]->getValues()["demominator"]) == typeid(Integer) &&
                        typeid(*values["numerator"]->getValues()["exponent"]->getValues()["numerator"]) == typeid(Integer)) {
                        // And the values of the denominator's of the exponents are equal,
                        if (values["numerator"]->getValues()["exponent"]->getValues()["demominator"]->getValue() == 
                            values["denominator"]->getValues()["exponent"]->getValues()["demominator"]->getValue()) {
                            // Set the denominator and numerator equal to only the coefficients.
                            values["numerator"] = values["numerator"]->getValues()["coefficient"];
                            values["denominator"] = values["denominator"]->getValues()["coefficient"];
                        }
                    }
                }
                // Or if the exponents of each are TranscendentalNumbers,
                else if (typeid(*values["denominator"]->getValues()["exponent"]) == typeid(TranscendentalNumber) &&
                         typeid(*values["numerator"]->getValues()["exponent"]) == typeid(TranscendentalNumber)) {
                    // And the exponents are equal.
                    if (values["denominator"]->getValues()["exponent"]->getTranscendentalValue() ==
                        values["numerator"]->getValues()["exponent"]->getTranscendentalValue()) {
                        // Set the denominator and numerator equal to only the coefficients.
                        values["numerator"] = values["numerator"]->getValues()["coefficient"];
                        values["denominator"] = values["denominator"]->getValues()["coefficient"];
                    }
                }
            }
        }
    }
    // If the denominator and numerator are Logarithms,
    else if (typeid(*values["denominator"]) == typeid(Logarithm) &&
             typeid(*values["numerator"]) == typeid(Logarithm)) {
        // And the values inside the logs are Integers,
        if (typeid(*values["denominator"]->getValues()["value"]) == typeid(Integer) &&
            typeid(*values["numerator"]->getValues()["value"]) == typeid(Integer)) {
            // And those values are equal,
            if (values["denominator"]->getValues()["value"]->getValue() == 
                values["numerator"]->getValues()["value"]->getValue()) {
                // And the bases are Integers,
                if (typeid(*values["denominator"]->getValues()["base"]) == typeid(Integer) &&
                    typeid(*values["numerator"]->getValues()["base"]) == typeid(Integer)) {
                    // And the bases are equal.
                    if (values["denominator"]->getValues()["base"]->getValue() == 
                        values["numerator"]->getValues()["base"]->getValue()) {
                        // Set the denominator and numerator equal to only the coefficients.
                        values["numerator"] = values["numerator"]->getValues()["coefficient"];
                        values["denominator"] = values["denominator"]->getValues()["coefficiet"];
                    }
                }
                // If the bases are Transcendentals
                if (typeid(*values["denominator"]->getValues()["base"]) == typeid(Integer) &&
                    typeid(*values["numerator"]->getValues()["base"]) == typeid(Integer)) {
                    // And the bases are equal,
                    if (values["denominator"]->getValues()["base"]->getTranscendentalValue() == 
                        values["numerator"]->getValues()["base"]->getTranscendentalValue()) {
                        // And the coefficients in front of them are both Integers,
                        if (typeid(*values["denominator"]->getValues()["base"]->getValues()["coefficient"]) ==
                            typeid(Integer) &&
                            typeid(*values["numerator"]->getValues()["base"]->getValues()["coefficient"]) ==
                            typeid(Integer)) {
                            // That are equal,
                            if (values["denominator"]->getValues()["base"]->getValues()["coefficient"]->getValue() ==
                                values["denominator"]->getValues()["base"]->getValues()["coefficient"]->getValue()) {
                                // Set the denominator and numerator equal to only the coefficients.
                                values["numerator"] = values["numerator"]->getValues()["coefficient"];
                                values["denominator"] = values["denominator"]->getValues()["coefficiet"];
                            }
                        }
                    }
                }
            }
        }
        // If the values inside the logs are transcendental
        else if (typeid(*values["denominator"]->getValues()["value"]) == typeid(TranscendentalNumber) &&
                 typeid(*values["numerator"]->getValues()["value"]) == typeid(TranscendentalNumber)) {
            // And those values are equal,
            if (values["denominator"]->getValues()["value"]->getTranscendentalValue() == 
                values["numerator"]->getValues()["value"]->getTranscendentalValue()) {
                // and the coefficients of those transcendental numbers are integers
                if (typeid(*values["denominator"]->getValues()["value"]->getValues()["coefficient"]) ==
                    typeid(Integer) &&
                    typeid(*values["numerator"]->getValues()["value"]->getValues()["coefficient"]) ==
                    typeid(Integer)) {
                    if (values["denominator"]->getValues()["value"]->getValues()["coefficient"]->getValue() ==
                        values["denominator"]->getValues()["value"]->getValues()["coefficient"]->getValue()) {
                        // And the bases are Integers,
                        if (typeid(*values["denominator"]->getValues()["base"]) == typeid(Integer) &&
                            typeid(*values["numerator"]->getValues()["base"]) == typeid(Integer)) {
                            // And the bases are equal.
                            if (values["denominator"]->getValues()["base"]->getValue() == 
                                values["numerator"]->getValues()["base"]->getValue()) {
                                // Set the denominator and numerator equal to only thise coefficients.
                                values["numerator"] = values["numerator"]->getValues()["coefficient"];
                                values["denominator"] = values["denominator"]->getValues()["coefficiet"];
                            }
                        }
                        // If the bases are Transcendentals
                        if (typeid(*values["denominator"]->getValues()["base"]) == typeid(Integer) &&
                            typeid(*values["numerator"]->getValues()["base"]) == typeid(Integer)) {
                            // And the bases are equal,
                            if (values["denominator"]->getValues()["base"]->getTranscendentalValue() == 
                                values["numerator"]->getValues()["base"]->getTranscendentalValue()) {
                                // And the coefficients in front of them are both Integers,
                                if (typeid(*values["denominator"]->getValues()["base"]->getValues()["coefficient"]) ==
                                    typeid(Integer) &&
                                    typeid(*values["numerator"]->getValues()["base"]->getValues()["coefficient"]) ==
                                    typeid(Integer)) {
                                    // That are equal,
                                    if (values["denominator"]->getValues()["base"]->getValues()["coefficient"]->getValue() ==
                                        values["denominator"]->getValues()["base"]->getValues()["coefficient"]->getValue()) {
                                        // Set the denominator and numerator equal to only the coefficients.
                                        values["numerator"] = values["numerator"]->getValues()["coefficient"];
                                        values["denominator"] = values["denominator"]->getValues()["coefficiet"];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
            
    else if (typeid(*values["denominator"]) == typeid(Exponential)) {  
        // Multiply the numerator and denominator by the denominator.
        // values["denominator"] * values["denominator"];
        // values["numerator"] * values ["denominator"];
    }
    else if (typeid(*values["numerator"]) == typeid(Integer)) {
        
    }
}
    
// Use euclid's algorithm
int RationalNumber::findGCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return findGCD(b, a % b);
    }
}

vector<Number*> RationalNumber::getLogValues() {
    // return NULL;
}

void RationalNumber::setLogValues(int index, Number* val) {
    return;
}

string RationalNumber::getTranscendentalValue() {
    return "";
}

void RationalNumber::setTranscendentalValue(string value) {
    return;
}

long RationalNumber::getValue() {
    return 1;
}

void RationalNumber::setValue(long value) {
    return; 
}
