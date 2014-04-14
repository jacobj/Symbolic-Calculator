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
vector<Number*> Logarithm::getLogValues() {
    return LogValues;
}
void Logarithm::setLogValues(vector<Number*> LogValues) {
    this->LogValues = LogValues;
}

// Make more general, in case other logs are added.
// So, Josh decided he doesn't want this. CHANGE SIMPLIFY.
void Logarithm::simplify() {
    // If the base is an Integer,
    if (typeid(*values["base"]) == typeid(Integer)) {
        // and the last value in logValues is also an Integer,
        if (typeid(*values["value"]) == typeid(Integer)) {
            // if the value is divisible by the base to the base
            if (values["value"]->getValue() / ((long)pow(values["value"]->getValue(), values["value"]->getValue())) == 0) {
                long multiplier = values["value"]->getValue() / ((long)pow(values["value"]->getValue(), values["value"]->getValue()));
                if (typeid(*values["coefficient"]) == typeid(Integer)) {
                    values["integer"]->setValue(multiplier * values[coefficient]->getValue());
                    // set the value equal to the multiplier,
                    values["value"]->setValue(multiplier);
                    // Get all the twos out.
                    int coefficientMultiplier = logBaseN(values["value"]->getValue(), 2, 0);
                    values["coefficient"]->setValue(values["coefficient"]->getValue() * counter);
                    for (int i = 0; i < coeffientMultiplier; i++) {
                        values["value"]->setValue(values["value"] / coefficientMultiplier);
                    }
                }
            }
        }
    }
                
        // if (typeid(*logValues[logValues.size() - 1]) == typeid(Integer)) {
    //         // Make a vector of prime factors
    //         // Fill it 
    //         vector<long> primes;
    //         primes = findPrimeFactors(LogValues[logValues() - 1]->getValue(), 2, primes);
    //         splitLog(primes)
    //             }
            
    // if (typeid(LogValues[0]) == typeid(Integer)){
    // 	primes = findPrimeFactors(LogValues[0]->getValue(), 2, primes);
    // 	splitLog(primes);
    // }
    // if (typeid(LogValues[0]) == typeid(RationalNumber)){
    // 	//Splits a log of a RationalNumber into a log of its numerator and denominator
    // 	//separated by a minus.
    // 	Number* temp = LogValues[0];
    //     LogValues[0] = temp->getValues()["numerator"];
    //     LogValues.push_back(temp->getValues()["denominator"]);
    //     smoothOperator = '-';
    // }
}

//toDouble and toString currently give you the log at the position in the vector
//you want. This certainly needs tweaking, along with better interaction with
//how log splitting will work. Just getting the basic implementation done.
double Logarithm::toDouble(){
	//Uses log() from cmath which gives the natural logarithm.
	//Either subtracts or adds, depending on smoothOperator.
	double tempSum;
	for (int i = 0; i >= LogValues.size(); i++){
		if (smoothOperator == '+'){
			tempSum += values["coefficient"]->toDouble()*(log(LogValues[i]->toDouble())/log(values["base"]->toDouble()));
		}
		else {
			tempSum -= values["coefficient"]->toDouble()*(log(LogValues[i]->toDouble())/log(values["base"]->toDouble()));
		}
	}
	return tempSum;
}

string Logarithm::toString(){
	stringstream valueStream;
	valueStream << values["coefficient"]->toString();
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
	string str = valueStream.str();
	return str;
}

void Logarithm::splitLog(vector<long> primes) {
    // Not the best way to do this, will be overhauled later. -- Well, seems good.
    LogValues.clear();
    for (int i = 0; i < primes.size(); i++) {
        LogValues.push_back(primes[i]);
        smoothOperator = '+';
    }
}

int Logarithm::logBaseN(int value, int n, int counter) {
    if (value % n != 0) {
        return counter;
    } else {
        return logBaseN(value % n, n, counter++);
    }
}

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

//Satisfying our love of maps
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
