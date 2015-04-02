#include "graphics.h"

/* char s[14] = "Hello\0World!";
   printf ("%s\n", s); */
   
// Variable globale (texte)
char q[11];

void Question_utilisateur()
{
	int i=0; //variable liée à q
	
	printf("Ecrivez mot par mot votre phrase /n" );
	printf("Votre phrase doit comporter au maximun 10 mots /n" ); //temporaire
	printf("Quand vous avez terminer votre phrase tapez STOP exactement /n" );
	
	while (i<11)
	{
		if (i!=10)
		{
			q[i]=lire_entier_clavier();
		}
		else
		{
			q[i]="STOP";
		}
		printf ("%s\n", s); //test
		i++;
	}
	
}

int main ()
{
	


// Fin du code
	wait_escape();
	exit(0);
}
