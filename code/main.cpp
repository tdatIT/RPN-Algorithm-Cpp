#include<iostream>
#include<string>

#include"Node.h"
#include "Stack.h"
#include"Queue.h"
#include "ReadFile.h"
#include "InfixToPostfix.h"
#include"RPN.h"

int main(){
    std::string _dataline = readLine();
    Queue* _postfix = infixToPostFix(_dataline);
    _postfix->print();
    _postfix->~Queue();
    std::cout<<std::endl;
    std::cout<<calculatorRPN(_postfix);
    system("pause");
    return 0;
}
