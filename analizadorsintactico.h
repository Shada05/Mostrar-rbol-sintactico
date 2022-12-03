#ifndef ANALIZADORSINTACTICO_H
#define ANALIZADORSINTACTICO_H
#define RegExpIf "(\\t*)?if\\((([a-zA-Z]([a-zA-Z]|\\d|_)*)|([+-]?(\\d*[.])?\\d+))(<|>|<=|=>|==|!=|&&|\\|\\|)(([a-zA-Z]([a-zA-Z]|\\d|_)*)|([+-]?(\\d*[.])?\\d+))\\)"
#define RegExpElse "(\\t*)?else"
#define RegExpFor "(\\t*)?for\\((int\\s)?[a-zA-Z]([a-zA-Z]|\\d|_)*=\\d\\;([a-zA-Z]([a-zA-Z]|\\d|_)*)(<|>|<=|=>|==|!=|&&|\\|\\|)(([a-zA-Z]([a-zA-Z]|\\d|_)*)|([+-]?(\\d*[.])?\\d+))\\;[a-zA-Z]([a-zA-Z]|\\d|_)*(\\+\\+|\\-\\-)\\)"
#define RegExpWhile "(\\t*)?while\\(([a-zA-Z]([a-zA-Z]|\\d|_)*)(<|>|<=|=>|==|!=|&&|\\|\\|)(([a-zA-Z]([a-zA-Z]|\\d|_)*)|([+-]?(\\d*[.])?\\d+))\\)"
#define RegExpIniVar "(\\t*)?(int|float|string)\\s[a-zA-Z]([a-zA-Z]|\\d|)*(\\=(([+-]?(\\d[.])?\\d+)|\".*\"|(\\d)))?;"
#define RegExpCout "(\\t*)?cout(<<\"(.)*\"|(<<[a-zA-Z]([a-zA-Z]|\\d|_)*))+;"
#define RegExpCin "(\\t*)?cin>>[a-zA-Z]([a-zA-Z]|\\d|_)*;"
#define RegExpAssign "(\\t*)?[a-zA-Z]([a-zA-Z]|\\d|_)*=(([a-zA-Z]([a-zA-Z]|\\d|_)*)|([+-]?(\\d*[.])?\\d+))[\\+\\-\\*/](([a-zA-Z]([a-zA-Z]|\\d|_)*)|([+-]?(\\d*[.])?\\d+));"
#define RegExpEmpty "(\\t*)?(\\s*)?"
#define RegExpBracketOpen "(\\t*)?(\\s*)?\\{(\\s*)?"
#define RegExpBracketClose "(\\t*)?(\\s*)?\\}(\\s*)?"
#define RegExpDo "(\\t*)?do\\{"
#define RegExpWhileDo "(\\t*)?\\}while(\\(([a-zA-Z]([a-zA-Z]|\\d|_)*)(<|>|<=|=>|==|!=|&&|\\|\\|)(([a-zA-Z]([a-zA-Z]|\\d|_)*)|([+-]?(\\d*[.])?\\d+))\\));"
#include <iostream>
#include <regex>

using namespace std;

class AnalizadorSintactico
{
public:
    AnalizadorSintactico();
    bool sintaxIf(const string &cad);
    bool sintaxElse(const string &cad);
    bool sintaxFor(const string &cad);
    bool sintaxWhile(const string &cad);
    bool sintaxInitialVar(const string &cad);
    bool sintaxCout(const string &cad);
    bool sintaxCin(const string &cad);
    bool sintaxAssign(const string &cad);
    bool emptyLine(const string &cad);
    bool sintaxBracketOpen(const string &cad);
    bool sintaxBracketClose(const string &cad);
    bool sintaxDo(const string &cad);
    bool sintaxWhileDo(const string &cad);
};

#endif // ANALIZADORSINTACTICO_H
