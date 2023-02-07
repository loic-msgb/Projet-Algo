#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include "header.h"


int bloque_direction_haut(block NV, int xBalle,int yBalle,int vyBalle){

	for(int i=0; i<NV.sizeMap; i++){
		//test pour aller en haut
		if(NV.map[i].Ypt1 > yBalle){
			if( yBalle+vyBalle >= NV.map[i].Ypt1 && (xBalle >= NV.map[i].Xpt1 && xBalle <= NV.map[i].Xpt2) ){
				return 1;
			}
		}
	}
	return 0;
}

int bloque_direction_bas(block NV, int xBalle,int yBalle, int vyBalle){
	for(int i=0; i<NV.sizeMap; i++){
		//test pour aller en bas
		if(NV.map[i].Ypt2 < yBalle){
			if( yBalle-vyBalle <= NV.map[i].Ypt2 && (xBalle >= NV.map[i].Xpt1 && xBalle <= NV.map[i].Xpt2) ){
				return 1;
			}
		}
	}
	return 0;
}

int bloque_direction_droite(block NV, int xBalle,int yBalle, int vxBalle){

	for(int i=0; i<NV.sizeMap; i++){
		if(NV.map[i].Xpt1 > xBalle){
			if( xBalle+vxBalle >= NV.map[i].Xpt1 && (yBalle >= NV.map[i].Ypt1 && yBalle <= NV.map[i].Ypt2) ){
				return 1;
			}
		}
	}
	return 0;
}

int bloque_direction_gauche(block NV, int xBalle,int yBalle, int vxBalle){

	for(int i=0; i<NV.sizeMap; i++){
		if(NV.map[i].Xpt2 < xBalle){
			if( xBalle-vxBalle <= NV.map[i].Xpt2 && (yBalle >= NV.map[i].Ypt1 && yBalle <= NV.map[i].Ypt2) ){
				return 1;
			}
		}
	}
	return 0;
}
