#include <map>

#include <iostream>
#include <string>

#include <export.h>




class VeryHeavyDatabase {
public:
    std::string API_VERYHEAVYDB GetData(const std::string& key) noexcept;
};

class CacheProxyDB : VeryHeavyDatabase {
public:
    explicit API_VERYHEAVYDB CacheProxyDB (VeryHeavyDatabase* real_object);
    std::string API_VERYHEAVYDB GetData(const std::string& key) noexcept;

private:
    std::map<std::string, std::string> cache_;
    VeryHeavyDatabase* real_db_;
};

class TestDB : VeryHeavyDatabase {
public:
    explicit API_VERYHEAVYDB TestDB(VeryHeavyDatabase* real_object);
    std::string API_VERYHEAVYDB GetData(const std::string& key) noexcept;
private:
    VeryHeavyDatabase* real_db_;
};

class OneShotDB : VeryHeavyDatabase {
public:
  explicit API_VERYHEAVYDB OneShotDB (VeryHeavyDatabase* real_object, size_t shots=1);
  std::string API_VERYHEAVYDB GetData(const std::string& key) noexcept;
private:
  //std::map<std::string, std::string> cache_;
  VeryHeavyDatabase* real_db_;
  int receive_count;
};