#pragma once
#include <veryheavydb.h>


std::string VeryHeavyDatabase::GetData(const std::string& key) noexcept {
        return "Very Big Data String: " + key;
    }

CacheProxyDB::CacheProxyDB (VeryHeavyDatabase* real_object) : real_db_(real_object) {}

std::string CacheProxyDB::GetData(const std::string& key) noexcept {
        if (cache_.find(key) == cache_.end()) {
            std::cout << "Get from real object\n";
            cache_[key] = real_db_->GetData(key);
        } else {
            std::cout << "Get from cache\n";
        }
        return cache_.at(key);
    }

TestDB::TestDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}

std::string TestDB::GetData(const std::string& key) noexcept {
        return "test_data\n";
    }
	
OneShotDB::OneShotDB (VeryHeavyDatabase* real_object, size_t shots) : real_db_(real_object), receive_count(shots) {}
std::string OneShotDB::GetData(const std::string& key) noexcept {
	
	if(receive_count > 0) {
		--receive_count;
		return real_db_ -> GetData(key);
	}
	
	else return "error";
}