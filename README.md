# ProjetC
Projet du cours de c.

La methode void viderBuffer(); est la en remplacement de l'instruction fflush(stdin); , car fflush est plus que déconseillé pour vider le buffer après une saisie! Pour plus de précisions ----> https://openclassrooms.com/forum/sujet/vider-le-buffer-14371   .fflush ne compilera pas avec certain ide (ex : gcc) et ne fonctionnera pas sur un OS different de windows!
