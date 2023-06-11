#include "school.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using std :: cout;
using std :: ofstream;
using std :: ifstream;
using std :: cerr;
using std :: endl;
using std :: string;

string School :: To_string (){
    std::string symbol = "+";
        if (this->IsEducationFree) {
        symbol = '+';
    } else {
        symbol = '-';
    }
    std :: stringstream raw_Value; 
    raw_Value << "--------------------------------------------------------------------------" << endl;
    raw_Value << " Name of the institution: " << this->Name << endl;
    raw_Value << " Head of the institution: " << this->head.name << ", " << this->head.last_name << ", " << this->head.mail << endl;
    raw_Value << " Free education: " << symbol << endl << " Amount of students: " << this->Amount_of_students << endl;
    raw_Value << " What time do classes start: " << ((this->Begin == standard) ? "8:00" : ((this->Begin == second_shift) ? "14:00" : "8:30")) << endl;
    raw_Value << "--------------------------------------------------------------------------" << endl;
    return raw_Value.str();
}

/*void School::Print_Me() const {
    std::string symbol = "+";
    if (this->IsEducationFree) {
        symbol = '+';
    } else {
        symbol = '-';
    }
    cout << "--------------------------------------------------------------------------" << endl;
    cout << " Name of the institution: " << this->Name << endl;
    cout << " Head of the institution: " << this->head.name << ", " << this->head.last_name << ", " << this->head.mail << endl;
    cout << " Free education: " << symbol << endl << " Amount of students: " << this->Amount_of_students << endl;
    cout << " What time do classes start: " << ((this->Begin == standard) ? "8:00" : ((this->Begin == second_shift) ? "14:00" : "8:30")) << endl;
    cout << "--------------------------------------------------------------------------" << endl;
}*/

void School :: Write_To_File(ofstream &of) const{
    of << this -> Name << "," << this ->head.name << "," << this ->head.last_name << "," << this ->head.mail << ",";
    of << this -> IsEducationFree << "," << this -> Amount_of_students << "," << (this->Begin == standard ? "8:00" : (this->Begin == second_shift ? "14:00" : "8:30")) << endl;
}

size_t School :: getAmount_of_students() const{
    return this->Amount_of_students;
}

bool School :: getIsEducationFree() const {
    return this->IsEducationFree;
}

void School :: setAmount_of_students (size_t number) {
    this->Amount_of_students = number;
}

void School :: setIsEducationFree (bool true_or_false) {
    this->IsEducationFree = true_or_false;
}

string Get_next_token (string& line, const string& delimiter) {
    size_t pos = line.find(delimiter);
    string result = line.substr (0, pos);
    line.erase(0, pos + delimiter.length());
    return result;
}

School* Parse_School(const string& lineRaw) {
    string name;
    Head_of_the_institution Head;
    The_beginning_of_the_school_day Begin;
    string line = lineRaw;
    const string delimiter = string(",");
    string token = Get_next_token(line, delimiter);
    name = token;
    token = Get_next_token(line, delimiter);
    bool is_education_free = strtol(token.c_str(), NULL, 10);
    token = Get_next_token(line, delimiter);
    size_t amount_of_students = static_cast<size_t>(strtol(token.c_str(), NULL, 10));
    token = Get_next_token(line, delimiter);
    Head.name = token;
    token = Get_next_token(line, delimiter);
    Head.last_name = token;
    token = Get_next_token(line, delimiter);
    Head.mail = token;
    token = Get_next_token(line, delimiter);
    Begin = static_cast<The_beginning_of_the_school_day>(strtol(token.c_str(), NULL, 10));
    School *school = new School (is_education_free,name,amount_of_students,Head, Begin);
    return school;
}
