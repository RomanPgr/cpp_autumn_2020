#ifndef FORMAT_H
#define FORMAT_H

//#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <sstream>
#include <stdexcept>

class out_of_range_param : std::exception{
public:
    out_of_range_param(size_t i, int max) :
    description_error("Invalid parameter number you requested " + std::to_string(i) + ", available 0-" + std::to_string(max - 1)){
    }
    const char* what() const noexcept override {
        return description_error.c_str();
    }

private:
    std::string description_error;
};

class exception_parantheses : std::exception{
public:
    exception_parantheses(size_t i) :
        description_error("Incorrect use of parentheses in the format string, character " + std::to_string(i)){
    }
    const char* what() const noexcept override {
        return description_error.c_str();
    }

private:
    std::string description_error;
};

std::string format_service_function(const std::string& format_str, const std::vector<std::string>& strs_vec){
    std::string result = "";
    std::string number = "";
    size_t num;
    char c;
    size_t len = format_str.length();
    for (size_t i = 0; i < len; ++i){
        c = format_str[i];
        if (c == '\\'){
            if (len - 1 == i){
                break;
            }
            result += format_str[++i];
        }
        else if (c == '{'){
            number = "";
            ++i;
            while (i < len){
                c = format_str[i];
                if (std::isdigit(c)){
                    number += c;
                    i++;
                }
                else{
                    break;
                }
            }
            size_t number_len = number.length();
            if (number_len == 0 || format_str[i] != '}'){
                throw exception_parantheses(i);
            }
            num = std::stoi(number);
            if (number_len > 5 || num >= strs_vec.size()){
                throw out_of_range_param(num, strs_vec.size());
            }
            result += strs_vec[num];
        }
        else{
            result += c;
        }
    }

    return result;
}

template<class param, class ... params>
std::string format_service_function(const std::string& format_str, std::vector<std::string>& strs_vec, const param& first, const params& ... other){
    std::stringstream str;
    str << first;
    strs_vec.push_back(str.str());
    return format_service_function(format_str, strs_vec, other ...);
}

template<class param, class ... params>
std::string format(const std::string& format_str, const param& first, const params& ... other){
    std::vector<std::string> strs_vec;
    return format_service_function(format_str, strs_vec, first, other ...);
}

std::string format(const std::string& format_str){
    std::vector<std::string> strs_vec;
    return format_service_function(format_str, strs_vec);
}

#endif
