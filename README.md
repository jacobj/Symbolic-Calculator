# Symbolic Calculator
Project for COP3503.

## How To
Compile with make, run with ./test
For help entering expressions, visit the help menu.
Please note that square roots are entered as x^(1/2) and nth roots as x^(1/n)

## Authors
- Elaine Del Rosario
- Nicola Frachesen
- Jacob Jenkins
- Brent Lewis
- Shreya Nirmalan

## Added Functionality For Stage 2
### Also Able To:
- 'ans' can now be placed anywhere in the expression, and an expression can contain multiple ans terms(i.e. ans + ans)
- Simplify mixed expressions containing different number types (i.e. 7+2*e+8*e^(4-3))
- Add, multiply, subtract, and divide expressions (i.e. 3 + 2*pi -1)
- Simplify exponentials with both positive and negative rational exponents
- FOIL expressions
- Add, multiply, subtract, and divide nthroot irrationals with Integer bases and exponents

### Bonus Functionality:
- Double negative input works, i.e. "x--y" and "x-(-y)"

## Accomplishments
### Able to:
- Add, subtract, multiply, divide, exponentiate, and take logs of integers
- Reduce fractions to their lowest terms
- Accepts transcendental numbers 'pi' and 'e'
- Add, subtract, multiply, and divide the transcendental numbers
- Add, subtract, multiply, and divide rational numbers with integers
- Can simplify with transcendental numbers in numerator, and when in both numerator and denominator
- Functional help menu with descriptions of how to input an expression
- Able to convert all numbers to decimal/float -> toDouble() method
- Able to show all previous expressions and answers entered
- Able to multiply exponentials with fractions
- 'ans' does not store the previous answer, but rather it stores the user-specified answer

### Used the following skills:
- Polymorphism
	- Abstract classes and typeids
- Maps
- Shunting yard algorithm
- Parsing to infinite depth of parentheses and infinite length of digits
- String conversion
- Euclid's method
- Prime factorization
- makefiles
- GitHub & git commands
- Team bonding!


