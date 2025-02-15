#include "errors.hpp"
#include "actions.hpp"

int main() {
    std::string action;

    while (true) {
        actions::getAction(&action, "Input action (calc, exit)");

        if (action == "calc") {
            actions::calculator();
            continue;
        }

        if (action == "exit") {
            actions::exitApp();
            break;
        }

        if (action != "") {
            errors::invalidActionError();
        }
    }
}