#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define DANESHJUHA 1000
#define MaX 50

using namespace std;

//*********** LESSON CLASS ***************
class dars
{
protected:
	float gheymat;
	string esm;
	string code;
	int vahed;
public:
	dars();
	dars(string , string ,int , float );
	
	string tostring();
	virtual string noe()
	{
		return "all";
	}

	virtual void print()
	{
		cout << left << setw(15) << code << setw(20) << esm <<setw(10) << "" << setw(8) << vahed << fixed << fixed << setprecision(2) << setw(10) << gheymat << endl;
	}
	int getVahed();
	float getGheymat();
	string getCode();
};
//******** LESSON CLASS FUNCTIONS  *********
dars::dars(){}
dars::dars(string esmeDars, string codeDars,int tedadVahed, float gheymateDars)
	{
		esm = esmeDars;
		code = codeDars;
		gheymat = gheymateDars;
		vahed = tedadVahed;
	}
string dars::tostring()
	{
		return esm;
	}
int dars::getVahed()
	{
		return vahed;
	}
float dars::getGheymat()
	{
		return gheymat;
	}
string dars::getCode()
	{
		return code;
	}

//******** NAZARI CLASS (derived of lesson class)  *********
class nazari:public dars
{
public:
	nazari(string , string , float  ,int );
	
virtual string noe()
	{
		return "nazari";
	}
	void print();
	
};

//******** NAZARI CLASS FUNCTIONS  *********
nazari::nazari(string esmeDars, string codeDars, float gheymateDars ,int tedadVahed)
	{
		esm = esmeDars;
		code = codeDars;
		gheymat = gheymateDars;
		vahed = tedadVahed;
	}
void nazari::print()
	{
		cout << left << setw(15) << code << setw(20) << esm <<setw(10) << "nazari" << setw(8) << vahed << fixed << setprecision(2) << setw(10) << gheymat << endl;
	}

//******** AMALI CLASS (derived of lesson class)  *********
class amali:public dars
{
public:
	amali(string , string , float  ,int );
virtual string noe();
virtual void print();
};
//******** AMALI CLASS FUNCTIONS  *********
amali::amali(string esmeDars, string codeDars, float gheymateDars ,int tedadVahed)
	{
		esm = esmeDars;
		code = codeDars;
		gheymat = gheymateDars;
		vahed = tedadVahed;
	}
string amali::noe()
	{
		return "amali";
	}
	
void amali::print()
	{
		cout << left << setw(15) << code << setw(20) << esm <<setw(10) << "amali" << setw(8) << vahed << fixed << setprecision(2) << setw(10) << gheymat << endl;
	}

//******** BARNAME CLASS  *********
class barname
{
private:
	string darsha[25];//code dars zakhire mishavad
	int top;
	float nomreha[25];

	int findDars(string code)
	{
		for(int i = 0 ; i < top ; i++)
			if(darsha[i] == code)
				return i;
		return -1;
	}
	int findDars(dars *list[], int size, string code)
	{
		for(int i = 0 ; i < size; i++)
			if(list[i]->getCode() == code)
				return i;
		return -1;
	}
public:

	barname()
	{
		top = 0;
		for(int i = 0 ; i < 25 ;nomreha[i++] = -1);
	}
	
	bool ezafeDars(string codeDars)
	{
		if(top == 25)
			return false;
		if(findDars(codeDars) == -1)
			darsha[top++] = codeDars;
		return true;
	}

	bool ezafeNomreh(string code, float nomreh)
	{
		int andis = findDars(code);
		if(andis == -1)
			return false;
		if(nomreh < 0) nomreh = 0;
		if(nomreh > 20) nomreh = 20;
		nomreha[andis] = nomreh;
		return true;
	}

	float moaddel(dars *listDarsha[], int size)
	{
		float majmueNomreh = 0;
		int majmueVahed = 0;
		for(int i = 0 ; i < top ; i++)
		{
			int andis = findDars(listDarsha, size, darsha[i]);
			majmueNomreh += nomreha[i]*listDarsha[andis]->getVahed();
			majmueVahed  += listDarsha[andis]->getVahed();
		}
		return majmueNomreh/majmueVahed;
	}
	float shahriye(dars *listDarsha[], int size)
	{
		float majmueShahriye = 0;
		for(int i = 0 ; i < top ; i++)
		{
			int andis = findDars(listDarsha, size, darsha[i]);
			majmueShahriye  += listDarsha[andis]->getGheymat();
		}
		return majmueShahriye;
	}

	void chaap(dars *listDarsha[], int size)
	{

		cout << left << setw(10) << "code"
				 << setw(15) << "esme dars"
				 << setw(10)  << "noe"
				 << setw(9)  << "vahed"
				 << setw(7) <<  "nomreh" << endl << endl;
		for(int i = 0 ; i < top ; i++)
		{
			
			int andis = findDars(listDarsha, size, darsha[i]);
			cout << left << setw(10) << listDarsha[andis]->getCode()
				 << setw(15) << listDarsha[andis]->tostring()
				 << setw(10)  << listDarsha[andis]->noe()
				 << setw(9)  << listDarsha[andis]->getVahed()
				 << fixed << setprecision(2) << setw(7) << nomreha[i] << endl;
		}

		float Moadel = moaddel(listDarsha, size);
		cout << "\n\n\t\tMoaddel : " << fixed << setprecision(2) << Moadel;
		cout << "\t\tShahriye : "    << fixed << setprecision(2) << shahriye(listDarsha, size) ;
		if(Moadel < 12)
		{
			cout << "\n\t\t\tMASHRUT";
		}
		else if(Moadel < 17)
		{
			cout << "\n\t\t\tGHEYREE MASHRUT";
		}
		else
			cout << "\n\t\t\tMOMTAZ";
	}//end chaap
};
//******** DANESHJU CLASS  *********
class daneshju
{
private:
	barname term;
	string esm;
	string family;
	string pedar;
	string shomare;
	string codeMelli;
public:
	daneshju(string Esm, string Family, string Pedar, string shomareDaneshjui, string CodeMelli)
	{
		esm=Esm; family=Family; pedar=Pedar; shomare=shomareDaneshjui; codeMelli=CodeMelli; 
	}

	string getshomare()
	{
		return shomare;
	}
	string getesm()
	{
		return esm;
	}
	string getfamily()
	{
		return family;
	}
	
	
	void ezafeDars(string code)
	{
		if(!term.ezafeDars(code))
			cout << "\nlist por ast.";
	}

	void ezafeNomreh(string codeDars, float nomreh)
	{
		if(!term.ezafeNomreh(codeDars, nomreh))
			cout << "\nDars ba code " << codeDars << " vojud nadarad.";
	}

	float moaddel(dars *listDarsha[], int size)
	{
		return term.moaddel(listDarsha, size);
	}

	float shahriye(dars *listDarsha[], int size)
	{
		return term.shahriye(listDarsha, size);
	}

	void chaapeBarname(dars *listDarsha[], int size)
	{
		term.chaap(listDarsha, size);
	}

	void chaap()
	{
		cout << left << "esm : " << setw(20) << esm << "   family : " << setw(20) << family << "   Pedar : " << setw(20) << pedar << endl;
		cout << left << "shomare daneshjui : " << setw(10) << shomare << "  shomare melli : " << codeMelli << endl << endl;
	}
};

//******** Global FUNCTIONS  *********

int findDaneshju(daneshju *daneshjuha[], int size, string shomareDaneshjui)
{
	for(int i = 0 ; i < size ; i++)
		if(daneshjuha[i]->getshomare() == shomareDaneshjui)
			return i;
	return -1;
}

int findDars(dars *list[], int size, string code)
{
	for(int i = 0 ; i < size; i++)
		if(list[i]->getCode() == code)
			return i;
	return -1;
}


void header()
{
	//__First Line_________________________________________
	cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187);
	//__Second Line_________________________________________
	cout<<endl<<char(186)<<" IAUCTB University System App "<<char(186)<<endl;
	//__third Line_________________________________________
	cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl;
}

void clrscr()
{
	system("cls");
	header();
}

char menu();

void headerDars()
{
	cout << left << setw(15) << "code" << setw(20) << "esm" <<setw(10) << "noe" << setw(8) << "vahed" << setw(10) << "gheymat" << endl;

}
void headerDaneshju()
{
	cout << left << setw(20) << "Shomare daneshjui" << setw(20) << "esm" <<setw(20) << "family"  << endl;

}

//_________________________________________________
 /////////////////Main Function\\\\\\\\\\\\\\\\\\\\\\

int main()
{	
	//System commands :
	system("color 81");
	system("mode 100,40");

	void logo();
	logo();
    dars *list[MaX];
	int top = 0;
	daneshju *daneshjuha[DANESHJUHA];
	int topSt = 0;
	bool end = false;

	while(!end)
	{
		clrscr();
		char choice = menu();
		switch(choice)
		{
		case 'a'://ezafe dars
			{
				clrscr();
				string code;
				cout << "Lotfan code dars ra vared konid : ";
				cin >> code;
				cin.get();
				if(findDars(list, top, code) != -1)
				{
					cout << "\nin dars mojud ast.";
					break;
				}
				else
				{
					string esm;
					float gheymat;
					int vahed;
					char noe='0';
					cout << "\nEsme dars : " ;
					getline(cin, esm);
					cout << "tedad vahed (use numbers) : ";
					cin >> vahed;
					cout << "gheymat (use numbers) : ";
					cin >> gheymat;
					cout << "noe (1. nazari, 2. amali) [1-2] : ";
					for(noe;noe!=1||noe!=2;)
					{
					    cin  >> noe;
					    if(noe == '1')
					    {
						      list[top++] = new nazari(esm, code, gheymat, vahed);
							  break;
					    }
					    else if(noe == '2')
					    {
						      list[top++] = new amali(esm, code, gheymat, vahed);
							  break;
					    }
					    else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
					        cout << "Adade vared shode na dorost ast.";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE|BACKGROUND_GREEN);
							cout << "\nnoe (1. nazari, 2. amali) [1-2] : ";
						}
					}
	
				}
				break;
			}//end case a
		case 'b'://ezafe daneshju
			{
				clrscr();
				string shomare;
				cout << "Shomare daneshjuyi ra vared konid : ";
				cin >> shomare;
				if(findDaneshju(daneshjuha, topSt, shomare) != -1)
				{
					cout << "\ndaneshju ba in shomare mojud ast\n\n";
					daneshjuha[findDaneshju(daneshjuha, topSt, shomare)]->chaap();
					break;
				}
				else
				{
					string esm, family, meli, pedar;
					cout << "\nEsm : ";
					cin.get();
					getline(cin, esm);
					cout << "Family : ";
					getline(cin, family);
					cout << "Name pedar : ";
					getline(cin, pedar);
					cout << "Code melli : ";
					cin >> meli;
					daneshjuha[topSt++] = new daneshju(esm, family, pedar, shomare, meli);
				}
				break;
			}//end case b
		case 'c'://entekhab vahed
			{
				clrscr();
				string shomare;
				cout << "Shomare daneshjui ra vared konid : ";
				cin >> shomare;
				int andis = findDaneshju(daneshjuha, topSt, shomare);
				if(andis == -1)
				{
					cout << "Daneshju ba in shomare sabt nashode.";
					break;
				}
				else
				{
					clrscr();
					string sd;
					daneshjuha[andis]->chaap();
					cout << endl << endl;;
					cout << "Shomare dars baraye etmam 0 ra vared konid : ";
					cin >> sd;
					while(sd != "0")
					{
						clrscr();
						
						int dd = findDars(list, top, sd);
						if(dd == -1)
							cout << "\nDars ba in shomare mojud nist. \n";
						else
						{
							daneshjuha[andis]->ezafeDars(sd);
						}
						daneshjuha[andis]->chaapeBarname(list, top);
						cout << endl << endl;
						cout << "Shomare dars baraye etmam 0 ra vared konid : ";
						cin >> sd;
					}//end while
					break;
				}
			}//end case c

		case 'd'://liste darsha
			{
				clrscr();
				headerDars();
				cout << endl;
				for(int i = 0 ; i < top ; i++)
					list[i]->print();
				break;
			}//end case d

		case 'e':
			{
				clrscr();
				headerDaneshju();
				for(int i = 0 ; i < topSt; i++)
					cout << left << setw(20) << daneshjuha[i]->getshomare() << setw(20) << daneshjuha[i]->getesm() <<setw(20) << daneshjuha[i]->getfamily()  << endl;
				break;
			}//end case e

		case 'f'://sabte nomreha
			{
				clrscr();
				string shomare, code;
				float nomreh;
				cout << "Shomare daneshjui ra vared konid : ";
				cin >> shomare;
				int andis = findDaneshju(daneshjuha, topSt, shomare);
				if(andis == -1)
				{
					cout << "Daneshju ba in shomare sabt nashode.";
					break;
				}
				else
				{
					clrscr();
					daneshjuha[andis]->chaapeBarname(list, top);
					cout << endl << endl;;
					cout << "Shomare dars baraye etmam 0 ra vared konid : ";
					cin >> code;
					while(code != "0")
					{
						
						int dd = findDars(list, top, code);
						if(dd == -1)
						{
							cout << "\nDars ba in shomare mojud nist. \n";
							_getch();//getch(); MSDN warning
						}
						else
						{
							cout << "\nNomreh ra vared konid : ";
							cin >>  nomreh;
							daneshjuha[andis]->ezafeNomreh(code, nomreh);
						}
						clrscr();
						daneshjuha[andis]->chaapeBarname(list, top);
						cout << endl << endl;
						cout << "Shomare dars baraye etmam 0 ra vared konid : ";
						cin >> code;
					}//end while
					break;
				}
			}//end case f

		case 'g'://karnaameh
			{
				clrscr();
				string shomare;
				cout << "Shomare daneshjuyi ra vared konid : ";
				cin >> shomare;
				int andis = findDaneshju(daneshjuha, topSt, shomare);
				if(andis == -1)
				{
					cout << "Daneshju ba in shomare sabt nashode. ";
					break;
				}
				else
				{
					clrscr();
					daneshjuha[andis]->chaapeBarname(list, top);
				}
				break;
			}//end case g

		case 'h' :
			{
				end = true;
				break;
			}

		}//end switch

			cout << "\n\n\t\t\t";
			system("pause");
	}//end while
	
	return 0;
}

//_________________________________________________
 /////////////////Local Functions\\\\\\\\\\\\\\\\\\\


void logo()
{

cout<<"\n\n\n\n";	
cout<<"\t\t\t   @@@@    @@@    @@     @@  @@@@@@  @@@@@@@@ @@@@@@@@"<<endl;Sleep(500);system("color 2B");
cout<<"\t\t\t    @@    @@ @@   @@     @@ @@    @@    @@    @@     @@"<<endl  ;Sleep(500);system("color 3C");
cout<<"\t\t\t    @@   @@   @@  @@     @@ @@          @@    @@     @@"<<endl  ;Sleep(500);system("color 4D");
cout<<"\t\t\t    @@  @@     @@ @@     @@ @@          @@    @@@@@@@@"<<endl   ;Sleep(500);system("color 5E");
cout<<"\t\t\t    @@  @@@@@@@@@ @@     @@ @@          @@    @@     @@"<<endl  ;Sleep(500);system("color 6F");
cout<<"\t\t\t    @@  @@     @@ @@     @@ @@    @@    @@    @@     @@ "<<endl ;Sleep(500);system("color B2");
cout<<"\t\t\t   @@@@ @@     @@  @@@@@@@   @@@@@@     @@    @@@@@@@@ "<<endl<<endl  ;Sleep(500);system("color 3C");
cout<<"\t\t\t       All rights reserved for Creator (C) May 2012"<<endl<<endl;Sleep(500);system("color 2F");
cout<<"\t\t\t \t            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	cout<<" Moein Iranshahi "<<endl;
	Sleep(4000);

}
//----------------------------------------------------------------------------------
char menu()
{
	system("color 81");
	char choice = '0';
	do
	{
		clrscr();
		cout << "A. Ezafe kardane dars\n"
			 << "B. Ezafe kardane daneshju\n"
			 << "C. Entekhab vahed\n"
			 << "D. Namayesh Doroos\n"
			 << "E. Namayeshe Daneshjuyan\n"
			 << "F. Sabte nomaraat\n"
			 << "G. karname\n"
			 << "H. Khorooj\n\n"
			 << "Yeki az gozine haye bala ra Entekhab konid   (A-H) : ";
		choice=_getch();
		
	}while(choice < 'a' || choice > 'h');
	return choice;
}
