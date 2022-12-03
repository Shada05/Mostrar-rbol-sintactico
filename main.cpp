#include <iostream>
#include <fstream>
#include "analizadorsintactico.h"

using namespace std;

int main()
{

    AnalizadorSintactico AS;
    string codeName, lineCode, lineBefore="", lineBeBefor="";
    fstream code(codeName);
    int cont=1, contLlaves=0, contDo=0;
    bool open=false;
    bool noneError=true;
    do{
        cout<<"\n+-----------------------------------------------+"<<endl
            <<"|             ANALIZADOR SINTACTICO             |"<<endl
            <<"+-----------------------------------------------+"<<endl
            <<"|Escriba el nombre del archivo y su extension:   "<<endl
            <<"|_______________________________________________|"<<endl;
        getline(cin, codeName);
        code.open(codeName, ios::in);
        if(code.good())
            open=true;
        else{
            cout<<"El archivo no se encontro, intente de nuevo"<<endl;
            system("Pause");
        }
    }while(!open);
    cout<<"Archivo encontrado"<<endl;

    while(!code.eof())
    {
        getline(code, lineCode,'\n');
        cout<<cont<<"\t"<<lineCode<<endl;
        ++cont;
    }
    cont=1;
    code.close();

    code.open(codeName, ios::in);

    while(!code.eof())
    {
        bool error;
        getline(code, lineCode,'\n');
        if(AS.sintaxAssign(lineCode))
            error=false;
        else
            if(AS.sintaxCin(lineCode))
            error=false;
            else
                if(AS.sintaxCout(lineCode))
                    error=false;
                else
                    if(AS.sintaxFor(lineCode))
                        error=false;
                    else
                        if(AS.sintaxIf(lineCode))
                        {
                            error=false;
                        }
                        else
                            if(AS.sintaxElse(lineCode))
                            {
                                if(AS.sintaxBracketClose(lineBefore)||AS.sintaxIf(lineBeBefor))
                                {
                                    error=false;
                                }
                                else
                                {
                                    cout<<"Instruccion else incorrecta, revisar if . ";
                                    error=true;
                                }
                            }
                            else
                                if(AS.sintaxInitialVar(lineCode))
                                    error=false;
                                else
                                    if(AS.sintaxWhile(lineCode))
                                        error=false;
                                    else
                                        if(AS.emptyLine(lineCode))
                                            error=false;
                                        else
                                            if(AS.sintaxBracketOpen(lineCode))
                                            {
                                                if(AS.sintaxIf(lineBefore)||AS.sintaxFor(lineBefore)||AS.sintaxWhile(lineBefore)||AS.sintaxElse(lineBefore))
                                                {
                                                    error=false;
                                                    ++contLlaves;
                                                }
                                                else
                                                {
                                                    cout<<"Apertura de llaves incorrecta. ";
                                                    error=true;
                                                }
                                            }
                                            else
                                                if(AS.sintaxBracketClose(lineCode))
                                                {
                                                    --contLlaves;
                                                    if(contLlaves<0)
                                                    {
                                                        cout<<"Incorrecto, revisar las llaves. ";
                                                        error=true;
                                                        contLlaves=0;
                                                    }
                                                    else
                                                        error=false;
                                                }
                                                else
                                                    if(AS.sintaxDo(lineCode))
                                                    {
                                                        error=false;
                                                        ++contDo;
                                                    }
                                                    else
                                                        if(AS.sintaxWhileDo(lineCode))
                                                        {
                                                            --contDo;
                                                            if(contDo<0)
                                                            {
                                                                cout<<"Instruccion while necesita colocar un do para funcionar. ";
                                                                error=true;
                                                                contDo=0;
                                                            }
                                                            else
                                                            {
                                                                error=false;
                                                            }
                                                        }
                                                        else
                                                            error=true;

        lineBeBefor=lineBefore;
        lineBefore=lineCode;

        if(error)
        {
            cout<<"Error en la linea "<<cont<<endl;
            noneError=false;
        }
        ++cont;
    }

    if(contLlaves!=0)
        cout<<"Error, se necesita '}'"<<endl;
    else
        if(contDo!=0)
            cout<<"Error, la sentencia do necesita un while"<<endl;
        else
            if(noneError)
                cout<<"Sintaxis correcta!"<<endl;

    code.close();
    return 0;
}
