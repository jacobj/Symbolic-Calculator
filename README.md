# Symbolic Calculator
```
 ____              ___                    ___             __
/\  _`\           /\_ \                  /\_ \           /\ \__
\ \ \/\_\     __  \//\ \     ___   __  __\//\ \      __  \ \ ,_\    __
 \ \ \/_/_  /'__`\  \ \ \   /'___\/\ \/\ \ \ \ \   /'__`\ \ \ \/  /'__`\
  \ \ \L\ \/\ \L\.\_ \_\ \_/\ \__/\ \ \_\ \ \_\ \_/\ \L\.\_\ \ \_/\  __/
   \ \____/\ \__/.\_\/\____\ \____\\ \____/ /\____\ \__/.\_\\ \__\ \____\
    \/___/  \/__/\/_/\/____/\/____/ \/___/  \/____/\/__/\/_/ \/__/\/____/
    
```

Project for COP 3503.

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
### tl;dr
- All of the "common" and "a bit complex" cases are functional. FOILing is functional. 
- The "more complex" case of simplification of logs with bases greater than their values is functional (i.e. log_64:4)
- BONUS: Double negative inputs are functional. Decimal inputs are turned into fractions. Any previous answer can be assigned to the 'mem' keyword.

### Also Able To:
- Display killer ASCII art on startup.
- 'ans' can now be placed anywhere in the expression, and an expression can contain multiple ans terms (i.e. ans + ans)
- Simplify mixed expressions containing different number types (i.e. 7+2*e+8*e^(4-3))
- Add, multiply, subtract, and divide expressions (i.e. 3 + 2*pi -1, or 5*(1+e))
- Simplify exponentials with both positive and negative rational exponents
- FOIL expressions (i.e. (e+1)*(e+2), or (e+1)^2)
- Add, multiply, subtract, and divide nthroot irrationals with Integer bases and exponents
- Logarithms simplify completely even with transcendentals and if the base is greater than the value (i.e. log_e:e^3, and log_64:4)
- Fixed: 'ans' variable now stores the previous expression's answer

### Bonus Functionality:
- Double negative input works (i.e. "x--y" and "x-(-y)")
- Evaluate terminating decimals and repeating decimals with 4+ sig figs (i.e. ".2 = 1/5" and ".3333 = 1/3")
- Any previous answer can be assigned to the 'mem' keyword.

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


