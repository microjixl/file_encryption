//
// Created by micro on 08/11/2018.
//

#ifndef FILE_ENCRYPTION_FILE_CIPHER_HPP
#define FILE_ENCRYPTION_FILE_CIPHER_HPP

#include <memory>
#include <string>

namespace org {
namespace mj {
namespace encryption {

class FileCipher {
public:
  /**
   * create a file cipher
   * @param key symmetric encryption key
   * @return
   */
  static std::shared_ptr<FileCipher> Create(const std::string &key);

  /**
   * encrypt file to output path
   * @param file_path
   * @param output
   * @return
   */
  virtual bool encrypt(const std::string &file_path, const std::string &output) = 0;

  /**
   * decrypt file to output path
   * @param file_path
   * @param output
   * @return
   */
  virtual bool decrypt(const std::string &file_path, const std::string &output) = 0;
};

}
}
}

#endif //FILE_ENCRYPTION_FILE_CIPHER_HPP
