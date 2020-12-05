#ifndef FORMAT_H
#define FORMAT_H

#include <iostream>
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
    const char* what() const noexcept{
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
    const char* what() const noexcept{
        return description_error.c_str();
    }

private:
    std::string description_error;
};

std::string format_service_function(const std::string& format_str, std::vector<std::string>& strs_vec){

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
            num = atoi(number.c_str());
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
std::string format_service_function(const std::string& format_str, std::vector<std::string>& strs_vec, param&& first, params&& ... other){
    std::stringstream str;
    str << std::forward<param>(first);
    strs_vec.push_back(str.str());
    return format_service_function(format_str, strs_vec, std::forward<params>(other) ...);
}


template<class param, class ... params>
std::string format(const std::string& format_str, param&& first, params&& ... other){
    std::vector<std::string> strs_vec;
    return format_service_function(format_str, strs_vec, std::forward<param>(first), std::forward<params>(other) ...);
}

std::string format(const std::string& format_str){
    std::string result = "";
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
            std::string number = "";
            ++i;
            while (i < len){
                c = format_str[i];
                if (std::isdigit(c)){
                    number += c;
                    i++;
                }
                break;
            }
            size_t number_len = number.length();
            if (number_len == 0 || format_str[i] != '}'){
                throw exception_parantheses(i);
            }
            size_t num = atoi(number.c_str());
            throw out_of_range_param(num, -1);
        }
        else{
            result += c;
        }
    }


    return result;
}



#endif
