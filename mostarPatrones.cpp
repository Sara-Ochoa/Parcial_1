void mostrarPatrones(){
    //Esta funcion es la encargada de mostrar la secuencia de 
  	//patrones uno a uno.
  	int espera = 1000; // Tiempo de delay entre encendido y apagado en milisegundos
  	MatrizX();
  	delay(espera);
  	MatrizZZ();
  	delay(espera);
}

void MatrizX() {
  // Llena la matriz con el patrón de una "X"
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i == j || i == (7 - j)) {
        patron[i][j] = 1;
      } else {
        patron[i][j] = 0;
      }
    }
  }
  patronOffOn();
}

void MatrizZZ() {
  // Inicializar la matriz con 0s
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      patron[i][j] = 0;
    }
  }

  // Cambiar 4 0s por 1s en las filas del 1 al 4
  for (int i = 0; i < 4; i++) {
    for (int j = i; j <= i + 3; j++) {
      patron[i][j] = 1;
    }
  }

  // Cambiar 4 0s por 1s en las filas del 5 al 8
  for (int i = 4; i < 8; i++) {
    for (int j = 6 - (i - 4); j >= 3 - (i - 4); j--) {
      patron[i][j] = 1;
    }
  }
  patronOffOn();
}
