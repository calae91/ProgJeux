#include "graphics.h"

#define LON 320
#define LAR 2*LON
#define E LON/8

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
	
	affichage_plateau_H(p);
	affichage_plateau_V(p);
}

int main ()
{
	init_graphics(LON,LAR);
	fill_screen(blanc);
	
	affichage_plateau();
	
// Fin du code
wait_escape();
exit(0);
}
