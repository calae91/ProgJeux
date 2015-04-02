#include "graphics.h"

//Note
/*Changer la consant "vitesse de deplacement" en variable globale et local pour augmenter la vitesse au cours du temps
 * OU la variable "temps d'attente"*/

#define N 20 // nombre d'arbre
#define V 10 // vitesse de deplacement
#define O 10 // nombre d'objet sur le chemin
#define A 15 // Temps d'attente de la boucle

struct paysage {
	POINT p1, p2,p3;
	POINT ombre;
	int d;
	int dx;
	int dy;
};
typedef struct paysage PAYSAGE;

struct personnage {
	POINT p[5][2];
	POINT tete; int r; int a;
};
typedef struct personnage PERSONNAGE;

struct objet {
	POINT p1,p2;
};
typedef struct objet OBJET;

void paysage ()
{
	POINT p1, p2;
	int n=0;
	
	while (n<4)
	{
		p1.x = (n*1200)/4; p1.y = 0;
		p2.x = p1.x + (1200/4); p2.y = 720;
		
		if (n==0 || n==3)
			draw_fill_rectangle(p1,p2,vertclair);
		else draw_fill_rectangle(p1,p2, orange);
		
		n++;
	}
}

//PAYSAGE
PAYSAGE init_paysage(PAYSAGE pay) // A REVOIR
{
	int r=alea_int(2);	
	int c=720;															//Correction d'affichage des arbres en fonction de sa distance
	
	if (r==0)
	{
		pay.dx = alea_int((1200/4)-10);
		pay.dy = alea_int(721)+c;
	}
	else
	{
		pay.dx = alea_int((1200/4)-10) + ((3*1200)/4);
		pay.dy = alea_int(721)+c;
	}
	
	return pay;
}

PAYSAGE position_obj_paysage(PAYSAGE pay) //A REVOIR
{
		pay.d = 50;														//Revoir le positionnnement et l'affichage(couleur...) de l'ombre
		
		pay.p1.x = pay.dx; pay.p1.y = pay.dy; 
		pay.p2.x = pay.p1.x + 20; pay.p2.y = pay.p1.y + 100;
		
		pay.p3.x = pay.p1.x + 10; pay.p3.y = pay.p2.y + pay.d;
		
		pay.ombre.x = pay.dx +10; pay.ombre.y = pay.dy;

	return pay;
}

PAYSAGE deplacement_obj_paysage(PAYSAGE pay)
{
		pay.dy = pay.dy - V;

	return pay;
}

PAYSAGE retour_au_point_de_depart_paysage(PAYSAGE pay)
{
	if (pay.p3.y<0)
	{
		pay=init_paysage(pay);
	} 
	
	return pay;
}

void affiche_obj_paysage(PAYSAGE pay)
{
		//draw_fill_circle(pay.ombre,pay.d-10,gris); //affichage de l'ombre
		draw_fill_circle(pay.p3,pay.d,vert); // affichage des feuilles
		draw_fill_rectangle(pay.p1,pay.p2,marron); // affichage du tron
}

//PERSONNAGE
PERSONNAGE init_personnage(PERSONNAGE pers)
{
	int n=1;
	
	//tron
//	pers.p[0][0].x = (2*1200)/4 - (1200/4)/2 ;
	pers.p[0][0].y = 70;
	pers.p[0][1].x = pers.p[0][0].x;
	pers.p[0][1].y = pers.p[0][0].y + 100;
	
	//Les jambes
	while ( n<=2)
	{
		pers.p[n][0].x = pers.p[0][0].x;
		pers.p[n][0].y = pers.p[0][0].y;
		
		pers.p[n][1].y = pers.p[0][0].y -60;
		
		if (n==1)
			pers.p[n][1].x = pers.p[0][0].x -20 ;
		else pers.p[n][1].x = pers.p[0][0].x +20 ;
		
		n++;
	}//n==3
	
	//les bras
	
	while (n<=4)
	{
		pers.p[n][0].x = pers.p[0][1].x;
		pers.p[n][0].y = ((2*pers.p[0][1].y)+75)/3;
		
		pers.p[n][1].y = pers.p[n][0].y -50;
		
		if (n==3)
			pers.p[n][1].x = pers.p[0][1].x -20 ;
		else pers.p[n][1].x = pers.p[0][1].x +20 ;
		
		n++;
	}//n==5
	
	//tête
	pers.r = 25;
	pers.tete.x = pers.p[0][1].x;
	pers.tete.y = pers.p[0][1].y + pers.r;
	
	return pers;
}

PERSONNAGE deplacemet_personnage(PERSONNAGE pers, POINT p)
{	
	if (p.x<0)
	{
		pers.p[0][0].x = (2*1200)/4 - (1200/4)/2 ;
		pers.a=0;
	}
	else
	{
		if (p.x>0)
		{
			pers.p[0][0].x = (3*1200)/4 - (1200/4)/2 ;
			pers.a=1;
		}
	}
	
	return pers;
}

void affiche_perso(PERSONNAGE pers)
{
	int i=0;
	while (i<5)
	{
		draw_line(pers.p[i][0],pers.p[i][1],noir);
		i++;
	}
	draw_circle(pers.tete, pers.r,noir);
}

//objet sur le chemin (des rectangles rouges)
OBJET init_objet(OBJET obj, OBJET temp) // A REVOIR
{
	obj.p1.x = ((2*1200)/4 - (1200/4)/2) -50 ;							//L'écrat entre chaque objet est trop(voir quasi-inexistant)
	obj.p1.y = temp.p2.y +500;											//Modification du code pour que les objets s'affichent des deux côtés (A faire après)
	
	obj.p2.x = ((2*1200)/4 - (1200/4)/2) +50 ;
	obj.p2.y = obj.p1.y +25;
	
	return obj ;
}

void affiche_objet(OBJET obj)
{
	draw_fill_rectangle(obj.p1,obj.p2,rouge);
}

OBJET deplacement_objet(OBJET obj)
{
	obj.p1.y = obj.p1.y - V;
	obj.p2.y = obj.p1.y +25;
	
	return obj ;
}

OBJET retour_au_point_de_depart_objet(OBJET obj)
{
	if (obj.p1.y<0)
	{						
		obj.p1.y = 720;										

		obj.p2.y = obj.p1.y +25; 
	} 
	
	return obj;
}

int choc(int q, OBJET obj, PERSONNAGE pers) //A REVOIR
{
	if ( (pers.tete.x > obj.p1.x && pers.tete.x < obj.p2.x) && (pers.tete.y > obj.p1.y) )		///Le programme ne s'arrête pas à tous les conflits.
		q=1;																					///Il s'arrête à des objets probablements aleatoire. 
																								//Correction de l'arrêt trop tard (lié au centre de la tête)
	return q;
}

int main()
{
	init_graphics(1200,720);

	PAYSAGE pay[N];
	PERSONNAGE pers;
	OBJET obj[O];
	
	POINT p;
	
	int q=0;
	
	pers.a=0;
	pers.p[0][0].x = (2*1200)/4 - (1200/4)/2 ;
	
	int n=0;
	
	while (n<N)
	{
		pay[n]=init_paysage(pay[n]);
		n++;
	}
	n=1;
	
	obj[0].p1.x = ((2*1200)/4 - (1200/4)/2) -50 ;							
	obj[0].p1.y = 720;										
	
	obj[0].p2.x = ((2*1200)/4 - (1200/4)/2) +50 ;
	obj[0].p2.y = obj[0].p1.y +25;
	
	while (n<O)
	{
		obj[n]=init_objet(obj[n], obj[n-1]);
		n++;
	}
	n=0;
	
	affiche_auto_off();
	while(q==0)
	{
		paysage();
		
		while (n<N)
		{
			pay[n]=position_obj_paysage(pay[n]);
			affiche_obj_paysage(pay[n]);
			pay[n]=deplacement_obj_paysage(pay[n]);
			pay[n] = retour_au_point_de_depart_paysage(pay[n]);

			n++;
		}
		n=1;
		
		while (n<O)
		{
			affiche_objet(obj[n]);
			obj[n] = deplacement_objet(obj[n]);
			obj[n] = retour_au_point_de_depart_objet(obj[n]);
			
			q=choc(q,obj[n],pers);
			
			n++;
		}
		
		p= get_arrow();
		pers=deplacemet_personnage(pers,p);
		pers = init_personnage(pers);
		affiche_perso(pers);
		
		affiche_all();
		attendre(A);
		n=0;
	}
	
// Fin du code
wait_escape();
exit(0);
}
