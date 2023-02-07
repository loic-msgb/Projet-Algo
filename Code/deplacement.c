#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include "header.h"


int bloque_direction_haut(block NV, Joueur joueur,int vyBalle){

	for(int i=0; i<NV.sizeMap; i++){
		//test pour aller en haut
		if(NV.map[i].Ypt1 > joueur.yPt2){
			if( joueur.yPt2 + vyBalle >= NV.map[i].Ypt1 && ( (joueur.xPt1 > NV.map[i].Xpt1 && joueur.xPt1 < NV.map[i].Xpt2) || (joueur.xPt2 < NV.map[i].Xpt2 && joueur.xPt2 > NV.map[i].Xpt1 )) ){
				return 1;
			}
		}
	}
	return 0;
}

int bloque_direction_bas(block NV, Joueur joueur, int vyBalle){
	for(int i=0; i<NV.sizeMap; i++){
		//test pour aller en bas
		if(NV.map[i].Ypt2 < joueur.yPt1){
			if( joueur.yPt1 - vyBalle <= NV.map[i].Ypt2 && ( (joueur.xPt1 > NV.map[i].Xpt1 && joueur.xPt1 < NV.map[i].Xpt2) || (joueur.xPt2 < NV.map[i].Xpt2 && joueur.xPt2 > NV.map[i].Xpt1 )) ){
				return 1;
			}
		}
	}
	return 0;
}

int bloque_direction_droite(block NV, Joueur joueur, int vxBalle){

	for(int i=0; i<NV.sizeMap; i++){
		if(NV.map[i].Xpt1 > joueur.xPt2){
			if( joueur.xPt2 + vxBalle >= NV.map[i].Xpt1 && ( (joueur.yPt1 > NV.map[i].Ypt1 && joueur.yPt1 < NV.map[i].Ypt2) || (joueur.yPt2 < NV.map[i].Ypt2 && joueur.yPt2 > NV.map[i].Ypt1)) ){
				return 1;
			}
		}
	}
	return 0;
}

int bloque_direction_gauche(block NV, Joueur joueur, int vxBalle){

	for(int i=0; i<NV.sizeMap; i++){
		if(NV.map[i].Xpt2 < joueur.xPt1){
			if( joueur.xPt1-vxBalle <= NV.map[i].Xpt2 && ( (joueur.yPt1 > NV.map[i].Ypt1 && joueur.yPt1 < NV.map[i].Ypt2) || (joueur.yPt2 < NV.map[i].Ypt2 && joueur.yPt2 > NV.map[i].Ypt1)) ){
				return 1;
			}
		}
	}
	return 0;
}


Joueur MoveVertical(Joueur joueur, int force){
	joueur.yPt1 += force;
	joueur.yPt2 += force;
	
	return joueur;
}

Joueur MoveLateral(Joueur joueur, int vitesse){
	joueur.xPt1 += vitesse;
	joueur.xPt2 += vitesse;

	return joueur;
}


Joueur doodle(Joueur joueur){

	float coteCarre = joueur.xPt2 - joueur.xPt1;
	if(joueur.xPt2 < largeurFenetre()*0){
		joueur.xPt2 = largeurFenetre();
		joueur.xPt1 = joueur.xPt2 - coteCarre; 
	}
	
	if(joueur.xPt1 > largeurFenetre()){
		joueur.xPt1 = largeurFenetre()*0;
		joueur.xPt2 = joueur.xPt1 + coteCarre;
	}

	return joueur;
}
