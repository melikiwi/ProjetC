#include <stdlib.h>
#include <stdio.h>

//Declaration et initialisation des Constantes.
#define sizeNom 31
#define sizePrenom 31
#define sizeDateNaiss 11
#define sizeNumCompte 20
#define sizeNumRegNat 14
#define sizeBanque 100
#define sizeTempon 100
#define sizeClientA 108
#define sizeClientB 74

//Prototype des fonctions.
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
void printClientA(struct clientA clientA);
void printClientB(struct clientB clientB);
void printTabStructA(struct clientA* tab, int size);
void printTabStructB(struct clientB* tab, int size);
void structTabACopy(struct clientA* source, struct clientA* destination, int size);
void structTabBCopy(struct clientB* source, struct clientB* destination, int size);
int stringcomp(char* A, char* B);
int structcompA(struct clientA* A,struct clientA* B);
int structcompB(struct clientB* A,struct clientB* B);
void quicksortA(struct clientA* tab, int inf, int sup);
void quicksortB(struct clientB* tab, int inf, int sup);
int concat(char* source, char* destination, int indice);
void structAToString(struct clientA client, char* tab);
void structBToString(struct clientB client, char* tab);
void saveCustomersA(struct clientA* tabClient, int size, int fileNumber);
void saveCustomersB(struct clientB* tabClient, int size, int fileNumber);
int split(char* source, char* destination, int indice);
struct clientA stringToStructA(char* tab);
struct clientB stringToStructB(char* tab);
int loadCustomersA(struct clientA* tabClient, int fileNumber);
int loadCustomersB(struct clientB* tabClient, int fileNumber);
int structComp(struct clientA clientA, struct clientB clientB);
void suprClientA(struct clientA* clientA, int indice, int size);
void suprClientB(struct clientB* clientB, int indice, int size);
void gestionBanqueABanqueB(int* sizeA, int* sizeB, struct clientA* clientA, struct clientB* clientB);

/**
 *Creation d'une structure client, contenant le nom du client, son prenom, sa date de naissance, son
 *numero de compte et son numero de registre national.
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

    //Declaration et initialisation des variables.
	struct clientA sourceA[sizeBanque];
	struct clientA trinomA[sizeBanque];
	struct clientB sourceB[sizeBanque];
	struct clientB trinomB[sizeBanque];
	int sizeA;
	int sizeB;

 	//Bloc d'instruction.
	system("cls");
	sizeA = loadCustomersA(sourceA,1);
	loadCustomersA(trinomA,0);
	sizeB = loadCustomersB(sourceB,1);
	loadCustomersB(trinomB,0);

	printf("lol");


	/*fillTabStructA(sourceA, 0, 1);
	structTabACopy(sourceA, trinomA,2);
	quicksortA(trinomA, 0, 1);
	printTabStructA(trinomA, 2);*/
	saveCustomersA(trinomA, 2, 0);
	loadCustomersA(trinomA,0);
	printTabStructA(trinomA, 2);

}

/**
 *Fonction vidant le buffer.
 *
 *@pre:/
 *@post: Vide le buffer.
 */
void viderBuffer(){

    //Declaration et initialisation des variables.
    char c = 0;

 	//Bloc d'instruction.
	//Parcours le "tableau" de saisie non enregistre et place le "curseur" a sa fin.
    while (c != '\n' && c != EOF && c !='\0'){
        c = getchar();
    }
}

/**
 *Fonction verifiant si la chaine de caracteres rentrees a la bonne taille.
 *
 *@pre: tab n'est pas vide, size > 0.
 *@post: Renvoie 1 si la chaine a la bonne taille, 0 sinon.
 */
int checkSize(char* tab, int size){

	//Declaration et initialisation des variables.
	int charCounter, error;
	error = 1;

	 //Bloc d'instruction.
	for(charCounter = 0; tab[charCounter] != '\0'; charCounter++);/*Boucle comptant le nombre de
	caracteres de la chaine.*/
	if(charCounter > size-1){
		error = 0;
		printf("Vous avez depass%c le nombre de cartact%cre autoris%c!\n",130,138,130);
	}
	return(error);
}

/**
 *Fonction verifiant que la chaine de caracteres n'est pas vide.
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
 *Fonction verifiant si le nom entre est un nom valide.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaine de caracteres ne correspond pas à un nom de client
 *		 valide et retourne la valeur 1 dans le cas contraire. Un nom est valide si il est
 *		 compose des caracteres suivant: l’espace blanc (code ascii 32) et les 26 lettres
 *		 majuscules non accentuees de l’alphabet (code ascii compris entre 65 et 90). Un nom
 *		 de client ne peut pas commencer par un espace blanc.
 */
int verifnom(char* chaine){

    //Declaration et initialisation des variables.
	int error = 1;//Variable prenant la valeur 1 ou 0 respectivement si le nom est valide ou non.
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
 *Fonction verifiant si le prenom entre est un prenom valide.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaine de caracteres ne correspond pas à un prenom de client
 *		 valide et retourne la valeur 1 dans le cas contraire. Un prenom est valide si il est
 *		 compose des caracteres suivant: l'espace blanc (code ascii 32), le tiret (code ascii
 *		 45) et les 26 lettres majuscules non accentuees de l’alphabet (code ascii compris
 *		 entre 65 et 90). Un prenom de client ne peut pas commencer par un espace blanc ni
 *		 par un tiret.
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
 *Fonction verifiant si la date de naissance entre est une date valide.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaîne de caracteres ne correspond pas à une date de
 *		 naissance valide et retourne la valeur 1 dans le cas contraire.
 */
int verifdatenaiss (char* chaine){

    //Declaration et initialisation des variables.
    int erreur, digitCounter, i, jour, mois, annee;
    erreur = 1;
    digitCounter = 0;

    //Bloc d'instruction.
	if(chaine[2] == '/' && chaine[5] == '/'){//Verifie que les "/" sont bien positionnes.
		for(i = 0; i < 10 ; i++){/*Boucle verifiant si l'utilisateur a bien rentre des
		chiffres aux bons endroits.*/
			if(chaine[i] < 58 && chaine[i] > 47 ){
					digitCounter ++;
			}
		}
		if(digitCounter == 8){
			//Conversion de la chaine de caractere en chiffre.
			jour = (chaine[0] - 48) * 10 + (chaine[1] - 48);
			mois = (chaine[3] - 48) * 10 + (chaine[4] - 48);
			annee=(chaine[6]-48)*1000+(chaine[7]-48)*100+(chaine[8]-48)*10+(chaine[9]-48);

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
			if(erreur != 0 && (mois==4 || mois==6 || mois==9 || mois==11) && jour==31){
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
 *Fonction verifiant si le numero de compte est valide.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaîne de caractères ne correspond pas à un numéro de compte
 *		 bancaire valide et retourne la valeur 1 dans le cas contraire.
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
	else if(chaine[4] == 32 && chaine[9] == 32 && chaine[14] == 32){/*Verifie que les espaces
																	  sont bien positionne.*/
		for(i = 2; i < 19; i++){/*Boucle verifiant si l'utilisateur a bien rentre des chiffres
								  aux bons endroits.*/
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
 *Fonction verifant le numero de registre national.
 *
 *@pre:/
 *@post: Retourne la valeur 0 si la chaine de caracteres ne correspond pas a un numero de
 *		 registre national valide et retourne la valeur 1 dans le cas contraire.
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
 *Fonction verifiant la compatibilite entre la date de naissance et le numero de registre national.
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
 *Fonction permettant a l'utilisateur de rentrer un nom de client.
 *
 *@pre:/
 *@post: Place dans tab le nom du client apres l'avoir verifie.
 */
void enterName(char* tab){

    //Declaration et initialisation des variables.
	char tempon[sizeTempon];
	int boolean = 0;//Variable passant a 0 (faux) lorsque l'utilisateur entre un nom valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	viderBuffer();
	do{
		printf("Veuillez entrer le nom du client en majuscule!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizeNom) && isEmpty(tempon)){//Verifie que la chaine n'est pas vide et qu'elle ne depasse pas sa longueur max.
			stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
            boolean = verifnom(tab);
		}
	}
	while(!boolean);
}

/**
 *Fonction permettant a l'utilisateur de rentrer un prenom de client.
 *
 *@pre:/
 *@post: Place dans tab le prenom du client apres l'avoir verifie.
 */
void enterFirstName(char* tab){

    //Declaration et initialisation des variables.
	char tempon[sizeTempon];
	int boolean = 0;//Variable passant a 0 (faux) lorsque l'utilisateur entre un prenom valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	do{
		printf("Veuillez entrer le prenom du client en majuscule!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizePrenom) && isEmpty(tempon)){//Verifie que la chaine n'est pas vide et qu'elle ne depasse pas sa longueur max.
            stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
            boolean = verifprenom(tab);
		}
	}
	while(!boolean);
}

/**
 *Fonction permettant a l'utilisateur de rentrer la date de naissance d'un client.
 *
 *@pre:/
 *@post: Place dans tab la date de naissance du client apres l'avoir verifie.
 */
void enterDateOfBirth(char* tab){

    //Declaration et initialisation des variables.
	char tempon[sizeTempon];
	int boolean = 0;//Variable passant a 0 (faux) lorsque l'utilisateur entre une date valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	do{
		printf("Veuillez entrer la date de naissance du client sous le format jj/mm/aaaa!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizeDateNaiss) && isEmpty(tempon)){//Verifie que la chaine n'est pas vide et qu'elle ne depasse pas sa longueur max.
			stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
            boolean = verifdatenaiss(tab);
		}
	}
	while(!boolean);
 }

/**
 *Fonction permettant a l'utilisateur de rentrer une numero de compte.
 *
 *@pre:/
 *@post: Place dans tab le numero de compte du client apres l'avoir verifie.
 */
void enterAccountNumber(char* tab){

    //Declaration et initialisation des variables.
	char tempon[sizeTempon];
	int boolean = 0;//Variable passant a 0 (faux) lorsque l'utilisateur entre un numero valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	do{
		printf("Veuillez entrer le numero de compte du client sous le format BExx xxxx xxxx xxxx!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizeNumCompte) && isEmpty(tempon)){//Verifie que la chaine n'est pas vide et qu'elle ne depasse pas sa longueur max.
			stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
            boolean = verifnumcompte(tab);
		}
	}
	while(!boolean);
 }

 /**
 *Fonction permettant a l'utilisateur de rentrer une numero de registre national.
 *
 *@pre:/
 *@post: Place dans tab le numero de registre national du client apres l'avoir verifie.
 */
void enterNationalRegistryNumber(char* tab){

    //Declaration et initialisation des variables.
	char tempon[sizeTempon];
	int boolean = 0;//Variable passant a 0 (faux) lorsque l'utilisateur entre un numero valide.

	//Bloc d'instruction.
	system("cls");//Clear consol.
	do{
		printf("Veuillez entrer le numero de registre national du client sous le format xxxxxx-xxx-xx!\n");
		gets(tempon);
		viderBuffer();
		if(checkSize(tempon,sizeNumRegNat) && isEmpty(tempon)){//Verifie que la chaine n'est pas vide et qu'elle ne depasse pas sa longueur max.
			stringcopy (tempon, tab);//Copie le contenu de tempon dans tab.
            boolean = verifnumregnat(tab);
		}
	}
	while(!boolean);
 }

/**
 *Fonction permetant a l'utilisateur d'entrer un numero de registre national correspondant a la date de naissance.
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
 *Fonction demandant a l'utilisateur de rentrer un nombre.
 *
 *@pre: size doit doit etre initialise et size > 0.
 *@post: Renvoie le nombre entre par l'utilisateur si il est plus petit ou egal a size.
 */
int enterNumber(int size){

	//Declaration et initialisation des variables.
	int number;
	int boolean = 1;
	char tab [sizeTempon];

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
 *Fonction convertissant une chaine de caracteres en nombre entier.
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
 *Fonction verifiant que l'utilisateur a rentre un nombre.
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
 *Fonction permettant a l'utilisateur d'encoder un client type A.
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
 *Fonction permettant a l'utilisateur d'encoder un client type B.
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
 *Fonction qui copie le contenu d'un tableau dans un autre.
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
 *Fonction remplissant un tableau de structure clientA avec les entres utilisateurs.
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
 *Fonction remplissant un tableau de structure clientB avec les entres utilisateurs.
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
 *Fonction qui copie le contenu d'une structure dans une autre.
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
 *Fonction qui copie le contenu d'une structure dans une autre.
 *
 *@pre:/
 *@post: Copie les informations se trouvant dans la structure clientB source et de les placer dans la structure clientB dont destination contient
 *		 l’adresse.
 */
void structclientBcopy (struct clientB source, struct clientB* destination){

    //Bloc d'instruction.
	stringcopy(source.nom, (*destination).nom);
	stringcopy(source.prenom, (*destination).prenom);
	stringcopy(source.datenaiss, (*destination).datenaiss);
 }

/**
 *Fonction affichant un clientA.
 *
 *@pre: clientA est un client valide.
 *@post: Affiche les informations contenues dans clientA.
 */
void printClientA(struct clientA clientA){
	    printf("Nom : ");
        puts(clientA.nom);
		printf("Prenom : ");
        puts(clientA.prenom);
		printf("Date de naissance : ");
        puts(clientA.datenaiss);
		printf("Numero de registre national : ");
        puts(clientA.num_reg_nat);
		printf("Numero de compte : ");
        puts(clientA.num_compte);
        printf("\n");
}

/**
 *Fonction affichant un clientB.
 *
 *@pre: clientB est un client valide.
 *@post: Affiche les informations contenues dans clientB.
 */
void printClientB(struct clientB clientB){
        printf("Nom : ");
        puts(clientB.nom);
		printf("Prenom : ");
        puts(clientB.prenom);
		printf("Date de naissance : ");
		puts(clientB.datenaiss);
        printf("\n");
}

/**
 *Fonction affichant les clients de la banque A.
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
		printClientA(tab[i]);
    }
}

/**
 *Fonction affichant les clients de la banque B.
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
		printClientB(tab[i]);
    }
}

/**
 *Fonction copiant un tableau de clientA.
 *
 *@pre: Il doit il y avoir au moins un client dans source.
 *@post: Copie les elements du tableau source dans le tableau destination.
 */
void structTabACopy(struct clientA* source, struct clientA* destination, int size){

	//Declaration et initialisation des variables.
	int i;

	//Bloc d'instruction.
	for(i = 0; i < size; i++){
		structclientAcopy(source[i], &(destination[i]));
	}
}

/**
 *Fonction copiant un tableau de clientB.
 *
 *@pre: Il doit il y avoir au moins un client dans source.
 *@post: Copie les elements du tableau source dans le tableau destination.
 */
void structTabBCopy(struct clientB* source, struct clientB* destination, int size){

	//Declaration et initialisation des variables.
	int i;

	//Bloc d'instruction.
	for(i = 0; i < size; i++){
		structclientBcopy(source[i], &(destination[i]));
	}
}

/**
 *Fonction qui verifie l'ordre lexicographique.
 *
 *@pre/
 *@post: Renvoie la valeur 0 si les chaînes A et B sont identiques ; 1 si A précède B dans l’ordre lexicographique et enfin, –1 si A succède B dans
 *       l’ordre lexicographique.
 */
int stringcomp(char* A, char* B){

    //Declaration et initialisation des variables.
    int place = 0;
    int i;

    //Bloc d'instruction.
    for(i = 0; (A[i] != '\0' || B[i] != '\0') && place == 0; i++){//Parcour les caracteres et les compare.
		if(A[i] < B[i]){
			place = 1;
		}
		else if(A[i] > B[i]){
			place = -1;
		}
    }
    /*Si les deux chaines sont identiques du premier caractere jusqu'au dernier caractere de la chaine la plus petite verifie si il ne reste pas
     *d'autre caractère et continue la comparaison.
     */
    if(place == 0){
		if(A[i] == '\0' && B[i] != '\0'){
			place = 1;
		}
		if(B[i] == '\0' && A[i] != '\0'){
			place = -1;
		}
    }
    return place;
}

/**
 *Fonction comparant 2 structures clientA.
 *
 *@pre : Les 2 structures ont ete initialisee.
 *@post : Renvoie la valeur 0 si les structure A et B sont identiques ; 1 si A précède B dans l’ordre lexicographique et enfin, –1 si A succède B dans
 *l’ordre lexicographique.
 */
int structcompA(struct clientA* A,struct clientA* B){

    //Declaration et initialisation des variables.
    int result;

    //Bloc d'instruction.
    result = stringcomp((*A).nom, (*B).nom);
    if(result == 0){
		result = stringcomp((*A).prenom, (*B).prenom);
    }
    return result;
}

/**
 *Fonction comparant 2 structures clientB.
 *
 *@pre : Les 2 structures ont ete initialisee.
 *@post : Renvoie la valeur 0 si les structure A et B sont identiques ; 1 si A précède B dans l’ordre lexicographique et enfin, –1 si A succède B dans
 *l’ordre lexicographique.
 */
int structcompB(struct clientB* A,struct clientB* B){

    //Declaration et initialisation des variables.
    int result;

    //Bloc d'instruction.
    result = stringcomp((*A).nom, (*B).nom);
    if(result == 0){//Si les deux noms sont identique, compare les prenoms.
		result = stringcomp((*A).prenom, (*B).prenom);
    }
    return result;
}

/**
 *Fonction de tri de tableau de structure clientA.
 *
 *@pre: Le tableau contient au moin une structure initalisee.
 *@post: Trie le tableau de structure de l'indice inf à sup, dans l'orde alphabetique des noms puis des prenoms si 2 noms sont identique.
 */
void quicksortA(struct clientA* tab, int inf, int sup){

    //Declaration et initialisation des variables.
	int i,j;
    clientA pivot,temp;
	i = inf;
	j = sup;

    //Bloc d'instruction.
	structclientAcopy((tab[(inf + sup)/2]), &pivot);//Choisi le pivot.
	do{
		//Parcours le tableau a la recherche d'element superieur ou inferieur au pivot.
        while((structcompA(&(tab[i]),&pivot)) == 1){
			i++;
		}
        while((structcompA(&pivot,&(tab[j]))) == 1){
			j--;
        }
		if(i <= j){
			//Effectue les permutations.
			structclientAcopy(tab[i], &(temp));
			structclientAcopy(tab[j], &(tab[i]));
			structclientAcopy(temp, &(tab[j]));
			i++;
			j--;
		}
	}
	while(i <= j);
	if(j > inf){
		quicksortA(tab, inf, j);//Appel recursif a la Fonction.
	}
	if(i < sup){
		quicksortA(tab, i, sup);
	}
}

/**
 *Fonction de tri de tableau de structure clientB.
 *
 *@pre: Le tableau contient au moin une structure initalisee.
 *@post: Trie le tableau de structure de l'indice inf à sup, dans l'orde alphabetique des noms puis des prenoms si 2 noms sont identique.
 */
void quicksortB(struct clientB* tab, int inf, int sup){

    //Declaration et initialisation des variables.
	int i,j;
	clientB pivot,temp;
	i = inf;
	j = sup;

    //Bloc d'instruction.
	structclientBcopy((tab[(inf + sup)/2]), &pivot);//Choisi le pivot.
	do{
		//Parcours le tableau a la recherche d'element superieur ou inferieur au pivot.
        while((structcompB(&(tab[i]),&pivot)) == 1){
			i++;
		}
        while((structcompB(&pivot,&(tab[j]))) == 1){
			j--;
        }
		if(i<=j){
			//Effectue les permutations.
			structclientBcopy(tab[i], &(temp));
			structclientBcopy(tab[j], &(tab[i]));
			structclientBcopy(temp, &(tab[j]));
			i++;
			j--;
		}
	}
	while(i<=j);
	if(j>inf){
		quicksortB(tab,inf,j);//Appel recursif a la Fonction.
	}
	if(i<sup){
		quicksortB(tab,i,sup);
	}
}

/**
 *Fonction remplissant un fichier de clientA.
 *
 *@pre: Au moins un client doit avoir ete initialise dans tabClient, size > 0.
 *@post: Ecrit dans un fichier le contenu de tabClient. Si le fichier n'existe pas, il est cree.
 */
void saveCustomersA(struct clientA* tabClient, int size, int fileNumber){

	//Declaration et initialisation des variables.
	FILE* file = NULL;
	int i;
	char tab[sizeClientA];

	//Bloc d'instruction.
	if(fileNumber){
		file = fopen("sourceA.txt","w");//Overture du fichier
	}
	else{
		file = fopen("trinomA.txt","w");//Overture du fichier
	}
	if(file != NULL){//Si le fichier existe.
		for(i = 0; i < size; i++){
			fprintf(file,"%s*%s*%s*%s*%s*\n",tabClient[i].nom,tabClient[i].prenom,tabClient[i].datenaiss,tabClient[i].num_reg_nat,tabClient[i].num_compte);
		}
		fclose(file);//Ferme le fichier.
	}
}

/**
 *Fonction remplissant un fichier de clientB.
 *
 *@pre: Au moins un client doit avoir ete initialise dans tabClient, size > 0.
 *@post: Ecrit dans un fichier le contenu de tabClient. Si le fichier n'existe pas, il est cree.
 */
void saveCustomersB(struct clientB* tabClient, int size, int fileNumber){

	//Declaration et initialisation des variables.
	FILE* file = NULL;
	int i;
	char tab[sizeClientB];

	//Bloc d'instruction.
	if(fileNumber){
		file = fopen("sourceB.txt","w");//Overture du fichier
	}
	else{
		file = fopen("trinomB.txt","w");//Overture du fichier
	}
	if(file != NULL){//Si le fichier existe.
		for(i = 0; i < size; i++){
            fprintf(file,"%s*%s*%s*\n",tabClient[i].nom,tabClient[i].prenom,tabClient[i].datenaiss);
		}
		fclose(file);//Ferme le fichier.
	}
}

/**
 *Fonction copiant une sous chaine de caractere.
 *
 *@pre: indice >= 0.
 *@post: Place la chaine de caractere comprise entre indice et * dans destination et retourne l'indice de la prochaine case de source a copier..
 */
int split(char* source, char* destination, int indice){

	//Declaration et initialisation des variables.
	int i;

	//Bloc d'instruction.
	for(i = 0; source[indice] != '*'; i++){
		destination[i] = source[indice];
		indice ++;
	}
	destination[i] = '\0';
	indice++;//Incremente indice pour arriver a la prochaine case de source a copier dans un eventuel rappel a la fonction.
	return(indice);
}

/**
 *Fonction copiant les info d'un string dans un client.
 *
 *@pre: tab n'est pas vide.
 *@post: retourne un clientA dans le quel a ete place les informations contenues dans tab.
 */
struct clientA stringToStructA(char* tab){

	//Declaration et initialisation des variables.
	int indice = 0;
	clientA client;
	char tempon[sizeNom];

	//Bloc d'instruction.
	indice = split(tab, tempon, indice);
	stringcopy(tempon, client.nom);//Copie tempon dans client.nom
	indice = split(tab, tempon, indice);
	stringcopy(tempon, client.prenom);
	indice = split(tab, tempon, indice);
	stringcopy(tempon, client.datenaiss);
	indice = split(tab, tempon, indice);
	stringcopy(tempon, client.num_reg_nat);
	indice = split(tab, tempon, indice);
	stringcopy(tempon, client.num_compte);

	return(client);
}

/**
 *Fonction copiant les info d'un string dans un client.
 *
 *@pre: tab n'est pas vide.
 *@post: retourne un clientB dans le quel a ete place les informations contenues dans tab.
 */
struct clientB stringToStructB(char* tab){

	//Declaration et initialisation des variables.
	int indice = 0;
	clientB client;
	char tempon[sizeNom];

	//Bloc d'instruction.
	indice = split(tab, tempon, indice);
	stringcopy(tempon, client.nom);//Copie tempon dans client.nom
	indice = split(tab, tempon, indice);
	stringcopy(tempon, client.prenom);
	indice = split(tab, tempon, indice);
	stringcopy(tempon, client.datenaiss);

	return(client);
}

/**
 *Fonction lisant un fichier.
 *
 *@pre: fileNumber == 0 || filleNumber == 1.
 *@post: Lit un fichier et stocke son contenu dans tabClient.
 */
int loadCustomersA(struct clientA* tabClient, int fileNumber){

	//Declaration et initialisation des variables.
	FILE* file = NULL;
	int size = 0;
	char tab[sizeClientA];

	//Bloc d'instruction.
	if(fileNumber){
		file = fopen("sourceA.txt","r");//Overture du fichier
	}
	else{
		file = fopen("trinomA.txt","r");//Overture du fichier
	}
	if(file != NULL){//Si le fichier existe.
			while(fgets(tab, sizeClientA, file) != NULL){//Lit une ligne du fichier.
				structclientAcopy((stringToStructA(tab)), &(tabClient[size]));//Transforme la chaine en client.
				size++;
			}
		fclose(file);//Ferme le fichier.
	}
	return(size);
}

/**
 *Fonction lisant un fichier.
 *
 *@pre: fileNumber == 0 || filleNumber == 1.
 *@post: Lit un fichier et stocke son contenu dans tabClient.
 */
int loadCustomersB(struct clientB* tabClient, int fileNumber){

	//Declaration et initialisation des variables.
	FILE* file = NULL;
	int size = 0;
	char tab[sizeClientB];

	//Bloc d'instruction.
	if(fileNumber){
		file = fopen("sourceB.txt","r");//Overture du fichier
	}
	else{
		file = fopen("trinomB.txt","r");//Overture du fichier
	}
	if(file != NULL){//Si le fichier existe.
			while(fgets(tab, sizeClientB, file) != NULL){//Lit une ligne du fichier.
				structclientBcopy((stringToStructB(tab)), &(tabClient[size]));//Transforme la chaine en client.
				size++;
			}
		fclose(file);//Ferme le fichier.
	}
	return(size);
}

/**
 *Fonction comparant une structure clientA et une clientB.
 *
 *@pre: clientA et ClientB sont 2 client valide.
 *@post: Renvoie 1 si clientA precede clientB, -1 dans le cas inverse et 0 si ils sont identique.
 */
int structComp(struct clientA clientA, struct clientB clientB){

	//Declaration et initialisation des variables.
	int resultat;

	//Bloc d'instruction.
	resultat = stringcomp(clientA.nom, clientB.nom);//Compare les noms.
	if(resultat == 0){//Si les noms sont identique, verifier prenom.
		resultat = stringcomp(clientA.prenom, clientB.prenom);//Compare les prenoms.
			if(resultat == 0){
				resultat = stringcomp(clientA.datenaiss, clientB.datenaiss);//!!!!!!!!!!!!Ouarf catastrophe, a decider.
			}
	}
	return(resultat);
}

/**
 *Fonction supriment un client de clientA;
 *
 *@pre: size > 0, indice >= 0, clientA possede au moins un client.
 *@post: Retire le client a l'indice indice et decale les autres clients.
 */
void suprClientA(struct clientA* clientA, int indice, int size){

	//Declaration et initialisation des variables.
	int i;

	//Bloc d'instruction.
	for(i = 0; i < size - 1; i++){
		structclientAcopy(clientA[i+1], &(clientA[i]));
	}
}

/**
 *Fonction supriment un client de clientB
 *
 *@pre: size > 0, indice >= 0, clientB possede au moins un client.
 *@post: Retire le client a l'indice indice et decale les autres clients.
 */
void suprClientB(struct clientB* clientB, int indice, int size){

	//Declaration et initialisation des variables.
	int i;

	//Bloc d'instruction.
	for(i = 0; i < size - 1; i++){
		structclientBcopy(clientB[i+1], &(clientB[i]));
	}
}

/**
 *Fonction de gestion des comptes double.
 *
 *@pre: sizeA > 0, sizeB > 0, il y a des clients initialises dans clientA et clientB.
 *@post: Verifie si il y a des clients qui ont un compte dans les deux banques et demande a l'utilisateur si il veut clore un compte ou ne rien faire.
 */
void gestionBanqueABanqueB(int* sizeA, int* sizeB, struct clientA* clientA, struct clientB* clientB){

	//Declaration et initialisation des variables.
	int choix, tempon, compteur, i, j;
	i = 0;
	j = 0;
	compteur = 0;

	//Bloc d'instruction.
	system("cls");
	while(i < *sizeA && j < *sizeB){
		tempon = structComp(clientA[i], clientB[j]);
		if(tempon == -1){
			i++;
		}
		else if(tempon = 1){
			j++;
		}
		else{
			compteur++;
			printf("Ce client est present dans les deux banques!\n");
			printClientA(clientA[j]);
			printClientB(clientB[i]);
			printf("Voulez vous le suprimez de la banque A(tapez 1), de la banque B(tapez 2), des deux banques(tapez 3) ou ne rien faire(tapez 4)?\n");
			choix = enterNumber(4);
			if(choix == 1){
				suprClientA(clientA, i, *sizeA);
				*sizeA--;
				j++;
			}
			else if(choix == 2){
				suprClientB(clientB, j, *sizeB);
				*sizeB--;
				i++;
			}
			else if(choix == 3){
				suprClientA(clientA, i, *sizeA);
				suprClientB(clientB, j, *sizeB);
				*sizeA--;
				*sizeB--;
			}
			else{
				i++;
				j++;
			}
		}
	}
	if(compteur){
		printf("Il n'y a plus de client se trouvant dans les deux banques, fin de la fonction!\n");
	}
	else{
		printf("Aucun client present dans les deux banques n'a %ct%c trouv%c!\n",130, 130, 130);
	}
}
