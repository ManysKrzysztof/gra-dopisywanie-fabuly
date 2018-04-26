#include <iostream>

using namespace std;

struct Player
{
    string nazwa = "Wojownik";
    int hp = 100;
    int lvl = 1;
    int strength = 0;
    int vitality = 0;
    int agility = 0;
    int morals = 0;
    int hit() {
       return 10;
    }
};
struct Enemy
{
    string nazwa = "Chrzaszcz";
    int hp = 50;
    int lvl = 1;
    int strength = 0;
    int vitality = 0;
    int agility = 0;
    int morals = 0;
    int hit() {
       return 5;
    }
};
void start();
void fill_stats(short choice);
bool fight(Player player, Enemy enemy);
Player gracz;
Enemy potwor;

int main()
{
    start();
    return 0;
}

void start() {
    short profession;
    cout << "Jako mlodzieniaszek oposciles rodzinny dom i udales sie w podroz. \nSzukajac przygod i bogacta wedrowales kilka lat." << endl;
    cout << "Jednak pewnego dnia na szlaku zostales napadniety. \nNie bez strat i ran, udalo ci sie umknac napastnikom." << endl;
    cout << "Co sil popedziles do najblizszego miasta. \nW ten sposob znalazles sie w Ezrac." << endl;
    cout << "Po wejsciu do pierwszej napotkanej gospody szukajac odpoczynku.\nOberzysta przywolal cie do siebie skinieniem glowy." << endl;
    cout << "-Kim jestes i co tutaj robisz? Odpowiadaj albo wyrzuce cie na bruk!" << endl;
    cout << "1.Jestem Lowca nagrod,przywedrowalem tutaj za praca, z polnocy ,dokladniej z Pirnu." << endl;
    cout << "2.Jestem Maratonczykiem,Pochodze z Teinn. " << endl;
   cout<< "~Wybierz Swoja Historie~"<<endl;
   cin>>profession;
    fill_stats(profession);
    cout << fight(gracz, potwor);

}

void fill_stats(short choice) {
    switch(choice){
            case 1:gracz.strength=1;cout<<"Wybrales Wojowinika\n";break;
            case 2:gracz.agility=1;cout<<"Wybrales Maratonczyka\n";break;

}
cout<<"Zostalem napadniety na szlaku!\nNie masz pomyslu jak moge zarobic troche pieniedzy na utrzymanie?\n";
cout<<"Oberzysta patrzy na ciebie i po chwili milczenia mowi.\n-Zalegly mi sie chrzaszcze w piwnicy.\n";
cout<<"Patrzysz na mezczyzne z obrzydzeniem i zazenowaniem.\n-Czemu sam sie ich nie pozbedziesz?!\n";
cout<<"Karczmarz patrzy na ciebie jak na debila i wzdycha.\nIch lajno wydziela trujacy gaz, a mi szkoda zdrowia.\nTo co? Idziesz, czy mam cie wyprowadzic.\n";
cout<<"Nie bez oporow zdajesz sobie sprawe ze nie masz innej opcj.\n-Dobra! dobra.Pojde, Pokaz mi gdzie jest ta piwnica.\n";
}

bool fight(Player player, Enemy enemy){
    while(player.hp > 0 && enemy.hp > 0) {
        int action = 0;
        player.hp -= enemy.hit();
        if (player.hp <= 0) return false;
        cout << "hp: " << player.hp << endl;
        cout << "hp wroga: " << enemy.hp << endl;
        cout << "co robisz?\n1. Atakuj \n2. Blok\n" << endl;
        cin >> action;
        if(action == 1) enemy.hp -= player.hit();
        if(action == 2) {
            player.hp += 10;
            if (player.hp > 100) player.hp = 100;
        }
    }
    if (player.hp > 0) return true;
    else return false;
}
