#include "graphics.h"

//Variable du jeu
int l=0; // longueur de la fenêtre
int L=0; // largeur de la fenêtre

int temps=0; // le chrono de spon

//Variable Equipe 1 (faible)
POINT E1 [5][2]; // 5 cube et 2 pour 1 cube
int a=0; /* pour 5 */ int sauvegardeA=0; // sauvegarde de a
int z=0; // pour 2

void quadrillage()
{
	POINT p1, p2;
	
	p1.x = l/10 ; p1.y=0;
	p2.x = l/10 ; p2.y=L;
	draw_line(p1,p2,blanc);
	
	p1.x =l-(l/10) ; p1.y=0;
	p2.x =l-(l/10) ; p2.y=L;
	draw_line(p1,p2,blanc);
}

void spon_alea_E1() // coté gauche de la fenêtre
{
	int temp1=alea_int((l+1)/10);
	int temp2=alea_int(L+1);
	
	E1[a][z].x = temp1-10 ; E1[a][z].y= temp2-10;
	z=z+1;
	E1[a][z].x = temp1 ; E1[a][z].y= temp2;
	z=0;
	
	draw_fill_rectangle(E1[a][z],E1[a][z+1],bleu);
}

void deplacement_E1()
{
	POINT t1,t2; // variable de sauvegarde temporaire
	
	int n=0;
	
	int d=0;
	int f=0;
	
	while(E1[a][0].x <= l/10)
	{
		d = alea_int(5);
		f = alea_int(5);
		
		t1.x=E1[a][0].x ; t1.y=E1[a][0].y ;
		t2.x=E1[a][1].x ; t2.y=E1[a][1].y ;
		
		if (E1[a][0].y < L/2)
		{
			E1[a][0].x = E1[a][0].x+d ;
			E1[a][0].y = E1[a][0].y+f;
			
			E1[a][1].x = E1[a][1].x+d ;
			E1[a][1].y = E1[a][1].y+f;
		}
		else
		{
			E1[a][0].x = E1[a][0].x-d ;
			E1[a][0].y = E1[a][0].y-f;
			
			E1[a][1].x = E1[a][1].x-d ;
			E1[a][1].y = E1[a][1].y-f;
		}
		
		draw_fill_rectangle(t1,t2,noir);
		draw_fill_rectangle(E1[a][0],E1[a][1],bleu);
		
		quadrillage();
		
	}
	
	n=alea_int(2);	
	
	d=0;
	f=0;
	
	d = alea_int(5);
	f = alea_int(5);
		
	t1.x=E1[a][0].x ; t1.y=E1[a][0].y ;
	t2.x=E1[a][1].x ; t2.y=E1[a][1].y ;
		
	if ((E1[a][1].x +(d*2) <= l-(l/10) && E1[a][1].y+(f*2) <=L) || (E1[a][0].x -(d*2) >= l-(l/10) && E1[a][0].y-(f*2) >=0))
	{
		if (n==0)
		{
			E1[a][0].x = E1[a][0].x+d ;
			E1[a][0].y = E1[a][0].y+f;
				
			E1[a][1].x = E1[a][1].x+d ;
			E1[a][1].y = E1[a][1].y+f;
		}
		else
		{
			E1[a][0].x = E1[a][0].x-d ;
			E1[a][0].y = E1[a][0].y-f;
			
			E1[a][1].x = E1[a][1].x-d ;
			E1[a][1].y = E1[a][1].y-f;
		}
	}
	
	affiche_auto_off();	
	draw_fill_rectangle(t1,t2,noir);
	draw_fill_rectangle(E1[a][0],E1[a][1],bleu);
		
	quadrillage();
	affiche_all();
	
}



int main()
{
	printf("Définissez la fenêtre : \n");
	printf("la longueur de la fenetre : \n");
	l=lire_entier_clavier();
	printf("la largeur de la fentre : \n");
	L=lire_entier_clavier();
	
	init_graphics(l,L);
	
	quadrillage();
	
	printf("Ajout d'un membre de l'equipe 1  \n");
	a=0;
	z=0;
	spon_alea_E1();
	
	deplacement_E1();
	
	while(12)
	{
		deplacement_E1();
	}
	
// Fin du code
	wait_escape();
	exit(0);
}
