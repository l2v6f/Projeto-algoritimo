//Nome Laura Vieira Fernandes.  Matricula 20103268
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define MAX 300

typedef struct {
	char nome[501];
    int idade;
    char sexo[2];
    int cidade;
    char sus[16];
    char teste[2];
    char resultado[2];
} Paciente;

typedef struct {
	Paciente paciente[MAX];
	int registros;
} DadosPacientes;


typedef struct Cidades {
	char cidade[50];
    int quantidade;
} Cidades;

DadosPacientes dadosPacientes;

Cidades cidadesDF[25];

int registros = 0;

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

int eDigito(char* str)
{
	int i;
	if(strlen(str)==0)
	{
		return 1;
	}
	else 
	{
		for (i=0;i<strlen(str); i++)
    	{
			if (isdigit(str[i])==0) 
			{   
				return 1;
			}
		}	
	}
    return 0;	
}

mostraErro(char* erro){
	char dig[2];
	gotoxy(5,19); 
	printf(erro);
	gotoxy(5,21); 
	printf("Pressione qualquer tela para voltar a digitação.");
	fflush(stdin); 
	fgets(dig, 2 , stdin);
	gotoxy(5,19); 
	printf("                                                                 ");
	gotoxy(5,21); 
	printf("                                                                 ");

}

void inicializaDados(DadosPacientes dadosPacientes)
{
	int i;
	dadosPacientes.registros = 0;
	for(i=0; i<MAX; i++) 
	{
     	strcpy(dadosPacientes.paciente[i].nome, "NULL");
     	dadosPacientes.paciente[i].idade = 0;
     	strcpy(dadosPacientes.paciente[i].sexo, " ");
     	dadosPacientes.paciente[i].cidade = 0 ;
    	strcpy(dadosPacientes.paciente[i].sus, "NULL");
     	strcpy(dadosPacientes.paciente[i].teste, " ");
     	strcpy(dadosPacientes.paciente[i].resultado, " ");
	}
}

void inicializaCidadesDF(Cidades *cidadesDF)
{
	int i;
	for(i=0;i<25;i++)
	{
		cidadesDF[i].quantidade=0;
	}		
	strcpy(cidadesDF[0].cidade,"Águas Claras        ");	
	strcpy(cidadesDF[1].cidade,"Asa Norte           ");
	strcpy(cidadesDF[2].cidade,"Asa Sul             ");
	strcpy(cidadesDF[3].cidade,"Braslândia          ");
	strcpy(cidadesDF[4].cidade,"Ceilândia           ");
	strcpy(cidadesDF[5].cidade,"Cruzeiro            ");
	strcpy(cidadesDF[6].cidade,"Estrutural          ");
	strcpy(cidadesDF[7].cidade,"Gama                ");
	strcpy(cidadesDF[8].cidade,"Guará               "); 
	strcpy(cidadesDF[9].cidade,"Lago Norte          ");
	strcpy(cidadesDF[10].cidade,"Lago Sul            ");
	strcpy(cidadesDF[11].cidade,"Noroeste            ");
	strcpy(cidadesDF[12].cidade,"Núcleo Bandeirante  ");
	strcpy(cidadesDF[13].cidade,"Paranoá             ");
	strcpy(cidadesDF[14].cidade,"Planaltina          ");
	strcpy(cidadesDF[15].cidade,"Recanto das Emas    ");
	strcpy(cidadesDF[16].cidade,"Riacho Fundo I      ");
	strcpy(cidadesDF[17].cidade,"Riacho Fundo II     "); 
	strcpy(cidadesDF[18].cidade,"Samambaia           ");
	strcpy(cidadesDF[19].cidade,"Santa Maria         ");
	strcpy(cidadesDF[20].cidade,"São Sebastião       ");
	strcpy(cidadesDF[21].cidade,"Sobradinho          ");
	strcpy(cidadesDF[22].cidade,"Sudoeste            ");
	strcpy(cidadesDF[23].cidade,"Taguatinga          ");
	strcpy(cidadesDF[24].cidade,"Vicente Pires       ");
}

leValidaNome(){
	char nome[501] = "NULL";
	int temErro = 0;
	do
	{   
	 	gotoxy(1,9);
		printf("Nome do Paciente: " );
		fflush(stdin); 
		fgets (nome, 501, stdin);
		if(strlen(nome)==0)
		{
			mostraErro("O nome não foi digitado!");
		}
		else 
		{
			strcpy(dadosPacientes.paciente[registros].nome, nome);
			temErro = 1;
		}	
	} while (temErro == 0);  
}

leValidaIdade(){
	char idade[4] = "-1";
	int temErro = 0;
	printf("Idade do Paciente: ");
	gotoxy(5,19); 
	printf("Informe a idade do paciente entre 0 e 120 anos");
	do
	{
	 	strcpy(idade,"\0");
	 	gotoxy(1,10);
		printf("Idade do Paciente: ");	
		fflush(stdin); 
		scanf ("%s", idade);
		if (eDigito(idade)==1)
		{
			mostraErro("A idade deve ser numerica!");
			printf ("passei 1");
		}
		else if(atoi(idade)<0) 
		{
			mostraErro("A idade deve ser maior ou igual a 0 anos!");	
		}
		else if(atoi(idade)>120)
		{
			mostraErro("A idade deve ser menor ou igual a 120 anos!");
		}
		else 
		{
			printf("gravei");
			dadosPacientes.paciente[registros].idade = atoi(idade);
			temErro = 1;
		}	
	} while (temErro == 0); 
}

leValidaSexo(){
	int i;
	char sexo[2];
	int temErro = 0;
	gotoxy(5,19); 
	printf("O sexo deve ser M - Masculino ou F - Feminino!                      ");
	do
	{
	 	gotoxy(1,11);
		printf("Sexo do Paciente: ");
		fflush(stdin); 		
		fgets (sexo, 2, stdin);
        sexo[0] = toupper(sexo[0]);	
		if(strcmp(sexo,"F")!=0 && strcmp(sexo,"M")!=0)
		{
			mostraErro("O sexo deve ser M - Masculino ou F - Feminino!");
		}
		else 
		{
			strcpy(dadosPacientes.paciente[registros].sexo, sexo);
			temErro = 1;
		}	
	} while (temErro == 0); 
}

apagaCidades()
{
	int linha = 19;
	int coluna = 5;
	gotoxy(coluna,linha); 
	printf("                                                                                      ");	
	gotoxy(coluna,linha+1); 
	printf("                                                                                      ");	
	gotoxy(coluna,linha+2); 
	printf("                                                                                      ");	
	gotoxy(coluna,linha+3); 
	printf("                                                                                      ");	
	gotoxy(coluna,linha+4); 
	printf("                                                                                      ");	
	gotoxy(coluna,linha+5); 
	printf("                                                                                      ");	
	gotoxy(coluna,linha+6); 
	printf("                                                                                      ");	
	gotoxy(coluna,linha+7); 
	printf("                                                                                      ");	
}

mostraCidades()
{
	int linha = 19;
	int coluna = 5;
	gotoxy(coluna,linha); 
	printf("Codigo de cidades do DF:                                         ");
	gotoxy(coluna,linha+1); 
	printf("    1 - Águas Claras        2 - Asa Norte        3 - Asa Sul     4 - Brazlândia       ");   
	gotoxy(coluna,linha+2); 
	printf("    5 - Ceilândia           6 - Cruzeiro         7 - Estrutural  8 - Gama             ");	
	gotoxy(coluna,linha+3); 
	printf("    9 - Guará              10 - Lago Norte      11 - Lago Sul   12 - Noroeste         ");
	gotoxy(coluna,linha+4); 
	printf("   13 - Núcleo Bandeirante 14 - Paranoá         15 - Planaltina 16 - Recanto das Emas ");
	gotoxy(coluna,linha+5); 
	printf("   17 - Riacho Fundo I     18 - Riacho Fundo II 19 - Samambaia  20 - Santa Maria      ");
	gotoxy(coluna,linha+6); 
	printf("   21 - São Sebastião      22 - Sobradinho      23 - Sudoeste   24 - Taguatinga       ");
	gotoxy(coluna,linha+7); 
	printf("   25 - Vicente Pires                                                                 ");	
}

leValidaCidade(){	
	int cidade = 0;
	int temErro = 0;
	do
	{
		mostraCidades();
	 	gotoxy(1,12);
		printf("Cidade do Paciente: ");
		fflush(stdin);
		scanf ("%i", &cidade);
		if(cidade < 1 || cidade > 25)
		{
			apagaCidades();
			mostraErro("O codigo da cidade deve estar entre 1 e 25!");
		}
		else 
		{
			dadosPacientes.paciente[registros].cidade = cidade;
			temErro = 1;
			apagaCidades();
		}	
	} while (temErro == 0); 
}

int temNroSusRepetido(char* nroSus)
{
	int i;
	for (i=0;i<dadosPacientes.registros; i++)
	{
		if(strcmp(dadosPacientes.paciente[i].sus,nroSus)==0)
		{  
			return 1;
		}
	}
	return 0;
}


leValidaSus()
{
	int i;
	char nroSus[16] = "NULL";
	int temErro = 0;
	gotoxy(5,19); 
	printf("O codigo deve ter 15 digitos!                             ");
	do
	{
	 	gotoxy(1,13);
		printf("Cartão SUS do Paciente: ");
		fflush(stdin);
		fgets (nroSus, 16, stdin);
		if(strlen(nroSus)!=15) 
		{
			mostraErro("O codigo deve ter 15 digitos!");
		}
		else 
		{
			int eNumeroSus = 0;
		    for (i=0;i<strlen(nroSus); i++)
            {
				if (!isdigit(nroSus[i])) 
				{   
					mostraErro("O numero SUS deve possuir apenas numeros!");
					eNumeroSus = 1;
					break;
				}
			}
			if (eNumeroSus==0) 
			{
				if (temNroSusRepetido(nroSus)==1)
				{
					mostraErro("O numero SUS digitado ja foi informado anteriormente!");
				}
				else
				{
					strcpy(dadosPacientes.paciente[registros].sus, nroSus);
					temErro = 1;
				}	
			}	
		}	
	} while (temErro == 0); 
}

 leValidaTipoTeste(){
	int i;
	char teste[2];
	int temErro = 0;
	gotoxy(5,19); 
	printf("O teste deve ser S - Sorologia ou R - RT-PCR ou T - Teste Rapido!      ");
	do
	{
	 	gotoxy(1,14);
		printf("Teste Realizado: ");
		fflush(stdin);
		fgets (teste, 2, stdin);
        teste[0] = toupper(teste[0]);		 
		if(strcmp(teste,"S")!=0 && strcmp(teste,"R")!=0 && strcmp(teste,"T")!=0) 
		{
			mostraErro("O teste deve ser S - Sorologia ou R - RT-PCR ou T - Teste Rapido!");
		}
		else 
		{
			strcpy(dadosPacientes.paciente[registros].teste, teste);
			temErro = 1;
		}	
	} while (temErro == 0); 
}

leValidaResultado(){
	int i;
	char resultado[2];
	int temErro = 0;
	gotoxy(5,19); 
	printf("O resultado informado deve ser P - Positivo ou N - Negativo!            ");
	do
	{
	 	gotoxy(1,15);
		printf("Resultado do Teste: ");
		fflush(stdin);
		fgets (resultado, 2, stdin);
        resultado[0] =  toupper(resultado[0]);		 
		if(strcmp(resultado,"P")!=0 && strcmp(resultado,"N")!=0 ) 
		{
			mostraErro("O resultado informado deve ser P - Positivo ou N - Negativo!");
		}
		else 
		{    
			strcpy(dadosPacientes.paciente[registros].resultado, resultado);
			temErro = 1;
		}	
	} while (temErro == 0); 
}

cadastrar_paciente()
{ 
	int sai;
	system("cls");
	puts("=====================================================");
	puts("=====  Secretaria de Saúde do Distrito Federal  =====");
	puts("=====================================================");
	puts(" ");
	puts("   CADASTRO DE PACIENTE");
	puts(" ");
	leValidaNome();
    leValidaIdade();
    leValidaSexo();
    leValidaCidade();
    leValidaSus();
    leValidaTipoTeste();
    leValidaResultado();
    registros++;
    dadosPacientes.registros = registros;
    printf(" Digite qualquer tecla para sair "); 
	char dig[2];
	fflush(stdin); 
	fgets (dig, 2, stdin);
    
}


exibeDadosPaciente(int i)
{
	printf("Nome = %s ", dadosPacientes.paciente[i].nome);
	printf("Idade = %i  Sexo = %s   Nro SUS = %s \n", dadosPacientes.paciente[i].idade, dadosPacientes.paciente[i].sexo, dadosPacientes.paciente[i].sus);
	printf("%s",cidadesDF[dadosPacientes.paciente[i].cidade-1].cidade);			
	if(strcmp(dadosPacientes.paciente[i].teste,"S")==0)
	{
		printf("Teste aplicado = S - Sorologia\n"); 
	} 
	else if (strcmp(dadosPacientes.paciente[i].teste,"R")==0)
	{
		printf("Teste aplicado = R - RT-PCR\n");
	} 
	else if (strcmp(dadosPacientes.paciente[i].teste,"T")==0)
	{
		printf("Teste aplicado = T - Teste Rapido\n"); 
	} 
}

exibeDados()
{
	int i;
	int totalPositivos = 0;
	int totalRegistros = dadosPacientes.registros;
	system("cls");
	puts("=====================================================");
	puts("=====  Secretaria de Saúde do Distrito Federal  =====");
	puts("=====================================================");
	puts(" ");
	puts("   RELATORIOS DO SISTEMA");
	puts(" ");
	puts(" Relacao de Pacientes com Testagem Positiva");
	for(i=0;i<totalRegistros;i++)
	{
		if(strcmp(dadosPacientes.paciente[i].resultado,"P")==0)
		{   
			exibeDadosPaciente(i);
			totalPositivos++;
		}
		
	}
	printf("\n ");
	printf(" O percentual de pacientes que testaram positivo foi de %.2d%%",100 * totalPositivos/totalRegistros);
	
	printf("\n Digite qualquer tecla para sair "); 
	char dig[2];
	fflush(stdin); 
	fgets (dig, 2, stdin);
}

exibeDadosMascMenor()
{
	int i;
	int totalMascMenor = 0;
	int totalRegistros = dadosPacientes.registros;
	system("cls");
	puts("=====================================================");
	puts("=====  Secretaria de Saúde do Distrito Federal  =====");
	puts("=====================================================");
	puts(" ");
	puts("   RELATORIOS DO SISTEMA");
	puts(" ");
	puts(" Relacao de Pacientes Homens Menores de Idade Cadastrados");
	for(i=0;i<totalRegistros;i++)
	{
		if(strcmp(dadosPacientes.paciente[i].sexo,"M")==0 &&
		   dadosPacientes.paciente[i].idade < 18)
		{	
			exibeDadosPaciente(i);
			totalMascMenor++;
		}
		
	}
	printf("\n ");
	printf(" O Total de pacientes homens menores de idade apurado foi de %d", totalMascMenor);
	
	printf("\n Digite qualquer tecla para sair "); 
	char dig[2];
	fflush(stdin); 
	fgets (dig, 2, stdin);
}

exibeDadosFemMenor()
{
	int i;
	int totalFemMenor = 0;
	int totalRegistros = dadosPacientes.registros;
	system("cls");
	puts("=====================================================");
	puts("=====  Secretaria de Saúde do Distrito Federal  =====");
	puts("=====================================================");
	puts(" ");
	puts("   RELATORIOS DO SISTEMA");
	puts(" ");
	puts(" Relacao de Pacientes Mulheres Menores de Idade Cadastradas");
	for(i=0;i<totalRegistros;i++)
	{
		if(strcmp(dadosPacientes.paciente[i].sexo,"F")==0 &&
		   dadosPacientes.paciente[i].idade < 18)
		{
			exibeDadosPaciente(i);
			totalFemMenor++;
		}
		
	}
	printf("\n ");
	printf(" O Total de pacientes mulheres menores de idade apurado foi de %d", totalFemMenor);
	
	printf("\n Digite qualquer tecla para sair "); 
	char dig[2];
	fflush(stdin); 
	fgets (dig, 2, stdin);
}

exibeDadosMascIdoso()
{
	int i;
	int totalMascIdoso = 0;
	int totalRegistros = dadosPacientes.registros;
	system("cls");
	puts("=====================================================");
	puts("=====  Secretaria de Saúde do Distrito Federal  =====");
	puts("=====================================================");
	puts(" ");
	puts("   RELATORIOS DO SISTEMA");
	puts(" ");
	puts(" Relacao de Pacientes Homens Maiores de Idade Cadastrados");
	for(i=0;i<totalRegistros;i++)
	{
		if(strcmp(dadosPacientes.paciente[i].sexo,"M")==0 &&
		   dadosPacientes.paciente[i].idade >= 60)
		{	
			exibeDadosPaciente(i);
			totalMascIdoso++;
		}
		
	}
	printf("\n ");
	printf(" O Total de pacientes homens maiores de idade apurado foi de %d", totalMascIdoso);
	
	printf("\n Digite qualquer tecla para sair "); 
	char dig[2];
	fflush(stdin); 
	fgets (dig, 2, stdin);
}

exibeDadosFemIdoso()
{
	int i;
	int totalFemIdosa = 0;
	int totalRegistros = dadosPacientes.registros;
	system("cls");
	puts("=====================================================");
	puts("=====  Secretaria de Saúde do Distrito Federal  =====");
	puts("=====================================================");
	puts(" ");
	puts("   RELATORIOS DO SISTEMA");
	puts(" ");
	puts(" Relacao de Pacientes Femininas Maiores de Idade Cadastradas");
	for(i=0;i<totalRegistros;i++)
	{
		if(strcmp(dadosPacientes.paciente[i].sexo,"F")==0 &&
		   dadosPacientes.paciente[i].idade >= 60)
		{	
			exibeDadosPaciente(i);
			
			totalFemIdosa++;
		}
		
	}
	printf("\n ");
	printf(" O Total de pacientes mulheres maiores de idade apurado foi de %d", totalFemIdosa);
	
	printf("\n Digite qualquer tecla para sair "); 
	char dig[2];
	fflush(stdin); 
	fgets (dig, 2, stdin);
}

exibeQuantitativoCidades()
{
 	int i;
	int totalRegistros = dadosPacientes.registros;
	system("cls");
	puts("=====================================================");
	puts("=====  Secretaria de Saúde do Distrito Federal  =====");
	puts("=====================================================");
	puts(" ");
	puts("   RELATORIOS DO SISTEMA");
	puts(" ");
	puts(" Relacao de Quantidade de Pacientes Positivos por Cidade do DF");
	puts(" ");
	for(i=0;i<totalRegistros;i++)
	{
		if (strcmp(dadosPacientes.paciente[i].resultado,"P")==0)
		{
			cidadesDF[dadosPacientes.paciente[i].cidade-1].quantidade = cidadesDF[dadosPacientes.paciente[i].cidade-1].quantidade + 1;
		}
	}
	
	printf("Cidade                                  Quantidade\n");
	printf("==================================================\n");
	for(i=0;i<25;i++)
	{
    	printf("%s                                      %i    \n",cidadesDF[i].cidade,cidadesDF[i].quantidade);
	}
	printf("\n Digite qualquer tecla para sair "); 
	char dig[2];
	fflush(stdin); 
	fgets (dig, 2, stdin);
}

exibeTipoTeste()
{
 	int i;
	int totalT = 0;
	int totalS = 0;
	int totalR = 0;

	system("cls");
	puts("=====================================================");
	puts("=====  Secretaria de Saúde do Distrito Federal  =====");
	puts("=====================================================");
	puts(" ");
	puts("   RELATORIOS DO SISTEMA");
	puts(" ");
	puts(" Indicacao do Tipo de Teste mais usado");
	puts(" ");
	for(i=0;i<dadosPacientes.registros;i++)
	{
		if (strcmp(dadosPacientes.paciente[i].teste,"T")==0)
		{
		 totalT++;	
		}
		else if (strcmp(dadosPacientes.paciente[i].teste,"S")==0)
		{
		 totalS++;	
		}
		else if (strcmp(dadosPacientes.paciente[i].teste,"R")==0)
		{
		 totalR++;	
		}
	}
	printf("Tipo Teste                              Quantidade\n");
	printf("==================================================\n");
	printf("S - Sorologia                              %d\n",totalS);
	printf("R - RT-PCR                                 %d\n",totalR);
	printf("T - Teste Rapido                           %d\n",totalT);
	printf("\n O teste mais aplicado ");

	printf("\n Digite qualquer tecla para sair "); 
	char dig[2];
	fflush(stdin); 
	fgets (dig, 2, stdin);
}

menu_relatorios()
{
	int opcao = 0;
	do
	{		
		system("cls");
		puts("=====================================================");
		puts("=====  Secretaria de Saúde do Distrito Federal  =====");
		puts("=====================================================");
		puts(" ");
		puts("   RELATORIOS DO SISTEMA");
		puts(" ");
		puts("ESCOLHA UMA OPÇÃO:\n");
		puts("1 - EXIBIR DADOS.\n");
		puts("2 - EXIBIR DADOS HOMENS MENORES DE IDADE.\n"); 
		puts("3 - EXIBIR DADOS MULHERES MENORES DE IDADE.\n"); 
		puts("4 - EXIBIR DADOS HOMENS IDOSOS.\n"); 
		puts("5 - EXIBIR DADOS MULHERES IDOSAS.\n");
		puts("6 - EXIBIR OCORRENCIAS POR CIDADE.\n"); 
		puts("7 - EXIBIR OCORRENCIAS POR TIPO DE TESTE.\n");
    	puts("8 - SAIR.\n");
    	puts("Opcao [   ]");
    	gotoxy(9,25);
    	scanf("%i", &opcao);
    	switch(opcao)
		{
    		case 1: 
            	exibeDados();
            	break;
    		case 2: 
    			exibeDadosMascMenor();
            	break;
        	case 3: 
           	 	exibeDadosFemMenor();
            	break;
    		case 4: 
    			exibeDadosMascIdoso();
            	break;
     		case 5: 
            	exibeDadosFemIdoso();
            	break;
    		case 6: 
    			exibeQuantitativoCidades();
            	break;
        	case 7: 
            	exibeTipoTeste();
            	break;
            case 8: 
            	break;
			default: 
	        	printf ("A opção selecionada está incorreta!\nPor favor digite novamente a opção desejada!");
		}
	}while(opcao!=8);	
}

main() 
{
	int registro = 0;
	inicializaDados(dadosPacientes);
	inicializaCidadesDF(cidadesDF);
	int opcao = 0;
	do
	{		
	    system("cls");
		puts("=====================================================");
		puts("=====  Secretaria de Saúde do Distrito Federal  =====");
		puts("=====================================================");
		puts(" ");
		puts("   CADASTRO DE TESTES DE DIAGNÓSTICO PARA COVID-19");
		puts(" ");
		puts("ESCOLHA UMA OPÇÃO:\n");
		puts("1 - Cadastro.\n");
		puts("2 - Relatórios.\n"); 
    	puts("3 - Sair.\n");
    	puts("Opcao [   ]");
    	gotoxy(9,15);
    	scanf("%i", &opcao);
    	switch(opcao)
		{
    	case 1: 
            cadastrar_paciente();
            break;
    	case 2: 
    		menu_relatorios();
            break;
    	case 3: 
			break;
		default: 
	        printf ("A opção selecionada está incorreta!\nPor favor digite novamente a opção desejada!");
		}
	}while(opcao!=3);
}
