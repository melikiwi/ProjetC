#include <stdlib.h>
#include <stdio.h>

//Declaration et initialisation des Constantes.
#define sizeNom 31
#define sizePrenom 31
#define sizeDateNaiss 11
#define sizeNumCompte 20
#define sizeNumRegNat 14

//Prototype de fonction.
void viderBuffer();
int checkSize(char* tab, int size);
int isEmpty(char* tab);
int verifnom(char* chaine);
int verifprenom(char* chaine);
int verifdatenaiss (char* chaine);
int verifnumcompte (char* chaine);
int verifnumregnat(char* chaine);
int compatibildatenaissregnat(char* dateofbirth, char* numregnat);
void enterName(char* tab);
void enterFirstName(char* tab);
void enterDateOfBirth(char* tab);
void enterAccountNumber(char* tab);
void enterNationalRegistryNumber(char* tab);
void enterDateAndRegNum(char* date,char* reg);
int enterNumber(int size);
int stringToNumber(char* tab);
int checkNumber(char* tab);
struct clientA encodenouvclientA(void);
struct clientB encodenouvclientB(void);
void stringcopy (char* source, char* destination);
void fillTabStructA(struct clientA* tab, int top, int end);
void fillTabStructB(struct clientB* tab, int top, int end);
void structclientAcopy (struct clientA source, struct clientA* destination);
void structclientBcopy (struct clientB source, struct clientB* destination);
void printTabStructA(struct clientA* tab, int size);
void printTabStructB(struct clientB* tab, int size);

/**
 *Creation d'une structure client, contenant le nom du client, son prenom, sa date de naissance, son numero de compte et son numero
 *de registre national.
 */
typedef struct clientA clientA;
struct clientA{

char nom [sizeNom];
char prenom [sizePrenom];
char datenaiss [sizeDateNaiss] ;
char num_compte [sizeNumCompte] ;
char num_reg_nat [sizeNumRegNat] ;
};

/**
 *Creation d'une structure client, contenant le nom du client, son prenom et sa date de naissance.
 */
typedef struct clientB clientB;
struct clientB{

char nom [sizeNom];
char prenom [sizePrenom];
char datenaiss [sizeDateNaiss] ;
};

main(){
	struct clientA client[10];
	system("cls");
	fillTabStructA(client, 0, 1);
	printTabStructA(client, 2);
}

/**
 *Methode vidant le buffer.
 *
 *@pre:/
 *@post: Vide le buffer.
 */
void viderBuffer(){

    //Declaration et initialisation des variables.
    char c = 0;

 	//Bloc d'instruction.
    while (c != '\n' && c != EOF && c !='\0'){//Parcours le "tableau" de saisie non enregistre et place le "curseur" a sa fin.
        c = getchar();
    }
}

/**
 *Methode verifiant si la chaine de caracteres rentrees a la bonne taille.
 *
 *@pre:/
 *@post: Renvoie 1 si la chaine a la bonne taille, 0 sinon.
 */
int checkSize(char* tab, int size){

	//Declaration et initialisation des variables.
	int charCounter, error;
	error = 1;

	 //Bloc d'instruction.
	for(charCounter = 0; tab[charCounter] != '\0'; charCounter++);//Boucle comptant le nombre de caracteres de la chaine.
	if(charCounter > size-1){
		error = 0;
		printf("Vous avez depass%c le nombre de cartact%cre autoris%c!\n",130,138,130);
	}
	return(error);
}

/**
 *Methode verifiant que la chaine de caracteres n'est pas vide.
 *
 *@pre:/
 *@post: Renvoie 1 si la chaine de caracteres n'est pas vide, 0 sinon.
 */
int isEmpty(char* tab){

	//Declaration et initialisation des variables.
	int error = 1;

	//Bloc d'instruction.
	if(tab[0] == '\0'){
		error = 0;
		printf("Vous avez effectu%c une saisie vide!\n",130);
	}
	return(error);
}

/**
 *Methode verifiant si le nom entre est un nom valide.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaine de caracteres ne correspond pas à un nom de client valide et retourne la valeur 1 dans le cas contraire.
 *       Un nom est valide si il est compose des caracteres suivant: l’espace blanc (code ascii 32) et les 26 lettres majuscules non accentuees de
 *       l’alphabet (code ascii compris entre 65 et 90). Un nom de client ne peut pas commencer par un espace blanc.
 */
int verifnom(char* chaine){

    //Declaration et initialisation des variables.
	int error = 1; //Variable prenant la valeur 1 ou 0 respectivement si le nom est valide ou non.
	int i;

	//Bloc d'instruction.
	if(chaine[0] == 32){//Verifie que la chaine ne commence pas par un espace.
        error = 0;
        printf("Votre nom ne peut pas commencer par un espace!\n");
	}
	else{
		//Bloc verifiant que tous les caracteres composant le nom sont des composants valides.
		for(i = 0; chaine[i] != '\0' && error == 1; i++){
				if(chaine[i] != 32 && (chaine[i] < 65 || chaine[i] > 90)){
					error = 0;
					printf("Vous avez entr%c des caract%cres non valide!\n",130,138);
				}
			}
	}
	return(error);
}

/**
 *Methode verifiant si le prenom entre est un prenom valide.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaine de caracteres ne correspond pas à un prenom de client valide
 *       et retourne la valeur 1 dans le cas contraire. Un prenom est valide si il est compose des caracteres suivant: l'espace blanc (code ascii 32),
 *       le tiret (code ascii 45) et les 26 lettres majuscules non accentuees de l’alphabet (code ascii compris entre 65 et 90). Un prenom de client
 *       ne peut pas commencer par un espace blanc ni par un tiret.
 */
int verifprenom(char* chaine){

    //Declaration et initialisation des variables.
	int error = 1; //Variable prenant la valeur 1 ou 0 respectivement si le prenom est valide ou non.
	int i;

    //Bloc d'instruction.
	if(chaine[0] == 45){//Verifie que la chaine ne commence pas par un tiret
        error = 0;
        printf("Votre prenom ne peut pas commencer par un tiret!\n");
    }
	else if(chaine[0] == 32){//Verifie que la chaine ne commence pas par un espace.
        error = 0;
        printf("Votre prenom ne peut pas commencer par un espace!\n");
	}
    //Bloc verifiant que tous les caracteres composant le prenom sont des caracteres valides.
    for(i = 0; chaine[i] != '\0' && error == 1; i++){
        if((chaine[i] != 32 || chaine[i] != 45) && (chaine[i] < 65 || chaine[i] > 90)){
            error = 0;
            printf("Vous avez entr%c des caract%cres non valide!\n",130,138);
        }
    }
	return error;
}

/**
 *Methode verifiant si la date de naissance entre est une date valide.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaîne de caracteres ne correspond pas à une date de naissance valide et retourne la valeur 1 dans le cas contraire.
 */
int verifdatenaiss (char* chaine){

    //Declaration et initialisation des variables.
    int erreur, digitCounter, i, jour, mois, annee;
    erreur = 1;
    digitCounter = 0;

    //Bloc d'instruction.
	if(chaine[2] == '/' && chaine[5] == '/'){//Verifie que les "/" sont bien positionnes.
		for(i = 0; i < 10 ; i++){//Boucle verifiant si l'utilisateur a bien rentre des chiffres aux bons endroits.
			if(chaine[i] < 58 && chaine[i] > 47 ){
					digitCounter ++;
			}
		}
		if(digitCounter == 8){
			//Conversion de la chaine de caractere en chiffre.
			jour = (chaine[0] - 48) * 10 + (chaine[1] - 48);
			mois = (chaine[3] - 48) * 10 + (chaine[4] - 48);
			annee = (chaine[6] - 48) * 1000 + (chaine[7] - 48) * 100 +(chaine[8] - 48) * 10 +(chaine[9] - 48);

			if(jour < 1 || jour > 31){
				erreur = 0;
				printf("Vous avez rentr%c un nombre de jours impossibles!\n",130);
			}
			if(mois < 1 || mois > 12){
				erreur = 0;
				printf("Vous avez rentr%c le numero d'un mois inexistant!\n",130);
			}
			if(annee < 1905 || annee > 1996){
				erreur = 0;
				printf("Vous avez rentr%c une ann%ce non valide!\n",130,130);
			}
			if(erreur != 0 && (mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour == 31){
				erreur = 0;
				printf("Il n'y a pas 31 jours pour ce mois la!\n");
			}
			else if(erreur != 0 && mois == 2 && jour > 28){
				if(jour > 29){
					erreur = 0;
					printf("Il ne peut y avoir plus de 29 jours en fevrier!\n");
				}
				else if(jour == 29 && annee % 4 != 0){
					erreur = 0;
					printf("L'ann%ce n'est pas bisextille, donc il ne peut-il y avoir 29 jours en fevrier!\n",130);
				}
			}
		}
		else{
			erreur = 0;
			printf("Vous avez rentr%c d'autre caract%cre que des chiffres dans les emplacements correspondants!\n",130,138);
		}
    }
    else{
		erreur = 0;
		printf("Le format de la date n'est pas valide!\n");
    }
    return erreur;
}

/**
 *Methode verifiant si le numero de compte est valide.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaîne de caractères ne correspond pas à un numéro de compte bancaire valide et retourne la valeur 1 dans le cas
 *       contraire.
 */
int verifnumcompte (char* chaine){

    //Declaration et initialisation des variables.
	int i, digitCounter, error;
	error = 1;
	digitCounter = 0;

    //Bloc d'instruction.
	if(chaine[0] != 66 || chaine[1] != 69){//Verifie que le numero de compte commence par BE.
        error = 0;
        printf("Votre numero de compte doit commencer par BE!\n");
	}
	else if(chaine[4] == 32 && chaine[9] == 32 && chaine[14] == 32){//Verifie que les espaces sont bien positionne.
		for(i = 2; i < 19; i++){//Boucle verifiant si l'utilisateur a bien rentre des chiffres aux bons endroits.
			if(chaine[i] >= 48 && chaine[i] <= 57){
				digitCounter ++;
			}
		}
		if(digitCounter != 14){//Verifie qu'il y a bien le bon nombre de chiffre.
            error = 0;
            printf("Vous avez rentr%c d'autre caract%cre que des chiffres dans les emplacements correspondants!\n",130,138);
		}
	}
	else{
        error = 0;
		printf("Le format de votre numero de compte n'est pas valide!\n");
	}
	return(error);
}

/**
 *Methode verifant le numero de registre national.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaine de caracteres ne correspond pas a un numero de registre national valide et retourne la valeur 1 dans le
 *       cas contraire.
 */
int verifnumregnat(char* chaine){

    //Declaration et initialisation des variables.
    int digitCounter, i, isTrue;
    isTrue = 1;
    digitCounter = 0;

    //Bloc d'instruction.
	if (chaine[6] == '-' && chaine[10] == '-'){//Verifie que les tirets sont bien positionne.
		for(i = 0; i < 13; i++){//Boucle verifiant si l'utilisateur a bien rentre des chiffres aux bons endroits.
			if(chaine[i] < 58 && chaine[i] > 47){
				digitCounter ++;
			}
		}
		if(digitCounter != 11){//Verifie qu'il y a bien le bon nombre de chiffre.
			isTrue = 0;
			printf("Vous avez rentr%c d'autre caract%cre que des chiffres dans les emplacements correspondants!\n",130,138);
		}
    }
    else{
        isTrue = 0;
        printf("Le format de votre numero de registre national n'est pas valide!\n");
    }
    return(isTrue);
}

/**
 *Methode verifiant la compatibilite entre la date de naissance et le numero de registre national.
 *
 *@pre: dateofbirth a ete initialise, numregnat a ete initialise.
 *@post: Retourne la valeur 1 si la date de naissance est compatible avec le numéro de registre national (Les deux premiers chiffres du numero de
 *       registre national correspondent a l’annee de naissance; les deux suivants au mois de la naissance tandis que le 5eme et 6eme chiffre
 *       correspondent au jour de la naissance) et retourne la valeur 0 dans le cas contraire.
 */
int compatibildatenaissregnat(char* dateofbirth, char* numregnat){

    //Declaration et initialisation des variables.
    int isTrue = 1;

    //Bloc d'instruction.
    //Verifie si l'annee de la date de naissance correspond a l'annee du registre national.
    if(numregnat[0] != dateofbirth[8] || numregnat[1] != dateofbirth[9]){
        isTrue = 0;
        printf("L'ann%ce de votre date de naissance ne correspond pas %c celle de votre registre national!\n",130,133);
    }
    //Verifie si le mois de la date de naissance correspond au mois du registre national.
    if(numregnat[2] != dateofbirth[3] || numregnat[3] != dateofbirth[4]){
        isTrue = 0;
        printf("Le mois de votre date de naissance ne correspond pas %c celui de votre registre national!\n",133);
    }
    //Verifie si le jour de la date de naissance correspond au jour du registre national.
    if(numregnat[4] != dateofbirth[0] || numregnat[5] != dateofbirth[1]){
		isTrue = 0;
		printf("Le jour de votre date de naissance ne correspond pas %c celui de votre registre national!\n",133);
    }
    return(isTrue);
}

/**
 *Methode permettant a l'utilisateur de rentrer un nom de client.
 *
 *@pre:/
 *@post: Place dans tab le nom du client apres l'avoir verifie.
 */
void enterName(char* tab){

    //Declaration et initialisation des variables.
	char tempon[100];
	int boolean;//Variable passant a 0 (faux) lorsque l'utilisateur entre un nom valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	viderBuffer();
	do{
		printf("Veuillez entrer le nom du client en majuscule!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizeNom)){//Verifie que l'utilisateur n'as pas depasse la longueur maximale.
			stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
			if(isEmpty(tab)){//Verifie que la saisie n'est pas vide.
				boolean = verifnom(tab);
			}
		}
	}
	while(boolean != 1);
}

/**
 *Methode permettant a l'utilisateur de rentrer un prenom de client.
 *
 *@pre:/
 *@post: Place dans tab le prenom du client apres l'avoir verifie.
 */
void enterFirstName(char* tab){

    //Declaration et initialisation des variables.
	char tempon[100];
	int boolean;//Variable passant a 0 (faux) lorsque l'utilisateur entre un prenom valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	viderBuffer();
	do{
		printf("Veuillez entrer le prenom du client en majuscule!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizePrenom)){//Verifie que l'utilisateur n'as pas depasse la longueur maximale.
			stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
			if(isEmpty(tab)){//Verifie que la saisie n'est pas vide.
				boolean = verifprenom(tab);
			}
		}
	}
	while(boolean !=1);
}

/**
 *Methode permettant a l'utilisateur de rentrer la date de naissance d'un client.
 *
 *@pre:/
 *@post: Place dans tab la date de naissance du client apres l'avoir verifie.
 */
void enterDateOfBirth(char* tab){

    //Declaration et initialisation des variables.
	char tempon[100];
	int boolean;//Variable passant a 0 (faux) lorsque l'utilisateur entre une date valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	viderBuffer();
	do{
		printf("Veuillez entrer la date de naissance du client sous le format jj/mm/aaaa!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizeDateNaiss)){//Verifie que l'utilisateur n'as pas depasse la longueur maximale.
			stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
			if(isEmpty(tab)){//Verifie que la saisie n'est pas vide.
				boolean = verifdatenaiss(tab);
			}
		}
	}
	while(boolean !=1);
 }

/**
 *Methode permettant a l'utilisateur de rentrer une numero de compte.
 *
 *@pre:/
 *@post: Place dans tab le numero de compte du client apres l'avoir verifie.
 */
void enterAccountNumber(char* tab){

    //Declaration et initialisation des variables.
	char tempon[100];
	int boolean;//Variable passant a 0 (faux) lorsque l'utilisateur entre un numero valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	viderBuffer();
	do{
		printf("Veuillez entrer le numero de compte du client sous le format BExx xxxx xxxx xxxx!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizeNumCompte)){//Verifie que l'utilisateur n'as pas depasse la longueur maximale.
			stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
			if(isEmpty(tab)){//Verifie que la saisie n'est pas vide.
				boolean = verifnumcompte(tab);
			}
		}
	}
	while(boolean != 1);
 }

 /**
 *Methode permettant a l'utilisateur de rentrer une numero de registre national.
 *
 *@pre:/
 *@post: Place dans tab le numero de registre national du client apres l'avoir verifie.
 */
void enterNationalRegistryNumber(char* tab){

    //Declaration et initialisation des variables.
	char tempon[100];
	int boolean;//Variable passant a 0 (faux) lorsque l'utilisateur entre un numero valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	viderBuffer();
	do{
		printf("Veuillez entrer le numero de registre national du client sous le format xxxxxx-xxx-xx!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizeNumRegNat)){//Verifie que l'utilisateur n'as pas depasse la longueur maximale.
			stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
			if(isEmpty(tab)){//Verifie que la saisie n'est pas vide.
				boolean = verifnumregnat(tab);
			}
		}
	}
	while(boolean != 1);
 }

/**
 *Methode permetant a l'utilisateur d'entrer un numero de registre national correspondant a la date de naissance.
 *
 *@pre:/
 *@post: Place dans date la date de naissance et dans re le numero de registre national apres les avoir verifier et verifier qu'ils correspondent.
 */
void enterDateAndRegNum(char* date,char* reg){

	//Declaration et initialisation des variables.
	int boolean = 3;//Variable prenant la valeur 0 si la date et le reg coincide,1 si l'user veut rentrer la date, 2 s'il veut rentrer le reg et 3 s'il veut rentrer les 2.

	//Bloc d'instruction.
	do{
		if(boolean == 1 || boolean == 3){
			enterDateOfBirth(date);
		}
		if(boolean == 2 || boolean == 3){
			enterNationalRegistryNumber(reg);
		}
		if(!(compatibildatenaissregnat(date, reg))){//Verifie que le numero de registre coincide avec la date de naissance.
			printf("Vous avez rentr%c comme date de naissance: ",130);
			puts(date);
			printf("et comme numero de registre national: ");
			puts(reg);
			printf("Voulez vous changer la date de naissance(taper 1), le numero de registre national(taper 2) ou les deux(taper 3)?\n");
			boolean = enterNumber(3);//Stocke dans la variable boolean la valeur rentre par l'utilisateur.
		}
		else{
			boolean = 0;
		}
	}
	while(boolean);
}

/**
 *Methode demandant a l'utilisateur de rentrer un nombre.
 *
 *@pre: size doit doit etre initialise et size > 0.
 *@post: Renvoie le nombre entre par l'utilisateur si il est plus petit ou egal a size.
 */
int enterNumber(int size){

	//Declaration et initialisation des variables.
	int number;
	int boolean = 1;
	char tab [20];

	//Bloc d'instruction.
	do{
		do{
			gets(tab);
			viderBuffer();
		}
		while(!(checkNumber(tab)));//Boucle verifiant que c'est bien un nombre qui a ete saisi.
		number = stringToNumber(tab);//Converti la chaine en entier.
		if(number > size || number < 1){//Verifie que le nombre ne depasse pas size.
			printf("Vous avez rentr%c un nombre invalide!\n",130);
		}
		else{
			boolean = 0;
		}
	}
	while(boolean);
}

/**
 *Methode convertissant une chaine de caracteres en nombre entier.
 *
 *@pre: tab dois etre initialise.
 *@post: Renvoie le nombre contenu dans la cahine de caractere tab.
 */
int stringToNumber(char* tab){

	//Declaration et initialisation des variables.
	int number, counter, multiplier;
	number = 0;
	multiplier = 1;

	//Bloc d'instruction.
	for(counter = 0; tab[counter] != '\0';counter++);//Compte le nombre de caractere dans tab.
	while(counter > 0){
		number = number + ((tab[counter - 1] - 48) * multiplier);//Place dans number, number + la valeur cotenue dans tab[counter -1] multiplie par la puissance de 10 correspondante.
		multiplier = multiplier * 10;
		counter --;
	}
	return(number);
}

/**
 *Methode verifiant que l'utilisateur a rentre un nombre.
 *
 *@pre:/
 *@post: Retourne 1 si l'utilisateur a saisi un nombre, 0 sinon.
 */
int checkNumber(char* tab){

	//Declaration et initialisation des variables.
	int  i, boolean;

	//Bloc d'instruction.
	boolean = isEmpty(tab);
	for(i = 0; tab[i] != '\0' && boolean; i++){
		if(tab[i] > 57 || tab[i] < 48){//Verifie que le caractere est un chiffre.
			boolean = 0;
			printf("Vous avez rentr%c autre chose q'un nombre, recommencez!\n",130);
		}
	}
	return(boolean);
}

/**
 *Methode permettant a l'utilisateur d'encoder un client type A.
 *
 *@pre:/
 *@post: Remplit un "clientB" avec les donnees rentrees par l'utilisateur apres avoir verifier leur validite.
 */
struct clientA encodenouvclientA(void){

    //Bloc d'instruction.
	clientA client;
	enterName(client.nom);
	enterFirstName(client.prenom);
	enterDateAndRegNum(client.datenaiss,client.num_reg_nat);
	enterAccountNumber(client.num_compte);
	return(client);
}

/**
 *Methode permettant a l'utilisateur d'encoder un client type B.
 *
 *@pre:/
 *@post: Remplit un "clientB" avec les donnees rentrees par l'utilisateur apres avoir verifier leur validite.
 */
struct clientB encodenouvclientB(void){

	//Bloc d'instruction.
	clientB client;
	enterName(client.nom);
	enterFirstName(client.prenom);
	enterDateOfBirth(client.datenaiss);
	return(client);
}
/**
 *Methode qui copie le contenu d'un tableau dans un autre.
 *
 *@pre:/
 *@post: Copie les caractères se trouvant dans la chaîne de caractères source (y compris la marque de fin de chaîne) et de les placer
 *       dans la chaîne de caractères destination.
 */
void stringcopy (char* source, char* destination){

    //Declaration et initialisation des variables.
	int i;

    //Bloc d'instruction.
	for(i = 0; source[i] != '\0'; i++){
		destination[i] = source[i];
	}
	destination[i] = '\0';//Ajoute a la fin de la chaine le caractere de fin de chaine.
}

/**
 *Methode remplissant un tableau de structure clientA avec les entres utilisateurs.
 *
 *@pre: top >= 0; end > 0 && end > top.
 *@post: Remplit tab de clientA de top, l'indice de départ jusqu'a end l'indice de fin.
 */
void fillTabStructA(struct clientA* tab, int top, int end){

	//Declaration et initialisation des variables.
	int i;

	//Bloc d'instruction.
	for(i = top; i <= end; i++){
		structclientAcopy(encodenouvclientA(), &(tab[i]));
	}
}

/**
 *Methode remplissant un tableau de structure clientB avec les entres utilisateurs.
 *
 *@pre: top >= 0; end > 0 && end > top.
 *@post: Remplit tab de clientB de top, l'indice de départ jusqu'a end l'indice de fin.
 */
void fillTabStructB(struct clientB* tab, int top, int end){

	//Declaration et initialisation des variables.
	int i;

	//Bloc d'instruction.
	for(i = top; i <= end; i++){
		structclientBcopy(encodenouvclientB(), &(tab[i]));
	}
}

/**
 *Methode qui copie le contenu d'une structure dans une autre.
 *
 *@pre:/
 *@post: Copie les informations se trouvant dans la structure clientA source et de les placer dans la structure clientA dont destination contient
 *       l’adresse.
 */
void structclientAcopy (struct clientA source, struct clientA* destination){

    //Bloc d'instruction.
	stringcopy(source.nom, (*destination).nom);
	stringcopy(source.prenom, (*destination).prenom);
	stringcopy(source.datenaiss, (*destination).datenaiss);
	stringcopy(source.num_compte, (*destination).num_compte);
	stringcopy(source.num_reg_nat, (*destination).num_reg_nat);
}

/**
 *Methode qui copie le contenu d'une structure dans une autre.
 *
 *@pre:/
 *@post: Copie les informations se trouvant dans la structure clientB source et de les placer dans la structure clientB dont destination contient
 *l’adresse.
 */
 void structclientBcopy (struct clientB source, struct clientB* destination){

    //Bloc d'instruction.
	stringcopy(source.nom, (*destination).nom);
	stringcopy(source.prenom, (*destination).prenom);
	stringcopy(source.datenaiss, (*destination).datenaiss);
 }

/**
 *Methode affichant les clients de la banque A.
 *
 *@pre: Il doit il y avoir au moins un client dans tab.
 *@post: Affiche tous les clientA contenu dans tab.
 */
void printTabStructA(struct clientA* tab, int size){

    //Declaration et initialisation des variables.
    int i;

    //Bloc d'instruction.
    system("cls");
    printf("Client de la banque A:\n");
    for(i = 0; i < size; i++){//Boucle parcourant le tableau de structure.
		//Affichage des informations du client.
        printf("Client n%c%d\n",167,i+1);
        printf("Nom : ");
        puts(tab[i].nom);
		printf("Prenom : ");
        puts(tab[i].prenom);
		printf("Date de naissance : ");
        puts(tab[i].datenaiss);
		printf("Numero de registre national : ");
        puts(tab[i].num_reg_nat);
		printf("Numero de compte : ");
        puts(tab[i].num_compte);
        printf("\n");
    }
}

/**
 *Methode affichant les clients de la banque B.
 *
 *@pre: Il doit il y avoir au moins un client dans tab.
 *@post: Affiche tous les clientB contenu dans tab.
 */
void printTabStructB(struct clientB* tab, int size){

    //Declaration et initialisation des variables.
    int i;

    //Bloc d'instruction.
    system("cls");
    printf("Clients de la banque B:\n");
    for(i = 0; i < size; i++){//Boucle parcourant le tableau de structure.
		//Affichage des informations du client.
        printf("Client n%c%d\n",167,i+1);
        printf("Nom : ");
        puts(tab[i].nom);
		printf("Prenom : ");
        puts(tab[i].prenom);
		printf("Date de naissance : ");
        printf("\n");
    }
}
