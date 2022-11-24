#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

// ===========================================================
// class: Car
//
// class: Manual
// class: Automatic
//
// Manaul ve Automatic-den de mashinlar yaransin.
// Misal class Bmw: Automatic
//
// funksiya yazirisiz, Parametr olaraq Base qebul edir.
// Funksiya icersinde mashinlarin melumatlarni chap edirsiz.
//
// Her mashina aid field-ler ve mehodlar olsun.
//
// Base class adi altinda butun mashinlari vector-da saxlamaq
// Dersde kecdiylermizden istifade etmek...
// 
// Abstract class istifade edin!!!
// ===========================================================

class Car {
public:
	string name;
	string model;
	bool type;
	string color;
	string engine;
	int year;
	bool hasSpoiler;

	Car(string name, string model, bool type, string color, string engine, int year, bool hasSpoiler) {
		this->name = name;
		this->model = model;
		this->type = type;
		this->color = color;
		this->engine = engine;
		this->year = year;
		this->hasSpoiler = hasSpoiler;
	}

	virtual void Show() {
		cout << "========> Car <========" << endl;
		cout << "Name: " << name << "\nModel: " << model << "\nType: " << (type ? "Automatic" : "Manual") << "\nColor: " << color << "\nEngine: " << engine << "\nYear: " << year << "\nSpoiler: " << (hasSpoiler ? "Yes" : "No") << endl;
		cout << "=======================" << endl;
	}
};

class CarQueue {
public:
	vector<Car> cars;

	bool IsEmpty() const { return cars.empty(); }

	void Enqueue(const Car& car) {
		cars.push_back(car);
	}

	void Dequeue() {
		if (!cars.empty()) {
			cars.erase(cars.begin());
		}
	}

	Car& Front() { return cars.front(); }
};

class Garage {
public:
	CarQueue queue;

	void AddCar(const Car& car) {
		queue.Enqueue(car);
	}

	void ShowAllCars() {
		while (!queue.IsEmpty()) {
			Car car = queue.Front();
			system("cls");
			car.Show();
			Sleep(1000);
			queue.Dequeue();
		}
	}
};

void main() {
	Garage gr;
	gr.AddCar(Car("BMW", "M4", true, "Black", "3.0L", 2018, true));
	gr.AddCar(Car("Mercedes", "Maybach", true, "White", "4.7L", 2015, false));

	gr.ShowAllCars();
}