#include "gra.hpp"

extern bool KoniecGry;
extern int tab_plansza[17][17];
extern postac gracz;
extern int inp;

int main() {
	initscr();
	noecho();
	setup ();
	int menu=menu_input();
	while(!KoniecGry)
	{
		draw(tab_plansza);
		mvprintw(38,5,"ZYCIE %d  \t   SILA %d \tMOC %d  \tZLOTO %d \tKLUCZ %d",gracz.hp, gracz.sila, gracz.moc,gracz.zloto, gracz.klucz);
		mvprintw(48,2,"numer menu=%d, numer inp=%d, pozycja gracza: x=%d,y=%d ", menu, inp, gracz.x, gracz.y);
		mvprintw(49,2,"pozycja gracza: x=%d,y=%d, numer z tab_plansza%d ", gracz.x, gracz.y, tab_plansza[gracz.x-1][gracz.y-1]);
		mvprintw(50,2,"gracz.expm: %d, gracz.exps: %d ", gracz.expm, gracz.exps);
		inp=input();
		czyszczenie();
		refresh();
		if (menu !=0)
		{
			switch (menu)
			{
				case 1:
					setup();
					menu=0;
					break;
				case 2:
					zapisz();
					menu=0;
					break;
				case 3:
					wczytaj();
					menu=0;
					break;
				case 4:
					KoniecGry=true;
					break;
			}
		}
		interakcja(gracz, inp, tab_plansza);
		if(inp==8)
			KoniecGry=true;
		if(inp==7)	
			menu=menu_input();
		if (gracz.hp<=0)
		{
			KoniecGry=true;
			koniec();
		}
	}

	endwin();
	return 0;
}
