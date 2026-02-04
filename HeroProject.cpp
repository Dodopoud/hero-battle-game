#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

#define H 4
#define P 4
using namespace std;

class Hero{
	private:
		string name;
		int kick;
		int life;
	public:
		void set_name(string n){
			name=n;
		}
		void set_kick(int x){
			kick=x;
		}
		
		void set_life(int z){
			life=z;
		}
		
		string get_name(){
			return name;
		}
		int get_kick(){
			return kick;
		}
		
		int get_life(){
			return life;
		}
		
		Hero(string  n, int k, int l){
		  name=n;
	  	  kick=k;
	  	  life=l;
	  }
};
class Pet{
	private:
		string petName;
		int petLife;
		int petDefence;
	public:
		void set_petName(string n){
			petName=n;
		}
		void set_petDefence(int y){
			petDefence=y;
		}
		void set_petLife(int l){
			petLife=l;
		}
		int get_petDefence(){
			return petDefence;
		}
		string get_petName(){
			return petName;
		}
		int get_petLife(){
			return petLife;
		}
		Pet (string n, int l, int d){
			petName=n;
			petLife=l;
			petDefence=d;
		}
};

void displayWelcome();
void displayHeroes(Hero allHeroes[]);
void displayPets(Pet allPets[]);
int chooseHero();
int choosePet();
void myPlayerDisplay(Hero myPlayer);
void myPetPlayerDisplay(Pet myPetPlayer);
void yourPlayerDisplay(Hero yourPlayer);
void yourPetPlayerDisplay(Pet yourPetPlayer);
void battle(Hero& myPlayer, Hero& yourPlayer, Pet& myPetPlayer, Pet& yourPetPlayer);
void winner(Hero& myPlayer, Hero& yourPlayer);

int main(){
	//HEROES CREATION
	Hero h1("Ashe",15,  85);
	Hero h2("Caitlyn",18, 80);
	Hero h3("Fiora",16,90);
	Hero h4("Katarina",20,75); 
	Hero allHeroes[] = {h1,h2,h3,h4};
	
	//PETS CREATION
	Pet p1("Wolf", 30, 40 );
	Pet p2("Dragon", 28, 35);
	Pet p3("Fox", 25, 33);
	Pet p4("Bear", 32, 38);
	Pet allPets[]={p1,p2,p3,p4};
	
	//WELCOME TO THE GAME
	displayWelcome();
	
	//DISPLAY OF ALL HEROES
	displayHeroes(allHeroes);

	//DISPLAY OF ALL PETS
	displayPets(allPets);

	//CHOICE OF HEROES
	int myHero=chooseHero();
	int yourHero=chooseHero();
	if (myHero == yourHero){
			cout<<"You can't choose the same hero! Choose again your hero: "<<endl;
			yourHero=chooseHero();
		}

	Hero myPlayer = allHeroes[myHero-1]; 
	Hero yourPlayer = allHeroes[yourHero-1];
	
	//CHOICE OF PETS
	int myPet=choosePet();
	int yourPet=choosePet();
	if(myPet == yourPet){
			cout<<"You can't choose the same pet! Choose again your pet: "<<endl;
			yourPet=choosePet();
		}
	
	
	Pet myPetPlayer = allPets[myPet-1];
	Pet yourPetPlayer = allPets[yourPet-1];
	
	//MY HERO DISPLAY
	myPlayerDisplay(myPlayer);
	
	//MY PET DISPLAY
	myPetPlayerDisplay(myPetPlayer);
	
	//YOUR HERO DISPLAY
	yourPlayerDisplay(yourPlayer);
	
	//YOUR PET DISPLAY
	yourPetPlayerDisplay(yourPetPlayer);

	//BATTLE ROUNDS
	battle(myPlayer,yourPlayer, myPetPlayer, yourPetPlayer);

	//WINNER ANNOUNCEMENT
	winner(myPlayer, yourPlayer);
	
	return 0;
}

void displayWelcome(){
	cout<<setw(70)<<"==========================";
	cout<<setw(68)<<endl<<"WELCOME TO THE GAME"<<endl;
	cout<<setw(70)<<"=========================="<<endl<<endl;
	cout<<setw(70)<<"--------------------------"<<endl<<endl<<endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void displayHeroes(Hero allHeroes[]){
	cout<<setw(68)<<"======= HEROES ======="<<endl<<endl<<endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for(int i=0; i<H; i++){
        cout << i+1<<". " << allHeroes[i].get_name()<<endl<<"   Kick: " << allHeroes[i].get_kick()<<
		" | Life: " << allHeroes[i].get_life() <<endl<<endl<<"---------------------------------------"<<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		};
		
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void displayPets(Pet allPets[]){
	cout<<setw(68)<<"======= PETS ======="<<endl<<endl<<endl;
	for (int i=0; i<P;i++){
		cout<< i+1<<". "<<allPets[i].get_petName()<<endl<<" Defence: " << allPets[i].get_petDefence()<<" | Life: " <<allPets[i].get_petLife()<<endl<<endl<<"---------------------------------------"<<endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(500));

	};
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int chooseHero(){
	int choice;
	do{
		cout<<">>> Choose your Hero: ";
		cin>>choice; 
		if (choice < 1 || choice > 4)
			cout<<"Invalid hero selection. Try again!"<<endl;
	}while(choice < 1 || choice > 4);
	return choice;
}

int choosePet(){
	int choice;
	do
	{
		cout<<">>> Choose your Pet: ";
		cin>>choice;
		if (choice < 1 || choice > 4)
			cout<<"Invalid pet selection. Try again!"<<endl;
	} while (choice < 1 || choice >  4);
	return choice;
	
}

void myPlayerDisplay(Hero myPlayer){
	cout<<endl<<setw(15)<<"-------- MY HERO: --------"<<endl;
	cout<<"+-------------------------+"<<endl<<"|"<<setw(14)<<myPlayer.get_name()<<setw(12)<<"|"<<endl;
	cout<<"+-------------------------+"<<endl;
	cout<<"|"<<setw(14)<<"Kick: "<<myPlayer.get_kick()<<setw(10)<<"|"<<endl;
	cout<<"|"<<setw(14)<<"Life: "<<myPlayer.get_life()<<setw(10)<<"|"<<endl;
	cout<<"+-------------------------+"<<endl;
}

void myPetPlayerDisplay(Pet myPetPlayer){
	cout<<"Pet: "<<endl<<myPetPlayer.get_petName()<<endl<<"Life: "<<myPetPlayer.get_petLife()<<
		endl<<"Defence: "<<myPetPlayer.get_petDefence()<<endl;
}

void yourPlayerDisplay(Hero yourPlayer){
	cout<<endl<<setw(15)<<"-------- YOUR HERO: -------"<<endl;
	cout<<"+-------------------------+"<<endl<<"|"<<setw(14)<<yourPlayer.get_name()<<setw(12)<<"|"<<endl;
	cout<<"+-------------------------+"<<endl;
	cout<<"|"<<setw(14)<<"Kick: "<<yourPlayer.get_kick()<<setw(10)<<"|"<<endl;
	cout<<"|"<<setw(14)<<"Life: "<<yourPlayer.get_life()<<setw(10)<<"|"<<endl;
	cout<<"+-------------------------+"<<endl<<endl;
}

void yourPetPlayerDisplay(Pet yourPetPlayer){
	cout<<"Pet: "<<endl<<yourPetPlayer.get_petName()<<endl<<"Life: "<<yourPetPlayer.get_petLife()<<
		endl<<"Defence: "<<yourPetPlayer.get_petDefence()<<endl<<endl;

	cout<<"--------------------------"<<endl;
	
}

void battle(Hero& myPlayer, Hero& yourPlayer, Pet& myPetPlayer, Pet& yourPetPlayer){
	//BATTLE START
	cout<<"Press ENTER to start the battle.."<<endl; // press any key to start the battle
	cin.ignore();
	cin.get();
	cout<<endl<<endl<<setw(75)<<"====== BATTLE ======"<<endl;
	
	int myPlayerMaxLife = myPlayer.get_life();
	int yourPlayerMaxLife = yourPlayer.get_life();
	int myPetMaxLife = myPetPlayer.get_petLife();
	int yourPetMaxLife = yourPetPlayer.get_petLife();

	//BATTLE ROUNDS
	
	int counter=1;
	do{
		cout<<endl<<setw(58)<<"ROUND "<<counter<<endl<<endl;
		cout<<"----------------"<<endl<<endl;                                   
		
		//MY HERO ATTACKS YOUR HERO
		cout<<myPlayer.get_name()<<" attacks "<<yourPlayer.get_name()<<endl;
		
		//IF YOUR PET IS STILL ALIVE
		if (yourPetPlayer.get_petLife() > 0){ 
			float petDamage = myPlayer.get_kick() * (yourPetPlayer.get_petDefence() / 100.0);
			float heroDamage = myPlayer.get_kick() * ((100 - yourPetPlayer.get_petDefence()) / 100.0);
			yourPetPlayer.set_petLife(yourPetPlayer.get_petLife() - petDamage);
			yourPlayer.set_life((yourPlayer.get_life() - heroDamage));
		}
		//IF YOUR PET HAS DIED
		else{
			yourPlayer.set_life(yourPlayer.get_life() - myPlayer.get_kick());
		}
		//SET YOUR PET LIFE TO 0 
		if (yourPetPlayer.get_petLife() < 0) {
   			 yourPetPlayer.set_petLife(0);
   			 cout<<yourPetPlayer.get_petName()<<" died."<<endl;
			}
		//SET YOUR HERO LIFE TO 0
		if (yourPlayer.get_life() <= 0) {
   			yourPlayer.set_life(0);
   			cout<<yourPlayer.get_name()<<" died."<<endl;
   			break;
		}
	
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		
		//YOUR HERO ATTACKS MY HERO
		cout<<yourPlayer.get_name()<<" attacks "<<myPlayer.get_name()<<endl;
		
		//IF MY PET IS STILL ALIVE
		if (myPetPlayer.get_petLife() > 0){
			float petDamage = yourPlayer.get_kick() * (myPetPlayer.get_petDefence() / 100.0);
			float heroDamage = yourPlayer.get_kick() * ((100 - myPetPlayer.get_petDefence()) / 100.0);
			myPetPlayer.set_petLife(myPetPlayer.get_petLife() - petDamage);
			myPlayer.set_life((myPlayer.get_life() - heroDamage));
			
		}
		//IF MY PET HAS DIED
		else{
			myPlayer.set_life(myPlayer.get_life() - yourPlayer.get_kick());
		}
		//SET MY PET LIFE TO 0 
		if (myPetPlayer.get_petLife() < 0) {
   			 myPetPlayer.set_petLife(0);
   			 cout<<myPetPlayer.get_petName()<<" died."<<endl;
			}
		//SET MY HERO LIFE TO 0 
		if (myPlayer.get_life() < 0) {
  		  	myPlayer.set_life(0);
  		  	cout<<myPlayer.get_name()<<" died."<<endl;
  		  	break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		
		//HERO AND PET LIFE DISPLAY(CURRENT LIFE / MAXIMUM LIFE)
		cout<<myPlayer.get_name()<<" life: "<<myPlayer.get_life()<< " / " <<myPlayerMaxLife<<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		cout<<yourPlayer.get_name()<<" life: "<<yourPlayer.get_life()<< " / "<<yourPlayerMaxLife<<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		
		cout<<myPetPlayer.get_petName()<<" life: "<<myPetPlayer.get_petLife()<< " / "<<myPetMaxLife<<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		cout<<yourPetPlayer.get_petName()<<" life: "<<yourPetPlayer.get_petLife()<< " / "<<yourPetMaxLife<<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		counter++;
	}while(myPlayer.get_life() > 0 && yourPlayer.get_life() > 0);
}

void winner(Hero& myPlayer, Hero& yourPlayer){
	if (myPlayer.get_life() > 0)
		cout<<endl<<endl<<myPlayer.get_name()<<" is the winner!";
	else if (yourPlayer.get_life() > 0)
		cout<<endl<<endl<<yourPlayer.get_name()<<" is the winner!";
	
	cout<<endl<<endl<<setw(68)<<"====== GAME OVER ======"<<endl;
}

