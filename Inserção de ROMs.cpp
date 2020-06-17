//NOME DO ALUNO: JHONATAS ALVES DE SOUZA
//jhonatasa_s@hotmail.com
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

//STRUCTS
typedef struct rom
{
	int codigo;
	string nome;
	int tamanho;
};
typedef struct rom tRom;


//CHAMADAS DE FUNCOES
void limpaTela();
void imprimeFuncoesSistema();
void imprimeCabecalho();
void switchCase(map<int, tRom> &roms);
void cadastraROM(map<int, tRom> &roms);
int numeroAleatorio();
void editaROM(map<int, tRom> &roms);
void excluiROM(map<int, tRom> &roms);
void consultaROM(map<int, tRom> &roms);
void imprimeCatalogo(map<int, tRom> roms);
//PROGRAMA PRINCIPAL
int main()
{
	imprimeCabecalho();

	//criando map
	map<int, tRom> mapaRoms;
	//menu do Programa
	switchCase(mapaRoms);
	system("pause");
	return 0;
}


//FUNCAO IMPRIME CABEÇALHO
void imprimeCabecalho()
{
	printf("-------------Por favor escolha a opcao desejada------------- \n");
}
//FUNCAO LIMPA A TELA
void limpaTela()
{
	system("CLS");
}
void imprimeFuncoesSistema()
{
	limpaTela();
	imprimeCabecalho();
	printf("1 - Cadastra ROM \n");
	printf("2 - Edita ROM \n");
	printf("3 - Exclui ROM \n");
	printf("4 - Consulta ROM \n");
	printf("5 - Imprime Catálogo \n");
}
void switchCase(map<int, tRom> &roms)
{
	int opcao = 0;
	while(opcao != 6)
	{
		//FUNCOES DO SISTEMA
		imprimeFuncoesSistema();

		scanf("%d", &opcao);

		switch(opcao)
		{
		case  1  :

			cadastraROM(roms);
			system("pause");
			break;
		case 2 :
			editaROM(roms);
			system("pause");
			break;
		case  3 :
			excluiROM(roms);
			system("pause");
			break;
		case  4 :
			consultaROM(roms);
			system("pause");
			break;
		case  5 :
			imprimeCatalogo(roms);
			system("pause");
			break;
		case 6 :
			printf("ATÉ MAIS!!!!", opcao);
			break;

		default:
			printf("Opcao ivalida");
			break;
		}
	}
}
void cadastraROM(map<int, tRom> &roms)
{
	tRom nova;
	cout << "\t\t *** CADASTRO DE ROM ***" << endl;
	cout << "DIGITE O NOME DA ROM QUE DESEJA CADASTRAR " << endl;
	cin >> nova.nome;
	cout << "DIGITE O TAMANHO DA ROM QUE DESEJA CADASTRAR " << endl;
	cin >> nova.tamanho;
	int codigo = numeroAleatorio();
	nova.codigo = codigo;
	cout << codigo;
	roms[codigo] = nova;
}
void editaROM(map<int, tRom> &roms)
{
	if(roms.size() != 0)
	{
		int codigo;
		cout << "\t\t *** EDICAO DE ROM ***" << endl;
		cout << "DIGITE O CODIGO DA ROM QUE DESEJA EDITAR" << endl;
		cin >> codigo;
		if(roms.find(codigo) == roms.end())
		{
			cout << "ROM NAO ENCONTRADA" << endl;
		}
		else
		{
			cout << "PARA QUAL NOME DESEJA ALTERAR A ROM " << roms[codigo].nome << endl;
			cin >> roms[codigo].nome;
			cout << "PARA QUAL TAMANHO DESEJA ALTERAR ROM " << roms[codigo].nome << endl;
			cin >> roms[codigo].tamanho;
		}
	}
	else
	{
		cout << "\t\t *** NAO HA NENHUMA ROM CADASTRADA ***" << endl;
	}
}
void excluiROM(map<int, tRom> &roms)
{
	if(roms.size() != 0)
	{
		int codigo;
		cout << "\t\t *** EXCLUSAO DE ROM ***" << endl;
		cout << "DIGITE O CODIGO DA ROM QUE DESEJA EXCLUIR" << endl;
		cin >> codigo;
		if(roms.find(codigo) == roms.end())
		{
			cout << "ROM NAO ENCONTRADA" << endl;
		}
		else
		{
			cout << "ROM " << roms[codigo].nome << " EXCLUIDA " << endl;
			roms.erase(codigo);
		}
	}
	else
	{
		cout << "\t\t *** NAO HA NENHUMA ROM CADASTRADA ***" << endl;
	}
}
void consultaROM(map<int, tRom> &roms)
{
	if(roms.size() != 0)
	{
		int codigo;
		cout << "\t\t *** CONSULTA DE ROM ***" << endl;
		cout << "DIGITE O CODIGO DA ROM QUE DESEJA CONSULTA" << endl;
		cin >> codigo;
		if(roms.find(codigo) == roms.end())
		{
			cout << "ROM NAO ENCONTRADA" << endl;
		}
		else
		{
			cout << "ROM {NOME} " << roms[codigo].nome << "  " << endl;
			cout << "ROM {TAMANHO} " << roms[codigo].tamanho << "  " << endl;
			cout << "ROM {CODIGO} " << roms[codigo].codigo << "  " << endl;
		}
	}
	else
	{
		cout << "\t\t *** NAO HA NENHUMA ROM CADASTRADA ***" << endl;
	}
}
void imprimeCatalogo(map<int, tRom> roms)
{
	map <int, tRom>::iterator mapIterator;
	if(roms.size() != 0)
	{
		for(mapIterator = roms.begin(); mapIterator != roms.end(); mapIterator++)
		{
			cout << "ROM {NOME}: " << mapIterator->second.nome << " ";
			cout << "ROM {CODIGO}: " << mapIterator->second.codigo << " ";
			cout << "ROM {TAMANHO}: " << mapIterator->second.tamanho << "> ";
			cout << endl;
		}
	}
	else
	{
		cout << "\t\t *** NAO HA NENHUMA ROM CADASTRADA ***" << endl;
	}
}

//FuncaoGeraCodigoRom
int numeroAleatorio()
{
	int a = rand() % 100;
	int b = rand() % 100;
	int c = (a * b) * (RAND_MAX) ;
	if(c == 0)
	{
		c = RAND_MAX;
	}
	return c;
}

