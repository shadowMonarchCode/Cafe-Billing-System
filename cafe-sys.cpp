#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class Cafe{
	
	pair <int, int> tea;
	pair <int, int> coffee;
    pair <int, int> sandwiches;
	pair <int, int> pastries;
	pair <int, int> muffins;
	pair <int, int> cake;
	pair <int, int> pizza;

public:

	float total_price, total_amt, tax, discount;
	char name[80];
	string number;
	
	Cafe(){
		
		tea.second=0;
		coffee.second=0;
    	sandwiches.second=0;
    	pastries.second=0;
    	muffins.second=0;
        cake.second=0;
        pizza.second=0;
	}
    
    Cafe(int teaPrice, int coffeePrice, int sandwichesPrice, int pastriesPrice, int muffinsPrice, int cakePrice, int pizzaPrice){
        
        tea.first=teaPrice;
        coffee.first=coffeePrice; 
        sandwiches.first=sandwichesPrice;
        pastries.first=pastriesPrice;
        muffins.first=muffinsPrice;
        cake.first=cakePrice;
        pizza.first=pizzaPrice;
    }
	
	void Item_List();
	void inputQuantity();
	void Reciept();
	
	int buyTea(int q){
        tea.second+=q;
        return tea.second;     
    }
    int buyCoffee(int q){
        coffee.second+=q;
        return coffee.second;     
    }
	int buySandwiches(int q){
        sandwiches.second+=q;
        return sandwiches.second;     
    }
	int buyPastries(int q){
		pastries.second+=q;
        return pastries.second;     
    }
    int buyMuffins(int q){
    	muffins.second+=q;
        return muffins.second;     
    }
    int buyCake(int q){
        cake.second+=q;
        return cake.second;        
    }
    int buyPizza(int q){
        pizza.second+=q;
        return pizza.second;     
    }
	
};

void Main_Menu();
void Exit();
void History();

void Intro(){
	
	system("cls");
	cout<<endl<<endl;
    cout<<"\t          ____        ____  ____   _____   ____"<<endl;
    cout<<"\t |  |  | |     |     |     |    | |  |  | |    "<<endl;
    cout<<"\t |  |  | |____ |     |     |    | |  |  | |____"<<endl;
    cout<<"\t |  |  | |     |     |     |    | |  |  | |    "<<endl;
    cout<<"\t |__|__| |____ |____ |____ |____| |  |  | |____"<<endl<<endl<<endl;
    cout<<" __________________________________________________________________"<<endl<<endl;
    cout<<"\t\t  THIS IS CAFE BILLING SYSTEM"<<endl;
    cout<<" __________________________________________________________________"<<endl;
    
    system("pause");
    
}

void Start(){
	
	int choice;
	
	do{
		system("cls");    
		cout<<"====================CAFE BILLING SYSTEM===================="<<endl<<endl<<endl;
		cout<<"\t1. MAIN MENU"<<endl<<endl;
		cout<<"\t2. EXIT"<<endl<<endl;
	
		cout<<"ENTER YOUR CHOICE :  ";
		cin>>choice;
	   
		switch(choice){
			case 1:{
		    	Main_Menu();
		    	break;
			}
			case 2:{
				Exit();
				break;
			}    
		}
	
	}while(choice>3);
	
}

void Main_Menu(){
	int choice;
	Cafe ob(25, 40, 50, 70, 45, 150, 210);


	do{
	system("cls");
	
	cout<<"\t==================MAIN MENU==================="<<endl<<endl;
	cout<<"\t1. Do you want to purchase an item?"<<endl;
    cout<<"\t2. Do you want to view transacion history?"<<endl;
    cout<<"_________________________________________________________"<<endl<<endl;
    cout<<"\t  Enter your choice [1-2]: ";
    cin>>choice;
	
		switch(choice){
			case 1:
			{
				ob.Item_List();
				ob.inputQuantity();
				break;
			}
			case 2:
			{
				History();
				break;
			}
		}
	}while(choice>3);
}

void Cafe::Item_List(){
	
	system("cls");
	
	cout<<"\tItem list:"<<endl<<endl;
    cout<<"\t1. Tea         - Rs."<<tea.first<<endl;
    cout<<"\t2. Coffee      - Rs."<<coffee.first<<endl;
    cout<<"\t3. Sandwiches  - Rs."<<sandwiches.first<<endl;
    cout<<"\t4. Pastries    - Rs."<<pastries.first<<endl;
    cout<<"\t5. Muffins     - Rs."<<muffins.first<<endl;
    cout<<"\t6. Cake        - Rs."<<cake.first<<endl;
    cout<<"\t7. Pizza       - Rs."<<pizza.first<<endl;
    cout<<"_____________________________________________"<<endl<<endl;
        
}

void Cafe::inputQuantity(){

    int item_no, quantity[7], answer;    

    for (int i=1; i<=10;i++){
        cout<<"\tEnter item number: ";
        cin>>item_no;
        cout<<"\tEnter quantity: ";
        
       switch (item_no){
			case 1:{
	            cin>>quantity[1];
	            buyTea(quantity[1]); 
	            break;
	        }
	        case 2:{
	            cin>>quantity[2];
	            buyCoffee(quantity[2]);
	            break;
	        }
	        case 3:{
				cin>>quantity[3];
	            buySandwiches(quantity[3]);
	            break;
	        }
	        case 4:{
				cin>>quantity[4];
	            buyPastries(quantity[4]);
	            break;
	        }
	        case 5:{
	            cin>>quantity[5];
	            buyMuffins(quantity[5]);
	            break;
	        }
	        case 6:{
	            cin>>quantity[6];
	            buyCake(quantity[6]);
	            break;
	        }
	        case 7:{
	            cin>>quantity[7];
	            buyPizza(quantity[7]);
	            break;
	        }
	        default:{
				cout<<"\t\t[ERROR] INVALID INPUT!"<<endl;
	            break;
			}
		}
	cout<<"_______________________________________________"<<endl;
	cout<<"\tDo you want to buy more?[0/1]   ";
    cin>>answer;
   	cout<<"_______________________________________________"<<endl;

    if(answer==0)
        break;
    else
        continue;
	}

	Reciept();

}

void Cafe::Reciept(){
	
	system("cls");
    Cafe c;
    ofstream outfile;
    outfile.open("Reciept.txt",ios::app|ios::binary);
    if(outfile.fail()){
        cout<<"[ERROR] THE FILE COULD NOT BE OPEN!!"<<endl;
        system("pause");
    }   
	
	cout<<"\t Enter costumer's name: ";
	cin.ignore();
	cin.getline(c.name,80);
	cout<<"\t Enter costumer's number: ";
	cin>>c.number;

	int disc_amt=5;

	c.total_price=((tea.first*tea.second)+(coffee.first*coffee.second)+(sandwiches.first*sandwiches.second)+(pastries.first*pastries.second)+(muffins.first*muffins.second)+(cake.first*cake.second)+(pizza.first*pizza.second));
	c.tax=(c.total_price*5)/100;
	c.discount=(c.total_price - c.tax)*disc_amt/100;
	c.total_amt=c.total_price-c.discount;
	
	cout<<"==================RECIEPT=================="<<endl<<endl;
	cout<<"\t   ITEM         COST"<<endl;
	cout<<"______________________________________________"<<endl<<endl;
	cout<<"\t1. Tea          "<<tea.first*tea.second<<endl;
	cout<<"\t2. Coffee       "<<coffee.first*coffee.second<<endl;
	cout<<"\t3. Sandwiches   "<<sandwiches.first*sandwiches.second<<endl;
	cout<<"\t4. Pastries     "<<pastries.first*pastries.second<<endl;
	cout<<"\t5. Muffins      "<<muffins.first*muffins.second<<endl;
	cout<<"\t6. Cake         "<<cake.first*cake.second<<endl;
	cout<<"\t7. Pizza        "<<pizza.first*pizza.second<<endl;
	cout<<"______________________________________________"<<endl<<endl;
	cout<<"\t  TOTAL PRICE   "<<c.total_price<<endl;
	cout<<"\t  TAX           "<<c.tax<<endl;
	cout<<"\t  DISCOUNT[5%]  "<<c.discount<<endl;
	cout<<"\t  TOTAL AMOUNT  "<<c.total_amt<<endl<<endl<<endl;
	
	system("pause");
	system("cls");
	int choice;
	cout<<endl<<endl<<"\tPayment Methods"<<endl;
	cout<<"______________________________________________"<<endl<<endl;
	cout<<"\t1. CASH"<<endl;
	cout<<"\t2. CARD"<<endl;
	cout<<"\t3. PAYTM"<<endl;
	cout<<"______________________________________________"<<endl<<endl;
	cout<<"\tSelect a method for payment: ";
	cin>>choice;
	switch(choice){
		case 1:{
			cout<<"\tPayment of "<<c.total_amt<<" via Cash has been successfully done"<<endl;
			break;
		}
		case 2:{
			cout<<"\tPayment of "<<c.total_amt<<" via Card has been successfully done"<<endl;
			break;
		}
		case 3:{
			cout<<"\tPayment of "<<c.total_amt<<" via Paytm has been successfully done"<<endl;
			break;
		}
	}
	 
	outfile.write(reinterpret_cast<char*>(&c),sizeof(Cafe));
	outfile.close();
    cout<<endl<<endl<<endl;
	system("pause");
	
}

void History(){
	
	system("cls");
    Cafe c;
    ifstream infile;
    bool check=false;
    infile.open("Reciept.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"[ERROR] CONTACT LIST CAN NOT BE OPENED!!";
        system("pause");
    }
    
    cout<<"\t\tRECENT COSTUMERS"<<endl;
    cout<<"_____________________________________________________"<<endl;
    while(infile.read(reinterpret_cast<char*>(&c),sizeof(Cafe)))
    {
        cout<<"\tCostumer Name: "<<c.name<<endl<<endl;
        cout<<"\tCostumer Phone Number: "<<c.number<<endl<<endl;
        cout<<"\tDiscount Given: 5%"<<endl;
		cout<<"\tTotal Amount: "<<c.total_amt<<endl;
    	cout<<"_____________________________________________________"<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t[EMPTY] NO RECORD FOUND..."<<endl<<endl;
    system("pause");
	
	Start();
	
}

void Exit(){
	system("cls");
	cout<<endl<<endl<<"\tTHANK YOU FOR USING THIS SOFTWARE"<<endl<<endl<<endl;
	cout<<"\tProject:- CAFE BILLING SYSTEM"<<endl;
	cout<<"\tGROUP MEMBERS:"<<endl<<endl;
	cout<<"\t     NAME                    Rollno."<<endl;
	cout<<"\t1. RISHABH PRAKASH         2K19/SE/098"<<endl;
	cout<<"\t2. RIYA ARORA              2K19/SE/100"<<endl;
		
}

int main(){

	Intro();
	Start();
	
	return 0;
}
