# get_next_line

## Parte obligatoria

| Nombre de función: | get_next_line |
|--------------------|---------------|
| Prototipo: | char *get_next_line(int fd); |
| Archivos a entregar: | get_next_line.c </br> get_next_line_utils.c </br> get_next_line.h |
| Parámetros: | File descriptor del que leer. |
| Valor de retorno: | Si todo va bien: la línea leída </br> En caso de fallo o si la lectura termina: NULL |
| Funciones autorizadas: | read, malloc, free |
| Descripción: | Escribe una función que devuelva la línea leída de un file descriptor. |

- Llamar a tu función get_next_line en un bucle te permitirá leer el contenido de
un file descriptor línea a línea hasta el final.
- Tu función deberá devolver la línea que se acaba de leer. Si no hay nada más que
leer o si ha ocurrido un error, deberá devolver NULL.
- Asegúrate de que tu función se comporta adecuadamente cuando lea de un archivo
y cuando lea de stdin.
- libft no se permite para este proyecto. Debes añadir un archivo get_next_line_utils.c
que tendrá las funciones necesarias para que tu get_next_line funcione.
- Tu programa debe compilar con la flag -D BUFFER_SIZE=xx. Esta flag se utilizará
para determinar el tamaño del buffer de las lecturas de tu get_next_line. Este
parámetro será modificado por tus evaluadores y por Moulinette.
- La compilación se realizará de la siguiente forma: gcc -Wall -Werror -Wextra -D
BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
- El programa se compilará de la siguiente forma:
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.
- Tu read deberá utilizar el BUFFER_SIZE definido durante la compilación para leer
de un archivo o del stdin. Este parámetro se modificará durante la evaluación para
las pruebas pertinentes.
- En el header get_next_line.h deberás tener como mínimo el prototipo de la función get_next_line.
- lseek no se permite. Debe leerse el archivo una única vez.
- Consideramos que get_next_line tiene un comportamiento indefinido si, entre
llamadas, el mismo fd cambia de archivo antes de terminar la lectura sobre el
primer fd.
- Finalmente, consideramos que get_next_line tiene un comportamiento indefinido
si se lee un binario. Sin embargo, y si así lo deseas, puedes dar coherencia a este
comportamiento.
- Las variables globales están prohibidas.
- Importante: la línea devuelta debe incluir el ’\n’, excepto si has llegado al final del
archivo y no hay ’\n’.

## Parte bonus
El proyecto get_next_line es bastante directo y no deja mucho margen a los bonus,
pero seguramente tengas un montón de imaginación. Si has clavado la parte obligatoria
y la tienes PERFECTA, puedes ir a por los bonus. De nuevo, tus bonus no se tendrán en
cuenta si la parte obligatoria no está PERFECTA.
Entrega los tres archivos iniciales con _bonus.[c/h] para esta parte.
- Entrega get_next_line con una sola variable estática.
- Sé capaz de gestionar múltiples fd con tu get_next_line. Es decir, si tienes tres fd
disponibles para lectura (por ejemplo: 3, 4 y 5), debes poder utilizar get_next_line
una vez sobre el fd 3, otra vez sobre el fd 4, y otra vez sobre el fd 5 de forma
intermitente. Y sí, no debe perder el hilo de lectura de cada uno de los fd.
 
NO TERMINADO
