//CODIGO EN ARDUINO
////////////////////////////////////////////////////////////////////////////////////////////////7
int opcion=0;
void publick();
void imagen();
void verificacion();
void mostrarPatrones();
void patronOn();
void setPatron();
void MatrizRombo();
void MatrizRare();

void setup(){
    Serial.begin(9600);
    publick();
}

void loop(){
    while (Serial.available() == 0);
    opcion = Serial.parseInt();

    clearScreen();
    if(opcion==1){
        verificacion();
    }
    else if(opcion==2){
        Serial.println("Ingrese una a una las posiciones leds a encender: ");
        imagen();
        Serial.println("Mostrando patron..."); Serial.println();
        setPatron();
        patronOn();
    }
    else if(opcion==3){
        mostrarPatrones();
        Serial.println("Mostrando patron..."); Serial.println();
        setPatron();
        patronOn();
    }

    publick();
}

void publick(){
    //Esta funcion se encarga de mostrar el menu de opciones
    clearScreen();
    Serial.println("Menu:");
    Serial.println("1. Verificar funcionamiento de los leds.");
    Serial.println("2. Visualizar un patron.");
    Serial.println("3. Visualizar secuencia de patrones.");
    Serial.println("Escoja una opcion.");
}


void imagen(){
    //Esta funcion se encarga de ir encendiendo los leds que
    //quiera el usuario hasta que de esa manera se forme un
    //patron.
    int espera = 0;
    int fila;
    int columna;
    char estado;

    setPatron();
    while(true){
        Serial.println("Ingrese la ubicacion del led a encender o apagar.");
        Serial.print("Fila: "); Serial.read();
        while(Serial.available()==0);
        fila=Serial.parseInt();
        clearScreen();

        Serial.println("Ingrese la ubicacion del led a encender o apagar.");
        Serial.print("Fila: ");
        Serial.println(fila);
        Serial.print("Columna: ");
        Serial.read();
        while(Serial.available()==0);
        columna=Serial.parseInt();
        clearScreen();

        Serial.println("Ingrese la ubicacion del led a encender o apagar.");
        Serial.print("Fila: "); Serial.println(fila);
        Serial.print("Columna: "); Serial.println(columna);

        if(fila==0 || columna==0){
            clearScreen();
            break;//Se rompe el ciclo infinito
        }
        Serial.print("Estado: "); Serial.read();
        while(Serial.available()==0);
        estado=Serial.read();
        clearScreen();

        if(estado == '+'){
            patron[fila-1][columna-1] = 1;
        }
        else{
            patron[fila-1][columna-1] = 0;
        }
        patronOn();
    }
    Serial.println("Ingrese el intervalo de tiempo (segundos): ");
    while(Serial.available()==0);
    espera = static_cast<int>(Serial.parseFloat()*1000);
    clearScreen();

    //Hacer que imprima ese patron n veces con el tiempo indicado
    for(int i=0; i<3; i++){
        patronOn();
        delay(espera);
        patronOff();
        delay(espera);
    }
}

void verificacion(){
    Serial.println("Aca se esta mostrando la verificacion de la matriz");
}

void mostrarPatrones(){
    //Esta funcion es la encargada de mostrar la secuencia de
    //patrones uno a uno.
    int espera = 1000; // Tiempo de delay entre encendido y apagado en milisegundos
    MatrizRombo();
    delay(espera);
    MatrizRare();
    delay(espera);
}

void clearScreen(){
    //Esta funcion da la sensacion de limpiar el monitor serial
    for(int i=0; i<5; i++){
        Serial.println();
    }
}


void patronOn() {
    // Envía el patrón al 74HC595 de derecha a izquierda.
    for (int i = 7; i >= 0; i--) {
        int fila_data = 0;
        for (int j = 7; j >= 0; j--) {
            fila_data |= (patron[i][j] << (7 - j));
        }
        shiftOut(pinData, pinClock, LSBFIRST, fila_data);
    }

    // Carga el patrón en los LEDs.
    digitalWrite(pinLatch, HIGH);
    digitalWrite(pinLatch, LOW);
}

void patronOff() {
    uint8_t m0s[8][8];
    //Inicializar una matriz con todas las posiciones en OFF
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            m0s[i][j]=0;
        }
    }
    // Envía el patrón al 74HC595 de derecha a izquierda.
    for (int i = 7; i >= 0; i--) {
        int fila_data = 0;
        for (int j = 7; j >= 0; j--) {
            fila_data |= (m0s[i][j] << (7 - j));
        }
        shiftOut(pinData, pinClock, LSBFIRST, fila_data);
    }

    // Carga el patrón en los LEDs.
    digitalWrite(pinLatch, HIGH);
    digitalWrite(pinLatch, LOW);
}


void setPatron(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            patron[i][j]=0;
        }
    }
}


void MatrizRombo() {
    // Inicializar la matriz con 0s
    setPatron();

    // Llena la matriz patron con el patrón del rombo
    for (int i = 0; i < 4; i++) {
        for (int j = 3 - i; j <= 4 + i; j++) {
            patron[i][j] = 1;
            patron[7 - i][j] = 1;
        }
    }
    patronOn();
}


void MatrizRare() {
    //Inicializar la matriz con 1s
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            patron[i][j] = 1;
        }
    }

    // Sobrescribe algunos elementos con 0s según tu patrón
    for (int i = 0; i < 8; i += 4) {
        for (int j = 2; j < 8; j += 3) {
            patron[i][j] = 0;
            patron[i + 1][j] = 0;
        }
    }

    for (int i = 2; i < 8; i += 4) {
        for (int j = 0; j < 8; j += 3) {
            patron[i][j] = 0;
            patron[i + 1][j] = 0;
        }
    }
    patronOn();
}




























