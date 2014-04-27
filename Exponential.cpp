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

Exponential::Exponential(string expression) {
    // searches for the position of the valid operator
    int pos1 = expression.find_first_of("(");
    int pos2 = expression.find_first_of("^");
    int pos3 = expression.find_last_of("(");
    Number* value;
    Number* exponent;
    Number* coefficient;
    string base;
    string expo;
    string coeff;
    
    if (pos2 == -1) {
        string exception = "ERROR! Enter the valid operator! (^) \n";
        throw exception;
    }
    // If there are two sets of parenthesis
    if (pos1 != pos3) {
        if (pos1 != 0) {
            coeff = expression.substr(0, pos1); 
            base = expression.substr(pos1 + 1, pos2);
            expo = expression.substr(pos3+1, expression.size() - 1);
        }
        else {
            coeff = "1";
            base = expression.substr(1, pos2);
            expo = expression.substr(pos3 + 1, expression.size() - 1);
        }
    }
    else if (pos1 == pos3 && pos2 > pos1) {
        coeff = expression.substr(0, pos1); 
        base = expression.substr(pos1 + 1, pos2);
        expo = expression.substr(pos2 + 1, expression.size());
    }
    else if (pos1 == pos3 && pos2 < pos1) {
        // Obtains expression substrings -- one for value, one for exponent
        coeff = "1";
        base = expression.substr(0, pos2);
        expo = expression.substr(pos3 + 1, expression.size() - 1);
    }
    else {
        // Obtains expression substrings -- one for value, one for exponent
        coeff = "1";
        base = expression.substr(0, pos2);
        expo = expression.substr(pos2 + 1, expression.size());
    }
    
    // Checks Number type for value/base
    if(base == "e") {
        value = new TranscendentalNumber(base);
    }
    else if(base == "pi") {
        value = new TranscendentalNumber(base);
    }
    else if(base.find_first_of("/") != -1) {
        value = new RationalNumber(base);
    }
    else if(base.find_first_of("log") != -1) {
        value = new Logarithm(base);
    }
    else {
        value = new Integer(base);
    }

    // Checks Number type for exponent
    if(expo == "e") {
        exponent = new TranscendentalNumber(expo);
    }
    else if(expo == "pi") {
        exponent = new TranscendentalNumber(expo);
    }
    else if(expo.find_first_of("/") != -1) {
        exponent = new RationalNumber(expo);
    }
    else if(expo.find_first_of("log") != -1) {
        exponent = new Logarithm(expo);
    }
    else {
        exponent = new Integer(expo);
    }

    // Checks Number type for exponent
    if(coeff == "e") {
        coefficient = new TranscendentalNumber(coeff);
    }
    else if(coeff == "pi") {
        coefficient = new TranscendentalNumber(coeff);
    }
    else if(coeff.find_first_of("/") != -1) {
        coefficient = new RationalNumber(coeff);
    }
    else if(coeff.find_first_of("log") != -1) {
        coefficient = new Logarithm(expo);
    }
    else {
        coefficient = new Integer(coeff);
    }

    // Creates Exponential object
    this->values["coefficient"] = coefficient;
    this->values["value"] = value;
    this->values["exponent"] = exponent;
    simplify();
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
    if (values["coefficient"]->toString().compare("1")) {
        valueStream << values["coefficient"]->toString(); 
    }
    if (values["value"]->toString().compare("1")) {
        valueStream << "(" << values["value"]->toString() << ")";
        if (values["exponent"]->toString().compare("1")) {
            valueStream << "^(" << values["exponent"]->toString() << ")";
        }
    }
    string str = valueStream.str();
    return str;
}
  
// Simplify method.
void Exponential::simplify() {
    bool isNegative = false;
    bool valueNegative = false;
    // If the value is an Integer,
    if (!values["exponent"]->toString().compare("1")) {
        values["coefficient"] = values["coefficient"]->multiply(values["value"]);
        values["value"] = new Integer(1);
    }
    else if (typeid(*values["value"]) == typeid(Integer)) {
        // If the exponent is a RationalNumber,
        if (typeid(*values["exponent"]) == typeid(RationalNumber)) { 
            // If the exponent's numerator is an Integer,
            if (typeid(*values["exponent"]->getValues()["numerator"]) == typeid(Integer)) {
                // Raise the value to nth power and set the exponent to 1.
                if(values["exponent"]->getValues()["numerator"]->getValue() < 0) {
                    isNegative = true;
                    values["value"]->setValue(((long)pow(values["value"]->getValue(),
                                                         -1*values["exponent"]->getValues()["numerator"]->getValue())));
                } else {
                    values["value"]->setValue(((long)pow(values["value"]->getValue(),
                                                         values["exponent"]->getValues()["numerator"]->getValue())));
                }
                // Set the numerator of the exponent to 1, as it has already been raised appropriately.
                values["exponent"]->getValues()["numerator"]->setValue(1);
            }
            // If the exponent's denominator is an Integer,
            if (typeid(*values["exponent"]->getValues()["denominator"]) == typeid(Integer)) {
                // Break up value into it's prime factors.
            	if(values["value"]->getValue() < 0)
            	{
            		valueNegative = true;
            		values["value"]->setValue(values["value"]->getValue()*-1);
            	}
                vector<int> primes; 
                primes = findPrimeFactors(values["value"]->getValue(), 2, primes);
                // Sort results in descending order.
                sort(primes.begin(), primes.end());
                int value = values["value"]->getValue();
                // If the coefficient is an Integer.
                if (typeid(*values["coefficient"]) == typeid(Integer)) {
                    int coefficient = values["coefficient"]->getValue();
                    if (primes.size() > 0) {
                        reduceInsideRoot(value, coefficient, 
                                         values["exponent"]->getValues()["denominator"]->getValue(), primes);
                    }
                    // Set value and coeffient to the returned values from reduceInsideRoot.
                    if(isNegative) {
                        stringstream str;
                        string temp;
                        str << "1/" << coefficient;
                        temp = str.str();
                        this->values["coefficient"] = new RationalNumber(temp);
                        values["value"]->setValue(value);
                    } else {
                    	if(valueNegative)
                    		coefficient *= -1;

                        values["value"]->setValue(value);
                        values["coefficient"]->setValue(coefficient);
                    }
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
    /*
    // Else, if the value is a rational
    else if (typeid(*values["value"]) == typeid(RationalNumber)) {
        // And the numerator of the value is an Integer
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
                values["value"]->getValues()["denominator"]->getValue();
                values["value"]->getValues()["numerator"]->getValue();
                values["value"]->simplify();
                values["exponent"]->setValue(1); 
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
                        // make coef1 and coef2 = to 1,
                        Number* coef1 = new Integer(1);
                        Number* coef2 = new Integer(1);
                        // Split into two seperate expoentials,
                        Number* denom = new Exponential(new Integer(values["value"]->getValues()["denominator"]->getValue()), 
                                                        new RationalNumber(new Integer(values["exponent"]->getValues()["numerator"]->getValue()),
                                                                           new Integer(values["exponent"]->getValues()["denominator"]->getValue())), coef1);
                        Number* numer = new Exponential(new Integer(values["value"]->getValues()["numerator"]->getValue()), 
                                                        new RationalNumber(new Integer(values["exponent"]->getValues()["numerator"]->getValue()),
                                                                           new Integer(values["exponent"]->getValues()["denominator"]->getValue())), coef2);

                        values["value"]->setValues("denominator", denom); //= denom;
                        values["value"]->setValues("numerator", numer);
                        setValues("exponent", new Integer(1));
                    }
                } 
   
            }      
        }
    }
    */
}


// Find the primes. Helper method.
vector<int> Exponential::findPrimeFactors(int number, int i, vector<int> primeFactors) {
    if (number < i) {
        return primeFactors;
    } else if (number % i == 0) {
        primeFactors.push_back(i);
        return findPrimeFactors(number / i, 2, primeFactors);
    } else {
        return findPrimeFactors(number, ++i, primeFactors);
    }
}

// Reduce value and multiply coefficients. Helper Method.
void Exponential::reduceInsideRoot(int &value, int &coefficient, int root, vector<int> primeFactors) {
    int counter = 1;
    int current = primeFactors[0];
    for (int i = 1; i < primeFactors.size(); i++) {
        if (current == primeFactors[i]) {
            ++counter;
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


string Exponential::getTranscendentalValue() {
    return "";
}

void Exponential::setTranscendentalValue(string value) {
    return;
}

//Operation methods
Number* Exponential::add(Number* val) {
    if (typeid(*val) == typeid(Exponential)) {
        if (typeid(*val->getValues()["exponent"]) == typeid(Integer) &&
            typeid(*values["exponent"]) == typeid(Integer)) {
            if (val->getValues()["exponent"]->getValue() == values["exponent"]->getValue()) {
                if (typeid(*val->getValues()["value"]) == typeid(Integer) &&
                    typeid(*values["value"]) == typeid(Integer)) {
                    if (val->getValues()["value"]->getValue() == values["value"]->getValue()) {
                        Number* result = new Exponential(values["value"], values["exponent"], values["coefficient"]->add(val->getValues()["coefficient"]));
                        return result;
                    }
                }
                else if (typeid(*val->getValues()["value"]) == typeid(TranscendentalNumber) &&
                    typeid(*values["value"]) == typeid(TranscendentalNumber)) {
                    if (val->getValues()["value"]->getTranscendentalValue() == values["value"]->getTranscendentalValue()) {
                        Number* result = new Exponential(values["value"], values["exponent"], values["coefficient"]->add(val->getValues()["coefficient"]));
                        return result;
                    }
                }
            }
        } 
        else if (typeid(*val->getValues()["exponent"]) == typeid(RationalNumber) &&
                 typeid(*values["exponent"]) == typeid(RationalNumber)) {
            if (typeid(*val->getValues()["exponent"]->getValues()["denominator"]) == typeid(Integer) &&
                typeid(*values["exponent"]->getValues()["denominator"]) == typeid(Integer)) {
                if (val->getValues()["exponent"]->getValues()["denominator"]->getValue() == values["exponent"]->getValues()["denominator"]->getValue()) {
                    if (typeid(*(val->getValues()["exponent"]->getValues()["numerator"])) == typeid(Integer) &&
                               typeid(*(values["exponent"]->getValues()["numerator"])) == typeid(Integer)) {
                        if (val->getValues()["exponent"]->getValues()["numerator"]->getValue() == values["exponent"]->getValues()["numerator"]->getValue()) {
                            if (typeid(*val->getValues()["value"]) == typeid(Integer) &&
                                typeid(*values["value"]) == typeid(Integer)) {
                                if (val->getValues()["value"]->getValue() == values["value"]->getValue()) {
                                    Number* result = new Exponential(values["value"], values["exponent"], values["coefficient"]->add(val->getValues()["coefficient"]));
                                    return result;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else{
    	stringstream valStream;
    	valStream << this->toString() << "+" << val->toString();
    	string str = valStream.str();
    	return new Expression(str);
    }
}
Number* Exponential::subtract(Number* val) {
    if (typeid(*val) == typeid(Exponential)) {
        if (typeid(*val->getValues()["exponent"]) == typeid(Integer) &&
            typeid(*values["exponent"]) == typeid(Integer)) {
            if (val->getValues()["exponent"]->getValue() == values["exponent"]->getValue()) {
                if (typeid(*val->getValues()["value"]) == typeid(Integer) &&
                    typeid(*values["value"]) == typeid(Integer)) {
                    if (val->getValues()["value"]->getValue() == values["value"]->getValue()) {
                        Number* result = new Exponential(values["value"], values["exponent"], values["coefficient"]->subtract(val->getValues()["coefficient"]));
                        return result;
                    }
                }
            } 
        }
        else if (typeid(*val->getValues()["exponent"]) == typeid(RationalNumber) &&
                 typeid(*values["exponent"]) == typeid(RationalNumber)) {
            if (typeid(*val->getValues()["exponent"]->getValues()["denominator"]) == typeid(Integer) &&
                typeid(*values["exponent"]->getValues()["denominator"]) == typeid(Integer)) {
                if (val->getValues()["exponent"]->getValues()["denominator"]->getValue() == values["exponent"]->getValues()["denominator"]->getValue()) {
                    if (typeid(*(val->getValues()["exponent"]->getValues()["numerator"])) == typeid(Integer) &&
                        typeid(*(values["exponent"]->getValues()["numerator"])) == typeid(Integer)) {
                        if (val->getValues()["exponent"]->getValues()["numerator"]->getValue() == values["exponent"]->getValues()["numerator"]->getValue()) {
                            if (typeid(*val->getValues()["value"]) == typeid(Integer) &&
                                typeid(*values["value"]) == typeid(Integer)) {
                                if (val->getValues()["value"]->getValue() == values["value"]->getValue()) {
                                    Number* result = new Exponential(values["value"], values["exponent"], values["coefficient"]->subtract(val->getValues()["coefficient"]));
                                    return result;
                                }
                            }
                        }
                    }
                }
            }
        }
        else {
        }
    }
    else{
    	stringstream valStream;
    	valStream << this->toString() << "-" << val->toString();
    	string str = valStream.str();
    	return new Expression(str);
    }
}

Number* Exponential::multiply(Number* val) {
    if (typeid(*val) == typeid(Integer) && 
        typeid(*values["coefficient"]) == typeid(Integer)) {
        Number* result = new Exponential(values["value"], values["exponent"], values["coefficient"]->multiply(val));
        return result;
    }
    else if (typeid(*val) == typeid(Exponential)) {
        if (val->getValues()["exponent"]->toString().compare(values["exponent"]->toString()) == 0) {
            Number* coefficient = values["coefficient"]->multiply(val->getValues()["coefficient"]);
            Number* value = values["value"]->multiply(val->getValues()["value"]);
            Number* result = new Exponential(value, values["exponent"], coefficient);
            return result;
        }
        
    }
    //NEEDS TO BE HANDLED
    //else if (typeid(*val) == typeid(Expression)) {
        
    //}
    //else if (typeid(*val) == typeid(TranscendentalNumber)) {
        
    //}
    else if (typeid(*val) == typeid(RationalNumber)) {
        return new RationalNumber(multiply(val->getValues()["numerator"]), val->getValues()["denominator"]);
    }
    //else if (typeid(*val) == typeid(Logarithm)) {

    //}
    else{
    	stringstream valStream;
    	valStream << this->toString() << "*" << val->toString();
    	string str = valStream.str();
    	return new Expression(str);
    }
}

Number* Exponential::divide(Number* val) {
    Number* result =  new RationalNumber(this, val);
    if(!result->getValues()["denominator"]->toString().compare("1")){
    	result = result->getValues()["numerator"];
    }
    return result;
}

Number* Exponential::exponentiate(Number* val) {
	return new Exponential(values["value"], values["exponent"]->multiply(val), values["coefficient"]->exponentiate(val));
}

// Not used
void Exponential::display() {

}

long Exponential::getValue() {

}

void Exponential::setValue(long value) {

}
