#ifndef SRC_COMMON_FILEUTILS_H_
#define SRC_COMMON_FILEUTILS_H_

#include "src/data_container.h"

#include <wordexp.h>
#include <fstream>
#include <stdexcept>
#include <boost/filesystem.hpp>

namespace Cthun {
namespace Common {
namespace FileUtils {

//
// Error
//

/// Generic file error class.
class file_error : public std::runtime_error {
  public:
    explicit file_error(std::string const& msg) : std::runtime_error(msg) {}
};

//
// Free functions
//

/// Perform a shell expansion of txt.
/// Return an empty string in case of failure.
std::string expandAsDoneByShell(std::string txt);

/// Return true if the specified file exists.
bool fileExists(const std::string& file_path);

/// Remove a file if exists.
/// Throw a file_error if the removal fails.
void removeFile(const std::string& file_path);

/// Write content to file in the specified mode.
/// Throw a file_error in case it fails to open the file to write.
void streamToFile(const std::string& text,
                  const std::string&  file_path,
                  std::ios_base::openmode mode);

/// Write content to file. If file exists, its previous content will
/// be deleted.
/// Throw a file_error in case it fails to open file to write.
void writeToFile(const std::string& text,
                 const std::string& file_path);

/// Create a directory.
/// Returns true on success, false on failure
bool createDirectory(const std::string& dirname);

// TODO(ploubser): Document
std::string readFileAsString(std::string path);

}  // namespace FileUtils
}  // namespace Common
}  // namespace Cthun

#endif  // SRC_COMMON_FILEUTILS_H_