#include <iostream>
using namespace std;


class Person
{
private:
	char* Name;
	int Age;
	char Gender;

public:
	Person()
	{
		//Initialise data members
		Name = new char[25];
		Name[0] = '\0';
		Age = 0;
		Gender = 'M';

		//cout << "Default constructor of Person" << endl;
	}
	Person(const char* name, int age, char gender)
	{
		Name = new char[25];
		int i = 0;
		while (name[i] != '\0')
		{
			Name[i] = name[i];
			i++;
		}
		Name[i] = '\0';
		Age = age;
		Gender = gender;

		cout << "Parametrized constructor of Person" << endl;
	}
	virtual void addInfo()
	{
		cout << "Wprowadz imie pasazera: ";
		cin.ignore();
		cin.getline(Name, 25);
		cout << "Wprowadz wiek: ";
		cin >> Age;
		cout << "Podaj plec (M/K): ";
		cin >> Gender;
	}
	virtual void Print()
	{
		cout << "Imie: " << Name << endl;
		cout << "Wiek: " << Age << endl;
		cout << "Plec: " << Gender << endl;
	}
	~Person()
	{
		delete[]Name;
		Name = nullptr;
	}
};

class Adult : public Person
{
private:
	char* Occupation;
	char* Qualification;
	char* Pesel;
public:
	Adult()
	{
		Occupation = new char[20];
		Qualification = new char[20];
		Pesel = new char[14];

		//initialise
		Occupation[0] = '\0';
		Qualification[0] = '\0';
		Pesel[0] = '\0';

		//cout << "Default constructor of Adult" << endl;
	}
	Adult(const char* name, int age, char gender, const char* job, const char* degree, const char* cpesel) :Person(name, age, gender)
	{
		Occupation = new char[20];
		Qualification = new char[20];
		Pesel = new char[14];

		int i = 0;
		while (job[i] != '\0')
		{
			Occupation[i] = job[i];
			i++;
		}
		Occupation[i] = '\0';
		
		i = 0;
		while (degree[i] != '\0')
		{
			Qualification[i] = degree[i];
			i++;
		}
		Qualification[i] = '\0';

		i = 0;
		while (cpesel[i] != '\0')
		{
			Pesel[i] = cpesel[i];
			i++;
		}
		Pesel[i] = '\0';

		cout << "Parametrized constructor of Adult" << endl;
	}
	void addInfo()
	{
		cout << "==========================================================" << endl;
		cout << "Wprowadz informacje o doroslym pasazerze:" << endl;
		Person::addInfo();
		cout << "Podaj zawod: ";
		cin.ignore();
		cin.getline(Occupation, 20);
		cout << "Podaj wyksztalcenie: ";
		cin.ignore();
		cin.getline(Qualification, 20);
		cout << "Wprowadz numer PESEL: ";
		cin.ignore();
		cin.getline(Pesel, 14);

	}
	void Print()
	{
		cout << "********************************************" << endl;
		Person::Print();
		cout << "Zawod: " << Occupation << endl;
		cout << "Wyksztalcenie: " << Qualification << endl;
		cout << "PESEL: " << Pesel << endl;
	}
	~Adult()
	{
		delete[]Occupation;
		delete[]Qualification;
		delete[]Pesel;

		Occupation = nullptr;
		Qualification = nullptr;
		Pesel = nullptr;
	}
};

class Kid :public Person
{
private:
	char* B_form_number;
public:
	Kid()
	{
		B_form_number = new char[14];
		B_form_number[0] = '\0';

		//cout << "Default constructor of Kid" << endl;
	}
	Kid(const char* name, int age, char gender, char* bform) :Person(name, age, gender)
	{
		B_form_number = new char[14];
		int i = 0;
		while (bform[i] != '\0')
		{
			B_form_number[i] = bform[i];
			i++;
		}
		B_form_number[i] = '\0';

		cout << "Parametrized constructor of Kid" << endl;
	}
	void addInfo()
	{
		cout << "==========================================================" << endl;
		cout << "Enter details of Kid Passenger:" << endl;
		Person::addInfo();
		cout << "Enter Bform number of Kid: ";
		cin.ignore();
		cin.getline(B_form_number, 14);
	}
	void Print()
	{
		cout << "********************************************" << endl;
		Person::Print();
		cout << "B form Number: " << B_form_number << endl;
	}
	~Kid()
	{
		delete[]B_form_number;
		B_form_number = nullptr;
	}
};

class Bogie
{
private:
	int Bogie_ID;
	Bogie* Next;
	Person** Adults;
	Person** Kids;
	char* FamilyName;
	int AdultCount;
	int KidsCount;
public:
	Bogie(int id)
	{
		Bogie_ID = id;
		Next = nullptr;
		Adults = new Person*[4];
		Kids = new Person*[6];
		FamilyName = new char[15];
		AdultCount = 0;
		KidsCount = 0;

		
		cout << "Reserved for Family: ";
		cin.ignore();
		cin.getline(FamilyName, 15);
		
		

		cout << "Bogie No." << Bogie_ID << " Created" << endl;
	}
	void AddPassengers()
	{
		int a = 0, k = 0;
		bool error = false;

		cout << "\n>>>>>>>>>>>>>>>PASSENGERS INFORMATION<<<<<<<<<<<<<<<<<<<<\n" << endl;

		if (AdultCount == 4)
		{
			cout << "No Adults can be added. maximum amount(4) reached." << endl;
		}
		else
		{
			do
			{
				cout << "How many Adults: ";
				cin >> a;
				if ((AdultCount + a) > 4)
				{
					cout << "Error: Invalid number. Adults left are: " << (4 - AdultCount) << endl;
					error = true;
				}
				else
				{
					//AdultCount += a;
					error = false;
				}
			} while (error==true);

		}

		if (KidsCount == 6)
		{
			cout << "No Kids can be added. maximum amount(6) reached." << endl;
		}
		else
		{
			do
			{
				cout << "How many Kids: ";
				cin >> k;
				if ((KidsCount + k) > 6)
				{
					cout << "Error: Invalid number. Kids left are: " << (6 - KidsCount) << endl;
					error = true;
				}
				else
				{
					//KidsCount += k;
					error = false;
				}
			} while (error==true);
		}
		
		//Input Passengers info
		
		for (int i = 0;i < a;i++)
		{

			Adults[AdultCount] = new Adult;
			Adults[AdultCount]->addInfo();
			AdultCount++;
			cout << "\nPassenger added successfully\n";
		}

		for (int i = 0;i < k;i++)
		{
			//Kids[KidsCount].addInfo();
			Kids[KidsCount] = new Kid;
			Kids[KidsCount]->addInfo();
			KidsCount++;
			cout << "\nPassenger added successfully\n";
		}
	}
	void Print()
	{
		cout << "\n********************************************\nRESERVED FOR FAMLIY: " << FamilyName << endl;
		for (int i = 0;i < AdultCount;i++)
		{
			Adults[i]->Print();
		}

		for (int i = 0;i < KidsCount;i++)
		{
			Kids[i]->Print();
		}
	}
	//Utility functions below
	int GetID()
	{
		int n = Bogie_ID;
		return n;
	}
	bool Last_Bogie()
	{
		if (Next == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void UpdateNext(Bogie& temp)
	{
		Next = &temp;
	}
	Bogie* GetNextBogie()
	{
		return Next;
	}
	void MakeNextNull()
	{
		Next = nullptr;
	}
	~Bogie()
	{
		delete[] Adults;
		delete[] Kids;
		delete[]FamilyName;
		Adults = nullptr;
		Kids = nullptr;
		FamilyName = nullptr;
		cout << "Bogie Destructor" << endl;
	}
};


class train
{
	Bogie* Engine;
public:
	train()
	{
		Engine = nullptr;
	}
	void AddBogie(int id)
	{
		if (SearchBogie(id) == true)
		{
			cout << "Wagon o tym identyfikatorze juz istnieje! Prosze wybrac inny." << endl;
		}
		else
		{
			Bogie* Newbogie = new Bogie(id);
			if (Engine == nullptr)
			{
				Engine = Newbogie;
			}
			else
			{
				bool end = false;
				Bogie* find = Engine;
				while (end == false)
				{
					if (find->Last_Bogie() == true)
					{
						find->UpdateNext((*Newbogie));
						end = true;
					}
					else
					{
						find = find->GetNextBogie();
						end = false;
					}
				}
			}
		}
	}
	void PrintTrain()
	{
		bool end = false;
		Bogie* traverse = Engine;
		if (Engine != nullptr)
		{
			cout << " __________" << endl;
			cout << "|  SILNIK  |" << endl;
			cout << "|__________|" << endl;
			cout << "OO        OO" << endl;
			cout << "      |    " << endl;
			cout << "      V    " << endl;
			while (end == false)
			{
				cout << " __________" << endl;
				cout << "| WAGON#"<<traverse->GetID()<<" |" << endl;
				cout << "|__________|" << endl;
				cout << "OO        OO" << endl;
				

				//cout << "ID Wagonu: " << traverse->GetID() << endl;
				if (traverse->Last_Bogie() == true)
				{
					end = true;
				}
				else
				{
					cout << "      |    " << endl;
					cout << "      V    " << endl;
					traverse = traverse->GetNextBogie();
				}
			}
		}
		else
		{
			//cout << "Pusty pociag. Brak wagonow.\n";
			cout << " __________" << endl;
			cout << "|  SILNIK  |" << endl;
			cout << "|__________|" << endl;
			cout << "OO        OO" << endl;
		}
	}
	bool SearchBogie(int id)
	{
		bool found = false, end = false;
		Bogie* search = Engine;
		if (Engine != nullptr)
		{
			while (found == false && end == false)
			{
				if (id == search->GetID())
				{
					found = true;
					break;
					
				}

				if (search->Last_Bogie() == true)
				{
					end = true;

				}
				else
				{
					end = false;
					search = search->GetNextBogie();
				}
			}
		}
		return found;
	}
	void RemoveBogie(int id)
	{
		int BogieIndex = 0;

		bool found = false, end = false;
		Bogie* search = Engine;
		if (Engine != nullptr)
		{
			while (found == false && end == false)
			{
				if (id == search->GetID())
				{
					found = true;
					break;
				}

				if (search->Last_Bogie() == true)
				{
					end = true;
				}
				else
				{
					end = false;
					search = search->GetNextBogie();
					BogieIndex++;
				}
			}

			if (found == true)
			{
				Bogie* predecessor = Engine;
				Bogie* successor = Engine;

				if (BogieIndex == 0)
				{
					for (int i = 0;i < (BogieIndex + 1);i++)
					{
						successor = successor->GetNextBogie();
					}

					Engine = successor;
					search->MakeNextNull();
					delete search;
					search = nullptr;
					cout << "Wagon numer " << id << " usuniety pomyslnie.\n";
				}
				else
				{
					for (int i = 0;i < (BogieIndex - 1);i++)
					{
						predecessor = predecessor->GetNextBogie();
					}
					for (int i = 0;i < (BogieIndex + 1);i++)
					{
						successor = successor->GetNextBogie();
					}

					predecessor->UpdateNext(*successor);
					search->MakeNextNull();
					delete search;
					search = nullptr;
					cout << "Wagon numer " << id << " usuniety pomyslnie.\n";
				}
			}
			else
			{
				cout << "Niepoprawne dane. Nie odnaleziono wagonu.\n";
			}
		}
		else
		{
			cout << "W pociagu nie ma juz wagonow.\n";
		}
	}
	void PassengersForBogie(int id)
	{
		bool found = false, end = false;
		Bogie* search = Engine;
		if (Engine != nullptr)
		{
			while (found == false && end == false)
			{
				if (id == search->GetID())
				{
					found = true;
					break;

				}

				if (search->Last_Bogie() == true)
				{
					end = true;

				}
				else
				{
					end = false;
					search = search->GetNextBogie();
				}
			}
		}

		//Now add passengers to that specific bogie
		if (found == true)
		{
			search->AddPassengers();
		}
		else
		{
			cout << "Niepoprawne ID. Wprowadz dane ponownie.\n";
		}
	}
	void BogieDetails(int id)
	{
		bool found = false, end = false;
		Bogie* search = Engine;
		if (Engine != nullptr)
		{
			while (found == false && end == false)
			{
				if (id == search->GetID())
				{
					found = true;
					break;

				}

				if (search->Last_Bogie() == true)
				{
					end = true;

				}
				else
				{
					end = false;
					search = search->GetNextBogie();
				}
			}
		}

		//Now print details of that specific bogie
		if (found == true)
		{
			search->Print();
		}
		else
		{
			cout << "Niepoprawne ID. Wprowadz dane ponownie.\n";
		}
	}
	~train()
	{
		delete Engine;
	}
};


int main()
{
	train FASTexpress;
	int choice=0;
	cout << "****************************************************\n";
	cout << "            WITAMY NA POKLADZIE PKP                 \n";
	cout << "****************************************************\n";
	while (true)
	{
		menu:
		cout << "\n-->> Nacisnij 1 aby dodac wagon" << endl;
		cout << "-->> Nacisniij 2 aby kupic bilety na zarezerwowany pociag" << endl;
		cout << "-->> Nacisniij 3 aby wyszukac wagon" << endl;
		cout << "-->> Nacisniij 4 aby usunac wagon" << endl;
		cout << "-->> Nacisniij 5 aby sprawdzic szczegoly pociagu" << endl;
		cout << "-->> Nacisniij 6 aby sprawdzic szczegoly wagonu" << endl;
		cout << "-->> Nacisniij -1 aby wyjsc z menu" << endl;
		cout << "Twoj wybor: ";
		cin >> choice;

		if (choice == 1)
		{
			int id;
			cout << "Wprowadz ID wagonu: " << endl;
			cin >> id;
			FASTexpress.AddBogie(id);
		}

		else if (choice == 2)
		{
			int id;
			cout << "Wprowadz ID wagonu: " << endl;
			cin >> id;
			FASTexpress.PassengersForBogie(id);
		}

		else if (choice == 3)
		{
			int id;
			bool result;
			cout << "Wprowadz ID wagonu: " << endl;
			cin >> id;
			result = FASTexpress.SearchBogie(id);
			if (result == true)
			{
				cout << "Wagon odnaleziony.\n";
			}
			else
			{
				cout << "Wagon nie odnaleziony.\n";
			}
		}

		else if (choice == 4)
		{
			int id;
			cout << "Wprowadz ID wagonu: " << endl;
			cin >> id;
			FASTexpress.RemoveBogie(id);
		}

		else if (choice == 5)
		{
			FASTexpress.PrintTrain();
		}

		else if (choice == 6)
		{
			int id;
			cout << "Wprowadz ID wagonu: " << endl;
			cin >> id;
			FASTexpress.BogieDetails(id);
		}

		else if (choice == -1)
		{
			cout << "\n==============================================\n";
			cout << "\nDziekujemy za wybor. PKP - koleje przyszlosci\n";
			cout << "\n==============================================\n\n";
			break;
		}
		else
		{
			goto menu;
		}
	}


	return 0;
}