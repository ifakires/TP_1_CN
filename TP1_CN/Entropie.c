#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float Entropie(float probas[]){
    float res = 0;
    int i = 0;

    while(i != 6){
        res = res + probas[i]*log2f(1/probas[i]);
        i++; 
    }
    return res;
}

float file_Entropie(char file_name[]){

    FILE *myFile;
    myFile = fopen("probas.txt", "r");


    float res = 0;
    int i = 0;

    while(!feof(myFile)){
        float proba;
        fscanf(myFile, "%f", &proba);
        res = res + proba*log2f(1/proba);
        i++; 
    }
    return res;
}


int main(){
    float probas[] = {0.39, 0.20, 0.14, 0.11,0.09,0.07};
    printf("Avec lecture dans le tableau de probas : ");
    printf("%f",Entropie(probas));
    printf("\n");
    printf("Avec lecture dans le fichier probas.txt : ");
    printf("%f",file_Entropie("probas.txt"));
}