#ifndef COMP6771_FERRARIPP_H
#define COMP6771_FERRARIPP_H

#include <string>
#include <utility>

class ferrari {
    public:
        ferrari() : ferrari("unknown", 6771, 0) {};
        ferrari(const std::string &owner, int modelno) : ferrari(owner, modelno, 0) {};

        std::pair<std::string, int> get_details() const {
            return std::make_pair(owner_, modelno_);
        }

        void drive(int spd)  {
            speed_ = spd;
        };

        std::string vroom() const {
            if (speed_ < 20) {
                return "";
            } else if (speed_ < 80) {
                return "vroom!!";
            } else {
                return "VROOOOOOOOM!!!";
            }
        }


    private:
        ferrari(const std::string &owner, int modelno, int speed)
        : owner_(owner), modelno_(modelno), speed_(speed) {};

        std::string owner_;
        int modelno_;
        
        int speed_;
};

#endif  // COMP6771_FERRARIPP_H