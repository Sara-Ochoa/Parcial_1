void verificacion(){
  int veces = 3; // Veces que se comprueba el ciclo de encendido y apagado de la matriz de LEDs
  int espera = 500; // Tiempo de delay entre encendido y apagado en milisegundos
  
    for (int ciclo = 0; ciclo < veces; ciclo++) { // Ciclo que se repite
    
        // Enciende todos los LEDs para verificar que están funcionando correctamente
        for(int i = 0; i < 8; i++){
            shiftOut(pinData, pinClock, MSBFIRST, 255); 
        }
        digitalWrite(pinLatch, HIGH);
        digitalWrite(pinLatch, LOW);

        Serial.println("Matriz encendida."); Serial.println();

        // Espera
        delay(espera);

        // Apaga todos los LEDs
        for(int i = 0; i < 8; i++){
            shiftOut(pinData, pinClock, MSBFIRST, 0); 
        }
        digitalWrite(pinLatch, HIGH);
        digitalWrite(pinLatch, LOW);

        // Espera
        delay(espera);
    }
}