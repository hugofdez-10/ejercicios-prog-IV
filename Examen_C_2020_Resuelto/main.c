#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "carrito.h"

void leerProductos(Producto* productos[], char* fichero)
{
	FILE* f = fopen(fichero, "r");
    char c;
    int pos_car = 0;
    int num_linea = 0;
    char ref[2];
    char nombre[15];
    char precio[6];
	while ((c = fgetc(f)) != EOF)
	{
		pos_car++;
		if (pos_car == 1){
			ref[pos_car-1] = c;
		}
		if (pos_car > 1 && pos_car < 16){
			nombre[pos_car-2] = c;
		}
		if (pos_car >= 16 && pos_car < 21)
		{
			precio[pos_car-16] = c;
		}
		if (c == '\n'){
			ref[1] = '\0';
			nombre[14] = '\0';
		    precio[5] = '\0';

			Producto * p = (Producto*)malloc(sizeof(Producto));
			sscanf(ref,"%i",&p->ref);
			strcpy(p->nombre, nombre);
			sscanf(precio,"%f",&p->precio);

			productos[num_linea] = p;
			pos_car = 0;
			num_linea++;
		}
	}
	fclose(f);
}

int main(void)
{
	Producto p1; p1.ref=1; strcpy(p1.nombre,"Platanos"); p1.precio=12.0;
	Producto p2; p2.ref=2; strcpy(p2.nombre,"Solomillo"); p2.precio=32.2;
	Producto p3; p3.ref=3; strcpy(p3.nombre,"Chocolate"); p3.precio=25.5;
	Producto p4; p4.ref=4; strcpy(p4.nombre,"Rodaballo"); p4.precio=35.4;
	Producto p5; p5.ref=5; strcpy(p5.nombre,"Cereales"); p5.precio=10.5;

	imprimirProducto(p1);

	Producto* comprados[] = {&p1, &p2, &p3, &p4, &p5};
	leerProductos(comprados, "productos.txt");

	/* PARTE 1 */printf("-----\n");

	Compra c1;
	c1.producto = p2;
	c1.cantidad = 3;
	imprimirCompra(c1);

	modificarCompra(&c1, 0);
	imprimirCompra(c1);

	/* PARTE 2 */printf("-----\n");

	Carrito carrito;
	int cantidades[] = {1, 3, 5, 7, 9};
	crearCarrito(&carrito, comprados, cantidades, 5);
	imprimirTicket(carrito);

	/* PARTE 3 */printf("-----\n");

	modificarCarrito(&carrito, 3, 0);
	imprimirTicket(carrito);

	devolverCarrito(&carrito);

	return 0;
}
