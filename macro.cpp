#include <stdio.h>
#include <iostream>
#include <string.h> 
#include <fstream> //manipulaçao de arquivo
#include <vector>

using namespace std;

string nome = "teste_macro_z808.txt";

int main(){
      ifstream arquivoTeste;//abrir para leitura
      arquivoTeste.open(nome);

      ofstream fout("a:teste1.txt");  // Cria arquivo para gravação 

      if (!arquivoTeste){//testa se houve errro, se tiver encerra o programa
            printf("Erro na leitura!\n");
            exit(1);
      }

  
      //....

  
      arquivoTeste.close();

      return 0;
}


//////---------------------------------
    vector<string> lines;
    string line;

    while (getline(input_file, line)){ //le linha a linha
        lines.push_back(line);
    }

    while (getline(input_file, line) && (line.compare(0,7,"SomaMem") != 0)){ //le até encontrar SomaMen
        lines.push_back(line);
    }

    for (const auto &i : lines)
        cout << i << endl;



//------ funcionou essa parte
#include <iostream>
#include <fstream>
#include <vector>

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;
using std::ofstream;

int main(){
    string filename("file.txt");
    vector<string> lines;
    string line;
    
    
    ofstream f_out; //gera Arquivo de saida
    f_out.open("teste.txt");

    if(! f_out.good()){ //verifica se houve erro na criação do arquivo
        printf("Erro ao criar arquivo!");
        exit(1);
    }
    

    ifstream input_file(filename);
    input_file.is_open();


    while (getline(input_file, line) && (line.compare(0,13,"SomaMem MACRO") != 0)){
        f_out << line + "\n";
    }

    for (const auto &i : lines)
        cout << i << endl;

    input_file.close();
    return EXIT_SUCCESS;
}
