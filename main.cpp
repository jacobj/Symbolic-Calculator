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

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{

    char menuChoice;
    string expression;
    
    cout << "*** Welcome to the Calculator Program! ***\n" << endl;
    
    //this do-while loop represents the main menu
    do
    {
        cout << "\nWhat do you want to do?\n" << endl;
        
        cout << "(1) Help" << endl;
        cout << "(2) Compute a new expression" << endl;
        cout << "(3) Review previous expressions" << endl;
        cout << "(4) Quit" << endl;
        cout << "\nEnter your choice: ";
        
        cin >> menuChoice;
        cout << endl;
        
        switch(menuChoice)
        {
            case '1':
                //this do-while loop represents the help menu
                do
                {
                    cout << "What do you need help with?\n" << endl;

                    cout << "(1) Entering an expression" << endl;
                    cout << "(2) Exponents" << endl;
                    cout << "(3) Square/Nth roots" << endl;
                    cout << "(4) Logarithms" << endl;
                    cout << "(5) Fractions" << endl;
                    cout << "(6) Return to main menu" << endl;
                    cout << "\nEnter your choice: ";
                    
                    cin >> menuChoice;
                    cout << endl;

                    switch(menuChoice) 
                    {
                        case '1':
                            cout << "<Explain entering an expression here>\n" << endl;
                            break;
                        case '2':
                            cout << "<Explain exponents here>\n" << endl;
                            break;
                        case '3':
                            cout << "<Explain square roots and nth roots here>\n" << endl;
                            break;
                        case '4':
                            cout << "<Explain logarithms here>\n" << endl;
                            break;
                        case '5':
                            cout << "<Explain fractions here>\n" << endl;
                            break;
                        case '6':
                            cout << "Returning back to the main menu..." << endl;
                            break;
                        default:
                            cout << "Invalid selection! Choose 1, 2, 3, or 4!\n" << endl;
                    }
                }while(menuChoice != '6');
                
                menuChoice = 1;
                break;
            case '2':
                cout << "Enter your expression: ";
                cin >> expression;
                break;
            case '3':
                cout << "Here are the previous inputs: " << endl;
                break;
            case '4':
                cout << "You chose to quit! Goodbye!" << endl;
                break;
            default:
                cout << "Invalid selection! Choose 1, 2, 3, or 4!\n" << endl;
        }
        
    }while(menuChoice != '4');
    
    return 0;
}