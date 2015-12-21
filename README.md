# ProjetC
Projet du cours de c.

premiere soumision{
La methode void viderBuffer(); est la en remplacement de l'instruction fflush(stdin); , car fflush est plus que déconseillé pour vider le buffer après une saisie! Pour plus de précisions ----> https://openclassrooms.com/forum/sujet/vider-le-buffer-14371   .fflush ne compilera pas avec certain ide (ex : gcc) et ne fonctionnera pas sur un OS different de windows!

les commentaires en debut de methode : /**
                                        *.....
                                        *
                                        *@pre:
                                        *@post:
                                        */
sont ce qu'on appel la cdoc comme vous avez sans doute vu la javadoc au cours de java.  
pre = precondition c'est a dire les conditions dans lequelles doivent être les variables passées en argument avant l'exécution de la methode.  
post = postcondition c'est a dire ce que la fonction fait ou renvoi.

les methode int enterNumber(int size);, int stringToNumber(char* tab); et int checkNumber(char* tab);, ont été ecrite pour verifier que l'utilisateur rentre bien un nombre. Leurs descriptions sont dans la cdoc au dessus des dites fonctions.
}
