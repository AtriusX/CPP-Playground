#include "errors.hpp"
#include "actions.hpp"

int main() {
    std::string action;

    while (true) {
        actions::getAction(&action, "Input action (calc, exit)");

        if (action == "calc" || action == "c") {
            actions::calculator();
            continue;
        }

        if (action == "exit" || action == "e") {
            actions::exitApp();
            break;
        }

        if (action != "") {
            errors::invalidActionError();
        }
    }
}