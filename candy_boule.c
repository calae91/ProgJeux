#include "graphics.h"

//128 cases au total
#define LON 320 //multiple de 8 (8 cases)
#define LAR 2*LON // (16 cases)
#define E LON/8

struct boule {
	POINT centre; // position de la boule
	COULEUR c; // couleur de la boule
	int v; // valeur de la boule (1,2,3,..) en fonction du nombre de couleur
};
typedef struct boule BOULE ;

void affichage_plateau_H(POINT p)
{
	POINT p1;
	
	p1.x = LON; p1.y = p.y;
	
	while (p.y<LAR)
	{
		draw_line(p,p1,noir);
		p.y = p.y +E;
		p1.y=p.y;
	}
}

void affichage_plateau_V(POINT p)
{
	POINT p1;
	
	p1.x = p.x ; p1.y = LAR;
	
	while(p.x < LON)
	{
		draw_line(p,p1,noir);
		p.x = p.x +E;
		p1.x=p.x;
	}
}

void affichage_plateau()
{
	POINT p;
	p.x = 0; p.y = 0;
	fill_screen(blanc);
	affichage_plateau_H(p);
	affichage_plateau_V(p);
}

int main ()
{
	init_graphics(LON,LAR);
	
	BOULE b[128];
	
	affichage_plateau();
	
// Fin du code
wait_escape();
exit(0);
}
