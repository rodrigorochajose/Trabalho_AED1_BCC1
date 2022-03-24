/*
  Programa : trabalhofinal.cpp
  Programador: Rodrigo Rocha
  Data da Última Atualização: 25/11/2021
  Horas: 10h00m
  Descrição: Trabalho Final
*/
#include <iostream>
#include <iomanip>
#include <clocale>
using namespace std;

struct NOLDL {
    NOLDL *pe;
    string pais;
    float hab;
    string idioma;
    float pib;
    NOLDL *pd;
};

NOLDL *ild, *ile, *aux;
char conf;

void IMPRI();
void LDL00();
void LDL01();
void LDL02();
void LDL03();
void LDL04();
void LDL05();
void LDL06();

int main (){

    setlocale (LC_ALL, "Portuguese");

    ild = NULL;
    ile = NULL;
    aux = ild;
    char op = 'X';
    while (op != '0'){
            system ("cls");
            cout << "\n\n\t\t\t\t\t\t\t\t\tPrograma Trabalho Final\t\n\n\n";
            cout << "\n\t\t1- Inserir Nó na Lista.";
            cout << "\n\t\t2- Imprimir Lista.";
            cout << "\n\t\t3- Procurar um nó e inserir após.";
            cout << "\n\t\t4- Consultar nó pelo PIB.";
            cout << "\n\t\t5- Procurar e Remover nó encontrado.";
            cout << "\n\t\t6- Classificar a lista em ordem crescente de descrição.";
            cout << "\n\t\t7- Imprimir o conteúdo da lista em ordem inversa.";
            cout << "\n\t\t8- Imprimir o nome do pais, o idioma e a quantidade de habitantes para os países que tem quantidade de habitantes maior que a media.";
            cout << "\n\t\t0- Sair";

            cout << "\n\n\n\t\tEscolha uma opção : ";
            fflush(stdin);
            cin >> op;
            fflush(stdin);
            op = toupper(op);

            switch (op){
                    case '1': LDL00(); break;
                    case '2': IMPRI(); break;
                    case '3': LDL01(); break;
                    case '4': LDL02(); break;
                    case '5': LDL03(); break;
                    case '6': LDL04(); break;
                    case '7': LDL05(); break;
                    case '8': LDL06(); break;
                    case '0': system ("cls"); cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\tObrigado por usar nosso serviço.\n\n\n\n\n"; break;
                    default: cout << "\t\t\tOpção Inválida.\n\n"; break;
            }
    }
}

void LDL00(){

    system("cls");
    cout << "\n\n\t\t\t\t\t\t\t\t\tPrograma Inserir Nó no Inicio\n\n";

    NOLDL *ant;
    ant = NULL;

    aux = new(NOLDL);
    if (aux != NULL){
        cout << "\n\t\tInforme Pais : ";
        cin >> aux->pais;
        cout << "\n\t\tInforme Número de Habitantes : ";
        cin >> aux->hab;
        cout << "\n\t\tInforme Idioma : ";
        cin >> aux->idioma;
        cout << "\n\t\tInforme PIB : ";
        cin >> aux->pib;
        cout << "\n\n\n\t\tConfirma (S/N): ";
        cin >> conf;
        conf = toupper(conf);
        if (conf == 'S'){
            if (ild == NULL){
                aux->pd = NULL;
                ile = aux;
            }
            else {  aux->pd = ild;
                    ild->pe = aux;
            }
            aux->pe = NULL;
            ild = aux;
            cout << "\n\n\t\t\t\t\t\t\t\t\t\tNó inserido.\n";
        }
        else {  cout << "\n\n\t\t\t\t\t\t\t\t\t   Dados não confirmados.\n";
                delete(aux);
        }
    }
    else cout << "\n\n\t\t\t\t\t\t\t\t\tMemória insuficiente.\n";
    system ("pause");
}

void IMPRI(){

    system("cls");
    cout << "\n\n\t\t\t\t\t\t\t\t\tPrograma Imprimir Lista\t\n\n\n\n";

    if (ild != NULL){
        cout << "\n\t" << setw(10) << "ENDEREÇO" << setw(15) <<  "PE" << setw(15) << "PAIS" << setw(15) << "HABITANTES" << setw(15) << "IDIOMA" << setw(15) << "PIB" << setw(15) << "PD" << endl;
        aux = ild;
        while (aux != NULL){
                cout << endl;
                cout << "\n\t" << setw(10) << aux << setw(15) << aux->pe << setw(15) << aux->pais << setw(15) << aux->hab << setw(15) << aux->idioma << setw(15) << aux->pib << setw(15) << aux->pd << endl;
                aux = aux->pd;
        }
    }
    else cout << "\n\n\t\t\t\t\t\t\t\t\t      Lista Vazia.\n";
    cout << "\n\n";
    system ("pause");
}

void LDL01(){

	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t\t\tPrograma Procurar um nó e inserir após\n\n";

	NOLDL *novo;
	string pais;

    cout << "\n\t\tInforme Pais que será procurado : ";
    cin >> pais;
    if (ild != NULL){
        while (aux->pais != pais && aux->pd != NULL)
                aux = aux->pd;
        if (aux->pais == pais){
            novo = new(NOLDL);
            if (novo != NULL){
                cout << "\n\t\tInforme Pais : ";
                cin >> novo->pais;
                cout << "\n\t\tInforme Número de Habitantes : ";
                cin >> novo->hab;
                cout << "\n\t\tInforme Idioma : ";
                cin >> novo->idioma;
                cout << "\n\t\tInforme PIB : ";
                cin >> novo->pib;
                cout << "\n\n\n\t\tConfirma (S/N): ";
                cin >> conf;
                conf = toupper(conf);
                if (conf == 'S'){
                    if (aux == ile){
                        aux->pd = novo;
                        novo->pd = NULL;
                        ile = novo;
                    }
                    else {  novo->pd = aux->pd;
                            aux->pd->pe = novo;
                            aux->pd = novo;
                    }
                    novo->pe = aux;
                }
                else cout << "\n\n\t\t\t\t\t\t\t\t\t   Dados não confirmados.\n";
            }
            else cout << "\n\n\t\t\t\t\t\t\t\t\tMemória insuficiente.\n";
        }
        else cout << "\n\n\n\t\t\t\t\t\t\t\t'" << pais << "' não pertence a lista.\n";
    }
    else cout << "\n\n\t\t\t\t\t\t\t\t\tLista Vazia.\n";
    system ("pause");
}

void LDL02(){

    system("cls");
	cout << "\n\n\t\t\t\t\t\t\t\t\tPrograma Consultar nó pelo PIB\n\n";

	float pib;

    cout << "\n\t\tInforme PIB : ";
    cin >> pib;
    if (ild != NULL){
        while (aux->pib != pib && aux->pd != NULL)
                aux = aux->pd;
        if (aux->pib == pib)
            cout << "\n\n\n\t\t\t\t\t\t\t\t\tPIB '" << pib << "' pertence a lista.\n";
        else cout << "\n\n\n\t\t\t\t\t\t\t\t\tPIB '" << pib <<"' não pertence a lista.\n";
    }
    else cout << "\n\n\t\t\t\t\t\t\t\t\t\tLista Vazia.\n";
    system ("pause");
}

void LDL03(){

    system("cls");
	cout << "\n\n\t\t\t\t\t\t\t\t\tPrograma Procurar e Remover nó encontrado\n\n";

	string pais;

	cout << "\n\t\tInforme Pais : ";
	cin >> pais;
	if (ild != NULL){
        aux = ild;
        while (aux->pais != pais && aux->pd != NULL)
				aux = aux->pd;
        if (aux->pais == pais){
            cout << "\n\n\t\tPais : " <<  aux->pais << "\n\t\tHabitantes : " << aux->hab << "\n\t\tIdioma : " << aux->idioma << "\n\t\tPIB : " << aux->pib << endl;
            cout << "\n\n\n\t\tConfirma Remoção (S/N) :";
            cin >> conf;
            conf = toupper(conf);
            if (conf == 'S'){
                if (aux == ild && aux == ile){
                    ild = NULL;
                    ile = NULL;
                }
                else if (aux == ild){
                            aux->pd->pe = NULL;
                            ild = aux->pd;
                }
                else if (aux == ile){
                            ile->pe->pd = NULL;
                            ile = aux->pe;
                }
                else {  aux->pe->pd = aux->pd;
                        aux->pd->pe = aux->pe;
                }
                delete(aux);
                cout << "\n\n\t\t\t\t\t\t\t\t\t\tNó Removido.\n";
                }
            else cout << "\n\n\t\t\t\t\t\t\t\t\t\tDados não confirmados.\n";
        }
        else cout << "\n\n\n\t\t\t\t\t\t\t\t'" << pais << "' não pertence a lista.\n";
	}
	else cout << "\n\n\t\t\t\t\t\t\t\t\tLista Vazia.\n";
    system ("pause");
}

void LDL04(){

    system("cls");
	cout << "\n\n\t\t\t\t\t\t\t\t\tPrograma Classificar a lista em ordem crescente de descrição\n\n";

	NOLDL *aux2;
    string apais, aid;
    int ahab;
    float apib;

    aux = ild;
    aux2 = NULL;
    if (aux != NULL){
        while (aux != NULL){
                aux2 = aux->pd;
                while (aux2 != NULL){
                        if (aux->hab > aux2->hab){
                            apais = aux->pais;
							ahab = aux->hab;
							aid = aux->idioma;
							apib = aux->pib;
							aux->pais = aux2->pais;
							aux->hab = aux2->hab;
							aux->idioma = aux2->idioma;
							aux->pib = aux2->pib;
							aux2->pais = apais;
							aux2->hab = ahab;
							aux2->idioma = aid;
							aux2->pib = apib;
                        }
                        aux2 = aux2->pd;
                }
                aux = aux->pd;
        }
    cout << "\n\n\t\t\t\t\t\t\t\tLista classificada em ordem crescente.\n";
    }
    else cout << "\n\n\t\t\t\t\t\t\t\t\tLista Vazia.\n";
    system ("pause");
}

void LDL05(){

    system("cls");
	cout << "\n\n\t\t\t\t\t\t\t\t\tPrograma Imprimir o conteúdo da lista em ordem inversa\n\n";

    if (ile != NULL){
        cout << "\n\t" << setw(10) << "ENDEREÇO" << setw(15) <<  "PE" << setw(15) << "PAIS" << setw(15) << "HABITANTES" << setw(15) << "IDIOMA" << setw(15) << "PIB" << setw(15) << "PD" << endl;
        aux = ile;
        while (aux != NULL){
                cout << endl;
                cout << "\n\t" << setw(10) << aux << setw(15) << aux->pe << setw(15) << aux->pais << setw(15) << aux->hab << setw(15) << aux->idioma << setw(15) << aux->pib << setw(15) << aux->pd << endl;
                aux = aux->pe;
        }
    }
    else cout << "\n\n\t\t\t\t\t\t\t\t\tLista Vazia.\n";
    cout << "\n\n";
    system ("pause");
}

void LDL06(){

    system("cls");
	cout << "\n\n\tPrograma Imprimir o nome do pais, o idioma e a quantidade de habitantes para os países que tem quantidade de habitantes maior que a media.\n\n";

    int soma, cont, i;
    float media;
    NOLDL *vet[10];

    if (ild != NULL){
        i = 0;
        soma = 0;
        cont = 0;
        aux = ild;
        while (aux != NULL){
                soma += aux->hab;
                aux = aux->pd;
                cont++;
        }
        media = (float) soma/cont;
        aux = ild;
        while (aux != NULL){
                if (aux->hab > media){
                    cout << "\n\nPais, idioma e quantidade de habitantes que tem quantidade de habitantes maior que a média : " << aux->pais << " | " << aux->hab << " | " << aux->idioma << " | \n";
                    i++;
                }
                aux = aux->pd;
        }
    }
    else cout << "\n\n\t\t\t\t\t\t\t\t\tLista Vazia.\n";
    cout << "\n\n";
    system ("pause");
}
