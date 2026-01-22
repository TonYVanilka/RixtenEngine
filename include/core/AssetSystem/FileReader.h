#pragma once
#include <string>
#include <vector>

namespace FileSystem {

bool ReadFileBinary(
    const std::string& path,
    std::vector<std::byte>& outData);
}