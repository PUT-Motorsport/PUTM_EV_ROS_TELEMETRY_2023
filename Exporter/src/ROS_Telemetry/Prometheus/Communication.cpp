#include <string.h>
#include <iostream>
#include <stdio.h>

#include "Communication.hpp"

Communication::semafora s1;
Communication::variable_labels labels{"Practice", "default", "Dry"};

void Set_driver()
{
    using namespace std;
    string driver;
    cin >> driver;

    for(auto registered_driver : Communication::sanity_check::Drivers)
    {
        if(driver == registered_driver)
        {
            labels.driver = driver;
        }
    }
    if(labels.driver == "default")
    {
        cout << "Invalid driver name" << endl;
    }
}

void Set_Run()
{
    using namespace std;
    string run;
    cin >> run;

    for(auto registered_Runs : Communication::sanity_check::Runs)
    {
        if(run == registered_Runs)
        {
            labels.run = run;
        }
    }
    if(labels.run == "default")
    {
        cout << "Invalid Run name" << endl;
    }
}

void Set_Condition()
{
    using namespace std;
    string condition;
    cin >> condition;

    for(auto registered_conditions : Communication::sanity_check::Condition)
    {
        if(condition == registered_conditions)
        {
            labels.condition = condition;
             cout << "Task 2 Condition changed to "<< condition << endl;
        }
    }
    if(labels.condition == "default")
    {
        cout << "Invalid Condition name" << endl;
    } 
}


void Read_Terminal_async()
{
    using namespace std;
    for(;;)
    {
        string input;
        cin >> input;
        
        if(input == "cdriver")
        {
           Set_driver();
           s1.change = true;
        }
        else if(input == "crun")
        {
            Set_Run();
            s1.change = true;
        }

        else if(input == "c")
        {
            Set_driver();
            Set_Run(); 
            Set_Condition();
            s1.change = true;
        }
        else if(input == "ccon")
        {
            Set_Condition();
            s1.change = true;
        }
    }
}