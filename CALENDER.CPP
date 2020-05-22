#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int mainmenu();
int cal(int yr,int m);
int press(int ch);
int yr,m;
int main()
{
  mainmenu();
  //getch();
  getchar();
  return 0;
}
int mainmenu()
{
  int choice;
  //system("clear");
  system("clear");
  cout<<"\n\n\t\t============================================";
  cout<<"\n\n\t\t		MAIN MENU                    ";
  cout<<"\n\n\t\t============================================";
  cout<<"\n\n\n\t\t 1.Press 1 to see monthly calender"<<endl;
  cout<<"\n\n\t\t 2.Press 2 to exit";
  cout<<"\n\n\n\t\t Enter Your Choice:   ";
  cin>>choice;
  switch (choice)
  {
    case 1:
	system("clear");
	cout<<"\n\n\n\t Enter integer value of year and month -- ";
	cout<<"\n\n\n\t\tYEAR : ";
	cin>>yr;
	cout<<"\n\n\t\tMONTH : ";
	cin>>m;
	if(yr<=0)
	{
	  system("clear");
	  cout<<"\n\n\n\n\n\n\n\t\t\t! ! !  I N V A L I D  I N P U T  ! ! !";
	}
	else
	  cal(yr,m);
	break;
    case 2:
	exit(0);
    default:
	system("clear");
	cout<<"\n\n\n\n\n\n\n\t\t\t! ! !  INVALID  INPUT  ! ! !";
  }
  return 0;
}
int cal(int yr,int m)
{
  int day=0,year=2012;   //initialize reference

  //yearwise increment

  if(yr>year)
    for(year=2012; year<yr; year++)
	day=(year%100==0?(year%400==0?day+2:day+1):(year%4==0?day+2:day+1));

  //yearwise decrement

  if(yr<year)
  {
    for(year=2012; year>yr; year--)
    {
	int year1=year-1;
	day=(year1%100==0?(year1%400==0?day-2:day-1):(year1%4==0?day-2:day-1));
    }
    while(day<0)
	day=day+7;
  }

  //month-wise increment

  int mday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  mday[1]=(yr%100==0?(yr%400==0?29:28):(yr%4==0?29:28));
  for(int month=0;month<=m-2;month++)
	day=mday[month]+day;
  day=(day%7);

  //printing title of calender

  system("clear");
  cout<<"\n\n\n\n\n\t\t\t\t";
  switch(m)
  {
     case 1: cout<<"JANUARY";
		break;
     case 2: cout<<"FEBRUARY";
		break;
     case 3: cout<<"MARCH";
		break;
     case 4: cout<<"APRIL";
		break;
     case 5: cout<<"MAY";
		break;
     case 6: cout<<"JUNE";
		break;
     case 7: cout<<"JULY";
		break;
     case 8: cout<<"AUGUST";
		break;
     case 9: cout<<"SEPTEMBER";
		break;
     case 10: cout<<"OCTOBER";
		break;
     case 11: cout<<"NOVEMBER";
		break;
     case 12: cout<<"DECEMBER";
		break;
  }
  cout<<" "<<yr;
  cout<<"\n\n\n";

  //printing calender headers

  cout<<"\t\tSUN\tMON\tTUE\tWED\tTHUR\tFRI\tSAT\n\n";

  //initializing calender matrix as zero matrix;

  int a[5][7];
  int num=0,i,j;
  for(i=j=0;j<7;j++)
  {
	if(j<day)
		a[i][j]=0;
	else
	{
		num=num+1;
		a[i][j]=num;
	}
  }
  for(i=1;i<6;i++)	//for remaining rows
     for(j=0;j<7;j++)
     {
	if(num<mday[m-1])
	{
	    num=num+1;
	    a[i][j]=num;
	}
	else
	    a[i][j]=0;
     }
  for(i=0;i<6;i++)
  {
     cout<<"\n\t\t";
     for(j=0;j<7;j++)
     {
	if(a[i][j]==0)
	   cout<<"\t";
	else
	   cout<<a[i][j]<<"\t";
     }
     cout<<endl<<endl;
  }

  //footer line

  int ch;
  cout<<"\n\n\n\n\n   ENTER:-\n";
  cout<<"\n\t 8   -  previous month same year"<<endl;
  cout<<"\n\t 2   -  next month same year"<<endl;
  cout<<"\n\t 4   -  previous year same month"<<endl;
  cout<<"\n\t 6   -  next year same month"<<endl;
  cout<<"\n\t 0   -  back to main menu"<<endl;
  cout<<"\n\t\t  Enter your choice - ";
  cin>>ch;
  press(ch);
  return 0;
}
int press(int ch)
{
   switch(ch)
   {
	case 8: m=m-1;
		if(m<1)
		   m=12;
		cal(yr,m);
		break;
	case 2: m=m+1;
		if(m>12)
		   m=1;
		cal(yr,m);
		break;
	case 4: yr=yr-1;
		if(yr<=0)
		{
		   system("clear");
		   cout<<"\n\n\n\n\n\n\n\t\t\t! ! !  I N V A L I D   I N P U T   ! ! !";
		   cout<<"\n\n\n\n\t\t\t Press ANY key to continue:";
		   getchar();
		}
		else
		   cal(yr,m);
	case 6: yr=yr+1;
		cal(yr,m);
	case 0: mainmenu();
   }
   return 0;
}
