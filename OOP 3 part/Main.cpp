#include <iostream>


class Kassa {
private:
	int money;				//деньги в кассе 
	
public:
    Kassa():money(0) {};	//заполняем значение money 0;

	int CurrentMoney() {
		return money;
	}
	void cash_in(int newNum_in) {
		money += newNum_in;
	}
		

	void cash_back(int newNum_back){
		if (newNum_back > money) {
			std::cerr << "Денег не достаточно\n";
			return;			// останваливает функцию
		}

		money = money - newNum_back;
		
	}

	int exchange(int newNum_in,int price) {

		if (price > newNum_in) {
			std::cerr << "Денег не достаточно для оплаты\n";
			return newNum_in;
		}
		if (money < newNum_in - price) {
			std::cerr << "Денег не достаточно для сдачи\n";
			return newNum_in;
		}
		money += price;
		return newNum_in - price;
	}
};
		
		 

int main() {

	setlocale(LC_ALL, "ru");
	Kassa var1;
	Kassa var2;
	


	var1.cash_in(1000);
	std::cout << "Первая касса имеет -> " << var1.CurrentMoney() << '\n';
	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << "\n\n";


	var1.cash_back(2000);
	std::cout << "Первая касса имеет -> " << var1.CurrentMoney() << '\n';
	var1.cash_back(200);
	std::cout << "Первая касса имеет -> " << var1.CurrentMoney() << '\n';
	var2.cash_back(10);
	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	var2.cash_back(0);
	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	


	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	int change = 0;
	change = var2.exchange(20, 100);
	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	std::cout << "Сдача-> " << change << "\n\n";

	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	change = var2.exchange(120, 100);
	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	std::cout << "Сдача-> " << change << "\n\n";

	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	change = var2.exchange(100, 100);
	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	std::cout << "Сдача-> " << change << "\n\n";

	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	change = var2.exchange(100, 80);
	std::cout << "Вторая касса имеет -> " << var2.CurrentMoney() << '\n';
	std::cout << "Сдача-> " << change << "\n\n";



	return 0;

}





	
