OBJS = main.o Calculator.o Integer.o TranscendentalNumber.o Expression.o RationalNumber.o Logarithm.o Exponential.o

all: test.exe

clean:
	rm *.o test.exe
	
test.exe: $(OBJS)
	g++ -g -o test $(OBJS)

testCalculator.o: testCalculator.cpp Calculator.h Calculator.cpp
	g++ -c -g testCalculator.cpp
	
testExpression.o: testExpression.cpp Expression.h Expression.cpp
	g++ -c -g testCalculator.cpp
	
Calculator.o: Calculator.h Calculator.cpp
	g++ -c -g Calculator.cpp
	
Integer.o: Integer.h Integer.cpp
	g++ -c -g Integer.cpp
	
main.o: main.cpp
	g++ -c -g main.cpp
	
TranscendentalNumber.o: TranscendentalNumber.h TranscendentalNumber.cpp
	g++ -c -g TranscendentalNumber.cpp
	
Expression.o: Expression.h Expression.cpp
	g++ -c -g Expression.cpp
	
Exponential.o: Exponential.h Exponential.cpp
	g++ -c -g Exponential.cpp
	
RationalNumber.o: RationalNumber.h RationalNumber.cpp
	g++ -c -g RationalNumber.cpp
	
Logarithm.o: Logarithm.h Logarithm.cpp
	g++ -c -g Logarithm.cpp
