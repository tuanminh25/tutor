#include "./rethrow.h"

#include <iostream>
#include <utility>
#include <vector>

int main() {
 
    auto db = db_conn{};
    const auto attempts = std::vector<std::pair<std::string, std::string>> {
        {"hsmith", "swagger/10"},                   // -> invalid -> throw blacklist
        {"vegeta", "over9000"},                     // -> invalid -> throw even nums of log in
        {"billgates", "apple<3"},                   // -> valid
        {"billgates", "macros0ft"},                 // -> invalid -> throw even nums of log in
        {"billgates", "m1cros0ft"},                 // -> valid
    };

    
    for (const auto &[uname, pwd] : attempts) {
        try {
            make_connection(db, uname, pwd);
        } catch (const std::string &e) {
            std::cout << "Could not establish connection: " << e << std::endl;
        }
    }
        
}

/**
 * Output:
 * Could not establish connection: hsmith is not allowed to login.
 * Could not establish connection: HeLp ;_; c0mpu73R c@ann0T c0mPut3 0w0
 * Could not establish connection: HeLp ;_; c0mpu73R c@ann0T c0mPut3 0w0
 */
