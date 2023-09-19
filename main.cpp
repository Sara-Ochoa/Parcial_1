//CODIGO EN ARDUINO
////////////////////////////////////////////////////////////////////////////////////////////////7
int opcion=0;
void publick();
void imagen();
void verificacion();
void mostrarPatrones();

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
        Serial.println("Mostrando patron...");
        Serial.println();
        Serial.println("Para interrumpir ingrese cualquier caracter: ");
        while(Serial.available()==0);
    }
    else if(opcion==3){
        mostrarPatrones();
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
    Serial.println("Aca se esta mostrando un patrón personalizado");
}

void verificacion(){
    Serial.println("Aca se esta mostrando la verificacion de la matriz");
}

void mostrarPatrones(){
    Serial.println("Aca se esta mostrando todos los patrones 1 a 1");
}

void clearScreen(){
    //Esta funcion da la sensacion de limpiar el monitor serial
    for(int i=0; i<5; i++){
        Serial.println();
    }
}
