#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../1/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../1/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../1/ESLib.h" // Pour utiliser valeurAleatoire()

#include "header.h"

void menu(){
	couleurCourante(255, 0, 0);
	rectangle(largeurFenetre()*0.3, hauteurFenetre()*0.625, largeurFenetre()*0.7, hauteurFenetre()*0.375);
	couleurCourante(255,255,255);
	epaisseurDeTrait(3);
	afficheChaine("JOUER", 20, largeurFenetre()*0.45, hauteurFenetre()*0.48);		
}
