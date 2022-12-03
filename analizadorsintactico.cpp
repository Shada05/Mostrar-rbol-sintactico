#include "analizadorsintactico.h"

AnalizadorSintactico::AnalizadorSintactico()
{

}

bool AnalizadorSintactico::sintaxIf(const string &cad)
{
    regex instruction(RegExpIf);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxElse(const string &cad)
{
    regex instruction(RegExpElse);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxFor(const string &cad)
{
    regex instruction(RegExpFor);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxWhile(const string &cad)
{
    regex instruction(RegExpWhile);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxInitialVar(const string &cad)
{
    regex instruction(RegExpIniVar);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxCout(const string &cad)
{
    regex instruction(RegExpCout);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxCin(const string &cad)
{
    regex instruction(RegExpCin);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxAssign(const string &cad)
{
    regex instruction(RegExpAssign);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::emptyLine(const string &cad)
{
    regex instruction(RegExpEmpty);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxBracketOpen(const string &cad)
{
    regex instruction(RegExpBracketOpen);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxBracketClose(const string &cad)
{
    regex instruction(RegExpBracketClose);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxDo(const string &cad)
{
    regex instruction(RegExpDo);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}

bool AnalizadorSintactico::sintaxWhileDo(const string &cad)
{
    regex instruction(RegExpWhileDo);
    if(regex_match(cad, instruction))
        return true;
    else
        return false;
}
