/* 
 * File:        main.cpp
 * 
 * Authors:     Brent Lewis
 *              Jacob Jenkins
 *              Shreya Nirmalan
 *              Nicola Frachesen
 *              Elaine Del Rosario
 * 
 * 
 */
#include "Calculator.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Calculator calculator;
    vector<string> previousExpressions;
    vector<string> previousAnswers;
    char mainMenu, reviewMenu, helpMenu;
    bool keepGoing, proceed;
    string expr;
    string ans;
    string previous, choice;
    
    cout << "*** Welcome to the Calculator Program! ***\n" << endl;
    
    //this do-while loop represents the main menu
    do
        {
            cout << "\nWhat do you want to do?\n" << endl;
        
            cout << "(1) Compute a new expression." << endl;
            cout << "(2) Review previous expressions and answers." << endl;
            cout << "(3) Help." << endl;
            cout << "(4) Quit." << endl;
            cout << "\nEnter your choice: ";
        
            cin >> mainMenu;
            cin.ignore();
            cout << endl;
        
            switch(mainMenu)
                {
                case '1':
                    keepGoing = true;
                    while(keepGoing)
                        {
                            cout << "\nEnter your expression: ";
                            getline(cin, expr);
                            if(expr == "back" || expr == "quit")
                                keepGoing = false;
                            else
                                {
                                    calculator.addInput(expr);
                                    calculator.calculate();
                                    cout << "\nAnswer: " << endl;
                                }
                        }
                    break;
                case '2':
                    previousExpressions = calculator.getPreviousInputs();
            	
                    if(previousExpressions.size() == 0)
                        cout << "There are no previous expressions!" << endl;
            	
                    else{
                        //this do-while loop is for the user to access previous answers and expressions 
                        do
                            {
                                cout << "\nWould you like to view previous expressions or answers?\n" << endl;

                                cout << "(1) View previous expressions." << endl;
                                cout << "(2) View previous answers." << endl;
                                cout << "(3) Convert a previous answer to a decimal." << endl;
                                cout << "(4) Store a previous answer into the 'ans' variable." << endl;
                                cout << "(5) Return to Main Menu" << endl;
                                cout << "\nEnter your choice: ";

                                cin >> reviewMenu;
                                cin.ignore();
                                cout << endl;

                                switch (reviewMenu)
                                    {
                                    case '1':
                                        cout << "\nHere are the previous expressions: \n" << endl;
                                        for(int i = 0;i<previousExpressions.size();i++)
                                            {
                                                cout << "Expression " << (i+1) << ": "
                                                     << previousExpressions[i] << "\n" 
                                                     << endl;;
                                            }
                                        break;
                                    case '2':
                                        cout << "\nHere are the previous answers: " << endl;
                                        break;
                                    case '3':
                                        do
                                            {
                                                cout << "\nIndicate the answer you wish to convert (Enter ""1"" for the first answer, etc.): " ;
                                                cin >> previous;
							
                                                cout << "\nHere is the floating point form: " << endl;
                                                cout << "\nContinue? (Y/N) ";
                                                cin >> choice;
							
                                                if(choice == "Y" || choice == "y")
                                                    {
                                                        proceed = true;
                                                    }
                                                else if(choice == "N" || choice == "n")
                                                    {
                                                        proceed = false;
                                                    }
                                            }while (proceed); //end while
                                        break;
                                    case '4':
                                        cout << "\nIndicate the answer you wish to store in the 'ans' variable "
                                             << "(Enter ""1"" for the first answer, etc.): " ;
                                        cin >> previous;
								
                                        //update this
                                        ans = "";
								
                                        cout << "\nans = " << endl;
                                        break;
                                    case '5':
                                        cout << "Returning back to the main menu..." << endl;
                                        break;
                                    default:
                                        cout << " Invalid selection! Please choose 1, 2, 3 or 4.\n" << endl;
                                    }
                            }while(reviewMenu != '5'); //end while
                    }
                    break;
                case '3':
                    //this do-while loop represents the help menu
                    do
                        {
                            cout << "What do you need help with?\n" << endl;

                            cout << "(1) Entering an expression" << endl;
                            cout << "(2) Exponents" << endl;
                            cout << "(3) Square/Nth roots" << endl;
                            cout << "(4) Logarithms" << endl;
                            cout << "(5) Fractions" << endl;
                            cout << "(6) How your answer will be displayed" << endl;
                            cout << "(7) Return to main menu" << endl;
                            cout << "\nEnter your choice: ";
                    
                            cin >> helpMenu;
                            cin.ignore();
                            cout << endl;

                            switch(helpMenu) 
                                {
                                case '1':
                                    cout << "To enter your expression, type in your first value followed by an operator, and then your second value. \n Ex: 4*5 \t (3 + 5) / 2 \nApproved Operators: +, -, *, /, ^ \nTranscedental Numbers: PI/pi, e \n" << endl;
                                    break;
                                case '2':
                                    cout << "To write out an exponent, use the ^ key and the following format: a^x \nThis will be read as 'a raised to the power of x', where a and x are replaced by your chosen coefficients. \n" << endl;
                                    break;
                                case '3':
                                    cout << "To write out a square root or nth root, use the following format: sqrt:x for a square root and x^(1/n) for an nth root. \nThis will read as 'the square root of x' or 'the nth root of x', where x is the coefficient \nyou wish to take the root of. \n" << endl;
                                    break;
                                case '4':
                                    cout << "To write out a logarithm, use the following format: log_b:x \nThis will read as 'log base b of x', where b and x are replaced by your chosen coefficients. \n" << endl;
                                    break;
                                case '5':
                                    cout << "To write out a fraction, use the following formats: a/b \nWhere a and b are replaced by your chosen coeffiecients. If you wish to write expressions for the numerator, \ndenominator, or both, then use the following format: (a+b)/(c*d) \nWhere a, b, c, and d are your given coefficients and you can use any of the approved operators in your expressions. \nRemember to enclose your expressions before and after the / in () ! \n" << endl;
                                    break;
                                case '6':
                                    cout << "Please keep in mind that your answers will be returned in their simplest forms as \nintegers (i.e. 2 + 2 = 4), fractions (i.e. 2/6 = 1/3), logarithms (i.e. log_10:6 = log_10:2 + log_10:3), \n or expressions (i.e. 2 + 2 + pi^2 = 4 + pi^2). /nIf you wish to receive decimal answers, please go to the main menu and press 2 to review previous answers. \nFrom here, you can also set previous answers to the ans keyword. \n" << endl;
                                    break;
                                case '7':
                                    cout << "Returning back to the main menu..." << endl;
                                    break;
                                default:
                                    cout << "Invalid selection! Choose 1, 2, 3, 4, 5, 6, or 7.\n" << endl;
                                }
                        }while(helpMenu != '7');
                    break;
                case '4':
                    break;
                default:
                    cout << "Invalid selection! Choose 1, 2, 3, or 4!\n" << endl;
                }
        
        }while(mainMenu != '4' && expr != "quit");
    
    return 0;
}
