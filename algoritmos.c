
#include <stdio.h>
#include <stdlib.h>

/*
XOR con clave privada: Este tipo de encriptación es uno de los más utilizados como base
de algoritmos criptográficos más complejos, como AES, por ejemplo. Para este algoritmo
al color (grises) de cada pixel (i,j) deberá aplicársele una operación XOR con un dato
de 8 bits, denominado clave privada. Para desencriptar una imagen encriptada con este
algoritmo, debe aplicarse el mismo proceso.
*/






/*
Desplazamiento simple: En este algoritmo, se deberá aplicar un desplazamiento de
una cantidad definida de bits entre 1 y 7, hacia cualquier dirección, al color de cada pixel.
Para desencriptar, se deberá aplicar un desplazamiento simple en la dirección contraria,
con la misma cantidad de bits. Este algoritmo generará pérdidas en la información, a la
hora de desencriptar.
*/




/*
Desplazamiento circular: Este algoritmo será similar al anterior, pero el desplazamien-
to será circular, lo que implica que los datos que serán desplazados no se perderán, sino
que pasan del bit más significativo al menos significativo, y viceversa. Para desencriptar,
se deberá aplicar el desplazamiento circular en la dirección contraria a la encriptación,
para la misma cantidad de bits desplazados.
*/





/*
Suma simple: En este algoritmo, al color de cada pixel, dentor de un vector, deberá
sumarsele un valor determinado diferente, dentro de otro vector (clave). Ası́, para un
vector de 4 pixeles [30,60,1,1], el vector clave a sumar (para toda la imagen) podrá ser,
por ejemplo, [12, 5, 100, 10], y el resultado de color, para este primer vector de pixeles
debe ser entonces [42,65,101,11]. Deberá considerarse asuntos de desbordamiento. Para
desencriptar, deberá restarse cada vector de pixeles en la imagen con respecto al mismo
vector clave, definido previamente.
*/


