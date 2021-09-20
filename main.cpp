#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using std::cout; using std::string;
using std::ifstream; using std::vector;
using std::ofstream; using std::basic_string;

int main(){
    vector<string> lines;
    string line;


    ofstream f_out; //gera arquivo de saida
    f_out.open("saida.txt");

    if(!f_out.good()){ //verifica se houve erro na criação do arquivo
        printf("Erro ao criar arquivo!");
        exit(1);
    }


    ifstream input_file("teste_macro_z808.txt"); //arquivo de entrada
    input_file.is_open();

    if (!input_file){//testa se houve errro
        printf("Erro na leitura1!\n");
        exit(1);
    }
    

    ofstream temp_macro; //gera arquivo para os dados da macro
    temp_macro.open("macro.txt");

    if(!temp_macro.good()){ //verifica se houve erro na criação do arquivo
        printf("Erro ao criar arquivo!");
        exit(1);
    }


    while (getline(input_file, line) && (line.compare(0,13,"SomaMem MACRO") != 0)){ //copia até a definição da macro
        f_out << line + "\n";
    }

    while(getline(input_file, line) && (line.compare(0,4,"ENDM") != 0)){ //copia os dados da macro pra um arquivo
        temp_macro << line + "\n";
    }
    temp_macro.close();


    while(getline(input_file, line)){//le arquivo linha a linha
        if(line.compare(0,9,"SomaMem V") == 0){ //cada vez que encontrar SomaMem V expande a macro
            char algumacoisa;
            string var1;
            string var2;
            string temp;
            string aux;
            int flag=0;

            for(int i=7;i<line.length();i++){// separa var1 e var2
                temp = line.at(i);
                if((temp != ",") && flag == 0){
                    var1 += line[i];
                }

                else{
                    flag += 1;
                    var2 += line[i];
                }
            }

            int p=0, q=0;

            ifstream dados_macro("macro.txt"); //abre o macro para leitura
            dados_macro.is_open();
            if (!dados_macro){//testa se houve errro, se tiver encerra o programa
                printf("Erro na leitura!\n");
                exit(1);
            }

            vector<string> commandss;
            string commands;

            while(getline(dados_macro, commands)){//le cada linha alterando Mem1 pela primeira variavel e Mem2 pela segunda variavel
                for(int i=0; i<commands.length(); i++){//pega as posições de espaço e virgula
                        if(commands.at(i) == '1'){
                            f_out << var1;//var1;
                        }
                        else if(commands.at(i) == '2'){
                            f_out << var2; //var2;
                        }
                        else if(commands.at(i) == 'M'){
                            i=i+2;
                        }
                        else{
                            f_out << commands.at(i);
                        }
                    }
                    f_out << "\n";

                }
            dados_macro.close();
        }
        else{ //não tem q expandir macro, só copia
            f_out << line + "\n";
        }
    }

    input_file.close();
    f_out.close();
    return EXIT_SUCCESS;
}
