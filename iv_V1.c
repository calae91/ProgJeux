#include "graphics.h"

/* char s[14] = "Hello\0World!";
   printf ("%s\n", s); */
   
#define Q 100 //nombre de carractère max
   
// Variable globale (texte)
char q[Q];

void Question_utilisateur()
{
	int i=0; //variable liée à q
	
	printf("Ecrivez mot par mot votre phrase /n" );
	printf("Votre phrase doit comporter au maximun 10 mots /n" ); //temporaire
	printf("Quand vous avez terminer votre phrase tapez STOP exactement /n" );
	
	
}

int main ()
{
	//init_graphics(500,500);	


// Fin du code
	wait_escape();
	exit(0);
}
