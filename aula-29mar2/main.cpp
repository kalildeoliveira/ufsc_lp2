#include <iostream>
#include <fstream>
#include <vector>
#include <utility>                                          // inclui o pair();
#include <algorithm>                                        // inclui o sort();

using namespace std;
bool ReadFile(string path, string &);

int main()                                                  // in�cio fun��o principal
{
    string filecontent = "";                                // cria e inicializa uma string
    if(!ReadFile("manuscript2.txt", filecontent))           // invoca fun��o para ler arquivo e passar seu conte�do
    {                                                       // para uma string e se houver algum problema retorna
        cout << "error" << endl;                            // uma mensagem de erro.
        return 1;
    }
    cout << "File is: " << filecontent << endl;             // imprime o conte�do da string

    vector< pair<char, size_t> > chcounter;                 // cria vetor de pares com o nome "chcounter" - contador de char
    for(size_t i=0; i<256; i++)                             // Loop para inicializar o vetor de pares
    {
        pair<char, size_t> newpair;                         // cria um par chamado newpair
        newpair.first = i;                                  // o primeiro par recebe "i" em cada itera��o
        newpair.second = 0;                                 // o segundo par recebe "0" em cada itera��o
        chcounter.push_back(newpair);                       // o vetor acumula uma altera��o do pair a cada itera��o
    }

    for(size_t i=0; i<filecontent.size(); i++)              // Loop que varre a string com o conte�do do texto
    {
        char ch = filecontent.at(i);                        // Cria char ch e armazena um caracter a cada itera��o
        chcounter.at(ch).second++;                          // o segundo par � incrementando em 1 a cada itera��o
    }

    sort(chcounter.begin(),                                 // sort() ordena o segundo par do vetor de pares
         chcounter.end(),                                   // https://stackoverflow.com/questions/26844983/sort-a-pair-vector-in-c
         [](const auto& x, const auto& y){return x.second > y.second;});

    for(size_t j=0; j<chcounter.size(); j++)                // Loop que varre o vetor de pares pelo tamanho dele
    {
        if (chcounter.at(j).second !=0) {                   // elimina os nulos
                if (chcounter.at(j).second )
            cout << "Character: " << chcounter.at(j).first <<   // imprime o primeiro par no formato char
            " Id ASCII: " << (int) chcounter.at(j).first <<     // imprime o primeiro par convertido para inteiro
            " -> Counts: " << chcounter.at(j).second << endl;   // imprime o segundo par com a contagem
        }
    }

    //eliminar todas as ocorrencias de caracteres nulos     - verificar se chcount==0 na hora de imprimir
    //ordenar em ordem decrescente                          - usando sort();
    //std::sort std::stable_sort                            - vamos pesquisar a documenta��o!

    return 0;
}

bool ReadFile(string path, string &content) {
    ifstream FileReader(path.c_str());
    if(FileReader.is_open() == false)
        return false;

    string tmp;
    while(getline(FileReader, tmp))
    {
        content += tmp;
    }

    FileReader.close();
    return true;
}
