//PER OSSERVARE IL DIAGRAMMA DI FLUSSO, LO SI DEVE APRIRE IN UNA NUOVA FINESTRA

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
///////////////////sub func//////////////////////////////////////////////

string testo_input ( string);
int dato_input ( string);
/*void inserimento(string, string , string );*/
int menu_options(int );
//void ordin_circ( int, string, string, string, string, string, int);
//void change(int, int);
void swap_dato(string[], string[], int, int);
void swap_num(int[],int[],int,int);
//void ordina( int, string , string, string,string, string, int , int );
//void stampa_classi(int , string, string);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main ()
{
  
  int menu;			/*numero del menu */
  int totale_alunni = 100;

  string nome_alunno[totale_alunni];
  string cognome_alunno[totale_alunni];
  string indirizzo[totale_alunni];
  string citta[totale_alunni];
  string scuola_di_prov[totale_alunni];
	int circoscrizione[totale_alunni];
	int cap[totale_alunni];

	int  conta_alunni = 0; 

	string select_name_mody, select_surname_mody;
	int controllo;

	bool instruction = true;

	int conta_menu3 = 3, conta_menu2 = 8, conta_menu_principale = 6;
	
	do
	{
		system ("clear");
	/*	cout << "::::::::::::::::MENU::::::::::::::::" << endl << "1) INSERISCI" <<
    endl << "2) MODIFICA " << endl << "3) CANCELLA" << endl << "4) GENERA" << endl << "5) STAMPA"<< endl <<
    "6) EXIT" << endl << endl;
	    
	  cout << "seleziona: ";
	  cin >> menu;
	  
	  while (menu < 1 || menu > 5)
	    {
	      cout << "errore, seleziona: ";
	      cin >> menu;
	    }
	 */
		
				cout << "::::::::::::::::MENU::::::::::::::::" <<endl<< "1) INSERISCI"<<endl<< "2) MODIFICA "<<endl<< "3) CANCELLA"<<endl<< "4) GENERA" <<endl<< "5) STAMPA"<<endl<< "6) EXIT"<<endl ;
				menu = menu_options(conta_menu_principale);

			
	      switch (menu)
	    	{
		    	case 1:
					{
						
						
						system ("clear");	//per pulire lo schermo al posto del (cls)che su replit non e valido
		        cout << "INSERIRE DATI DELLO STUDENTE: " << endl;
		    	  nome_alunno[conta_alunni] = testo_input ("nome: ");
		    	  cognome_alunno[conta_alunni] = testo_input ("cognome: ");
		    	  indirizzo[conta_alunni] = testo_input ("via/corso di residenza: ");
		    	  citta[conta_alunni] = testo_input ("citta: ");
		    	  scuola_di_prov[conta_alunni] = testo_input ("escuola di provenienza:");
						circoscrizione[conta_alunni] = dato_input("circoscrizione numero: ");
						cap[conta_alunni] = dato_input("CAP : ");
		    	  conta_alunni++;
						instruction = false;
						break;
					}
					
					////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					case 2 :
					{
						system("clear");
						/*inserimento("MODIFICA DATI STUDENTE", select_name_mody, select_surname_mody);*/
						cout << "MODIFICA DATI STUDENTE:"<< endl;
						select_name_mody= testo_input("inserire nome dello studente del quale si vuole efettuare la modifica dei dati: ");
						select_surname_mody= testo_input("inserire cognome dello studente del quale si vuole efettuare la modifica dei dati: ");
						for(int j = 0; j < conta_alunni; j++){
							if(select_name_mody == nome_alunno[j] && select_surname_mody == cognome_alunno[j])
							{
								instruction = true;
								do
								{
	/*								cout << "OPZIONI DI MODIFICA:" << endl << "1) NOME" << endl<< "2) COGNOME" <<endl << "3) INDIRIZZO" <<endl <<"4) CITTA" <<endl <<"5) SCUOLA DI PROVENIEZA" <<endl << "6) NESSUNA MODIFICA"<< endl << "seleziona: ";
									cin >> controllo;
									while (controllo < 1 || controllo > 6)
							    {
							      cout << "errore, seleziona: ";
							      cin >> controllo;
									}
*/								
									system("clear");
									
									cout << "OPZIONI DI MODIFICA:"<<endl<< "1) NOME"<<endl<< "2) COGNOME "<<endl<< "3) INDIRIZZO"<<endl<< "4) CITTA" <<endl<< "5) SCUOLA DI PROVENIENZA"<<endl<< "6)CIRCOSCRIZIONE" <<endl<< "7)CAP"<<endl<<"8) EXIT"<<endl;
									controllo = menu_options(conta_menu2);
							    
									switch(controllo) //si va a inserire un menu con il quale l'admin puo modificare un singolo dato
									{
										case 1:
										{
											system("clear");
											nome_alunno[j] = testo_input ("nome: ");
											instruction = false;
											break;
										}
										case 2:
										{
											system("clear");
											 cognome_alunno[j] = testo_input ("cognome: ");
											instruction = false;
											break;
										}
										case 3:
										{
											system("clear");
											indirizzo[j] = testo_input ("via/corso di residenza: ");
											instruction = false;
											break;
										}
										case 4:
										{
											system("clear");
											citta[j] = testo_input ("citta: ");
											instruction = false;
											break;
										}
										case 5:
										{
											system("clear");
											 scuola_di_prov[j] = testo_input ("escuola di provenienza:");
											instruction = false;
											break;
										}
										case 6:
										{
											system("clear");
											 circoscrizione[j] = dato_input ("circoscrizione:");
											instruction = false;
											break;
										}
										case 7:
										{
											system("clear");
											 cap[j] = dato_input ("CAP:");
											instruction = false;
											break;
										}
										case 8:
										{
											system("clear");
											instruction = true;
										}
									}
								}while(instruction == false);
							}
							else
							{
								
								cout << "STUDENTE NON RECISTRATO! " << endl;
							}
						}
					}
					
					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					case 3:
					{
						system("clear");
						cout << "CANCELLA ISCRIZIONE STUDENTE:"<< endl;
						select_name_mody= testo_input("inserire nome dello studente da eliminare: ");
						select_surname_mody= testo_input("inserire cognome dello studente da eliminare: ");
						for(int j = 0; j < totale_alunni; j++ )
						{
							if(select_name_mody == nome_alunno[j] && select_surname_mody == nome_alunno[j])
							{
								for(int k=j +1; k < totale_alunni; k++)
								{
									nome_alunno[j] = nome_alunno[k];
									cognome_alunno[j] = cognome_alunno[k];
									indirizzo[j] = indirizzo[k];
									citta[j] = citta[k];
									scuola_di_prov[j] = scuola_di_prov[k];
									circoscrizione[j] = circoscrizione[k];
									cap[j] = cap[k];
								}
								conta_alunni-- ; 
								cout << "STUDENTE RIMOSSO CON SUCCESSO! " << endl;
							}
							else
							{
								cout << "STUDENTE NON REGISTRATO! " << endl;
							}
						}
						instruction = false;
						break;
					}

					//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					case 4:
					{
						system("clear");
						string temp; //variabile auxiliaria scambio stringhe
						int val; ///variabile auxiliaria scambio numeri
						//  int n_class = 10;

						for (int i = 0; i < conta_alunni - 1; i++)
						{
							for (int j = i+1; j < conta_alunni - i - 1; j++)
							{
								if (circoscrizione[i] > circoscrizione[j])
								{
								  swap_dato(nome_alunno, nome_alunno, i, j);
									swap_dato(cognome_alunno,cognome_alunno,i, j);
									swap_dato(indirizzo, indirizzo,i, j);
									swap_dato(citta, citta,i, j);
				          swap_dato(scuola_di_prov, scuola_di_prov,i, j);
									swap_num(circoscrizione, circoscrizione,i, j);
									swap_num(cap, cap,i, j);
										/*
								  temp = nome_alunno[i];
							    nome_alunno[i] = nome_alunno[j];
							    nome_alunno[j] = temp;

									temp = cognome_alunno[i];
							    cognome_alunno[i] = cognome_alunno[j];
							    cognome_alunno[j] = temp;
									
									temp = indirizzo[i];
							    indirizzo[i] = indirizzo[j];
							    indirizzo[j] = temp;
									
									temp = citta[i];
							    citta[i] = citta[j];
							    citta[j] = temp;

									temp = scuola_di_prov[i];
							    scuola_di_prov[i] = scuola_di_prov[j];
							    scuola_di_prov[j] = temp;

									val = circoscrizione[i];
									circoscrizione[i] = circoscrizione[j];
									circoscrizione[j] = val;

									val = cap[i];
									cap[i] = circoscrizione[j];
									circoscrizione[j] = val;
				 */
								}
							}   
						}		
						
						int max = 5;
						int min = 7;
						int conta = 0;
						int x = 1; //conta un tot per inserire lo studente nella classe
						char alfabeto [10]= {'A','B','C','D','E','F','G','H','I','J'};
						cout <<"LE CLASSI SONO:" << endl <<"::::::: 1ma "<< alfabeto[0]<<" ::::::::" <<endl;
						for(int j = 0;j < conta_alunni; j++)
						{
							conta++;
							if(conta > min && conta <= max)
							{
								cout <<"::::::: 1ma "<< alfabeto[x]<<" ::::::::" <<endl;
								conta = 0;
								x ++;
							}
							else
							{
								cout << ":::::::::::::::STUDENTI SENZA CLASSE:::::::::::: " << endl;
							}
							if(x < 10)
							{
								cout << nome_alunno[j] <<" "<< cognome_alunno[j] <<endl;
							}
							else
							{
								cout << nome_alunno[j] <<" "<< cognome_alunno[j] <<endl;
							}
						}
					  instruction = false;
						break;
					}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					case 5:
					{
						system("clear");
						cout <<"SELEZIONA ORDINE DI STAMPA"<<endl<<"1) PER CAP"<<endl<<"2) PER CIRCOSCRIZIONE"<< endl;
						controllo = menu_options(conta_menu3);

						switch(controllo)
						{
							case 1:
							{
								system("clear");
								cout<<"ELENCO ALUNNI IN ORDINE CRESCENTE IN BASE A LA CIRCOSCRIZIONE"<< endl;
								for (int i = 0; i < conta_alunni - 1; i++)
								{
									for (int j = i+1; j < conta_alunni - i - 1; j++)
									{
										if (circoscrizione[i] > circoscrizione[j])
										{
											
										  swap_dato(nome_alunno, nome_alunno, i, j);
											swap_dato(cognome_alunno,cognome_alunno,i, j);
											swap_dato(indirizzo, indirizzo,i, j);
											swap_dato(citta, citta,i, j);
						          swap_dato(scuola_di_prov, scuola_di_prov,i, j);
											
											swap_num(circoscrizione, circoscrizione,i, j);
											swap_num(cap, cap,i, j);
										}
									}   
								}	
								for (int j = 0; j < conta_alunni; j++)
								{
									cout << " " << circoscrizione << " " << nome_alunno << " " << cognome_alunno << " " << indirizzo<< " " << citta << " " << scuola_di_prov << " " << cap;
								}
							}
							case 2:
							{
								system("clear");
								cout<<"ELENCO ALUNNI IN ORDINE CRESCENTE IN BASE AL CAP"<< endl;
								for (int i = 0; i < conta_alunni - 1; i++)
								{
									for (int j = i+1; j < conta_alunni - i - 1; j++)
									{
										if (cap[i] > cap[j])
										{
											
										  swap_dato(nome_alunno, nome_alunno, i, j);
											swap_dato(cognome_alunno,cognome_alunno,i, j);
											swap_dato(indirizzo, indirizzo,i, j);
											swap_dato(citta, citta,i, j);
						          swap_dato(scuola_di_prov, scuola_di_prov,i, j);
											
											swap_num(circoscrizione, circoscrizione,i, j);
											swap_num(cap, cap,i, j);
										}
									}   
								}	
								for (int j = 0; j < conta_alunni; j++)
								{
									cout << " " << cap << " " << nome_alunno << " " << cognome_alunno << " " << indirizzo<< " " << citta << " " << scuola_di_prov << " " << circoscrizione;
								}
						}
						instruction = false;
						break;
					}
				}
				}
	}while(instruction == false);
}

//////////////////////////////////funz/////////////////////////

string
testo_input (string msg)
{
  string val;
  cout << msg;
	cin.ignore(); //per ingnorare 
  getline(cin,val);
  return val;
}

int dato_input (string msg)
{
  int d;
  cout << msg;
  cin >> d;
	while(d < 0)
	{
		cout << "ERRORE, "<< msg;
  	cin >> d;
	}	
  return d;
}

int menu_options(int n)//contatore numero max di opzioni
{
	int val;
	cout <<"inserire numero operazione: "<< endl;
  cin >> val;
	while (val < 1 || val > n)
	    {
	      cout << "errore, seleziona: ";
	      cin >> val;
	    }
	return val;
}
/*
void ordina( int n, string* a, string* b, string * c,string* d, string *e, int *f, int *g)
{
	for (int i = 0; i < n - 1; i++)
						{
							for (int j = i+1; j < n - i - 1; j++)
							{
								if (f[i] > f[j])
								{
							  	swap_str(nome_alunno[i], nome_alunno[j]);
									swap_str(cognome_alunno[i],cognome_alunno[j]);
									swap_str(indirizzo[i], indirizzo[j]);
									swap_str(citta[i], citta[j]);
				          swap_str(scuola_di_prov[i], scuola_di_prov[j]);
									swap_int(circoscrizione[i], circoscrizione[j]);
									swap_int(cap[i], cap[j]);
							
									string temp = a[i];
							    a[i] = a[j];
							    a[j] = temp;
									
									temp = b[i];
							    b[i] = b[j];
							    b[j] = temp;

									temp = c[i];
							    c[i] = c[j];
							    c[j] = temp;
									
									temp = d[i];
							    d[i] = d[j];
							    d[j] = temp;
									
									temp = e[i];
							    e[i] = e[j];
							    e[j] = temp;

									int val = f[i];
									f[i] = f[j];
									f[j] = val;

									val = g[i];
									g[i] = g[j];
									g[j] = val;
								}
							}   
						}	
}
 */				
/*void ordina( int n, string* a, string* b, string * c,string* d, string *e, int *f, int *g)
{
	 int i, j;
    for (i = 0; i < n - 1; i++)
		{
			for (j = i+1; j < n - i - 1; j++)
			{
				if (f[j] > f[j + 1])
				{
					swap_str(a[i], a[j]);
					swap_str(b[i], b[j]);
					swap_str(c[i], c[j]);
					swap_str(d[i], d[j]);
          swap_int(f[i], f[j]);
					swap_int(g[i], g[j]);
				}
			}   
		}						
}*/

/*void inserimento(string option, string a, string b)
{
	cout << option << endl;
  a= testo_input("inserire nome dello studente: ");
	b= testo_input("inserire cognome dello studente: ");							
}*/
/*
void ordin_circ(int n, string* nome_alunno, string* cognome_alunno, string* indirizzo, string* citta, string* scuola_di_prov, int* circoscrizione){
	for( int j = 0; j < n-1; j++)
	{
		for (int k = 0; k < n - j - 1; ++k) 
		{
			change (circoscrizione, k);
    	change (nome_alunno, k);
			change (cognome_alunno, k);
			change (indirizzo, k);
			change (citta, k);
			change (scuola_di_prov, k);

			if (circoscrizione[k] > circoscrizione[k + 1]) 
			{
				swap_int(circoscrizione[k], circoscrizione[k + 1]);
				swap_str(nome_alunno[k], nome_alunno[k + 1]);
				swap_str(cognome_alunno[k], cognome_alunno[k + 1]);
				swap_str(indirizzo[k], indirizzo[k + 1]);
				swap_str(citta[k], citta[k + 1]);
				swap_str(scuola_di_prov[k], scuola_di_prov[k + 1]);
			} 
    }
  }
}

void change(int *arr[], int i)
{
	if (arr[i] > arr[i + 1]) 
        swap(arr[i], arr[i + 1]); // Swap
}

void ordina( string *arr[], int i)
{
	swap(arr[i], arr[i + 1]);
}*/


void swap_num(int* a, int* b,int i, int j)
{
    int temp = a[i];
    a[i] = b[j];
    b[j]= temp;
}
void swap_dato(string* a, string* b, int i, int j)//SWAP DATO SU TUTTI RICORDA
{
    string val;
		val = a[i];
    a[i] = b[j];
    b[j]= val;
}
/*
void stampa_classi(int n, string* a, string* b)
{
	int max = 5;
	int min = 7;
	int conta = 0;
	int x = 1; //contaclassi
	char alfabeto [10]= {'A','B','C','D','E','F','G','H','I','J'};
	cout <<"LE CLASSI SONO:" << endl <<"::::::: 1ma "<< alfabeto[0]<<" ::::::::" <<endl;
	for(int i = 0; i < n; i++)
	{
		conta++;
		if(conta > min && conta <= max)
		{
			cout <<"::::::: 1ma "<< alfabeto[x]<<" ::::::::" <<endl;
			conta = 0;
			x ++;
		}
		else
		{
			cout << ":::::::::::::::SUUDENTI SENZA CLASSE:::::::::::: " << endl;
		}
		if(x < 10)
		{
			cout << a[n] <<" "<< b[n] <<endl;
		}
		else
		{
			cout << a[n] <<" "<< b[n] <<endl;
		}
	}
	
}*/

