uint8_t **patron;
int opcion=0;
const int filas = 8;
const int columnas = 8;

void cleanser();
void asignarMemoriaPatron();

void loop(){
    //Dentro de cada caso del option switch primero se inicia la memoria y al final se libera
}


void asignarMemoria() {
    patron = new uint8_t *[filas];
    for (int i = 0; i < filas; i++) {
        patron[i] = new uint8_t[columnas];
    }
}


void cleanser() {
    // Liberar la memoria utilizada por el arreglo bidimensional
    for (int i = 0; i < filas; i++) {
        delete[] patron[i];
    }
    delete[] patron;
    
    patron = nullptr;
}

