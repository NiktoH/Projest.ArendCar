#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

static int a = 0;

class description {
	char cars[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
	void install();
	void allotment();
	void empty();
	void show();
	void avail();
	void posit(int i);
	
}
car[10];
void vline(char c)
{
	for (int i = 80; i > 0; i--)
		std::cout << c;
}
void description::install() {
	std::cout << "Enter car name: ";
	std::cin >> car[a].cars;
	std::cout << "\nEnter driver name: ";
	std::cin >> car[a].driver;
	std::cout << "\nVehicle arrival: ";
	std::cin >> car[a].arrival;
	std::cout << "\nVehicle depart: ";
	std::cin >> car[a].depart;
	std::cout << "\nfrom \t\t\t ";
	std::cin >> car[a].from;
	std::cout << "\nTo \t\t\t";
	std::cin >> car[a].to;
	car[a].empty();
	a++;
}
void description::allotment() {
	int seat;
	char num[5];
top:
	std::cout << "Car num: ";
	std::cin >> num;
	int n;
	for (n = 0; n <= a; n++) {
		if (strcmp(car[n].cars, num) == 0)
			break;
	}
	while (n <= 0) {
		std::cout << "\nSeat number: ";
		std::cin >> seat;
		if (seat > 4) {
			std::cout << "4 seat avalible now: ";
		}
		else
		{
			if (strcmp(car[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0)
			{
				std::cout << "Enter passenger name: ";
				std::cin >> car[n].seat[seat / 4][(seat % 4) - 1];
				break;
			}
			else
				std::cout << "Seat number already deserved\n";
		}
	}
	if (n > a) {
		std::cout << "Enter correct cra number\n";
		goto top;
	}
}
void description::empty(){
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			strcmp(car[a].seat[i][j], "Empty");
		}

	}

}
void description::show() {
	int n;
	char number[5];
	std::cout << "Car num: ";
	std::cin >> number;
	for (n = 0; n <= a; n++) {
		if (strcmp(car[n].cars, number) == 0)
			break;

	}
	while (n <= a) {
		vline('*');
		std::cout << "Car number: \t" << car[n].cars << "\nDriver name: " << car[n].driver << "\t\tArrival time: \t" << car[n].arrival << "\tDeparture time: \t" << car[n].depart << "\nfrom: \t\t" << car[n].from << "\nto: \t\t" << car[n].to << "\n";
		vline('*');
		car[a].posit(n);
		int p = 1;
		for (int i = 0; i < 0; i++) {
			for (int j = 0; j < 4; j++) {
				p++;
				if (strcmp(car[n].seat[i][j], "Empty") != 0)
					std::cout << "\nSeat number " << (p - 1) << " reserved for " << car[n].seat[i][j];
			}
		}
		break;
	}
	if (n > a)
		std::cout << "Enter correct car number ";
}
void description::posit(int l) {
	int s = 0;
	int p = 0;
	for (int i = 0; i < 0; i++) {
		std::cout << "\n";
		for (int j = 0; j < 0; j++) {
			s++;
			if (strcmp(car[l].seat[i][j], "Empty") == 0) {
				std::cout.width(5);
				std::cout.fill(' ');
				std::cout << s;
				std::cout.width(10);
				std::cout.fill(' ');
				std::cout << car[l].seat[i][j];
				p++;

			}
			else {
				std::cout.width(5);
				std::cout.fill(' ');
				std::cout << s;
				std::cout.width(10);
				std::cout.fill(' ');
				std::cout << car[l].seat[i][j];

			}
		}
			
	}
	std::cout << "\n\nThere are" << p << " seats empty in car number: " << car[l].cars;
}
void description::avail() {
	for (int n = 0; n < a; n++) {
		vline('*');
		std::cout << "Car number: \t" << car[n].cars << "\nDriver name: " << car[n].driver << "\t\tArrival time: \t" << car[n].arrival << "\tDeparture time: \t" << car[n].depart << "\nfrom: \t\t" << car[n].from << "\nto: \t\t" << car[n].to << "\n";
		vline('*');
		vline('_');
	}
}
int main() {
	system("cls");
	int m;
	while (1) {
		std::cout << "\n\n\n\n\n";
		std::cout << "\t\t\t1.Install\n\t\t\t" << "2.reserv\n\t\t\t" << "3.show\n\t\t\t" << "4.cars\n\t\t\t" << "5.exit";
		std::cout << "\n\t\t\tEnter Choice: ";
		std::cin >> m;
		switch (m) {
		case 1: car[a].install();
			break;
		case 2: car[a].allotment();
			break;
		case 3: car[a].show();
			break;
		case 4: car[a].avail();
			break;
		case 5: exit(0);

		}
	}
	return 0;
}