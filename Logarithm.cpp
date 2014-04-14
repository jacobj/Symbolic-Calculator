#include "Logarithm.h"

using namespace std;

/*
 * TODO: Write a little bit about what this class does in relation to Expression
 */

Logarithm::Logarithm(Number* coefficient, Number* values, Number* base) {
	this->values["coefficient"] = coefficient;
	this->values["value"] = value;
	this->values["base"] = base;
    this->values["integer"] = 0;
}

Logarithm::~Logarithm() {
    delete values["coefficient"];
    delete values["value"];
    delete values["base"];
    delete values["integer"];
}

// Get and Set Methods
map<string, Number*> Logarithm::getValues() {
    return values;
}

void Logarithm::setValues(string key, Number* val) {
    values[key] = val;
}

/*
vector<Number*> Logarithm::getLogValues() {
    return LogValues;
}

void Logarithm::setLogValues(vector<Number*> LogValues) {
    this->LogValues = LogValues;
}
*/

double Logarithm::toDouble(){
	//Uses log() from cmath which gives the natural logarithm.
    return values["coefficient"]->toDouble() * (log(values["value"]->toDouble()) / 
                                                log(values["base"]->toDouble())) + values["integer"]->toDouble();
}

// Needs to be changed.
string Logarithm::toString(){
	stringstream valueStream;
	valueStream << values["coefficient"]->toString() << "log_" << values["base"]->toString() << ":" << values["value"]->toString();
    if (values["integer"]->getValue() != 0) {
        valueStream << "+" << values["integer"]->toString();
    }
	/* Not needed any longer...
    for (int i = 0; i >= LogValues.size(); i++){
		if (i == LogValues.size()-1){
			valueStream << "log_" << values["base"]->toString() << ":" << LogValues[i]->toString();
		}
		else if (smoothOperator == '+'){
			valueStream << "log_" << values["base"]->toString() << ":" << LogValues[i]->toString() << "+";
		}
		else{
			valueStream << "log_" << values["base"]->toString() << ":" << LogValues[i]->toString() << "-";
		}
	}
    */
	string str = valueStream.str();
	return str;
}

// Only simplifies Integers to integer bases with Integer coefficients ATM.
void Logarithm::simplify() {
    // If the base is an Integer,
    if (typeid(*values["base"]) == typeid(Integer)) {
        // and the last value in logValues is also an Integer,
        if (typeid(*values["value"]) == typeid(Integer)) {
            // See what power of base can be pulled out of the value,
            long multiplier = logBaseN(values["value"]->getValue(), values["base"]->getValue(), 0);
            // If the coefficient is an Integer.
            if (typeid(*values["coefficient"]) == typeid(Integer)) {
                // Set the value of the Integer to the coefficient times the multiplier.
                values["integer"]->setValue(multiplier * values["coefficient"]->getValue());
                // Set the value equal to the result of the value divided by the base^multiplier,
                values["value"]->setValue(values["value"]->getValue() / ((long)pow(values["base"]->getValue(), multiplier)));
                // Get all the twos out.
                int coefficientMultiplier = logBaseN(values["value"]->getValue(), 2, 0);
                // Set the value of the coefficient equal to itself times the coefficient multiplier,
                values["coefficient"]->setValue(values["coefficient"]->getValue() * coeffientMultiplier);
                // Set the value of value to the value divided by 2^coefficient multiplier.
                values["value"]->setValue(values["value"]->getValue() / ((long)pow(2, coefficientMultiplier)));
            }
        }
    }
}



//toDouble and toString currently give you the log at the position in the vector
//you want. This certainly needs tweaking, along with better interaction with
//how log splitting will work. Just getting the basic implementation done.



/*
void Logarithm::splitLog(vector<long> primes) {
    // Not the best way to do this, will be overhauled later. -- Well, seems good.
    LogValues.clear();
    for (int i = 0; i < primes.size(); i++) {
        LogValues.push_back(primes[i]);
        smoothOperator = '+';
    }
}
*/

int Logarithm::logBaseN(int value, int n, int counter) {
    if (value % n != 0) {
        return counter;
    } else {
        return logBaseN(value % n, n, counter++);
    }
}

/*
vector<long> Logarithm::findPrimeFactors(long number, long i, vector<long> prime) {
    if (number < i) {
        return primeFactors;
    } else if (number % i == 0) {
        primeFactors.push_back(i);
        return findPrimeFactors(number / i, 2, primeFactors);
    } else {
        return findPrimeFactors(number, i++, primeFactors);
    }
}
*/

// Operation methods -- not sure exactly what goes in these methods just yet
Number* Logarithm::add(Number*) {
    return;
}

Number* Logarithm::subtract(Number*) {
    return;
}

Number* Logarithm::multiply(Number*) {
    return;
}

Number* Logarithm::divide(Number*) {
    return;
}

Number* Logarithm::exponentiate(Number*) {
    return;
}

// Satisfying our love of maps
string Logarithm::getTranscendentalValue() {
    return "";
}

void Logarithm::setTranscendentalValue(string value) {
    return;
}
long Logarithm::getValue() {
    return 1;
}
void Logarithm::setValue(long value){
	return;
}
