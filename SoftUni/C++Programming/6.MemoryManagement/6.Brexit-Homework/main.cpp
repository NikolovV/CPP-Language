#include <iostream>
#include <memory>
#include <string>
#include <set>

#include "VoterData.h"
#include "CollectorsMenu.h"
#include "CollectorControl.h"
#include "Collector.h"
#include "CollectorExport.h"
#include "Printer.h"

using namespace std;

const string voteCollectorPass = "12344321";
/**
 * Data hold voters
 */
shared_ptr<Data> g_voterData(new VoterData());
/**
 * hold pointer to data.
 */
shared_ptr<CollectorControl> collectorControl(new Collector(g_voterData));
/**
 * Export specific Voter data to main into a set.
 */
shared_ptr<CollectorExport> collectorExport(new CollectorExport(g_voterData));

/**
 * Menu functions.
 */
void main_menu();
void collector_menu();
/**
 * Collect voter data.
 */
Voter collect_voter_parameters();
/**
 * Function that print massage to user and return the user input.
 */
string ask_for(string msg);
/**
 * Clear input "cin" buffer;
 */
void clear_in_buufer();

int main()
{
    Printer printer;
    while (1)
    {
        /**
         * Main menu call.
         * @return 
         */
        main_menu();
        string userOption;
        cin >> userOption;
        clear_in_buufer();
        if (userOption.compare("1") == 0)
        {
            /**
             * Collect user vote and info, add to database. 
             * @return 
             */
            g_voterData->add_vote(collect_voter_parameters());

            // Some demo variable.
            // parameters: name, age, gender, city, ethnos, vote;
//            Voter tmp = Voter("Pesho", 18, MALE, "Sofia", "bulgarian", 1);
//            g_voterData->add_vote(tmp);
//            tmp = Voter("Gosho", 19, MALE, "Sofia", "greeck", 0);
//            g_voterData->add_vote(tmp);
//            tmp = Voter("Ginka", 19, FIMALE, "Burgas", "american", 0);
//            g_voterData->add_vote(tmp);
//            tmp = Voter("Minka", 20, FIMALE, "Varna", "german", 1);
//            g_voterData->add_vote(tmp);
        }
            /**
             * If user enter special password for the vote collectors call collector menu.
             * @return 
             */
        else if (userOption.compare(voteCollectorPass) == 0)
        {
            // Continue until pressing q.
            while (1)
            {
                collector_menu();
                int collectorChoice;
                cin >> collectorChoice;
                clear_in_buufer();
                switch (collectorChoice)
                {
                    case(RES_IN_PERCENT):
                    {
                        map<float, float> result = collectorControl->result_based_in_percent();
                        map<float, float>::iterator it = result.begin();
                        cout << "Stay: ";
                        cout << it->first;
                        cout << " %" << endl;
                        cout << "Leave: ";
                        cout << it->second;
                        cout << " %" << endl;
                        break;
                    }
                    case(RES_IN_NUMBERS):
                    {
                        int numberVoters = g_voterData->get_size();
                        cout << "There is " << numberVoters << " voters." << endl;
                        break;
                    }
                    case(RES_BASE_AGE):
                    {
                        cout << "Enter age: ";
                        int age;
                        cin >> age;
                        clear_in_buufer();
                        map<int, int> result = collectorControl->result_base_on_age(age);
                        map<int, int>::iterator it = result.begin();
                        if (it->first != -1)
                        {
                            cout << age << "y - Stay: " << it->first <<
                                    ", Leave: " << it->second << endl;
                            cout << endl;
                        }
                        break;
                    }
                    case(RES_BASE_NAME):
                    {
                        string value = ask_for("Enter Name: ");
                        map<int, int> result = collectorControl->result_base_on_name(value);
                        printer.print_info(value, result);
                        break;
                    }
                    case(RES_BASE_ETHNOS):
                    {
                        string value = ask_for("Enter Ethnos: ");
                        map<int, int> result = collectorControl->result_base_on_ethnos(value);
                        printer.print_info(value, result);
                        break;
                    }
                    case(RES_BASE_CITY):
                    {
                        string value = ask_for("Enter Living city/village: ");
                        map<int, int> result = collectorControl->result_base_on_city(value);
                        printer.print_info(value, result);
                        break;
                    }
                    case(ALL_POSSIBLE_AGE):
                    {
                        cout << "Age to choose: ";
                        set<int> allAges = collectorExport->all_possible_age();
                        printer.print_specific_voter_data<int>(allAges);
                        break;
                    }
                    case(ALL_POSSIBLE_NAME):
                    {
                        cout << "Names to choose: ";
                        set<string> allNames = collectorExport->all_possible_name();
                        printer.print_specific_voter_data<string>(allNames);
                        break;
                    }
                    case(ALL_POSSIBLE_ETHNOS):
                    {
                        cout << "Ethnos to choose: ";
                        set<string> allEthnos = collectorExport->all_possible_ethnos();
                        printer.print_specific_voter_data<string>(allEthnos);
                        break;
                    }
                    case(ALL_POSSIBLE_CITY):
                    {
                        cout << "Living city/village to choose: ";
                        set<string> allCity = collectorExport->all_possible_city();
                        printer.print_specific_voter_data<string>(allCity);
                        break;
                    }
                    default:
                    {
                        cout << "Wrong choise!" << endl;
                        break;
                    }
                }
                if (collectorChoice == EXIT)
                {
                    break;
                }
            }
        }
        else if (userOption.compare("q") == 0)
        {
            break;
        }
        else
        {
            cout << "Wrong input or password." << endl;
        }
    }

    return 0;
}

string ask_for(string msg)
{
    cout << msg;
    string value;
    getline(cin, value);
    return value;
}

void clear_in_buufer()
{
    cin.get();
    cin.clear();
    fflush(stdin);
}

void collector_menu()
{
    cout << "0. Exit" << endl;
    cout << "1. Results in percent" << endl;
    cout << "2. Results in numbers" << endl;
    cout << "3. Results based on age " << endl;
    cout << "4. Results based on name " << endl;
    cout << "5. Results based on Ethnos" << endl;
    cout << "6. Results based on living city/village" << endl;
    cout << "7. All possible for age" << endl;
    cout << "8. All possible for name" << endl;
    cout << "9. All possible for Ethnos" << endl;
    cout << "10. All possible for living city/village" << endl;
}

void main_menu()
{
    cout << "q. Exit" << endl;
    cout << "1. Make a vote." << endl;
    cout << "View result. (enter special password)" << endl;
}

Voter collect_voter_parameters()
{
    string name = ask_for("Enter name: ");
    int age = 0;
    while (age < 18)
    {
        cout << "Enter age: ";
        cin >> age;
        clear_in_buufer();
        if (age < 18)
        {
            cout << "You must be over 18 to vote!" << endl;
            continue;
        }
    }
    cout << "Enter gender (0 Male, 1 Female): ";
    bool gen;
    cin >> gen;
    Gender gender;
    if (gen == MALE)
    {
        gender = MALE;
    }
    else
    {
        gender = FIMALE;
    }
    clear_in_buufer();
    string city = ask_for("Enter living city/village: ");
    string ethons = ask_for("Enter Ethnos: ");
    cout << "Enter your vote (0 Leave, 1 Stay): ";
    bool vote;
    cin >> vote;
    clear_in_buufer();

    Voter tempVoter = Voter(name, age, gender, city, ethons, vote);
    return tempVoter;
}