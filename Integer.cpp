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

#include "Integer.h"

// Constructor
Integer::Integer(long value) {
    this->value = value;
}

Integer::Integer(string val){
	const long d2 = strtol( val.c_str(), NULL ,0);
	this->value = d2;
}

Integer::Integer() {
    this->value = 0;
}

// Get-Set methods
long Integer::getValue() {
    return value;
}

void Integer::setValue(long val) {
    this->value = val;
}

void Integer::display() {
    // Implement this.
}

double Integer::toDouble() {
	// get method can also be used here if double value not needed
	return (double) value;
}

string Integer::toString() {
	stringstream valueStream;
	valueStream << value;
	string str = valueStream.str();
	return str;
}
 
// The methods below exist only to satisfy Number.h.
map<string, Number*> Integer::getValues() {
    //return NULL;
}

void Integer::setValues(string key, Number* val) {
}

string Integer::getTranscendentalValue() {
    //return "";
}

void Integer::setTranscendentalValue(string value) {
}

void Integer::simplify() {
}

Number* Integer::add(Number* val) {
	if (typeid(*val) == typeid(Integer)) {
		this->value += val->getValue();
		Number* result = new Integer(this->toString());
        return result;
	} else if (typeid(*val) == typeid(RationalNumber)) {
		return val->add(this);
	} else if (typeid(*val) == typeid(Exponential)){
		stringstream valStream;
		valStream << val->toString() << "+" << toString();
		string str = valStream.str();
		return new Expression(str);
	} else {
		stringstream valStream;
		valStream << toString() << "+" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
}

Number* Integer::subtract(Number* val) {
	if (typeid(*val) == typeid(Integer)) {
        this->value -= val->getValue();
        Number* result = new Integer(this->toString());
        return result;
    } else if (typeid(*val) == typeid(RationalNumber)) {
		stringstream RatNumStream;
		RatNumStream << getValue() << "/1";
		string str = RatNumStream.str();
		Number* RatNum = new RationalNumber(str);
		return RatNum->subtract(val);
	} else {
		stringstream valStream;
		valStream << toString() << "-" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
}

Number* Integer::multiply(Number* val) {
    if (typeid(*val) == typeid(Integer)) {
        this->value *= val->getValue();
        Number* result = new Integer(this->toString());
        return result;
    } else if (typeid(*val) == typeid(RationalNumber)) {
		stringstream RatNumStream;
		RatNumStream << getValue() << "/1";
		string str = RatNumStream.str();
		Number* RatNum = new RationalNumber(str);
		return RatNum->multiply(val);
	} else if (typeid(*val) == typeid(TranscendentalNumber)) {
        Number* coeffs = new Integer(multiply(val->getValues()["coefficient"])->toString());
    	stringstream valStream;
        valStream << coeffs->toString() << val->getTranscendentalValue();
        string str = valStream.str();
        Number* result = new TranscendentalNumber(str);
        return result;
    } else if (typeid(*val) == typeid(Exponential)) {
    	return val->multiply(this);
    } else if (typeid(*val) == typeid(Expression)) {
        return val->multiply(this);
    } else {
		stringstream valStream;
		valStream << toString() << "*" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
    // Add cases where this multiplies into coefficients
}

Number* Integer::divide(Number* val) {
    if (typeid(*val) == typeid(Integer)) {
        if (this->value % val->getValue() == 0) {
            this->value /= val->getValue();
            Number* result = new Integer(this->toString());
            return result;
        } else {
        	return new RationalNumber(this, val);
        }
    // Add cases where this divides out coefficients
    } else if (typeid(*val) == typeid(RationalNumber)) {
		stringstream RatNumStream;
		RatNumStream << getValue() << "/1";
		string str = RatNumStream.str();
		Number* RatNum = new RationalNumber(str);
		return RatNum->divide(val);
        /*Number* numerator = this;
        Number* result = new RationalNumber(this, val);
        return result;*/
    } else {
    	return new RationalNumber(this, val);
    }
}
Number* Integer::exponentiate(Number* val) {
	if (this->getValue() == 0) {
		return new Integer("0");
	} else {
		if (toString() == "1") {
			return new Integer("1");
		} else {
			stringstream valStream;
			if (typeid(*val) == typeid(Integer)) {
				long valLong = 0;
				valLong = pow(getValue(), val->getValue());
				return new Integer((long)valLong);
			} else if (typeid(*val) == typeid(RationalNumber)) {
				Number* intCoefficient = new Integer("1");
				return new Exponential(this, val, intCoefficient);
			} else {
				stringstream valStream;
				valStream << toString() << "^" << val->toString();
				string str = valStream.str();
				return new Exponential(str);
			}
		}
	}
}
