#include<iostream>
#include<vector>
#include<windows.h>
#include<fstream>
using namespace std;
struct time
{
	int hh,mm,ss;
	char co11,co12;
};
struct date
{
 int day,month,year;
char sym1,sym2;
};
class vehicle
{
	string pltno;
	int type;
	date dt;
	time arrive;
	time departure;
	public:
		void addvehicle();
		void deletevehicle();
		void printvechicle(vehicle v);
		void show();
};
vector<vehicle>veh(100);
int static totalvechicle=0,totalcar=0,totalbike=0,totaleamt=0,i=0;

fstream file;

void vehicle::addvehicle()
{
	vechicle *v=new vechicle;
	cout<<"enter vechicle type(1 for car/2 for bike): ";
	cout<<v->type;
	cout<<"enter vechicle number: ";
	cin>>v->pltno;
	cout<<"enter arrival time in hours minute and seconds: ";
	cin>>v->arrive.hh>>v->arrive.coll>>v->arrive.mm>>v->arrive.co12>>v->arrive.ss;
	cout<<"enter date in day month and year:";
	cin>>v->dt.day>>v->dt.syml>>v->dt.month>>v->dt.sym2>>v->dt.year;
	
	veh.at(i).pltno=v->pltno;
	veh.at(i).type=v->type;
	veh.at(i).arrive.hh=v->arrive.hh;
	veh.at(i).arrive.mm=v->arrive.mm;
	veh.at(i).arrive.ss=v->arrive.ss;
	veh.at(i).dt.day=v->dt.day;	
	veh.at(i).dt.month=v->dt.month;		
	veh.at(i).dt.year=v->dt.year;	
	
	i++;
	totalvehicle++;
	if(v->type==1)
	{
		totalcar++;
	}
	else
	{
		totalbike++;
	}
	cout<<"\nvehicle added successfully"<<"\n";
}
int computetimedifference(time t1,time t2)
{
	int sec1,sec2,totalsec;
	time t3;
	sec1=t1.hh*60*60+t1.mm*60+t1.ss;
	sec2=t2.hh*60*60+t1.mm*60+t2.ss;
	
	totalsec=sec2-sec1;
	t3.mm=totalsec/60;
	t3.hh=t3.mm/60;
	t3.mm=t3.mm%60;
	t3.ss=totalsec%60;
	return t3.hh;
	
}
void vechicle::deletevechicle()
{
	string pno;
	int typ;
	time depart;
	int time_diff;
	int charge=0;
	
	cout<<"enter vechicle type(1 forcar/2 for bike): ";
	cin>>typ;
	cout<<"enter vechickle number:  ";
	cin>>pno;
	cout<<"enter deprature time in hr min and sec :";
	cin>>depart.hh>>depart.co11>>depart.mm<<depart.co12>>depart.ss;
	
	for( int j=0;j<=i;j++)
	{
		if((veh.at(j).pltno==pno)&&(veh.at(j).type==typ))
		{
			veh.at(j).departure.hh=depart.hh;
			veh.at(j).departure.mm=depart.mm;
			veh.at(j).departure.ss=depart.ss;
			
			time_diff=computetimedifference(veh.at(j).arrive,depart);
			if(veh.at(j).type==1)
			{
				totalcar--;
				if(time_diff<2)
				{
					charge=20;
				}
				else
				{
					if(time_diff>2 and time_diff<5)
					{
						charge=40;
						
					}
					else
					{
						charge=50;
					}
				}
			}
		}
		else
		{
				totalbike--;
				if(time_diff<2)
				{
					charge=5;
				}
				else
				{
					if(time_diff>2 and time_diff<5)
					{
						charge=10;
						
					}
					else
					{
						charge=20;
					}
				}
			}
			
			
			cout<<"\nvechicle having vechical number: "<<veh.at(j).pltno<<"has left the parking after paying rs. "<<charge<<"\n";
			
		}
	})
}
	}
		}	
	
	
	
	
	
	
	
	
	
	
	
	
}
int main()
{
	cout<<"gjfgjd";
}