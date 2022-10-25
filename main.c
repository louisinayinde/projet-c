#include <stdio.h>
#include <stdlib.h>

void CALCFREQ(float alpha[26], char * nom_fic)
{
  FILE *fic=fopen(nom_fic,"r");
char lettre;
int total=0;

while((lettre=fgetc(fic))!=EOF)
{
    if(lettre>='a'&& lettre<='z')
    {
        alpha[lettre-'a']=alpha[lettre-'a']+1;
        total=total+1;
    }
    else if (lettre>='A' && lettre<='Z')
    {
        alpha[lettre-'A']=alpha[lettre-'A']+1;
        total=total+1;
    }
}
for(int i=0;i<26;i++)
{
    alpha[i]=alpha[i]/total;
    printf("%c => %lf\n",i+97,alpha[i]);
}
fclose(fic);
}

int main()
{
    float alpha[26];
    CALCFREQ(alpha,"Compression.TXT");
    return 0;

}
