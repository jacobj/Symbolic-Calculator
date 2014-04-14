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

TranscendentalNumber::TranscendentalNumber(string value, Number* coefficient) {
    this->value = value;
    this->values["coefficient"] = coefficient;
}

TranscendentalNumber::TranscendentalNumber(string value){
	this->value = value;
	coefficient = new Number("1");
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
	valueStream << values["coefficient"]->toString() << value;
	string str = valueStream.str();
	return str;
}

//Operation Methods
Number* TranscendentalNumber::add(Number* val){
	stringstream valStream;
	if (typeid(*val) == typeid(Exponential)) {
		if(!values["coefficient"]->toString().compare("1")){
			valStream << value << "+" << val->toString();
		}
		else{
			valStream << values["coefficient"]->toString() << value << "+" << val->toString();
		}
		string str = valStream.str();
		return new Expression(str);
	}
	else if (typeid(*val) == typeid(Expression)) {
		if(!values["coefficient"]->toString().compare("1")){
			valStream << value << "+" << val->toString();
		}
		else{
			valStream << values["coefficient"]->toString() << value << "+" << val->toString();
		}
		string str = valStream.str();
		return new Expression(str);
	}
	else if (typeid(*val) == typeid(Integer)) {
		if(!values["coefficient"]->toString().compare("1")){
			valStream << value << "+" << val->toString();
		}
		else{
			valStream << values["coefficient"]->toString() << value << "+" << val->toString();
		}
		string str = valStream.str();
		return new Expression(str);
	}
	else if (typeid(*val) == typeid(Logarithm)) {
		if(!values["coefficient"]->toString().compare("1")){
			valStream << value << "+" << val->toString();
		}
		else{
			valStream << values["coefficient"]->toString() << value << "+" << val->toString();
		}
		string str = valStream.str();
		return new Expression(str);
	}
	else if (typeid(*val) == typeid(RationalNumber)) {
		if(!values["coefficient"]->toString().compare("1")){
			valStream << value << "+" << val->toString();
		}
		else{
			valStream << values["coefficient"]->toString() << value << "+" << val->toString();
		}
		string str = valStream.str();
		return new Expression(str);
	}
	else if (typeid(*val) == typeid(TranscendentalNumber)) {
		if (!value.compare(val->value)){
			Number* coeffs = value["coefficient"]->add(val->value["coefficient"]);
			valStream << coeffs->toString() << value;
		}
		else if(!values["coefficient"]->toString().compare("1")){
			valStream << value << "+" << val->toString();
		}
		else{
			valStream << values["coefficient"]->toString() << value << "+" << val->toString();
		}
		string str = valStream.str();
		return new TranscendentalNumber(str);
	}
	else {
		return;
	}
}
Number* Transcendental::subtract(Number* val){

}
Number* Transcendental::multiply(Number* val){

}
Number* Transcendental::divide(Number* val){

}
Number* Transcendental::exponentiate(Number* val){

}

//For number's satisfaction
vector<Number*> TranscendentalNumber::getLogValues() {
    //return NULL;
}
void TranscendentalNumber::setLogValues(int index, Number* val) {
    return;
}
long TranscendentalNumber::getValue(){
  return 0;
}
void TranscendentalNumber::setValue(long value){
	return;
}
