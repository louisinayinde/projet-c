#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float * CALCFREQ(float alpha[26], char * nom_fic)
{
    FILE *fic=fopen("Compression.TXT","r");
    char lettre;
    int total=0;
    int i=0;

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
        if(alpha[i]!=0 && i<26) printf("%c => %lf %%\n",i+97,alpha[i]);
        if(i==26) printf("%c => %lf %%\n",32, alpha[26]);

    }
    fclose(fic);
    return alpha;
}

void convertToBinary() {
    char test = 'a';
    int num = 'a';
    int it = 0;
    int binary[32];
    printf("%d\n", num);

    while (num > 0) {
        binary[it] = num% 2;
        printf("%d\n", binary[it]);
        num/2;
        it++;
    }
    /*for (int j = it-1; j >= 0; j--){
      printf("%d", binary[j]);
    }*/
}

void display() {

    int choix;
    float alpha[27] = {0}; // alpha = 27 : 26 lettre + espace
    float * tab_alpha;

    printf("Veuillez choisir : \n  1 - Compression\n  2 - Decompression\n  3 - Quitter\n");
    scanf("%d",&choix);
    switch(choix){
        case 1 :
            printf("Vous avez choisi la compression\n\n");
            tab_alpha = CALCFREQ(alpha,"Compression.txt");
            convertToBinary();
            display();
        case 2 :
            printf("Vous avez choisi la decompression\n");
            display();
        case 3 :
            printf("Vous avez choisi qe quitter\n");
            break;
        default :
            printf("Erreur entree, au revoir\n");
            break;
    }
    free(tab_alpha);
}

int main()
{
    //display();
    convertToBinary();
    return 0;

}
