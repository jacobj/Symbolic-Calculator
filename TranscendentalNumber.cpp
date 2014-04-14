/* 
 * File:        TranscendentalNumber.cpp
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */

#include "TranscendentalNumber.h"

using namespace std;

/*TranscendentalNumber::TranscendentalNumber(string value, Number* coefficient) {
    this->value = value;
    this->values["coefficient"] = coefficient;
}*/

TranscendentalNumber::TranscendentalNumber(string expression){
	// find the first e or pi in a string, then treat everything to the right as it's coefficient.
    // for now, just think of e and pi as having Integer coefficients.
    // p for pi, e for well e.
    int pos = expression.find_first_of("pe");
    if(pos == -1) {
		string exception = "ERROR! Enter a valid Transcendental! (e or pi)\n";
		throw exception;
	}
    else if (expression[pos] == 'p') {
        this->value = "pi";
    }
    else if (expression[pos] == 'e') {
        this->value = "e";
    }
    if (pos == 0) {
        values["coefficient"] = new Integer("1");
    }
    else {
        // currently, just row everything to the right in an Integer constructor
        values["coefficient"] = new Integer(expression.substr(0,pos));
    }
}

TranscendentalNumber::~TranscendentalNumber() {
    delete values["coefficient"];
}

//Get and set methods
map<string, Number*> TranscendentalNumber::getValues() {
    return values;
}

void TranscendentalNumber::setValues(string key, Number* val) {
    values[key] = val;
}
string TranscendentalNumber::getTranscendentalValue() {
    return value;
}

void TranscendentalNumber::setTranscendentalValue(string value) {
    this->value = value;
}

void TranscendentalNumber::simplify() {
    // Exists to satisfy Number Parent class.
}

void TranscendentalNumber::display() {
    // Exists to display Number Parent class.
	//Please call getValue() to return pi or e.
}
double TranscendentalNumber::toDouble(){
	//Coefficient is currently a number, so I am weary of its implmentation here,
	//as it requires very good operator overloading.
	//If we run out of time, consider changing back to int for simplicity.
	if (!value.compare("pi") || !value.compare("PI")){
		return values["coefficient"]->toDouble()*3.14;
	}
	else if(!value.compare("e")){
		return values["coefficient"]->toDouble()*2.72;
	}
	else{
	    return 0;
	}
}
string TranscendentalNumber::toString(){
	stringstream valueStream;
	if(values["coefficient"]->toString() != "1")
		valueStream << values["coefficient"]->toString() << value;

	else
		valueStream  << value;
	string str = valueStream.str();
	return str;
}

//Operation Methods
Number* TranscendentalNumber::add(Number* val){
	stringstream valStream;
	if (typeid(*val) == typeid(TranscendentalNumber)) {
		//TODO might need this line?
		//if (value.compare(val->toString()) == 0){
			Number* coeffs = values["coefficient"]->add(val->getValues()["coefficient"]);
			if(coeffs->toString() != "0")
				valStream << coeffs->toString() << value;
			else
				valStream << coeffs->toString();

			string str = valStream.str();
			return new TranscendentalNumber(str);
		//}
	}
	else if(!values["coefficient"]->toString().compare("1")){
		valStream << value << "+" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
	else{
		valStream << values["coefficient"]->toString() << value << "+" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
}
Number* TranscendentalNumber::subtract(Number* val){
	stringstream valStream;
	if (typeid(*val) == typeid(TranscendentalNumber)) {
		if (!value.compare(val->toString())){
			Number* coeffs = values["coefficient"]->subtract(val->getValues()["coefficient"]);
			if(coeffs->toString() != "0")
				valStream << coeffs->toString() << value;
			else
				valStream << coeffs->toString();

			string str = valStream.str();
			return new TranscendentalNumber(str);
		}
	}
	else if(!values["coefficient"]->toString().compare("1")){
		valStream << value << "-" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
	else{
		valStream << values["coefficient"]->toString() << value << "-" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
}
Number* TranscendentalNumber::multiply(Number* val){
	stringstream valStream;
	if (typeid(*val) == typeid(TranscendentalNumber)) {
		if (!value.compare(val->toString())){
			Number* coeffs = values["coefficient"]->multiply(val->getValues()["coefficient"]);
			if(coeffs->toString() != "0")
				valStream << coeffs->toString() << value;
			else
				valStream << coeffs->toString();
			string str = valStream.str();
			return new TranscendentalNumber(str);
		}
	}
	else if(!values["coefficient"]->toString().compare("1")){
		valStream << value << "*" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
	else{
		valStream << values["coefficient"]->toString() << value << "*" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
}
Number* TranscendentalNumber::divide(Number* val){
	//return new RationalNumber(this, val);
}
Number* TranscendentalNumber::exponentiate(Number* val){
	stringstream valStream;
	if(!values["coefficient"]->toString().compare("1")){
		valStream << value << "^" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
	else{
		valStream << values["coefficient"]->toString() << value << "^" << val->toString();
		string str = valStream.str();
		return new Expression(str);
	}
}

//For number's satisfaction
// vector<Number*> TranscendentalNumber::getLogValues() {
//     //return NULL;
// }
// void TranscendentalNumber::setLogValues(int index, Number* val) {
//     return;
// }

long TranscendentalNumber::getValue(){
  return 0;
}
void TranscendentalNumber::setValue(long value){
	return;
}
