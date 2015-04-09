#include "graphics.h"

//128 cases au total
#define LON 320 //multiple de 8 (8 cases)
#define LAR 2*LON // (16 cases)
#define E LON/8
#define D 20 //centre de la case
#define R D-1 //rayon du cercle

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

void init_boule(BOULE b[128])
{
	int n=1;
	int a;
	int h=0;
	
	b[0].centre.x = D; b[0].centre.y = D;
	b[0].c=bleu;
	
	while ((b[n-1].centre.x)+2*D < LON && n<128)
	{
		while ((h==1 || (b[n-1].centre.y)+ 2*D < LAR)  && n<128)
		{
			a = alea_int(4);
			
			if (h==1)
			{
				b[n].centre.x = b[n-1].centre.x +2*D;
				b[n].centre.y = D;
			}
			else
			{
				b[n].centre.x = b[n-1].centre.x;
				b[n].centre.y = b[n-1].centre.y + 2*D;
			}
			
			if(a==0)
				b[n].c=bleu;
			if(a==1)
				b[n].c=rouge;
			if(a==2)
				b[n].c=vert;
			if(a==3)
				b[n].c=jaune;
			
			h=0;
			n++;
		}
		h=1;
	}

}

void affiche_boule(BOULE b)
{
	draw_fill_circle(b.centre,R,b.c);
}

int main ()
{
	init_graphics(LON,LAR);
	
	BOULE b[128];
	int n=0;
	
	affichage_plateau();
	init_boule(b);
	
	while (n<128)
	{
		affiche_boule(b[n]);
		n++;
	}
	
// Fin du code
wait_escape();
exit(0);
}
