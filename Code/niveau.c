#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include "header.h"

block initialise_block(block NV){

	NV.map = (forme*) calloc(3, sizeof(forme));
	
	forme a = initialise_forme(0, 0, 1, 0.15);
	forme b = initialise_forme(0.625, 0.15, 0.75, 0.30); 	
	forme c = initialise_forme(0.56, 0.23, 0.625, 0.250); 	

			
	NV.map[0] = a;
	NV.map[1] = b;
	NV.map[2] = c;

	NV.sizeMap = 3;
	

	return NV;
}

forme initialise_forme(float FacteurXpt1, float FacteurYpt1, float FacteurXpt2, float FacteurYpt2){
	forme a;
	a.Xpt1 = largeurFenetre()*FacteurXpt1;
	a.Xpt2 = largeurFenetre()*FacteurXpt2;
	a.Ypt2 = hauteurFenetre()*FacteurYpt2;
	a.Ypt1 = hauteurFenetre()*FacteurYpt1;

	return a;
}



