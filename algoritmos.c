
#include <stdio.h>
#include <stdlib.h>

/*
XOR con clave privada: Este tipo de encriptación es uno de los más utilizados como base
de algoritmos criptográficos más complejos, como AES, por ejemplo. Para este algoritmo
al color (grises) de cada pixel (i,j) deberá aplicársele una operación XOR con un dato
de 8 bits, denominado clave privada. Para desencriptar una imagen encriptada con este
algoritmo, debe aplicarse el mismo proceso.
*/

add(ss)nc    S1, S0, #11111111  //Cargo la clave xor en S1
-repeat -u4
ldv(m)nc     V0, S2, #00000000
ldv(m)nc     V1, S2, #00001000
ldv(m)nc     V2, S2, #00010000
ldv(m)nc     V3, S2, #00011000
xor(sv)nc    V0, S1, V0
xor(sv)nc    V1, S1, V1
xor(sv)nc    V2, S1, V2
xor(sv)nc    V3, S1, V3
strv(m)nc    V0, S2, #00000000
strv(m)nc    V1, S2, #00001000
strv(m)nc    V2, S2, #00010000
strv(m)nc    V3, S2, #00011000
add(ss)nc    S2, S2, #00100000 //actualizo el indice i+=64





/*
Desplazamiento simple: En este algoritmo, se deberá aplicar un desplazamiento de
una cantidad definida de bits entre 1 y 7, hacia cualquier dirección, al color de cada pixel.
Para desencriptar, se deberá aplicar un desplazamiento simple en la dirección contraria,
con la misma cantidad de bits. Este algoritmo generará pérdidas en la información, a la
hora de desencriptar.
*/

add(ss)nc    S1, S0, #00000001  //Cargo num de desplazamientos
-repeat -u4
ldv(m)nc     V0, S2, #00000000
ldv(m)nc     V1, S2, #00001000
ldv(m)nc     V2, S2, #00010000
ldv(m)nc     V3, S2, #00011000
shr(sv)nc    V0, S1, V0
shr(sv)nc    V1, S1, V1
shr(sv)nc    V2, S1, V2
shr(sv)nc    V3, S1, V3
strv(m)nc    V0, S2, #00000000
strv(m)nc    V1, S2, #00001000
strv(m)nc    V2, S2, #00010000
strv(m)nc    V3, S2, #00011000
add(ss)nc    S2, S2, #00100000 //actualizo el indice i+=64


add(ss)nc    S1, S0, #00000001  //Cargo num de desplazamientos
-repeat -u4
ldv(m)nc     V0, S2, #00000000
ldv(m)nc     V1, S2, #00001000
ldv(m)nc     V2, S2, #00010000
ldv(m)nc     V3, S2, #00011000
shl(sv)nc    V0, S1, V0
shl(sv)nc    V1, S1, V1
shl(sv)nc    V2, S1, V2
shl(sv)nc    V3, S1, V3
strv(m)nc    V0, S2, #00000000
strv(m)nc    V1, S2, #00001000
strv(m)nc    V2, S2, #00010000
strv(m)nc    V3, S2, #00011000
add(ss)nc    S2, S2, #00100000 //actualizo el indice i+=64




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


ldv(m)nc     V0, S3, #00000001  //cargo un vector que será el clave
-repeat -u2
ldv(m)nc     V2, S2, #00000000
ldv(m)nc     V3, S2, #00001000
add(vv)nc    V2, V0, V2
add(vv)nc    V3, V0, V3
strv(m)nc    V2, S2, #00000000
strv(m)nc    V3, S2, #00001000
add(ss)nc    S2, S2, #00010000 //actualizo el indice i+=24



ldv(m)nc     V0, S3, #00000001  //cargo un vector que será el clave
-repeat -u2
ldv(m)nc     V2, S2, #00000000
ldv(m)nc     V3, S2, #00001000
sub(vv)nc    V2, V0, V2
sub(vv)nc    V3, V0, V3
strv(m)nc    V2, S2, #00000000
strv(m)nc    V3, S2, #00001000
add(ss)nc    S2, S2, #00010000 //actualizo el indice i+=24
