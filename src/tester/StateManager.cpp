#include "StateManager.hpp"
string dataset[1000];
string UBattack;
string BUattack;
int UBattackIdx = 1;
int BUattackIdx = 1;
int UBhistory[1000];
int BUhistory[1000];
int current_stage = 1;
int state_change[3];
int state_idx = 0;
int idx = 0;

void
StateManager::set_testcase(string filepath) {
    state_change[0] = 0;
    state_change[1] = 1;
    state_change[2] = 0;
    cout << "===== Read and Analyze "<< filepath << " =====" << endl;
    ifstream openFile(filepath.data());

    if (openFile.is_open()) {
        string line;
        string stage;
        int chanUBidx = 0;
        int chanBUidx = 0;

        while (getline(openFile, line)) {
            line += "\n";
            size_t pos = line.find("State:");
            if (pos != string::npos) {
                cout << line << endl;
                dataset[idx] = stage;
                stage = "";
                if (chanUBidx == 0) {
                    UBhistory[idx] = UBhistory[idx - 1];
                }

                if (chanBUidx == 0) {
                    BUhistory[idx] = BUhistory[idx - 1];
                }
                chanUBidx = 0;
                chanBUidx = 0;
                idx++;
            }

            pos = line.find("sm");
            if (pos != string::npos) {
                continue;
            }

            pos = line.find("paging");
            if (pos != string::npos) {
                continue;
            }

            pos = line.find("ue_rrc_action");
            if (pos != string::npos) {
                pos = line.find("null_action");
                if (pos == string::npos) {
                    cout << line << endl;
                    stage += line;
                }
            }

            pos = line.find("bs_rrc_action");
            if (pos != string::npos) {
                pos = line.find("null_action");
                if (pos == string::npos) {
                    cout << line << endl;
                    stage += line;
                }
            }

            pos = line.find("inj_adv_act");
            if (pos != string::npos) {
                pos = line.find("null_action");
                if (pos == string::npos) {
                    cout << line << endl;
                    stage += line;
                }
            }

            pos = line.find("attacker_inject_message_chan");
            if (pos != string::npos) {
                cout << line << endl;
                stage += line;

                pos = line.find("chanUB");
                if (pos != string::npos) {
                    chanUBidx = 1;
                    pos = line.find("= ");
                    string token = line.substr(pos + 2);
                    pos = token.find("TRUE");
                    if (pos != string::npos) {
                        UBhistory[idx] = 1;
                    }
                    else {
                        UBhistory[idx] = 0;
                    }
                }

                pos = line.find("chanBU");
                if (pos != string::npos) {
                    chanBUidx = 1;
                    pos = line.find("= ");
                    string token = line.substr(pos + 2);
                    pos = token.find("TRUE");
                    if (pos != string::npos) {
                        BUhistory[idx] = 1;
                    }
                    else {
                        BUhistory[idx] = 0;
                    }
                }
            }

            pos = line.find("Loop");
            if (pos != string::npos) {
                cout << line << endl;
            }
        }
        cout << line << endl;
        dataset[idx] = stage;
        openFile.close();
    }
    UBhistory[4] = 1;

    string first_state = dataset[1];
    string delimeter = "\n";
    size_t last = 0;
    size_t next = first_state.find(delimeter);

    while (next != string::npos) {
        string token = first_state.substr(last, next - last - 1);
        last = next + delimeter.length();
        next = first_state.find(delimeter, last);

        size_t pos = token.find("inj_adv_act_UB");
        if (pos != string::npos) {
            pos = token.find("= ");
            UBattack = token.substr(pos + 2);
        }

        pos = token.find("inj_adv_act_BU");
        if (pos != string::npos) {
            pos = token.find("= ");
            BUattack = token.substr(pos + 2);
        }
    }

    cout << "chanUB: " << UBhistory[1] << endl;
    cout << "chanBU: " << BUhistory[1] << endl;
    cout << "Attack reloaded: " << UBattack << endl;
    cout << "Attack reloaded: " << BUattack << endl;
    cout << "===== Stage 1.1 =====" << endl;
    current_stage++;

    cout << "" << endl;
    cout << "Current State : Listen" << endl;
    change_state();
}

void
StateManager::receive_string(string input) {
    string delimeter = "\n";
    string lines = dataset[current_stage];
    string token;
    size_t last = 0;
    size_t next = 0;
    size_t pos = 0;

    next = lines.find(input);
    if (next == string::npos) {
        cout << "Wrong Condition: " << input << endl;
        return;
    }

    while ((next = lines.find(delimeter)) != string::npos) {
        token = lines.substr(last, next - last - 1);
        pos = token.find("= ");
        token = token.substr(pos + 2);

        if (token == input) {
            cout << "Condition Fulfilled: " << token << endl;
            lines.erase(last, next - last + delimeter.length());
            dataset[current_stage] = lines;
            change_state();
            return;
        }
    }
}

string
StateManager::send_act_string() {
    string act;
    string next_attack;
    string token;
    string delimeter = "\n";
    string lines = dataset[current_stage];
    size_t next = 0;
    size_t last = 0;
    size_t pos = 0;
    size_t i = 0;

    while ((next = lines.find(delimeter)) != string::npos) {
        token = lines.substr(last, next - last);
        if ((i = token.find("inj_adv_act")) != string::npos) {
            pos = token.find("= ");
            next_attack = token.substr(pos + 2);

            if (UBattackIdx == 1) {
                act = UBattack;
                cout << "Send Action: " << act << endl;
                UBattackIdx = 0;
                UBattack = next_attack;
            }

            else if (BUattackIdx == 1) {
                act = BUattack;
                cout << "Send Action: " << act << endl;
                BUattackIdx = 0;
                BUattack = next_attack;
            }

            lines.erase(last, next - last + delimeter.length());
            dataset[current_stage] = lines;

            change_state();
            break;
        }
    }
    return act;
}

void
StateManager::change_state() {
    string lines = dataset[current_stage];
    int UB_old = UBhistory[current_stage - 1];
    int BU_old = BUhistory[current_stage - 1];
    int UB = UBhistory[current_stage];
    int BU = BUhistory[current_stage];
    size_t next = 0;

    if (UB_old == 1 && UB == 0 && BU_old == 1 && BU == 0) { // Both T-F
        // TODO
    }

    else if (UB_old == 0 && UB == 1 && BU_old == 0 && BU == 1) { // Both F-T
        // TODO
    }

    if (StateManager::state == Listen_e) {
        next = lines.find("rrc_action");
        if (next == string::npos) {
            cout << "No more condtions in this state (Listen -> Action)" << endl;
            StateManager::state = Action_e;
        }
    }

    else {
        next = lines.find("inj_adv_act");
        if (next == string::npos) {
            cout << "No more actions in this state (Action -> Listen)" << endl;
            StateManager::state = Listen_e;

            next = lines.find("rrc_action");
            if (next == string::npos) {
                cout << "No more condtions in this state (State Done)" << endl;
                cout << "===== State 1." << current_stage << " =====" << endl;
                cout << "" << endl;
                cout << "Current State : Listen" << endl;
                current_stage++;
                UBattackIdx = 1;
                BUattackIdx = 1;

                if (current_stage == idx+1) {
                    cout << "TestCase Complete (Listen -> Success)" << endl;
                    StateManager::state = Success_e;
                    return;
                }

                lines = dataset[current_stage];
                next = lines.find("rrc_action");
                if (next == string::npos) {
                    cout << "No more condtions in this state (Listen -> Action)" << endl;
                    StateManager::state = Action_e;
                }
            }
        }
    }
}