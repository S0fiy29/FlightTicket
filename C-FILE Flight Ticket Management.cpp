#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
int calcDate (int);
int countPerson(int,int,int);
void display(char*, int,double,double,double,double,double,double,double,double, int&);
double calcTic(double,double, double, double, char*, int, int&);
int flightJapan(int, double&, double&, double&, double&, double&, double&);
int flightIndia(int, double&, double&, double&, double&, double&, double&);
int flightPhilippines(int, double&, double&, double&, double&, double&, double&);
int flightKorean(int, double&, double&, double&, double&, double&, double&);
int flightIndonesia(int, double&, double&, double&, double&, double&, double&);
int flightTaiwan(int, double&, double&, double&, double&, double&, double&);
int flightVietnam(int, double&, double&, double&, double&, double&, double&);
int flightUSA(int, double&, double&, double&, double&, double&, double&);
int flightBrunei(int, double&, double&, double&, double&, double&, double&);
int flightChina(int, double&, double&, double&, double&, double&, double&);

int main ()
{
	char name[30], flighttype[5], flight[200], option, trip[5];
	double date, ticket, adult, kid, baby, totalticket, day, hour, min, timedepart, timearrived, totalperson;
	int destination, newdate, babyage;
	
	do
	{
		cout<<"WELCOME TO FLIGHT TICKET ONLINE \n";
		cout<<"PLEASE ENTER YOUR NAME: \n";
		cin>>name;
		cout<<"PLEASE SELECT DESTINATION: \n";
		cout<<"1 = TOKYO,JAPAN, 2 = NEW DELHI,INDIA, 3 = MANILA,PHILIPINES, 4 = SEOL,KOREAN, 5 = JAKARTA,INDONESIA, 6 = TAIPEI,TAIWAN \n"; 
		cout<<"7 = HO CHI MINH CITY,VIETNAM, 8 = NEW YORK,UNITED STATE OF AMERICA, 9 = BANDAR SERI BEGAWAN,BRUNEI, 10 = BEIJING,CHINA \n";
		cin>>destination;

			switch (destination)
			{
				case 1 : flightJapan(destination, ticket, day, hour, min, timedepart, timearrived); break;
				case 2 : flightIndia(destination, ticket, day, hour, min, timedepart, timearrived); break;
				case 3 : flightPhilippines(destination, ticket, day, hour, min, timedepart, timearrived); break;
				case 4 : flightKorean(destination, ticket, day, hour, min, timedepart, timearrived); break;
				case 5 : flightIndonesia(destination, ticket, day, hour, min, timedepart, timearrived); break;
				case 6 : flightTaiwan(destination, ticket, day, hour, min, timedepart, timearrived); break;
				case 7 : flightVietnam(destination, ticket, day, hour, min, timedepart, timearrived); break;
				case 8 : flightUSA(destination, ticket, day, hour, min, timedepart, timearrived); break;
				case 9 : flightBrunei(destination, ticket, day, hour, min, timedepart, timearrived); break;
				case 10 : flightChina(destination, ticket, day, hour, min, timedepart, timearrived); break;
				default : cout<<"INVALID CODE \n"; break;
			}
		
		cout<<"PLEASE ENTER THE NUMBER CUSTOMER \n";
		cout<<"ADULT: ";
		cin>>adult;
		cout<<"KID: ";
		cin>>kid;
		cout<<"BABY: ";
		cin>>baby;

		totalperson = countPerson(adult, kid, baby);
		
			if (baby > 0)
			{
				cout<<"ENTER BABY AGE IN MONTH \n";
				cin>>babyage;
	
				if (babyage <= 24)
				{
					baby = 0;
				}
				if (babyage > 24)
				{
					baby;
				}	
			}
				
		cout<<"PLEASE CHOOSE YOUR DATE FOR DEPARTURE\n";
		cin>>date;	
		date = calcDate (date);
		cout<<"PLEASE CHOOSE THE TRIP: ONE WAY [O] OR ROUND TRIP [R] \n";
		cin>>trip;
		
		totalticket = calcTic(ticket, adult, kid, baby, trip, date, newdate);
		display(name, destination,date,timedepart,timearrived,day,hour,min,totalperson,totalticket, newdate);
		
		cout<<"DO YOU WANT TO MAKE ANOTHER PAYMENT? (Y = YES OR N = NO)"<<endl;
		cin>>option;
	}while ( option != 'N');
	
	cout<<"THANK YOU FOR PURCHASE";
}
int calcDate (int date)
{
	do
	{
		if (date <= 31)
		{
			date = date;
		}
		else if (date > 31)
		{
			cout<<"INVALID DATE \n";
			cout<<"PLEASE ENTER ANOTHER DATE \n";
			cin>>date;
		}
		
	}while (date > 31);

	return date;
}
int countPerson(int adult, int kid, int baby)
{
	int totalperson;
	totalperson = adult + kid + baby;
	return totalperson;
}
double calcTic(double ticket, double adult, double kid, double baby, char* trip, int date, int &newdate)
{
	double totalticket;
	
	if (strcmp(trip,"O")==0)
	{
		newdate = date;
		totalticket = ticket * (adult + kid + baby);
	}
	if (strcmp(trip,"R")==0)
	{
		newdate = date + 3;
		totalticket = (ticket * 3) * (adult + kid + baby);
	}
	return totalticket;
}
int flightJapan(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{
	char flighttype[5];
	
	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"A = ALL NIPPON AIRWAYS, S = SINGAPORE AIRLINES, K = KOREAN AIR \n";
	cin>>flighttype;
	
	if (strcmp(flighttype,"A")==0)
	{
		cout<<"PRICE: RM1364.43"<<endl;
		ticket = 1364.43;
		timedepart = 08.00;
		timearrived = 15.40;
		day = 0;
		hour = 6;
		min = 40;
	}
	if (strcmp(flighttype,"S")==0)
	{
		cout<<"PRICE: RM1645.00"<<endl;
		ticket = 1645.00;
		timedepart = 10.20;
		timearrived = 08.30;
		day = 0;
		hour = 21;
		min = 5;
	}
	if (strcmp(flighttype,"K")==0)
	{
		cout<<"PRICE: RM2917.00"<<endl;
		ticket = 2917.00;
		timedepart = 21.55;
		timearrived = 13.35;
		day = 0;
		hour = 14;
		min = 40;
	}
	ticket;
}
int flightIndia(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{
	char flighttype[5];

	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"E = EMIRATES, Q = QATAR AIRWAYS, M = MALINDO AIR \n";
	cin>>flighttype;
	
	if (strcmp(flighttype,"E")==0)
	{
		cout<<"PRICE: RM2580.00"<<endl;
		ticket = 2580.00;
		timedepart = 01.45;
		timearrived = 08.55;
		day = 1;
		hour = 9;
		min = 40;
	}
	if (strcmp(flighttype,"Q")==0)
	{
		cout<<"PRICE: RM2342.00"<<endl;
		ticket = 2342.00;
		timedepart = 02.35;
		timearrived = 02.05;
		day = 1;
		hour = 2;
		min = 0;
	}
	if (strcmp(flighttype,"M")==0)
	{
		cout<<"PRICE: RM760.00"<<endl;
		ticket = 760.00;
		timedepart = 17.55;
		timearrived = 21.05;
		day = 0;
		hour = 5;
		min = 40;
	}
	ticket;
}
int flightPhilippines(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{
	char flighttype[5], flightpackage[5];

	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"MA = MULTI AIRLINE, K = KOREAN AIR, A = ALL NIPPON AIRWAYS, S = SINGAPORE AIRLINES \n";
	cout<<"AA = AIR ASIA, C = CATHAY PACIFIC, P = PHILIPPINE AIRLINES, M = MALAYSIA AIRLINES, J = JESTAR ASIA \n";
	cin>>flighttype;
	
	if (strcmp(flighttype,"MA")==0)
	{
		cout<<"PLEASE CHOOSE THE FLIGHT PACKAGE: \n";
		cout<<"MP = MALINDO AIR + PHILIPPINE AIRLINES, MG = MALINDO AIR + GARUDA INDONESIA, SP = SINGAPORE AIRLINES + PHILIPPINE AIRLINES \n";
		cout<<"JC = JETSTAR ASIA + CEBU PACIFIC, MC = MALAYSIA AIRLINES + CEBU PACIFIC, SC = SILK AIR + CEBU PACIFIC, MJ = MALAYSIA AIRLINE + JESTAR ASIA \n";
		cin>>flightpackage;
		
			if(strcmp(flightpackage,"MP")==0)
			{
				cout<<"PRICE: RM2489.13"<<endl;
				ticket = 2489.13,
				timedepart = 17.00;
				timearrived = 06.15;
				day = 0;
				hour = 13;
				min = 15;
			}
				if (strcmp(flightpackage,"MG")==0)
			{
				cout<<"PRICE: RM2489.13"<<endl;
				ticket = 2489.13,
				timedepart = 17.00;
				timearrived = 06.15;
				day = 0;
				hour = 13;
				min = 15;
			}
			if (strcmp(flightpackage,"SP")==0)
			{
				cout<<"PRICE: RM1445.05"<<endl;
				ticket = 1445.05,
				timedepart = 10.25;
				timearrived = 11.35;
				day = 0;
				hour = 7;
				min = 25;
			}
			if (strcmp(flightpackage,"JC")==0)
			{
				cout<<"PRICE: RM602.58"<<endl;
				ticket = 602.58,
				timedepart = 21.35;
				timearrived = 05.05;
				day = 0;
				hour = 7;
				min = 30;
			}
			if (strcmp(flightpackage,"MC")==0)
			{
				cout<<"PRICE: RM880.58"<<endl;
				ticket = 880.58,
				timedepart = 17.20;
				timearrived = 05.05;
				day = 0;
				hour = 11;
				min = 45;
			}
			if (strcmp(flightpackage,"SC")==0)
			{
				cout<<"PRICE: RM892.78"<<endl;
				ticket = 892.78,
				timedepart = 20.30;
				timearrived = 05.05;
				day = 0;
				hour = 8;
				min = 35;
			}
			if (strcmp(flightpackage,"MJ")==0)
			{
				cout<<"PRICE: RM937.68"<<endl;
				ticket = 937.68,
				timedepart = 12.20;
				timearrived = 20.15;
				day = 0;
				hour = 7;
				min = 55;
			}
	}
	if (strcmp(flighttype,"K")==0)
	{
		cout<<"PRICE: RM4893.00"<<endl;
		ticket = 4893.00;
		timedepart = 21.55;
		timearrived = 21.45;
		day = 0;
		hour = 23;
		min = 50;
	}
	if (strcmp(flighttype,"A")==0)
	{
		cout<<"PRICE: RM9595.00"<<endl;
		ticket = 9595.00;
		timedepart = 08.00;
		timearrived = 21.55;
		day = 0;
		hour = 13;
		min = 55;
	}
	if (strcmp(flighttype,"S")==0)
	{
		cout<<"PRICE: RM1063.00"<<endl;
		ticket = 1063.00;
		timedepart = 10.20;
		timearrived = 08.30;
		day = 1;
		hour = 2;
		min = 25;
	}
	if (strcmp(flighttype,"AA")==0)
	{
		cout<<"PRICE: RM658.12"<<endl;
		ticket = 658.12;
		timedepart = 08.15;
		timearrived = 12.15;
		day = 0;
		hour = 4;
		min = 0;
	}
	if (strcmp(flighttype,"C")==0)
	{
		cout<<"PRICE: RM1042.00"<<endl;
		ticket = 1042.00;
		timedepart = 17.50;
		timearrived = 09.40;
		day = 0;
		hour = 15;
		min = 50;
	}
	if (strcmp(flighttype,"P")==0)
	{
		cout<<"PRICE: RM1117.56"<<endl;
		ticket = 1117.56;
		timedepart = 11.55;
		timearrived = 15.40;
		day = 0;
		hour = 3;
		min = 45;
	}
	if (strcmp(flighttype,"M")==0)
	{
		cout<<"PRICE: RM661.00"<<endl;
		ticket = 661.00;
		timedepart = 12.45;
		timearrived = 16.30;
		day = 0;
		hour = 3;
		min = 45;
	}
	if (strcmp(flighttype,"J")==0)
	{
		cout<<"PRICE: RM712.88"<<endl;
		ticket = 712.88;
		timedepart = 11.15;
		timearrived = 20.15;
		day = 0;
		hour = 9;
		min = 0;
	}
	ticket;
}
int flightKorean(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{	
	char flighttype[5], flightpackage[5];
	
	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"S = SINGAPORE AIRLINES, K = KOREAN AIR, M = MULTI AIRLINE \n";
	cin>>flighttype;
	
	if (strcmp(flighttype,"K")==0)
	{
		cout<<"PRICE: RM2919.00"<<endl;
		ticket = 2919.00;
		timedepart = 21.55;
		timearrived = 05.15;
		day = 0;
		hour = 6;
		min = 20;
	}
	if (strcmp(flighttype,"S")==0)
	{
		cout<<"PRICE: RM1495.00"<<endl;
		ticket = 1495.00;
		timedepart = 10.25;
		timearrived = 15.30;
		day = 1;
		hour = 4;
		min = 5;
	}
	if (strcmp(flighttype,"M")==0)
	{
		cout<<"PLEASE CHOOSE THE FLIGHT PACKAGE: \n";
		cout<<"MK = MALAYSIA AIRLINES + KOREAN AIR, MA = MALAYSIA AIRLINES + ASIANA AIRLINES \n";
		cin>>flightpackage;
		
		if (strcmp(flightpackage,"MK")==0)
		{
			cout<<"PRICE: RM2161.92"<<endl;
			ticket = 2161.92;
			timedepart = 17.35;
			timearrived = 05.00;
			day = 0;
			hour = 10;
			min = 25;
		}
		if (strcmp(flightpackage,"MA")==0)
		{
			cout<<"PRICE: RM2065.7"<<endl;
			ticket = 2065.7;
			timedepart = 12.45;
			timearrived = 05.00;
			day = 0;
			hour = 15;
			min = 15;
		}
	}
	
	ticket;
}
int flightIndonesia(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{
	char flighttype[5], flightpackage[5];

	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"A = AIR ASIA, S = SINGAPORE AIRLINES, SA = SAUDI ARABIAN AIRLINES, I = INDONESIA AIRASIA \n";
	cout<<"G = GARUDA INDONESIA, M = MALINDO AIR ";
	cin>>flighttype;
	
	if (strcmp(flighttype,"A")==0)
	{
		cout<<"PRICE: RM236.53"<<endl;
		ticket = 236.53;
		timedepart = 08.35;
		timearrived = 09.40;
		day = 0;
		hour = 2;
		min = 5;
	}
	if (strcmp(flighttype,"S")==0)
	{
		cout<<"PRICE: RM833.00"<<endl;
		ticket = 833.00;
		timedepart = 10.25;
		timearrived = 10.15;
		day = 1;
		hour = 0;
		min = 50;
	}
	if (strcmp(flighttype,"SA")==0)
	{
		cout<<"PRICE: RM4108.44"<<endl;
		ticket = 4108.44;
		timedepart = 13.40;
		timearrived = 09.00;
		day = 0;
		hour = 20;
		min = 20;
	}
	if (strcmp(flighttype,"I")==0)
	{
		cout<<"PRICE: RM364.00"<<endl;
		ticket = 364.00;
		timedepart = 12.40;
		timearrived = 13.40;
		day = 0;
		hour = 2;
		min = 0;
	}
	if (strcmp(flighttype,"G")==0)
	{
		cout<<"PRICE: RM632.17"<<endl;
		ticket = 632.17;
		timedepart = 12.50;
		timearrived = 14.00;
		day = 0;
		hour = 2;
		min = 10;
	}
	if (strcmp(flighttype,"M")==0)
	{
		cout<<"PRICE: RM449.00"<<endl;
		ticket = 449.00;
		timedepart = 17.00;
		timearrived = 18.10;
		day = 0;
		hour = 2;
		min = 10;
	}
	ticket;
}
int flightTaiwan(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{
	char flighttype[5], flightpackage[5];

	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"E = EVA AIR, K = KOREAN AIR, C = CHINA AIRLINES \n";
	cin>>flighttype;
	
	if (strcmp(flighttype,"E")==0)
	{
		cout<<"PRICE: RM1273.00"<<endl;
		ticket = 1273.00;
		timedepart = 12.55;
		timearrived = 17.35;
		day = 0;
		hour = 4;
		min = 40;
	}
	if (strcmp(flighttype,"K")==0)
	{
		cout<<"PRICE: RM4318.00"<<endl;
		ticket = 4318.00;
		timedepart = 21.55;
		timearrived = 11.00;
		day = 1;
		hour = 13;
		min = 5;
	}
	if (strcmp(flighttype,"C")==0)
	{
		cout<<"PRICE: RM1059.17"<<endl;
		ticket = 1059.17;
		timedepart = 14.35;
		timearrived = 19.15;
		day = 0;
		hour = 4;
		min = 40;
	}
	ticket;
}
int flightVietnam(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{
	char flighttype[5], flightpackage[5];

	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"M = MALINDO AIR \n";
	cin>>flighttype;
	
	if (strcmp(flighttype,"M")==0)
	{
		cout<<"PRICE: RM313.00"<<endl;
		ticket = 313.00;
		timedepart = 14.20;
		timearrived = 15.25;
		day = 0;
		hour = 2;
		min = 5;
	}
	ticket;
}
int flightUSA(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{
	char flighttype[5], flightpackage[5];

	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"EA = ETIHAD AIRWAYS, Q = QATAR AIRWAYS, A = ALL NIPPON AIRWAYS \n";
	cout<<"E = EMIRATES, K = KOREAN AIR, S = SINGAPORE AIRLINES \n";
	cin>>flighttype;

	if (strcmp(flighttype,"EA")==0)
	{
		cout<<"PRICE: RM2636.00"<<endl;
		ticket = 2636.00;
		timedepart = 02.15;
		timearrived = 13.50;
		day = 0;
		hour = 23;
		min = 35;
	}
	if (strcmp(flighttype,"Q")==0)
	{
		cout<<"PRICE: RM2685.00"<<endl;
		ticket = 2685.00;
		timedepart = 20.30;
		timearrived = 14.25;
		day = 1;
		hour = 5;
		min = 55;
	}
	if (strcmp(flighttype,"A")==0)
	{
		cout<<"PRICE: RM2753.00"<<endl;
		ticket = 2753.00;
		timedepart = 08.00;
		timearrived = 15.30;
		day = 1;
		hour = 19;
		min = 30;
	}
	if (strcmp(flighttype,"E")==0)
	{
		cout<<"PRICE: RM2773.00"<<endl;
		ticket = 2773.00;
		timedepart = 01.45;
		timearrived = 13.55;
		day = 1;
		hour = 0;
		min = 10;
	}
	if (strcmp(flighttype,"K")==0)
	{
		cout<<"PRICE: RM2636.00"<<endl;
		ticket = 2636.00;
		timedepart = 21.55;
		timearrived = 10.00;
		day = 1;
		hour = 0;
		min = 5;
	}
	if (strcmp(flighttype,"S")==0)
	{
		cout<<"PRICE: RM8282.00"<<endl;
		ticket = 8282.00;
		timedepart = 20.30;
		timearrived = 07.30;
		day = 0;
		hour = 23;
		min = 0;
	}
	ticket;
}
int flightBrunei(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{
	char flighttype[5], flightpackage[5];

	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"R = ROYAL BRUNEI AIRLINES \n";
	cin>>flighttype;
	
	if (strcmp(flighttype,"R")==0)
	{
		cout<<"PRICE: RM1374.45"<<endl;
		ticket = 1374.45;
		timedepart = 21.20;
		timearrived = 23.40;
		day = 0;
		hour = 2;
		min = 20;
	}
	ticket;	
}
int flightChina(int destination, double &ticket, double &day, double &hour, double &min, double &timedepart, double &timearrived)
{
	char flighttype[5], flightpackage[5];

	cout<<"PLEASE CHOOSE YOUR FLIGHT \n";
	cout<<"C = CHINA SOUTHERN \n";
	cin>>flighttype;
	
	if (strcmp(flighttype,"C")==0)
	{
		cout<<"PRICE: RM5292.86"<<endl;
		ticket = 5292.86;
		timedepart = 13.35;
		timearrived = 22.55;
		day = 0;
		hour = 9;
		min = 20;
	}
	ticket;
}
void display (char* name,int destination,double date, double timedepart,double timearrived,double day,double hour,double min,double totalperson,double totalticket, int &newdate)
{
	cout<<"************************ TICKET FLIGHT RESIT *************************"<<endl;
	cout<<"CUSTOMER NAME: "<<name<<endl;
	cout<<"DESTINATION CHOICE: "<<destination<<endl;
	cout<<"FLIGHT DEPARTURE DATE: "<<date<<endl;
	if (newdate > date)
	{
		cout<<"FLIGHT RETURN DATE: "<<newdate<<endl;
	}
	cout<<"TIME DEPARTURE: "<<timedepart<<endl;
	cout<<"TIME ARRIVED: "<<timearrived<<endl;
	cout<<"TOTAL HOUR FLIGHT: "<<day<<" DAYS "<<hour<<" HOURS "<<min<<" MINS"<<endl;
	cout<<"TOTAL CUSTOMER: "<<totalperson<<endl;
	cout<<"TOTAL PRICE: RM"<<totalticket<<endl;
	cout<<"**********************************************************************"<<endl<<endl;
}
