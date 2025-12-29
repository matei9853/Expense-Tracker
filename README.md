# Expense-Tracker
A much more developed project , keyboard driven C++ expense-tracker

## Features
- Add and delete Expenses
- Manage mothly Expenses
- Save and Load from files
- Keyboard controlled menu
- Yearly ASCII data chart

## What I Learned
- Desing a driven menu using keyboard input
- How to save information using file input/output
- How to visualize data using an ASCII graph
- How to separate and structure a longer code
- How to actually build something useful , not just competitive programming

## Screenshots

### Main menu
```
========================================
           EXPENSE TRACKER
========================================

 >> Add Expense <<
    Add Subscription
    View Expenses
    View Expenses - Chart
    Delete Expense / Subscription
    Exit

========================================
```
### Add Expense
```
========================================
              New expense !
========================================
        - introduce the following -

CATEGORY of the expense
Please chose any of the following -> food / travel / house / family / other :
travel

AMOUNT of the expense :
120

DATE of the expense (YYYY-MM-DD) :
2023-07-15

========================================
               EXPENSE SAVED!
========================================

Press any key to go back to the menu....
```
### View Expenses
```
              EXPENSES MADE!
========================================
 CATEGORY ------- AMOUNT ---------- DATE

 food            50.00        2023-06-10
 travel          120.00       2023-07-15
 house           300.00       2023-07-01

========================================
Press any key to go back to the menu....
```
### Expense Chart
```
================= EXPENSE DASHBOARD =======================
            EXPENSE TREND FOR : 2023

 500 |       * *
 400 |     * * *
 300 |     * * * *
 200 |   * * * * * *
 100 | * * * * * * * * * * *
   0 | -----------------------------------
       Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec

========================================
Total spent      : 470
Average / month  : 39.17
Highest month    : 120
Lowest month     : 50
========================================

Press any key to go back to the menu....
```
## Things To-Do
I know the project is not perfect but it was very usefull in my learning process , here are some things that i could have done better :
- better input validation
- export charts / category
- search a expense / subscription
- undo / confirm buttons

## Author 
Voicu Matei - 29.12.2025

