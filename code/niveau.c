#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include "header.h"

block initialise_block(block NV){

	NV.map = (forme*) calloc(5, sizeof(forme));
	
	forme a = initialise_forme(0.25, 0.58, 0.75, 0.6);
	forme b = initialise_forme(0.25, 0.1, 0.75, 0.30); 	
	forme c = initialise_forme(0.25, 0.3, 0.3, 0.50); 	
	forme d = initialise_forme(0.7, 0.3, 0.75, 0.50); 
	forme e = initialise_forme(0.45, 0.3, 0.50, 0.35); 	
			
	NV.map[0] = a;
	NV.map[1] = b;
	NV.map[2] = c;
	NV.map[3] = d;
	NV.map[4] = e;
	NV.sizeMap = 5;
	

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



