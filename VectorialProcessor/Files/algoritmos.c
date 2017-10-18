
/*
XOR con clave privada: Este tipo de encriptación es uno de los más utilizados como base
de algoritmos criptográficos más complejos, como AES, por ejemplo. Para este algoritmo
al color (grises) de cada pixel (i,j) deberá aplicársele una operación XOR con un dato
de 8 bits, denominado clave privada. Para desencriptar una imagen encriptada con este
algoritmo, debe aplicarse el mismo proceso.
*/
add(ss)nc    S2, S2, #00010000 //posicion donde inicia la imagen
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
add(ss)nc    S0, S0, #00000000 //nop





/*
Desplazamiento simple: En este algoritmo, se deberá aplicar un desplazamiento de
una cantidad definida de bits entre 1 y 7, hacia cualquier dirección, al color de cada pixel.
Para desencriptar, se deberá aplicar un desplazamiento simple en la dirección contraria,
con la misma cantidad de bits. Este algoritmo generará pérdidas en la información, a la
hora de desencriptar.
*/

add(ss)nc    S2, S2, #00010000 //posicion donde inicia la imagen
add(ss)nc    S1, S0, #00000001  //num corrimientos
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
add(ss)nc    S0, S0, #00000000 //nop





add(ss)nc    S2, S2, #00010000 //posicion donde inicia la imagen
add(ss)nc    S1, S0, #00000001  //num corrimientos
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
add(ss)nc    S0, S0, #00000000 //nop





/*
Desplazamiento circular: Este algoritmo será similar al anterior, pero el desplazamien-
to será circular, lo que implica que los datos que serán desplazados no se perderán, sino
que pasan del bit más significativo al menos significativo, y viceversa. Para desencriptar,
se deberá aplicar el desplazamiento circular en la dirección contraria a la encriptación,
para la misma cantidad de bits desplazados.
*/


add(ss)nc    S2, S2, #00010000 //posicion donde inicia la imagen
add(ss)nc    S1, S0, #00000001  //num corrimientos
-repeat -u4
ldv(m)nc     V0, S2, #00000000
ldv(m)nc     V1, S2, #00001000
ldv(m)nc     V2, S2, #00010000
ldv(m)nc     V3, S2, #00011000
shlc(sv)nc    V0, S1, V0
shlc(sv)nc    V1, S1, V1
shlc(sv)nc    V2, S1, V2
shlc(sv)nc    V3, S1, V3
strv(m)nc    V0, S2, #00000000
strv(m)nc    V1, S2, #00001000
strv(m)nc    V2, S2, #00010000
strv(m)nc    V3, S2, #00011000
add(ss)nc    S2, S2, #00100000 //actualizo el indice i+=64
add(ss)nc    S0, S0, #00000000 //nop



add(ss)nc    S2, S2, #00010000 //posicion donde inicia la imagen
add(ss)nc    S1, S0, #00000001  //num corrimientos
-repeat -u4
ldv(m)nc     V0, S2, #00000000
ldv(m)nc     V1, S2, #00001000
ldv(m)nc     V2, S2, #00010000
ldv(m)nc     V3, S2, #00011000
shrc(sv)nc    V0, S1, V0
shrc(sv)nc    V1, S1, V1
shrc(sv)nc    V2, S1, V2
shrc(sv)nc    V3, S1, V3
strv(m)nc    V0, S2, #00000000
strv(m)nc    V1, S2, #00001000
strv(m)nc    V2, S2, #00010000
strv(m)nc    V3, S2, #00011000
add(ss)nc    S2, S2, #00100000 //actualizo el indice i+=64
add(ss)nc    S0, S0, #00000000 //nop





/*
Suma simple: En este algoritmo, al color de cada pixel, dentor de un vector, deberá
sumarsele un valor determinado diferente, dentro de otro vector (clave). Ası́, para un
vector de 4 pixeles [30,60,1,1], el vector clave a sumar (para toda la imagen) podrá ser,
por ejemplo, [12, 5, 100, 10], y el resultado de color, para este primer vector de pixeles
debe ser entonces [42,65,101,11]. Deberá considerarse asuntos de desbordamiento. Para
desencriptar, deberá restarse cada vector de pixeles en la imagen con respecto al mismo
vector clave, definido previamente.
*/

add(ss)nc    S1, S0, #11111111 // cargo 255
add(ss)nc    S2, S0, #10000011 //cargo 131
strs(m)nc    S1, S0, #00000000 //guardo 255 en memoria
strs(m)nc    S2, S0, #00000001 //guardo 131 en memoria
sub(ss)nc    S1, S1, S1        //limpio S1
sub(ss)nc    S2, S2, S2        //limpio S2
add(ss)nc    S1, S0, #00001010 // cargo 10
add(ss)nc    S2, S0, #10000000 //cargo 128
strs(m)nc    S1, S0, #00000010 //guardo 10 en memoria
strs(m)nc    S2, S0, #00000011 //guardo 128 en memoria
sub(ss)nc    S1, S1, S1        //limpio S1
sub(ss)nc    S2, S2, S2        //limpio S2
add(ss)nc    S1, S0, #01000001 // cargo 65
add(ss)nc    S2, S0, #00101010 //cargo 42
strs(m)nc    S1, S0, #00000100 //guardo 65 en memoria
strs(m)nc    S2, S0, #00000101 //guardo 42 en memoria
sub(ss)nc    S1, S1, S1        //limpio S1
sub(ss)nc    S2, S2, S2        //limpio S2
add(ss)nc    S1, S0, #01100000 // cargo 96
add(ss)nc    S2, S0, #00000011 //cargo 3
strs(m)nc    S1, S0, #00000110 //guardo 96 en memoria
strs(m)nc    S2, S0, #00000111 //guardo 3 en memoria
add(ss)nc    S3, S3, #00010000 //posicion donde inicia la imagen
ldv(m)nc     V0, S0, #00000000 //cargo la posición de memoria     
-repeat -u2
ldv(m)nc     V2, S3, #00000000
ldv(m)nc     V3, S3, #00001000
add(vv)nc    V2, V0, V2
add(vv)nc    V3, V0, V3
strv(m)nc    V2, S3, #00000000
strv(m)nc    V3, S3, #00001000
add(ss)nc    S3, S3, #00010000 //actualizo el indice i+=24
add(ss)nc    S0, S0, #00000000 //nop




add(ss)nc    S1, S0, #11111111 // cargo 255
add(ss)nc    S2, S0, #10000011 //cargo 131
strs(m)nc    S1, S0, #00000000 //guardo 255 en memoria
strs(m)nc    S2, S0, #00000001 //guardo 131 en memoria
sub(ss)nc    S1, S1, S1        //limpio S1
sub(ss)nc    S2, S2, S2        //limpio S2
add(ss)nc    S1, S0, #00001010 // cargo 10
add(ss)nc    S2, S0, #10000000 //cargo 128
strs(m)nc    S1, S0, #00000010 //guardo 10 en memoria
strs(m)nc    S2, S0, #00000011 //guardo 128 en memoria
sub(ss)nc    S1, S1, S1        //limpio S1
sub(ss)nc    S2, S2, S2        //limpio S2
add(ss)nc    S1, S0, #01000001 // cargo 65
add(ss)nc    S2, S0, #00101010 //cargo 42
strs(m)nc    S1, S0, #00000100 //guardo 65 en memoria
strs(m)nc    S2, S0, #00000101 //guardo 42 en memoria
sub(ss)nc    S1, S1, S1        //limpio S1
sub(ss)nc    S2, S2, S2        //limpio S2
add(ss)nc    S1, S0, #01100000 // cargo 96
add(ss)nc    S2, S0, #00000011 //cargo 3
strs(m)nc    S1, S0, #00000110 //guardo 96 en memoria
strs(m)nc    S2, S0, #00000111 //guardo 3 en memoria
add(ss)nc    S3, S3, #00010000 //posicion donde inicia la imagen
ldv(m)nc     V0, S0, #00000000 //cargo la posición de memoria     
-repeat -u2
ldv(m)nc     V2, S3, #00000000
ldv(m)nc     V3, S3, #00001000
sub(vv)nc    V2, V0, V2
sub(vv)nc    V3, V0, V3
strv(m)nc    V2, S3, #00000000
strv(m)nc    V3, S3, #00001000
add(ss)nc    S3, S3, #00010000 //actualizo el indice i+=24
add(ss)nc    S0, S0, #00000000 //nop



//////////////// PROGRAMA DE PRUEBA DE INSTRUCCIONES/////////////////////////////////


add(ss)nc    S1, S0, #00000011 // cargo 3
add(ss)nc    S0, S0, #00000000 //nop
or(sv)nc     V3, S1,V0         // 0 or 3        = [3,3,3,3,3,3,3,3]
add(ss)nc    S0, S0, #00000000 //nop
shl(sv)nc    V2, S1, V3        //v2 =  V3<<3   =  [24,24,24,24,24,24,24,24]
add(ss)nc    S3, S0, #00000001 // cargo 1
shr(sv)nc    V2, S1, V2        //v2 =  V3>>3   =  [3,3,3,3,3,3,3,3]
add(ss)nc    S0, S0, #00000000 //nop
sub(vv)ne    V3, S3,V2         // si no es igual restele 1
xor(sv)nc    V2,S3,V2          // xor       V2  =  [2,2,2,2,2,2,2,2]
-repeat -u2
ldv(m)nc     V2, S0, #00000000
strv(m)nc    V2, S0, #00000000
