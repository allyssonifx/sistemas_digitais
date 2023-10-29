#include <iostream>
#include <string>

//Tipo estruturado que vai quardar o url e uma variavel do tipo ponteiro que aponta para o proximo No
struct Node{
    std::string pagina;
    Node* proximo;
};

//Funcao para criar um novo No e inserir ele no historico ou na fila de salvos
Node* list_insert(Node* posicao, std::string pagina){

    //Criacao de um novo No e preenchimento do campo pagina desse No
    Node* temp = new Node();
    temp->pagina = pagina;

    //Fazendo com que o ponteiro do novo No aponte para o mesmo No que o outro ponteiro de outro No
    temp->proximo = posicao->proximo;

    //Fazendo com que o ponteiro desse outro No aponte para o novo No
    posicao->proximo = temp;

    //Retornando o outro No, com as suas modificacoes
    return posicao;
}

//Funcao para apagar um No do historico ou da fila de salvos, que recebera o head da pilha ou fila
Node* list_delete(Node* posicao){

    //Criando um novo No temporario que vai ter as informacoes do No que queremos deletar
    Node* temp = posicao->proximo;

    //Ligamos o No que estava 'atras' do No que deletaremos ao No que estava na 'frente' do deletado
    posicao->proximo = temp->proximo;

    //Campo pagina do head vai receber o campo pagina do No deletado
    posicao->pagina = temp->pagina;

    //Deletamos o No
    delete temp;

    //Retornamos o head atualizado
    return posicao;
}

//Funcao para o comando SAV, ira salvar a pagina atual
Node* SAV(Node* head, Node* tail, std::string valor){

    //Criando um No local e usando a funcao list_insert para configurar esse No
    Node* temp = list_insert(tail, valor);

    //Retornando o head e o campo proximo do No local
    return head, temp->proximo;
}

//Funcao para o comando REA, ira ler a primeira pagina salva e retirar da fila de salvos
Node* REA(Node* head, Node* tail){

    //Usando a funcao list_delete para excluir o primeiro No e atualizar o head da fila
    head = list_delete(head);

    //Caso a fila esteja vazia
    if(head->proximo == NULL){
        tail = head;
    }

    //Retornando head e tail atualizado
    return head, tail;
}

//Funcao para o comando PAN, apaga todos os Nos que fazem parte do historico
Node* PAN(Node* head){

    //Usando list_delete para apagar o No mais recente
    head = list_delete(head);

    //Caso a pilha ainda nao esteja vazia
    if (head->proximo != NULL){

        //Chamamos a funcao PAN novamente
        PAN(head);
    }

    //Retornando o head atualizado, que vai ter o campo proximo vazio
    return head;
}


//Funcao Main
int main(int argc, char const *argv[])
{
    //Criando o head da pilha
    Node* head_historico = new Node();

    //Criando o head e o tail da fila
    Node* head_salvos = new Node();
    Node* tail_salvos = new Node();
    tail_salvos = head_salvos;

    //String que vai pegar o comando digitado
    std::string comando = "";
    //String que ira pegar o url digitado ao usar o comando OPN
    std::string url = "";

    //Contador para saber quantas paginas estao no historico
    int contador_historico = 0;
    //Contador para saber quantas paginas foram salvas
    int contador_salvos = 0;

    //Loop para pegar e realizar os comandos
    while(comando != "END"){

        //Recebendo o comando
        std::cin >> comando;

        //Caso o comando seja OPN
        if(comando == "OPN"){
            //Recebendo o pagina digitado
            std::cin >> url;

            //Chamando a funcao list_insert para criar um novo No e atualizar o head_historico
            head_historico = list_insert(head_historico, url);

            //Incrementando o contador_historico em um e imprimindo a quantidade de paginas no historico
            contador_historico++;
            std::cout << contador_historico << "\n";
        }

        //Caso o comando seja CUR
        else if(comando == "CUR"){
            //Imprimindo na tela o pagina mais recente
            std::cout << url << "\n";
        }

        //Caso o comando seja BCK
        else if(comando == "BCK"){
            
            //Caso a pilha nao esteja vazia
            if(head_historico->proximo != NULL){

                //Chamando a funcao list_delete para excluir o No mais recente e atualizar o head_historico
                head_historico = list_delete(head_historico);
                
                //Caso a pilha nao esteja vazia depois de excluir um elemento
                if(head_historico->proximo != NULL){
                    //Url recebe o pagina que vai ser a pagina corrente
                    url = head_historico->proximo->pagina;

                    //Imprimindo qual eh a pagina corrente
                    std::cout << url << "\n";
                }

                //Caso a pilha esteja vazia depois de excluir um elemento
                else{
                    //Imprimimos 'NULL'
                    std::cout << "NULL\n";
                }

                //Decrementando o comtador_historico, pois excluimos 1 pagina do historico
                contador_historico--;
                
            }

            //Caso a pilha ja estivesse vazia
            else{
                //Imprimimos 'NULL'
                std::cout << "NULL\n";
            }

        }

        //Caso o comando seja PAN
        else if(comando == "PAN" ){

            //Caso a pilha/historico nao esteja vazia
            if(contador_historico > 0) {
                //Chamamos a funcao PAN para excluir tudo da pilha e atualizar o head_historico
                head_historico = PAN(head_historico);
            }

            //Imprimindo a quantidade de paginas que existiam, visto que eh a quantidade de paginas excluidas
            std::cout << contador_historico << "\n";

            //Dizendo que o contador_historico eh 0, pois excluimos as paginas do historico
            contador_historico = 0;
        }

        //Caso o comando seja SAV
        else if(comando == "SAV"){
            
            //Chamando funcao SAV para criar novo No na fila e atualizar head e tail salvos
            head_salvos, tail_salvos = SAV(head_salvos, tail_salvos, url);

            //Incrementado contador_salvos em 1
            contador_salvos++;

            //Imprimindo a quantidade de paginas salvas
            std::cout << contador_salvos << "\n";
        }

        //Caso o comando seja REA
        else if(comando == "REA"){

            //Caso a fila nao esteja vazia
            if(head_salvos->proximo != NULL) {
                //Chamando a funcao REA para deletar o No mais antigo e atualizar o head e tail salvos
                head_salvos, tail_salvos = REA(head_salvos, tail_salvos);

                //Decrementando o contador_salvos em 1
                contador_salvos--;

                //Imprimindo o nome do pagina lido
                std::cout << head_salvos->pagina << "\n";
            }
            
            //Caso a fila esteja vazia
            else{
                std::cout << "NULL\n";
            }
        }
    }

    //Deletando os ponteiros que formam o historico
    PAN(head_historico);
    delete head_historico;
    
    //Deletando os ponteiros que formam os salvos
    while(head_salvos != tail_salvos){
        head_salvos, tail_salvos = REA(head_salvos, tail_salvos);
    }
    delete head_salvos;

    return 0;
}