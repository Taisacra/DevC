#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


void cabecalho(){
	
	printf("======================================");
    printf("\n          Desafio - GENIUS           ");
    printf("\n=====================================");
    printf("\n");
}

int main(){

	int g[20], v[20], a, b, c=1;

	do{
		cabecalho();
		for(a=0; a<b; a++){
	
			 srand(time(NULL));
			 g[a]=1+(rand()%4);
			 printf("[%d]\n", g[a]);
			 Sleep(2000);
			 
		}
			system("cls");
			cabecalho();
			
		for(a=0; a<b; a++){
	
			 printf("Repita a sequencia nivel %d: ", c);
			 scanf(" %d",& v[a]);
			
			
			 printf("\n %d", v[a]);
	 
		}
	 
			system("cls");
			cabecalho();
			
	 	for(a=0; a<c; a++){
	 		
	  		if(v[a]==g[a]){
	   
				printf("PARABENS. Siga ao proximo nivel!");
				printf("\n");
				Sleep(2000);
				system("cls");
			b++;
	 
	  		}else{
	 
			printf("Que pena, voce errou!");
			printf("\n");
	 
	 		c=0;
		    b=0;
	 
	  		}
		}
		c++;
	}while(b!=0);
}
