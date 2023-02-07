#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../1/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../1/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../1/ESLib.h" // Pour utiliser valeurAleatoire()



// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

#include "header.h"

// Fonction de trace de cercle
void cercle(float centreX, float centreY, float rayon);
/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);
void menuQuitter();
void menu();

int main(int argc, char **argv)
{
	
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();
	
	return 0;
}



/* Fonction de trace de cercle */

void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;
	
	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2.*M_PI*index/Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
			// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}
	
}


/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
	static int condition_quitter;
	static int retour_menu;
	
	static int xJoueur;
	static int yJoueur;
	static int vxJoueur= 7;
	static int saut= 20;
	static int gravite = 2;
	
	static int condition_droite =0;
	static int reponse_droite =0;
	
	static int condition_gauche =0;
	static int reponse_gauche =0;
	
	static int condition_haut =0;
	static int reponse_haut =0;
	
	static int compteur_temps =0;
		
	block test;
	test = initialise_block(test);
	int stop = 0;
	switch (evenement)
	{
		case Initialisation:
			/* Le message "Initialisation" est envoye une seule fois, au debut du
			programme : il permet de fixer "image" a la valeur qu'il devra conserver
			jusqu'a la fin du programme : soit "image" reste a NULL si l'image n'a
			pas pu etre lue, soit "image" pointera sur une structure contenant
			les caracteristiques de l'image "imageNB.bmp" */

			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			condition_quitter = 0;
			retour_menu = 0;
			xJoueur = largeurFenetre()/2;
			yJoueur = hauteurFenetre()/2;
				
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			
			/*----------------------------------------------gere les collision et les deplacements---------------------------------*/
			stop = bloque_direction_bas(test, xJoueur, yJoueur, gravite);
			if(stop !=1){
				yJoueur -= gravite;
			}
			else{
				if(condition_haut==1){
					while(compteur_temps <4){
						stop = bloque_direction_haut(test, xJoueur, yJoueur, saut);
						if(stop != 1){
							yJoueur += saut;
						}
						compteur_temps++;
					}
					compteur_temps =0;
					condition_haut =0;	
				}			
			}
			
					
			if(condition_droite ==1){
				stop = bloque_direction_droite(test, xJoueur, yJoueur, vxJoueur);
				if(stop !=1){
					reponse_droite = 1;
				}
				else reponse_droite =0;
			}
			
			if(condition_gauche ==1){
				stop = bloque_direction_gauche(test, xJoueur, yJoueur, vxJoueur);
				if(stop !=1){
					reponse_gauche = 1;
				}
				else reponse_gauche =0;
			}
			/*-------------------------------------------------------------------------------------------------------------------*/
			
			rafraichisFenetre();		
			break;	
			
		case Affichage:
			
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			couleurCourante(255, 0, 0);
			if( (condition_quitter != 1) && retour_menu == 0){
				menu();
			}
			
			else if( (condition_quitter != 1) && (retour_menu == 1) ){
				cercle(xJoueur, yJoueur, 10);
				for(int i=0; i<test.sizeMap; i++){
					rectangle(test.map[i].Xpt1, test.map[i].Ypt1, test.map[i].Xpt2, test.map[i].Ypt2);
				}
			}
			else menuQuitter(); 

			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{

				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
				case 'r':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'n':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
										
				case 'D':
				case 'd':
					condition_droite=1;
					if(reponse_droite==1) xJoueur+=vxJoueur;
					break;
				
				case 'Q':
				case 'q':
					condition_gauche=1;
					if(reponse_gauche==1) xJoueur-=vxJoueur;
					break;
					
				case ' '://pour sauter
					condition_haut=1;
					break;
					
				case 'W':
				case 'w':
					if(condition_quitter ==0) condition_quitter =1;
					else condition_quitter =0;
					break;
			}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			switch(toucheClavier())
			{
				/*
				//touche escape
				case 27:
					libereDonneesImageRGB(&image); // On libere la structure image,c'est plus propre, meme si on va sortir du programme juste apres 
					termineBoucleEvenements();
					break;
				*/
			}
			break;

		case BoutonSouris:
			if (etatBoutonSouris() == GaucheAppuye)
			{
				if(retour_menu ==0){
					retour_menu =1;
				}
			
				if( (abscisseSouris() > largeurFenetre()*0.3 && abscisseSouris() < largeurFenetre()*0.7) && (condition_quitter == 1) ){
					if(ordonneeSouris() < hauteurFenetre()*0.625 && ordonneeSouris() > hauteurFenetre()*0.375){
						libereDonneesImageRGB(&image);
						termineBoucleEvenements();
					}
				}
							
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}
			break;
		
		case Souris: // Si la souris est deplacee
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			if (xJoueur >= largeurFenetre())
				xJoueur = largeurFenetre()-1;
			if (yJoueur >= hauteurFenetre())
				yJoueur = hauteurFenetre()-1;
			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}

void menuQuitter(){
	rectangle(largeurFenetre()*0.3, hauteurFenetre()*0.625, largeurFenetre()*0.7, hauteurFenetre()*0.375);
	couleurCourante(255,255,255);
	epaisseurDeTrait(3);
	afficheChaine("QUITTER", 20, largeurFenetre()*0.45, hauteurFenetre()*0.48);
}

void menu(){

	rectangle(largeurFenetre()*0.3, hauteurFenetre()*0.625, largeurFenetre()*0.7, hauteurFenetre()*0.375);
	couleurCourante(255,255,255);
	epaisseurDeTrait(3);
	afficheChaine("JOUER", 20, largeurFenetre()*0.45, hauteurFenetre()*0.48);		
}

