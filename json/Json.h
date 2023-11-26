//
// Created by Xianming on 2023/11/25.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>


namespace json {

    class Json {
    public:
        enum Type {
            json_null = 0,
            json_bool,
            json_int,
            json_double,
            json_string,
            json_array,
            json_object
        };

        Json();
        Json(Type type);
        Json(bool value);
        Json(int value);
        Json(double value);
        Json(const char *value);
        Json(const std::string &value);
        Json(const Json &other);
        ~Json();

        Type type() const;

        operator bool();
        operator int();
        operator double();
        operator std::string();

        Json &operator[](int index);
        void append(const Json &other);
        Json &operator[](const char *key);
        Json &operator[](const std::string &key);

        void operator=(const Json &other);
        bool operator==(const Json &other);
        bool operator!=(const Json &other);

        void parse(const std::string & str);
        std::string str() const;

        void clear();
        typedef std::vector<Json>::iterator iterator;

        iterator begin() {
            return m_value.m_array->begin();
        }

        iterator end() {
            return m_value.m_array->end();
        }

        bool isNull() const { return m_type == json_null; }
        bool isBool() const { return m_type == json_bool; }
        bool isInt() const { return m_type == json_int; }
        bool isDouble() const { return m_type == json_double; }
        bool isString() const { return m_type == json_string; }
        bool isArray() const { return m_type == json_array; }
        bool isObject() const { return m_type == json_object; }

        bool asBool() const;
        int asInt() const;
        double asDouble() const;
        std::string asString() const;

        int size() const;

        bool empty() const;

        bool has(int index);
        bool has(const char *key);
        bool has(const std::string &key);

        void remove(int index);
        void remove(const char *key);
        void remove(const std::string &key);


    private:
        void copy(const Json &other);

        union Value {
            bool m_bool;
            int m_int;
            double m_double;
            std::string *m_string;
            std::vector<Json> *m_array;
            std::map<std::string, Json> *m_object;

        };

        Type m_type;
        Value m_value;
    };
}
