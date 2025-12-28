#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <iomanip>

using namespace std;

/// MENU FUNCTIONS
int seeWhatKey(); 
void displayMenu( int selected );

/// LOAD SAVE FUNCTIONS
void loadExpenses();
void saveExpenses();
void loadSub();
void saveSub();

/// MAIN MENU FUNCTIONS
void addExpenses();
void addSubcription();
void deleteExp_Sub();
void viewExpenses();
void fullChartOfExpenses();

/// SUBFUNCTIONS
void deleteExpense();
void deleteSub();

/// CHART FUNCTIONS
void getYear();
int choseYear();


int num_options = 6;
int selected_main = 0;

struct Expense{
    string category;
    double amount;
    string date;
};

struct Subscription{
    string category;
    double amount;
    string start_month;
};

vector<Expense> Expenses;
vector<Subscription> Subcriptions;

int main()
{
    loadExpenses();
    loadSub();

    Sleep(1500);

    while( true )
    {
    
        displayMenu( selected_main );

        int input = seeWhatKey();

        if( input == 72 )
        {
            if ( selected_main == 0 )
                selected_main = num_options - 1 ;
            else
                 selected_main--;
        }

        if( input == 80 )
        {
            if( selected_main == num_options - 1 )
                selected_main = 0 ;
            else
                 selected_main++;
        }
        
        if( input == 13 )
        {
            switch (selected_main)
            {
            case 0:
                addExpenses();
                break;
            case 1:
                addSubcription();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                fullChartOfExpenses();
                break;
            case 4:
                deleteExp_Sub( );
                break;
            case 5:
                saveExpenses();
                saveSub();
                cout<< "Goodbye ! ";
                return 0;

            default:
                break;
            }
        }
    }
    return 0;
}

int seeWhatKey()
{
    int ch = _getch();

    if( ch == 224 )
    {
        ch = _getch();

        if( ch == 72 )
            return ch;
        if( ch == 80 )
            return ch;
    }

    if( ch == 13 )
    {
        return ch;
    }

    cout << " INVALID INPUT! ";
    return 0;
}
void displayMenu( int selected )
{
    system("cls");

    cout << "========================================\n";
    cout << "           EXPENSE TRACKER\n";
    cout << "========================================\n\n";

    string menu_options[] = {
        "Add Expense",
        "Add Subcription",
        "View Expenses ",
        "View Expenses - Chart",
        "Delete Expense / Subcription",
        "Exit"
    };

    for(int i = 0 ; i < num_options ; i++)
    {
        if( i == selected )
            cout << " >> " << menu_options[i] << " << " << '\n';
        else
            cout << "    " << menu_options[i] << "    " << '\n';
    }
    
    cout << "========================================\n\n";
}

void loadSub()
{
    ifstream fin("subs.txt");

    if( !fin )
        {
            cout << "No past subscriptions!";
            return;
        }
    
    Subscription newsub;

    while( getline( fin , newsub.category))
    {
        fin >> newsub.amount;
        fin.ignore();
        getline(fin, newsub.start_month);

        Subcriptions.push_back(newsub);
    }

    fin.close();

    if( !Subcriptions.empty() )
    {
        cout<< "Loaded " << Subcriptions.size() << " subscriptions from file!" <<'\n';
    }

}
void loadExpenses()
{
    ifstream fin("expenses.txt");

    if( !fin )
        {
            cout << "No past expenses!";
            return;
        }
    
    Expense newExpense;

    while( getline( fin , newExpense.category))
    {
        fin >> newExpense.amount;
        fin.ignore();
        getline(fin, newExpense.date);

        Expenses.push_back(newExpense);
    }

    fin.close();

    if( !Expenses.empty() )
    {
        cout<< "Loaded " << Expenses.size() << " expenses from file!" <<'\n';
    }

}

void saveSub()
{
    ofstream fout("subs.txt");

    for(int i = 0 ; i < Subcriptions.size() ; i++ )
    {
        fout << Subcriptions[i].category << '\n';
        fout << Subcriptions[i].amount << '\n';
        fout << Subcriptions[i].start_month << '\n';
    }

    fout.close();

    cout << "Subscriptions Loaded! \n" ; 
}
void saveExpenses()
{
    ofstream fout("expenses.txt");

    for(int i = 0 ; i < Expenses.size() ; i++ )
    {
        fout << Expenses[i].category << '\n';
        fout << Expenses[i].amount << '\n';
        fout << Expenses[i].date << '\n';
    }

    fout.close();

    cout << "Expenses Loaded! \n" ; 
}

void addExpenses()
{
    Expense newExpense;

    cout << "========================================\n";
    cout << "              New expense ! \n";
    cout << "========================================\n";
    cout << "        - introduce the following- \n";

    cout <<  " CATEGORY of the expense  \n" ;
    cout << " Please chose any of the following -> food / travel / house / family / other : ";
    getline(cin , newExpense.category );

    cout << " AMOUNT of the expense :" ;
    cin >> newExpense.amount;
    cin.ignore();

    cout << " DATE of the expense (YYYY-MM-DD) :  " ;
    getline(cin , newExpense.date );
    if(newExpense.date.size() != 10)
        {
            cout << "\n========================================\n"; 
            cout << "       Expense introduced incorectly! \n";
        }
    else
       {
            Expenses.push_back(newExpense);
            cout << "\n========================================\n"; 
            cout << "               EXPENSE SAVED!";
            cout << "\n========================================\n"; 
       } 

    cout << "\n Press any key to go back to the menu....";
    _getch();

    return;
    
}
void addSubcription()
{
    Subscription newsub;

    cout << "========================================\n";
    cout << "            New subscription ! \n";
    cout << "========================================\n";
    cout << "        - introduce the following- \n";

    cout <<  " CATEGORY of the expense  \n" ;
    cout << " Please chose any of the following -> house / television / rent / other : ";
    
    getline(cin , newsub.category);

    cout << " AMOUNT of the subscription : ";
    cin >> newsub.amount;

    cin.ignore();

    cout << " YEAR AND MONTH in which the subscription starts (YYYY-MM) :" ; 
    getline(cin , newsub.start_month);

    Subcriptions.push_back(newsub);

    cout << "\n========================================\n"; 
    cout << "            SUBSCRIPTION SAVED!";
    cout << "\n========================================\n"; 

    cout << "\n Press any key to go back to the menu....";
    _getch();
    

}

void deleteExp_Sub()
{
    string exp_sub_choice[] = {
        "Delete Expense",
        "Delete Subscription",
        "Exit"
    };
    
    int choice = 0, done = 0;

    while ( done == 0 )
    {
        system("cls");

        cout << "    DELETE EXPENSES / SUBSCRIPTION\n";
        cout << "========================================\n";

        for(int i = 0 ; i < 3 ; i++)
        {
            if(i == choice)
                cout << " >> " << exp_sub_choice[i] << " << " << '\n';
            else
                cout << "    " << exp_sub_choice[i] << "    " << '\n';
        }

        int input = seeWhatKey();

        if( input == 72 )
            {
                if ( choice == 0 )
                    choice = 2 ;
                else
                    choice--;
            }

        if( input == 80 )
            {
                if( choice == 2 )
                    choice= 0 ;
                else
                    choice++;
            }
        
        if( input == 13 )
        {
            switch(choice)
            {
                case 0 :
                    deleteExpense();
                    done=1;
                    break;
                case 1 :
                    deleteSub();
                    done=1;
                    break;
                case 2 :
                    done=1;
                    return ;
            }
        }
    }
}
void deleteExpense()
{
    int choice = 0, done = 0;

    if(Expenses.empty()) {
        cout << "No expenses to delete!\n";
        cout << "Press any key...";
        _getch();
        return;
    }

    while( done == 0 )
    {
        system("cls");

        cout << "            DELETE EXPENSES             \n";
        cout << "========================================\n";
        cout << " CATEGORY ------ AMOUNT --------- DATE\n";

        for(int i =0 ; i < Expenses.size() ; i++)
        {
            if( choice == i )
            cout<< "  >>  " <<Expenses[i].category << "         " << Expenses[i].amount << "         " << Expenses[i].date << " <<" << '\n';
            else
            cout << "      " << Expenses[i].category << "         " << Expenses[i].amount << "         "<< Expenses[i].date << "      " << '\n';
        }

        int input = seeWhatKey();

        if( input == 72 )
        {
            if( choice == 0 )
                choice = Expenses.size() - 1;
            else
                choice--;
        }
        
        if( input == 80 )
        {
            if( choice == Expenses.size() - 1 )
                choice = 0;
            else
                choice++;
        }

        if( input == 13 )
        {
            Expenses.erase( Expenses.begin() + choice );
            done=1;
        }
        cout << "\n========================================\n";
        cout << "       Expense deleted succesfully!\n";
        cout << "========================================\n";
        cout << "\n Press any key to go back to the menu....";
    }
    _getch();
    return;
}
void deleteSub()
{
    int choice = 0, done = 0;

    if(Subcriptions.empty()) {
        cout << "No subscriptions to delete!\n";
        cout << "Press any key...";
        _getch();
        return;
    }

    while( done == 0 )
    {
        system("cls");

        cout << "          DELETE SUBSCRIPTIONS             \n";
        cout << "========================================\n";
        cout << " CATEGORY ------ AMOUNT --------- DATE\n";

        for(int i =0 ; i < Subcriptions.size() ; i++)
        {
            if( choice == i )
            cout<< "  >>  " <<Subcriptions[i].category << "         " << Subcriptions[i].amount << "         " << Subcriptions[i].start_month << " <<" << '\n';
            else
            cout << "      " << Subcriptions[i].category << "         " << Subcriptions[i].amount << "         "<< Subcriptions[i].start_month << "      " << '\n';
        }

        int input = seeWhatKey();

        if( input == 72 )
        {
            if( choice == 0 )
                choice = Subcriptions.size() - 1;
            else
                choice--;
        }
        
        if( input == 80 )
        {
            if( choice == Subcriptions.size() - 1 )
                choice = 0;
            else
                choice++;
        }

        if( input == 13 )
        {
            Subcriptions.erase( Subcriptions.begin() + choice );
            done=1;
        }
        cout << "\n========================================\n";
        cout << "     Subscription deleted succesfully!\n";
        cout << "========================================\n";
        cout << "\n Press any key to go back to the menu....";
    }
    _getch();
    return;
}

void viewExpenses()
{
    cout << "              EXPENSES MADE! \n";
    cout << "========================================\n";
    cout << " CATEGORY ------- AMOUNT ---------- DATE\n";

    for(int i = 0 ; i < Expenses.size() ; i++)
    {
        cout << "   " << Expenses[i].category << "         " << Expenses[i].amount << "         " << Expenses[i].date << '\n';
    }

    cout << "========================================\n";
    cout << "\n Press any key to go back to the menu....";
    _getch();
    return;
}

int getYearFromDate(const string& date)
{
    return stoi(date.substr(0, 4));
}

int getMonthFromDate(const string& date)
{
    return stoi(date.substr(5 , 2));
}

vector<int> getAvaliableYears(const vector<Expense>& Expenses)
{
    vector<int> years;

    for(int i=0 ; i < Expenses.size() ; i++ )
    {
        int year = getYearFromDate(Expenses[i].date);
        bool exist = false;

        for(int j = 0 ; j < years.size() ; j++ )
        {
            if(years[j] == year)
                {
                    exist=true ; 
                    break;
                }
        }
        if(exist == false)
        years.push_back(year);
    }
    return years;
}

void fullChartOfExpenses()
{
    vector<int> years = getAvaliableYears(Expenses);

    if(years.empty())
    {
        cout << " No expenses yet!\n";
        cout << " Press any key to go back\n";
        _getch();
        return;
    }

    int done = 0, choice = 0 , selected_year;
    while( done == 0 )
    {
        system("cls");
        cout << "      Select the Year\n";
        cout << "===========================\n";
        for( int i= 0 ; i < years.size() ; i++)
        {
            if( i == choice)
                cout << " >> " << years[i] << " << \n";
            else
                cout << "    " << years[i] << '\n';
        }

        int input = seeWhatKey();

        if(input == 72)
        {
            if(choice == 0)
                choice = years.size() - 1;
            else
                choice--;
        }
        if(input == 80)
        {
            if(choice == years.size() - 1)
                choice = 0;
            else
                choice++;
        }
        if(input == 13)
        {
            selected_year = years[choice];
            done = 1;
        }
    }
    system("cls");
    

     cout << "================= EXPENSE DASHBOARD =======================\n";
     cout << "            EXPENSE TREND FOR : " << selected_year << '\n' << '\n';

    double monthlyTotals[12] = {0};
    for(int i = 0 ; i < Expenses.size() ; i++)
    {
        if(getYearFromDate(Expenses[i].date) == selected_year)
        {
            monthlyTotals[ getMonthFromDate(Expenses[i].date) - 1 ] += Expenses[i].amount;
        }
    }
    for(int i = 0 ; i < Subcriptions.size() ; i++)
    {
        int subYear = stoi(Subcriptions[i].start_month.substr(0, 4));  
        int subMonth = stoi(Subcriptions[i].start_month.substr(5, 2));

        if( subYear == selected_year)
        {
            for(int m =subMonth - 1 ; m < 12 ; m++ )
            {
                monthlyTotals[m] += Subcriptions[i].amount;
            }
        }
        else if( subYear < selected_year)
        {
            for(int m = 0 ; m <= 12 ; m++)
            monthlyTotals[m] += Subcriptions[i].amount;
        }
    }

    int yScale[] = {500 , 400 , 300 , 200, 100 , 0};
    for(int y = 0 ; y < 6 ; y++)
    {
        cout << setw(4) << yScale[y] << " | " ;

        for(int i = 0 ; i <= 11 ; i++)
        {
            if(monthlyTotals[i] >= yScale[y])
                cout<< " * ";
            else
                cout<< "   ";
        }
        cout<<'\n';
    }
    cout<<"     ";
    for(int i=1;i<=12;i++)
        cout<<"---";

    cout << '\n' ;

    string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        
    cout << "     ";
    for(int i = 0; i < 12; i++) 
        cout << months[i] << " ";
    cout<< '\n' ;
    cout << "\n========================================\n";
    
    double total=0, highest=-1, lowest=100000000;

    for(int i = 0 ; i < 12 ; i++)
    {
        total += monthlyTotals[i];
        if(highest < monthlyTotals[i])
            highest = monthlyTotals[i];
        if(lowest > monthlyTotals[i])
            lowest = monthlyTotals[i];
    }
    
    cout<< setw(15) << "Total spent : " << total << '\n';
    cout<< setw(15) << "Average / month : " << total / 12 << '\n';
    cout<< setw(15) << "Highest month : " << highest << '\n';
    cout<< setw(15) << "Lowest month : " << lowest << '\n';
  
    /// finish thing
    cout << "========================================\n";
    cout << "\n Press any key to go back to the menu....";
    _getch();
    return;
}