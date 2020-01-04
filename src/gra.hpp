#ifndef GRA_HPP
#define GRA_HPP
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <unistd.h>

struct okno{
		int kolumny,wiersze,x,y;
		okno()
		{
			kolumny = 6;
			wiersze = 70;
			x=39;
			y=4;
		}
		okno (int k,int w, int cx, int cy)
		{
			kolumny = k;
			wiersze = w;
			x=cx;
			y=cy;		
		}
};

struct postac {
		int hp, sila, moc, exps, expm, pokonani, zloto, x, y, klucz, poziom;
		bool smierc;
	postac()
		{
		hp = 20;
		sila = 10;
		moc = 10;
		exps = expm = pokonani = zloto = klucz = poziom = 0;
		x = y = 2;
		smierc=false;
		}
	void zerowanie()
	{
		hp = 20;
		sila = 10;
		moc = 10;
		exps = expm = pokonani = zloto = klucz = poziom =0;
		x = y = 2;
		smierc=false;
	}
};

struct mag {
	int hp;
	int moc;
	bool smierc;
	mag ()
	{
		hp = 8;
		moc = 7;
		smierc=false;
	}
	mag (int h, int m, bool sm)
	{
		hp = h;
		moc = m;
		smierc = sm;
	}
	void poziom(int poziom)
	{
		hp += poziom*2;
		moc += poziom;
	}
	~mag()
	{}
};

struct woj {
	int hp;
	int sila;
	bool smierc;
	woj()
	{
		hp = 12;
		sila = 8;
		smierc=false;
	}
	woj (int h, int s, bool sm)
	{
		hp = h;
		sila = s;
		smierc = sm;
	}
	void poziom(int poziom)
	{
		hp += poziom*2;
		sila += poziom;
	}
	~woj()
	{}
};

struct str {
	int hp;
	int atak;
	bool smierc;
	str()
	{
		hp = 16;
		atak = 16;
		smierc=false;
	}
	str(int h, int a, bool sm)
	{
		hp = h;
		atak = a;
		smierc = sm;
	}
	void poziom(int poziom)
	{
		hp += poziom*2;
		atak += poziom;
	}
	~str()
	{}
};

void setup();
void draw(int [17][17]);
void czyszczenie();
int input();
int kosc(int);
void interakcja(postac &, int,int [17][17]);
int czy_mozna(postac &);
int mwalka(postac &);
int wwalka(postac &);
int swalka(postac &);
int walka(int, int);
int drzwi(postac &);
void las(postac &);
void gory(postac &);
void kufer(postac &);
int menu_input();
void wczytaj_mape();
void koniec();
void zapisz();
void wczytaj();
void sklep();
int sklep_menu();



#endif
