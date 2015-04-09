#include "graphics.h"

#define LON 1200
#define LAR 720
#define R 20
#define E 50
#define FOND noir
#define GRILLE rouge
#define PB (3*LAR)/4
#define PH 1-PB

void cercle()
{
	POINT p;
	p.x = E + R; p.y = E + R;
	
	while (p.x + E< LON && p.x - E > 0)
	{
		while (p.y + E  < PB && p.y -E > 0)
		{
			draw_fill_circle(p,R,FOND);
			p.y = p.y +E;
		}
		p.x = p.x +E;
		p.y = E + R;
	}
}

void grille()
{
	POINT p1,p2;
	
	p1.x = E; p1.y = E;
	p2.x = LON-E; p2.y = PB -E;
	draw_fill_rectangle(p1,p2,GRILLE);
	
	cercle();
}

int main ()
{
	init_graphics(LON,LAR);
	
	grille();
	
wait_escape();
exit(0);
}
