#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int it = 0;
int tabLettre [256];
float tabFreq[27] = {0}; // alpha = 27 : 26 lettre + espace

struct Huffman{
int tabLettre [256];
float tabFreq[27];
struct Huffman *suivant;
};

struct Noeud {
    int freq;
    char caractere;
    struct Noeud *left, *right;
};

void * CALCFREQ()
{
    FILE *fic=fopen("Compression.TXT","r");
    float alpha[27] = {0};
    char lettre;
    int total=0, j=0;


    while((lettre=fgetc(fic))!=EOF)
    {
        lettre = tolower(lettre);

        if(lettre>='a'&& lettre<='z')
        {
            alpha[lettre-97]+=1;
            total+=1;
        }
        else if (lettre ==' ')
        {
            alpha[26]+=1;
            total+=1;
        }
    }

    for(int i=0;i<27;i++)
    {
        alpha[i]=(alpha[i]/total)*100;
        if(alpha[i]!=0 && i<26) {
            tabLettre[j] = i+97; //stock le caractere(en int) dans tableau globale de lettre
            tabFreq[j] = (int)alpha[i]; // stock la frequence dans tableau globale de frequence
            j++;
        }
        if(i==26) {
            tabLettre[j] = 32;
            tabFreq[j] = (int)alpha[i];
            j++;
        }
        it=j; // iterator de tabLettre recupere la valeur de j
    }
    fclose(fic);
}

struct Noeud createHeap (int freq, char caractere){
    struct Noeud temp;
    if(freq!=0 && caractere!=NULL){
        temp.caractere = caractere;
        temp.freq = freq;
        temp.left = temp.right =NULL;
    }
    return temp;
}

struct Noeud createNode (int freq, char caractere, struct Noeud node1, struct Noeud node2){
    struct Noeud temp;
    struct Noeud *tempNode1 = &node1;
    struct Noeud *tempNode2 = &node2;
    if(freq!=0 && caractere!=NULL){
        temp.caractere = caractere;
        temp.freq = freq;
        temp.left =tempNode1;
        temp.right =tempNode2;
    }
    return temp;
}

void display2DNodeUtil (struct Noeud *racine, int espace){

    espace += 5;

    // branche "right" de l'arbre
    display2DNodeUtil(racine->right, espace);


    printf("\n");
    for (int i = it; i < espace; i++) printf(" ");
    printf("%d\n", racine->freq);

    // branche "left" de l'arbre
    display2DNodeUtil(racine->left, espace);
}

void display2DNode (struct Noeud *racine) {
    display2DNodeUtil(racine, 0);
}

void displayNode (struct Noeud temp) {
    printf("%c => %d\n", temp.caractere, temp.freq);
}


void createTree(){
    int sommeFrequence = 0, iterator = it, k=0;
    char temp;
    struct Noeud tabNoeud [it];
    struct Noeud tempNode;
    struct Noeud arbre;

    //creation des feuilles de l'arbre a partir des tableau de frequence et caractere
    for(int i=0;i<it;i++)
    {
        temp = tabLettre[i];
        tabNoeud[i] = createHeap(tabFreq[i], temp);
    }

    for(int i=0;i<it;i++) displayNode(tabNoeud[i]);
    printf("\n\n");



    for(int l=0;l<iterator;l++){

        //tri du tableau de noeud
        for (int i=0;i<it-1;i++)
        {
            for (int j=0;j<it-i-1;j++)
            {
              if (tabNoeud[j].freq > tabNoeud[j+1].freq)
              {
                tempNode = tabNoeud[j];
                tabNoeud[j] = tabNoeud[j+1];
                tabNoeud[j+1] = tempNode;
              }
            }
        }

        sommeFrequence = tabNoeud[0].freq + tabNoeud[1].freq;
        tabNoeud[0] = createNode(sommeFrequence, '.', tabNoeud[0], tabNoeud[0+1]);
        for(int i=1; i<it-1; i++)
        {
            tabNoeud[i] = tabNoeud[i + 1];
        }

        /* decrementation de it(taille tableau de frequence, caractere et noeud */
        it--;

        for(int i=0;i<it;i++) displayNode(tabNoeud[i]);
        printf("\n\n");

    }

    it=iterator;
    display2DNode(&tabNoeud[0]);

}

bool estFeuille(struct Noeud *arbre)
{
    if(arbre=NULL){
        estFeuille = false;
    }
    else{
        estFeuille = arbre->right=NULL && arbre->left=NULL;
    }
}

struct Noeud Parcours(struct Noeud *arbre,string str)
{
    if(arbre = NULL)
    {
        return;
    }
    if(arbre->right!=NULL)
    {
        arbre=arbre->right;
        Parcours(arbre->right,str+"1");
    }

    if(arbre->left!=NULL)
        {
            arbre=arbre->left;
            Parcours(arbre->left,str+"0");

        }
    }
void CodeHuffman(int siez)
{
    struct Noeud;
    priority_queue<Noeud> queue;
    int tabLettre[256];
    int i;
    for(i=0;i<256;i++)
    {
        tabLettre[i]=0;
    }
    for (i=0;i<256;i++)
    {
        if(tabLettre[i]!=0)
        {
            queue.push(Noeud(i, tabLettre[i]));
        }
    }

while(queue.size()!=1)
{

    Noeud *right = queue.top();
    queue.top();

    Noeud *left = queue.top();
    queue.top();

    queue.push(Noeud(right, left));

}
queue.top.Parcoours();
}
void display() {

    int choix;

    printf("Veuillez choisir : \n  1 - Compression\n  2 - Quitter\n");
    scanf("%d",&choix);
    switch(choix){
        case 1 :
            printf("Vous avez choisi la compression\n\n");
            CALCFREQ();
            createTree();
            display();
        case 2 :
            printf("Vous avez choisie de quitter\n");
            break;
        default :
            printf("Erreur entree, au revoir\n");
            break;
    }
}


int main()
{
    display();
    return 0;
}
