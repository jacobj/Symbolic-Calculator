#include "Logarithm.h"

using namespace std;

/*
 * TODO: Write a little bit about what this class does in relation to Expression
 */

Logarithm::Logarithm(Number coefficient, vector<Number*> LogValues, Number base) {
	this->values["coefficient"] = coefficient;
	this->LogValues = LogValues;
	this->values["base"] = base;
}

Logarithm::~Logarithm() {
    delete values["coefficient"];
    delete values;
    delete values["base"];
}

// Get and Set Methods
map<string, Number*> Logarithm::getValues() {
    return values;
}

void Logarithm::setValues(string key, Number* val) {
    values[key] = val;
}
vector<Number*> Logarithm::getLogValues() {
    return values;
}
void Logarithm::setLogValues(vector<Number*> LogValues) {
    this->LogValues = LogValues;
}

// Make more general, in case other logs are added.
void Logarithm::simplify() {
    vector<int> primes;
    if (typeid(LogValues[0]) == typeid(Integer)){
    	vector<int> primes = findPrimeFactors(LogValues[0].getValue(), 2, primes);
    	splitLog(primes);
    }
    if (typeid(LogValues[0]) == typeid(RationalNumber)){
    	//Splits a log of a RationalNumber into a log of its numerator and denominator
    	//separated by a minus.
    	RationalNumber temp = LogValues[0];
        LogValues[0] = temp.getValues()["numerator"];
        LogValues.push_back(temp.getValues()["denominator"]);
        smoothOperator = '-';
    }
}
void Logarithm::display() {
    // Exists to satisfy Number Parent class. May be needed in the future.
}

//toDouble and toString currently give you the log at the position in the vector
//you want. This certainly needs tweaking, along with better interaction with
//how log splitting will work. Just getting the basic implementation done.
double Logarithm::toDouble(){
	//Uses log() from cmath which gives the natural logarithm.
	//Either subtracts or adds, depending on smoothOperator.
	double tempSum;
	for (i = 0; i >= LogValues.size(), i++){
		if (smoothOperator = '+'){
			tempSum += values["coefficient"]->toDouble()*(log(LogValues[i]->toDouble())/log(values["base"]->toDouble));
		}
		else {
			tempSum -= values["coefficient"]->toDouble()*(log(LogValues[i]->toDouble())/log(values["base"]->toDouble));
		}
	}
	return tempSum;
}
string Logarithm::toString(){
	stringstream valueStream;
	valueStream << values["coefficient"]->toString()
	for (i = 0; i >= LogValues.size(), i++){
		if (i = LogValues.size()-1){
			valueStream << "log_" << values["base"]->toString() << ":" << LogValues[i]->toString();
		}
		else if (smoothOperator = '+'){
			valueStream << "log_" << values["base"]->toString() << ":" << LogValues[i]->toString() << "+";
		}
		else{
			valueStream << "log_" << values["base"]->toString() << ":" << LogValues[i]->toString() << "-";
		}
	}
	string str = valueStream.str();
	return str;
}

void Logarithm::splitLog(vector<int> primes) {
    // Not the best way to do this, will be overhauled later. -- Well, seems good.
    LogValues.clear();
    for (int i = 0; i < primes.size(); i++) {
        LogValues.push_back(primes[i]);
        smoothOperator = '+';
    }
}

vector<int> Logarithm::findPrimeFactors(int number, int i, vector<int> primeFactors) {
    if (number < i) {
        return primeFactors;
    } else if (number % i == 0) {
        primeFactors.push_back(i);
        return findPrimeFactors(number / i, 2, primeFactors);
    } else {
        return findPrimeFactors(number, i++, primeFactors);
    }
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
