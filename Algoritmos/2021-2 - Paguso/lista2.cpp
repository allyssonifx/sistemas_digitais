#include <iostream>
#include <string>

int andar;

void Printar(int andar_ocupado, int jazido_ocupado){
    if(jazido_ocupado == -1){
        std::cout << "?.?" << "\n";
    }

    else{
        std::cout << andar_ocupado << "." << jazido_ocupado << "\n";
    }
}

int BinarySearch(int V[], int superior, int inferior, int m, int numero){
    
    if(V[m] == numero){
        return m;
    }

    else if(inferior > superior){
        return -1;
    }

    else if ( numero < abs(V[m])){
        return BinarySearch(V, m - 1, 0, int((superior + inferior)/2), numero);
    }

    else{
        return BinarySearch(V, superior, m + 1, int((superior + inferior)/2), numero);
    }
   
}

int QRY(int** Cemiterio, int andar, int jazido, int numero, int* andar_ocupado){
    int jazido_ocupado = -1;
    for(int i = numero % andar; i<andar;i++){
        jazido_ocupado = BinarySearch(Cemiterio[i], Cemiterio[i][jazido + 1] - 1, 0, (Cemiterio[i][jazido + 1] - 1)/2, numero);

        if(jazido_ocupado != -1){
            *andar_ocupado = i;
            return jazido_ocupado;
        }

        else if(Cemiterio[i][jazido + 1] < jazido){
            *andar_ocupado = -1;
            return -1;
        }
    }

    if(jazido_ocupado == -1){    
        for(int j = 0; j < numero % andar; j++){
            jazido_ocupado = BinarySearch(Cemiterio[j], Cemiterio[j][jazido + 1] - 1, 0, (Cemiterio[j][jazido + 1] - 1)/2, numero);

            if(jazido_ocupado != -1){
                *andar_ocupado = j;
                return jazido_ocupado;
            }

            else if(Cemiterio[j][jazido + 1] < jazido){
                *andar_ocupado = -1;
                return -1;
            }
        }
    }
    
    *andar_ocupado = -1;
    return -1;
}

int Ordenar(int Vetor[], int superior, int inferior, int numero, int jazido){
    int metade;

    while(inferior <= superior && Vetor[jazido] != 0){
        metade = int((inferior + superior)/2);
        if(abs(numero) > abs(Vetor[metade])){
            inferior = metade + 1;
        }
        else{
            superior = metade - 1;
        }
    }

    for(int i = Vetor[jazido] - 1; i >= inferior; i--){
        Vetor[i + 1] = Vetor[i];
    }

    Vetor[inferior] = numero;
    return inferior;
}

int** ADD(int** Cemiterio, int jazido, int numero, int printar){
    int fim = 0;
    int andar_ocupado = -1;
    int jazido_ocupado = -1;
    for(int i = ((abs(numero)) % andar); i < andar && fim == 0; i++){
        if(Cemiterio[i][jazido + 1] == 0){
            andar_ocupado = i;
            jazido_ocupado = 0;
            Cemiterio[i][jazido_ocupado] = numero;
            Cemiterio[i][jazido + 1] += 1;
            fim = 1;
        }
        else if(Cemiterio[i][jazido + 1] < jazido){
            andar_ocupado = i;
            jazido_ocupado = Ordenar(Cemiterio[i], Cemiterio[i][jazido + 1] - 1, 0, numero, jazido + 1);
            Cemiterio[andar_ocupado][jazido_ocupado] = numero;
            Cemiterio[i][jazido + 1] += 1;
            fim = 1;
        }
    }

    if(fim == 0){
        for(int i = 0; i < ((abs(numero)) % andar) && fim == 0; i++){
            if(Cemiterio[i][jazido + 1] == 0){
            andar_ocupado = i;
            jazido_ocupado = 0;
            Cemiterio[i][jazido_ocupado] = numero;
            Cemiterio[i][jazido + 1] += 1;
            fim = 1;
        }
        else if(Cemiterio[i][jazido + 1] < jazido){
            andar_ocupado = i;
            jazido_ocupado = Ordenar(Cemiterio[i], Cemiterio[i][jazido + 1] - 1, 0, numero, jazido + 1);
            Cemiterio[andar_ocupado][jazido_ocupado] = numero;
            Cemiterio[i][jazido + 1] += 1;
            fim = 1;
        }
        }
    }

    if(fim == 0){
        andar = (andar*2) + 1;
        int** Temp = new int*[andar];

        for(int i = 0; i < andar; i++){
            Temp[i] = new int[jazido + 3];
            Temp[i][jazido + 1] = 0;

            for(int j = 0; j < jazido; j++){
                Temp[i][j] = -10;
            }
        }

        for(int i = 0; i < (andar - 1)/2; i++){
            for(int j = 0; j < Cemiterio[i][jazido + 1]; j++){
                if(Cemiterio[i][j] >= 0){
                    Temp = ADD(Temp, jazido, Cemiterio[i][j], 0);
                }
            }
        }

        Temp = ADD(Temp, jazido, numero, 1);
        
        delete []Cemiterio;
        Cemiterio = Temp;
        
        
        return Temp;
    }

    if(printar == 1){
        Printar(andar_ocupado, jazido_ocupado);
    }
    return Cemiterio;
}

void REM(int** Cemiterio, int andar, int jazido, int numero){
    int andar_ocupado;
    int jazido_ocupado;

    jazido_ocupado = QRY(Cemiterio, andar, jazido, numero, &andar_ocupado);

    if(jazido_ocupado >= 0){
        Cemiterio[andar_ocupado][jazido_ocupado] = (-1)*numero;
        Printar(andar_ocupado, jazido_ocupado);
    }

    else{
        Printar(-1, -1);
    }
}

int main(int argc, char const *argv[])
{
    int jazido, numero, jazido_ocupado;
    int andar_ocupado = -1;
    std::string comando = "";

    std::cin >> andar >> jazido;
    int** Cemiterio = new int*[andar];

    for(int i = 0; i<andar; i++){
        Cemiterio[i] = new int[jazido + 3];
        Cemiterio[i][jazido + 1] = 0;

        for(int j = 0; j < jazido; j++){
            Cemiterio[i][j] = -10;
        }
    }

    while(comando != "END"){
        std::cin >> comando;

        if(comando == "ADD"){
            std::cin >> numero;
            Cemiterio =  ADD(Cemiterio, jazido, numero, 1);
        }

        else if(comando == "QRY"){
            std::cin >> numero;
            jazido_ocupado = QRY(Cemiterio, andar, jazido, numero, &andar_ocupado);
            Printar(andar_ocupado, jazido_ocupado);
        }

        else if(comando == "REM"){
            std::cin >> numero;
            REM(Cemiterio, andar, jazido, numero);
        }
    }

    delete []Cemiterio;
    return 0;
}
