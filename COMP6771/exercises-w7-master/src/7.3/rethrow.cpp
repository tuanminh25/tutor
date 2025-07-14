#include "./rethrow.h"

// Class resources
/*
    private:
        int n_attempts_;
        bool active_;

*/


const std::set<std::string> db_conn::blacklist_ = {"hsmith"};

/**
* @brief Attempts to make a connection given a uname and pwd.
* 
* If the uname is not part of the blacklist, and pword is at least 8 characters,
* the connection is successfully established (i.e. active_ becomes true).
* Once a connection is established, any further calls to this function have no effect.
* All calls to this function, even calls that result in an exception being thrown, count as attempts.
* 
* Throws exceptions in the cases and order given below.
* 
* @throws std::domain_error: if uname is part of the blacklist,
*         throws a std::domain_error with message: <uname> is not allowed to login.
* @throws std::runtime_error: every 2nd attempt, the computer malfunctions and throws a std::runtime_error with message:
*         HeLp ;_; c0mpu73R c@ann0T c0mPut3 0w0
* 
* @param uname - the uname to login / make a connection.
* @param pword - the password of the user.
*/
auto db_conn::try_connect(const std::string &uname, const std::string &pword) -> void {
    if (!active_) {
        n_attempts_ += 1;
        if (blacklist_.contains(uname)) {
            throw std::domain_error(uname + " is not allowed to login.");
        } else if (n_attempts_ % 2 == 0) {
            throw std::runtime_error("HeLp ;_; c0mpu73R c@ann0T c0mPut3 0w0");
        }

        active_ = pword.length() >= 8;
    }
}

auto db_conn::is_active() const-> bool {
    return active_;
}

auto make_connection(db_conn &db, const std::string &uname, const std::string &pword) -> void {
    try {
        db.try_connect(uname, pword);
    } catch(const std::domain_error &e) {
        throw std::string{e.what()}; // .what extract out of error object and return c style string: const char*
    } catch(const std::runtime_error &e) {
        throw std::string{e.what()};
    }
}