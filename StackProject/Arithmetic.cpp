/** Requests an arithmetic expression from the end user and passes
 *     the string to the eval function.  The eval function evaluates
 *     the arithmetic expression, returning the result to the main.
 *     Input expressions are expected to be in proper inorder form.
 *
 * @file Arithmetic.cpp
 * @author YOUR NAME           
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include "ArrayStack.h"
#include <string>

float eval(std::string expr);
bool isHigher(char currOpr, char topOpr);
float calculate(char topOpr, float operand1, float operand2);


// The following main function should not be modified
int main(void) {
    std::string expression = "Continue";

    do {
        std::cout << "Enter an arithmetic expression on a single line ('q' to end): ";
        getline(std::cin, expression);
        if (expression[0] != 'q') {
            float result = eval(expression);
            std::cout << expression << " = " << result << std::endl;
        }
    } while (expression[0] != 'q');

    return 0;
}

/*
 * Returns the result of a given expression
 * @param expr - the expression to be evaluated
 * @return the result of the expression
 */
float eval(std::string expr) 
{  // To be implemented
   // Any number of support functions may also be added
//	std::cout << "eval function not implemented" << std::endl;
        float num1;
        float num2;
        float result;
        float castNum;
        
        char currOpr;
        char topOpr;
        
        int exprLength = expr.size(); 
        int parenStart;
        int parenEnd;
        int insideParenLength;
        std::string inParen;
        
        ArrayStack<float> numberStack;
        ArrayStack<char> operatorStack;
        
        for(int i = 0; i < expr.size(); i++){
            if(expr[i] == '(') {    //check for precedence of parentheses
                
                parenStart = expr.find('(');
                parenEnd = expr.find(')');
                insideParenLength = parenEnd - (parenStart + 1);
                inParen = expr.substr(parenStart + 1, insideParenLength);
                expr.replace(parenStart, insideParenLength + 2, " ");
//                std::cout << inParen << " " << expr;
                result = eval(inParen);
                numberStack.push(result);
                
            }
            else if(isdigit(expr[i])){  //check whether the char is a digit or not
                castNum = expr[i] - '0';
                numberStack.push(castNum);
            } 
            else { 
                currOpr = expr[i];
                if(operatorStack.isEmpty()){    //adds first operator to operator stack
                    operatorStack.push(currOpr);
                }
                else if (isHigher(currOpr, operatorStack.peek())){  //checks the precedence of the current operator
                    operatorStack.push(currOpr);
                }
                else{   //does operation of higher precedence
                    num1 = numberStack.peek();
                    numberStack.pop();
                    num2 = numberStack.peek();
                    numberStack.pop();
                    topOpr = operatorStack.peek();
                    operatorStack.pop();
                    result = calculate(topOpr, num1, num2);
                    numberStack.push(result);
                    operatorStack.push(currOpr);
                }
            }
        }
        
        //Does all lower precedence operations remaining
        while(!operatorStack.isEmpty()){
            num1 = numberStack.peek();
            numberStack.pop();
            num2 = numberStack.peek();
            numberStack.pop();
            topOpr = operatorStack.peek();
            operatorStack.pop();
            result = calculate(topOpr, num1, num2);
            numberStack.push(result);
        }
        
        return numberStack.peek();
        
}


/*
 * Determines whether an operator has precedence over another
 * @param currOpr - the operator to determine order of precedence for
 * @param topOpr - the operator to compare to
 * @returns whether the currOpr has precedence over the topOpr
 */
bool isHigher(char currOpr, char topOpr){
    bool hasPrec = false;
    
    if(currOpr == '^'){
        hasPrec = true;
    } 
    else if ((currOpr == '*' || currOpr == '/') && (topOpr == '+' || topOpr == '-')){
        hasPrec = true;
    } 
    return hasPrec;
}


/* Does a calculation given an arithmetic operator
 * @param topOpr - the arithmetic operator to use
 * @param operand1 - the first operand
 * @param operand2 - the second operand
 * @returns the result of the arithmetic operation
 */
float calculate(char topOpr, float operand1, float operand2){
    float result;
    
    switch(topOpr)
    {
        case('^') :     result = pow(operand2, operand1);
                        break;
        case('*') :     result = operand2 * operand1;
                        break;
        case('/') :     result = operand2 / operand1;
                        break;
        case('+') :     result = operand2 + operand1;
                        break;
        case('-') :     result = operand2 - operand1;
                        break;
    }
    
    return result;
}