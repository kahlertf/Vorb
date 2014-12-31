#include "stdafx.h"
#include "Path.h"

#include <boost/filesystem.hpp>

#include "Directory.h"

namespace fs = boost::filesystem;

vio::Path::Path() : Path("") {
    // Empty
}
vio::Path::Path(const cString p) :
m_path(p) {
    // Empty
}
vio::Path::Path(const nString& p) :
m_path(p) {
    // Empty
}

bool vio::Path::isNull() const {
    return m_path.empty() || m_path.length() == 0;
}
bool vio::Path::isValid() const {
    if (isNull()) return false;
    return fs::exists(fs::path(m_path));
}
bool vio::Path::isFile() const {
    if (isNull()) return false;
    fs::path p(m_path);
    return fs::exists(p) && fs::is_regular_file(p);
}
bool vio::Path::isDirectory() const {
    if (isNull()) return false;
    fs::path p(m_path);
    return fs::exists(p) && fs::is_directory(p);
}

vio::Path& vio::Path::makeAbsolute() {
    if (isNull() || !isValid()) return *this;
    fs::path p(m_path);
    p = fs::canonical(fs::absolute(p));
    m_path = p.string();
    return *this;
}

vio::Path& vio::Path::append(const nString& dir) {
    if (isNull() || !isValid()) return *this;
    fs::path p(m_path);
    p += dir;
    m_path = p.string();
    return *this;
}
vio::Path& vio::Path::concatenate(const nString& dir) {
    if (isNull() || !isValid()) return *this;
    fs::path p(m_path);
    p /= dir;
    m_path = p.string();
    return *this;
}
vio::Path& vio::Path::trimEnd() {
    if (isNull() || !isValid()) return *this;
    fs::path p(m_path);
    p = p.parent_path();
    m_path = p.string();
    return *this;
}

bool vio::Path::asDirectory(OUT Directory* dir) const {
    if (isDirectory()) {
        *dir = Directory(*this);
        return true;
    }
    return false;
}
