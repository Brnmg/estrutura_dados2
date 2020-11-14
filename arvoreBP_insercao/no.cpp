#include <iostream>
#include <stdlib.h>

#include "no.h"

No::No() { 
  int ordem = 5; //Esse número irá mudar de acordo com o que for pedido no exercício
  chave = new int[ordem]; 
  pont = new No*[ordem + 1]; 
} 

