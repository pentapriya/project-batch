#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

#include"LMS.h"
using namespace std;

int main()
{
    char yes;
    string book_name;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"````````````LOGIN``````````"<<endl;
    cout<<"***************************"<<endl;
    do{
    cout<<"1.Admin Login"<<endl<<"2.Student Access"<<endl;
    int Login_Type;
    cout<<"Enter Login Type: ";
    cin>>Login_Type;
    switch(Login_Type)        
    {
        case 1:
        {
            cout<<"Hello, Admin "<<endl;
                int Pin=1234;
                int Input_Pin=0;
                int Warning=1;
                do
                {
                    cout<<"Enter Pin: ";
                    cin>>Input_Pin;
                    if(Input_Pin==Pin)
                    {
                        cout<<"Login Succesful"<<endl;
                    }
                    else
                    {
                        Warning++;
                        cout<<"Try Again"<<endl;
                    }
                }
                while(Warning<=3 && Input_Pin!=Pin);
                {
                    if(Warning>3)
                    {
                            cout<<"Your Account Is Blocked! "<<endl;
                            exit(0);
                    }
                }
                cout<<"-------------------------------------------------------------"<<endl;
                cout<<"--------------------------ADMIN MENU-------------------------"<<endl;
                cout<<"-------------------------------------------------------------"<<endl;
                do{
                 cout<<"1.Add Books" <<endl<<"2.display books"<<endl<<"3.Delete Books"<<endl<<"4.Search Book"<<endl<<
                 "5.Return Books "<<endl<<"6.Issue Book"<<endl<<"7.Exit"<<endl;
                
                 int Choice;
                 cout<<"Enter Your Choice: ";
                 cin>>Choice;
                 switch(Choice)
                 {
                    case 1:
                    {
                        
                        cout<<"**********************************"<<endl;
                        cout<<"------------ADD BOOKS-------------"<<endl;
                        cout<<"**********************************"<<endl;
                        do
                        {
                          addbooks library;
                          library.insert_books();
                          cout<<"do you want to append another book"<<endl;
                          cin>>yes;
                        }while(yes=='y');
                        break;
                    }
                    case 2:
                    {
                        cout<<"**************************************"<<endl;
                        cout<<"------------DISPLAY BOOKS-------------"<<endl;
                        cout<<"**************************************"<<endl;
                        addbooks library;
                        library.display_books();
                        break;
                    }
                    case 3:
                    {
                        cout<<"**********************************"<<endl;
                        cout<<"---------DELETE BOOK MENU---------"<<endl;
                        cout<<"**********************************"<<endl;
                        Delete library;
                        int choice, book_id;
                        string book_name;
                     do{
                        cout<<"Delete\n1. by id\n2. by name"<<endl;
                        cin>>choice;
                        
                        switch(choice)
                    	{
                    		case 1:
                    		    cout<<"Enter Book Id To Delete "<<endl;
                    		    cout<<"------------------------"<<endl;
                    			cout<<"Enter Book ID"<<endl;
                    		    cin>>book_id;
                    		    library.delete_bookId(book_id);
                    		    break;
                    
                    		case 2:
                    		    cout<<"Enter Book Name To Delete "<<endl;
                    		    cout<<"------------------------"<<endl;
                    		    cout<<"Enter Book name"<<endl;
                    			cin.ignore();
                    			getline(cin,book_name);
                    			transform(book_name.begin(),book_name.end(),book_name.begin(), ::toupper);
                    			library.delete_bookName(book_name);
                    			break;
                    		    
                    		default:
                    			cout<<"Invalid choice"<<endl;
                    			break;
                    	}
                    	cout<<"Do you want to delete another book"<<endl;
                    	cin>>yes;
                     }while(yes=='y');
    
                        break;
                    }
                    case 4:
                    {
                        cout<<"**********************************"<<endl;
                        cout<<"---------SEARCH BOOK MENU---------"<<endl;
                        cout<<"**********************************"<<endl;
                        Search library;
                    	string book_name, author_name;
                    	int choice,book_id;
                    	do
                    	{
                    	    cout<<"\nSearch Book\n1. by name\n2. by id\n3. by author"<<endl;
                            cin>>choice;
                    	    switch(choice)
                    	    {
                    	        case 1:
                    	        {
                    	            
                    	            cout<<"Enter Book Name To Search "<<endl;
                    		        cout<<"------------------------"<<endl;
                    	            cout<<"Enter Book name"<<endl;
                        			cin.ignore();
                        			getline(cin,book_name);
                        			transform(book_name.begin(),book_name.end(),book_name.begin(), ::toupper);
                        			library.search_bookname(book_name);
                    	            break;
                    	        }
                    	        case 2:
                    	        {
                    	            cout<<"Enter Book Id To Search "<<endl;
                    		        cout<<"------------------------"<<endl;
                    	            cout<<"Enter Book ID"<<endl;
                        		    cin>>book_id;
                        		    library.search_bookId(book_id);
                    	            break;
                    	        }
                    	        case 3:
                    	        {
                    	            cout<<"Enter Book Author To Search "<<endl;
                    		        cout<<"------------------------"<<endl;
                    	            cout<<"Enter Author name"<<endl;
                        		    cin.ignore();
                        		    getline(cin,author_name);
                        		    transform(author_name.begin(),author_name.end(),author_name.begin(), ::toupper);
                        		    library.search_author(author_name);
                    	            break;
                    	        }
                    	        default:
                    	        {
                    	            cout<<"Enter Valid Choice"<<endl;
                    	            break;
                    	        }
                    	    }
                    	    cout<<"do you want to search another book"<<endl;
                    	    cin>>yes;
                    	}while(yes=='y');
	
                        break;
                    }
                    case 5:
                    {
                        cout<<"******************************"<<endl;
                        cout<<"--------RETURN BOOK BOOK-------"<<endl;
                        cout<<"******************************"<<endl;
                     do{
                        returnBook rb;
                        rb.showdate();
                        rb.Return();
                        cout<<"Do you want to return another book"<<endl;
                        cin>>yes;
                       }while(yes=='y');
                        break;
                    }
                    case 6:
                    {
                        student s;
                        char ch;
                        string str;
                        fstream file;
                        int opt;
                        cout<<"**********************************************************************"<<endl;
                        cout<<"---------------------ISSUE BOOK MENU----------------------------------"<<endl;
                        cout<<"**********************************************************************"<<endl;
                        do{
                            cout<<"enter required choice: "<<endl<<"1.Add Data"<<endl<<"2.Display"<<endl<<"3.Search"<<endl<<"4.exit"<<endl;
                            cin>>opt;
                            switch(opt)
                            {
                                case 1:
                                {
                                    cout<<"******************************"<<endl;
                                    cout<<"---------ADD BOOK-------------"<<endl;
                                    cout<<"******************************"<<endl;
                                    cout<<"Enter Data "<<endl;
                    		        cout<<"-----------"<<endl;
                                   // file.open("text.txt",ios::out|ios::app);
                                    do
                                    {
                                        s.create();
                                        cout<<"do you want to enter another record(y/n)"<<endl;
                                        cin>>ch;
                                    }
                                    while(ch=='y');
                                    //file.close();
                                        
                                    break;
                                }
                                case 2:
                                {
                                    cout<<"******************************"<<endl;
                                    cout<<"-----DISPLAY ISSUED BOOK------"<<endl;
                                    cout<<"******************************"<<endl;
                                    cout<<"Display Issued Data "<<endl;
                    		        cout<<"-----------"<<endl;
                                   // file.open("text.txt",ios::in|ios::binary);
                                    s.display();
                                   // file.close();
                                    break;
                                }
                                case 3:
                                {
                                    cout<<"******************************"<<endl;
                                    cout<<"---------SEARCH BOOK----------"<<endl;
                                    cout<<"******************************"<<endl;
                                    cout<<"Search book by its name"<<endl;
                                  //  file.open("text.txt");
                                    cout<<"Enter Book name"<<endl;
                                    cin.ignore();
                                    getline(cin,book_name);
                                    s.search_bookname(book_name);
                                  //  file.close();
                                    break;
                                }
                                case 4:
                                {
                                   
                                    break;
                                }
                                default:
                                {
                                    cout<<"Enter Valid Choice"<<endl;
                                    break;
                                }
                            }
                        cout<<"Do you want to issue another book";
                        cin>>yes;
                        }
                        while(yes=='y');
                        file.close();
                        break;
                    }
                    case 7:
                    {
                        
                        exit(0);
                    }
                    default:
                    {
                        cout<<"Enter Valid Choice"<<endl;
                        break;
                    }
                  
                 }
                cout<<"do u want to continue"<<endl;
                cin>>yes;
                }while(yes=='y');
            break;
        }
        case 2:
        {
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"--------------------------STUDENT MENU-------------------------"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
          do{
            cout<<"1.Search Book"<<endl<<"2.Display"<<endl<<"3.exit"<<endl;
            int choice;
            cout<<"Enter choice: ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    cout<<"**********************************************"<<endl;
                    cout<<"-----------------SEARCH BOOK------------------"<<endl;
                    cout<<"**********************************************"<<endl;
                    
                    Search library;
                	string book_name, author_name;
                	int choice,book_id;
                	do
                	{
                	    cout<<"\nSearch Book\n1. by name\n2. by id\n3. by author"<<endl;
                        cin>>choice;
                	    switch(choice)
                	    {
                	        case 1:
                	        {
                	            cout<<"Enter Book name: ";
                    			cin.ignore();
                    			getline(cin,book_name);
                    			library.search_bookname(book_name);
                	            break;
                	        }
                	        case 2:
                	        {
                	            cout<<"Enter Book ID: ";
                    		    cin>>book_id;
                    		    library.search_bookId(book_id);
                	            break;
                	        }
                	        case 3:
                	        {
                	            cout<<"Enter Author name: ";
                        		cin.ignore();
                        		getline(cin,author_name);
                        		library.search_author(author_name);
                        		break;
                	        }
                	        default:
                	        {
                	            cout<<"Enter Valid choice"<<endl;
                	        }
                	    }
                	   cout<<"do you want to search another book"<<endl;
                	   cin>>yes;
                	 }while(yes=='y');
                	    
                	 break;
                }
                case 2:
                {
                    cout<<"**************************************"<<endl;
                    cout<<"------------DISPLAY BOOKS-------------"<<endl;
                    cout<<"**************************************"<<endl;
                    addbooks library;
                    library.display_books();
                    break;
                }
                case 3:
                {
                    exit(0);
                }
                default:
                {
                    cout<<"Enter Valid Choice"<<endl;
                    break;
                }
            
            }
            cout<<"do you want to continue"<<endl;
            cin>>yes;
          }while(yes=='y');
        }
        
        default:
        {
           cout<<"Enter Valid Choice"<<endl;
           break;  
        }
    }
    cout<<"do you want to continue"<<endl;
    cin>>yes;
    }while(yes=='y');
}
