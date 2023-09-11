//Nathan Lamoureux


//Including all necessary libraries
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


/*The program will use a query-based system to narrow-down to the topic of interest. Each answer will give an integer value that will
identify the next set of questions or the solution until the desired outcome is reached.*/
int main() {

    int v = 0; //enter key/letter verifier
    string code;

    //Creating date/time variable for issue log
    time_t now = time(0);

    char* date_time = ctime(&now);

    int init = 0; //integer used to check whether date-time was already printed

    //introduction to program
    cout << "Welcome to VDEP (Vehicle Diagnostic for Engine Problems)" << endl << endl;
    cout << "Created by Nathan Lamoureux" << endl;
    cout << endl;
    cout << "DISCLAIMER: ";
    cout << "This program is designed around the four-cylinder engine. If your engine is different, results may vary" << endl;
    cout << "Press enter to start." << endl;

    //file creation
    fstream problemList("problem_list.txt", fstream::app);
    if(!problemList.is_open()) {
        cout << "File could not be opened." << endl;
    }

    while (v != 1) {
        if (cin.get() == '\n') {
            cout << "Beginning Diagnostic:" << endl;
            v = 1;
        } else {}
    }
    char tinput; //input variable for check-engine light
    bool done1 = false;
    //Checking for check-engine indicator
    while(!done1) {

        cout << "Is your check-engine light on? (y/n)" << endl;
        cin >> tinput;

        if (tinput == 'n') {
            cout
                    << "Please see a mechanic or dealer, this program specifies in issues that are indicated by the check-engine light."
                    << endl;
            done1 = true;

            return EXIT_SUCCESS;

        } else if (tinput == 'y') {
            done1 = true;

        } else {

            cout << "Please enter the correct character." << endl;

        }
    }



    /*Implementing threat levels. Threat levels will inform the user of the severity of the issue and the likelihood of one being able to
      repair the damaged component(s) themselves. Will vary with 1 being the lowest level of severity, and the most repairable, to 3 being the "Oh my god this thing
      is going to blow up if I don't bring it to a mechanic".*/

    string threatLevel[3];

    threatLevel[0] = "Threat Level: 1. This issue is non-severe in the short-term but can lead to more severe damage if not resolved. A mechanic is not required to "
                     "resolve the above issue if one desired to attempt a repair themselves, but prior research or video guides will be necessary.";

    threatLevel[1] = "Threat Level: 2. This issue will lead to severe damage if not fixed as soon as possible. A mechanic is not required to resolve the above issue "
                     "if one desired to attempt a repair themselves, but prior research or video guides are REQUIRED.";

    threatLevel[2] = "Threat Level: 3. This issue will cause vehicle-threatening damage if not repaired IMMEDIATELY. A mechanic will be required to resolve the above issue, "
                     "and it is recommended to cease all driving of the vehicle unless it is to a mechanic or dealership.";

    string descriptions_e[10];
    string solutions_e[10];
    string descriptions_t[5];
    string solutions_t[3];


    //Writing in the descriptions of engine issues to an array
    descriptions_e[0] = "Misfires are a common problem in most engines, where the engine's cylinder can stop producing power to the drive-train.";
    descriptions_e[1] = "Internal damaged components are a serious issue that could include compromised pistons, cylinders, engine block frame, or other key mechanical components.";
    descriptions_e[2] = "Oil leaks can be caused by damaged parts (tank, line, engine components), or a unaligned seal.";
    descriptions_e[3] = "Burning oil could lead to poor engine health in the future. This mainly occurs when an engine is past due for an oil change.";
    descriptions_e[4] = "Coolant leaks will lead to above average engine temperatures and possible overheating, as coolant is essential to keeping the engine at "
                        "a operable temperature.";
    descriptions_e[5] = "A thermostat malfunction can cause an overflow of coolant, keeping the engine from warming properly. This can cause a number of future problems for the"
                        " engine as well as the transmission.";
    descriptions_e[6] = "The A/C compressor is 'connected' to the vehicle's alternator via the serpentine belt. Damage to this part can directly result to damage of the vehicle's "
                        "electrical systems.";
    descriptions_e[7] = "Fuel line damage or fuel leaks can result in a decrease in fuel efficiency, as well as cause car fires due to the flammable nature of gasoline.";
    descriptions_e[8] = "The alternator is essential for generating electricity to keep the electrical systems in the car operational. Losing the alternator can result in the "
                        "inability to operate the vehicle all together.";
    descriptions_e[9] = "Wiring issues can affect numerous systems as there is wiring all throughout the vehicle. It is suggested that you take the vehicle to a dealership "
                        "if wiring is deemed the problem.";


    //Writing in the solutions for engine issues to an array
    solutions_e[0] = "Replace spark plugs, replace ignition coil.";
    solutions_e[1] = "Bring vehicle to mechanic or dealer.";
    solutions_e[2] = "Check oil seals, tubes, and tank for leaks and replace as necessary. If leak is coming from the engine block, see mechanic or dealer.";
    solutions_e[3] = "Change oil in vehicle.";
    solutions_e[4] = "Check coolant tubes and reservoir and replace as necessary. If leak is coming from the engine block, see mechanic or dealer.";
    solutions_e[5] = "Replace vehicle thermostat.";
    solutions_e[6] = "Replace vehicle A/C compressor. Replacing serpentine belt is optional but suggested.";
    solutions_e[7] = "Check fuel line for leaks as well as gas tank. Replace as necessary while fuel tank is empty. If leak is coming from the engine block, see mechanic or dealer.";
    solutions_e[8] = "Replace vehicle alternator. Replacing serpentine belt is optional but suggested.";
    solutions_e[9] = "See dealership. There may be other issue(s) that this program cannot detect.";


    //Writing in the descriptions of transmission issues to an array
    descriptions_t[0] = "Gearbox issues can directly result in the compromise of the transmission and ability to drive the vehicle. Symptoms like gear grinding, slipping "
                        "or losing a gear are major warning signs.";
    descriptions_t[1] = "Transmission fluid is essential for keeping your car shifting and staying in gear by keeping the transmission lubricated. The transmission fluid filter "
                        "helps to keep the fluid clean.";
    descriptions_t[2] = "Transmission fluid leaks can result to gearbox damage as well as overheating. It is vital to keeping the moving parts and bearings lubricated.";
    descriptions_t[3] = "Stalling is when a vehicle's transmission cannot change gears properly and causes the engine to shut down. Commonly occurs while vehicle is stopped.";
    descriptions_t[4] = "Transmission solenoids control the flow of fluid through the gearbox via electrical signals. The compromise of this part will cause the compromise of the "
                        "transmission gearbox.";


    //Writing in the solutions of transmission issues to an array
    solutions_t[0] = "Take vehicle to mechanic or dealership.";
    solutions_t[1] = "Draining and replacing the transmission fluid and filter is doable on your own, but it is recommended to see a mechanic if you are not experienced with "
                     "DIY maintenance.";
    solutions_t[2] = "Replace transmission solenoid.";


    int solution;   //This variable will be assigned a value based on the query results
    int input; //This variable will be the user's input within the query
    bool rerunVariable; //Determining whether to rerun diagnostic

    int problemNumber = 0; //Integer to determine issue number on log
    rerunVariable = true;

    //Beginning diagnostic loop
    while (rerunVariable) {


        //Query creation (nested switch statements)
        cout << "Do any of these visible issues exist?" << endl;
        cout << "1. Leaking fluid" << endl;
        cout << "2. No A/C in vehicle" << endl;
        cout << "3. Slow engine warm-up" << endl;
        cout << "4. None" << endl;

        cin >> input;
        bool done2 = true;

       do {
           switch (input) {
               case 1:
                   char colorCode; //A user input to determine leak solution
                   cout << "What color is the fluid?" << endl;
                   cout << "C - clear" << endl;
                   cout << "B - brown or black" << endl;
                   cout << "R - red" << endl;
                   cout << "O - orange or green" << endl;
                   cin >> colorCode;
                   done2 = true;
                   switch (colorCode) {
                       case 'C':
                           solution = 1;
                           problemNumber++;
                           break;
                       case 'B':
                           solution = 2;
                           problemNumber++;
                           break;
                       case 'R':
                           solution = 3;
                           problemNumber++;
                           break;
                       case 'O':
                           solution = 4;
                           problemNumber++;
                           break;
                       default:
                           cout << "Please enter a valid character." << endl;
                           done2 = false;
                           break;
                   }
                   break;

               case 2:
                   solution = 5;
                   problemNumber++;
                   break;

               case 3:
                   solution = 6;
                   problemNumber++;
                   break;

               case 4:
                   cout << "Do any of these auditory issues exist while operating the vehicle?" << endl;
                   cout << "1. Grinding or sounds of metal" << endl;
                   cout << "2. Popping sounds" << endl;
                   cout << "3. Engine shutoff" << endl;
                   cout << "4. None" << endl;
                   cin >> input;


                   switch (input) {
                       case 1:
                           cout << "Do the grinding sounds occur while shifting gears? (y/n)" << endl;
                           cin >> tinput;
                           if (tinput == 'y') {
                               solution = 9;
                               problemNumber++;
                           } else if (tinput == 'n') {
                               solution = 10;
                               problemNumber++;
                           } else {
                               cout << "Please use correct characters." << endl;
                           }
                           break;

                       case 2:
                           solution = 7;
                           problemNumber++;
                           break;

                       case 3:
                           solution = 8;
                           problemNumber++;
                           break;

                       case 4:
                           cout << "Do any of these other issues exist?" << endl;
                           cout << "1. My battery is not charging" << endl;
                           cout << "2. Specific electrical systems are not working properly" << endl;
                           cout << "3. I can smell burning oil" << endl;
                           cout << "4. My vehicle shifts slowly or won't shift at all" << endl;
                           cout << "5. None of the above issues exist" << endl;

                           cin >> input;

                           switch (input) {
                               case 1:
                                   solution = 11;
                                   problemNumber++;
                                   break;
                               case 2:
                                   solution = 12;
                                   problemNumber++;
                                   break;
                               case 3:
                                   solution = 13;
                                   problemNumber++;
                                   break;
                               case 4:
                                   solution = 14;
                                   problemNumber++;
                                   break;
                               case 5:
                                   cout
                                           << "No issue could be found. Please try again or seek a mechanic for assistance."
                                           << endl;
                                   solution = 0;
                                   init = 1;
                                   break;
                               default:
                                   cout << "Please enter the correct number value." << endl;
                                   done2 = false;
                                   break;
                           }
                           break;


                   }

           }

           //if condition that determines if the date and time has already been printed before printing
           if (init == 0) {
               problemList << date_time << endl; //printing date and time to log
               init = 1;
           }

           switch (solution) {
               case 0:
                   break;
               case 1:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Fuel leak" << endl;
                   problemList << "Description: " << descriptions_e[7] << endl;
                   problemList << threatLevel[1] << endl;
                   problemList << "Solution(s): " << solutions_e[7] << endl;
                   problemList << "Code: P0094" << endl;
                   problemList << endl;
                   break;
               case 2:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Oil leak, low oil pressure" << endl;
                   problemList << "Description: " << descriptions_e[2] << endl;
                   problemList << threatLevel[1] << endl;
                   problemList << "Solution(s): " << solutions_e[2] << endl;
                   problemList << "Code: P0521" << endl;
                   problemList << endl;
                   break;
               case 3:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Transmission fluid leak" << endl;
                   problemList << "Description: " << descriptions_t[2] << endl;
                   problemList << threatLevel[1] << endl;
                   problemList << "Solution(s): " << solutions_t[2] << endl;
                   problemList << "Code: P0897" << endl;
                   problemList << endl;
                   break;
               case 4:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Coolant leak" << endl;
                   problemList << "Description: " << descriptions_e[4] << endl;
                   problemList << threatLevel[1] << endl;
                   problemList << "Solution(s): " << solutions_e[4] << endl;
                   problemList << "Code: P0128" << endl;
                   problemList << endl;
                   break;
               case 5:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: A/C compressor malfunction" << endl;
                   problemList << "Description: " << descriptions_e[6] << endl;
                   problemList << threatLevel[1] << endl;
                   problemList << "Solution(s): " << solutions_e[6] << endl;
                   problemList << "Code: P0645, P0531, P0534" << endl;
                   problemList << endl;
                   break;
               case 6:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Thermostat malfunction" << endl;
                   problemList << "Description: " << descriptions_e[5] << endl;
                   problemList << threatLevel[1] << endl;
                   problemList << "Solution(s): " << solutions_e[5] << endl;
                   problemList << "Code: P0128" << endl;
                   problemList << endl;
                   break;
               case 7:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Engine misfires" << endl;
                   problemList << "Description: " << descriptions_e[0] << endl;
                   problemList << threatLevel[0] << endl;
                   problemList << "Solution(s): " << solutions_e[0] << endl;
                   problemList << "Code: P0300-P0308" << endl;
                   problemList << endl;
                   break;
               case 8:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Vehicle stalling" << endl;
                   problemList << "Description: " << descriptions_t[3] << endl;
                   problemList << threatLevel[2] << endl;
                   problemList << "Solution(s): " << solutions_t[0] << endl;
                   problemList << "Code: P0505" << endl;
                   problemList << endl;
                   break;
               case 9:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Transmission gearbox damage" << endl;
                   problemList << "Description: " << descriptions_t[0] << endl;
                   problemList << threatLevel[2] << endl;
                   problemList << "Solution(s): " << solutions_t[0] << endl;
                   problemList << "Code: P0729-P0736" << endl;
                   problemList << endl;
                   break;
               case 10:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Internal engine component damage" << endl;
                   problemList << "Description: " << descriptions_e[1] << endl;
                   problemList << threatLevel[2] << endl;
                   problemList << "Solution(s): " << solutions_e[1] << endl;
                   problemList << endl;
                   break;
               case 11:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Alternator malfunction" << endl;
                   problemList << "Description: " << descriptions_e[8] << endl;
                   problemList << threatLevel[1] << endl;
                   problemList << "Solution(s): " << solutions_e[8] << endl;
                   problemList << "Code: P0526" << endl;
                   problemList << endl;
                   break;
               case 12:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Wiring issue" << endl;
                   problemList << "Description: " << descriptions_e[9] << endl;
                   problemList << threatLevel[2] << endl;
                   problemList << "Solution(s): " << solutions_e[9] << endl;
                   problemList << endl;
                   break;
               case 13:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Engine burning oil" << endl;
                   problemList << "Description: " << descriptions_e[3] << endl;
                   problemList << threatLevel[0] << endl;
                   problemList << "Solution(s): " << solutions_e[3] << endl;
                   problemList << "Code: P0524" << endl;
                   problemList << endl;
                   break;
               case 14:
                   problemList << "Issue " << problemNumber << ": " << endl;
                   problemList << "Problem: Transmission solenoid malfunction" << endl;
                   problemList << "Description: " << descriptions_t[4] << endl;
                   problemList << threatLevel[2] << endl;
                   problemList << "Solution(s): " << solutions_t[2] << endl;
                   problemList << "Code: P0750" << endl;
                   problemList << endl;
                   break;
           }
       } while(!done2);

        cout << "Would you like to rerun the diagnostic? (y/n)" << endl;
        if(cin.get() == 'y') {

        }
        else if( cin.get() == 'n') {
            rerunVariable = false;
        }
    }

    cout << "Log is created, please navigate to program's source to view." << endl;
    cout << endl;

    //Editing/deleting the log
    cout << "Would you like to edit the log? (y/n)" << endl;
    char r;
    cin >> r;

    bool done = true;
    do {
    if (r == 'y') {
        cout << "What would you like to do?" << endl;
        cout << endl;
        cout << "1. Add issue" << endl;
        cout << "2. Delete log" << endl;
        cout << "3. Exit program" << endl;
        cin >> input;

        //Adding problem to log (without rerunning diagnostic)
            switch (input) {
                case 1:
                    cout << "Which issue would you like to add?" << endl;
                    cout << "1. Fuel leak" << endl;
                    cout << "2. Oil leak" << endl;
                    cout << "3. Transmission fluid leak" << endl;
                    cout << "4. Coolant leak" << endl;
                    cout << "5. A/C compressor malfunction" << endl;
                    cout << "6. Thermostat malfunction" << endl;
                    cout << "7. Engine misfires" << endl;
                    cout << "8. Stalling" << endl;
                    cout << "9. Transmission gearbox damage" << endl;
                    cout << "10. Internal engine damage" << endl;
                    cout << "11. Alternator malfunction" << endl;
                    cout << "12. Wiring issue" << endl;
                    cout << "13. Burning oil" << endl;
                    cout << "14. Transmission solenoid malfunction" << endl;
                    int i;
                    cin >> i;
                    problemNumber++;

                    if (init == 0) {
                        problemList << date_time << endl; //printing date and time to log
                        init = 1;
                    }
                    else {}

                    switch (i) {
                        case 1:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Fuel leak" << endl;
                            problemList << "Description: " << descriptions_e[7] << endl;
                            problemList << threatLevel[1] << endl;
                            problemList << "Solution(s): " << solutions_e[7] << endl;
                            problemList << "Code: P0094" << endl;
                            problemList << endl;
                            break;
                        case 2:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Oil leak, low oil pressure" << endl;
                            problemList << "Description: " << descriptions_e[2] << endl;
                            problemList << threatLevel[1] << endl;
                            problemList << "Solution(s): " << solutions_e[2] << endl;
                            problemList << "Code: P0521" << endl;
                            problemList << endl;
                            break;
                        case 3:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Transmission fluid leak" << endl;
                            problemList << "Description: " << descriptions_t[2] << endl;
                            problemList << threatLevel[1] << endl;
                            problemList << "Solution(s): " << solutions_t[2] << endl;
                            problemList << "Code: P0897" << endl;
                            problemList << endl;
                            break;
                        case 4:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Coolant leak" << endl;
                            problemList << "Description: " << descriptions_e[4] << endl;
                            problemList << threatLevel[1] << endl;
                            problemList << "Solution(s): " << solutions_e[4] << endl;
                            problemList << "Code: P0128" << endl;
                            problemList << endl;
                            break;
                        case 5:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: A/C compressor malfunction" << endl;
                            problemList << "Description: " << descriptions_e[6] << endl;
                            problemList << threatLevel[1] << endl;
                            problemList << "Solution(s): " << solutions_e[6] << endl;
                            problemList << "Code: P0645, P0531, P0534" << endl;
                            problemList << endl;
                            break;
                        case 6:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Thermostat malfunction" << endl;
                            problemList << "Description: " << descriptions_e[5] << endl;
                            problemList << threatLevel[1] << endl;
                            problemList << "Solution(s): " << solutions_e[5] << endl;
                            problemList << "Code: P0128" << endl;
                            problemList << endl;
                            break;
                        case 7:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Engine misfires" << endl;
                            problemList << "Description: " << descriptions_e[0] << endl;
                            problemList << threatLevel[0] << endl;
                            problemList << "Solution(s): " << solutions_e[0] << endl;
                            problemList << "Code: P0300-P0308" << endl;
                            problemList << endl;
                            break;
                        case 8:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Vehicle stalling" << endl;
                            problemList << "Description: " << descriptions_t[3] << endl;
                            problemList << threatLevel[2] << endl;
                            problemList << "Solution(s): " << solutions_t[0] << endl;
                            problemList << "Code: P0505" << endl;
                            problemList << endl;
                            break;
                        case 9:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Transmission gearbox damage" << endl;
                            problemList << "Description: " << descriptions_t[0] << endl;
                            problemList << threatLevel[2] << endl;
                            problemList << "Solution(s): " << solutions_t[0] << endl;
                            problemList << "Code: P0729-P0736" << endl;
                            problemList << endl;
                            break;
                        case 10:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Internal engine component damage" << endl;
                            problemList << "Description: " << descriptions_e[1] << endl;
                            problemList << threatLevel[2] << endl;
                            problemList << "Solution(s): " << solutions_e[1] << endl;
                            problemList << endl;
                            break;
                        case 11:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Alternator malfunction" << endl;
                            problemList << "Description: " << descriptions_e[8] << endl;
                            problemList << threatLevel[1] << endl;
                            problemList << "Solution(s): " << solutions_e[8] << endl;
                            problemList << "Code: P0526" << endl;
                            problemList << endl;
                            break;
                        case 12:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Wiring issue" << endl;
                            problemList << "Description: " << descriptions_e[9] << endl;
                            problemList << threatLevel[2] << endl;
                            problemList << "Solution(s): " << solutions_e[9] << endl;
                            problemList << endl;
                            break;
                        case 13:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Engine burning oil" << endl;
                            problemList << "Description: " << descriptions_e[3] << endl;
                            problemList << threatLevel[0] << endl;
                            problemList << "Solution(s): " << solutions_e[3] << endl;
                            problemList << "Code: P0524" << endl;
                            problemList << endl;
                            break;
                        case 14:
                            problemList << "Issue " << problemNumber << ": " << endl;
                            problemList << "Problem: Transmission solenoid malfunction" << endl;
                            problemList << "Description: " << descriptions_t[4] << endl;
                            problemList << threatLevel[2] << endl;
                            problemList << "Solution(s): " << solutions_t[2] << endl;
                            problemList << "Code: P0750" << endl;
                            problemList << endl;
                            break;
                        default:
                            cout << "Please enter the correct number." << endl;
                            break;
                    }
                    break;

                    //clearing log
                case 2:
                    problemList.close();
                    problemList.open("problem_list.txt", ios::out | ios::trunc);
                    cout << "Log cleared." << endl << endl;
                    break;

                    //exiting program
                case 3:
                    done = false;
                    break;

                default:
                    cout << "Please enter an appropriate integer." << endl;
            }
    }

    else if(r == 'n'){
        done = false;
    }

    else {
        cout << "Please enter correct character (y/n)" << endl;
    }

    } while (done);

    problemList.close();

    cout << "Log successfully closed." << endl;

    return EXIT_SUCCESS;
}