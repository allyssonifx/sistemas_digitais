#include<iostream>
using namespace std; 

class Node{ //Classe do no, que vai ser um "array" do Dicionário
    public:
        bool ocup = false; // Variável se ta ocupada ou não, que por padão já vem setada em false
        string name; // O Que tá escrito

    Node(){
        ocup = false; // Nem precisaa mas é só pra criar msm
    }
    void insert(int key, string texto){// Função pra inserir
        name = texto;
        ocup = true;
    }

};

class Dictionary{ // Classe do Dicionário
    private:
        int size; // Tamanho Máximo
        int cnt; // Tamanho Atual
        Node *nos; // Ponteiro pros nós 
    public:
        Dictionary(int tam){
            size = tam; // O tamanho recebe o valor máximo de casas
            nos = new Node[101]; // "Array" de Nodes
            for(int i = 0; i < tam; i++){
                nos[i].ocup = false; // Crio o array e ponho o valor de ocupado como falso
            }
            cnt = 0; // inicio o contador como 0
        }

        void insert(string tex){ // Função de Inserir
            int chave = hashconv(tex); // obtenho a chave pela função hashconv, que retorna o valor da chave a partir da soma dos n caracteres
            int *hashmap = new int[20]; // Crio um array de elementos para inserir neles o valor das novas chaves possíveis
            bool inserir = true; // Variável pra identificar e posso inserir ou não
            hashmap[0] = chave; // O primeiro elemento recebe o valor da chave obtida
            if (nos[chave].ocup== true && nos[hashmap[0]].name == tex){
                inserir = false; // Se o nó estiver ocupado e já possui essa string na primeira posição, não va para a funçao de inserir
            }

            for (int i = 1; i <20; i++){ 
                hashmap[i] = (chave + i*i + 23*i)%101; // Insiro o  valor obtido pela função de dispersão do enunciado a partir do 2 elemento
                if (nos[hashmap[i]].ocup== true && nos[hashmap[i]].name == tex){  ///->Retirar a primeira condicional<-///
                    inserir = false; // Se alguma posição estiver acupada e possuir o mesmo texto ele não vai inserir
                }
            }

            if (inserir){ // Se o inserir n ficou falso, quer dizer que nenhuma das chaves está ocupada 
            for (int i = 0; i < 20; i++){
                if (nos[hashmap[i]].ocup== false && nos[hashmap[i]].name != tex){ // Se a posição está vazia e o seu texto for diferente do que eue quero inseir:
                    nos[hashmap[i]].insert(hashmap[i], tex); // Insiro nesse no o conteudo
                    cnt++; // Aumeento o contador
                    break; // Quebro o laço
                }
            }
            }
        }

        void remove(string tex){ // Fnção para remover
            int chave = hashconv(tex); // Recebo a chave dele 
            int *hashmap = new int[20]; // Crio um array de elementos para inserir neles o valor das novas chaves possíveis
            hashmap[0] = chave; // O primeiro elemento recebe a chave
            for (int i = 1; i <20; i++){ // Os demais recebem os valores possíveis //-> Possivel erro, ter um mod com repetição, talve interfira
                hashmap[i] = (chave + i*i + 23*i)%101; // Cada elemento recebe o valor de uma possível nova chave
            }

            for (int i = 0; i < 20; i++){
                if (nos[hashmap[i]].ocup== true && nos[hashmap[i]].name == tex){ // Se o nó está ocupado e nele está o testo que eu quero remover
                    nos[hashmap[i]].ocup = false; // ela não está ocupada
                    nos[hashmap[i]].name = ""; // Sua string se torna 0
                    cnt--;
                    break;
                }
            }
        }

        void showtable(){
            cout<< cnt << endl; // Sai o tamanho  da lista
            for (int i=0; i<size; i++){
                if (nos[i].ocup){ // Se o no na posição i esta ocupado: 
                    cout << i << ":" << nos[i].name << endl; // print a chave,:,string 
                }
            }
        }
        int hashconv(string letter){ // função para converssão
            int soma = 0; // valor da soma da letter
            int tamanho = letter.length() +1; // o tamanho recebe +1 pq temos que fazer o calculo a partir do elemento 1 até o 19 ///-> Será um erro que é para ter menos chaves?
            for (int i = 1; i < tamanho; i++){ 
                char x = letter.at(i-1); // x recebe o caracter da posição da letra -1(ja que se inicia do zero)
                soma = soma +int(x) * i; // soma = soma + valor ASCII de x multiplicado pelo i, como tá na fórmula lá
            }
            int hash = (soma*19) % 101; // multiplico por 19 e faço o mod de 101
            return abs(hash); // Retoro a valor absoluto da soma
            }

        
};

int main(){

    int cases; 
    cin >> cases; //Recebo a qnt de testes
    for (int i=0; i < cases; i++){ 
        int operations;
        cin >> operations; // Recebo quantas operações podem ser feitas
        Dictionary dic = Dictionary(101); // crio a variável dic e ponto o tamano maximo do Dicionário como 101
        for (int j=0; j < operations; j++){
            string input;
            cin >> input; // Recebo a string
            string command = "";
            string object = "";
            for (int k=0; k < input.length(); k++){
                if (k < 4){
                    command = command + input[k];//Pego os 4 primeiros elementos, no caso DEL: ou ADD:
                } else{
                    object = object + input[k];// Pego as outras entradas
                }
            }
            if (command == "ADD:"){
                dic.insert(object);//Se o camando for inserir vá para a função de inserir com o elemento obtido
            } else if (command == "DEL:"){
                dic.remove(object); // Caso o camando seja para remover, vá para a função de remorção
            }
                
            }
            dic.showtable();// Mostre a tabela após concluir as operações do caso n
        }
    return 0; // Saia da função
}