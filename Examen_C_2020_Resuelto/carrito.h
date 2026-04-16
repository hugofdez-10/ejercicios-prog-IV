#ifndef CARRITO_H_
#define CARRITO_H_

#include "producto.h"

typedef struct
{
	Producto producto;
	int cantidad;
} Compra;

void modificarCompra(Compra* c, int cant);
void imprimirCompra(Compra c);

typedef struct
{
	Compra* compras;
	int numCompras;
	float total;
} Carrito;

void crearCarrito(Carrito* carrito, Producto* comprados[], int cantidades[], int numCompras);
void devolverCarrito(Carrito* carrito);
void imprimirTicket(Carrito carrito);

void modificarCarrito(Carrito* carrito, int ref, int cantidad);

#endif /* CARRITO_H_ */
