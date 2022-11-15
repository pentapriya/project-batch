#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
using namespace std;


class addbooks
{
    private:
     int books_count,book_id,count=0;
     string book_name,author;
     char ch;
     string line;
    
     public:
     
     //for inserting books into library
     void insert_books()
     {
        
         ofstream fout;
         ifstream fin;
         fout.open("database.txt",ios::app);
         fin.open("database.txt");
         
         //for finding no of records in file.
          
          ch=fin.get();
          while(!fin.eof())
          {
              count++;
              ch=fin.get();
          }
          fin.close();
          
        //addind new records to library   
         cout<<"enter no.of books to be added to library's bookslist"<<endl;
         cin>>books_count;
         for(int i=0;i<books_count;i++)
         {
            book_id=count+1;
            count++;
            cin.ignore();
            cout<<"Enter the name of the book: ";
            getline(cin,book_name);
            transform(book_name.begin(),book_name.end(),book_name.begin(), ::toupper);
            cout<<"Enter the Author Name: ";
            getline(cin,author);
             transform(author.begin(),author.end(),author.begin(), ::toupper);
            fout<<book_id<<" : "<<book_name<<": "<<author<<endl;
            cout<<"New Book Added Succesfully "<<endl;
          }
          fout.close();
      }
    
    void display_books()
    {
        ifstream ifile;
        ifile.open("database.txt");
        while(getline(ifile,line))
        {
            cout<<line<<endl;
        }
        ifile.close();
    }
};


class Delete
{
    protected:
    ifstream ifile;
    ofstream temp;
    smatch match;
    string line, name, id_dummy;
    int id, flag = 0;
    
    public:
    void delete_bookId(int book_id)
    {
        ifile.open("database.txt");
        temp.open("temp.txt");
		while(getline(ifile,line))
		    {
		        regex reg = regex("\\d+");
		        regex_search(line, match, reg);
		        for (string s : match) 
		        {
		            id = atoi(s.c_str());
		        }
		        if(id == book_id)
		        {
		            cout<<"Record successfully deleted"<<endl;
		            cout<<line<<endl;
		            flag++;
		        }
		        else
		        {
		            temp<<line<<endl;
		        }
		    }
		    if(flag == 0)
		    {
		        cout<<"Record not found"<<endl;
		    }
		        temp.close();
		        ifile.close();
		        remove("database.txt");
		        rename("temp.txt","database.txt");
    }
    
    void delete_bookName(string bookName)
    {
        ifile.open("database.txt");
        temp.open("temp.txt");
        while(getline(ifile,line))
		    {
		        stringstream strm(line);
		        getline(strm,id_dummy,':');
		        strm.ignore();
		        getline(strm,name,':');
		        if(name == bookName)
		        {
		            cout<<"Record successfully deleted"<<endl;
		            cout<<line<<endl;
		            flag++;
		        }
		        else
		        {
		            temp<<line<<endl;
		        }
		    }
			if(flag == 0)
			{
			    cout<<"Record not found"<<endl;
			}
			temp.close();
		    ifile.close();
		    remove("database.txt");
		    rename("temp.txt","database.txt");
    }
};



class returnBook
{
    private:
         int books_count,book_id;
         char book_name[15],author[20];
         
        int Day,Return_Day,Current_Day,d,day;
        int Month,Return_Month,Current_Month,m,month;
        int Year,Return_Year,Current_Year,y,year;
        
        void rectifyData()
        {
            if(Month>12)
            {
                Month-=12;
                Year++;
            }
            if(Month==1 || Month==3 || Month==5 || Month==7 || Month==8 || Month==10 || Month==12)
            {
                if(Day>31)
                {
                    Day-=31;
                    Month++;
                }
            }
            else if(Month==4 || Month==6 || Month==9 || Month==11)
                {
                    if(Day>30)
                    {
                        Day-=30;
                        Month++;
                    }
            }
            else
            {
                if(Year%4==0 && Year%100!=0 || Year%400==0)
                {
                    if(Day>29)
                    {
                        Day=Day-29;
                        Month++;
                    }
                }
                else
                {
                    if(Day>28)
                    {
                        Day-=28;
                        Month++;
                    }
                }
            }
            
            if(Return_Month>12)
            {
                Return_Month-=12;
                Return_Year++;
            }
            if(Return_Month==1 || Return_Month==3 || Return_Month==5 || Return_Month==7 || Return_Month==8 || Return_Month==10 || Return_Month==12)
            {
                if(Return_Day>31)
                {
                    Return_Day-=31;
                    Return_Month++;
                }
            }
            else if(Return_Month==4 || Return_Month==6 || Return_Month==9 || Return_Month==11)
                {
                    if(Return_Day>30)
                    {
                        Return_Day-=30;
                        Return_Month++;
                    }
            }
            else
            {
                if(Return_Year%4==0 && Return_Year%100!=0 || Return_Year%400==0)
                {
                    if(Return_Day>29)
                    {
                        Return_Day-=29;
                        Return_Month++;
                    }
                }
                else
                {
                    if(Return_Day>28)
                    {
                        Return_Day-=28;
                        Return_Month++;
                    }
                }
            }
        }
    public:
        returnBook()
        {
            cout<<"Enter the Book Received Day: ";
            cin>>d;
            cout<<"Enter the Book Received month: ";
            cin>>m;
            cout<<"Enter the Book Received Year: ";
            cin>>y;
            Day=d;
            Month=m;
            Year=y;
            rectifyData();
        }
        void showdate()
        {
            cout<<"Book Issued Date is: "<<Day<<"/"<<Month<<"/"<<Year<<endl;
            rectifyData();
        }
        void Return()
        {
            Return_Day=Day+15;
            Return_Month=Month;
            Return_Year=Year;
            rectifyData();
            cout<<"Book Return Date is : "<<Return_Day<<"/"<<Return_Month<<"/"<<Return_Year<<endl;
        
            cout<<"**************Checking For Penality*****************"<<endl;
            cout<<"----------------------------------------------------"<<endl;
            cout<<"1. Current Date id Between the Issue Date And Return Date the NO Penality"<<endl;
            cout<<"2. Current Date Is more then Return Date: "<<endl;
            int choice;
            cout<<"Enter Choice: ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    ofstream fout;
                    fout.open("database.txt",ios::app);
                        
                    cout<<"Enter Book Id: ";
                    cin>>book_id;
                    cin.ignore();
                    cout<<"Enter the name of the book: ";
                    cin.getline(book_name,15);
                    cout<<"Enter the Author Name: ";
                    cin.getline(author,20);
                    fout<<book_id<<"\t: "<<book_name<<": "<<author<<endl;
                    cout<<"Book Return Succesfully Completed "<<endl;
                    break;
                }
                case 2:
                {
                    cout<<"Enter Current Day: ";
                    cin>>Current_Day;
                    cout<<"Enter Current Month: ";
                    cin>>Current_Month;
                    cout<<"Enter Current Year: ";
                    cin>>Current_Year;
                    int year=Current_Year-Return_Year;
                    int month=Current_Month-Return_Month;
                    int day=Current_Day-Return_Day;
                    
                    year=year*365;
                    month=month*30;
                    int No_Of_Days=year+month+day;
                    int Penality=No_Of_Days*3;
                    
                    cout<<"The Money for the penality is: "<<Penality<<endl;
                    int Money;
                    cout<<"Enter Money Given By the User: ";
                    cin>>Money;
                    if(Penality==Money)
                    {
                        cout<<"Penality Cleared "<<endl;
                    }
                    else
                    if(Penality>Money)
                    {
                        cout<<"Still Bill Pending is: "<<Penality-Money<<endl;
                    }
                    else 
                    {
                        if(Penality<Money)
                        {
                            cout<<"Change for the user: "<<Money-Penality<<endl;
                        }
                        
                    }
                    ofstream fout;
                    fout.open("database.txt",ios::app);
                    
                    cout<<"Enter Book Id: ";
                    cin>>book_id;
                    cin.ignore();
                    cout<<"Enter the name of the book: ";
                    cin.getline(book_name,15);
                    cout<<"Enter the Author Name: ";
                    cin.getline(author,20);
                    fout<<book_id<<"\t: "<<book_name<<": "<<author<<endl;
                    cout<<"Book Return Succesfully Completed "<<endl;
                    break;
                }
                default:
                {
                    exit(0);
                }
            }
            
        }
            
};

class Search
{
	private:
	    int id;
		string line;
		string id_book, name_book, name_author;
		int flag = 0;
		ifstream file;
		smatch match;
	
	public:
	    
		void search_bookname(string book_name)
		{
		    file.open("database.txt");
		    while(getline(file,line))
		    {
		        stringstream strm(line);
		        getline(strm,id_book,':');
		        strm.ignore();
		        getline(strm,name_book,':');
		        strm.ignore();
		        if(name_book == book_name)
		        {
		            cout<<"\nBook ID   Book name     Author name"<<endl;
		            cout<<line<<endl;
		            flag++;
		        }
		    }
		    
			if(flag > 0)
			{
			    cout<<"Book found"<<endl;
			}
			else
			{
			    cout<<"Book not found"<<endl;
			}
			file.close();
		}
		
		void search_bookId(int book_id)
		{
		    file.open("database.txt");
		    while(getline(file,line))
		    {
		        regex reg = regex("\\d+");
		        regex_search(line, match, reg);
		        for (string s : match) 
		        {
		            id = atoi(s.c_str());
		        }
		        if(id == book_id)
		        {
		            cout<<"\nBook ID   Book name     Author name"<<endl;
		            cout<<line<<endl;
		            flag++;
		        }
		    }
		    if(flag > 0)
		    {
		        cout<<"Book found"<<endl;
		    }
		    else
		    {
		        cout<<"Book not found"<<endl;
		    }
		    file.close();
		}
		
		void search_author(string author_name)
		{
		    file.open("database.txt");
		    while(getline(file,line))
		    {
		        stringstream strm(line);
		        getline(strm,id_book,':');
		        strm.ignore();
		        getline(strm,name_book,':');
		        strm.ignore();
		        getline(strm,name_author);
		        if(name_author == author_name)
		        {
		            cout<<line<<endl;
		            flag++;
		        }
		    }
		    
			if(flag > 0)
			{
			    cout<<"Book found"<<endl;
			}
			else
			{
			    cout<<"Book not found"<<endl;
			}
			file.close();
		}
};	


class student:public Delete{
    private:
    string line;
    int book_id,student_id,id;
    string id_book,name_book,id_student,name_student,branch_student;
    int flag=0;
    fstream file;
    smatch match;
    char student_name[30],book_name[30],student_branch[30];
    public:
    void create()
    {
        fstream file;
        file.open("Text.txt",ios::out|ios::app);
        cout<<"enter bookid"<<endl;
        cin>>book_id;
        cout<<"enter student id"<<endl;
        cin>>student_id;
        cin.ignore();
        cout<<"enter book name"<<endl;
        cin.getline(book_name,30);
        cout<<"enter name"<<endl;
        cin.getline(student_name,30);
        cout<<"enter branch"<<endl;
        cin.getline(student_branch,30);
        file<<book_id<<"    : "<<book_name<<": "<<student_id<<": "<<student_name<<": "<<student_branch<<endl;
        file.close();
        delete_bookId(book_id);
        cout<<book_name<<" successfully issued to "<<student_name<<endl;
    }
    void search_bookname(string book_name)
    {
		    file.open("Text.txt");
		    while(getline(file,line))
		    {
		        stringstream strm(line);
		        getline(strm,id_book,':');
		        strm.ignore();
		        getline(strm,name_book,':');
		        strm.ignore();
		        if(name_book == book_name)
		        {
		            cout<<"\nBook ID   Book name  studentID  studentname  studentbranch"<<endl;
		            cout<<line<<endl;
		            flag++;
		        }
		    }
		    
			if(flag > 0)
			{
			    cout<<"Book found"<<endl;
			}
			else
			{
			    cout<<"Book not found"<<endl;
			}
			file.close();
	}
    void display(){
        fstream file;
        file.open("Text.txt",ios::in);
        string str;
        while(file.eof()=='\0'){
        getline(file,str);
        cout<<str<<endl;
        
        }
        file.close();
    }
    
};
