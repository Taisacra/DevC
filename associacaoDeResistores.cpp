#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include<conio.h>

void cabecalho(){
    printf("======================================");
    printf("\n     ASSOCIACAO DE RESITORES        ");
    printf("\n======================================");
    printf("\n\n");
}

int main(){

    int op, R1, R2, R3, R4, R5; 
    float  somaReq21, somaReq21e3, Req21, multReq21;
    char resp[10], r;

    cabecalho();
    
	do{
	    printf("Informe Circuito em serie ou paralelo: ");
	    gets(resp);
	    system ("cls");
	
	    if(resp == "Serie" || resp == "serie"){
	            cabecalho();
	        printf("Informe a quantidade de resistores presente no circuito em serie: ");
	        printf("\n1- 2 resistores \n2- 3 resistores \n3- 4 resistores \n5- 5 resistores");
			scanf("%d", &op);
			
			system("cls");
			cabecalho();
	
	        switch(op){
	            case 1:
	
	                printf("Digite R1: ");
	                scanf("%d", &R1);
	                printf("Digite R2: ");
	                scanf("%d", &R2);
	                    printf("Req = %d Ohm  ", R1+R2);
	                    
	                break;
	
	            case 2:
	            
	                printf("Digite R1: ");
	                scanf("%d", &R1);
	                printf("Digite R2: ");
	                scanf("%d", &R2);
	                printf("Digite R3: ");
	                scanf("%d", &R3);
	                    printf("Req = %d Ohm ", R1+R2+R3);
	
	                break;
	
	            case 3:
	            
	                printf("Digite R1: ");
	                scanf("%d", &R1);
	                printf("Digite R2: ");
	                scanf("%d", &R2);
	                printf("Digite R3: ");
	                scanf("%d", &R3);
	                printf("Digite R4: ");
	                scanf("%d", &R4);
	                    printf("Req = %d Ohm ", R1+R2+R3+R4);
	
	                break;
	
	            case 4:
	            
	                printf("Digite R1: ");
	                scanf("%d", &R1);
	                printf("Digite R2: ");
	                scanf("%d", &R2);
	                printf("Digite R3: ");
	                scanf("%d", &R3);
	                printf("Digite R4: ");
	                scanf("%d", &R4);
	                printf("Digite R5: ");
	                scanf("%d", &R5);
	                    printf("Req = %d Ohm ", R1+R2+R3+R4+R5);
	
	                break;
	                default:
	                    printf("Opcao invalida! ");
	
	        }
	
	    }else(resp == "paralelo" || resp == "Paralelo");{
	        cabecalho();
	        printf("Informe a quantidade de resistores presente no circuito em Paralelo: ");
	        printf("\n1- 2 resistores em paralelo \n2- 3 resistores em paralelo ");
	        scanf("%d", &op);
			
			system("cls");
			cabecalho();
			
	        switch(op){
	
	            case 1:
	        
	                printf("Digite R1: ");
	                scanf("%d", &R1);
	                printf("Digite R2: ");
	                scanf("%d", &R2);
	
	                somaReq21 = (R1*R2)/(R1+R2);
	                    printf("Req = %.2f Ohm ", somaReq21);
	
	
	                break;
	
	            case 2:
	            
	                printf("Digite R1: ");
	                scanf("%d", &R1);
	                printf("Digite R2: ");
	                scanf("%d", &R2);
	                printf("Digite R3: ");
	                scanf("%d", &R3);
	
	                multReq21 = R1*R2;
	                somaReq21 = R1+R2;
	                Req21= multReq21/somaReq21;
	                somaReq21e3 = (Req21*R3)/ (Req21+R3);
	                    printf("Req = %.2f Ohm ", somaReq21e3);
	
	                break;
	
	            default:
	                printf("Opcao invalida");
	
	        }
	    }
	    
	    printf("Deseja continuar?\n S- sim \nN-nao ");
	    scanf(" %c", &r);
	    
	}while(r == 'S' || r == 's');
	
		getch();
 		return 0;
}

