#include <iostream>
#include <fstream>
#include <vector>

using std::cout; using std::string;
using std::ifstream; using std::vector;
using std::ofstream; using std::basic_string;

string nome = "teste_macro_z808.txt";

int main(){
    string filename("file.txt");
    vector<string> lines;
    string line;
    
    ofstream f_out; //gera Arquivo de saida
    f_out.open("teste.txt");

    if(!f_out.good()){ //verifica se houve erro na criação do arquivo
        printf("Erro ao criar arquivo!");
        exit(1);
    }

    ifstream input_file(filename);
    input_file.is_open();
    
    if (!input_file){//testa se houve errro, se tiver encerra o programa
        printf("Erro na leitura!\n");
        exit(1);
    }
    
    
    ofstream temp_macro; //gera Arquivo de saida
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
    

    string dados("macro.txt");
    
    while(getline(input_file, line)){//le tudo linha a linha
        if(line.compare(0,9,"SomaMem V") == 0){ //cada vez q tiver somaMen V expande a macro
            char algumacoisa;
            int espaco;
            int virgulina;
            string var1;
            string var2;
            int p=0, q=0;
        
            //pega as variaveis
            for(int i=0; i<line.length(); i++){//pega as posições de espaço e virgula
                algumacoisa = line.at(i);
                if(algumacoisa == ' '){
                    espaco= i;
                }
                if(algumacoisa == ','){
                    virgulina = i;
                }
            }
            
            for(int i=espaco + 1; i<virgulina; i++){//variavel1
                var1[p] = line.at(i);
                p++;
            }
            var1[p] = '\0';

            for(int i=virgulina + 1; i<line.length(); i++){//variavel2
                var2[q] << line.at(i);
                q++;
            }
            var2[q]='\0';

            ifstream dados_macro(dados); //abre o macro para leitura
            dados_macro.is_open();
            if (!dados_macro){//testa se houve errro, se tiver encerra o programa
                printf("Erro na leitura!\n");
                exit(1);
            }
            
              
              
            //FALTA EXPANDIR A MACRO, SUBSTITUINDO Mem1 E Mem2 PELO NOME DA VARIAVEL
              
            //while(){//le cada linha alterando Mem1 pela primeira variavel e Mem2 pela segunda variavel
            
                
            //}
        }
        else{ //não tem q expandir macro, só copia
            f_out << line + "\n";
        }
    }
    
    

    input_file.close();
    return EXIT_SUCCESS;
}
