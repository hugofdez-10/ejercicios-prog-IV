#include <stdio.h>
#include <stdlib.h>
#include "carrito.h"
#include "producto.h"

void modificarCompra(Compra* c, int cant)
{
	c->cantidad = cant;
}

void imprimirCompra(Compra c)
{
	printf("Ref.%i  %s \t %.2f x %i kg/ud\n", c.producto.ref, c.producto.nombre, c.producto.precio, c.cantidad);
}

void crearCarrito(Carrito* carrito, Producto* comprados[], int cantidades[], int numCompras)
{
	carrito->numCompras = numCompras;
	carrito->compras = (Compra*)malloc(sizeof(Compra)*carrito->numCompras);
	int i;
	float total = 0;
	for(i=0;i<carrito->numCompras;i++)
	{
		carrito->compras[i].producto = *comprados[i];
		carrito->compras[i].cantidad = cantidades[i];
		total += (comprados[i]->precio * cantidades[i]);
	}
	carrito->total = total;
}

void devolverCarrito(Carrito* carrito)
{
	free(carrito->compras);
}

void imprimirTicket(Carrito carrito)
{
	printf("TICKET\n");
	printf("------\n");
	int i;
	for(i=0;i<carrito.numCompras;i++)
	{
		imprimirCompra(carrito.compras[i]);
	}
	printf("........................................\n");
	printf("TOTAL: %.2f euros\n", carrito.total);
}

void modificarCarrito(Carrito* carrito, int ref, int cantidad)
{
	carrito->total = 0;
	int i;
	for(i=0;i<carrito->numCompras;i++)
	{
		if(carrito->compras[i].producto.ref == ref)
		{
			carrito->compras[i].cantidad = cantidad;
		}
		carrito->total += (carrito->compras[i].producto.precio * carrito->compras[i].cantidad);
	}
}
