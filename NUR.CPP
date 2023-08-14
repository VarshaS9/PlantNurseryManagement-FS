
#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
#include<iomanip.h>

fstream data;
char Baf[80],Buffer[80];
//char manager_id[]="vysh";
//char manager_password[]="vysh";
unsigned long int total = 0;
char charr[50];
class cart
{
   public: int flag;
    char name[20],num[20],stock[20];
	unsigned long int amount;
	//,amount[20];
};
class items
{
	public:
		char num[20],name[20],stock[20];
		unsigned long int amt;
}acc;
cart rec[10];
int no,k;

int hash(int m)
{   int r,q;
    r=m%10;
	q=rand()/10;
    q=m/10;
    k=(q+r+7)%10; //because 7 is our fav number #CR7
    return k;
}
void unpack()
{   int i=0;
    fstream in;
    in.open("ca.txt",ios::in);
    char buf[80];
    while(!in.eof())
    {
      in.getline(rec[i].name,50,'|');
      //sprintf(buf,"%s|%s|%lu",rec[i].name,rec[i].num,rec[i].amount);
      in.getline(rec[i].num,50,'|');
      in.getline(rec[i].stock,50,'|');
      in.getline(charr,50,'\n');
      rec[i].amount=atoi(charr);
      i++;
    }
    in.close();
}
void search()
{
 int m,i,f=0,ff=0;
 char num[15];
 clrscr();
    cout<<endl;
    cout<<"Enter Item Number : ";
    cin>>num;
    m=atoi(num);
    k=hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[k%10].num,num))==0 && ff==0) 
      {
      	ff=1;
      cout<<"\n found at "<<k<<": "<<endl;
      cout<<"\n\n\tITEM NO : "<<rec[k%10].num<<"\t"<<"\n\n\tITEM NAME : "<<rec[k%10].name<<"\t"<<"\n\n\tITEM COST : "<<rec[k%10].amount<<"\n";
      f=1;
      }
      k=k+1;
    }
    if(f!=1)
    cout<<"\n NOT found :( \n";    getch();
    return;
 }
 void deletee()
 {
     int ch;
     clrscr();

	cout<<"\n\n\t\t REMOVING ITEMS FROM CART............\n\n";
     cout<<" \n\n\n 1. Specific ITEM ";
     cout<<" \n\n\n 2. All ITEMS ";
     cout<<" \n\n\n 3. Exit ";
     cout<<" \n\n\n\t ENTER YOUR CHOICE    : ";
     cin>>ch;
     switch(ch)
      {
      	clrscr();
       case 1:
		 int m,i,f=0,cc;
	char vv[20];
   char tt[20],num[20];
   unsigned long amt;
    cout<<endl;
    cout<<"Enter Item Number : ";
    cin>>num;
    m=atoi(num);
    k=hash(m);
    unpack();
    for(i=0;i<10;i++)
    {
      if((strcmp(rec[k%10].num,num))==0)
      {
      f=1;
      cout<<" \n\n\t\t ITEM REMOVED :) "    ;
      rec[k%10].flag=0;
      strcpy(rec[k%10].num,"zzzzzzzzzzzzzzzzzzz");
      total = total - rec[k%10].amount;
      break;
      }
     k=k+1;
    }
    fstream f1;
    f1.open("ca.txt",ios::out);
    for(i=0;i<10;i++)
    {
      if(rec[i].flag==0)
	{
		  f1<<"#|#"<<"\n";}
      //else if(strcmp(vv,rec[i].num)==0)
	//f1<<"#|#                   ";
      else
	{
		  f1<<rec[i].num<<"|"<<rec[i].name<<"|"<<rec[i].amount<<"\n";}
    }
   f1.close();
    if(f!=1)
    cout<<"\n not found \n";   getch();
    return;


	   case 2:

		fstream f12;
	f12.open("ca.txt",ios::out);
	for(i=0;i<10;i++)
	{
		if(rec[i].flag==0)
			f12<<"#|#"<<"\n";
		else
			  {
			  rec[i].flag=0;
			  strcpy(rec[i].num,"zzzzzzzzzzzzzzzzzzz");
			  f12<<"#|#"<<"\n";
			  }
	}
		f12.close();
		      total = 0;

		      cout<<" \n\n\t\tREMOVED ALL ITEMS OF CART     :) "  ;
		      getch();

	    break;



 }
}
 void disp()
{
	clrscr();
	cout<<"\n\n\t\tDISPLAYING ALL ITEMS...............\n";
	cout<<"\n\n\nITEM NAME \t\t ITEM NUMBER \t\t COST\n";
	cout<<"###############################################################\n";
	  for(int i=0;i<10;i++)
    {
    if(rec[i].flag==1)
    cout<<endl<<rec[i].name<<"\t\t"<<rec[i].num<<"\t\t"<<rec[i].stock<<"\t\t"<<rec[i].amount<<"\n";
	}
	getch();
}

void additems()
{
	 clrscr();
       cout<<"\n\n\t\tINSERTION OF ITEMS.................\n\n";
	char Buffer[51],offset[10];
		char itno[20],baa[50],num[20],name[20],charr[20],stock[20];
	unsigned long int a;
	int flaggg=0;

		char ch='y';
	cout << "\n\n\t\tPLANT CATEGORIES:\n";
    cout << "1. Seed\n";
    cout << "2. Indoor Plant\n";
    cout << "3. Outdoor Plant\n";
    cout << "4. Pots\n";
    cout << "5. Fertilizers\n";
    cout << "6. Gardening tools\n";
    cout << "7. Exit\n";

    int choice;
    cout << "Enter the category number: ";
    cin >> choice;

    // Displaying items based on selected category
    clrscr();
    //cout << "\n\n\t\tITEMS IN SELECTED CATEGORY:\n";
    switch (choice)
    {
	case 1:while(ch=='y')
	{
		
	data.open("itm.txt",ios::in);
	cout << "\n\n\t\tITEMS IN SEED CATEGORY:\n";
	cout<<"\n Enter ITEM ID: ";
    cin>>acc.num;
  //  int accnum=acc.num;
    //if ((accnum >=1000) && (accnum <=1999)) {
            if(!data)
	flaggg=2;
    while(!data.eof() && flaggg==0)
	{
	  data.getline(num,50,'|');
	  data.getline(name,50,'|');
	  data.getline(stock,50,'|');
      data.getline(charr,50,'\n');
      a=atoi(charr);
      if((strcmp(acc.num,num))==0)
      {
	flaggg=1;
	cout<<"\n\n\t\t ITEM WITH THE SAME NUMBER ALREADY EXISTS..!!!";
	getch();
	  }
	  if(data.eof())
		break;
	}
	data.close();
	if(flaggg==1)
		break;
	if(flaggg != 1)
	{

	cout<<"\n Enter  Name (max 50 characters)       : ";
	gets(acc.name);
	cout<<"\n Enter Stock: ";
	gets(acc.stock);
	//cin>>acc.name;
	 cout << "\n Enter Price: ";
            int validPrice = 0;
            while (!validPrice) {
                if (cin >> acc.amt) {
                    validPrice = 1;
                    data.open("itm.txt",ios::app);
		//sprintf(Buffer,"|%s|%s|%lu|#",acc.num,acc.name,acc.amt);
		data<<acc.num<<'|'<<acc.name<<'|'<<acc.stock<<'|'<<acc.amt<<'\n';

		data.close();

	  cout<<" \n\n\n\n\n ITEM ADDED......!! ";
		 cout<<"\n\n\n\t\t\tClick y to Add one more  :  "    ;
		cin>>ch;
                } else {
                    cout << "Invalid input. Please enter a valid price!!! ";
                    cin.clear();
                    cin.ignore(100, '\n');
                    //getch();
                    exit(0);
                }

	
	}

  }

    }
		break;
	case 2:while(ch=='y')
	{
	data.open("itm.txt",ios::in);
	cout << "\n\n\t\tITEMS IN INDOOR CATEGORY:\n";
	cout<<"\n Enter ITEM ID: ";
    cin>>acc.num;
    if(!data)
	flaggg=2;
    while(!data.eof() && flaggg==0)
	{
	  data.getline(num,50,'|');
	  data.getline(name,50,'|');
	  data.getline(stock,50,'|');
      data.getline(charr,50,'\n');
      a=atoi(charr);
      if((strcmp(acc.num,num))==0)
      {
	flaggg=1;
	cout<<"\n\n\t\t ITEM WITH THE SAME NUMBER ALREADY EXISTS..!!!";
	getch();
	  }
	  if(data.eof())
		break;
	}
	data.close();
	if(flaggg==1)
		break;
	if(flaggg != 1)
	{

	cout<<"\n Enter  Name (max 50 characters)       : ";
	gets(acc.name);
	cout<<"\n Enter Stock: ";
	gets(acc.stock);
	//cin>>acc.name;
	 cout << "\n Enter Price: ";
            int validPrice = 0;
            while (!validPrice) {
                if (cin >> acc.amt) {
                    validPrice = 1;
                    data.open("itm.txt",ios::app);
		//sprintf(Buffer,"|%s|%s|%lu|#",acc.num,acc.name,acc.amt);
		data<<acc.num<<'|'<<acc.name<<'|'<<acc.stock<<'|'<<acc.amt<<'\n';

		data.close();

	  cout<<" \n\n\n\n\n ITEM ADDED......!! ";
		 cout<<"\n\n\n\t\t\tClick y to Add one more  :  "    ;
		cin>>ch;
                } else {
                    cout << "Invalid input. Please enter a valid price!!! ";
                    cin.clear();
                    cin.ignore(100, '\n');
                    //getch();
                    exit(0);
                }

	
	}

  }
  }
 		break;
	case 3:while(ch=='y')
	{
	data.open("itm.txt",ios::in);
	cout << "\n\n\t\tITEMS IN OUTDOOR CATEGORY:\n";
	cout<<"\n Enter ITEM ID: ";
    cin>>acc.num;
    if(!data)
	flaggg=2;
    while(!data.eof() && flaggg==0)
	{
	  data.getline(num,50,'|');
	  data.getline(name,50,'|');
	  data.getline(stock,50,'|');
      data.getline(charr,50,'\n');
      a=atoi(charr);
      if((strcmp(acc.num,num))==0)
      {
	flaggg=1;
	cout<<"\n\n\t\t ITEM WITH THE SAME NUMBER ALREADY EXISTS..!!!";
	getch();
	  }
	  if(data.eof())
		break;
	}
	data.close();
	if(flaggg==1)
		break;
	if(flaggg != 1)
	{

	cout<<"\n Enter  Name (max 50 characters)       : ";
	gets(acc.name);
	cout<<"\n Enter Stock: ";
	gets(acc.stock);
	//cin>>acc.name;
	 cout << "\n Enter Price: ";
            int validPrice = 0;
            while (!validPrice) {
                if (cin >> acc.amt) {
                    validPrice = 1;
                    data.open("itm.txt",ios::app);
		//sprintf(Buffer,"|%s|%s|%lu|#",acc.num,acc.name,acc.amt);
		data<<acc.num<<'|'<<acc.name<<'|'<<acc.stock<<'|'<<acc.amt<<'\n';

		data.close();

	  cout<<" \n\n\n\n\n ITEM ADDED......!! ";
		 cout<<"\n\n\n\t\t\tClick y to Add one more  :  "    ;
		cin>>ch;
                } else {
                    cout << "Invalid input. Please enter a valid price!!! ";
                    cin.clear();
                    cin.ignore(100, '\n');
                    //getch();
                    exit(0);
                }

	
	}

  }
  }
		break;
	case 4:while(ch=='y')
	{
	data.open("itm.txt",ios::in);
	cout << "\n\n\t\tITEMS IN POTS CATEGORY:\n";
	cout<<"\n Enter ITEM ID: ";
    cin>>acc.num;
    if(!data)
	flaggg=2;
    while(!data.eof() && flaggg==0)
	{
	  data.getline(num,50,'|');
	  data.getline(name,50,'|');
	  data.getline(stock,50,'|');
      data.getline(charr,50,'\n');
      a=atoi(charr);
      if((strcmp(acc.num,num))==0)
      {
	flaggg=1;
	cout<<"\n\n\t\t ITEM WITH THE SAME NUMBER ALREADY EXISTS..!!!";
	getch();
	  }
	  if(data.eof())
		break;
	}
	data.close();
	if(flaggg==1)
		break;
	if(flaggg != 1)
	{

	cout<<"\n Enter  Name (max 50 characters)       : ";
	gets(acc.name);
	cout<<"\n Enter Stock: ";
	gets(acc.stock);
	//cin>>acc.name;
	 cout << "\n Enter Price: ";
            int validPrice = 0;
            while (!validPrice) {
                if (cin >> acc.amt) {
                    validPrice = 1;
                    data.open("itm.txt",ios::app);
		//sprintf(Buffer,"|%s|%s|%lu|#",acc.num,acc.name,acc.amt);
		data<<acc.num<<'|'<<acc.name<<'|'<<acc.stock<<'|'<<acc.amt<<'\n';

		data.close();

	  cout<<" \n\n\n\n\n ITEM ADDED......!! ";
		 cout<<"\n\n\n\t\t\tClick y to Add one more  :  "    ;
		cin>>ch;
                } else {
                    cout << "Invalid input. Please enter a valid price!!! ";
                    cin.clear();
                    cin.ignore(100, '\n');
                    //getch();
                    exit(0);
                }

	
	}

  }

  }
		break;
	case 5:while(ch=='y')
	{
	data.open("itm.txt",ios::in);
	cout << "\n\n\t\tITEMS IN FERTILIZERS CATEGORY:\n";
	cout<<"\n Enter ITEM ID: ";
    cin>>acc.num;
    if(!data)
	flaggg=2;
    while(!data.eof() && flaggg==0)
	{
	  data.getline(num,50,'|');
	  data.getline(name,50,'|');
	  data.getline(stock,50,'|');
      data.getline(charr,50,'\n');
      a=atoi(charr);
      if((strcmp(acc.num,num))==0)
      {
	flaggg=1;
	cout<<"\n\n\t\t ITEM WITH THE SAME NUMBER ALREADY EXISTS..!!!";
	getch();
	  }
	  if(data.eof())
		break;
	}
	data.close();
	if(flaggg==1)
		break;
	if(flaggg != 1)
	{

	cout<<"\n Enter  Name (max 50 characters)       : ";
	gets(acc.name);
	cout<<"\n Enter Stock: ";
	gets(acc.stock);
	//cin>>acc.name;
	 cout << "\n Enter Price: ";
            int validPrice = 0;
            while (!validPrice) {
                if (cin >> acc.amt) {
                    validPrice = 1;
                    data.open("itm.txt",ios::app);
		//sprintf(Buffer,"|%s|%s|%lu|#",acc.num,acc.name,acc.amt);
		data<<acc.num<<'|'<<acc.name<<'|'<<acc.stock<<'|'<<acc.amt<<'\n';

		data.close();

	  cout<<" \n\n\n\n\n ITEM ADDED......!! ";
		 cout<<"\n\n\n\t\t\tClick y to Add one more  :  "    ;
		cin>>ch;
                } else {
                    cout << "Invalid input. Please enter a valid price!!! ";
                    cin.clear();
                    cin.ignore(100, '\n');
                    //getch();
                    exit(0);
                }

	
	}

  }
  }
		break;
	case 6:while(ch=='y')
	{
	data.open("itm.txt",ios::in);
	cout << "\n\n\t\tITEMS IN TOOLS CATEGORY:\n";
	cout<<"\n Enter ITEM ID: ";
    cin>>acc.num;
    if(!data)
	flaggg=2;
    while(!data.eof() && flaggg==0)
	{
	  data.getline(num,50,'|');
	  data.getline(name,50,'|');
	  data.getline(stock,50,'|');
      data.getline(charr,50,'\n');
      a=atoi(charr);
      if((strcmp(acc.num,num))==0)
      {
	flaggg=1;
	cout<<"\n\n\t\t ITEM WITH THE SAME NUMBER ALREADY EXISTS..!!!";
	getch();
	  }
	  if(data.eof())
		break;
	}
	data.close();
	if(flaggg==1)
		break;
	if(flaggg != 1)
	{

	cout<<"\n Enter  Name (max 50 characters)       : ";
	gets(acc.name);
	cout<<"\n Enter Stock: ";
	gets(acc.stock);
	//cin>>acc.name;
	 cout << "\n Enter Price: ";
            int validPrice = 0;
            while (!validPrice) {
                if (cin >> acc.amt) {
                    validPrice = 1;
                    data.open("itm.txt",ios::app);
		//sprintf(Buffer,"|%s|%s|%lu|#",acc.num,acc.name,acc.amt);
		data<<acc.num<<'|'<<acc.name<<'|'<<acc.stock<<'|'<<acc.amt<<'\n';

		data.close();

	  cout<<" \n\n\n\n\n ITEM ADDED......!! ";
		 cout<<"\n\n\n\t\t\tClick y to Add one more  :  "    ;
		cin>>ch;
                } else {
                    cout << "Invalid input. Please enter a valid price!!! ";
                    cin.clear();
                    cin.ignore(100, '\n');
                    //getch();
                    exit(0);
                }

	
	}

  }
  }
		break;
	case 7:exit(0);
		break;

}

  }
 void viewitems()
 {
		clrscr();
		cout<<"\n\n\t\tDISPLAYING ALL ITEMS......................\n\n";
		data.open("itm.txt",ios::in);
		cout<<"\n ITEM NO   \t   ITEM NAME   \t\t   STOCK   \t   ITEM COST\n";
		cout<<"\n******************************************************************\n";


	while(!data.eof())
				{

				data.getline(acc.num,50,'|');
				data.getline(acc.name,50,'|');
				data.getline(acc.stock,50,'|');
				data.getline(charr,50,'\n');
				acc.amt=atoi(charr);

		//		cout<<"READIIIIIIIIIIIIIIIIIIIIIIIIIIIIIING BUFFFFFFFFFFFFFFFFFFFFFFER";
			if(data.eof())
					 break;

				//	sscanf(Baf,"|%[^|]|%[^|]|%[^|]",acc.num,acc.name,acc.amt);
					for(int i=0;i<strlen(Baf);i++)
					{
						cout<<endl<<Baf[i]<<" ";
					}
				cout<<"\n "<<acc.num<<"   \t     "<<acc.name<<"   \t     "<<acc.stock<<"   \t     "<<acc.amt;
			}
			data.close();
			getch();


 }
 
 void viewitems1()
 {
 	clrscr();
		cout<<"\n\n\t\tDISPLAYING ALL ITEMS......................\n\n";
		data.open("itm.txt",ios::in);
		cout<<"\n ITEM NO   \t   ITEM NAME   \t\t   STOCK   \t   ITEM COST\n";
		cout<<"\n******************************************************************\n";


	while(!data.eof())
				{

				data.getline(acc.num,50,'|');
				data.getline(acc.name,50,'|');
				data.getline(acc.stock,50,'|');
				data.getline(charr,50,'\n');
				acc.amt=atoi(charr);

		//cout<<"READIIIIIIIIIIIIIIIIIIIIIIIIIIIIIING BUFFFFFFFFFFFFFFFFFFFFFFER";
			if(data.eof())
					 break;

				//sscanf(Baf,"|%[^|]|%[^|]|%[^|]",acc.num,acc.name,acc.amt);
					for(int i=0;i<strlen(Baf);i++)
					{
						cout<<endl<<Baf[i]<<" ";
					}
				cout<<"\n "<<acc.num<<"   \t     "<<acc.name<<"   \t     "<<acc.stock<<"   \t     "<<acc.amt;
			}
			data.close();
			getch();
 }
void searchitem()
{
	clrscr();
	char itno[20],baa[50],num[20],name[20],charr[20],stock[20];
	unsigned long int a;
	int flaggg=0;
	fstream ff;
	ff.open("itm.txt",ios::in);
	cout<<"\n\n\t Enter ITEM NUMBER : ";
	cin>>itno;
	while(!ff.eof())
	{
	  ff.getline(num,50,'|');
	  ff.getline(name,50,'|');
	  ff.getline(stock,50,'|');
      ff.getline(charr,50,'\n');
      a=atoi(charr);
      if((strcmp(itno,num))==0)
      {
	flaggg=1;
	cout<<"\n\n\tITEM NAME : "<<name<<"\n\n\tSTOCK : "<<stock<<"\n\n\tITEM COST : "<<a;
	  }
	  if(ff.eof())
		break;
	}
	if(flaggg == 0)
		cout<<"\n\n\t\tITEM NOT FOUND :( ";
	 getch();
		ff.close();

}
void welcome()
{

//textcolor(WHITE+LIGHTGRAY);
	gotoxy(20,9);
	cout<<"NURSERY MANAGEMENT SYSTEM";
	gotoxy(20,12);
	cout<<"PROJECT DEVELOPED BY:  ";
	gotoxy(20,14);
	setcolor(GREEN);
	cout<<"NIKHITHA AR";
	gotoxy(20,17);
	cout<<"VARSHA S";
	gotoxy(20,18);
	cout<<"VYSHNAVI P";

  gotoxy(20,24);
  cout<<"PRESS ANY KEY TO CONTINUE";
  getch();
}




int main()
{
    int m,ch,chh;
    int i, j = 1, gd = DETECT, gm;
    char num[20],name[20];//,amount[20];

    unsigned int amount;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 //welcome();
 clrscr();


   clearviewport();
  // closegraph();
 setcolor(1);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);

 outtextxy(70,70,"\nWELCOME TO OUR NURSERY");
 setcolor(8);
 outtextxy(150,150,"\n 1.Customer");
 outtextxy(150,200,"\n 2.Manager");
 outtextxy(150,250,"\n 3.Display");
 outtextxy(150,300,"\n 4.Exit");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
 outtextxy(120,350,"\n ENTER YOUR CHOICE:  ");

 gotoxy(75,24);
 cin>>ch;
clearviewport();
//clrscr();
 textcolor(BLACK);
    switch(ch)
    {
	 case 1:
			do{

			 clrscr();
			 cout<<"\n\n\t\tCUSTOMER CART\n\n\n";
			 setcolor(8);
			 cout<<"\n\n Press 1 for Add Items into CART";
			 cout<<"\n\n Press 2 for Viewing Items of CART";
			 cout<<"\n\n Press 3 for Removing Items from CART";
			 cout<<"\n\n Press 4 for Search for an ITEM in CART";
			 cout<<"\n\n Press 5 to GO BACK";
			 cout<<"\n\n\n\n\t\t PRESS 6 TO PAY THE BILL "    ;
			 cout<<"\n\n\n\n\t Enter ur Choice : ";
			 cin>>chh;
			 switch(chh)
			{
					case 1:
							clrscr();
							cout<<"\n\t\tADDING ITEMS INTO CART...........\n\n";
							cout<<"\nEnter no of ITEMS : ";
							cin>>no;
						    if(no<=10)
						    {
						  for(int l=0;l<no;l++)
						  rec[l].flag=0;
						 for(int i=0;i<no;i++)
						 {
							int ff=0;
							cout<<"\n  Enter Item No : ";
							cin>>num;
							char Baf[80];
							data.open("itm.txt",ios::in);

							while(!data.eof())
									{
									if(data.eof())
											 break;

										data.getline(acc.num,50,'|');
										data.getline(acc.name,50,'|');
										data.getline(acc.stock,50,'|');
										data.getline(charr,50,'\n');
											acc.amt=atoi(charr);

										for(int i=0;i<strlen(Baf);i++)
										{
												cout<<Baf[i]<<" ";
										}

										if(strcmp(acc.num,num)==0)
										{
												ff=1;
												strcpy(name,acc.name);
												amount = acc.amt;
												cout<<"\n\t NAME :"<<name<<"\n\t AMOUNT :"<<amount<<"\n\n";
													total = total + amount;

										}
									}
									data.close();


						 if(ff==1)
						{

							m=atoi(num);
							k=hash(m);
							cout<<"address: "<<k<<"\n";
							if(rec[k].flag==0)
							{
							    strcpy(rec[k].name,name);
							    strcpy(rec[k].num,num);
							    //strcpy(rec[k].stock,stock);
							    //strcpy(rec[k].amount,amount);
							    rec[k].amount=amount;
								rec[k].flag=1;
							}
							else
							{
							    for(int j=k+1;j%10<10;j++)
							    {
									if(rec[j%10].flag==0)
									{
										strcpy(rec[j%10].name,name);
										strcpy(rec[j%10].num,num);
										//strcpy(rec[k].stock,stock);
										//strcpy(rec[j%10].amount,amount);
										rec[j%10].amount=amount;
										rec[j%10].flag=1;
										break;
									}
							    }
							}
						  }
						  else
							cout<<"\n\n\t\t\ ITEM DOESNT EXISTS..!!!!!!";
						 }
						 /* cout<<"CART ITEMS : \n";
						  for(i=0;i<10;i++)
						  {
						  if(rec[i].flag==1)
						  {
							cout<<rec[i].name<<"\t"<<rec[i].num<<"\t"<<rec[i].amount<<"\n";
							}
						 else
						 cout<<"## \n";
						 }
						 */
						    cout<<"\n\n\tTOTAL AMOUNT TO BE PAID : "<<total;
						    fstream f1;
						    f1.open("ca.txt",ios::out);
						    for(i=0;i<10;i++)
							{
							    if(rec[i].flag==0)
							    f1<<"#|#"<<"\n";
							    else
							    f1<<rec[i].name<<"|"<<rec[i].num<<"|"<<rec[i].amount<<"\n";
							}
							f1.close();
						}getch();
					   break;
			case 2:disp();
					break;
			case 3:deletee();
					break;
			case 4:search();
					break;
			case 5:main();break;	
			//default: cout<<"\n\n\t\tPLEASE ENTER A VALID CHOICE"	;
			case 6:
				clrscr();
				fstream f12;
				cout<<"\n\n\n\n\n\n\t\t       Your TOTAL BILL AMOUNT : "<<total;
				
				f12.open("ca.txt",ios::out);
					for(int i=0;i<10;i++)
					{
						if(rec[i].flag==0)
							f12<<"#|#"<<"\n";
						else
							 {
							 rec[i].flag=0;
							  strcpy(rec[i].num,"zzzzzzzzzzzzzzzzzzz");
							  f12<<"#|#"<<"\n";
							}
					}
						f12.close();
		      total = 0;
		      cout<<"\n\n\n\n\n\n  _______________________________________________________________________";
		      cout<<"\n\n       NOTE: For Indoor plants maintain a temperature between 65-75 F        ";
		      cout<<"\n\n  _______________________________________________________________________";
			cout<<"\n\n\n\n\n\n\n\t\t     THANK YOU FOR SHOPPING WITH US :)";
		      getch();

					break;




			}
		}while(chh!=5);
			   break;

		case 2:
//			do
//			{

		    clrscr();
			cout<<"\n\n\t\tLOGINTO MANAGER PAGE\n\n\n";
			char input_id[50],input_password[50];
		    cout<<"\nEnter Manager ID: ";
		    cin>>input_id;
		    cout<<"\nEnter Password: ";
		    cin>>input_password;
		    if(strcmp(input_id,"100")==0 && strcmp(input_password,"varsha")==0)
		    {
			cout<<"\n\n\t\tWELCOME MANAGER\n\n \n";
		}
		else
		{
			cout<<"Invalid password\n";
			cout<<"Enter 1 to exit,any other continue";
			int a;
			cin>>a;
			if(a==1)
			main();
		}
		do{
			clrscr();
			cout<<"\n\n\t\tWELCOME MANAGER\n\n \n";
			cout<<"\n\n Press 1 for ADDING ITEMS";
			cout<<"\n\n Press 2 to Search for an ITEM";
			cout<<"\n\n Press 3 to Display the ITEM";
			cout<<"\n\n Press 4 to go BACK";
			cout<<"\n\n\t Enter ur Choice : ";
			cin>>chh;
			  switch(chh)
				 {
					 case 1:additems();
							break;	 
					case 2:searchitem();
							break;
					case 3: viewitems1();
							//main();
							break;
					case 4: main();
							break;
					default:cout<<"\n\n\t\tENTER A VALID CHOICE :( ";
					exit(0);
					}
			}while(chh!=4);
			return 0;
				     break;

		case 3:
					 viewitems();
					 main();
					break;
		case 4:
				exit(0);
}
//return 0;
}
